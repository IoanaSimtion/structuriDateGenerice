#include "stiva.h";
#include "coada.h";
#include <fstream>
#pragma once


//INTREBARI: 
//4263 (sol 6)
//2645 (sol 7)
//867 (sol 13)



//STIVA


/*875: Să se scrie un program care gestionează o stivă de numere întregi.
Inițial stiva este vidă. Programul va citi de la tastatură o listă de operații, care pot fi:

push X – adaugă valoarea întreagă X pe stivă;
pop – elimină elementul din vârful stivei;
top – afișează elementul din vârful stivei.

Programul va realiza asupra stivei operațiile citite, în ordine. 
Afișările se fac pe ecran, câte o valoare pe linie.*/



void sol1() {

	Stiva<int> s;

	string operatie;

	int x, n;

	cout << "Cate operatii doriti sa efectuati?" << endl;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << "Introduceti operatia:" << endl;

		cin >> operatie;

		if (operatie == "push") {

			cin >> x;

			s.push(x);

		}
		else {

			if (operatie == "top") {

				cout << s.peak() << endl;

			}
			else {

				s.pop();

			}

		}

	}

}



/*848: Se dau n șiruri de paranteze rotunde. Să se stabilească, despre fiecare șir,
dacă este corect parantezat – adică dacă parantezele se închid corect.

Un șir de paranteze S rotunde este corect parantezat dacă:

S este șirul vid, sau
S = (T) și T este corect parantezat, sau
S = AB, iar A și B sunt corect parantezate.*/



//todo functie ce verifica daca un text este corect parantezat

bool corectParantezat(string text) {
		
	Stiva<char> s;

	for (int i = 0; i < text.length(); i++) {

		if (text[i] == '(') {

			s.push(text[i]);

		}

		if (text[i] == ')') {

			if (s.isEmpty()) {

				return false;

			}
			else {

				s.pop();

			}

		}

	}

	return s.isEmpty();
}



void sol2() {

	string text;

	int n;

	cout << "Cate siruri de paranteze doriti sa introduceti?" << endl;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << "Introduceti sirul: " << endl;

		cin >> text;

		if (corectParantezat(text)) {

			cout << "Sirul este corect parantezat" << endl;

		}
		else {

			cout << "Sirul nu este corect parantezat" << endl;

		}
	}

}



/*3795: Să se scrie un program care citește un șir de paranteze rotunde care se închid corect
(corect parantezat) în care parantezele deschise sunt numerotate de la stânga la dreapta,
îndepând de la 1, și determină pentru fiecare paranteză închisă 
numărul de ordine al parantezei deschise corespunzătoare.

Un șir de paranteze rodunde S este corect parantezat dacă:

S este șirul vid, sau
S = (T) și T este corect parantezat, sau
S = AB, iar A și B sunt corect parantezate*/



//todo functie ce afiseaza nr de ordine al parantezei deschise coresp parantezei deschise

void afisareNrOrd(string text) {

	Stiva<int> s;

	int nr = 1;

	for (int i = 0; i < text.length(); i++) {

		if (text[i] == '(') {

			s.push(nr);

			nr++;

		}

		if (text[i] == ')') {

			cout << s.peak() << ' ';

			s.pop();

		}

	}

}



void sol3() {

	string text;

	cout << "Introduceti sirul de paranteze: " << endl;

	cin >> text;

	afisareNrOrd(text);
	

}



/*852: Se dau n șiruri de paranteze rotunde sau pătrate. 
Să se stabilească, despre fiecare șir, dacă este corect parantezat –
adică dacă parantezele se închid corect.

Un șir de paranteze S rotunde este corect parantezat dacă:

S este șirul vid, sau
S = (T) și T este corect parantezat, sau
S = [T] și T este corect parantezat, sau
S = AB, iar A și B sunt corect parantezate.*/



//todo functie ce verifica daca un text este corect parantezat 

bool parantezatCorect(string text) {

	Stiva<char> r, p;

	for (int i = 0; i < text.length(); i++) {

		if (text[i] == '(') {

			r.push(text[i]);

		}

		if (text[i] == ')') {

			if (r.isEmpty()) {

				return false;

			}

			r.pop();

		}

		if (text[i] == '[') {

			p.push(text[i]);

		}

		if (text[i] == ']') {

			if (p.isEmpty()) {

				return false;

			}

			p.pop();

		}

	}

	if (!r.isEmpty() || !p.isEmpty()) {

		return false;

	}

	return true;

}



