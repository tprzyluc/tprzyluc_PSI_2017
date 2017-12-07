clear all; close all; clc;  

%DEKLARACJE DANYCH WEJSCIOWYCH - TABLIC z LITERAMI
 CharacterA = [0 1 1 1 0;
               1 0 0 0 1;
               1 1 1 1 1;
               1 0 0 0 1;
               1 0 0 0 1];
 
 CharacterB = [1 1 1 1 0;
               1 0 0 0 1;
               1 1 1 1 0;
               1 0 0 0 1;
               1 1 1 1 0]; 

 CharacterC = [0 1 1 1 1;
               1 0 0 0 0;
               1 0 0 0 0;
               1 0 0 0 0;
               0 1 1 1 1];
 
 CharacterD = [1 1 1 1 0;
               1 0 0 0 1;
               1 0 0 0 1;
               1 0 0 0 1;
               1 1 1 1 0];
 
 CharacterE = [1 1 1 1 1;
               1 0 0 0 0;
               1 1 1 1 0;
               1 0 0 0 0;
               1 1 1 1 1];
 
 CharacterF = [1 1 1 1 1;
               1 0 0 0 0;
               1 1 1 1 0;
               1 0 0 0 0;
               1 0 0 0 0]; 
 
 CharacterG = [0 1 1 1 1;
               1 0 0 0 0;
               1 0 1 1 1;
               1 0 0 0 1;
               0 1 1 1 0];
 
 CharacterH = [1 0 0 0 1;
               1 0 0 0 1;
               1 1 1 1 1;
               1 0 0 0 1;
               1 0 0 0 1];
 
 CharacterI = [0 1 1 1 0;
               0 0 1 0 0;
               0 0 1 0 0;
               0 0 1 0 0;
               0 1 1 1 0];
 
 CharacterJ = [0 1 1 1 1;
               0 0 0 0 1;
               0 0 0 0 1;
               0 1 0 0 1;
               0 0 1 1 1];
 
 CharacterK = [1 0 0 1 1;
               1 0 1 0 0;
               1 1 0 0 0;
               1 0 1 0 0;
               1 0 0 1 1];
 
 CharacterL = [1 0 0 0 0;
               1 0 0 0 0;
               1 0 0 0 0;
               1 0 0 0 0;
               1 1 1 1 1];
 
 CharacterM = [1 0 0 0 1;
               1 1 0 1 1;
               1 0 1 0 1;
               1 0 0 0 1;
               1 0 0 0 1];
 
 CharacterN = [1 0 0 0 1;
               1 1 0 0 1;
               1 0 1 0 1;
               1 0 0 1 1;
               1 0 0 0 1];
  
 CharacterO = [0 1 1 1 0;
               1 0 0 0 1;
               1 0 0 0 1;
               1 0 0 0 1;
               0 1 1 1 0];
 
 CharacterP = [1 1 1 1 0;
               1 0 0 0 1;
               1 1 1 1 0;
               1 0 0 0 0;
               1 0 0 0 0]; 
 
 CharacterR = [1 1 1 1 0;
               1 0 0 0 1;
               1 1 1 1 0;
               1 0 0 1 0;
               1 0 0 0 1]; 
 
 CharacterS = [0 1 1 1 1;
               1 0 0 0 0;
               0 1 1 1 0;
               0 0 0 0 1;
               1 1 1 1 0]; 
 
 CharacterT = [1 1 1 1 1;
               0 0 1 0 0;
               0 0 1 0 0;
               0 0 1 0 0;
               0 0 1 0 0]; 

 CharacterU = [1 0 0 0 1;
               1 0 0 0 1;
               1 0 0 0 1;
               1 0 0 0 1;
               0 1 1 1 0];
 
           
%TWORZENIE SIECI
iterator=1;

%ZEROWANIE MACIERZY POMOCNICZNEJ DO WYNIKOW KONCOWYCH
dane = zeros(5*5, 20);

