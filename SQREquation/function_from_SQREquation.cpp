#include "function_from_SQREquation_header.h"


bool srav_tWo_numbErs (const float number1, const float number2, const float fallibility)
{
    return fabs (number2 - number1) < fallibility;
}


int solve_line_equation (const float a, const float b, const float c, float *x1)
{
    assert (x1 != NULL);

    if (srav_tWo_numbErs (0, b, Zoro))
    {
         if (srav_tWo_numbErs (0, c, Zoro)) return 3;
         else return 0;
    }
    else
    {
        if (srav_tWo_numbErs (0, c, Zoro))
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

int solve_sqr_equation (const float a, const float b, const float c, float *x1, float *x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    if (srav_tWo_numbErs (0, a, Zoro)) return (solve_line_equation (a, b, c, x1));
    else
    {
        float discriminant = b * b - 4 * a * c;

        if (discriminant < 0) return 0;

        if (srav_tWo_numbErs (0, discriminant, Zoro))
        {
            *x1 = -b / (2 * a);

            return 1;
        }
        if (discriminant > 0)
        {
            float koren = sqrt (discriminant);

            *x1 = (-b + koren) / (2 * a);
            *x2 = (-b - koren) / (2 * a);

            return 2;
        }
    }
}
