//******************************************************************************************************************************
//
// Klasa: obraz
//
// Opis klasy:
// klasa przechowujaca zmienne wysokosc, szerokosc i kontener
//
// Autor:
// Kamil Wi�niewski	
//
// Historia zmian:
// Jaka zmiana:							Data zmiany:
// stworzenie klasy						24/11/2018
// stworzenie struktury i przestrzeni   25/11/2018
// poprawki i dodanie komentarzy		01/12/2018							
//
//******************************************************************************************************************************




#ifndef OBRAZ_H_
#define OBRAZ_H_

#include<vector>




struct RGB															//struktura dla trzech kolor�w										
{
	unsigned char czerwony;
	unsigned char zielony;
	unsigned char niebieski;

	bool operator==(RGB const& inny) const
	{
		return (czerwony == inny.czerwony) && (zielony == inny.zielony) && (niebieski == inny.niebieski);
	}
};






namespace std													//Przestrze� wymagana przez unordered_map
{
	
	template <>
	struct hash<RGB>
		{
		std::size_t operator()(RGB const& piksel) const
		{
			return piksel.niebieski + piksel.zielony +piksel.czerwony;
		}
	};
}






class obraz
{


protected:														//zmiene chronione z powodu dziedziczenia
	int wysokosc;										//wysokosc
	int szerokosc;										//szerokosc
	std::vector<RGB> piksele;							//kontener





public:
	obraz();											//konstruktor bezparametrowy
	obraz(const obraz & t);								//konstruktor kopiuj�cy
	obraz(const obraz && t);							//konstruktor kopiuj�cy przenoszacy
	virtual ~obraz();									//destruktor wirtualny z powodu dziedziczenia
	obraz operator=(const obraz & t);					//operator przypisania
	obraz operator=(const obraz && t);					//operator przypisania przenoszacy
	RGB pobierzPiksel(int wiersz, int kolumna) const;	//metoda zwracajaca kontener
	int pobierzWysokosc() const;						//metoda zwracaj�ca wysoko��
	int pobierzSzerokosc() const;						//metoda zwracaj�ca szeroko��

};



#endif	// !OBRAZ_H_