#ifndef MAXARGS_H_
#define MAXARGS_H_

#include "slp.h"

/*
 * Tells the maximum number of arguments of any print statement within any subexpression of a given
 * statements
 */
int maxargs(A_stm stm);

/*
 * Tells the maximum number of arguments of any print statement within any subexpression of a given
 * expression
 */
int maxargs_exp(A_exp exp);

/*
 * Tells the maximum number of arguments of any print statement within any subexpression of a given
 * expression list
 */
int maxargs_list(A_expList list);

/*
 * Tells the number of elements of the list
 */
int numargs(A_expList list);

/*
 * Returns the biggest number
 */
int max(int a, int b);

#endif
