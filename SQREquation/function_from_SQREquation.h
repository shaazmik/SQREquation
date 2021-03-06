//!@mainpage It is short library with math function for me
//! I don't think that u will use this peace of pie
//! WARNING functions solve_sqr_equation: in case of infinite number of roots, returns 3
//! Please read the documentation

#ifndef FUNCTION_FROM_SQREQUATION_H
#define FUNCTION_FROM_SQREQUATION_H

#include <math.h>
#include <assert.h>

//! use for return error about unreal math situation

const int ERR_HM_HM_HM = 1337;


//! use for return message about infinite numbers of roots

const int Infinite_number_of_roots = 3;


//! the error value for comparison with 0

// Buenos Dias

const double Zoro = 0.0001;


/*!
 *   \brief Checks the number#1 for equality with number#2, the 3d argument is accuracy value
 *   \param[in] number1 - the first number for comparison
 *   \param[in] number2- the second number for comparison
 *   \param[in] fallibility - accuracy value, for example 0.01 or 0.00001
 *   \return the truthfulness(VO KAK!) of equality
 */

bool srav_tWo_numbErs (const double number1, const double number2, const double fallibility);


/*!
 *   \brief Solves linear equations provided that the coefficient a = 0
 *   \param[in]  coef_with_var - coefficient with variable
 *   \param[in]  coef_without_var - coefficient without variable
 *   \param[out] x1 pointer to the root of equation
 *   \return number of roots of equation
 */

int solve_line_equation (const double coef_with_var, const double coef_without_var, double *x1);


/*!
 *   \brief Solves the quadratic equation
 *   \param[in]  a - coefficient
 *   \param[in]  b - coefficient
 *   \param[in]  c - coefficient
 *   \param[out] x1 pointer to the first  root x1
 *   \param[out] x2 pointer to the second root x2
 *   \return Number of roots
 *   \note In case of infinite number of roots, returns 3, if you get unreal math situation , returns 1337
 */

int solve_sqr_equation (const double a, const double b, const double c, double *x1, double *x2);

#endif // FUNCTION_FROM_SQREQUATION_H
