//#include "lista.h";
#include "stiva.h";

int main()
{

    //LISTA


    /*
    Lista<char> lista;

    //cout << lista.isEmpty();

    lista.addStart('a');

    lista.addStart('b');

    lista.addStart('s');

    lista.addStart('i');

    lista.add('X');
    
    lista.afisare();

    cout << endl << endl;

    //cout << lista.get(1);

    //cout << lista.size();

    //cout << lista.indexOf('x');

    //cout << lista.contains('b');

    //cout << lista.isEmpty();

    //lista.removeIndex(0);

    //lista.removeObject('b');

    //lista.set('x', 2);

    //lista.afisare();
    */   



    //STIVA


    Stiva<char> s;

    //cout << s.isEmpty();

    s.push('A');

    s.push('w');

    s.push('C');

    s.push('q');

    s.push('o');

    s.afisare();

    cout << endl << endl;

    cout << s.peak();

    s.pop();

    s.pop();

    s.afisare();

    //cout << s.isEmpty();

    //cout << s.peak();



}
