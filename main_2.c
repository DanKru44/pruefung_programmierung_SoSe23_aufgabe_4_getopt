#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

void pruefung_schalter ( int argc_pruefung , char *argv_pruefung[] , int *case_pruefung , char *datum_pruefung)
{
	int option ;

	while ( ( option = getopt ( argc_pruefung , argv_pruefung , "d:" ) ) != -1 )
	{
		switch ( option )
		{
			case 'd' :
				strncpy ( datum_pruefung , optarg , 10 ) ;
				datum_pruefung[10] = '\0' ;
				*case_pruefung = 1 ;
				break ;
			case '?' :
				if ( optopt == 'd' )
				{
					fprintf ( stderr , "Die Option -%c benötigt ein Datum in der Form YYYY-MM-DD.\n" , optopt ) ;
				}
				else if ( optopt != 'd' )
				{
					fprintf ( stderr , "Unbekannte Operation -%c. Bitt die Option -d benutzen.\n" , optopt ) ;
				}
				return  ;
			default : 
				abort() ;
		}
	}
}

void unbekanntes_optionszeichen ( int argc_unbekannt , char *argv_unbekannt[] )
{
	for ( int i = optind ; i < argc_unbekannt ; i++ )
		printf ( "%s ist ein unbekanntes Optionszeichen, bitte die Option -d benutzen.\n" , argv_unbekannt[i] ) ;
}

void zuweisung_daten ( char *datum_daten , int *jahr_daten , int *monat_daten , int *tag_daten ) 
{
	char temp_jahr[5] , temp_monat[3] , temp_tag[3] ;
	char *endPtr ;

	strncpy ( temp_jahr , datum_daten , 4 ) ;
	temp_jahr[4] = '\0' ; 
	*jahr_daten = strtol ( temp_jahr , &endPtr , 10 ) ;

	strncpy ( temp_monat , datum_daten + 5 , 2 ) ;
	temp_monat[2] = '\0' ; 
	*monat_daten = strtol ( temp_monat , &endPtr , 10 ) ;

	strncpy ( temp_tag , datum_daten + 8 , 2 ) ;
	temp_tag[2] = '\0' ; 
	*tag_daten = strtol ( temp_tag , &endPtr , 10 ) ;
}
	
void berechnung_jahres_stellen ( int jahr_stellen , int monat_stellen , int *stelle_1_2_jahr_stellen , int *stelle_3_4_jahr_stellen )
{
	if ( monat_stellen == 1 || monat_stellen == 2 )
	{
		*stelle_1_2_jahr_stellen = ( jahr_stellen / 100 ) -1 ;
		*stelle_3_4_jahr_stellen = ( jahr_stellen - 1) - ( *stelle_1_2_jahr_stellen * 100 ) ;
	}
	else
	{
		*stelle_1_2_jahr_stellen = jahr_stellen / 100 ;
		*stelle_3_4_jahr_stellen = jahr_stellen - ( *stelle_1_2_jahr_stellen * 100 ) ;
	}
}

int berechnung_monat_julianisch ( int monat_gregorianisch )
{
	if ( monat_gregorianisch == 1 || monat_gregorianisch == 2 )
	{
		return monat_gregorianisch + 10 ;
	}
	else 
	{
		return monat_gregorianisch - 2 ;
	}
}
int berechnung_wochentagszahl ( int tag_tagzahl , int monat_julianisch_tagzahl , int stelle_1_2_jahr_tagzahl , int stelle_3_4_jahr_tagzahl)
{
	int wochentagzahl ;

	wochentagzahl = tag_tagzahl ;
	wochentagzahl += floor ( 2.6 * monat_julianisch_tagzahl - 0.2 ) ;
	wochentagzahl += stelle_3_4_jahr_tagzahl ;
	wochentagzahl += floor ( stelle_3_4_jahr_tagzahl / 4 ) ;
	wochentagzahl += floor ( stelle_1_2_jahr_tagzahl / 4 ) ;
	wochentagzahl -= 2 * stelle_1_2_jahr_tagzahl ;
	wochentagzahl = wochentagzahl % 7 ;

	if ( wochentagzahl < 0 )
	{
		wochentagzahl = wochentagzahl + 7 ;
	}

	return wochentagzahl ;
}

void zuweisung_tagname ( int tagzahl_zuweisung , char *wochentag_zuweisung ) 
{
	if ( tagzahl_zuweisung == 0 )
	{
		strcpy ( wochentag_zuweisung , "Sonntag" ) ;
	}
	else if ( tagzahl_zuweisung == 1 )
	{
		strcpy ( wochentag_zuweisung , "Montag" ) ;
	}
	else if ( tagzahl_zuweisung == 2 )
	{
		strcpy ( wochentag_zuweisung , "Dienstag" ) ;
	}
	else if ( tagzahl_zuweisung == 3 )
	{
		strcpy ( wochentag_zuweisung , "Mittwoch" ) ;
	}
	else if ( tagzahl_zuweisung == 4 )
	{
		strcpy ( wochentag_zuweisung , "Donnerstag" ) ;
	}
	else if ( tagzahl_zuweisung == 5 )
	{
		strcpy ( wochentag_zuweisung , "Freitag" ) ;
	}
	else if ( tagzahl_zuweisung == 6 )
	{
		strcpy ( wochentag_zuweisung , "Samstag" ) ;
	}
}


int main ( int argc , char *argv[] ) 
{
	int case_erfuellt = 0 ;
	int *case_erfuellt_pointer = &case_erfuellt ;
	int jahr , monat , monat_julianisch , tag ;
	int *jahr_pointer = &jahr ;
	int *monat_pointer = &monat ;
	int *tag_pointer = &tag ;
	int stelle_1_2_jahr , stelle_3_4_jahr ;
	int *stelle_1_2_jahr_pointer = &stelle_1_2_jahr ;
	int *stelle_3_4_jahr_pointer = &stelle_3_4_jahr ; 
	int nummer_wochentag ;
	char datum [11] ; 
	char wochentag [11] ;

	pruefung_schalter ( argc , argv , case_erfuellt_pointer , datum ) ;
	
	unbekanntes_optionszeichen ( argc , argv ) ;

	if ( case_erfuellt == 1 )
	{
		zuweisung_daten ( datum , jahr_pointer , monat_pointer , tag_pointer ) ;

		if ( jahr >= 1900 )
		{
			berechnung_jahres_stellen ( jahr , monat , stelle_1_2_jahr_pointer , stelle_3_4_jahr_pointer ) ;
		
			monat_julianisch = berechnung_monat_julianisch ( monat ) ;

			nummer_wochentag = berechnung_wochentagszahl ( tag , monat_julianisch , stelle_1_2_jahr , stelle_3_4_jahr ) ;
				
			zuweisung_tagname ( nummer_wochentag , wochentag ) ;

			printf ( "Wochentag: %s\n" , wochentag ) ;
		}

		else
		{
			printf ( "Das Datum liegt außerhalb des Definitonsbereiches. Bitte ein Datum > 1900-01-01 eingeben.\n" ) ;
		}

	}

	return 0 ;
}
