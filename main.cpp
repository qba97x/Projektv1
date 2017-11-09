#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <fstream>



using namespace std;

int pol = 0;
int kolor = 7;
int niebylo;
int wylosowana;
int gwarantowana = 0;
int wygrana = 0;
int milion = 0;
int bledna = 0;
char odpowiedz;
char poprawna;
int nrpytania;
int tab[30];
int koniecpetli = 0;
int pytaniedopublicznosci, telefonwykorzystano, polnapol, jakinumerpytania;
string trescpytania;
string mozliwaodpowiedz_a;
string mozliwaodpowiedz_b;
string mozliwaodpowiedz_c;
string mozliwaodpowiedz_d;


int KolorZielony()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}


int KolorCzcionki()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | kolor);
}



int zmianakoloru()
{

	int n = 1, z, wyjscie;
	while (wyjscie != 1)
	{
		system("cls");
		KolorCzcionki();
		cout << "\t\t\t\t ZMIANA KOLORU CZCIONKI \n" << endl;

		printf("\t\t\t        ______________________\n");
		printf("\t\t\t       |");

		if (n == 1) { KolorZielony(); }
		printf("     Bialy            ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 2) { KolorZielony(); }

		printf("     Niebieski        ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 3) { KolorZielony(); }

		printf("     Blekitny         ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 4) { KolorZielony(); }

		printf("     Czerwony         ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 5) { KolorZielony(); }

		printf("     Purpurowy        ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 6) { KolorZielony(); }
		printf("     Zolty            ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 7) { KolorZielony(); }

		printf("     Szary            ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 8) { KolorZielony(); }

		printf("     Powrot           ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t        ----------------------");



		z = getch();

		if (z == 72) { n--; }
		if (z == 80) { n++; }
		if (z == 72) { if (n == 0) { n = 8; } }
		if (z == 80) { if (n == 9) { n = 1; } }

		if (z == 13)
		{
			if (n == 1) {
				system("cls");
				kolor = 7;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na bialy";
				getch();
			}
			if (n == 2) {
				system("cls");
				kolor = 1;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Niebieski";
				getch();
			}
			if (n == 3) {
				system("cls");
				kolor = 3;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Blekitny";
				getch();
			}
			if (n == 4) {
				system("cls");
				kolor = 4;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Czerwony";
				getch();
			}
			if (n == 5) {
				system("cls");
				kolor = 5;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Purpurowy";
				getch();
			}
			if (n == 6) {
				system("cls");
				kolor = 6;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Zolty";
				getch();
			}
			if (n == 7) {
				system("cls");
				kolor = 8;
				KolorCzcionki();
				cout << "Zmieniono kolor czcionki na Szary";
				getch();
			}

			if (n == 8) { wyjscie = 1; }
		}
	}

}





int Opcje()
{
	int n = 1, z, wyjscie;
	while (wyjscie != 1)
	{
		system("cls");
		KolorCzcionki();
		cout << "\t\t\t\t    Ustawienia \n" << endl;
		printf("\t\t\t        ______________________\n");
		printf("\t\t\t       |");

		if (n == 1) { KolorZielony(); }
		printf("Zmien kolor czcionki");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");

		if (n == 2) { KolorZielony(); }
		printf("        Powrot        ");
		KolorCzcionki();
		printf("| \n");
		printf("\t\t\t        ----------------------");



		z = getch();

		if (z == 72) { n--; }
		if (z == 80) { n++; }
		if (z == 72) { if (n == 0) { n = 2; } }
		if (z == 80) { if (n == 3) { n = 1; } }

		if (z == 13)
		{
			if (n == 1) { zmianakoloru(); }
			if (n == 2) { wyjscie = 1; }
		}
	}

}





int listamilionerow()
{

	int wpisales;
	do
	{
		system("cls");
		cout << "1 - Czyszczenie listy" << endl;
		cout << "2 - Powroc do menu" << endl << endl;

		cout << "Ranking:" << endl;
		std::fstream plik;
		plik.open("milionerzy.mln", std::ios::in);
		if (plik.good() == true)
		{
			string plikzmienna[30];

			int i = 1;
			while (getline(plik, plikzmienna[i]))
			{
				cout << i << "." << plikzmienna[i] << endl;;
				i++;
			}
			plik.close();

			if (plikzmienna[1] == "") cout << "Brak milionerow." << endl;

			cin >> wpisales;
			if (wpisales == 1)
			{
				ofstream i("milionerzy.mln");
				i << "";
			}
		}
		else std::cout << "Nie mozna uzyskac dostepu do pliku! Byc moze plik nie istnieje!" << std::endl;
	} while (wpisales != 2);
}





int czypytaniejuzbylo()
{
	niebylo = 1;

	if (wylosowana == tab[wylosowana])
	{
		niebylo = 0;
	}

	if (niebylo == 1)
	{
		tab[wylosowana] = wylosowana;
	}
}








int kolaratunkowe_telefon()
{

	system("cls");
	cout << "                           Nawiazuje polaczenie z przyjacielem...";
	Sleep(3000);
	system("cls");
	cout << "                       Sadze, ze poprawna odpowiedz to " << poprawna << endl << endl;

	KolorZielony();
	cout << "Aby kontynuowac wcisnij dowolny przycisk...";
	KolorCzcionki();
	getch();
}







int kolaratunkowe_polnapol()
{
	if (poprawna == 'a' || poprawna == 'c')
	{
		mozliwaodpowiedz_b = "";
		mozliwaodpowiedz_d = "";
	}

	if (poprawna == 'b' || poprawna == 'd')
	{
		mozliwaodpowiedz_a = "";
		mozliwaodpowiedz_c = "";
	}
}








int kolaratunkowe_pytanie(int polnapol, int nr)
{



	if (poprawna == 'a' && nr == 0) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a - 64%" << endl;
		cout << "b -  5%" << endl;
		cout << "c -  5%" << endl;
		cout << "d - 23%" << endl << endl;
	}
	if (poprawna == 'a' && polnapol == 1 && nr == 1) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a - 69%" << endl;
		cout << "c - 31%" << endl << endl;
	}


	if (poprawna == 'b' && nr == 0) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a -  6%" << endl;
		cout << "b - 72%" << endl;
		cout << "c -  8%" << endl;
		cout << "d - 14%" << endl << endl;
	}
	if (poprawna == 'b' && polnapol == 1 && nr == 1) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "b - 79%" << endl;
		cout << "d - 21%" << endl << endl;
	}

	if (poprawna == 'c' && nr == 0) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a - 22%" << endl;
		cout << "b - 11%" << endl;
		cout << "c - 48%" << endl;
		cout << "d - 19%" << endl << endl;
	}
	if (poprawna == 'c' && polnapol == 1 && nr == 1) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a -  9%" << endl;
		cout << "c - 91%" << endl << endl;
	}

	if (poprawna == 'd' && nr == 0) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "a - 11%" << endl;
		cout << "b - 19%" << endl;
		cout << "c - 18%" << endl;
		cout << "d - 54%" << endl << endl;
	}
	if (poprawna == 'd' && polnapol == 1 && nr == 1) {
		system("cls");
		cout << "                              Glosowanie trwa...";
		Sleep(3000);
		system("cls");
		cout << "Wyniki glosowania:" << endl;
		cout << "b - 31%" << endl;
		cout << "d - 69%" << endl << endl;
	}

	KolorZielony();
	cout << "Aby kontynuowac wcisnij dowolny przycisk...";
	KolorCzcionki();
	getch();
}








