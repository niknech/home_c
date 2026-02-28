#include "nummethods.h"

/* === ПОЛЬЗОВАТЕЛЬСКИЕ ТИПЫ === */
typedef float(*function)(float); // математическая функция
typedef float(*method_r)(float, float, float, function, int*); // функция расчета корней
typedef float(*method_i)(float, float, size_t, function); // функция расчета интеграла

// перечисления методов расчета корней и интегралов
enum { LS, DIV, CHORD };
enum { SIMP, SQUARE, TRAP };

/* === ПРОТОТИПЫ ВНУТРЕННИХ ФУНКЦИЙ === */
static void PrintHelpInformation(void); // печать help
static void printX(void); // печать корней
static void printI(void); // печать иттераций
static void printS(void); // печать площади
static void checkArguments(int argc, char* argv[]); // обработка опций
static void fullCalc(void); // посчитать площадь выбранным методом поиска корней и выбранным методом расчета интеграла
static void testMethods(void); // протестировать все методы

// математические функции
static float f1(float x);
static float f2(float x);
static float f3(float x);
// разности функций
static float diffFunc1(float x);
static float diffFunc2(float x);
static float diffFunc3(float x);
// знак функции
static int signF(float x, function f);

static float rootFindLineSearch(float xl, float xr, float eps, function f, int* iters);
static float rootFindDiv(float xl, float xr, float eps, function f, int* iters);
static float rootFindChord(float xl, float xr, float eps, function f, int* iters);
static float root(float xl, float xr, float eps, function f, method_r m, int* iters); // подсчет корней выбранным методом
static float calcIntegralSquare(float xl, float xr, size_t n, function f);
static float calcIntegralTrap(float xl, float xr, size_t n, function f);
static float calcIntegralSimpson(float xl, float xr, size_t n, function f);

/* === ВНУТРЕННИЕ ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ === */
static const method_r methods_root[3] = { rootFindLineSearch, rootFindDiv, rootFindChord }; // методы подсчета корней
static const method_i methods_integral[3] = { calcIntegralSimpson, calcIntegralSquare, calcIntegralTrap }; // методы вычисления интеграла
static const function functions[3] = { diffFunc1, diffFunc2, diffFunc3 }; // все разности функций

// названия методов
static const char* methods_root_str[3] = { "line search", "div", "chord" };
static const char* methods_integral_str[3] = { "simpson", "square", "trap" };

// массивы для хранения корней, иттераций, ориентровочных точек пересечения
static float x[3] = {0};
static int i[3] = {0};
static float points[3][2] = { {0.5f, 1.0f}, {3.0f, 3.5f}, {3.5f, 4.0f} };
static float s = 0.0f;

static float f1(float x) { return 0.6f*x + 3.0f; }
static float f2(float x) { return (x-2)*(x-2)*(x-2) - 1.0f; }
static float f3(float x) { return 3.0f/x; }

static float diffFunc1(float x) { return f1(x) - f3(x); }
static float diffFunc2(float x) { return f2(x) - f3(x); }
static float diffFunc3(float x) { return f1(x) - f2(x); }

static int signF(float x, function f)
{
    return f(x) > 0 ? 1 : 0;
}

static float rootFindLineSearch(float xl, float xr, float eps, function f, int* iters)
{
    float xcur, minx = xl;
    float nextstep = fabsf(xr - xl) / (1.0f / eps);
    int stepcount = 0;

    for (xcur = xl; xcur < xr; xcur += nextstep, stepcount++)
    {
        if (fabsf(f(xcur)) < fabsf(f(minx)))
            minx = xcur;
    }

    *iters = stepcount;
    return minx;
}

static float rootFindDiv(float xl, float xr, float eps, function f, int* iters)
{
    int stepcount = 0;
    float xm;

    while (fabsf(xr - xl) > eps)
    {
        stepcount++;
        xm = (xl + xr) / 2;
        if (signF(xl, f) != signF(xm, f))
            xr = xm;
        else
            xl = xm;
    }

    *iters = stepcount;
    return (xl + xr) / 2;
}

