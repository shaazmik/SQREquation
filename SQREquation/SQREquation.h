#ifndef SQREQUATION_H_INCLUDED
#define SQREQUATION_H_INCLUDED

//!@mainpage
//!Program for solving quadratic equations
//!An equation of the form ax^2+bx+c=0. 3 coefficients @c a, @c b, and @c c are entered.
//!If you want, you can turn on the debug. In the header, you need to delete the "/ / " near #define DEBUG_MOD.
//!The file for debug must be entered with the name Tests.txt. Format:
//!First line is the number of tests, next:
//!'coefficient a' 'coefficient b' 'coefficient c' 'number of answer' 'answer 1' 'answer 2' (if roots are exist).
//!The output accuracy is 2 significant digits after the decimal point

#include "TXLib.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

//! use for launch debug mod , if delete '//'

//#define DEBUG_MODE


//! the error value to compare 2 numbers

const float Pogreshnik = 0.01;


//! declaring an error for not finding a file

enum ERRORS
{
    ERR_FILE_NOT_FOUND = 1
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

int zapuskTRTR (float *a, float *b, float *c);


/*!
 *   \brief outputs solutions of equations
 *   \param[in] KOL_otv - number of solutions
 *   \param[in] x1 - first root of equation
 *   \param[in] x2 - second root of equation
 *   \note if there are no solutions or infinitely, then reports it
 */

void outputVJUX (const int KOL_otv, const float x1, const float x2);


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

int TEST_inpuT_file (float *a, float *b, float *c, int *KOL_otv, float *x1, float *x2, FILE *in);


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

void vivod_debugga (const int number, const int KOL_otv_file, const float x1_from_file, const float x2_from_file, const float x1_from_func, const float x2_from_func, const int KOL_otv_function);

#endif // SQREQUATION_HEADER_H_INCLUDED
