#include <stdio.h>
#include <string.h>
#include "trace.h"



int main(int argc, char *argv[]){

	char str[250];
	gets( str );
	if ( strlen( str ) == 0 ){ lireop(); } //chaine vide ==> afficher trace.txt
	else { savop(str); printf("le résultat est sauvegardé dans trace\n") ;} 
}

void savop( char* lop) {

	FILE* f;
	f = fopen("trace.txt","a");
	strcat(lop,"\n");
	fputs(lop,f);
	fclose(f);
}

void lireop(){

	FILE* f;
	char line[250];
	f = fopen("trace.txt","r");
        printf("=================================================\n");
	while (fgets(line, sizeof(line),f)){
                printf("==========!============!===========!==========!\n");
		printf("%s", line);
                printf("==========!============!===========!==========!\n");

	}

	fclose(f);
}
