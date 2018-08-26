#include <stdio.h>
#include "maxargs.h"

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