int wygrales()
{
	int takczynie;
	do
	{
		cout << "                                   !!!!!!!!!!!!!!" << endl;
		cout << "                                   !!!Wygrana!!!!" << endl;
		cout << "                                   !!! Milion !!!" << endl;
		cout << "                                   !!!!!!!!!!!!!!" << endl << endl;

		cout << "Czy chcesz wpisac sie do rankingu milionerow? 1 - tak, 2 - nie: ";
		cin >> takczynie;

		if (takczynie == 1)
		{
			takczynie = 2;
			string imie;
			string nowalinia = "\n";
			cout << "Podaj imie: ";
			cin.ignore();
			getline(cin, imie);
			imie += nowalinia;

			fstream plik;
			plik.open("milionerzy.mln", ios::out | ios::app);
			if (plik.good() == true)
			{
				plik << imie;
				plik.close();
			}
			else
			{
				cout << "Nie mozna uzyskac dostepu do pliku! Byc moze plik nie istnieje!" << std::endl;
			}
		}

		cout << endl;
	} while (takczynie != 2);
}







int wpisanoodpowiedz(int nrpytania)
{
	if (odpowiedz == poprawna)
	{
		system("cls");
		if (nrpytania == 1) { wygrana = 500; }
		if (nrpytania == 2) { wygrana = 1000; gwarantowana = 1000; }
		if (nrpytania == 3) { wygrana = 2000; }
		if (nrpytania == 4) { wygrana = 5000; }
		if (nrpytania == 5) { wygrana = 10000; }
		if (nrpytania == 6) { wygrana = 20000; }
		if (nrpytania == 7) { wygrana = 40000; gwarantowana = 40000; }
		if (nrpytania == 8) { wygrana = 75000; }
		if (nrpytania == 9) { wygrana = 125000; }
		if (nrpytania == 10) { wygrana = 250000; }
		if (nrpytania == 11) { wygrana = 500000; }
		if (nrpytania == 12) { bledna = 1; milion = 1; wygrales(); }

		if (milion == 0)
		{
			cout << "Gratulacje! Poprawna odpowiedz to " << poprawna << endl;
			cout << "Na twoim koncie jest: " << wygrana << "zl" << endl << endl;
		}
	}

	else
	{
		if (milion == 0)
		{
			system("cls");
			bledna = 1;
			cout << "Niestety podales bledna odpowiedz. Poprawna odpowiedz to " << poprawna << endl;
			cout << "Twoja wygrana wynosi " << gwarantowana << "zl" << endl << endl;
		}
	}


	KolorZielony();
	cout << "Aby kontynulowac wcisnij dowolny przycisk...";
	KolorCzcionki();
	getch();

}




