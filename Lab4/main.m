dane = csvread('litery.csv', 0, 0)

%figure                                        
%colormap(gray);                              
%for i = 1:20
 %   digit = reshape(dane(i, 1:end), [7,8])'
  %  imagesc(digit)                              
%end

wagi = (rand(56,1)*2) - 1 %3 neurony, 56 wejœæ dla ka¿dego
przed=sin(dane*wagi)
wagi=Uczenie_Hebba(wagi, dane, 0.3, 10000, 1);
bez_zapamietywania=sin(dane*wagi)

wagi = (rand(56,1)*2) - 1 %3 neurony, 56 wejœæ dla ka¿dego
przed=sin(dane*wagi)
wagi=Uczenie_Hebba(wagi, dane, 0.3, 10000, 2);
z_zapamietywaniem=sin(dane*wagi)

dane = csvread('litery2.csv', 0, 0);
z_zapamietywaniem2=sin(dane*wagi)


function [wagi] = Uczenie_Hebba(wagi, dane_wejsciowe,wspolczynnik_uczenia,kroki_uczenia,zapominanie)
    lp.lr = wspolczynnik_uczenia;
    lp.dr=0.999;
    for k = 1:kroki_uczenia
        wartosc=sin(dane_wejsciowe*wagi)';
        if (zapominanie == 1)  
            wagi=wagi+learnh([],dane_wejsciowe',[],[],wartosc,[],[],[],[],[],lp,[])';
        end
        if(zapominanie == 2)
            wagi=wagi+learnhd(wagi',dane_wejsciowe',[],[],wartosc,[],[],[],[],[],lp,[])';
        end
    end
end

