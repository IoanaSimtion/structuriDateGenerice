#include "stiva.h";
#include "coada.h";
#include <fstream>
#pragma once

//4263


void sol4263() {

	//codeblocks

}


//864


unsigned x, x2, y, y2, t[100][100], n, m, sol[100][100], v[100], ct = 0;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };




void citireTraseu() {

	ifstream f("matrice.txt");

	f >> n >> m;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			f >> t[i][j];

		}

	}

	cout << "Introduceti coordonatele robotului:" << endl;

	cout << "x=";

	cin >> x;

	cout << "y=";

	cin >> y;

	cout << "Introduceti coordonatele roboticii:" << endl;

	cout << "x=";

	cin >> x2;

	cout << "y=";

	cin >> y2;

}


void afisareMatrice() {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cout << t[i][j] << ' ';

		}

		cout << endl;

	}

}


void memorarePasi(int pas) {

	v[ct] = pas;

	ct++;

}



void back(int i, int j, int pas) {

	int imax, jmax, k;

	for (k = 0; k < 4; k++) {

		imax = i + dx[k];

		jmax = j + dy[k];

		if (t[imax][jmax] == 0 && sol[imax][jmax] == 0) {

			sol[imax][jmax] = pas;

			if (imax == x2 && jmax == y2) {

				memorarePasi(pas);

			}

			back(imax, jmax, pas + 1);

			sol[imax][jmax] = 0;

		}

	}

}


int minimVector() {

	int minim = 0;

	for (int i = 0; i < ct; i++) {

		if (v[i] < minim) {

			minim = v[i];

		}

	}

	return minim;

}



void sol864() {

	Coada<int> c;

	citireTraseu();

	//afisareMatrice();

	sol[x][y] = 1;

	back(x, y, 2);

	cout << "Cel mai scurt drum consta in " << minimVector() - 1 << " pasi" << endl;

}