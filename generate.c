#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "variables.h"

//generowanie losowej planszy
void generator(void)
{
     int i, j, r, ile_razy;

     srand(time(NULL));

     ile_razy = rand() % (MAXw * MAXk) + 1;     //losowanie liczby wpisan do tablicy
     for (ile_razy; ile_razy > 0; ile_razy--)
     {
         i = rand() % MAXw;         //losowanie pozycji w wierszu
         j = rand() % MAXk;         //losowanie pozycji w kolumnie
         r = rand() % 2;            //losowanie wartosci 0 lub 1
         tab[i][j] = r;             //wpisanie tej wartosci do komorki w tablicy tab
     }
}
