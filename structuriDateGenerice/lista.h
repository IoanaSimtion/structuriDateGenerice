#pragma once

#include "node.h";


template<typename U>
struct Lista {

	Node<U>* head;

	void addStart(U data) {

		if (head == NULL) {

			head = new Node<U>();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node<U>* nou = new Node<U>();

			nou->data = data;

			nou->next = head;

			head = nou;

		}

	}


	

};