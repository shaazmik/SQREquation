#include "function_from_SQREquation.h"


bool srav_tWo_numbErs (const double number1, const double number2, const double fallibility)
{
    assert (! (isnan (number1)));
    assert (! (isnan (number2)));
    assert (! (isnan (fallibility)));

    return fabs (number2 - number1) < fallibility;
}


int solve_line_equation (const double coef_with_var, const double coef_without_var, double *x1)
{
    assert (x1 != NULL);
    assert (! (isnan (coef_without_var)));
    assert (! (isnan (coef_with_var)));

    if (srav_tWo_numbErs (0, coef_with_var, Zoro))
    {
         if (srav_tWo_numbErs (0, coef_without_var, Zoro)) return Infinite_number_of_roots;
         else return 0;
    }
    else
    {
        if (srav_tWo_numbErs (0, coef_without_var, Zoro))
        {
            *x1 = 0;
            return 1;
        }
        else
        {
            *x1 = -coef_without_var / coef_with_var;
            return 1;
        }
    }
}


int solve_sqr_equation (const double a, const double b, const double c, double *x1, double *x2)
{
    assert (! (isnan (a)));
    assert (! (isnan (b)));
    assert (! (isnan (c)));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (srav_tWo_numbErs (0, a, Zoro)) return (solve_line_equation (b, c, x1));
    else
    {
        if (srav_tWo_numbErs (0, c, Zoro))
        {
            int KOL_roots = solve_line_equation (a, b, x2);
            *x1 = 0;
            if (KOL_roots == 1)
                {
                    if (srav_tWo_numbErs (*x1, *x2, Zoro))
                        return 1;
                    else
                        return 2;
                }
            else
                return ERR_HM_HM_HM;
        }
        else
        {
            double discriminant = b * b - 4 * a * c;

            if (discriminant < 0) return 0;

            if (srav_tWo_numbErs (0, discriminant, Zoro))
            {
                *x1 = -b / (2 * a);

                return 1;
            }
            if (discriminant > 0)
            {
                discriminant = sqrt (discriminant); //BLM BLM LGBTQ+ ANDREW ♂♂♂♂♂

                *x1 = (-b + discriminant) / (2 * a);
                *x2 = (-b - discriminant) / (2 * a);

                return 2;
            }
        }
    }
}
