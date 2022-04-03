#include <iostream>
#include <time.h>
#include "matrizOrtogonal.h"
using namespace std;

void crearMatrizOrtogonal(int alto, int ancho) {
	matrizOrtogonal* matriz;
	matriz = new matrizOrtogonal();

	matriz->llenar(alto, ancho);
	matriz->mostarTablero();
	
}

/*void eliminarMatriz() {
	delete matriz;
}*/

matrizOrtogonal* crearJugador(int x,int y,string nombre) {
	
	matrizOrtogonal* matriz2;
	
	matriz2 = new matrizOrtogonal();
	
	matriz2->insertar(x,y,nombre);	

	return matriz2;
}

matrizOrtogonal* crearMatrizManual(int alto, int ancho) {
	
	matrizOrtogonal* matriz;
	matriz = new matrizOrtogonal();
	int valor;
	

		for (int p = 0; p < alto; p++) {

			for (int g = 0; g < ancho; g++) {

				cout << "Ingrese el valor de  x: "<<(p+1)<<", y: "<<(g+1)<<"\n";
				cin >> valor;

				if (p == alto - 1 && g == ancho - 1) {
					matriz->insertar(g, p, "X");
				}
				else {
					matriz->insertar(g, p, valor);
					
				}

			}
		}
		
	matriz->mostarTablero();
	return matriz;
}


matrizOrtogonal* crearMatrizAleatoria(int alto, int ancho) {

	matrizOrtogonal* matriz;
	matriz = new matrizOrtogonal();
	
	matriz->crearMatrizAleatoria(alto, ancho);
	matriz->mostarTablero();
	
	return matriz;

}

void mover(int x, int y,string opcion, matrizOrtogonal* m) {
	
	nodoValor* valorAMover;
	nodoValor* tmp;
	
	valorAMover = m->moverPieza(x,y,m);
	tmp = m->moverPieza(x, y, m);
	
	

	cout << "Numero a mover: " << valorAMover->numero<<"\n";

	// SI X ESTA ABAJO
	if (opcion == "abajo") {
		
		if (valorAMover->abajo->nombre == "X") {
			cout << "Si cambio";
			valorAMover->nombre = "X";
			valorAMover->abajo->numero = tmp->numero;
			valorAMover->abajo->nombre = "a";
			m->mostarTablero();
		}
		else {
			cout << "NO cambio";
		}

	}
	// SI X ESTA ARRIBA
	else if (opcion == "arriba") {
		
		if (valorAMover->arriba->nombre == "X") {
			cout << "Si cambio";
		}
		else {
			cout << "NO cambio";
		}
	
	// SI X ESTA A LA DERECHA
	}else if(opcion == "derecha") {
	
		if (valorAMover->derecha->nombre == "X") {
			cout << "Si cambio";
		}
		else {
			cout << "NO cambio";
		}
	}
	// SI X ESTA A LA DERECHA
	else if (opcion == "izquierda") {

		if (valorAMover->izquierda->nombre == "X") {
			cout << "Si cambio";
		}
		else {
			cout << "NO cambio";
		}

	}
}
