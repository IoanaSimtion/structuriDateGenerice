#pragma once

#include "node.h";

template<typename S>
struct Stiva {

	Node<S>* top = NULL;


	void afisare() {

		Node<S>* aux = top;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}

	}


	void push(S data) {

		if (top == NULL) {

			top = new Node<S>();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node<S>* nou = new Node<S>();

			nou->data = data;

			nou->next = top;

			top = nou;

		}

	}


	void pop() {

		top = top->next;

	}


	bool isEmpty() {

		if (top == NULL) {

			return true;

		}

		return false;

	}


	S peak() {

		Node<S>* aux = top;

		return aux->data;

	}

};