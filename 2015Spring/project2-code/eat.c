#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "logic.h"
#include "io.h"

int main(int argc, char **argv) {
    int type, decision;
    printf("Decisions, decisions, decisions\n\n");

    type = dropped();
    if ( type == 1 ) decision = meat();
    if ( type == 2 ) decision = produce();
    if ( type == 3 ) decision = bread();
    if ( type == 4 ) decision = junk();

    if (decision == 1) {
        printf("\nYou can eat what dropped!\n");
        return 0;
    }
    else {
        printf("\nDo NOT eat what dropped!\n");
        return 1;
    }
}
