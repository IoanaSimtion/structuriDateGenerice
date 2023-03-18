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



struct BinaryTree {

	TreeNode* root = NULL;


	BinaryTree(int number) {

		root = new TreeNode();

		root->left = NULL;

		root->right = NULL;

		root->data = number;

	}


	void add(TreeNode*current,int numar) {

		if (current == NULL) {

			TreeNode* nou = new TreeNode();

			nou->left = NULL;

			nou->right = NULL;

			nou->data = numar;

		}
		else if (current->data>numar) {


			if (current->left != NULL) {

				add(current->left, numar);
			}
			else {

				current->left = new TreeNode();
				current->left->data = numar;
				current->left->left = NULL;
				current->left->right = NULL;
			}

		}
		else {

			if (current->right != NULL) {

				add(current->right, numar);
			}
			else {

				current->right = new TreeNode();
				current->right->data = numar;
				current->right->left = NULL;
				current->right->right = NULL;

			}

		}
		

	}


	void afisare() {

		TreeNode* aux = root;

		Coada<TreeNode*> coada;

		coada.push(aux);

		while (coada.isEmpty() == false) {

			aux = coada.peak()->data;

			if (aux->left != NULL) {

				coada.push(aux->left);

			}

			if (aux->right != NULL) {

				coada.push(aux->right);

			}
			
			cout << aux->data << ' ';

			coada.pop();

		}

	}
	

	TreeNode* find(int numar, TreeNode* current) {

		if (current == NULL) {

			return NULL;

		}

		if (current->data == numar) {

			return current;

		}

		TreeNode* aux = find(numar, current->left);

		if (aux != NULL) {

			return aux;

		}

		return find(numar, current->right);
	}


	int elementMaxim() {

		int maxim = INT_MIN;

		TreeNode* aux = root;

		Coada<TreeNode*> coada;

		coada.push(aux);

		while (coada.isEmpty() == false) {

			aux = coada.peak()->data;

			if (aux->left != NULL) {

				if (aux->left->data > maxim) {
					maxim = aux->left->data;
				}

				coada.push(aux->left);

			}

			if (aux->right != NULL) {

				if (aux->right->data > maxim) {
					maxim = aux->right->data;
				}

				coada.push(aux->right);
			}

			coada.pop();
		}

		return maxim;
	}


	int elementMinim() {

		int minim = INT_MAX;

		TreeNode* aux = root;

		Coada<TreeNode*> coada;

		coada.push(aux);

		while (coada.isEmpty() == false) {

			aux = coada.peak()->data;

			if (aux->left != NULL) {

				if (aux->left->data < minim) {
					minim = aux->left->data;
				}

				coada.push(aux->left);

			}

			if (aux->right != NULL) {

				if (aux->right->data < minim) {
					minim = aux->right->data;
				}

				coada.push(aux->right);

			}

			coada.pop();
		}

		return minim;

	}


	void preordine(TreeNode* current) {
		
		if (current == NULL) {
			return;
		}
		cout << current->data << ' ';
		preordine(current->left);
		preordine(current->right);

	}
	 

	void ordine(TreeNode* current) {

		if (current == NULL) {
			return;
		}
		ordine(current->left);		
		cout << current->data << ' ';
		ordine(current->right);

	}


	void postordine(TreeNode* current) {

		if (current == NULL) {
			return;
		}
		postordine(current->left);
		postordine(current->right);
		cout << current->data << ' ';

	}


};


