/*
		Klasa macierz
		Opis: Zadaniem klasy o nazwie macierz jest stworzenie tablicy o rozmiarze 2x2, wypelnienie jej wartosciami, wykonanie dzialan
		na tych macierzach oraz stworzenie przeciazen operatorow.
		Autor: Bart�omiej Ulanowski
		Data utworzenia: 26.10.2020
		Data poprawki/edycja: ------
*/


#ifndef macierz_h
#define macierz_h

#include <iostream>


using namespace std;

class macierz
{
public:

	//konstruktory
	macierz()
	{
		t = new double* [n];
		for (int i = 0; i < n; i++)
			t[i] = new double[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				t[i][j] = 0;
	}
	~macierz() {
		delete[] t;
	};
	//metody

	void set(int a, int b, double c) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (i == a && j == b)
					t[i][j] = c;
	}

	void secik() {
		for (int i = 0; i < n; i++)
		{
			if (i == 1) cout << endl;
			for (int j = 0; j < m; j++)
				cout << t[i][j] << " ";
		}
		cout << endl;
	}

	//operatory
	const macierz& operator = (const macierz& m2) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				this->t[i][j] = m2.t[i][j];
		return *this;
	}

	const macierz& operator * (const macierz& m2) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					this->t[i][j] = this->t[i][k] * m2.t[k][j];
		return *this;
	}

	bool operator == (const macierz& m2)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (this->t[i][j] == m2.t[i][j])
					return true;
		return false;
	}

		bool operator !(const macierz& m2)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (this->t[i][j] != m2.t[i][j])
						return false;
			return true;
		}

private:
	//zmienne
	double** t;
	int n = 2;
	int m = 2;
};


#endif