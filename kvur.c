#include <stdio.h>
#include <math.h>
#include <assert.h>


#define DEBUG_MODE

int line_equation(float a, float b, float c, float *x1)   /* функция решения лин. уравнения, функция возвращает значение количества корней уравнения */
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

int sqr_equation(float a, float b, float c, float *x1, float *x2)  /* функция решения квадратного уравнения + вызов на случай линейного, возвращает кол-во корней */
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

int zapuskTRTR(float *a, float *b, float *c)  /*Запуск программы + проверка на валидность ввёденных данных */
{                                             /*Если данные не являются корректными возвращает 1, в ином случае 0 */

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

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

void outputVJUX(float a, float b, float c, int kol, float x1, float x2)   /* функция вывода   */
{
    if (a == 0 && b == 0 && c == 0)
        printf("infinite quantity of roots\n");
    else
    {
        if (kol == 0)
            printf("no roots\n");
        if (kol == 1)
            printf("%f single root\n", x1);
        if (kol == 2)
            printf("%f %f two roots\n", x1, x2);
    }


}



void tests()
{
    float x1T = 0, x2T = 0;
    int kol = 0;

    printf("Standart tests for check\n\n");


    printf("Input a = 0 b = 2 c = 0 Correct answer:0 single root\t Program answer: ");
    kol = sqr_equation(0, 2, 0, &x1T, &x2T);
    outputVJUX(0, 2, 0, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;

    printf("Input a = 1 b = 1 c = 1 Correct answer: no roots\t Program answer: ");
    kol = sqr_equation(1, 1, 1, &x1T, &x2T);
    outputVJUX(1, 1, 1, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;


    printf("Input a = 2 b = 3 c = -1 Correct answer: 0.28 and -1.78 two roots\t Program answer: ");
    kol = sqr_equation(2, 3, -1, &x1T, &x2T);
    outputVJUX(2, 3, -1, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;


    printf("Input a = 0 b = 0 c = 0 Correct answer: infinite quantity of roots\t Program answer: ");
    kol = sqr_equation(0, 0, 0, &x1T, &x2T);
    outputVJUX(0, 0, 0, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;


    printf("Input a = 0 b = 0 c = 3 Correct answer: no roots\t Program answer: ");
    kol = sqr_equation(0, 0, 3, &x1T, &x2T);
    outputVJUX(0, 0, 3, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;

    printf("Input a = 0 b = 5 c = 3 Correct answer: -0.6 single root\t Program answer: ");
    kol = sqr_equation(0, 5, 3, &x1T, &x2T);
    outputVJUX(0, 5, 3, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;


    printf("Input a = 1 b = 2 c = 1 Correct answer: -1 single root\t Program answer: ");
    kol = sqr_equation(1, 2, 1, &x1T, &x2T);
    outputVJUX(1, 2, 1, kol, x1T, x2T);
    x1T = 0;
    x2T = 0;

}

int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int kol = 0;

    printf("form of equation: ax^2+bx+c\n\n");

    tests();

    if (zapuskTRTR(&a, &b, &c) == 1)
    {
       printf("Hmmm something went wrong\n");
       return 1;
    }
        kol = sqr_equation(a, b, c, &x1, &x2);
        outputVJUX(a, b, c, kol, x1, x2);

return 0;
}
