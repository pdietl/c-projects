#include <stdio.h>
#include "is.h"
#include "qs.h"

void
qs(int *array,int lo,int hi)
    {
    if (hi - lo > 1)
        {
        int i = partition(array,lo,hi,lo);
        qs(array,lo,i);
        qs(array,i+1,hi);
        }
    }

int
partition(int *array,int lo,int hi,int pi)
    {
    int pivot = array[pi];
    swap(array,hi-1,pi);
    int i = lo - 1;
    int j;
    for (j = lo; j < hi - 1; ++j)
        {
        if (array[j] <= pivot)
            {
            ++i;
            swap(array,i,j);
            }
        }
    swap(array,i+1,hi-1);
    return i + 1;
    }

void
selectRank(int *array,int lo,int hi,int rank,int level) //rank is relative to lo
    {
    int i;

    if (hi - lo < 5)
        {
        is(array,lo,hi);
        return;
        }

    if (level == 0) printf("finding group medians...\n");

    int count = 0;
    for (i = lo; i < hi - 4; i += 5)
        {
        if (level == 0) displayArray(array,i,i+5);
        is(array,i,i+5);

        if (level == 0) printf("    median is %d\n",array[i+2]);

        swap(array,lo+count,i+2);
        ++count;
        }

    if (level == 0) printf("medians are: ");
    if (level == 0) displayArray(array,lo,lo+count);

    selectRank(array,lo,lo+count,count/2,level+1);

    if (level == 0) printf("median of median is: %d\n",array[lo+count/2]);

    if (level == 0) printf("before partitioning: ");
    if (level == 0) displayArray(array,lo,hi);

    int index = partition(array,lo,hi,lo+count/2); //index is absolute

    if (level == 0) printf("after partitioning: ");
    if (level == 0) displayArray(array,lo,hi);
    if (lo + rank < index)
        selectRank(array,lo,index,rank,level + 1);
    else if (lo + rank > index)
        selectRank(array,index,hi,lo + rank-index,level + 1);

    if (level == 0) printf("after recursive select: ");
    if (level == 0) displayArray(array,lo,hi);
    }
