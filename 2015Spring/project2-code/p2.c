#include <stdio.h>
#include <string.h>
#include "scanner.h"

int meat(void);
int produce(void);
int bread(void);
int junk(void);

int yesNo(char *);
int cleanedFloor(void);
int blowBrush(void);
int threeSecondRule(void);

int main(int argc, char **argv) {
    char *ans;
    int decision;
    printf("Decisions, decisions, decisions\n\n");
    printf("What did you drop (meat/produce/bread/junk) ? ");
    ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans,"meat") == 0 ) decision = meat();
    if ( strcmp(ans,"produce") == 0 ) decision = produce();
    if ( strcmp(ans,"bread") == 0 ) decision = bread();
    if ( strcmp(ans,"junk") == 0 ) decision = junk();

    if (decision == 1)
        printf("\nYou can eat what dropped!\n");
    else
        printf("\nDo NOT eat what dropped!\n");
    return 0;
}

int meat(void) {
    int reply;
    printf("What type of meat - fish, beef, or chicken?\n");
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans,"fish") == 0 ) {
        printf("Canned or fresh fish? ");
        ans = readToken(stdin);
        // convert(ans);
        if ( strcmp(ans,"canned") == 0 ) {
            reply = blowBrush();
            if ( reply == 1 )
                return 1;
            else
                return threeSecondRule();
        }
        else {
            reply = cleanedFloor();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
        }
    }
    if ( strcmp(ans,"beef") == 0 ) {
        reply = yesNo("Was it steak? ");
        if ( reply == 1 )
            return 1;
        else {
            reply = blowBrush();
            if ( reply == 1 )
                return 1;
            else
                return threeSecondRule();
        }
    }
    if ( strcmp(ans,"chicken") == 0 ) {
        reply = yesNo("Chicken nuggets ?");
        if (reply == 1)
            return 1;
        else
            reply = cleanedFloor();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
    }
    return -1;
}

int produce(void) {
    int reply;
    reply = yesNo("Does that food grow in the ground ?");
    if ( reply == 1 )
        return threeSecondRule();
    else {
        reply = yesNo("Does it appear smashed/bruished ?");
        if ( reply == 1 ) {
            reply = blowBrush();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
        }
        else {
            reply = cleanedFloor();
            if ( reply == 1 || reply == 2 )
                return 1;
            else
                return 0;
        }
    }
    return -1;
}

int bread(void) {
    int reply;
    reply = yesNo("Was the bread/roll buttered? ");
    if ( reply == 1 ) {
        reply = yesNo("Did it land butter side up? ");
        if ( reply == 1 ) {
            reply = blowBrush();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
        }
        else {
            reply = blowBrush();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
        }
    }
    else {
        reply = cleanedFloor();
        if ( reply == 1 || reply == 2 || reply == 3 ) {
            reply = blowBrush();
            if ( reply == 1 || reply == 2 )
                return threeSecondRule();
            else
                return 0;
        }
        else
            return 0;
    }
    return -1;
}

int junk(void) {
    int reply;
    printf("What kind of junk food - donut or chips? ");
    char *ans = readToken(stdin);
    // convert(ans);
    if ( strcmp(ans,"donut") == 0 ) {
        reply = yesNo("Did it have sprinkles on it? ");
        if ( reply == 1 ) {
            reply = cleanedFloor();
            if ( reply == 1 ) {
                reply = blowBrush();
                if ( reply == 1 ) return 1;
                else return 0;
            }
            else
                return 0;
        }
        else
            return threeSecondRule();
    }
    else {
        reply = blowBrush();
        if ( reply == 1 )
            return 1;
        else
            return 0;
    }
    return -1;
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