int pytanie()
{
	czypytaniejuzbylo();
	koniecpetli = 0;
	if (niebylo == 1)
	{
		nrpytania++;




		int n = 1, z, wyjscie;
		int k[6];
		k[1] = k[2] = k[3] = k[4] = k[5] = k[5] = 0;

		while (wyjscie != 1)
		{

			system("cls");
			KolorZielony();
			cout << "Pytanie numer: " << nrpytania << "\t\t Na twoim koncie jest: " << wygrana << "zl" << endl;
			cout << "\t\t\t\t Gwarantowana nagroda: " << gwarantowana << "zl" << endl << endl;


			cout << "Kola ratunkowe:" << endl;
			if (pytaniedopublicznosci == 1 && telefonwykorzystano == 1 && polnapol == 1) { cout << "Brak kol"; }
			KolorCzcionki();

			if (k[1] == 0 && pytaniedopublicznosci == 0 && telefonwykorzystano == 1 && polnapol == 0)
			{
				n = 2;
				k[1] = 1;
			}

			if (k[2] == 0 && pytaniedopublicznosci == 1 && telefonwykorzystano == 1 && polnapol == 0)
			{
				n = 3;
				k[2] = 1;
			}

			if (k[3] == 0 && pytaniedopublicznosci == 1 && telefonwykorzystano == 0 && polnapol == 0)
			{
				n = 1;
				k[3] = 1;
			}

			if (k[4] == 0 && pytaniedopublicznosci == 0 && telefonwykorzystano == 0 && (polnapol == 1 || pol == 1))
			{
				n = 1;
				k[4] = 1;
			}

			if (k[5] == 0 && pytaniedopublicznosci == 1 && telefonwykorzystano == 1 && (polnapol == 1 || pol == 1))
			{
				if (poprawna == 'a' || poprawna == 'c')
				{
					n = 4;
				}
				if (poprawna == 'b' || poprawna == 'd')
				{
					n = 5;
				}
				k[5] = 1;
			}

			if (n == 1) { KolorZielony(); }
			if (telefonwykorzystano == 0)
			{
				cout << "Telefon do przyjaciela [t]" << endl;
			}
			KolorCzcionki();


			if (n == 2) { KolorZielony(); }
			if (pytaniedopublicznosci == 0)
			{
				cout << "Pytanie do publicznosci [p]" << endl;
			}
			KolorCzcionki();


			if (n == 3) { KolorZielony(); }
			if (polnapol == 0)
			{
				cout << "Pol na pol [i]" << endl;
			}
			KolorCzcionki();

			if (telefonwykorzystano == 1) { cout << endl; }
			if (pytaniedopublicznosci == 1) { cout << endl; }
			if (polnapol == 1) { cout << endl; }
			cout << endl;

			cout << trescpytania << endl;

			if (n == 4) { KolorZielony(); }
			cout << mozliwaodpowiedz_a << endl;
			KolorCzcionki();

			if (n == 5) { KolorZielony(); }
			cout << mozliwaodpowiedz_b << endl;
			KolorCzcionki();

			if (n == 6) { KolorZielony(); }
			cout << mozliwaodpowiedz_c << endl;
			KolorCzcionki();

			if (n == 7) { KolorZielony(); }
			cout << mozliwaodpowiedz_d << endl;
			KolorCzcionki();


			z = getch();

			if (pytaniedopublicznosci == 0 && telefonwykorzystano == 0 && (polnapol == 0 || pol == 1))
			{
				if (z == 72) { n--; }
				if (z == 80) { n++; }
				if (pol == 1) {
					if (z == 72) { if (n == 3) { n = 2; } }
					if (z == 80) { if (n == 3) { n = 4; } }
				}
				if (z == 72) { if (n == 0) { n = 1; } }
				if (z == 80) { if (n == 8) { n = 7; } }
			}

			if (pytaniedopublicznosci == 0 && telefonwykorzystano == 1 && (polnapol == 0 || pol == 1))
			{
				if (z == 72) { n--; }
				if (z == 80) { n++; }
				if (pol == 1) {
					if (z == 72) { if (n == 3) { n = 2; } }
					if (z == 80) { if (n == 3) { n = 4; } }
				}
				if (z == 72) { if (n == 1) { n = 2; } }
				if (z == 80) { if (n == 8) { n = 7; } }
			}

			if (pytaniedopublicznosci == 1 && telefonwykorzystano == 0 && (polnapol == 0 || pol == 1))
			{
				if (z == 72) { n--; }
				if (z == 80) { n++; }
				if (pol == 1) {
					if (z == 72) { if (n == 3) { n = 1; } }
					if (z == 80) { if (n == 2) { n = 4; } }
				}
				if (z == 72) { if (n == 0) { n = 1; } }
				if (z == 80) { if (n == 8) { n = 7; } }

				if (z == 72) { if (n == 2) { n = 1; } }
				if (z == 80) { if (n == 2) { n = 3; } }
			}

			if (pytaniedopublicznosci == 1 && telefonwykorzystano == 1 && (polnapol == 0 || pol == 1))
			{
				if (z == 72) { n--; }
				if (z == 80) { n++; }
				if (pol == 1) {
					if (z == 72) { if (n == 3) { n = 4; } }
				}
				if (z == 72) { if (n == 2) { n = 3; } }
				if (z == 80) { if (n == 8) { n = 7; } }
			}

			if (pytaniedopublicznosci == 0 && telefonwykorzystano == 0 && polnapol == 1 && pol == 0)
			{
				if (poprawna == 'b' || poprawna == 'd')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 0) { n = 1; } }
					if (z == 80) { if (n == 8) { n = 7; } }


					if (z == 80) { if (n == 3) { n = 5; } }
					if (z == 72) { if (n == 4) { n = 2; } }
					if (z == 72) { if (n == 6) { n = 5; } }

					if (z == 80) { if (n == 6) { n = 7; } }
				}

				if (poprawna == 'a' || poprawna == 'c')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 0) { n = 1; } }
					if (z == 80) { if (n == 6) { n = 5; } }

					if (z == 72) { if (n == 3) { n = 2; } }
					if (z == 80) { if (n == 3) { n = 4; } }

					if (z == 72) { if (n == 5) { n = 4; } }
					if (z == 80) { if (n == 5) { n = 6; } }

					if (z == 80) { if (n == 7) { n = 6; } }
				}
			}

			if (pytaniedopublicznosci == 1 && telefonwykorzystano == 0 && polnapol == 1 && pol == 0)
			{
				if (poprawna == 'b' || poprawna == 'd')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 0) { n = 1; } }
					if (z == 80) { if (n == 8) { n = 7; } }
					if (z == 80) { if (n == 2) { n = 5; } }
					if (z == 72) { if (n == 4) { n = 1; } }
					if (z == 80) { if (n == 2) { n = 5; } }
					if (z == 72) { if (n == 6) { n = 5; } }

					if (z == 80) { if (n == 6) { n = 7; } }
				}

				if (poprawna == 'a' || poprawna == 'c')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 0) { n = 1; } }
					if (z == 80) { if (n == 6) { n = 5; } }

					if (z == 72) { if (n == 3) { n = 1; } }
					if (z == 80) { if (n == 2) { n = 4; } }

					if (z == 72) { if (n == 5) { n = 4; } }
					if (z == 80) { if (n == 5) { n = 6; } }

					if (z == 80) { if (n == 7) { n = 6; } }
				}
			}

			if (pytaniedopublicznosci == 0 && telefonwykorzystano == 1 && polnapol == 1 && pol == 0)
			{
				if (poprawna == 'b' || poprawna == 'd')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 1) { n = 2; } }
					if (z == 80) { if (n == 8) { n = 7; } }


					if (z == 80) { if (n == 3) { n = 5; } }
					if (z == 72) { if (n == 4) { n = 2; } }
					if (z == 72) { if (n == 6) { n = 5; } }

					if (z == 80) { if (n == 6) { n = 7; } }
				}

				if (poprawna == 'a' || poprawna == 'c')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 1) { n = 2; } }
					if (z == 80) { if (n == 6) { n = 5; } }

					if (z == 72) { if (n == 3) { n = 2; } }
					if (z == 80) { if (n == 3) { n = 4; } }

					if (z == 72) { if (n == 5) { n = 4; } }
					if (z == 80) { if (n == 5) { n = 6; } }

					if (z == 80) { if (n == 7) { n = 6; } }
				}
			}

			if (pytaniedopublicznosci == 1 && telefonwykorzystano == 1 && polnapol == 1 && pol == 0)
			{
				if (poprawna == 'b' || poprawna == 'd')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 4) { n = 5; } }
					if (z == 80) { if (n == 8) { n = 7; } }


					if (z == 72) { if (n == 6) { n = 5; } }
					if (z == 80) { if (n == 6) { n = 7; } }
				}

				if (poprawna == 'a' || poprawna == 'c')
				{
					if (z == 72) { n--; }
					if (z == 80) { n++; }

					if (z == 72) { if (n == 1) { n = 2; } }
					if (z == 80) { if (n == 6) { n = 5; } }

					if (z == 72) { if (n == 3) { n = 2; } }
					if (z == 80) { if (n == 3) { n = 4; } }

					if (z == 72) { if (n == 5) { n = 4; } }
					if (z == 80) { if (n == 5) { n = 6; } }

					if (z == 80) { if (n == 7) { n = 6; } }
				}
			}


			if (z == 13)
			{
				if (n == 1) { telefonwykorzystano = 1; kolaratunkowe_telefon(); }
				if (n == 2) { pytaniedopublicznosci = 1; kolaratunkowe_pytanie(polnapol, jakinumerpytania); }
				if (n == 3) { polnapol = 1;  jakinumerpytania = 1; kolaratunkowe_polnapol(); }
				if (n == 4) { odpowiedz = 'a', wpisanoodpowiedz(nrpytania);  wyjscie = 1; }
				if (n == 5) { odpowiedz = 'b', wpisanoodpowiedz(nrpytania);  wyjscie = 1; }
				if (n == 6) { odpowiedz = 'c', wpisanoodpowiedz(nrpytania);  wyjscie = 1; }
				if (n == 7) { odpowiedz = 'd', wpisanoodpowiedz(nrpytania);  wyjscie = 1; }
			}
		}
	}

	if (polnapol == 1)
	{
		pol = 1;
	}
}


