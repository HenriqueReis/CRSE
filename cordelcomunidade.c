#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "d6.h"
#include "cordel.h"
#define TXTS(A) "./txts/"A
#define PATHCOMUNIDADES "./txts/Comunidades/Comunidades"
#define COMUNIDADE(A) "./txts/Comunidades/Comunidades"A


int main(int argc, char *argv[]) 
{
       srand(time(NULL));

       int qtd  = 0;
       char *strComunidade = generatefeature(PATHCOMUNIDADES,6); 
       char *strTemp = "";
       
       int Nivel = 1;
       int NivelAtual = 0;
       int AtribModificados[5];
       int contModificacoes = 0;
       
       for (int i = 0; i < 6; i++) {
	      AtribModificados[i] = 0;
       }

       for (int i = 0; i < argc; i++) {
	       if (strcmp(argv[i],"-t") == 0) {
		       
		      strTemp = match(PATHCOMUNIDADES, argv[i+1]);
		      
		      if (strcmp(strTemp,"NULL") != 0) {
			      strcpy(strComunidade,strTemp);
		      }
		      
		      else {
			      printf("Comunidade %s ainda não foi parida!", argv[i+1]);
			      return 1; 
		    }
	       }
	       
	       else if (strcmp(argv[i], "-n") == 0) { // -n define o Nível do personagem
		      Nivel =  atoi(argv[i+1]);
	       }

	       else if (strcmp(argv[i],"--t") == 0) {
		       do {
      			      strcpy(strComunidade,generatefeature(PATHCOMUNIDADES,6)); 
		       } while ( strcasecmp(strComunidade,argv[i+1]) == 0);
	       }
	       
	       
       }
       
       char pathComunidade[164] = "";
       char *strOrigem = generatefeature(TXTS("Origem"),6);

       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);

       strcat(pathComunidade,"/Tipo");  
       char *strTipo = generatefeature(pathComunidade,countlines(pathComunidade));
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
       
       char *strLider = generatefeature(strcat(pathComunidade,"/Líder"),6);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);

       char *strAliado = generatefeature(strcat(pathComunidade,"/Aliado"),6);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
       
       strcat(pathComunidade,"/Maioria");
       char *strMaioria = generatefeature(pathComunidade,countlines(pathComunidade));
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
       
