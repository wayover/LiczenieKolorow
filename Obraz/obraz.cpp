#include"obraz.h"


obraz::obraz() :											//konstruktor bezparametrowy
	wysokosc(1),
	szerokosc(1)
{}



obraz::obraz(const obraz &t) :								//konstruktor kopiujacy		
	wysokosc(t.wysokosc),
	szerokosc(t.szerokosc)
{}



obraz::obraz(const obraz &&t) :								//konstruktor kopiujacy		
	wysokosc(t.wysokosc),
	szerokosc(t.szerokosc)
{}


obraz::~obraz()												//desruktor pusty poniewaz brak alokowanej pamieci
{

}




obraz obraz::operator=(const obraz & t)						//operator przypisania							
{
	if (this == &t)					//ochrona przed przyposaniem do samego siebie
	{
		return *this;
	}

		szerokosc = t.szerokosc;
		wysokosc = t.wysokosc;
	

	return *this;
}


obraz obraz::operator=(const obraz && t)					//operator przypisania przenaszacy
{
	if (this == &t)					//ochrona przed przyposaniem do samego siebie
	{
		return *this;
	}

	szerokosc = t.szerokosc;
	wysokosc = t.wysokosc;
	return *this;
}




RGB obraz::pobierzPiksel(int wiersz, int kolumna) const		//metoda zwracajaca kontener
{
	return piksele[wiersz* pobierzSzerokosc()+ kolumna];
}



int obraz::pobierzWysokosc() const							//metoda zwracajaco wysokosc
{
	return wysokosc;
}



int obraz::pobierzSzerokosc() const							//metoda zwracajaca szerokosc
{
	return szerokosc;
}