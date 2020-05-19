#include <iostream>
#include<unordered_map>
#include "ppm.h"



int liczkolory(obraz const& ob);							//definicja funkcji



int main()
{
    obraz *ob;
    ob=new ppm("Lena.ppm");
    int kolor;
    kolor=liczkolory(*ob);
    std::cout<<"kolorow: "<<kolor;
    delete ob;

	system("pause");
    return 0;
}




int liczkolory(obraz const& ob)								//funkcja zliczaj¹ca kolory
{
		std::unordered_map<RGB, int> kolory;
		for (int wiersz = 0; wiersz < ob.pobierzWysokosc(); wiersz++) 
		{
			for (int kolumna = 0; kolumna < ob.pobierzSzerokosc(); kolumna++)
			{
				kolory[ob.pobierzPiksel(wiersz, kolumna)]++;
			}
		}
		return kolory.size();
}