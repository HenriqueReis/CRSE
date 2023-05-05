#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "d6.h"

int main(int argc, char *argv[]) 

{
	srand(time(NULL));
//	if (argc > 3) { printf("Número excessivo de argumentos! (Máximo 2) \n"); return 1;}
	printf("%s", generatefeature(argv[1],countlines(argv[1])));
       	return 0;
}