void sol4() {

	string text;

	int n;

	cout << "Cate siruri de paranteze doriti sa introduceti?" << endl;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << "Introduceti sirul: " << endl;

		cin >> text;

		if (parantezatCorect(text)) {

			cout << "Sirul este corect parantezat" << endl;

		}
		else {

			cout << "Sirul nu este corect parantezat" << endl;

		}
	}

}



/*877: Gigel are un set de n cuburi. Fiecare cub este marcat cu un număr natural, de la 1 la n și i se cunoaște lungimea laturii – număr natural. Cu o parte dintre aceste cuburi Gigel va construi o stivă, astfel:

fiecare cub se analizează o singură dată, în ordinea numerelor marcate;
dacă stiva nu conține niciun cub, cubul curent devine baza stivei
dacă cubul curent are latura mai mică sau egală cu cubul din vârful stivei, se adaugă pe stivă;
dacă cubul curent are latura mai mare decât cubul din vârful stivei, se vor înlătura de pe stivă cuburi (eventual toate) până când cubul curent are latura mai mică sau egală cu cubul din vârful stivei.
Să se afișeze numerele de pe cuburile existente la final în stivă, de la bază spre vârf.*/


//todo functie ce sterge elem de pe stiva pana cand se implineste conditia

void stergereElem(Stiva<int>& s, int cub) {

	while (s.top!=NULL && cub > s.peak()) {

		s.pop();

	}

}


void sol5() {

	Stiva<int> s;

	int n, cub;

	cout << "Cate cuburi sunt in set?" << endl;

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cout << "Introduceti lungimea laturii cubului " << i << endl;

		cin >> cub;

		if (s.isEmpty()) {

			s.push(i);

		}
		else {

			if (cub <= s.peak()) {

				s.push(i);

			}
			else {

				stergereElem(s, cub);

				s.push(i);

			}
		}

	}

	cout << endl;

	cout << "Cuburile existente pe stiva sunt: " << endl;

	s.afisare();

}



/*4263: Studiind instrucțiunea if, Alinutza a aflat că ramura else se asociază 
celui mai apropiat if neasociat încă. Aprofundând studiul, a extras din fiecare program
scris cuvintele if și else. Din neatenție a transcris greșit, pierzând asocierea corectă if else.
Ajutați-o voi să aibă scrierea corectă, folosind un număr minim de modificări.
O modificare înseamnă să înlocuim un cuvânt if cu else sau un cuvânt else cu if.*/


//todo functie ce verifica daca scrierea este corecta


bool scriereCorecta(char text[]) {

	Stiva<char> s;

	return true;

}


int nrModificari() {

	int ct = 0;

	return ct;

}




void sol6() {

	//Stiva<string> s;

	char instructiune[100];

	int n;

	cout << "Din cate programe se extrag instructiunuile?" << endl;

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cout << "Introduceti instructiunea extrasa din programul nr " << i << endl;

		cin >> instructiune;

		cout << endl;

		cout << "Numarul minim de modificari este " << nrModificari();

		cout << endl << endl;

	}

}




/*2645: Se consideră un cuvânt format numai din litere mici și un număr natural nenul K.
Să se determine cuvântul minim lexicografic obținut prin eliminarea a exact K litere din cuvântul inițial.*/



//todo functie ce determina cuv min lexicografic

void cuvMinLex(Stiva<char>& s, int k) {

	

}



void sol7() {

	Stiva<char> s;

	string cuv;

	int K;

	cout << "Introduceti un cuvant: " << endl;

	cin >> cuv;

	cout << "K=";

	cin >> K;

	cuvMinLex(s, K);

	cout << endl;

	cout << "Cuvantul minim lexicografic obtinut dupa eliminarea a " << K << " litere este: " << endl;

	s.afisare();

}



/*4285: Se dă un șir a1, a2, …, an de numere întregi și m operații, 
fiecare operație fiind dată printr-o pereche de numere op și k:
dacă op = 1 atunci primele k elemente din șir se ordonează crescător,
iar dacă op = 2 atunci primele k elemente din șir se ordonează descrescător.
Să se afișeze elementele șirului după efectuarea tuturor celor m operații.*/



//todo functie ce efectueaza op 1

void sortCresc(Stiva<int>& s, int k) {

	bool flag = 0;

	do {

		flag = 1;

		for (int i = k - 1; i > 0; i--) {

			if (s.getNode(i) > s.getNode(i - 1)) {

				int aux = s.getNode(i)->data;

				s.set(s.getNode(i + 1)->data, i);

				s.set(aux, i + 1);

				flag = 0;

			}

		}

	} while (flag == 0);
}



