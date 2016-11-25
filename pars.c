#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char** argv)
{
    int nbColor=atoi(argv[1]);
    int nbVar=argc-3;
    int nbSommet=nbVar/nbColor;
    int color;
    int var;
    int error=0;
    if(strcmp(argv[2],"v")==0)
    {
	argv+=3;
	for(int i=0;i<nbSommet;i++)
	{
	    color=-1;
	    printf("le sommet n°%d est de couleur",i);
	    for(int j=0;j<nbColor;j++,argv++)
	    {
		var=atoi(*argv);
		if(var>0)
		{
		    if(color!=-1)
		    {
			printf(" \033[0;31mET\033[0m");
			if(error==2 || error==3)
			    error=3;
			else
			    error=1;
		    }
		    color=j;
		    printf(" %d",color);
		}
	    }
	    if(color==-1)
	    {
		printf(" \033[0;31mNON DÉFINIE\033[0m");
		if(error==1 || error==3)
		    error=3;
		else
		    error=2;
	    }
	    printf(".\n");
	
	}
	if(error==1  || error==3)
	    printf("\033[0;31mERREUR : au moins un des sommets possède plusieurs couleurs\033[0m\n");
	if(error==2 || error ==3)
	    printf("\033[0;31mERREUR : au moins un des sommets ne possède pas de couleurs\033[0m\n");
	return EXIT_SUCCESS;
    }
    else if(strcmp(argv[2],"s")==0)
    {
	if(strcmp(argv[3],"UNSATISFIABLE")==0)
	{
	    printf("le graphe n'est pas coloriable en %d couleurs\n",nbColor);
	    return EXIT_SUCCESS;
	}
    }
    return EXIT_FAILURE;
}