static float rootFindChord(float xl, float xr, float eps, function f, int* iters)
{
    int stepcount = 0;

    while (fabsf(xr - xl) > eps)
    {
        xl = xr - (xr - xl) * f(xr) / (f(xr) - f(xl));
        xr = xl - (xl - xr) * f(xl) / (f(xl) - f(xr));
        stepcount++;
    }

    *iters = stepcount;
    return xr;
}

static float root(float xl, float xr, float eps, function f, method_r m, int* iters)
{
    return m(xl, xr, eps, f, iters);
}

static float calcIntegralSquare(float xl, float xr, size_t n, function f)
{
    float sum = 0.0f;
    float h = (xr - xl) / (float)n;

    for (size_t k = 0; k < n; k++)
    {
        sum += f(xl);
        xl += h;
    }
    return sum * h;
}

static float calcIntegralTrap(float xl, float xr, size_t n, function f)
{
    float sum = 0.0f;
    float h = (xr - xl) / (float)n;

    for (float t = xl + h; t < xr - h; t += h)
        sum += 0.5f * h * (f(t) + f(t + h));

    return sum;
}

static float calcIntegralSimpson(float xl, float xr, size_t n, function f)
{
    float sum = 0.0f;
    float h = (xr - xl) / (float)n;

    for (float t = xl + h; t < xr - h; t += h)
        sum += h/6.0f * (f(t) + 4.0f*f(0.5f*(t + t + h)) + f(t + h));

    return sum;
}

static void PrintHelpInformation(void)
{
    printf(
        "Options:\n"
        "-h   show help\n"
        "-x   print x\n"
        "-i   print iterations\n"
        "-s   print square\n"
        "-t   test all methods\n"
    );
}

static void printX(void)
{
    for (int k = 0; k < 3; k++)
        printf("x%d: %.4f  ", k + 1, x[k]);
    printf("\n");
}

static void printI(void)
{
    for (int k = 0; k < 3; k++)
        printf("i%d: %d  ", k + 1, i[k]);
    printf("\n");
}

static void printS(void)
{
    printf("s= %.4f\n", s);
}

// посчитать площадь основным методом
static void fullCalc(void)
{
    for (int k = 0; k < 3; k++)
        x[k] = root(points[k][0], points[k][1], 0.0001f, functions[k], methods_root[CHORD], &i[k]);

    const size_t n = 10000;
    const method_i mi = methods_integral[SIMP];

    float s1 = mi(x[0], x[1], n, f3);
    float s2 = mi(x[1], x[2], n, f2);
    float s3 = mi(x[0], x[2], n, f1);

    s = s3 - s2 - s1;
}

// протестировать все методы
static void testMethods(void)
{
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int p = 0; p < 3; p++)
                x[p] = root(points[p][0], points[p][1], 0.0001f, functions[p], methods_root[k], &i[p]);

            const size_t n = 10000;
            float s1 = methods_integral[j](x[0], x[1], n, f3);
            float s2 = methods_integral[j](x[1], x[2], n, f2);
            float s3 = methods_integral[j](x[0], x[2], n, f1);
            s = s3 - s2 - s1;

            printf("========== ROOT METHOD: %s   INTEGRAL METHOD: %s ==========\n",
                   methods_root_str[k], methods_integral_str[j]);
            printX();
            printI();
            printS();
        }
    }
}

static void checkArguments(int argc, char* argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, "hxist")) != -1)
    {
        switch (opt)
        {
            case 'h': 
                PrintHelpInformation(); 
                break;
            case 'x': 
                printX();
                break;
            case 'i':
                printI();
                break;
            case 's':
                printS();
                break;
            case 't':
                testMethods();
                break;
            default:
                break;
        }
    }
}

void run(int argc, char* argv[])
{
    if (argc == 1)
    {
        PrintHelpInformation();
        return;
    }

    fullCalc();
    checkArguments(argc, argv);
}