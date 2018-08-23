#include "slc.h"
#include "util.h"


A_stm A_CompoundStm(A_stm stm1, A_stm stm2){
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_CompoundStm;
    s->u.compound.stm1 = stm1;
    s->u.compound.stm2 = stm2;
    return s;
}

A_stm A_AssignStm(string id, A_exp exp){
    A_sim s = checked_malloc(sizeof(*s));
    s->kind = A_AssignStm;
    s->u.assign.id = id;
    s->u.assign.exp = exp;
    return s;
}

A_stm A_PrintStm(A_expList exps){
    A_sim s = checked_malloc(sizeof(*s));
    s->kind = A_PrintStm;
    s->u.print.exps = exps;
    return s;
}

A_exp A_IdExp(string id){
    A_exp e = checked_malloc(sizeof(*e));
    e->kind = A_IdExp;
    e->id = id;
    return e;
}





















