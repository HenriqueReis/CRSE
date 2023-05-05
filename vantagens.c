#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "d6.h"

int main()
{
    srand(time(NULL));
    FILE* stream = fopen("./txts/Vantagens", "r");

    char *token, *temp, *strMinAtrib, *strClasses[43], *strNotClasses[43];
    char Vantage[64];;
    char *Atribs[6];

    Atribs[0] = "Pel";
    Atribs[1] = "Lig";
    Atribs[2] = "Par";
    Atribs[3] = "Est";
    Atribs[4] = "Esp";
    Atribs[5] = "Val";
    
    char line[1024];
    int intNivelMin;
    int intMinAtrib[6];
    int intMaxAtrib[6];
    int intCountVantage = 0;
    int intLegalVantage = 0;

   while(!intLegalVantage) {
	   
	   intLegalVantage = 1;

	   int intRandomVantage = rand() % (countlines("./txts/Vantagens")) + 1;
         
	     while (fgets(line, 1024, stream) && (intCountVantage < intRandomVantage) ) {

		  intCountVantage++;

		  if (intCountVantage == intRandomVantage) {

		  char* tmp = strdup(line);
		  char *lando = strtok(getfield(tmp,3), " "); 
        	
		  // CHECK MINIMUM ATRIB'S REQUIREMENTS

		  int i = 0;
		 
		  while (lando != NULL)  {
	
				  intMinAtrib[i] = atoi(lando);  
				  printf(" %s : %d \n", Atribs[i], intMinAtrib[i]);
				  lando = strtok(NULL," ");
				  i++;
		  }	
		
		  tmp = strdup(line);
        	  lando = strtok(getfield(tmp,4), " ");
		  i = 0;

		 
		  while (lando != NULL)  {
	
				  intMaxAtrib[i] = atoi(lando);  
				  printf(" %s : %d \n", Atribs[i], intMaxAtrib[i]);
				  lando = strtok(NULL," ");
				  i++;
		  }	
		
		  tmp = strdup(line);
        	  lando = strtok(getfield(tmp,5), " ");
		  i = 0;

		  while (lando != NULL) {
			  strClasses[i] = lando;
			  printf("%s-",strClasses[i]);
			  lando = strtok(NULL, " ");
			  i++;
		  }
		
		  tmp = strdup(line);
        	  lando = strtok(getfield(tmp,6), " ");
		  i = 0;

		  while (lando != NULL) {
			  strNotClasses[i] = lando;
			  printf("%s-",strNotClasses[i]);
			  lando = strtok(NULL, " ");
			  i++;
		  }
		


		  tmp = strdup(line);
		  strcpy(Vantage, getfield(tmp, 1));
		  printf("%s\n", Vantage);
		  intNivelMin = atoi(getfield(line,NIVELMIN));
		  printf("%d\n", intNivelMin);
        
//	free(tmp);
	
               }
	     }
   }
}