int Gra()
{
	pytaniedopublicznosci = 0, telefonwykorzystano = 0, polnapol = 0, jakinumerpytania = 0;
	niebylo = 1;
	pol = 0;
	milion = 0;
	nrpytania = 0;
	koniecpetli = 0;
	bledna = 0;
	wygrana = 0;
	gwarantowana = 0;

	system("cls");
	cout << "                           Witaj w grze milionerzy!" << endl;
	Sleep(2000);
	cout << "                   Tylko od ciebie zalezy, czy wygrasz milion!" << endl;
	Sleep(2000);
	system("cls");
	cout << "                                  Zaczynamy " << endl;
	Sleep(1500);
	system("cls");




	do
	{

		srand(time(NULL));
		wylosowana = (rand() % 22) + 1;




		if (wylosowana == 1)
		{
			poprawna = 'a';
			trescpytania = "Jak nazywa sie nazwa najpopularniejszego w Polsce serwisu aukcyjego?";
			mozliwaodpowiedz_a = " a - Allegro";
			mozliwaodpowiedz_b = " b - Facebook";
			mozliwaodpowiedz_c = " c - E-bay";
			mozliwaodpowiedz_d = " d - Oto-Moto";
			pytanie();
		}

		if (wylosowana == 2)
		{
			poprawna = 'c';
			trescpytania = "Ktora z planet ma pierscienie?";
			mozliwaodpowiedz_a = " a - Ziemia";
			mozliwaodpowiedz_b = " b - Merkury";
			mozliwaodpowiedz_c = " c - Saturn";
			mozliwaodpowiedz_d = " d - Mars";
			pytanie();
		}

		if (wylosowana == 3)
		{
			poprawna = 'b';
			trescpytania = "Ktora planeta od Slonca jest Ziemia?";
			mozliwaodpowiedz_a = " a - 1";
			mozliwaodpowiedz_b = " b - 3";
			mozliwaodpowiedz_c = " c - 4";
			mozliwaodpowiedz_d = " d - 6";
			pytanie();
		}

		if (wylosowana == 4)
		{
			poprawna = 'a';
			trescpytania = "Kto wyrezyserowal film 'Tato'?";
			mozliwaodpowiedz_a = " a - Maciej Slesicki";
			mozliwaodpowiedz_b = " b - Olaf Lubaszenko";
			mozliwaodpowiedz_c = " c - Lew Rywin";
			mozliwaodpowiedz_d = " d - Boguslaw Linda";
			pytanie();
		}

		if (wylosowana == 5)
		{
			poprawna = 'a';
			trescpytania = "Ktory film powstal najwczesniej?";
			mozliwaodpowiedz_a = " a - Popiol i Diament";
			mozliwaodpowiedz_b = " b - Psy";
			mozliwaodpowiedz_c = " c - Potop";
			mozliwaodpowiedz_d = " d - Ogniem i mieczem";
			pytanie();
		}

		if (wylosowana == 6)
		{
			poprawna = 'd';
			trescpytania = "W ktorym roku wybuchla II Wojna Swiatowa?";
			mozliwaodpowiedz_a = " a - 17 wrzesnia 1945.r";
			mozliwaodpowiedz_b = " b -  1 wrzesnia 1940.r";
			mozliwaodpowiedz_c = " c - 17 wrzesnia 1939.r";
			mozliwaodpowiedz_d = " d -  1 wrzesnia 1939.r";
			pytanie();
		}

		if (wylosowana == 7)
		{
			poprawna = 'c';
			trescpytania = "Do jakiej marki nalezy model samochodu lybra?";
			mozliwaodpowiedz_a = " a - Mercedes";
			mozliwaodpowiedz_b = " b - Sama nazwa lybra jest marka";
			mozliwaodpowiedz_c = " c - Lancia";
			mozliwaodpowiedz_d = " d - Nie ma takiego samochodu";
			pytanie();
		}

		if (wylosowana == 8)
		{
			poprawna = 'b';
			trescpytania = "Ktory z ponizszych utworow nie jest dzielem polskiego pisarza?";
			mozliwaodpowiedz_a = " a - 'Wiedzmin'";
			mozliwaodpowiedz_b = " b - 'Zbrodnia i Kara'";
			mozliwaodpowiedz_c = " c - 'Chlopi'";
			mozliwaodpowiedz_d = " d - 'Wesele w Atomicach'";
			pytanie();
		}

		if (wylosowana == 9)
		{
			poprawna = 'd';
			trescpytania = "Zwarta grupa zawodnikow jadaca w wyscigu kolarskim to:";
			mozliwaodpowiedz_a = " a - Aktyw";
			mozliwaodpowiedz_b = " b - Plejada";
			mozliwaodpowiedz_c = " c - Konwoj";
			mozliwaodpowiedz_d = " d - Peleton";
			pytanie();
		}

		if (wylosowana == 10)
		{
			poprawna = 'a';
			trescpytania = "Co oznacza nazwa frutti di mare?";
			mozliwaodpowiedz_a = " a - Owoce morza";
			mozliwaodpowiedz_b = " b - Owoce cytrusowe";
			mozliwaodpowiedz_c = " c - Owoce lesne";
			mozliwaodpowiedz_d = " d - Owoce tropikalne";
			pytanie();
		}

		if (wylosowana == 11)
		{
			poprawna = 'c';
			trescpytania = "Sport wodny uprawiany na desce z zaglem to:";
			mozliwaodpowiedz_a = " a - Skateboard";
			mozliwaodpowiedz_b = " b - Surfing";
			mozliwaodpowiedz_c = " c - Windsurfing";
			mozliwaodpowiedz_d = " d - Bojery";
			pytanie();
		}

		if (wylosowana == 12)
		{
			poprawna = 'd';
			trescpytania = "Kanal Sueski stanowi umowna granice miedzy:";
			mozliwaodpowiedz_a = " a - Amerykami";
			mozliwaodpowiedz_b = " b - Kanada i Grenlandia";
			mozliwaodpowiedz_c = " c - Australia i Azja";
			mozliwaodpowiedz_d = " d - Afryka i Azja";
			pytanie();
		}

		if (wylosowana == 13)
		{
			poprawna = 'b';
			trescpytania = "W ktorym roku zniesiono komunizm w Polsce?";
			mozliwaodpowiedz_a = " b - 1945";
			mozliwaodpowiedz_b = " b - 1989";
			mozliwaodpowiedz_c = " c - 1991";
			mozliwaodpowiedz_d = " d - 1987";
			pytanie();
		}

		if (wylosowana == 14)
		{
			poprawna = 'b';
			trescpytania = "Ktory dowodca wypowiedzial te slowa: 'Ucze­ni i os³y do œrod­ka!'?";
			mozliwaodpowiedz_a = " a - Jozef Pilsudzki";
			mozliwaodpowiedz_b = " b - Napoleon Bonaparte";
			mozliwaodpowiedz_c = " c - Juliusz Cezar";
			mozliwaodpowiedz_d = " d - Jan III Sobieski";
			pytanie();
		}

		if (wylosowana == 15)
		{
			poprawna = 'a';
			trescpytania = "Jakie imie otrzymala fregata rakietowa USS Clark podarowana Polsce przez Stany Zjednoczone?";
			mozliwaodpowiedz_a = " a - Kazimierz Pulaski";
			mozliwaodpowiedz_b = " b - Tadeusz Kosciuszko";
			mozliwaodpowiedz_c = " c - Ignacy Paderewski";
			mozliwaodpowiedz_d = " d - Jozef Karge";
			pytanie();
		}

		if (wylosowana == 16)
		{
			poprawna = 'd';
			trescpytania = "Kto 'zmodyfikowal' portret Giacondy, domalowujac jej wasy?";
			mozliwaodpowiedz_a = " a - George Grosz";
			mozliwaodpowiedz_b = " b - Max Ernst";
			mozliwaodpowiedz_c = " c - Otto Dix";
			mozliwaodpowiedz_d = " d - Marcel Duchamp";
			pytanie();
		}

		if (wylosowana == 17)
		{
			poprawna = 'd';
			trescpytania = "Jak mial na imie s³on Trabalski z wiersza Juliana Tuwima?";
			mozliwaodpowiedz_a = " a - Jonasz";
			mozliwaodpowiedz_b = " b - Dominik";
			mozliwaodpowiedz_c = " c - Jakub";
			mozliwaodpowiedz_d = " d - Tomasz";
			pytanie();
		}

		if (wylosowana == 18)
		{
			poprawna = 'c';
			trescpytania = "Slynna gielda na Wall Street miesci sie w nowojorskiej dzielnicy:";
			mozliwaodpowiedz_a = " a - Harlem";
			mozliwaodpowiedz_b = " b - Queens";
			mozliwaodpowiedz_c = " c - Manhattan";
			mozliwaodpowiedz_d = " d - Brooklyn";
			pytanie();
		}

		if (wylosowana == 19)
		{
			poprawna = 'b';
			trescpytania = "W ktorym filmie Romana Polanskiego jedna z rol przypadla Wladyslawowi Pasikowskiemu?";
			mozliwaodpowiedz_a = " a - 'Lokator'";
			mozliwaodpowiedz_b = " b - 'Piraci'";
			mozliwaodpowiedz_c = " c - 'Frantic'";
			mozliwaodpowiedz_d = " d - 'Tess'";
			pytanie();
		}

		if (wylosowana == 20)
		{
			poprawna = 'a';
			trescpytania = "Ktory z bogow Egiptu zostal zabity przez Seta, rozerwany na kawalki i rozrzucony po swiecie?";
			mozliwaodpowiedz_a = " a - Ozyrys";
			mozliwaodpowiedz_b = " b - Ptah";
			mozliwaodpowiedz_c = " c - Horus";
			mozliwaodpowiedz_d = " d - Anubis";
			pytanie();
		}

		if (wylosowana == 21)
		{
			poprawna = 'd';
			trescpytania = "Kto jest wokalista zespolu Curly Heads?";
			mozliwaodpowiedz_a = " a - Stachursky";
			mozliwaodpowiedz_b = " b - Michal Wisniewski";
			mozliwaodpowiedz_c = " c - Niall Horan";
			mozliwaodpowiedz_d = " d - Dawid Podsiad³o";
			pytanie();
		}

		if (wylosowana == 22)
		{
			poprawna = 'd';
			trescpytania = "Vegeta, Goku, Freezer to postacie wystêpuj¹ce w:";
			mozliwaodpowiedz_a = " a - 'Naruto'";
			mozliwaodpowiedz_b = " b - 'Muminki'";
			mozliwaodpowiedz_c = " c - 'Attack on titan'";
			mozliwaodpowiedz_d = " d - 'Dragon Ball Z'";
			pytanie();
		}

		if (wylosowana == 23)
		{
			poprawna = 'b';
			trescpytania = "W którym roku i jakim wystêpem znana polska wokalistka zaliczy³a wpadkê na festiwalu w Sopocie?";
			mozliwaodpowiedz_a = " a - 2005r, Here we go again";
			mozliwaodpowiedz_b = " b - 2005r, Ev'ry Night";
			mozliwaodpowiedz_c = " c - 2006r, Szansa";
			mozliwaodpowiedz_d = " d - 2006r, Dzaga";
			pytanie();
		}


	} while (bledna != 1);



}


