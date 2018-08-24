#include <stdio.h>
#include "slp.h"

/*
 * Tells the maximum number of arguments of any print statement within any subexpression of a given
 * statements
 */
int maxargs(A_stm stm);

/*
 * Tells the number of elements of the list
 */
int numargs(A_expList list);

int main(int argc, const char *argv[])
{
    printf("Running...\n");
    A_stm prog = A_CompoundStm(A_AssignStm("a",
                A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
            A_CompoundStm(A_AssignStm("b",
                    A_EseqExp(A_PrintStm(A_PairExpList(A_IdExp("a"),
                            A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1))))),
                        A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
                A_PrintStm(A_LastExpList(A_IdExp("b")))));
    return 0;
}

int maxargs(A_stm stm){
    return -1;
}

int numargs(A_expList list){
    if(list->kind == A_lastExpList)
        return 1;
    else
        return 1 + numargs(list->u.pair.tail);
}
