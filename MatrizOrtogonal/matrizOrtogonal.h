#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;



/*NODO QUE TIENE LOS VALORES A INGRESAR*/

struct nodoValor {

	int numero, x, y, punteo = 0;
	string nombre;

	//Apuntadores entre si
	nodoValor* arriba;
	nodoValor* abajo;
	nodoValor* izquierda;
	nodoValor* derecha;


	//constructor del nodo que tiene los valores

	nodoValor(int numero, int eje_x, int eje_y) {

		this->numero = numero;
		this->x = eje_x;
		this->y = eje_y;
		arriba = NULL;
		abajo = NULL;
		izquierda = NULL;
		derecha = NULL;

	}

	//constructor del nodo que tiene los valores nombre y  X
	nodoValor(string nombre, int eje_x, int eje_y) {

		this->nombre = nombre;
		this->x = eje_x;
		this->y = eje_y;
		arriba = NULL;
		abajo = NULL;
		izquierda = NULL;
		derecha = NULL;

	}
};

/* Lista enlazada vertical */

struct listaEnlazadaVertical {

	nodoValor* primero;
	nodoValor* ultimo;

	listaEnlazadaVertical() {
		primero = NULL;
		ultimo = NULL;
	}

	bool isEmpty() {

		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}

	}



	void insertar(nodoValor* valor) {

		if (isEmpty()) {
			primero = ultimo = valor;

		}
		else {
			if (valor->y < primero->y) {
				insertarAlFrente(valor);
			}
			else if (valor->y > ultimo->y) {
				insertarUltimo(valor);
			}
			else {
				insertarAlMedio(valor);
			}
		}
	}

	void insertarAlFrente(nodoValor* datoIngresar) {
		primero->arriba = datoIngresar;
		datoIngresar->abajo = primero;
		primero = primero->arriba;
	}

	void insertarUltimo(nodoValor* datoIngresar) {
		ultimo->abajo = datoIngresar;
		datoIngresar->arriba = ultimo;
		ultimo = ultimo->abajo;

	}

	void insertarAlMedio(nodoValor* datoIngresar) {
		nodoValor* tmp1;
		nodoValor* tmp2;
		tmp1 = primero;

		while (tmp1->y < datoIngresar->y) {
			tmp1 = tmp1->abajo;
		}
		tmp2 = tmp1->arriba;

		tmp2->abajo = datoIngresar;
		tmp1->arriba = datoIngresar;
		datoIngresar->abajo = tmp1;
		datoIngresar->arriba = tmp2;

	}

};

/* lista enlazada horizontal .*/

struct listaEnlazadaHorizontal {

	nodoValor* primero;
	nodoValor* ultimo;

	listaEnlazadaHorizontal() {
		primero = NULL;
		ultimo = NULL;
	}

	bool isEmpty() {

		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}
	}



	void insertar(nodoValor* valor) {

		if (isEmpty()) {
			primero = ultimo = valor;

		}
		else {
			if (valor->x < primero->x) {
				insertarAlFrente(valor);
			}
			else if (valor->x > ultimo->x) {
				insertarAlFinal(valor);
			}
			else {
				insertarAlMedio(valor);
			}
		}
	}

	void insertarAlFrente(nodoValor* valor) {
		primero->izquierda = valor;
		valor->derecha = primero;
		primero = primero->izquierda;
	}

	void insertarAlMedio(nodoValor* valor) {
		nodoValor* tmp1;
		nodoValor* tmp2;
		tmp1 = primero;

		while (tmp1->x < valor->x) {
			tmp1 = tmp1->derecha;
		}
		tmp2 = tmp1->izquierda;

		tmp2->derecha = valor;
		tmp1->izquierda = valor;
		valor->derecha = tmp1;
		valor->izquierda = tmp2;

	}

	void insertarAlFinal(nodoValor* valor) {
		ultimo->derecha = valor;
		valor->izquierda = ultimo;
		ultimo = ultimo->derecha;

	}



};



/*NODO CABECERA . */

struct nodoDeCabecera {
	int x;
	nodoDeCabecera* siguiente;
	nodoDeCabecera* anterior;
	listaEnlazadaVertical* Columna;

	nodoDeCabecera(int x) {

		this->x = x;
		Columna = new listaEnlazadaVertical();
		siguiente = NULL;
		anterior = NULL;
	}

};

/* CABECERAS */

struct NodosCabeceras {
	nodoDeCabecera* primero;
	nodoDeCabecera* ultimo;

	NodosCabeceras() {
		primero = NULL;
		ultimo = NULL;
	}



	void insertar(nodoDeCabecera* valor) {

		if (isEmpty()) {
			primero = ultimo = valor;

		}
		else {
			if (valor->x < primero->x) {
				insertarAlFrente(valor);
			}
			else if (valor->x > ultimo->x) {
				insertarAlFinal(valor);
			}
			else {
				insertarAlMedio(valor);
			}
		}
	}

