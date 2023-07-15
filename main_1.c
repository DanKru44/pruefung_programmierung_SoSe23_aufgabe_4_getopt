#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main( int argc, char *argv[] ){

	int option;
	char *datum = NULL;
	int jahr, monat, tag;
	char *endPtr;
	char temp_jahr[4], temp_monat[3], temp_tag[3];

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
				else if ( optopt != 'd' )
				{
					fprintf( stderr, "Unbekannte Option -%c. Bitte die Option -d benutzen.\n", optopt );
	printf ( "%c\n", optopt );
				}
				return 1;
			default:
				abort();
				
		}
	}
	
	//01.01.2024 = Montag
	strncpy( temp_jahr, datum, 4);
	temp_jahr[4] = '\0';
	jahr = strtol( temp_jahr, &endPtr, 10 );

	printf( "Jahr: %i\n", jahr );
	
	for( int i = optind; i < argc ; i++ )
		printf ("%s ist ein unbekanntes Optionszeichen, bitte die Option -d benutzen.\n", argv[i] );
		
	return 0;
}
