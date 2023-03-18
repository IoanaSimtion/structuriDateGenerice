#include "arbori.h";
#include <fstream>
#pragma once


/*675: Considerăm un arbore binar cu n noduri în care fiecare nod este numerotat de la 1 la n
și conține o valoare număr natural. Să se afișeze frunzele acestui arbore.
Fișierul de intrare bifrunze.in conține pe prima linie numărul n. 
Fiecare dintre următoarele n linii contine câte 3 numere X st dr; 
linia i + 1 din fișier conține informatiile despre nodul numerotat cu i:
X reprezintă valoare din nod, st reprezintă numărul de ordine al descendentului stâng 
sau 0 dacă nodul i nu are descendent stâng, iar dr reprezintă numărul de ordine 
al descendentului drept sau 0 dacă nodul i nu are descendent drept.

*/


void citireDate(int frunze[], int& i) {

	int x, st, dr, n;

	ifstream f("bifrunze.in");

	f >> n;

	for (int j = 0; j < n; j++) {

		f >> x;
		f >> st;
		f >> dr;

		if (st == 0 && dr == 0) {
			frunze[i] = j;
			i++;
		}

	}

}

void afisareVector(int v[], int d) {

	for (int i = 0; i < d; i++) {
		cout << v[i] << ' ';
	}

}


void sol675() {

	int frunze[20], d = 0;

	citireDate(frunze, d);

	cout << "Frunzele arborelui sunt: " << endl;

	afisareVector(frunze, d);
	

}


/*670: Considerăm un arbore binar cu n noduri în care fiecare nod este numerotat de la 1 la n
și conține o valoare număr natural. 
Să se afișeze valorile din arbore în urma parcurgerii în preordine (rădăcină, stâng, drept).

Fișierul de intrare preordine.in conține pe prima linie numărul n. 
Fiecare dintre următoarele n linii contine câte 3 numere X st dr; 
linia i + 1 din fișier conține informatiile despre nodul numerotat cu i: 
X reprezintă valoare din nod, st reprezintă numărul de ordine al descendentului stâng sau 0 
dacă nodul i nu are descendent stâng, iar dr reprezintă numărul de ordine al 
descendentului drept sau 0 dacă nodul i nu are descendent drept.

*/


//todo functie ce memoreaza datele in matrice

void treeMatrice(int m[100][100], int d, int& n) {

	ifstream f("preordine.in");

	f >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			f >> m[i][j];
		}
	}

}


//todo functie ce afiseaza o matrice

void afisareMatrice(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}

}

//todo functie ce verifica daca un nr se gaseste in matrice

bool exista(int m[100][100], int n, int d, int data) {

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < d; j++) {
			if (m[i][j] == data) {
				return true;
			}
		}
	}
	
	return false;

}


//todo functie ce returneaza valoarea root ului

int treeRoot(int m[100][100], int n, int d) {

	for (int i = 0; i < n; i++) {
		if (!exista(m, n, d, i + 1)) {
			return m[i][0];
		}
	}

}



void sol670() {

	int treeM[100][100], d = 3, n, root;

	treeMatrice(treeM, d, n);

	afisareMatrice(treeM, n, d);

	root = treeRoot(treeM, n, d);

	cout << root;

}