	void insertarAlMedio(nodoDeCabecera* valor) {
		nodoDeCabecera* tmp1;
		nodoDeCabecera* tmp2;
		tmp1 = primero;

		while (tmp1->x < valor->x) {
			tmp1 = tmp1->siguiente;
		}
		tmp2 = tmp1->anterior;

		tmp2->siguiente = valor;
		tmp1->anterior = valor;
		valor->siguiente = tmp1;
		valor->anterior = tmp2;
	}

	void insertarAlFrente(nodoDeCabecera* valor) {
		primero->anterior = valor;
		valor->siguiente = primero;
		primero = primero->anterior;
	}

	void insertarAlFinal(nodoDeCabecera* valor) {
		ultimo->siguiente = valor;
		valor->anterior = ultimo;
		ultimo = ultimo->siguiente;

	}

	bool isEmpty() {

		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}

	}



	bool existeX(int x) {
		if (isEmpty()) {
			//	cout << "no existe" << endl;
			return false;

		}
		else {
			nodoDeCabecera* temporal;
			temporal = primero;
			while (temporal != NULL) {
				if (temporal->x == x) {
					//		cout<<"existe" << endl;
					return true;


				}
				else if (temporal->siguiente == NULL) {
					//			cout << "no se encontro" << endl;
					return false;
				}
				temporal = temporal->siguiente;
			}
		}
	}

	nodoDeCabecera* buscarNodoCabecera(int x) {
		if (existeX(x)) {
			nodoDeCabecera* tmp1;
			tmp1 = primero;
			while (tmp1->x != x) {
				tmp1 = tmp1->siguiente;
			}
			//cout << "retornando " << endl;
			return tmp1;
		}
		else {
			//	cout << "no existe" << endl;
			return(new nodoDeCabecera(-1));
		}
	}

};

/*NODO LATERALES*/

struct nodoLateral {
	int y;
	nodoLateral* siguiente;
	nodoLateral* anterior;
	listaEnlazadaHorizontal* Filas;

	nodoLateral(int y) {

		this->y = y;
		Filas = new listaEnlazadaHorizontal();
		anterior = NULL;
		siguiente = NULL;

	}

};

/*LISTA DE LOS LATERALES LATERALES*/

struct laterales {

	nodoLateral* primero;
	nodoLateral* ultimo;

	laterales() {
		primero = NULL;
		ultimo = NULL;
	}

	bool isEmpty() {

		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}

	}



	void insertar(nodoLateral* valor) {

		if (isEmpty()) {
			primero = ultimo = valor;

		}
		else {
			if (valor->y < primero->y) {
				insertarAlFrente(valor);
			}
			else if (valor->y > ultimo->y) {
				insertarAlFinal(valor);
			}
			else {
				insertarAlMedio(valor);
			}
		}
	}

	void insertarAlFrente(nodoLateral* valor) {
		primero->anterior = valor;
		valor->siguiente = primero;
		primero = primero->anterior;
	}

	void insertarAlMedio(nodoLateral* valor) {
		nodoLateral* temporal1;
		nodoLateral* temporal2;
		temporal1 = primero;

		while (temporal1->y < valor->y) {
			temporal1 = temporal1->siguiente;
		}
		temporal2 = temporal1->anterior;

		temporal2->siguiente = valor;
		temporal1->anterior = valor;
		valor->siguiente = temporal1;
		valor->anterior = temporal2;

	}

	void insertarAlFinal(nodoLateral* valor) {
		ultimo->siguiente = valor;
		valor->anterior = ultimo;
		ultimo = ultimo->siguiente;

	}



	bool existeY(int y) {
		if (isEmpty()) {
			//	cout << "no existe" << endl;
			return false;

		}
		else {
			nodoLateral* temporal;
			temporal = primero;
			while (temporal != NULL) {
				if (temporal->y == y) {
					//		cout << "existe" << endl;
					return true;


				}
				else if (temporal->siguiente == NULL) {
					//		cout << "no se encontro" << endl;
					return false;
				}
				temporal = temporal->siguiente;
			}
		}
	}

	nodoLateral* buscarNodoLateral(int y) {
		if (existeY(y)) {
			nodoLateral* tmp;
			tmp = primero;
			while (tmp->y != y) {
				tmp = tmp->siguiente;
			}

			return tmp;
		}
		else {
			//	cout << "no existe ****" << endl;
			return(new nodoLateral(-1));
		}
	}

};

struct matrizOrtogonal {

	laterales* lateral;
	NodosCabeceras* cabeza;


	matrizOrtogonal() {
		cabeza = new NodosCabeceras();
		lateral = new laterales();
	}

