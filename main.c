#include <stdio.h>
#include <stdlib.h>

/*#include "generate.c"
#include "openfile.c"
#include "simulation.c"*/

int main()
{
    int opcja, spr;

    while (1)
    {
          printf("Wybierz opcje symulacji gry w zycie:\n1 - wczytanie tablicy komorek z pliku\n2 - wygenerowanie losowej struktury\n");
          scanf("%d", &opcja);      //wybranie opcji symulacji

          switch (opcja)
          {
                 case 1:        //opcja wczytania tablicy z pliku
                 {
                      spr = odczyt_pliku_tekstowego();

                      //jezeli podczas odczytu danych z pliku zostana wczytane zle znaki, program konczy dzialanie
                      if (spr == 1)
                      {
                         printf("Zle dane! Program konczy dzialanie.\n");
                         return 0;
                      }
                      //jezeli podczas odczytu danych z pliku zostanie przekroczony rozmiar szablonu, program konczy dzialanie
                      if (spr == 2)
                      {
                         printf("Przekroczony rozmiar szablonu! Program konczy dzialanie.\n");
                         return 0;
                      }
                      //jezeli wystapi problem z odczytaniem pliku, program konczy dzialanie
                      if (spr == 3)
                        return 0;

                      symulacja();      //wykonanie symulacji
                      return 0;
                 }
                 case 2:
                 {
                      generator();      //wygenerowanie szablnonu
                      symulacja();      //wykonanie symulacji
                      return 0;
                 }
                 default:           //w przypadku wybrania zlej opcji, program prosi o podanie jej jeszcze raz
                 {
                        printf("Nie ma takiej opcji!\n");
                        break;
                 }
          }
    }

    return 0;
}
