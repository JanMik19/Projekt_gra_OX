# Projekt_gra_OX

Moja wersja gry w kółko krzyżyk;

Opis:

klasa Gracz - przechowuje zmienną typu 'char', która w grze będzie reprezentować symbol gracza - nas(człowieka :D) i komputera. Symbol jest z góry zainicjalizowany w jednej z funkcji klasy AI - klasy reprezentująca komputer - jest tam główna fukcjagry (taki game loop). 

Klasy 'Czlowiek' i 'Komputer' są pochodnymi klasy 'Gracz', obie mają metody, które na swój sposób pozwalają dokonać poruszania się na planszy gry (plansza w grze jest reprezentowana jako dynamiczna tablica dwuwymiarowa);

Klasa "Kolko_Krzyzyk" jest, że tak można nazwać bazą całej gry. W klasie tej jest tworzona tablica, w której następnie będą przechowywane symbole obu graczy. Są metody alokacji pamięci do tej tablicy, uwalniania pamięci, wyświetlania tablicy oraz instrukji. Następnie są medoty sprawdzące stan tablicy, tzn. są sprawdzane konfiguracje oznaczające wygraną bądź remis, metody pozwalające "wrzucić" gracza na planszę itd, oczywiśie gettery, settery (prawda tylko pod inną nazwą:)). Niektóre wykorzystują biblioteki STL. Skorzystałem przede wszystkim z 'vector'
  
Co dotyczy warunków to są wykonane za pomocą instrukcji if(), else if(), jest warunek wykorzystujący wyjątki, jednak ten musiałbym pewnie poprawić, więcej przetestować...

W int main() jest kolejną pętla (do...while()), znajdują się pola do wprowadzenia, decydowania/kontynowania rozgrywki. Jest Dynamicznie alokowana pamięc do głowej funkcji (poprzez wskaxźnik na klasę bazową są tworzeni w konkretnej kolejności gracze, w zależności którą opcję gry wybrano).