	void insertar(int x, int y, int numero) {
		nodoValor* insercion;
		insercion = new nodoValor(numero, x, y);

		if (cabeza->existeX(x) == false) {
			cabeza->insertar(new nodoDeCabecera(x));
		}if (lateral->existeY(y) == false) {
			lateral->insertar(new nodoLateral(y));
		}

		//para insertar
		nodoDeCabecera* CabezaTemporal;
		//para insertar
		nodoLateral* LadoTemporal;

		CabezaTemporal = cabeza->buscarNodoCabecera(x);
		LadoTemporal = lateral->buscarNodoLateral(y);

		CabezaTemporal->Columna->insertar(insercion);
		LadoTemporal->Filas->insertar(insercion);
		//cout << "Se inserto el valor " << numero << " en la columna " << y << " fila" << x << endl;
		//	cout << "Se inserto " << numero << " en x " << y << " y " << x << endl;
	}

	void insertar(int x, int y, string cadena) {
		nodoValor* insercion;
		insercion = new nodoValor(cadena, x, y);

		if (cabeza->existeX(x) == false) {
			cabeza->insertar(new nodoDeCabecera(x));
		}if (lateral->existeY(y) == false) {
			lateral->insertar(new nodoLateral(y));
			//	cout << "Se inserto " << cadena << " en x " << y << " y " << x << endl;
		}

		nodoDeCabecera* cabezaTemporal;
		nodoLateral* ladoTemporal;
		cabezaTemporal = cabeza->buscarNodoCabecera(x);
		ladoTemporal = lateral->buscarNodoLateral(y);

		cabezaTemporal->Columna->insertar(insercion);
		ladoTemporal->Filas->insertar(insercion);
		//	cout << "Se inserto el valor " << cadena << " en la columna " << x << " fila" << y << endl;
	//		cout << "Se inserto " << cadena << " en x " << x << " y " << y << endl;
	}


	void llenar(int x, int y) {
		int numero = 0;

		for (int p = 0; p < y; p++) {

			for (int g = 0; g < x; g++) {

				if (p == y - 1 && g == x - 1) {
					insertar(g, p, "X");
				}
				else {
					insertar(g, p, numero);
					numero++;
				}

			}
		}
	}


	bool isEmpty() {

		if (cabeza == NULL && lateral == NULL) {
			return true;
		}
		else {
			return false;
		}

	}

	void MostrarJugadores() {

		if (!isEmpty()) {

			nodoDeCabecera* tmp2 = cabeza->primero;

			while (tmp2 != NULL) {
				cout << "Nombre jugador: " << tmp2->Columna->primero->nombre << ", Punteo: " << tmp2->Columna->primero->punteo << endl;
				tmp2 = tmp2->siguiente;

			}
		}

	}

	/*MOSTRAR EL TABLERO GENERADO*/

	void mostarTablero() {

		if (!isEmpty()) {

			nodoDeCabecera* tmp1 = cabeza->primero;
			nodoValor* tmp2 = cabeza->primero->Columna->primero;
			//nodoValor* constante = c->primero->Columna->primero->abajo;
			nodoValor* constante = cabeza->primero->Columna->primero->abajo;
			cout << "\n\n";
			tmp2 = imprimirLinea(tmp1->Columna->primero);
			cout << "\n";

			while (constante != NULL) {

				//if (tmp2 == NULL) {

				tmp2 = imprimirLinea(constante);
				constante = constante->abajo;
				cout << "\n";

				//}

			}

		}

	}


	nodoValor* imprimirLinea(nodoValor* nodo) {

		while (nodo != NULL) {

			if (nodo->nombre == "X") {
				cout << nodo->nombre << "  ";
				nodo = nodo->derecha;
			}
			else {
				if (nodo->numero < 10) {
					cout << nodo->numero << "  ";
					nodo = nodo->derecha;
				}
				else {
					cout << nodo->numero << " ";
					nodo = nodo->derecha;
				}
			}

		}

		return nodo;

	}

	void crearMatrizAleatoria(int x, int y) {

		int numA;

		for (int p = 0; p < y; p++) {


			for (int g = 0; g < x; g++) {

				numA = numeroAleatorio();

				if (p == y - 1 && g == x - 1) {
					insertar(g, p, "X");
				}
				else {
					insertar(g, p, numA);

				}
			}
		}


	}

	int numeroAleatorio() {
		int  num;
		num = 1 + rand() % (99 - 1);
		return num;

	}


	void moverPieza(int x, int y, matrizOrtogonal* m) {

		if (!isEmpty()) {

			nodoDeCabecera* tmp1 = m->cabeza->primero;
			nodoValor* tmp2 = m->cabeza->primero->Columna->primero;
			
			for (int i = 0; i <= y; i++) {
				
				
				

				for (int j = 0; j <= x; j++) {
					tmp2 = tmp2->derecha;
					tmp2 = tmp2->abajo;
				}

				
			}
			
			if (tmp2->nombre == "X") {
				cout << "hallado" << tmp2->nombre;
			}
			else {
				cout << "hallado" << tmp2->numero;
			}

			


			

		}


	}

};

