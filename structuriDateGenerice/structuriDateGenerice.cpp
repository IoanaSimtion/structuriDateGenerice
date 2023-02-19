#include "lista.h";
//#include <iostream>
//using namespace std;

int main()
{

    Lista<char> lista;

    //cout << lista.isEmpty();

    lista.addStart('a');

    lista.addStart('b');

    lista.addStart('s');

    lista.addStart('i');

    lista.addSfarsit('X');
    
    lista.afisare();

    cout << endl << endl;

    //cout << lista.get(1);

    //cout << lista.size();

    //cout << lista.indexOf('x');

    //cout << lista.contains('b');

    //cout << lista.isEmpty();

    //lista.removeIndex(0);

    //lista.removeObject('b');

    lista.set('x', 2);

    lista.afisare();
       
}
