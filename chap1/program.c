#include <stdio.h>
#include "slp.h"
#include "maxargs.h"

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