//todo functie ce efectueaza op 2

void sortDescresc(Stiva<int>& s, int k) {

	bool flag = 0;

	do {

		flag = 1;

		for (int i = k - 1; i > 0; i--) {

			if (s.getNode(i) < s.getNode(i - 1)) {

				int aux = s.getNode(i)->data;

				s.set(s.getNode(i + 1)->data, i);

				s.set(aux, i + 1);

				flag = 0;

			}

		}

	} while (flag == 0);
}



void sol8() {

	Stiva<int> s;

	int n, m, op, a, k;

	cout << "Cate numere contine sirul?" << endl;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << "Introduceeti elementul nr " << i << endl;

		cin >> a;

		s.push(a);

	}

	cout << endl;

	cout << "Cate operatii doriti sa efectuati?" << endl;

	cin >> m;

	cout << endl;

	for (int i = 1; i <= m; i++) {

		cout << "Operatia " << i << endl;

		cout << "op=";

		cin >> op;

		cout << "k=";

		cin >> k;

		if (op == 1) {

			sortCresc(s, k);

		}
		else {

			sortDescresc(s, k);

		}

	}

	cout << endl;

	cout << "Sirul obtinut este: " << endl;

	s.afisare();

}



/*3659: Pentru că e criză, cu ocazia campaniei electorale, în loc de găleți pline cu făină,
zahăr și bilete la teatru primiți un șir a1, a2, …, an care reprezintă o permutare a 
mulțimii {1,2,...,n}. Pentru fiecare secvență nevidă a permutării costul ei este valoarea maximă 
din acea secvență. De exemplu, costul secvenței 4,2,6,1,3,5 este 6, iar costul secvenței 4,2 este 4.
Să se calculeze suma totală a costurilor tuturor secvențelor.*/



//todo functie ce returneaza val max dintr o secventa

int valMax(int v[], int i, int d, int n) {

	int maxim = 0;

	for (int j = i; j < d; j++) {

		cout << v[j] << ' ';

		if (v[j] > maxim) {

			maxim = v[j];

		}

		if (d + 1 < n) {

			d++;

		}

	}

	cout << endl;

	return maxim;

}



//todo functie ce salveaza pe stiva elem max din secv

void memorareMax(Stiva<int>& s, int v[], int d) {

	for (int i = 0; i < d; i++) {

		s.push(valMax(v, i, i + 1, d));

	}

}



//todo functie ce returneaza suma elem de pe stiva


int sumaStiva(Stiva<int> s) {

	int suma = 0;

	Node<int>* aux = s.iterator();

	while (aux != NULL) {

		suma = suma + aux->data;

		aux = aux->next;

	}

	return suma;

}



void sol9() {

	Stiva<int> s;

	int sir[100], n;

	cout << "Introduceti dimensiunea sirului: " << endl;

	cin >> n;

	cout << "Introduceti elementele sirului: " << endl;

	for (int i = 0; i < n; i++) {

		cin >> sir[i];

	}

	memorareMax(s, sir, n);

	s.afisare();

	cout << "Suma totala a costurilor este " << sumaStiva(s);
}



/*1884: Se dă un șir cu n elemente, numere naturale. Să se afișeze, pentru fiecare element din șir,
valoarea din șir aflată după acesta și mai mare decât acesta (Următorul Element Mai Mare).
Dacă o asemenea valoare nu există, se va afișa -1.*/



//todo functie ce memoreaza valoarea mai mare din sir aflate dupa o anumita val


void salvareValori(Stiva<int>& s, int poz, int val, int v[], int d) {

	int i;

	for (i = poz; i < d; i++) {

		if (v[i] > val) {

			s.push(v[i]);

			break;

		}

	}

	if (i == d) {

		s.push(-1);

	}

}



void sol10() {

	int sir[100], n;

	Stiva<int> s;

	cout << "Cate valori are sirul? " << endl;

	cin >> n;

	cout << "Introduceti elementele sirului: " << endl;

	for (int i = 0; i < n; i++) {

		cin >> sir[i];

	}

	cout << "Sirul obtinut este: " << endl;

	for (int i = 0; i < n; i++) {

		salvareValori(s, i + 1, sir[i], sir, n);

	}

	s.afisare();

}






//COADA



