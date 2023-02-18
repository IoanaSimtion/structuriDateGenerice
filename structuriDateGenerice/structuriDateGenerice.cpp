#include "lista.h";
//#include <iostream>
//using namespace std;

int main()
{

    Lista<char> lista;

    lista.addStart('s');

    lista.addStart('i');
    
    Node<char>* aux = lista.head;

    while (aux != NULL) {

        cout << aux->data << "";

        aux = aux->next;

    }
   



    
}