for i = 1 : 5 
    for j = 1 : 5 
    dane(iterator, :) = [CharacterA(i, j) CharacterB(i, j) CharacterC(i, j) CharacterD(i, j) CharacterE(i, j) CharacterF(i, j) CharacterG(i, j) CharacterH(i, j) CharacterI(i, j) CharacterJ(i, j) CharacterK(i, j) CharacterL(i, j) CharacterM(i, j) CharacterN(i, j) CharacterO(i, j) CharacterP(i, j) CharacterR(i, j) CharacterS(i, j) CharacterT(i, j) CharacterU(i, j)];
    iterator=iterator+1;
    end
end

%TRANSPONOWANIE MACIERZY
dane = dane';

%MACIERZ LITERY DO TESTOWANIA M

%WAGI INICJOWANE MASZYNOWO LUB WPISYWANE RECZNIE
Wagi = zainicjuj_wagi(size(dane,2));

%TESTOWANIE SIECI HEBBA DLA DANYCH POCZATKOWYCH
Testowanie_Hebba(Wagi, dane);

%AKTUALIZACJA WAG W UCZENIU HEBBA
Wagi = Uczenie_Hebba(Wagi, dane, 0.6 , 10000, 1); 

%TESTOWANIE HEBBA DLA AKTUALIZOWANYCH DANYCH
Testowanie_Hebba(Wagi, dane);

%wYZNACZENIE WARTOSCI NA WYJSCIU DLA TESTOWANEJ LITERY

%FUNKCJA INICJUJACA WAGI
function [wagi] = zainicjuj_wagi(rozmiar)
    wagi = (rand(rozmiar,1)*2) - 1;
end

%FUNKCJA WYZNACZAJACA WARTOSC DLA PODANEJ LITERY TESTOWEJ
function [wyjscie] = wyznacz_wartosc(dane,wagi)
    wektor_wag = wagi'*dane';
    wyjscie = sin(wektor_wag);
end

%FUNKCJA AKTUALIZUJACA WAGI BEZ WSPOLCZYNNIKA ZAPOMINANIA
function [aktualizowane_wagi] = aktualizuj_wagi_bez_zapominania(wagi,wartosc,dane,wspolczynnik_uczenia)
    aktualizowane_wagi = wagi + (wspolczynnik_uczenia*wartosc)*dane';
end

%FUNKCJA AKTUALIZUJACA WAGI ZE WSPOLCZYNNIKIEM ZAPOMINANIA
function [aktualizowane_wagi] = aktualizuj_wagi_z_zapominaniem(wagi,wartosc,dane,wspolczynnik_uczenia,wspolczynnik_zapominania)
    aktualizowane_wagi = wagi*(1-wspolczynnik_zapominania) + (wspolczynnik_uczenia*wartosc)*dane';
end

%NUMEL = Number of array elements
%FUNKCJA WYPISUJACA WEKTOR WAG
function [] = wypisz_wektor_wag(wektor_wag)
    for i = 1:numel(wektor_wag)
        fprintf(' %f',wektor_wag(i));
    end
    fprintf('\n');
end

%FUNKCJA REALIZUJACA UCZENIE METODA HEBBA
function [wagi] = Uczenie_Hebba(wagi, dane_wejsciowe,wspolczynnik_uczenia,kroki_uczenia,zapominanie)
fprintf('WAGI WEJSCIOWE:\n');
wypisz_wektor_wag(wagi);
for k = 1:kroki_uczenia
    for i = 1:size(dane_wejsciowe,1)
        wartosc = wyznacz_wartosc(dane_wejsciowe(i,:),wagi);
        if (zapominanie == 1)
        wagi = aktualizuj_wagi_bez_zapominania(wagi,wartosc,dane_wejsciowe(i,:),wspolczynnik_uczenia);
        end
        if(zapominanie == 2)
        wagi = aktualizuj_wagi_z_zapominaniem(wagi,wartosc,dane_wejsciowe(i,:),wspolczynnik_uczenia, 0.05);
        end
    end
end
fprintf('WAGI WYJSCIOWE:\n');
wypisz_wektor_wag(wagi);
end

%FUNKCJA REALIZUJACA TESTOWANIE SIECI UCZONEJ METODA HEBBA
function [] = Testowanie_Hebba(wagi,dane) 
    fprintf('TEST: \n');
    rozmiar = size(dane,1);
    for i = 1:rozmiar
        wartosc = (wyznacz_wartosc(dane(i,:),wagi));
        fprintf('%f \n', wartosc);
    end
end