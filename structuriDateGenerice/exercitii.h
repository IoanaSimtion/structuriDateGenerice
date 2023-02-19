#include "stiva.h";

#include "coada.h";

#pragma once


//1. sa se verifice folosind o stiva daca un text este corect balantat 
//(asdas][)


bool eBalantat(string text) {

	Stiva<char> s;


	for (int i = 0; i < text.length(); i++) {

		if (text[i] == '(') {

			s.push(text[i]);
		}
		if (text[i] == ')') {

			if (s.isEmpty() == true) {

				return false;
			}
			s.pop();
		}
	}

	cout << "aici" << endl;

	return s.isEmpty();
	

}




void sol1() {

	Stiva<char> s;

	string text = "(ma)))()(mnjk(abc(n))";

	cout << eBalantat(text);

}