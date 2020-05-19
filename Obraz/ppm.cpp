#include"ppm.h"
#include<fstream>




ppm::ppm()																	//konstruktor bezparametrowy	 brak sk³adowych dlatego pusty
{
}


	
ppm::ppm(const ppm & t)														//konstruktor kopiujacy		brak sk³adowych dlatego pusty
{
}



ppm::~ppm()																	//desruktor pusty poniewaz brak alokowanej pamieci
{
}



ppm ppm::operator=(const ppm & t)											//operator przypisania			brak skladowych dlatego pusty							
{

	return *this;
}




ppm::ppm(std::string const& sciezkaDoPliku)										//konstruktor ze sciezka do pliku
{
	laduj(sciezkaDoPliku);
}




void ppm::laduj(std::string const& sciezkaDoPliku)								//metoda ladujaca plik
{


	std::ifstream plik{sciezkaDoPliku};
	if (!plik.is_open())
	{
	throw std::invalid_argument{"Plik " + sciezkaDoPliku + " nie istnieje"};
	}





	std::string token;


	if (!(plik >> token) || token.find("P3") == std::string::npos)				//sprawdzenie formatu
	{
	throw std::invalid_argument{"Plik " + sciezkaDoPliku + " ma nieznany format"};
	}





	if (plik >> token)														//pomijanie komentarza
	{

		if (token.find("#") != std::string::npos)
		{
			getline(plik, token);
			plik >> token;
		}
	}




	try																		//pobranie szeokosci i wysokosci
	{
		szerokosc = stoi(token);
		plik >> token;
		wysokosc = stoi(token);
		plik >> token;
	}




	catch (...)
	{
		throw std::invalid_argument{"Plik " + sciezkaDoPliku + " jest uszkodzony"};
	}





	piksele.clear();


	for (int i = 0, liczbaPikseli = szerokosc * wysokosc; i  < liczbaPikseli; i++)								
	{
		int czerwony, zielony, niebieski;
		if (plik >> czerwony >> zielony >> niebieski)
		{
			piksele.push_back({(unsigned char)czerwony, (unsigned char)zielony, (unsigned char)niebieski});
		}
		else 
		{
			throw std::invalid_argument{"Plik " + sciezkaDoPliku + " jest uszkodzony"};
		}
	}
}