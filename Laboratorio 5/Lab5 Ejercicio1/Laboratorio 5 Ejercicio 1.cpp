// Laboratorio 5 Ejercicio 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
struct Node* createnode(int data)
{
	Node* newnode = new Node;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int max(int a, int b)
{
	int res = (a > b) ? a : b;
	return res;
}
int height(Node* node)
{
	if (node == NULL)
		return 0;
	return (1 + max(height(node->left), height(node->right)));
}



int sum(Node* root)
{
	if (root == NULL)
		return 0;
	return (root->data + sum(root->left) + sum(root->right));
}

int size(Node* node)
{
	if (node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}
int main()
{
	Node* root = createnode(1);
	root->left = createnode(2);
	root->right = createnode(3);
	root->left->left = createnode(4);
	root->left->right = createnode(5);
	root->left->right->left = createnode(7);
	root->left->right->right = createnode(8);
	root->right->right = createnode(6);
	root->right->right->right = createnode(9);
	root->right->right->right->left = createnode(11);
	root->right->right->right->right = createnode(10);
	root->right->right->right->left->left = createnode(12);
	root->right->right->right->left->right = createnode(13);
	cout << "Altura del arbol binario: " << height(root) << endl;
	cout << "Tamano del arbol binario: " << size(root) << endl;
	cout << "Suma de los nodos del arbol binario: " << sum(root) << endl;
	return 0;
}