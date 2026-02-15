#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    size_t cap = 1024, len = 0;
    char *s = (char*)malloc(cap);
    if (!s) return 0;

    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') break;
        if (len + 1 >= cap) {
            cap *= 2;
            char *ns = (char*)realloc(s, cap);
            if (!ns) { free(s); return 0; }
            s = ns;
        }
        s[len++] = (char)ch;
    }
    s[len] = '\0';

    unsigned char s1[10] = {0};
    unsigned char s2[10][10] = {{0}};
    unsigned char s3[10][10][10] = {{{0}}};

    for (size_t i = 0; i < len; i++) {
        int d = s[i] - '0';

        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                if (s2[a][b]) s3[a][b][d] = 1;
            }
        }

        for (int a = 0; a < 10; a++) {
            if (s1[a]) s2[a][d] = 1;
        }

        s1[d] = 1;
    }

    int ans = 0;
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                if (s3[a][b][c]) ans++;
            }
        }
    }

    printf("%d\n", ans);
    free(s);
    return 0;
}
