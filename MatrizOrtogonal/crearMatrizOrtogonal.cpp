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

/*SE CREA UN JUGADOR*/

matrizOrtogonal* crearJugador(int x,int y,string nombre,int punteo,double tiempoPartida) {
	
	matrizOrtogonal* matriz2;
	
	matriz2 = new matrizOrtogonal();
	
	matriz2->insertarJugador(x,y,nombre,punteo,tiempoPartida);	

	return matriz2;
}

/*SE CREA LA MATRIZ MANUALMENTE*/
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

/*CREA LA MATRIZ ALEATORIAMENTE*/
matrizOrtogonal* crearMatrizAleatoria(int alto, int ancho) {

	matrizOrtogonal* matriz;
	matriz = new matrizOrtogonal();
	
	matriz->crearMatrizAleatoria(alto, ancho);
	matriz->mostarTablero();
	
	return matriz;

}
/*PARA ENCONTRAR UN NUMERO*/
void mover(int x, int y,string opcion, matrizOrtogonal* m) {
	
	nodoValor* valorAMover;
	nodoValor* tmp;
	
	valorAMover = m->moverPieza(x,y,m);
	tmp = m->moverPieza(x, y, m);
	
	
	cout <<"\n";
	cout << "Numero a mover: " << valorAMover->numero<<"\n";

	// SI X ESTA ABAJO
	if (opcion == "abajo") {
		
		if (valorAMover->abajo->nombre == "X") {
			
			cout << "Se realizo el cambio";
			valorAMover->nombre = "X";
			valorAMover->abajo->numero = tmp->numero;
			valorAMover->abajo->nombre = "a";
			
			
			
			m->mostarTablero();
		}
		else {
			cout << "\nNO es posible realizar el cambio\n";
			m->mostarTablero();
		}

	}
	// SI X ESTA ARRIBA
	else if (opcion == "arriba") {
		
		if (valorAMover->arriba->nombre == "X") {
			
			cout << "Se realizo el cambio";
			valorAMover->nombre = "X";
			valorAMover->arriba->numero = tmp->numero;
			valorAMover->arriba->nombre = "a";
			
			

			m->mostarTablero();
		}
		else {
			cout << "\nNO es posible realizar el cambio\n";
			m->mostarTablero();
		}
	
	// SI X ESTA A LA DERECHA
	}else if(opcion == "derecha") {
	
		if (valorAMover->derecha->nombre == "X") {
			cout << "Se realizo el cambio";
			
			valorAMover->nombre = "X";
			valorAMover->derecha->numero = tmp->numero;
			valorAMover->derecha->nombre = "a";
			
			
			m->mostarTablero();
		}
		else {
			cout << "\nNO es posible realizar el cambio\n";
			m->mostarTablero();
		}
	}
	// SI X ESTA A LA IZQUIERDA
	else if (opcion == "izquierda") {

		if (valorAMover->izquierda->nombre == "X") {
			cout << "Se realizo el cambio";
			valorAMover->nombre = "X";
			valorAMover->izquierda->numero = tmp->numero;
			valorAMover->izquierda->nombre = "a";
			
			
			m->mostarTablero();
		}
		else {
			cout << "\nNO es posible realizar el cambio\n";
			m->mostarTablero();
		}

	}

}
/*SE MUESTRA EL TABLERO*/
void mostrarElTablero(matrizOrtogonal* m) {
	m->mostarTablero();
}

int obtenerPunteo(int alto,int ancho,matrizOrtogonal* m) {
	int punteo;
	punteo = m->ordenamiento(alto, ancho,m);
	return punteo;
}