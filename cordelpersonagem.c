#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "d6.h"
#include "cordel.h"
#define TXTS(A) "./txts/"A



/////////////////////////// MAIN/////////////////////////////

int main(int argc, char *argv[]) 

{
       srand(time(NULL));

       char TabToSearch[64] = TXTS("TabClasses");
       char *strClasse;// = generatefeature("./txts/Classes", countlines("./txts/Classes"));
       char *strOrigem = generatefeature(TXTS("Origem"), 6);
       
       int sexo = rand() % 2 + 1;
       int Nivel = 1;
       int NivelAtual = 0;
       int AtribModificados[5];
       int contModificacoes = 0;
       int atrib[5], LinhaClasse;
       char Classe[32];
       int ParamSexo = 0, ParamName = 0, ParamClasse = 0;

       for (int i = 0; i < 6; i++) {
	      AtribModificados[i] = 0;
       } 

       for (int i = 0; i < 6; i++) {
	atrib[i] = 0;
       }

//       if (argc % 2 == 0) { printf("Número de argumentos inválido !\n"); return 1;}

	       
  
       for (int i = 0; i < argc; i++) {  
	      if (strcmp(argv[i],"-t") == 0) { // -t : Tipo da classe de personagem 
		      if (thereis(TXTS("Classes"), argv[i+1]) == 1) { strClasse = argv[i+1]; }

		      else if (thereis("./txts/Classesnpcs", argv[i+1]) == 1) { 
			      strClasse = argv[i+1]; 
			      strcpy(TabToSearch,"./txts/TabClassesnpcs");
		      }

		      else { 
			      printf("Argumento Inválido! Essa classe num existe não cabra leso! \n"); 
			      return 1;
		      }

		      ParamClasse = 1;
		      sexo = ajustasexo(strClasse);     
      
	      }

	      else if (strcmp(argv[i], "-n") == 0) { // -n define o Nível do personagem 
		      if( atoi(argv[i+1]) > 260 ) { printf("Nível alto demais"); return 1;}   // 260 is the maximum level 
		      Nivel =  atoi(argv[i+1]);
	      }

	      else if (strcmp(argv[i], "-s") == 0) { // a childish definition of sex

		      if (strcmp(argv[i+1], "f") == 0) { 
			      ParamSexo = 2;}

		      if (strcmp(argv[i+1], "m") == 0) { 

			      ParamSexo = 1;}
			      
		      sexo = ParamSexo;
	      }

	      else if(strcmp(argv[i], "-nm") == 0) { // nome do personagem 
	      	ParamName = i + 1;
	      }

      }

	       if (!ParamClasse && (ParamSexo > 0) ) {
		       if (ParamSexo == 1) {
		       
			       do {		      			      
				       strClasse = generatefeature("./txts/Classes", countlines("./txts/Classes"));      	       
		       
			       } while ( (strcasecmp(strClasse,"Vidente") == 0) || (strcasecmp(strClasse,"Dona") == 0) || (strcasecmp(strClasse,"Dama") == 0) || (strcasecmp(strClasse,"Cangaceira") == 0) || (strcasecmp(strClasse,"BemNascida") == 0) || (strcasecmp(strClasse,"Beata") == 0) || (strcasecmp(strClasse,"Rezadeira")) == 0); 
		       }

		       else if (ParamSexo == 2) {

			       do {
				       strClasse = generatefeature("./txts/Classes", countlines("./txts/Classes"));      	      
			       } while( (strcasecmp(strClasse,"Cangaceiro") == 0) || (strcasecmp(strClasse,"Padre") == 0) || (strcasecmp(strClasse,"Bispo") == 0) || (strcasecmp(strClasse,"Beato") == 0) || (strcasecmp(strClasse,"BemNascido") == 0) || (strcasecmp(strClasse,"Profeta")) == 0);

	       
		       }
		       
		       sexo = ParamSexo;
	       }
	       
	       else if (!ParamClasse && ParamSexo == 0) {
			strClasse = generatefeature("./txts/Classes", countlines("./txts/Classes"));
			sexo = ajustasexo(strClasse);
			
	       }

    
    		   if (ParamName !=0) {
			       printf("Nome : %s \n",argv[ParamName]);
		   }
		   
		   else {
       
		       if (sexo == 1) {        
			       printf("Nome : %s \n", generatefeature(TXTS("NomesMasculinos"),countlines(TXTS("NomesMasculinos"))));
       		       }
       
		       else { 
			       printf("Nome : %s \n", generatefeature(TXTS("NomesFemininos"),countlines(TXTS("NomesFemininos"))));
       		       }
       	   }     
    //   }
       
       char *NameExtended = extendClassName(strClasse, sexo);
       
       if ( strcmp(NameExtended,"") !=0)  {
	       if ( strcmp("Dotôra", NameExtended) == 0 ) {
		       printf("Classe : %s(%s) \n", NameExtended, ProfDoto(sexo));
	       }
	       else {
		       printf("Classe : %s \n", NameExtended);
	       }
       }
       
       else {
	       if ( strcmp("Dotô", strClasse) == 0 ) {
		       printf("Classe : %s(%s) \n", strClasse, ProfDoto(sexo));}
	       else {
		       printf("Classe : %s \n", strClasse);
	       }
       }


       printf("Nível : %d \n", Nivel);
       printf("Disposição: %s \n", generatefeature(TXTS("Disposicao"),6));
       printf("Motivação : %s \n", generatefeature(TXTS("Motivacao"),6));

       if (strcmp(strOrigem,"ALSE") == 0) {
	       printf("Origem : %s \n", generatefeature(TXTS("ALSE"),6));
       }
       else {
               printf("Origem : %s \n", strOrigem);
       }

     FILE *Arquivo = fopen(TabToSearch,"r");
     LinhaClasse = fscanf(Arquivo, "%s %d %d %d %d %d %d", Classe, &atrib[0], &atrib[1], &atrib[2], &atrib[3], &atrib[4], &atrib[5]);
     
    
     while ( (LinhaClasse !=EOF) && (strcasecmp(Classe,strClasse) !=0) ) {
     	     LinhaClasse = fscanf(Arquivo, "%s %d %d %d %d %d %d", Classe, &atrib[0], &atrib[1], &atrib[2], &atrib[3], &atrib[4], &atrib[5]);
     }


   int ChangedAtrib = 0, Repetido = 0;
   long CountVantagens;
   char *Vantagem;
   char *Vantagens[1024];

   while (NivelAtual < Nivel) {

	ChangedAtrib = rand() % 6;

	if (AtribModificados[ChangedAtrib] == 0) {		 
		   AtribModificados[ChangedAtrib] = 1;
		   atrib[ChangedAtrib] = atrib[ChangedAtrib] + 1;
		   contModificacoes++;
		   NivelAtual++;
//		   printf("Nível %d | %s \n", NivelAtual, atributos[ChangedAtrib]);

	   if (contModificacoes == 2) {
		   
		   contModificacoes = 0 ;
		   for (int i = 0; i < 6; i++) {
			   AtribModificados[i] = 0;
		   } 
	   
		   AtribModificados[ChangedAtrib] = 1;
	   }

 
	}
}

   printf("PEL: %d LIG:%d PAR: %d EST: %d ESP: %d VAL: %d\n", atrib[0], atrib[1], atrib[2], atrib[3], atrib[4], atrib[5]);

   if (Nivel > 0) {

	   for (int i = 0; i < ((Nivel / 3) + 1); i++) {
	
	   	   do {

			   Repetido = 0;
			   Vantagens[CountVantagens] = newvantage(i, strClasse, atrib);   

				   for (int j = 0; j < CountVantagens; j++) {
   	
						   if ( strcmp(Vantagens[CountVantagens], Vantagens[j]) == 0 ) { Repetido = 1; break;}
			   }

		   } while ( strcmp(Vantagens[CountVantagens],"") == 0 || Repetido == 1);

		   printf("Vantagem %d : %s\n",i + 1,Vantagens[CountVantagens]);
		   CountVantagens++;
   		   free;
 	 
 
	   }
   }
 
}
