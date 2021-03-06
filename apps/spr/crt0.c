/*
 * \o/
 * Gramado Operating System - The main file for the shell.
 * (c) Copyright 2015~2018 - Fred Nora.
 *
 * File: crt0.c
 *
 * Environment: Gramado Core.
 * Usado para inicializar a rt na libc
 */


#include "spr.h"


static char *argv[] = { 
    "-interactive",        //shell interativo
	"-login",              //login
	"Gramado Core Shell",  //nome do shell
	"test.sh",             //nome do arquivo de script.
	NULL 
};


// Fake environment.
static char *envp[] = { 
    "VFSROOT=root:/volume0",           //root dir do vfs
    "BOOTVOLUMEROOT=root:/volume1",    //root dir do volume de boot
    "SYSTEMVOLUMEROOT=root:/volume2",  //root dir do volume do sistema
	NULL 
};


extern int main ( int argc, char *argv[] );



#define xxxLSH_TOK_DELIM " \t\r\n\a" 
#define xxxSPACE " "
#define xxxTOKENLIST_MAX_DEFAULT 80


//
// Main function in C part.
// The entry point is in head.s
//

int crt0 (){
	
	char *tokenList[xxxTOKENLIST_MAX_DEFAULT];
	char *token;
	int token_count;
	int index;	
	
	int retval;
	
	// #importante
	// Linha de comandos passada pelo shell.
	char *shared_memory = (char *) (0xC0800000 -0x100);	
	
	
#ifdef TEDITOR_VERBOSE	
	
	printf("\n");
	printf("crt0:\n");
	printf("Initializing Sprinkler ...\n\n");	
	//printf("\n");
	//printf(".\n");
	printf("..\n");
	printf("# MESSAGE={%s} #\n", shared_memory );
	printf("..\n");
	//printf(".\n");
	//printf("\n");
	
	//#debug
	//while(1){
	//	asm ("pause");
	//}
	
#endif
	

    // Criando o ambiente.
	// Transferindo os ponteiros do vetor para o ambiente.

	tokenList[0] = strtok ( &shared_memory[0], xxxLSH_TOK_DELIM );
	
 	// Salva a primeira palavra digitada.
	token = (char *) tokenList[0];
 
	index = 0;                                  
    while ( token != NULL )
	{
        // Coloca na lista.
        // Salva a primeira palavra digitada.
		tokenList[index] = token;

		//#debug
        //printf("shellCompare: %s \n", tokenList[i] );
		
		token = strtok ( NULL, xxxLSH_TOK_DELIM );
		
		// Incrementa o índice da lista
        index++;
		
		// Salvando a contagem.
		token_count = index;
    }; 

	//Finalizando a lista.
    tokenList[index] = NULL;	
	
	
	// #debug 
	// Mostra argumentos.
#ifdef TEDITOR_VERBOSE	
	// Mostra a quantidade de argumentos. 	
	printf("\n");
	printf("token_count={%d}\n", token_count );
	
	//Mostra os primeiros argumentos.
	for ( index=0; index < token_count; index++ )
	{
		token = (char *) tokenList[index];
	    if ( token == NULL )
		{
			printf("crt0: for fail!\n")
			goto hang;
		}
	    printf("# argv{%d}={%s} #\n", index, tokenList[index] );		
	};
#endif	
	
    
   	libcInitRT ();
	stdioInitialize ();	 
	

#ifdef TEDITOR_VERBOSE		
    //Inicializando o editor propriamente dito.	
	printf("Calling main ... \n"); 
#endif	

    retval = (int) main ( token_count, tokenList );
	
	switch (retval)
	{
		case 0:
		    printf("crt0: main returned 0.\n");
			exit (0);
			break;
			
		case 1:
		    printf("crt0: main2 returned 1.\n");
		    exit (1);
			break;
			
		//...
		
	    default:
		    printf("crt0: main2 returned default\n");
            exit (-1);
			break; 		
	};
			
    printf ("*HANG\n");
	exit (-1);
}

