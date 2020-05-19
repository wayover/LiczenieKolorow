//******************************************************************************************************************************
//
// Klasa: obraz
//
// Opis klasy:
// klasa wczytujaca plik i dodawanie wartosci go do konteneru
//
// Autor:
// Kamil Wiœniewski	
//
// Historia zmian:
// Jaka zmiana:							Data zmiany:
// stworzenie klasy						24/11/2018
// stworzenie wczytywania pliku		    25/11/2018
// poprawki i dodanie komentarzy		02/12/2018							
//
//******************************************************************************************************************************




#ifndef PPM_H							//ochrona przed wielokrotym wlaczeniem
#define PPM_H

#include"obraz.h"
#include<string>





class ppm : public obraz 
{


public:

	ppm();														//konstruktor bezparmetrowy
	ppm(const ppm & t);											//konstruktor kopiujacy
	virtual ~ppm();												//destruktor wirtualny z powodu dziedziczenia
	ppm operator=(const ppm & t);								//operator przypisania	

	explicit ppm(std::string const& sciezkaDoPliku);			//konstruktor ze sciezka do pliku
	void laduj(std::string const& sciezkaDoPliku);				//metoda ladujaca plik
};


#endif // !PPM_H_