#include <stdio.h>
#include "slp.h"

/*
 * Tells the maximum number of arguments of any print statement within any subexpression of a given
 * statements
 */
int maxargs(A_stm stm);
int maxargs_exp(A_exp exp);
int maxargs_list(A_expList list);

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
    static int max = 0;
    switch(stm->kind){
        case A_printStm:
            ; // empty statement required to make it compile
            int num_args1 = numargs(stm->u.print.exps);
            if(max < num_args1) max = num_args1;
            int num_args2 = maxargs_list(stm->u.print.exps);
            if(max < num_args2) max = num_args2;
            break;
        case A_compoundStm:
            maxargs(stm->u.compound.stm1);
            maxargs(stm->u.compound.stm2);
            break;
        case A_assignStm:
            if(stm->u.assign.exp->kind == A_eseqExp){
                int num_args = maxargs_exp(stm->u.assign.exp);
                if(num_args > max) max == num_args;
            }
            break;
    }
    return max;
}

int maxargs_exp(A_exp exp){
    static int max = 0;
    if(exp->kind == A_eseqExp){
        int num_args = maxargs(exp->u.eseq.stm);
        if(num_args > max) max = num_args;
        maxargs_exp(exp->u.eseq.exp);
    }
    return max;
}

int maxargs_list(A_expList list){
    static int max = 0;
    if(list->kind == A_pairExpList){
        int num_args = maxargs_exp(list->u.pair.head);
        if(num_args > max) max = num_args;
        maxargs_list(list->u.pair.tail);
    } else{
        int num_args = maxargs_exp(list->u.last);
        if(num_args > max) max = num_args;
    }
    return max;
}

int numargs(A_expList list){
    if(list->kind == A_lastExpList)
        return 1;
    else
        return 1 + numargs(list->u.pair.tail);
}
