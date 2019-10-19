#include<iostream>
#include<cstdlib>
#include<string.h>
#define maxchar 50

using namespace std;


struct nodo {

	int codigo;     // campo codigo
	
	struct nodo* sgte;

};


typedef struct nodo* PLista;

void menu(void) {

	cout << "\n\t\t[    REGISTRO DE Elementos    ]\n";
	cout << "\t\t----------------------------\n\n";
	cout << " 1. REGISTRAR ELEMENTO                          " << endl;
	cout << " 2. ELIMINAR ELEMENTOS                " << endl;
	cout << " 3. MOSTRAR LISTADO                             " << endl;
	cout << " 4. SALIR                                       " << endl;

	cout << "\n Ingrese opcion : ";
}





void registrarElementos(PLista& lista) {

	PLista t, q = new(struct nodo);

	cout << "\n\n\t\t[  REGISTRO  ]\n";
	cout << "\t\t------------";
	cout << "\n\tElementos ";
	cin.ignore(); cout << "\n\n\tCODIGO:"; cin >> q->codigo;
	


	q->sgte = NULL;

	if (lista == NULL) {

		lista = q;

	}
	else {

		t = lista;

		while (t->sgte != NULL) {

			t = t->sgte;
		}

		t->sgte = q;

	}
}

void eliminarElementos(PLista& lista, int codigoLista) {

	PLista q, t;
	q = lista;
	t = NULL;

	
	while (q != NULL) {

		if (q->codigo == codigoLista) {

			if (q == lista)
				lista = lista->sgte;

			else
				t->sgte = q->sgte;

			delete(q);

			cout << "\n\n\tREGISTRO ELIMINADO...!!!!!\n";

			return;


		}
		else {

			t = q;
			q = q->sgte;

		}

	}
	if (q == NULL) 
		cout << "\n\tCODIGO INCORRECTO...!!\n";
	return;

}




void mostrarDatos(PLista q) {

	int i = 1;

	while (q != NULL) {

		cout << "\n\tMOSTRAR ELEMENTO [" << i << "] ";
		cout << "\n\t------------------------";
		cout << "\n\n\tCODIGO   : " << q->codigo << endl;
		

		q = q->sgte;

		i++;
	}

}
int main(void) {

	PLista lista = NULL;

	int opcion;

	do {
		menu();
		cin >> opcion;

		switch (opcion) {

		case 1: registrarElementos(lista);
			break;

		case 2: if (lista == NULL) {

			cout << "\n\tNo Hay Elementos Registrados.....!!!!\n";

		}
				else {

			eliminarElementos(lista,1);

		}
				break;

		

		case 3: if (lista == NULL) {

			cout << "\n\tNo Hay Elementos Registrados.....!!!!\n";

		}
				else {

			mostrarDatos(lista);

		}
				break;

		

		case 4: return 0;


		default: cout << "\nINGRESE UNA OPCION VALIDA...\n"; break;

		}


	} while (opcion != 6);

	

	return 0;
}



