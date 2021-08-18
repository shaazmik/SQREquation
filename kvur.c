#include <stdio.h>
#include <math.h>
#include <assert.h>


#define DEBUG_MODE

int line_equation(float a, float b, float c, float *x1)
{
    if (b == 0 && c != 0)
            return 0;
    if (b != 0 && c == 0)
    {
        *x1 = 0;
        return 1;
    }
    if (b!=0 && c != 0)
        {
            *x1 = -c/b;
            return 1;
        }
    return;
}

int sqr_equation(float a, float b, float c, float *x1, float *x2)
{
   float  Discriminant = 0;

    if (a == 0)
    {
        if (line_equation(a, b, c, x1) == 1)
             return 1;
        if (line_equation(a, b, c, x1) == 0)
             return 0;
    }
    else
    {
        Discriminant = b * b - 4 * a * c;

        if (Discriminant < 0)

        return 0;

        if (Discriminant == 0)
        {
            *x1 = -b/(2*a);

            return 1;
        }
        if (Discriminant > 0)
        {
            *x1 = (-b + sqrt(Discriminant))/(2*a);

            *x2 = (-b - sqrt(Discriminant))/(2*a);

            return 2;
        }
    }

    return;
}

int zapuskTRTR(float *a, float *b, float *c)
{

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("form of equation: ax^2+bx+c\n");

    printf("\n");

    printf("input the a - coefficients of the equation:");

    if (scanf("%f", a) == 0)
    {
        return 1;
    }

    printf("\n");

    printf("input the b - coefficients of the equation:");

    if (scanf("%f", b) == 0)
    {
        return 1;
    }

    printf("\n");

    printf("input the c - coefficients of the equation:");

    if (scanf("%f", c) == 0)
    {
        return 1;
    }

    printf("\n");
    return 0;
}

void outputVJUX(float a, float b, float c, int kol, float x1, float x2)
{
    if (a == 0 && b == 0 && c == 0)
        printf("infinite quantity of roots\n");
    else
    {
        if (kol == 0)
            printf("no roots\n");
        if (kol == 1)
            printf("%f\t single root", x1);
        if (kol == 2)
            printf("%f\t%f\t two roots", x1, x2);
    }


}


int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int kol = 0;

    if (zapuskTRTR(&a, &b, &c) == 1)
    {
       printf("Hmmm something went wrong\n");
       return 1;
    }
        kol = sqr_equation(a, b, c, &x1, &x2);
        outputVJUX(a, b, c, kol, x1, x2);

return 0;
}
