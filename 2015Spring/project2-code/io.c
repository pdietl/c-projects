#include "io.h"

int dropped(void) {
    char *ans;
    printf("What did you drop (meat/produce/bread/junk) ? ");
    ans = readToken(stdin);
    if ( strcmp(ans,"meat") == 0 )           return 1;
    if ( strcmp(ans,"produce") == 0 )        return 2;
    if ( strcmp(ans,"bread-roll") == 0 )     return 3;
    if ( strcmp(ans,"junk-food") == 0 )      return 4;
    return 0;
}

int cleanedFloor(void) {
    printf("When is the last time you cleaned the floor,\n");
    printf("\twas it today, yesterday, this-week, or do-not-know? ");
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans,"today") == 0 ) return 1;
    if ( strcmp(ans,"yesterday") == 0 ) return 2;
    if ( strcmp(ans,"this-week") == 0 ) return 3;
    if ( strcmp(ans,"do-not-know") == 0 ) return 4;
    return 0;
}

int blowBrush(void) {
    printf("Blow on it and brush it off as best you can,\n");
    printf("\tis it immaculate, looks-clean, visible-specks, still-yucky ? ");
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans,"immaculate") == 0 ) return 1;
    if ( strcmp(ans,"looks-clean") == 0 ) return 2;
    if ( strcmp(ans,"visible-specks") == 0 ) return 3;
    if ( strcmp(ans,"still-yucky") == 0 ) return 4;
    return 0;
}

int yesNo(char *s) {
    printf("%s ", s);
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans, "yes") == 0 ) return 1;
    return 0;
}

int threeSecondRule(void) {
    printf("Has the food been on the floor for more than three seconds? ");
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans, "yes") == 0 ) return 0;
    return 1;
}