/*876: Să se scrie un program care gestionează o coadă de numere întregi. 
Inițial coada este vidă. Programul va citi de la tastatură o listă de operații, care pot fi:

push X – adaugă valoarea întreagă X în coadă;
pop – elimină elementul din coadă;
front – afișează elementul de la începutul cozii.
Programul va realiza asupra cozii operațiile citite, în ordine. Afișările se fac pe ecran, câte o valoare pe linie.*/



void sol11() {

	Coada<int> c;

	string operatie;

	int x, n;

	cout << "Cate operatii doriti sa efectuati?" << endl;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cout << "Introduceti operatia:" << endl;

		cin >> operatie;

		if (operatie == "push") {

			cin >> x;

			c.push(x);

		}
		else {

			if (operatie == "front") {

				cout << c.peak() << endl;

			}
			else {

				c.pop();

			}

		}

	}

}



/*1598: Se consideră C o coadă de numere naturale, iniţial vidă. Se definesc 2 tipuri de operaţii.

Operaţia 1 : push X, adaugă elementul X în coadă. Dacă X există deja în coadă, se scot toate elementele din coadă, pana la întâlnirea lui, inclusiv X.
Exemplu: C: 2 4 5 1 6
	Push 5
	C: 1 6 5 ( s-au scos 2, 4, 5).

Operaţia 2: query X, cere afişarea poziţiei elementului X în coada C. Dacă elementul nu există în coadă, se afişează -1.
Exemplu: C: 2 5 1 3 7
	Query 1
	Răspuns: 3
	
Dându-se M, reprezentând numărul de operaţii şi cele M operaţii, să se răspundă la operaţiile de tip query.*/



//todo functie ce verifica daca un nr exista deja in coada

bool exista(Coada<int> c, int X) {

	Node<int>* aux = c.iterator();

	while (aux != NULL) {

		if (aux->data == X) {

			return true;

		}

		aux = aux->next;

	}

	return false;

}


//todo functie ce realizeaza operatia push X

void pushX(int X, Coada<int>& c) {

	if (exista(c, X)) {

		Node<int>* aux = c.iterator();

		while (aux->data != X) {

			c.pop();

			aux = aux->next;

		}

		c.pop();

	}

	c.push(X);

}


//todo functie ce realizeaza operatia query

int query(Coada<int> c, int X) {

	int poz = 0;

	Node<int>* aux = c.iterator();

	while (aux != NULL && aux->data!=X) {

		poz++;

		aux = aux->next;

	}

	if (aux == NULL) {

		return -1;

	}

	return poz;

}



void sol12() {

	Coada<int> c;

	int M, X;

	string operatie;

	cout << "Cate operatii doriti sa efectuati? " << endl;

	cin >> M;

	for (int i = 0; i < M; i++) {

		cout << "Introduceti operatia:" << endl;

		cin >> operatie;

		if (operatie == "push") {

			cin >> X;

			pushX(X, c);

			cout << endl;

			c.afisare();

			cout << endl;

		}

		if (operatie == "query") {

			cin >> X;

			cout << query(c, X) << endl;

		}

	}

}



/*864: Se dă o matrice cu n linii și m coloane și elemente 0 sau 1, 
reprezentând planul unui teren în care 0 reprezintă o zonă accesibilă,
iar 1 reprezintă o zonă inaccesibilă. O zonă a terenului are ca și coordonate linia 
și coloana corespunzătoare din matrice. Într-o zonă cunoscută a matricei se află un robot, 
iar în altă zonă, de asemenea cunoscută, se află o roboțică.
Determinați numărul minim de pași prin care robotul va ajunge la roboțică.
Dacă nu este posibil ca robotul să ajungă la roboțică, rezultatul va fi -1.

4 5
1 0 0 0 1
0 0 1 0 0
0 0 0 0 1
1 1 0 0 1
1 2 - coord robot
2 5 -coord robotica

raspuns: 4

*/


//todo functie ce citeste o matrice


void citireMatrice(int a[100][100], int& n, int& m) {

	ifstream f("matirce.txt");

	f >> n >> m;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			f >> a[i][j];

		}

	}

}



void sol13() {

	Coada<int> c;

	int traseu[100][100], n, m, x1, y1, x2, y2;

	citireMatrice(traseu, n, m);

	cout << "Introduceti coordonatele robotului:" << endl;

	cout << "x=";
	
	cin >> x1;

	cout << "y=";

	cin >> y1;

	cout << "Introduceti coordonatele roboticii:" << endl;

	cout << "x=";
	
	cin >> x2;

	cout << "y=";

	cin >> y2;

	cout << "Cel mai scurt drum consta in ... pasi" << endl;

}


