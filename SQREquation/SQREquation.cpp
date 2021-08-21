#include "SQREquation.h"
#include "function_from_SQREquation.h"
#define __troll__ printf ("\nProizoshel trolling: ");

int main (int argc, const char* argv[])
{
    system( "color D5" ); // Разрешаю закомментить, если не нравится)

    printf ("Path: \"%s\"\n\n", argv[0]);

    if (argc == 2 && strcmp (argv[1], "-h") == 0)
    {
        printf ("It is program for solving quadratic equations. Version 1.3.3.7, author @shaazmik.\n\n");
        return 1;
    }

    printf ("form of equation: ax^2+bx+c\n\n");

    #ifndef DEBUG_MODE

        float a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

        if (zapuskTRTR (&a, &b, &c) == 1)
        {
            __troll__ printf ("hmmm something went wrong\n");
            return 1;
        }

        int KOL_otv = solve_sqr_equation (a, b, c, &x1, &x2);

        outputVJUX (KOL_otv, x1, x2);

        return 0;

    #else

        return debajim_yOhOO();

    #endif // DEBUG_MODE
}

#ifdef DEBUG_MODE
//{

int TEST_inpuT_file (float *a, float *b, float *c, int *KOL_otv, float *x1, float *x2, FILE *in)
{
    assert (in != NULL);
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (KOL_otv != NULL);
    assert (x1 != x2);
    assert (! (a == b || b == c || a == c));

    if (fscanf (in, "%f %f %f %d", a, b, c, KOL_otv) != 4) return ERR_NO_DIGIT;
    switch (*KOL_otv)
    {
        case 0:
            return 0;
            break;

        case 1:
            return (fscanf (in, "%f", x1) != 1);
            break;

        case 2:
            return (fscanf (in, "%f %f", x1, x2) != 2);
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

int debajim_yOhOO ()
{
    int KOL_lines = 0;
    FILE *in = fopen ("Tests.txt", "r");
    if (!in)
    {
        perror ("error:File \"Tests.txt\" is poteryalsya\n");
        return ERR_FILE_NOT_FOUND;
    }

    if (fscanf (in, "%d", &KOL_lines) != 1 ) return ERR_NO_DIGIT;

    for (int i = 0; i < KOL_lines; ++i)
    {
        float a = NAN, b = NAN, c = NAN, x1_from_file = NAN, x2_from_file = NAN;

        int KOL_otv_file = 0;

        if (TEST_inpuT_file (&a, &b, &c, &KOL_otv_file, &x1_from_file, &x2_from_file, in) == ERR_NO_DIGIT)
        {
            fprintf (stderr, "Paren ti sovsem documentation not read?\n");
            break;
        }

        float x1_from_func = NAN, x2_from_func = NAN;

        int KOL_otv_function = solve_sqr_equation (a, b, c, &x1_from_func, &x2_from_func);

        vivod_debugga (i, KOL_otv_file, x1_from_file, x2_from_file, x1_from_func, x2_from_func, KOL_otv_function);
    }

    fclose (in);

    return 0;
}

void vivod_debugga (const int number, const int KOL_otv_file, const float x1_from_file, const float x2_from_file, const float x1_from_func, const float x2_from_func, const int KOL_otv_func)
{
   if (KOL_otv_file != KOL_otv_func)
                                printf ("Test #%d wasn't passed\n",                        number + 1);
        else
        {
            switch (KOL_otv_file)
            {
            case 0:
                                printf ("Test #%d passed, no roots\n",                   number + 1);

                break;
            case 1:
                if (srav_tWo_numbErs (x1_from_file, x1_from_func, Pogreshnik))
                                printf ("Test #%d passed, x1 = %.2f\n",                  number + 1, x1_from_func);
                else            printf ("Test #%d wasn't passed\n",                      number + 1);

                break;
            case 2:
                if ((srav_tWo_numbErs (x1_from_file, x1_from_func, Pogreshnik) && srav_tWo_numbErs (x2_from_file, x2_from_func, Pogreshnik)) ||
                    (srav_tWo_numbErs (x2_from_file, x1_from_func, Pogreshnik) && srav_tWo_numbErs (x1_from_file, x2_from_func, Pogreshnik)))
                                printf ("Test #%d passed, x1 = %.2f, x2 = %.2f\n",       number + 1, x1_from_func, x2_from_func);
                else            printf ("Test #%d wasn't passed\n",                      number + 1);

                break;
            case 3:
                                printf ("Test #%d passed, infinite quantity of roots\n", number + 1);

                break;
            }
         }
    return;
}

//}
#endif // DEBUG_MODE


int zapuskTRTR (float *a, float *b, float *c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (! (a == b || b == c || a == c));

    printf ("\n"
            "input the a - coefficients of the equation:");

    if (scanf ("%f", a) == 0) return 1;

    printf ("\n"
            "input the b - coefficients of the equation:");

    if (scanf ("%f", b) == 0) return 1;

    printf ("\n"
            "input the c - coefficients of the equation:");

    if (scanf ("%f", c) == 0) return 1;

    printf ("\n");

    return 0;
}



void outputVJUX (const int KOL_otv, const float x1, const float x2)
{
    switch (KOL_otv)
    {
        case 0:
            printf ("no roots\n");
            break;

        case 1:
            printf ("%.2f single root\n", x1);
            break;

        case 2:
            printf ("%.2f %.2f two roots\n", x1, x2);
            break;

        case 3:
            printf ("infinite quantity of roots\n");
            break;

        default:
            break;
    }
    return;
}


