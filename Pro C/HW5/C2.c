#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inttypes.h"

#define MAX_STACK_SIZE 255

typedef int32_t datatype;
datatype st[MAX_STACK_SIZE];

int pst=0;

void push(datatype v){ // используется для вычислений
    st[pst++]=v;
}

datatype pop()
{
    if(pst<=0) {
        fprintf(stderr, "Error. Stack underflow");
        return 1;
    } else if(pst>MAX_STACK_SIZE) {
        fprintf(stderr, "Error. Stack overflow");
        return 1;
    }
    return st[--pst];
}

void operate(char c){ // вычисляем два верхних значения на стеке st
    datatype arg1=pop(),arg2=pop();
    if (c=='+') push(arg1+arg2);
    else if (c=='-') push(arg2-arg1);
    else if (c=='*') push(arg1*arg2);
    else if (c=='/') push(arg2/arg1);
}

int main(void)
{
    char line[256];

    if (!fgets(line, sizeof(line), stdin)) {
        return 0;
    }

    for (char *tok = strtok(line, " \t\r\n");
         tok != NULL;
         tok = strtok(NULL, " \t\r\n"))
    {
        char *end = NULL;
        datatype number = strtod(tok, &end);

        if (end != tok && *end == '\0') {
            push(number);
        } else {
            operate(tok[0]);
        }
    }

    printf("%" PRId32 "\n", pop());
    return 0;
}