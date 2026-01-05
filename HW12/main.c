#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "sensor.h"
#include "unistd.h"
#include "getopt.h"

void checkKeys(int argc, char* argv[], union sensor_serdes* ds);

int main(int argc, char* argv[])
{
    struct statistic stat;
    union sensor_serdes ds = {0};    
    AddInfo(&ds);

    //обработка аргументов командной строки
    checkKeys(argc, argv, &ds);

    /*save_bin_des(&ds);
    load_bin_des(&ds);*/
    
    printf("Sensor data:\n");
    PrintInfo(ds.d.info, ds.d.number);

    //Среднемесячная температура
    printf("Average month: %.3f\n", GetAverageTemperature(2021, 9, &ds));

    //Минимальная температура в месяце
    
    printf("Minimal temperature in month: %d\n", GetMinTemperature(2022, 9, &ds));
    
    //Максимальная температура в месяце
    printf("Maximum temperature in month: %d\n", GetMaxTemperature(2021, 9, &ds));

    printf("========================\n");

    //получаем статистику за год
    GetStatistics(2021, 0, &ds);
    printf("========================\n");

    //получаем статистику за сентябрь 2021
    GetStatistics(2021, 9, &ds);
    printf("========================\n");

    //добавляем элемент
    printf("Adding 2025-1-9 -5\n");
    AddRecord(&ds, 2025, 1, 9, -5);
    PrintInfo(ds.d.info, ds.d.number);

    //удаляем его же
    printf("Deleting 2025-1-9 -5\n");
    DelReccord(ds.d.number-1, &ds);
    PrintInfo(ds.d.info, ds.d.number);

    //сортировка по температуре
    printf("Sorting by temperature\n");
    SortByT(ds.d.info, ds.d.number);
    PrintInfo(ds.d.info, ds.d.number);

    //сортировка по дате
    printf("Sorting by date\n");
    SortByDate(ds.d.info, ds.d.number);
    PrintInfo(ds.d.info, ds.d.number);

    return 0;
}

void checkKeys(int argc, char* argv[], union sensor_serdes* ds)
{

    printf("DEBUG: argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("DEBUG: argv[%d] = %s\n", i, argv[i]);
    }

    int opt;
    optind = 1;

    while ((opt = getopt(argc, argv, "hm:a:")) != -1)
    {
        switch (opt)
        {
            case 'h':
                printf("-h - help\n-m [NUMBER OF MONTH] - get statistic by month\n-a [""YYYY-MM-DD t""] - add sensor data\n");
                break;
                
            case 'm':
            {
                int month;
                if (sscanf(optarg, "%d", &month) != 1) {
                    fprintf(stderr, "Error: invalid month format\n");
                    break;
                }
                GetStatistics(2021, month, ds);
                printf("========================\n");
                break;
            }
            
            case 'a':
                ParseSensorInfoFromStr(optarg, ds);
                break;
                
            case '?':
                fprintf(stderr, "Unknown option: -%c\n", optopt);
                break;
                
            default:
                printf("Arguments are not found\n");
                break;
        }
    }
}
