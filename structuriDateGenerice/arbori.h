#pragma once

#include "treeNode.h";

#include "stiva.h";

#include <fstream>

#include "coada.h";

//template<typename T>

struct TreeIerarhie {

	TreeNodeIerarhie* root = NULL;

	TreeNodeIerarhie* find(string  data,TreeNodeIerarhie* current) {

		
		if (current == NULL) {

			return NULL;
		}
		if (current->data == data) {

			return current;
		}

		TreeNodeIerarhie* left = find(data,current->left);

		if (left != NULL) {

			return left;
		}

		return find(data, current->right);

		

	}

	TreeIerarhie(string ceo) {

		
		root = new TreeNodeIerarhie();

		root->left = NULL;

		root->right = NULL;

		root->data = ceo;


	}

	bool addSubordonat(string manager, string subordonat) {
				
		TreeNodeIerarhie* nodeManager = find(manager, root);

		if (nodeManager != NULL) {
			TreeNodeIerarhie* nou = new TreeNodeIerarhie();
			nou->left = NULL;
			nou->right = NULL;
			nou->data = subordonat;
			if (nodeManager->left == NULL) {
				nodeManager->left = nou;
				return true;
			}else if (nodeManager->right == NULL) {
				nodeManager->right = nou;
				return true;
			}
		}

		return false;

	}
	void afisare() {


		TreeNodeIerarhie* aux = root;
		

		Coada<TreeNodeIerarhie*>coada;

		coada.push(aux);

		while (coada.isEmpty() == false) {
			aux = coada.peak()->data;
			if (aux->left != NULL) {

				coada.push(aux->left);
			}

			if (aux->right != NULL) {

				coada.push(aux->right);
			}
			
			cout << aux->data << " ";
				coada.pop();
		}
	}


	void treeFisier() {

		ifstream f("arbore.txt");

		string manager, subordonat;

		TreeNodeIerarhie* aux = root;

		while (!f.eof()) {

			f >> subordonat;

			f >> manager;

			if (manager == "NULL") {

				aux->data = subordonat;

			}
			else {

				addSubordonat(manager, subordonat);

			}

		}

	}
	

};






