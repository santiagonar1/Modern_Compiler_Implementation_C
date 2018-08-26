#include <stdio.h>
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
    printf("Max. attr. print: %d\n", maxargs(prog));

    A_stm prog2 = A_CompoundStm(A_AssignStm("kk", A_NumExp(2)),
        A_PrintStm(A_PairExpList(A_EseqExp(
                    A_PrintStm(A_PairExpList(A_IdExp("d"), A_PairExpList(A_IdExp("e"),
                               A_LastExpList(A_IdExp("f"))))),
                    A_IdExp("c")), A_LastExpList(A_IdExp("b")))));
    printf("Max. attr. print: %d\n", maxargs(prog2));
    return 0;
}

int maxargs(A_stm stm){
    switch(stm->kind){
        case A_printStm:
            return max(numargs(stm->u.print.exps), maxargs_list(stm->u.print.exps));
            break;
        case A_compoundStm:
            return max(maxargs(stm->u.compound.stm1), maxargs(stm->u.compound.stm2));
            break;
        case A_assignStm:
            return maxargs_exp(stm->u.assign.exp);
            break;
        default:
            printf("Error: undefined type of statement\n");
            return -1;
    }
}

int maxargs_exp(A_exp exp){
    switch(exp->kind){
        case A_idExp:
            return 0;
            break;
        case A_numExp:
            return 0;
            break;
        case A_opExp:
            return 0;
            break;
        case A_eseqExp:
            return max(maxargs(exp->u.eseq.stm), maxargs_exp(exp->u.eseq.exp));
            break;
        default:
            printf("Error: undefined type of expression\n");
            return -1;

    }
}

int maxargs_list(A_expList list){
    switch(list->kind){
        case A_pairExpList:
            return max(maxargs_exp(list->u.pair.head), maxargs_list(list->u.pair.tail));
            break;
        case A_lastExpList:
            return maxargs_exp(list->u.last);
            break;
        default:
            printf("Error: undefined type of expression list\n");
            return -1;
    }
}

int numargs(A_expList list){
    if(list->kind == A_lastExpList)
        return 1;
    else
        return 1 + numargs(list->u.pair.tail);
}

int max(int a, int b){
    return (a > b) ? a : b;
}
