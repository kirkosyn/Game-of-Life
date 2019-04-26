#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "variables.h"

// funkcja wyliczajaca liczbe sąsiadów i wypisujaca szablon
void symulacja(void)
{
    int i, j, x, suma = 0;

    sleep(czas);
    system("clear");

    //wypisanie planszy, ktora uzytkownik wpisal do pliku
    for (i = 0; i < MAXw; i++)
    {
        for (j = 0; j < MAXk; j++)
        {
            if (tab[i][j] == 0)
                printf("%s ", LITERA);
            else
                printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    for (x = 0; x < iloscPowtorzen; x++)
    {
        sleep(czas);
        system("clear");
        for (i = 0; i < MAXw; i++)
        {
            for (j = 0; j < MAXk; j++)
            {
                //wyliczanie liczby sasiadow
                if (i - 1 < 0 && j - 1 < 0)         //komorka znajduje sie w lewym gornym rogu
                     suma = tab[i+1][j] + tab[i][j+1] + tab[i+1][j+1];
                else if (i + 1 >= MAXw && j + 1 >= MAXk)        //komorka znajduje sie w prawym dolnym rogu
                     suma = tab[i-1][j-1] + tab[i-1][j] + tab[i][j-1];
                else if (i - 1 < 0)         //komorka znajduje sie na samym poczatku wiersza
                   suma = tab[i+1][j] + tab[i][j-1] + tab[i][j+1] + tab[i+1][j-1] + tab[i+1][j+1];
                else if (j - 1 < 0)         //komorka znajduje sie w pierwszym wierszu
                     suma = tab[i+1][j] + tab[i-1][j] + tab[i-1][j+1] + tab[i][j+1] + tab[i+1][j+1];
                else if (i + 1 >= MAXw)         //komorka znajduje sie na samym koncu wiersza
                     suma = tab[i-1][j-1] + tab[i-1][j] + tab[i-1][j+1] + tab[i][j-1] + tab[i][j+1];
                else if (j + 1 >= MAXk)            //komorka znajduje sie w ostatnim wierszu
                     suma = tab[i-1][j-1] + tab[i+1][j] + tab[i-1][j] + tab[i][j-1] + tab[i+1][j-1];
                //komorka znajduje sie w srodku tablicy
                else suma = tab[i-1][j-1] + tab[i-1][j] + tab[i-1][j+1] + tab[i][j-1] + tab[i][j+1] + tab[i+1][j-1] + tab[i+1][j] + tab[i+1][j+1];

                //jezeli pierwotnej komorka nie bylo i to miejsce na planszy otaczaly 3 komorki zyjace, to w tym
                //miejscu w nastepnym etapie rodzi sie nowa komorka, w przeciwnym wypadku miejsce to pozostaje puste
                if (tab[i][j] == 0)
                {
                   if (suma == 3)
                      tab2[i][j] = 1;
                   else tab2[i][j] = 0;
                }
                //jezeli pierwotna komorka zyla i to miejsce na planszy otaczaly 2 lub 3 komorki, to komorka
                //w nastepnym etapie pozostaje przy zyciu, w pyrzpadku mniejszej lub wiekszej liczby komorek
                //pierwotna komorka ginie
                else
                {
                    if (suma == 2 || suma == 3)
                       tab2[i][j] = 1;
                    else tab2[i][j] = 0;
                }
            }
        }

        //wypisanie wartosci z talbicy tab2
        for  (i = 0; i < MAXw; i++)
        {
             for (j = 0; j < MAXk; j++)
             {
                if (tab2[i][j] == 0)
                    printf("%s ", LITERA);
                else
                    printf("%d ", tab2[i][j]);
             }
             printf("\n");
        }

        //skopiowanie wartosci tab2 do tablicy tab
        for  (i = 0; i < MAXw; i++)
        {
             for (j = 0; j < MAXk; j++)
                 tab[i][j] = tab2[i][j];
        }
    }

    sleep(czas);
    printf("\nZakonczono symulacje gry w zycie\n");
}
