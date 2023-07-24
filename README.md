# Prüfung SoSe 2023 Aufgabe 4
In diesem Repo befindet sich das Programm das zur Lösung der Aufgabe 4 der Ausarbeitung erstellt wurde. Diese Programm wurde in der Programmiersprache C geschrieben. Das Programm soll ein Datum in dem Format YYYY-MM-DD über die Kommandozeile entgegennehmen und ausgeben um welchen Wochentag es sich hierbei handelt.

Die Datei main_1.c enthält die Teilaufgabe 1 mit dem Definitionsbereich YYYY-MM-DD > 2024-01-01.

Die Datei main_2.c enthält die Teilaufgabe 2 mit dem erweiterten Definitionsbereich von 1900-01-01 < YYYY-MM-DD < heute. Für das heutige Datum wurde 2023-12-12 festgelegt, da heute natürlich abhängig vom Tag des Betrachtens ist und somit das restliche Jahr abgebildet wird. 

Die Datei main_3.c enthält das Programm mit dem Definitionsbereich erweitert bis zum 0000-01-01. Dieses Programm wurde erstellt um die Funktion zum berechnen und später in der Teilaufgaben zu verwenden. 

Zur Hilfe der [Berechnung der Wochentage wurde der Algorithmus](https://de.wikipedia.org/wiki/Wochentagsberechnung#Programmierung) von [Christian Zeller](https://de.wikipedia.org/wiki/Christian_Zeller_(Mathematiker)) aus dem Jahre 1882 verwendet.

## Format der Übergabe 
Wie bereits erwähnt erfolgt die Übergabe in dem Format: YYYY-MM-DD
- YYYY: Jahr in vierstelliger Form (Bsp.: 2023, 0132, 0023, 0003)
- MM: Monat in zweistelliger Form (Bsp.: 02, 06, 11) 
- DD: Tag in zweistelliger Form (Bsp.: 01, 06, 12, 23, 30)
 
## Kompilation 
Das Programm kann einfach mit einem beliebigen Compiler kompiliert werden. Ich habe dafür gcc verwendet. Es muss allerdings die Verlinkung für die library math.h hinzugefügt werden.

Beispiel: 
```
gcc main_1.c -o main_1.elf -lm
```

## Ausführung 
Um das Programm auszuführen muss der Befehl zum ausführen des Programms eingegeben werden. Zusätzlich muss die Option -d und ein Datum im oben erwähnten Format übergeben werden.

Beispiel für Ubunt/WSL:
```
./main.elf -d 2023-08-16 
```
