#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main( int argc , char *argv[] ){

	int option , case_erfuellt = 0 ;
	char datum[11] ;
	int jahr, monat , tag , wochentag , stelle_1_2_jahr , stelle_3_4_jahr , monat_julianisch ;
	char *endPtr ;
	char temp_jahr[5], temp_monat[3], temp_tag[3] ;

	while((	option = getopt ( argc , argv , "d:" ) ) != -1 )
	{
		switch ( option )
	   	{
			case 'd' :
				strncpy ( datum , optarg , 10 ) ;
				datum[10] = '\0' ;
				case_erfuellt = 1 ;
				break ;
			case '?' :
				if ( optopt == 'd' )
				{
					fprintf ( stderr , "Die Option -%c benötigt ein Datum in der Form YYYY-MM-DD.\n" , optopt ) ;
				}
				else if ( optopt != 'd' )
				{
					fprintf ( stderr , "Unbekannte Option -%c. Bitte die Option -d benutzen.\n" , optopt ) ;
	printf ( "%c\n" , optopt ) ;
				}
				return 1 ;
			default :
				abort() ;
				
		}
	}
	
	//Berechnung nach Algorithmus von Zeller
	if ( case_erfuellt == 1 )
	{
		strncpy ( temp_jahr , datum , 4 ) ;
		temp_jahr[4] = '\0' ;
		jahr = atoi ( temp_jahr ) ;
	
		strncpy ( temp_monat , datum + 5 , 2 ) ;
		temp_monat[2] = '\0' ;
		monat = strtol ( temp_monat , &endPtr, 10 ) ;

		strncpy ( temp_tag , datum + 8 , 2 ) ;
		temp_tag[2] = '\0' ;
		tag = strtol ( temp_tag , &endPtr , 10 ) ;
	

		printf ( "Jahr: %i\n", jahr ) ;	
		printf ( "Monat: %i\n", monat ) ;
		printf ( "Tag: %i\n", tag ) ;
			
		if ( monat == 1 || monat == 2 )
		{
			stelle_1_2_jahr = ( jahr / 100 ) - 1 ;
			stelle_3_4_jahr = ( jahr -1 ) - ( stelle_1_2_jahr * 100 ) ;
				
		}
		else
		{
			stelle_1_2_jahr	= jahr / 100 ;
			stelle_3_4_jahr = jahr - ( stelle_1_2_jahr * 100 ) ;
			printf("%i %i\n" , stelle_1_2_jahr , stelle_3_4_jahr ) ;	
		}
		
		monat_julianisch = abs(monat - 2) ;
		printf("%i\n" , monat_julianisch) ;	

		wochentag = ( tag + floor ( 2.6 * monat_julianisch - 0.2 ) + stelle_3_4_jahr + floor ( stelle_3_4_jahr / 4 ) + floor ( stelle_1_2_jahr / 4 ) - 2 * stelle_1_2_jahr ) ;
		wochentag = wochentag % 7 ;	
		printf("%i\n" , wochentag) ;	
		if ( wochentag < 0 )
		{
			wochentag = wochentag + 7 ;
		}
		printf( "Wochentag: %i\n" , wochentag ) ;

	}
	
	for ( int i = optind; i < ( argc - 1 ) ; i++ )
		printf ("%s ist ein unbekanntes Optionszeichen, bitte die Option -d benutzen.\n" , argv[i] ) ;
		
	return 0 ;
}
