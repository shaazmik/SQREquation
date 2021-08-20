#ifndef FUNCTION_FROM_SQREQUATION_HEADER_H_INCLUDED
#define FUNCTION_FROM_SQREQUATION_HEADER_H_INCLUDED
#include <math.h>
#include <assert.h>

//! the error value for comparison with 0

//Buenos Dias

const float Zoro = 0.0001;

/*!
 *   \brief Checks the number#1 for equality with number#2, the 3d argument is accuracy value
 *   \param[in] number1 - the first number for comparison
 *   \param[in] number2- the second number for comparison
 *   \param[in] fallibility - accuracy value, for example 0.01 or 0.00001
 *   \return the truthfulness(VO KAK!) of equality
 */

bool srav_tWo_numbErs (const float number1, const float number2, const float fallibility);

/*!
 *   \brief Solves linear equations provided that the coefficient a = 0
 *   \param[in]  b - coefficient
 *   \param[in]  c - coefficient
 *   \param[out] x1 pointer to the root of equation
 *   \return number of roots of equation
 */

int solve_line_equation (const float a, const float b, const float c, float *x1);

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

int solve_sqr_equation (const float a, const float b, const float c, float *x1, float *x2);

#endif // FUNCTION_FROM_SQREQUATION_HEADER_H_INCLUDED