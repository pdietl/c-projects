/*
 * program for uncapped NFL rating, by John C. Lusth, 2014
 * 
 * this program may be freely distributed and modified, as long as:
 * 
 * a) the authorship of any modifications is added
 *
 * b) the reason for modification is added
 *
 * c) the comments are updated to reflect modifications
 *
 * d) the original authorship and that of any previous modifiers is preserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

// function prototypes

void getData(int *,int *,int *,int *,int *);
void displayData(int,int,int,int,int);
double computeRating(int,int,int,int,int);

int
main(int argc, char **argv)
    {
    int attempts,completions,yards,tds,ints;
    double rating;
    
    //get the statistics from the user
    //pass in addresses so getDat can set these variables
    getData(&attempts,&completions,&yards,&tds,&ints);

    //compute the rating
    rating = computeRating(attempts,completions,yards,tds,ints);

    //display the statistics
    displayData(attempts,completions,yards,tds,ints);

    //display the results
    printf("\nFor these statistics, the efficiency rating is %f\n",rating);

    return 0;
    }

void
getData(int *atts,int *comps,int *yards,int *tds,int *ints)
    {
    printf("Enter number of attempts: ");
    scanf(" %d",atts);  //atts is a pointer already

    printf("Enter number of completions: ");
    scanf(" %d",comps);

    printf("Enter total yards gained: ");
    scanf(" %d",yards);

    printf("Enter number of touchdowns: ");
    scanf(" %d",tds);

    printf("Enter number of interceptions: ");
    scanf(" %d",ints);

    return;
    }

double
computeRating(int a,int c,int y,int t,int i)
    {
    double completionFactor,yardFactor,tdFactor,intFactor;
    
    //compute the four individual factors per Wikipedia
    completionFactor = (c / (double) a - 0.3) * 5;
    yardFactor = (y / (double) a - 3) * 0.25;
    tdFactor = (t / (double) a) * 20;
    intFactor = 2.375 - (i / (double) a * 25);

    //this computes an uncapped rating, so do not adjust the factors
    return ((completionFactor + yardFactor + tdFactor + intFactor) / 6.0) * 100;
    }

void
displayData(int at,int co,int ya,int td,int pix)
    {
    printf("\n");
    printf("attempts: %d\n",at);
    printf("completions: %d\n",co);
    printf("yards: %d\n",ya);
    printf("touchdowns: %d\n",td);
    printf("interceptions: %d\n",pix);
    return;
    }
