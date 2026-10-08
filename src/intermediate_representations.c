/**
 * ============================================================================
 * Course: Compiler Design Laboratory (BCSE306L)
 * Experiment 10: Intermediate Representations (Quadruple, Triple, Indirect Triple)
 * Author: Shrri Dharshan D R (Reg No: 23BPS1090)
 * Slot: L23+L24
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int index;
    char op[8];
    char arg1[16];
    char arg2[16];
    char result[16];
} Quadruple;

typedef struct {
    int index;
    char op[8];
    char arg1[16];
    char arg2[16];
} Triple;

void print_quadruples(void) {
    printf("============================================================\n");
    printf("                  QUADRUPLE REPRESENTATION                  \n");
    printf("============================================================\n");
    printf("%-8s | %-6s | %-12s | %-12s | %-12s\n", "Index", "Op", "Arg1", "Arg2", "Result");
    printf("------------------------------------------------------------\n");

    Quadruple quads[] = {
        {1,  "*",  "4",    "i",    "S1"},
        {2,  "[]", "a",    "S1",   "S2"},
        {3,  "*",  "4",    "i",    "S3"},
        {4,  "[]", "b",    "S3",   "S4"},
        {5,  "*",  "S2",   "S4",   "S5"},
        {6,  "+",  "prod", "S5",   "S6"},
        {7,  ":=", "S6",   "-",    "prod"},
        {8,  "+",  "i",    "1",    "S7"},
        {9,  ":=", "S7",   "-",    "i"},
        {10, "<=", "i",    "20",   "goto 1"}
    };

    int n = sizeof(quads) / sizeof(quads[0]);
    for (int i = 0; i < n; i++) {
        printf("%-8d | %-6s | %-12s | %-12s | %-12s\n",
               quads[i].index, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].result);
    }
    printf("============================================================\n\n");
}

void print_triples(void) {
    printf("============================================================\n");
    printf("                    TRIPLE REPRESENTATION                   \n");
    printf("============================================================\n");
    printf("%-8s | %-6s | %-12s | %-12s\n", "Index", "Op", "Arg1", "Arg2");
    printf("------------------------------------------------------------\n");

    Triple triples[] = {
        {0, "*",  "4",    "i"},
        {1, "[]", "a",    "(0)"},
        {2, "*",  "4",    "i"},
        {3, "[]", "b",    "(2)"},
        {4, "*",  "(1)",  "(3)"},
        {5, "+",  "prod", "(4)"},
        {6, ":=", "(5)",  "prod"},
        {7, "+",  "i",    "1"},
        {8, ":=", "(7)",  "i"},
        {9, "<=", "i",    "20 (goto 0)"}
    };

    int n = sizeof(triples) / sizeof(triples[0]);
    for (int i = 0; i < n; i++) {
        printf("%-8d | %-6s | %-12s | %-12s\n",
               triples[i].index, triples[i].op, triples[i].arg1, triples[i].arg2);
    }
    printf("============================================================\n\n");
}

void print_indirect_triples(void) {
    printf("============================================================\n");
    printf("               INDIRECT TRIPLE REPRESENTATION               \n");
    printf("============================================================\n");
    printf("%-15s | %-15s | %s\n", "Pointer Index", "Target Triple", "Operation Summary");
    printf("------------------------------------------------------------\n");
    const char *summaries[] = {
        "S1 := 4 * i",
        "S2 := a[S1]",
        "S3 := 4 * i",
        "S4 := b[S3]",
        "S5 := S2 * S4",
        "S6 := prod + S5",
        "prod := S6",
        "S7 := i + 1",
        "i := S7",
        "if i <= 20 goto 0"
    };

    for (int i = 0; i < 10; i++) {
        printf("P%-14d | Triple (%d)      | %s\n", i, i, summaries[i]);
    }
    printf("============================================================\n\n");
    printf("Key Insight: Indirect Triples allow statement reordering\n");
    printf("without having to update positional indices inside instructions!\n\n");
}

int main(void) {
    print_quadruples();
    print_triples();
    print_indirect_triples();
    return 0;
}
