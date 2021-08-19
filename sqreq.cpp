#include "sqreq.h"

int main()
{
    printf("form of equation: ax^2+bx+c\n\n");

    #ifndef DEBUG_MODE

        float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int KOL_otv = 0;
        if (zapuskTRTR(&a, &b, &c) == 1)
        {
            printf("Hmmm something went wrong\n");
            return 1;
        }
        KOL_otv = solve_sqr_equation(a, b, c, &x1, &x2);
        outputVJUX(KOL_otv, x1, x2);

        return 0;

    #else

        return debajim_yohoo();

    #endif // DEBUG_MODE
}


int TESTinpuT_file(float *a, float *b, float *c, int *KOL_otv, float *x1, float *x2, FILE *in)
{
    assert(in != NULL);
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(KOL_otv != NULL);
    assert(x1 != x2);
    assert(! (a == b || b == c || a == c));

    if (fscanf(in, "%f %f %f %d", a, b, c, KOL_otv) != 4) return 1;
    switch(*KOL_otv)
    {
        case 0:
            return 0;
            break;
        case 1:
            return (fscanf(in, "%f", x1) != 1);
            break;
        case 2:
            return (fscanf(in, "%f %f", x1, x2) != 2);
            break;
        case 3:
            return 0;
            break;
        default:
            return 1;
            break;

    }


    return 0;
}

int debajim_yohoo()
{
    int KOL_lines = 0;
    FILE *in = fopen("Tests.txt", "r");
    if (!in)
    {
        fprintf(stderr, "error:File \"Tests.txt\" is poteryalsya\n");
        return ERR_FILE_NOT_FOUND;
    }

    fscanf(in, "%d", &KOL_lines);

    for (int i = 0; i < KOL_lines; ++i)
    {
        float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        int KOL_otv_file = 0;
        if (TESTinpuT_file(&a, &b, &c, &KOL_otv_file, &x1, &x2, in) == 1)
        {
                fprintf(stderr, "");
                break;
        }
        float x1v = 0, x2v = 0;
        int KOL_otv_function = solve_sqr_equation(a, b, c, &x1v, &x2v);
        vivoddebugga(i, KOL_otv_file, x1, x2, x1v, x2v, KOL_otv_function);
    }

    fclose(in);
    return 0;
}

void vivoddebugga(const int number, const int KOL_otv_file, const float x1, const float x2, const float x1v, const float x2v, const int KOL_otv_func)
{
   if (KOL_otv_file != KOL_otv_func)
            printf("Test #%d wasnt passed", number + 1);
        else
        {
            switch(KOL_otv_file)
            {
            case 0:
                printf("Test #%d passed, no roots\n", number + 1);
                break;
            case 1:
                if (x1v == x1) printf("Test #%d passed, x1 = %.2f\n", number + 1, x1);
                else printf("Test #%d wasnt passed\n", number + 1);
                break;
            case 2:
                if (srav(x1, x1v, Pogranichnik) && srav(x2, x2v, Pogranichnik)) printf("Test #%d passed, x1 = %.2f, x2 = %.2f\n", number + 1, x1, x2);
                else printf("Test #%d wasnt passed\n", number + 1);
                break;
            case 3:
                printf("Test #%d passed, infinite quantity of roots\n", number + 1);
                break;
            }
        }
    return;
}

bool srav(const float number1, const float number2, const float fallibility)
{
    return fabs(number2 - number1) < fallibility;
}


int solve_line_equation(const float a, const float b, const float c, float *x1)
{
    assert(x1 != NULL);


    if (srav(0, b, Zoro))
    {
         if (srav(0, c, Zoro)) return 3;
         else return 0;
    }
    else
    {
        if (srav(0, c, Zoro))
        {
            *x1 = 0;
            return 1;
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }

    }

}

int solve_sqr_equation(const float a, const float b, const float c, float *x1, float *x2)
{

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (srav(0, a, Zoro)) return (solve_line_equation(a, b, c, x1));
    else
    {
        float discriminant = 0;
        discriminant = b * b - 4 * a * c;

        if (discriminant < 0) return 0;

        if (srav(0, discriminant, Zoro))
        {
            *x1 = -b / (2 * a);

            return 1;
        }
        if (discriminant > 0)
        {
            float koren = sqrt(discriminant);

            *x1 = (-b + koren) / (2 * a);
            *x2 = (-b - koren) / (2 * a);

            return 2;
        }
    }

}

int zapuskTRTR(float *a, float *b, float *c)
{

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



void outputVJUX(const int KOL_otv, const float x1, const float x2)
{
    switch(KOL_otv)
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


