#include <stdio.h>

int main(void){
    int a, b, c;

    printf("Informe 3 valores inteiros: ");
    scanf("%d%d%d", &a, &b, &c);

    if(a < b)
        if(b < c)
            printf("%d, %d, %d!", a, b, c);
        else if(a < c)
            printf("%d, %d, %d!", a, c, b);
        else
            printf("%d, %d, %d!", c, a, b);
    else
        if(a < c)
            printf("%d, %d, %d!", b, a, c);
        else if(b < c)
            printf("%d, %d, %d!", b, c, a);
        else
            printf("%d, %d, %d!", c, b, a);

    return 0;
}