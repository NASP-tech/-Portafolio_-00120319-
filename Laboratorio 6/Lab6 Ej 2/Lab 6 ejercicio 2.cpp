#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo
{
	int datos;
	struct Nodo* izq, * der;
};

Nodo* nuevoNodo(int datos)
{
	Nodo* temp = new Nodo;
	temp->datos = datos;
	temp->izq = temp->der = NULL;
	return temp;
}

void intercambiar(Nodo** a, Nodo** b)
{
	Nodo* temp = *a;
	*a = *b;
	*b = temp;
}

void IntercabiarSubArbolesDI(Nodo* raiz, int level, int k)
{
	if (raiz == NULL ||
		(raiz->izq == NULL && raiz->der == NULL))
		return;

	if ((level + 1) % k == 0)
		intercambiar(&raiz->izq, &raiz->der);

	IntercabiarSubArbolesDI(raiz->izq, level + 1, k);
	IntercabiarSubArbolesDI(raiz->der, level + 1, k);
}

void IntercabiarSubArboles(Nodo* raiz, int k)
{
	IntercabiarSubArbolesDI(raiz, 1, k);
}

void inorden(Nodo* raiz)
{
	if (raiz == NULL)
		return;
	inorden(raiz->izq);
	cout << raiz->datos << " ";
	inorden(raiz->der);
}

int main()
{
	struct Nodo* raiz = nuevoNodo(1);
	raiz->izq = nuevoNodo(2);
	raiz->der = nuevoNodo(3);
	raiz->izq->izq = nuevoNodo(4);
	raiz->der->der = nuevoNodo(8);
	raiz->der->izq = nuevoNodo(7);

	int k = 2;
	cout << "\n\tArbol original:" << endl;
	inorden(raiz);

	IntercabiarSubArboles(raiz, k);

	cout << "\n\t Arbol intercambiado:" << endl;
	inorden(raiz);
	return 0;
}