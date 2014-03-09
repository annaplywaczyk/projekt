/*
 * uruchom.hh
 *
 *  Created on: 8 mar 2014
 *      Author: Ania
 */

#ifndef URUCHOM_HH_
#define URUCHOM_HH_

/*!
 * \file
 * \brief Definicja klasy zegar
 *
 * Plik zawiera definicje klasy zegar, ktora jest klasa glowna programu.
 * Klasa ta jest pochodna i specjalizacja klasy dane.
 */
#include "dane.hh"
#include <windows.h>

using namespace std;
/*!
 * \brief Klasa modeluje uruchomienia g�ownych wlasciowosci programu.
 * Atrybutem klasy sa stowrzone dwa elemnty klasy dane, na ktorych wykonywane sa dzialania.
 */

class zegar{
private:
	/*!
	 * \brief Element podsatwowy klasy dane.
	 * Dane_podstawowe sa elementem klasy dane, na ktorych wykonywany jest alagorytm
	 * oraz jest jakby glownym elementem programu.
	 */
	dane dane_podstawowe;
	/*!
	 * \brief Element sprawdzajacy klasy dane.
	 * Dane_sprawdzjace sa elementem klasy dane, wektor ten wykorzystywany jest do porownania
	 * wykannego algorytmu z denymi podstawowymi.
	 */
	dane dane_sprawdzajace;
public:
	/*!
	 * \breif Wczytanie danych podstawowych
	 * Funkcja wczytuje dane, na ktorych wykonywany jest algorytm.
	 * Dane te sa glowna funkcja programu.
	 * \param[in] nazwa_pliku_pod - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty.
	 * \return (brak)
	 */
	void wczytaj_dane_pod(string nazwa_pliku_pod){
		dane_podstawowe.wczytaj(nazwa_pliku_pod);
	}
	/*!
	 * \breif Wczytanie danych sprawdzajacych
	 * Funkcja wczytuje dane, na ktore zostaja porwonane z danymi na ktorych
	 * zostal wykonany algorytm.
	 * \param[in] nazwa_pliku_spr - jest to zmienna ktora jest ciagiem
	 * znakow (nazwa pliku), ktory ma zostac otwarty, w celu porownania.
	 * \return (brak)
	 */
	void wczytaj_dane_spr(string nazwa_pliku_spr){
		dane_sprawdzajace.wczytaj(nazwa_pliku_spr);
	}
	/*!
	* \brief Funkcja wykonuj�ca zadany algorytm na wektorze.
	* Funkcja wykonuje zadany algorytm na wektorze wejsciowym.
	* W naszym przypadku wektor pomno�ony jest przez sta�� liczb� 2.
	* \return (brak)
	*/
	void algorytm();
	/*!
	* \brief Funkcja por�wnuj�ca dwa wektory.
	* Funkcja por�wnuje dwa wektory, sprawdza czy wszystkie elemnty s� ze sob� r�wne.
	* \return Funkcja zwraca true jezeli wektory sa jednakowe w przeciwnym wypadku zostaje wzrocony false.
	*/
	bool porownaj(){
		return dane_podstawowe==dane_sprawdzajace;
	}
	/*!
	* \brief Funkcja zapamietuj�ca czas poczatkowy.
	* Funkcja nale��ca do biblioteki "windows.h",  stoper zostaje w��czony.
	* Funkcja nale��ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je�eli w�aczenie zako�czy si� sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b��d i zwr�ci wartosc 0. Dla komputer�w multiprocesorowych nie ma znaczenia, kt�ry jest u�ywany,
	* mog� jedynie r�ni� si� minimalnie czasy.
	*/
	LARGE_INTEGER wlaczStoper();
	/*!
	* \brief Funkcja zapamietuj�ca czas ko�cowy.
	* Funkcja nale��ca do biblioteki "windows.h",  stoper zostaje wy��czony, aby zosta� zmierzony czas wykonania
	* algorytmu w programie, poprzez odj�cie czasu pocz�tkowego od czasu ko�cowego.
	* Funkcja nale��ca do funkcji bool QueryPerformanceCounter(_out LARGE_INTEGER *IpPerformanceCount),
	* funkcja ta zwraca wartosc niezerowa je�eli wy�aczenie zako�czy si� sukcesem, natomiast w przeciwnym wypadku
	* zostanie wyrzucony b��d i zwr�ci wartosc 0. Dla komputer�w multiprocesorowych nie ma znaczenia, kt�ry jest u�ywany,
	* mog� jedynie r�ni� si� minimalnie czasy.
	*/
	LARGE_INTEGER wylaczStoper();

};




#endif /* URUCHOM_HH_ */
