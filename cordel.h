#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define VANTAGEM 1
#define NIVELMIN 2
#define ALLOWEDCLASSES 4
#define MINATRIB 3

char *nomedelugar() { 

	int roll = rand() % 6 + 1;

	if (roll == 1) {
		return generatefeature("./txts/Tab1", 6);
	}


	if (roll == 2) {
		return strcat(generatefeature("./txts/Tab2",6),generatefeature("./txts/Tab4",6));
	}

	if (roll == 3) {
		return strcat(generatefeature("./txts/Tab2",6),generatefeature("./txts/Tab5",6));
	}

	if (roll == 4) {
		return strcat(generatefeature("./txts/Tab3",6),generatefeature("./txts/Tab4",6));
	}

	if (roll == 5) {
		return strcat(generatefeature("./txts/Tab3",6),generatefeature("./txts/Tab5",6));
	}

	if (roll == 6) {
		return strcat(generatefeature("./txts/Tab1",1),generatefeature("./txts/Tab5",6));
	}

}

char *ProfDoto(int sexo) {
	int dice = rolldice(3,1);

	if (sexo == 1) { 
		if (dice == 1) { return "Engenheiro"; }
		else if (dice == 2) { return "Médico"; }
		else if (dice == 3) { return "Advogado"; }
	}
	
	else if (sexo == 2) { 
		if (dice == 1) { return "Engenheira"; }
		else if (dice == 2) { return "Médica"; }
		else if (dice == 3) { return "Advogada"; }
	}
}

char *extendClassName(char *Classe, int sexo) {
	
	
       if (strcasecmp(Classe,"MãeDeSanto") == 0 && sexo == 1) {
       	return "Pai de Santo"; 
       }
       
       else if (strcasecmp(Classe,"MãeDeSanto") == 0 && sexo == 2) {
       	return "Mãe de Santo"; 
       }
       
       if (strcasecmp(Classe,"Mininu") == 0 && sexo == 2) {
       	return "Minina"; 
       }
       
       
       else if(strcasecmp(Classe,"BemNascida") == 0) {
       	return "Bem Nascida";
       }
       
       else if(strcasecmp(Classe,"BemNascido") == 0) {
       	return "Bem Nascido";
       }
       
       else if(strcasecmp(Classe,"Criada") == 0 && sexo == 1) {
       	return "Criado";
       }
       
       else if(strcasecmp(Classe,"Caçadô") == 0 && sexo == 2) {
       	return "Caçadora";
       }
       
       else if(strcasecmp(Classe,"Dotô") == 0 && sexo == 2) {
       	return "Dotôra";
       }
       
       else if(strcasecmp(Classe,"Jagunço") == 0 && sexo == 2) {
       	return "Jagunça";
       }
       
       else if(strcasecmp(Classe,"Caçadô") == 0 && sexo == 2) {
       	return "Caçadora";
       }
       
       else if(strcasecmp(Classe,"Valentão") == 0 && sexo == 2) {
       	return "Valentona";
       }

       else if(strcasecmp(Classe,"Vaqueiro") == 0 && sexo == 2) {
       	return "Vaqueira";
       }
       
       else if(strcasecmp(Classe,"Véi") == 0 && sexo == 2) {
       	return "Véia";
       }

       else if(strcasecmp(Classe,"BemNascido") == 0) {
       	return "Bem Nascido";
       }

       else if(strcasecmp(Classe,"Bajuladô") == 0 && sexo == 2) {
       	return "Bajuladôra";
       }

       
       else if(strcasecmp(Classe,"Caçadô") == 0 && sexo == 2) {
       	return "Caçadora";
       }


       else if(strcasecmp(Classe,"Capitão") == 0 && sexo == 2) {
       	return "Capitã";
       }

       else if(strcasecmp(Classe,"Matadô") == 0 && sexo == 2) {
       	return "Matadôra";
       }

       return "";
}

int ajustasexo(char *strClasse) {
     	if ( (strcasecmp(strClasse,"Cangaceiro") == 0) || (strcasecmp(strClasse,"Padre") == 0) || (strcasecmp(strClasse,"Bispo") == 0) || (strcasecmp(strClasse,"Beato") == 0) || (strcasecmp(strClasse,"BemNascido") == 0) || (strcasecmp(strClasse,"Profeta")) == 0) {
	       return 1; }

              
		       if ( (strcasecmp(strClasse,"Vidente") == 0) || (strcasecmp(strClasse,"Dona") == 0) || (strcasecmp(strClasse,"Dama") == 0) || (strcasecmp(strClasse,"Cangaceira") == 0) || (strcasecmp(strClasse,"BemNascida") == 0) || (strcasecmp(strClasse,"Beata") == 0) || (strcasecmp(strClasse,"Rezadeira")) == 0) {
	       return 2;}
	       
	      return rand() % 2 + 1;
	       
	       }

char *newvantage(int Nivel, char *Classe, int atribs[5]) {

    FILE* stream = fopen("./txts/Vantagens", "r");

//    char Vantage[128];
    char *minatribs, *maxatribs, *allowedclasses, *notallowedclasses;
    char* tmp;

    char line[1024];
    int intNivelMin, i;
    int intCountVantage = 0;
    int allwdclass = 0; 
    int bolClasses = 0;
	 
    int intRandomVantage = rand() % (countlines("./txts/Vantagens")) ;
            
    while (fgets(line, 1024, stream) && (intCountVantage != intRandomVantage) ) {
		  
	    intCountVantage++;
		 
    }
 
    tmp = strdup(line);
    minatribs = strtok(getfield(tmp,3), " ");      	

    // CHECK MINIMUM ATRIB'S REQUIREMENTS

    i = 0;

    while (minatribs != NULL && i < 6)  {
	
	    if (atribs[i] < atoi(minatribs)) {
		    return "";
	    }

	    minatribs = strtok(NULL," ");   
	    i++;
    }	

    // CHECK MAX ATRIB'S

		  
    tmp = strdup(line);    	  
    maxatribs = strtok(getfield(tmp,4), " ");  
    i = 0;

    while (maxatribs != NULL && i < 6)  {
	
				  
	    if ( (atribs[i] > atoi(maxatribs)) && ( atoi(maxatribs) !=-1) ) { 
		    return "";					  
	    }
				  
	    maxatribs = strtok(NULL," ");				 	    
	    i++;  
    }	
		
		
    //CHECK ALLOWED CLASSES

    tmp = strdup(line);
    allowedclasses = strtok(getfield(tmp,5), " ");
    i = 0;

    if (allowedclasses != NULL) { bolClasses = 1;}
             
    while (allowedclasses != NULL && i < 6) {
	    if (strcmp(allowedclasses,Classe) == 0) { 
		    allwdclass = 1;
		    break;
		    // PTOATENCAO
	    }
				 

	    allowedclasses = strtok(NULL, " ");
	    i++;
    }
		  

    if (allwdclass == 0 && bolClasses == 1) { return "";}
		
    //CHECK NOT ALLOWED CLASSES

    tmp = strdup(line);
    notallowedclasses = strtok(getfield(tmp,6), " ");
    i = 0;


    while (notallowedclasses != NULL) {


	    if (strcmp(notallowedclasses,Classe) == 0) {
	  	  return "";
	    }

	    notallowedclasses = strtok(NULL, " ");
	    i++;

    }

    
    tmp = strdup(line);
    char *retorno = getfield(tmp,1);//strcpy(Vantage, getfield(tmp, 1));
    intNivelMin = atoi(getfield(line,NIVELMIN));
    if (Nivel < intNivelMin)  { return "";}
        
    return retorno;
   
}

