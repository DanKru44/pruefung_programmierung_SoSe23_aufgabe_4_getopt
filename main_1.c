#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>


int main( int argc, char *argv[] ){

	int option;
	char *datum = NULL;

	while((	option = getopt( argc, argv, "d:")) !=-1)
	{
		switch ( option )
	   	{
			case 'd':
				datum = optarg;
				break;
			case '?':
				if ( optopt == 'd' )
				{
					fprintf( stderr, "Die Option -%c benötigt ein Datum in der Form YYYY-MM-DD.\n", optopt );
				}
				else if ( isprint( '-' ) && isprint( ( unsigned char ) optopt ) )
				{
					fprintf( stderr, "Unbekannte Option -%c. Bitte die Option -d benutzen.\n", optopt );
				}
				else
				{
					fprintf( stderr, "Unbekanntes Optionszeichen %c. Bitt die Option -d benutzen.\n", optopt );
				}
				return 1;
			default:
				abort();
				
		}
	}

	printf( "Datum: %s\n", datum );
	
//	for( int i = optind; i < argc ; i++ )
//		printf ("%s ist ein unbekanntes Optionszeichen, bitte die Option -d benutzen.\n", argv[i] );
		
	return 0;
}
