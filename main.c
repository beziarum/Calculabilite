#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "all.h"

#ifndef NDEBUG
static int nbVertice;
#endif

int getVar(int nbColor,int numVertice,int numColor)
{
  assert(0<=numVertice);
  assert(numVertice<nbVertice);
  assert(0<=numColor);
  assert(numColor<nbColor);
  return numVertice*nbColor+1+numColor;
}

int main(int argc, char** argv)
{
#ifdef NDEBUG
    int nbVertice;
#endif
    int nbColor=atoi(argv[1]);
    int n=nbColor-1;
    nbVertice=orderG();
    int nbClose=orderG()+nbVertice*(n*n+n)/2+sizeG()*nbColor;
    printf("p cnf %d %d\n",nbVertice*nbColor,nbClose);
#if 1
    for(int i=0;i<nbVertice;i++)
    {
	for(int j=0;j<nbColor;j++)
	    printf("%d ",getVar(nbColor,i,j));
	printf("0\n");
	for(int j=0;j<nbColor;j++)
	    for(int k=j+1;k<nbColor;k++)
		printf("%d %d 0\n",-getVar(nbColor,i,j),-getVar(nbColor,i,k));
    }
#endif
#if 1
    for(int i=0;i<nbVertice;i++)
    {
	for(int j=i;j<nbVertice;j++)
	{
	    if(are_adjacent(i,j))
		for(int k=0;k<nbColor;k++)
		{
		    int var1=-getVar(nbColor,i,k);
		    int var2=-getVar(nbColor,j,k);
		    printf("%d %d 0\n",var1,var2);
		}
	}
    }
#endif			
    return EXIT_SUCCESS;
}
