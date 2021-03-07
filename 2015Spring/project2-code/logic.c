#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "io.h"

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
            reply = cleanedFloor();
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

