//!@mainpage
//!Program for solving quadratic equations
//!An equation of the form ax^2+bx+c=0. 3 coefficients @c a, @c b, and @c c are entered.
//!If you want, you can turn on the debug. In the header, you need to delete the "/ / " near #define DEBUG_MOD.
//!The file for debug must be entered with the name Tests.txt. Format:
//!First line is the number of tests, next:
//!'coefficient a' 'coefficient b' 'coefficient c' 'number of answer' 'answer 1' 'answer 2' (if roots are exist).
//!The output accuracy is 2 significant digits after the decimal point

#ifndef SQREQUATION_H
#define SQREQUATION_H

#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

//! use for launch debug mod , if delete '//'

#define DEBUG_MODE


//! the error value to compare 2 numbers

const double Pogreshnik = 0.01;


//! declaring an error for not finding a file

enum ERRORS
{
    ERR_NO_DIGIT = 1,
    ERR_FILE_NOT_FOUND = 2
};


/*!
 *   \brief Use for output of unit tests
 *   \return In the function fails, the return value 1, else return value 0
 */

int debajim_yOhOO ();


/*!
 *   \brief Displays the initial dialog box and accepts the values of the coefficients
 *   \param[out] a pointer to the 'a' - coefficient
 *   \param[out] b pointer to the 'b' - coefficient
 *   \param[out] c pointer to the 'c' - coefficient
 */

int zapuskTRTR (double *a, double *b, double *c);


/*!
 *   \brief outputs solutions of equations
 *   \param[in] KOL_otv - number of solutions
 *   \param[in] x1 - first root of equation
 *   \param[in] x2 - second root of equation
 *   \note if there are no solutions or infinitely, then reports it
 */

void outputVJUX (const int KOL_otv, const double x1, const double x2);


/*!
 *   \brief gets a b c coefficients for tests, number of roots and roots themselves
 *   \param[in] a pointer to the 'a' - coefficient
 *   \param[in] b pointer to the 'b' - coefficient
 *   \param[in] c pointer to the 'c' - coefficient
 *   \param[in] x1 pointer to the 'x1' - the first root
 *   \param[in] x2 pointer to the 'x2' - the second root
 *   \param[in] this is pointer to the structure of 'in' file
 *   \return In the function fails, the return value 1, else return value 0
 */

int TEST_inpuT_file (double *a, double *b, double *c, int *KOL_otv, double *x1, double *x2, FILE *in);


/*!
 *   \brief output tests from debug
 *   \param[in] number - number of test
 *   \param[in] KOL_otv_file - number of roots of equation from file
 *   \param[in] x1 - the first root of equation from file
 *   \param[in] x2 - the second root of equation from file
 *   \param[in] x1v - the first root of equation from function
 *   \param[in] x2v - the second root of equation from function
 *   \param[in] KOL_otv_function - number of roots of equation from function
 */

void vivod_debugga (const int number, const int KOL_otv_file, const double x1_from_file, const double x2_from_file, const double x1_from_func, const double x2_from_func, const int KOL_otv_function);

#endif // SQREQUATION_H