int Autor()
{
	system("cls");
	cout << "             Autorem gry milionerzy jest Kuba";
	getch();
}




int main()
{

	int n = 1, z, wyjscie;
	while (wyjscie != 1)
	{
		system("cls");
		KolorCzcionki();
		cout << "\t\t\t\t         MENU \n" << endl;

		printf("\t\t\t        ______________________\n");
		printf("\t\t\t       |");
		if (n == 1)
		{
			KolorZielony();
		}
		printf("         Graj         "); KolorCzcionki();
		printf("|\n");
		printf("\t\t\t       |");
		if (n == 2)
		{
			KolorZielony();
		} printf("         Autor        "); KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");
		if (n == 3)
		{
			KolorZielony();
		} printf("       Ustawienia     "); KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");
		if (n == 4)
		{
			KolorZielony();
		} printf("        Ranking       "); KolorCzcionki();
		printf("| \n");
		printf("\t\t\t       |");
		if (n == 5)
		{
			KolorZielony();
		} printf("        Wyjscie       "); KolorCzcionki();
		printf("|\n");
		printf("\t\t\t        ----------------------\n");

		z = getch();

		if (z == 72) { n--; }
		if (z == 80) { n++; }
		if (z == 72) { if (n == 0) { n = 5; } }
		if (z == 80) { if (n == 6) { n = 1; } }

		if (z == 13)
		{
			if (n == 1) {
				char odpowiedz;
				Gra();
				do
				{
					system("cls");
					cout << "                  Grasz jeszcze raz? t - Tak, n - Nie: ";
					cin >> odpowiedz;
					if (odpowiedz == 't')
					{
						Gra();
					}
				} while (odpowiedz != 'n');
			}
			if (n == 2) { Autor(); }
			if (n == 3) { Opcje(); }
			if (n == 4) { listamilionerow(); }
			if (n == 5) { wyjscie = 1; }
		}
	}


}
