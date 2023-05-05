#include <stdlib.h>
#include <string.h>
#include <time.h>

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int rolldice(int type, int n) {
	
	float roll = 0;

	while( n > 0) {
//		for (int i  = 0; i < 10000; i++){	}
		roll += rand() % type + 1; 
		n--;
	}

	return roll;
}

int countlines (char filechar[64]) {

    FILE *fileptr;

    int count_lines = 0;

    char chr;

    fileptr = fopen(filechar, "r");

   //extract character from file and store in chr

    chr = getc(fileptr);

    while (chr != EOF)

    {

        //Count whenever new line is encountered

        if (chr == '\n')

        {

            count_lines = count_lines + 1;

        }

        //take next character from file.

        chr = getc(fileptr);

    }

    fclose(fileptr); //close file.

    return count_lines;

}

char *generatefeature(char feature[32], int dN) {

    FILE *File = fopen(feature,"r");
    int rollD = rolldice(dN, 1);
    size_t bufsize = 64;
    char *buffer;
    buffer = (char *)malloc(bufsize * sizeof(char));

    for (int i = 1; i <= rollD; i++) {
	   getline(&buffer, &bufsize, File);
    }

    char *temp;

    temp = (char *) malloc((strlen((buffer)) - 1) * sizeof(char));

    for (int i = 0; i < strlen((buffer)) - 1;i ++) {
		temp[i] = buffer[i];
    }
  
    return temp;
}

int thereis(char feature[32], char *element) {

    FILE *File = fopen(feature,"r");
    int FileLines = countlines(feature);
    size_t bufsize = 64;
    char *buffer;
    char *temp;
    buffer = (char *)malloc(bufsize * sizeof(char));

    for (int i = 1; i <= FileLines; i++) {
	   getline(&buffer, &bufsize, File);
       	   temp = (char *) malloc((strlen((buffer)) - 1) * sizeof(char));

	   for (int i = 0; i < strlen((buffer)) - 1;i ++) {
   		   temp[i] = buffer[i];
	   }
       
      if (strcasecmp(element,temp) == 0) { return 1; }

    }

    return 0;
}


char *match(char feature[64], char *element) {

    FILE *File = fopen(feature,"r");
    
    char pathComunidade[64] = "./txts/Comunidades/Comunidades";

    int FileLines = countlines(feature);
    size_t bufsize = 64;
    char *buffer;
    char *temp;
    buffer = (char *)malloc(bufsize * sizeof(char));

    for (int i = 1; i <= FileLines; i++) {
	   getline(&buffer, &bufsize, File);
       	   temp = (char *) malloc((strlen((buffer)) - 1) * sizeof(char));

	   for (int i = 0; i < strlen((buffer)) - 1;i ++) {
   		   temp[i] = buffer[i];
	   }

      if (strcasecmp(element, temp) == 0) { return temp; }

    }

    return "NULL";
}


