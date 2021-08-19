#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

//!Program for solving quadratic equations
//!An equation of the form ax^2+bx+c=0. 3 coefficients a, b, and c are entered.
//!If you want, you can turn on the debug. In the header, you need to delete the "/ / " near #define DEBUG_MOD.
//!The file for debug must be entered with the name Tests.txt. Format:
//!First line is the number of tests, next:
//!'coefficient a' 'coefficient b' 'coefficient c' 'number of answer' 'answer ¹1' 'answer ¹2 ' (if roots are exist).
//!The output accuracy is 2 significant digits after the decimal point



//#define DEBUG_MODE

//! the error value to compare 2 numbers

const float Pogranichnik = 0.01;


//! the error value for comparison with 0

const float Zoro =0.0001;

//! declaring an error for not finding a file

enum ERRORS
{
    ERR_FILE_NOT_FOUND = 1
};

/*!
 *   \brief Use for output of unit tests
 *   \return In the function fails, the return value 1, else return value 0
 */

int debajim_yohoo();

/*!
 *   \brief Checks the number#1 for equality with number#2, the 3d argument is accuracy value
 *   \param[in] number1 - the first number for comparison
 *   \param[in] number2- the second number for comparison
 *   \param[in] fallibility - accuracy value, for example 0.01 or 0.00001
 *   \return the truthfulness of equality
 */

bool srav(const float number1, const float number2, const float fallibility);


/*!
 *   \brief Solves linear equations provided that the coefficient a = 0
 *   \param[in]  b - coefficient
 *   \param[in]  c - coefficient
 *   \param[out] x1 pointer to the root of equation
 *   \return number of roots of equation
 */

int solve_line_equation(const float a, const float b, const float c, float *x1);


/*!
 *   \brief Solves the quadratic equation
 *   \param[in]  a - coefficient
 *   \param[in]  b - coefficient
 *   \param[in]  c - coefficient
 *   \param[out] x1 pointer to the first  root x1
 *   \param[out] x2 pointer to the second root x2
 *   \return Number of roots
 *   \note In case of infinite number of roots, returns 3
 */

int solve_sqr_equation(const float a, const float b, const float c, float *x1, float *x2);



/*!
 *   \brief Displays the initial dialog box and accepts the values of the coefficients
 *   \param[out] a pointer to the 'a' - coefficient
 *   \param[out] b pointer to the 'b' - coefficient
 *   \param[out] c pointer to the 'c' - coefficient
 */

int zapuskTRTR(float *a, float *b, float *c);



/*!
 *   \brief outputs solutions of equations
 *   \param[in] KOL_otv - number of solutions
 *   \param[in] x1 - first root of equation
 *   \param[in] x2 - second root of equation
 *   \note if there are no solutions or infinitely, then reports it
 */

void outputVJUX(const int KOL_otv, const float x1, const float x2);


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

int TESTinpuT_file(float *a, float *b, float *c, int *KOL_otv, float *x1, float *x2, FILE *in);

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

void vivoddebugga(const int number, const int KOL_otv_file, const float x1, const float x2, const float x1v, const float x2v, const int KOL_otv_function);