//       int sexo = rand() % 2 + 1;
       int atrib[5], LinhaComunidade;
       char Comunidade[32];
       
       for (int i = 0; i < 6; i++) {
	atrib[i] = 0;
       }	

       if (strcmp(strOrigem,"Alagoas ou Sergipe") == 0) {
	  strOrigem = generatefeature("ALSE",6);
       }
  
       printf("Comunidade : %s (Maioria : %s) \n", strComunidade, strMaioria);
       printf("Nível : %d \n", Nivel);
       printf("Tipo : %s \n", strTipo);
       printf("Líder : %s Nível %d \n", strLider, rand() % 6 + 1);
       printf("Aliado : %s Nível %d \n", strAliado, rand() % 6  + 1);

    if (strcmp("Bando", strComunidade) == 0) {
       
       strcat(pathComunidade,"/Passado");
       char *strPassado = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Passado : %s \n", strPassado);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);

       strcat(pathComunidade,"/Motivação");
       char *strMotivacao = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Motivação : %s \n", strMotivacao);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);

       strcat(pathComunidade,"/Inimigo");
       char *strInimigo = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Inimigo : %s Nível %d \n", strInimigo, rand() % 6 + 1);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
  
   }

   if (strcmp("Fazenda", strComunidade) == 0) {

       char *strNomeFazenda = nomedelugar();
       printf("Nome : %s \n", strNomeFazenda);
     
       printf("Localização : %s \n", generatefeature("./txts/Localização",countlines("./txts/Localização")));
       
       strcat(pathComunidade,"/Fortuna");
       char *strFortuna = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Fortuna : %s \n", strFortuna);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
         
       strcat(pathComunidade,"/Produção");
       char *strProducao = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Produção : %s \n", strProducao);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
       
       strcat(pathComunidade,"/Capataz");
       char *strCapataz = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Capataz : %s Nível %d \n", strCapataz, rand() % 6  + 1);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade,strComunidade);
   
      
   }

       
   if (strcmp("Milícia", strComunidade) == 0) {
   
      strcat(pathComunidade, "/Comportamento");
      char *strComportamento = generatefeature(pathComunidade, countlines(pathComunidade));
      printf("Comportamento : %s \n", strComportamento);
      strcpy(pathComunidade, "./txts/Comunidades/");     
      strcat(pathComunidade, strComunidade);
       
       
       strcat(pathComunidade,"/Popularidade");
       char *strPopularidade = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Popularidade : %s \n", strPopularidade);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
      
       strcat(pathComunidade,"/Inimigo");
       char *strInimigo = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Inimigo : %s Nível %d \n", strInimigo, rand() % 6 + 1);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
  
   }


    if (strcmp("Povoado", strComunidade) == 0) {
   
       
      char *strNomePovoado = nomedelugar();
      printf("Nome : %s \n", strNomePovoado);
      
      strcat(pathComunidade, "/Fortuna");
      char *strFortuna = generatefeature(pathComunidade, countlines(pathComunidade));
      printf("Fortuna : %s \n", strFortuna);
      strcpy(pathComunidade, "./txts/Comunidades/");     
      strcat(pathComunidade, strComunidade);
       
       strcat(pathComunidade,"/Peculiaridade");
       char *strPeculiaridade = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Peculiaridade : %s \n", strPeculiaridade);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
       
       strcat(pathComunidade,"/Procurado");
       char *strProcurado = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Procurado : %s Nível %d \n", strProcurado, rand() % 6 + 1);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
    }

    if (strcmp("Procissão", strComunidade) == 0) {
   
      strcat(pathComunidade, "/Formação");
      char *strFormacao = generatefeature(pathComunidade, countlines(pathComunidade));
      printf("Formação : %s \n", strFormacao);
       strcpy(pathComunidade, "./txts/Comunidades/");     
      strcat(pathComunidade, strComunidade);
    
       
       strcat(pathComunidade,"/Moral");
       char *strMoral = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Moral : %s \n", strMoral);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);

       
       strcat(pathComunidade,"/Receio");
       char *strReceio = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Receio : %s \n", strReceio);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
    
    }


    if (strcmp("Tropa", strComunidade) == 0 ) {

       
       strcat(pathComunidade,"/Atitude");
       char *strAtitude = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Atitude : %s \n", strAtitude);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
       
       strcat(pathComunidade,"/Popularidade");
       char *strPopularidade = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Popularidade : %s \n", strPopularidade);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
       
       strcat(pathComunidade,"/Alvo");
       char *strAlvo = generatefeature(pathComunidade,countlines(pathComunidade));
       printf("Alvo : %s nível %d \n", strAlvo, rand() % 6 + 1);
       strcpy(pathComunidade, "./txts/Comunidades/");     
       strcat(pathComunidade, strComunidade);
    }
   
       FILE *Arquivo = fopen("./txts/TabComunidades","r");

    LinhaComunidade = fscanf(Arquivo, "%s %d %d %d %d %d %d", Comunidade, &atrib[0], &atrib[1], &atrib[2], &atrib[3], &atrib[4], &atrib[5]);

    while ( (LinhaComunidade !=EOF) && (strcasecmp(Comunidade,strComunidade) !=0) ) {
        LinhaComunidade = fscanf(Arquivo, "%s %d %d %d %d %d %d", Comunidade, &atrib[0], &atrib[1], &atrib[2], &atrib[3], &atrib[4], &atrib[5]);
    }

   int ChangedAtrib = 0;

   while (NivelAtual < Nivel) {

	ChangedAtrib = rand() % 6;

	if (AtribModificados[ChangedAtrib] == 0) {		 
		   AtribModificados[ChangedAtrib] = 1;
		   atrib[ChangedAtrib] = atrib[ChangedAtrib] + 1;
		   contModificacoes++;
		   NivelAtual++;
//		   printf("Nível %d | %s \n", NivelAtual, atributos[ChangedAtrib]);
	}

	   if (contModificacoes == 2) {
		   
		   contModificacoes = 0 ;
		   for (int i = 0; i < 6; i++) {
			   AtribModificados[i] = 0;
		   } 
	   
		   AtribModificados[ChangedAtrib] = 1;
	   }

   }


 
   printf("Disciplina : %d Recursos : %d Influência : %d Armamento : %d Beligerância : %d Reputação : %d\n", atrib[0], atrib[1], atrib[2], atrib[3], atrib[4], atrib[5]); 

    
   
   int  Repetido = 0;
   long CountVantagens;
   char *Vantagem;
   char *Vantagens[1024];
 
      if (Nivel > 0) {

	   for (int i = 0; i < ((Nivel / 3) + 1); i++) {
	
	   	   do {

			   Repetido = 0;
			   Vantagens[CountVantagens] = newvantage(i, strMaioria, atrib);   

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
