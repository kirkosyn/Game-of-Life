MAIN=main
SIM=simulation
OPEN=openfile
GEN=generate
VAR=variables

# nazwa pliku wynikowego
WYNIK=wynik

# tu definiuje zbudowanie calego programu z czastkowych modulow
all: clean $(VAR).o $(OPEN).o $(GEN).o $(SIM).o $(MAIN).o $(WYNIK)
	@echo "Kompilacja zakonczona sukcesem!"

#modul VAR
$(VAR):
	gcc -c $(VAR).c -o $(VAR).o

# modul OPEN
$(OPEN):
	gcc -c $(OPEN).c -o $(OPEN).o

# modul GEN
$(GEN):
	gcc -c $(GEN).c -o $(GEN).o

# modul SIM
$(SIM): 
	gcc -c $(SIM).c -o $(SIM).o

# modul MAIN
$(MAIN):
	gcc -c $(MAIN).c -o $(MAIN).o

# tutaj nastepuje konsolidacja stworzonych wczesniej plikow obiektowych
$(WYNIK): 
	gcc $(MAIN).o $(SIM).o $(GEN).o $(OPEN).o $(VAR).o -o $(WYNIK)

# sprzatanie wynikow pracy kompilatora
clean:
# @ na poczatku linijki oznacza ze nie wyswietlamy komendy
	@rm -f $(WYNIK) $(MAIN).o $(SIM).o $(GEN).o $(OPEN).o $(VAR).o
# echo pozwala na wyswietlanie napisow
	@echo "Posprzatane!"
