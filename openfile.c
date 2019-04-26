#include <stdio.h>
#include <stdlib.h>
#include "variables.h"

//odczyt pliku i zapis do tablicy
int odczyt_pliku_tekstowego(void)
{
    FILE* fu;
    char c;
    int i = 0, j = 0;

    if ((fu = fopen(PLIK_TXT, "r")) != NULL)
    {
        while (!feof(fu))
        {
              //wczytywanie znakow z pliku
              fscanf(fu, "%c", &c);
              if (c != ' ' && c != '\n')
              {
                 if(c - 48 == 0 || c - 48 == 1)         //zapis do pliku jedynie cyfr 0 oraz 1
                 {
                      tab[i][j] = c - 48;
                      j++;
                 }
              }
              else if (c == '\n')       //przejscie do nastepnego wiersza w tablicy tab
              {
                   j = 0;
                   i++;
              }
              else if (c == ' ')
                    continue;
              //jezeli program napotka jakis nieznany znak, przerywa dzialanie
              if (c != -1 && c != ' ' && c != '\n' &&  (c - 48) != 0 && (c - 48) != 1)
              {
                       fclose(fu);
                       return 1;
              }
              //jezeli wielkosc tablicy w pliku jest wieksza niz wielkosc szablonu, program przerywa dzialanie
              if (j > MAXk || i > MAXw)
              {
                       fclose(fu);
                       return 2;
              }
        }
        fclose(fu);
    }
    else
    {
        printf("Nie moge odczytac pliku!\n");       //w przypadku problemow z odczytem pliku, program przerywa dzialanie
        return 3;
    }
    return 0;
}
