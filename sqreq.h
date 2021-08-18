#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

//#define DEBUG_MODE

const size_t MAXLENGTH = 30;

const float pogranichnik = 0.01;

enum ERRORS {
    FILE_NOT_FOUND = 1
};

/*!
  \brief Use for unit tests
*/

int debajim();

/*!
    \brief Checks the number#1 for equality with number#2
*/

bool srav(const float number1, const float number2);


/*!
    \brief Solves linear equations provided that the coefficient a = 0
    \param[in]  b b - coefficient
    \param[in]  c c - coefficient
    \param[out] x1 pointer to the root of equation
*/

int line_equation(const float a, const float b, const float c, float *x1);


/*!
    \brief Solves the quadratic equation
    \param[in]  b b - coefficient
    \param[in]  c c - coefficient
    \param[out] x1 pointer to the first  root x1
    \param[out] x2 pointer to the second root x2
    \return Number of roots
    \note In case of infinite number of roots, returns 3

*/

int sqr_equation(const float a, const float b, const float c, float *x1, float *x2);



/*!
    \brief Displays the initial dialog box and accepts the values of the coefficients
    \param[out] a pointer to the 'a' - coefficient
    \param[out] b pointer to the 'b' - coefficient
    \param[out] c pointer to the 'c' - coefficient
*/

int zapuskTRTR(float *a, float *b, float *c);



/*!
    \brief outputs solutions of equations
    \param[in] kol - number of solutions
    \param[in] x1 - first root of equation
    \param[in] x2 - second root of equation
    \note if there are no solutions or infinitely, then reports it
*/

void outputVJUX(const int kol, const float x1, const float x2);


/*!
    \brief gets abs coefficients for tests
*/

int testinpt(float *a, float *b, float *c, int *kolotv, float *x1, float *x2, FILE *in);

/*!
    \brief output tests from debug
*/

void vivoddebugga(const int number, const int kolotv, const float x1, const float x2, const float x1v, const float x2v, const int kol);


