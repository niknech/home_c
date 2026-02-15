#include <stdio.h>
#include <string.h>

#define MAX 10000
#define MAXS (2*MAX)

static void z_function(const char *s, int z[]) {
    int n = (int)strlen(s);
    z[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (i + j < n && s[j] == s[i + j]) j++;
        z[i] = j;
    }
}

static int prefA_sufB(const char *A, const char *B) 

{
    static char s[MAXS];
    static int z[MAXS];

    int n = (int)strlen(A), m = (int)strlen(B);

    memcpy(s, A, n);
    s[n] = '#';
    memcpy(s + n + 1, B, m);
    s[n + 1 + m] = '\0';

    z_function(s, z);

    int ans = 0;
    for (int p = 0; p < m; p++) 
    {
        int L = z[n + 1 + p];
        if (p + L == m && L > ans) ans = L;
    }
    return ans;
}

int main(void) {
    
    char s1[MAX];
    char s2[MAX];

    scanf("%s", s1);
    scanf("%s", s2);

    int ans1 = prefA_sufB(s1, s2);
    int ans2 = prefA_sufB(s2, s1);

    printf("%d %d\n", ans1, ans2);
    return 0;
}
