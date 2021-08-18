#include "sqreq.h"

int main()
{
    printf("form of equation: ax^2+bx+c\n\n");

    #ifndef DEBUG_MODE
        float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int kol = 0;
        if (zapuskTRTR(&a, &b, &c) == 1)
        {
            printf("Hmmm something went wrong\n");
            return 1;
        }
        kol = sqr_equation(a, b, c, &x1, &x2);
        outputVJUX(kol, x1, x2);

        return 0;
    #else
        return debajim();
    #endif // DEBUG_MODE
}


int debajim()
{
    int kolstr = 0;
    FILE *in = NULL;
    if ((in = fopen("Tests.txt", "r")) == NULL){
        fprintf(stderr, "File poteryalsya\n");
        return FILE_NOT_FOUND;
    }

    fscanf(in, "%d", &kolstr);

    for (int i = 0; i < kolstr; ++i){
        float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        if (testinpt(&a, &b, &c, in) == 1){
                fprintf(stderr, "");
                break;
        }

        int kol = sqr_equation(a, b, c, &x1, &x2);
        char ans[MAXLENGTH] = "";
        fgets(ans, MAXLENGTH, in);

        printf("%.2f %.2f %.2f %s", a, b, c, ans);
        outputVJUX(kol, x1, x2);
        printf("\n");
    }

    fclose(in);
    return 0;
}


_Bool srav(const float zero, const float koef)
{
    return fabs(koef - zero) < 0.0001;
}


int line_equation(const float a, const float b, const float c, float *x1)
{
    assert(x1 != NULL);

    if (srav(0, b) && !srav(0, c)) return 0;
    if (!srav(0, b) && srav(0, c))
    {
        *x1 = 0;
        return 1;
    }
    if (!srav(0, b) && !srav(0, c))
    {
        *x1 = -c / b;
        return 1;
    }
    if (srav(0, b) && srav(0, c)) return 3;

}

int sqr_equation(const float a, const float b, const float c, float *x1, float *x2)
{
    float Discriminant = 0;

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (a == 0) return (line_equation(a, b, c, x1));
    else
    {
        Discriminant = b * b - 4 * a * c;

        if (Discriminant < 0) return 0;

        if (Discriminant == 0)
        {
            *x1 = -b / (2 * a);

            return 1;
        }
        if (Discriminant > 0)
        {
            *x1 = (-b + sqrt(Discriminant)) / (2 * a);

            *x2 = (-b - sqrt(Discriminant)) / (2 * a);

            return 2;
        }
    }

}

int zapuskTRTR(float *a, float *b, float *c)

    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(! (a == b || b == c || a == c));

    printf("\n"
           "input the a - coefficients of the equation:");


    if (scanf("%f", a) == 0) return 1;


    printf("\n"
           "input the b - coefficients of the equation:");

    if (scanf("%f", b) == 0) return 1;

    printf("\n"
           "input the c - coefficients of the equation:");

    if (scanf("%f", c) == 0) return 1;

    printf("\n");
    return 0;
}

int testinpt(float *a, float *b, float *c, FILE *in)
{
    assert(in != NULL);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(! (a == b || b == c || a == c));

    if (fscanf(in, "%f", a) == 0)
        return 1;
    if (fscanf(in, "%f", b) == 0)
        return 1;
    if (fscanf(in, "%f", c) == 0)
        return 1;
    return 0;
}


void outputVJUX(const int kol, const float x1, const float x2)
{
    switch(kol)
    {
        case 0:
            printf("no roots\n");
            break;
        case 1:
            printf("%.2f single root\n", x1);
            break;
        case 2:
            printf("%.2f %.2f two roots\n", x1, x2);
            break;
        case 3:
            printf("infinite quantity of roots\n");
            break;
        default:
            break;
    }
    return;
}


