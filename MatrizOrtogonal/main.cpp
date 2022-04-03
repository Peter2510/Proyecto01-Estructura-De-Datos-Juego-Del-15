#include "matrizOrtogonal.h"
#include "crearMatrizOrtogonal.h"


int opcion;
bool salir = false;
int contadorJugadorX=0;
matrizOrtogonal* matrizNombres ;
matrizOrtogonal* matrizAleatoria;
matrizOrtogonal* matrizManual;


int main() {

	do {

		cout << "\n\n*** Bienvenido ***\n\n";
		cout << "Ingresa una opcion a realizar " << endl;
		cout << "1. Iniciar partida " << endl;
		cout << "2. Reporte de partidas " << endl;
		cout << "3. Salir " << endl;
		cin >> opcion;

		if (opcion == 1) {

			int ancho;
			int alto;
			string nombre;
			cout << "\n--------------------------- " << endl;
			cout << "\nSe inicia partida " << endl;
			cout << "Ingresa tu nombre\n";
			cin >> nombre;
			cout << "\n";
			if(contadorJugadorX==0){
				matrizNombres = crearJugador(contadorJugadorX, 0, nombre);
				contadorJugadorX++;
			}
			else {
				matrizNombres->insertar(contadorJugadorX, 0, nombre);
			}
			
			int llenado;

			cout << "Ingresa el numero que corresponda\n";
			cout << "1. Llenar de forma manual\n";
			cout << "2. Llenar de forma aleatoria\n";
			
			cin >> llenado;
			cout << "\n";

			cout << "Las posiciones se ingresan (fila,columna) iniciando x=1 y y=1\n\n";

			if (llenado == 1) {
				
				int moverX;
				int moverY;
				string opcion;

				cout << "Ingresa el alto del tablero" << endl;
				cin >> alto;
				cout << "Ingresa el ancho del tablero" << endl;
				cin >> ancho;
				cout << "\n";
				matrizManual = crearMatrizManual(alto, ancho);
				cout << "\n";
				
				do {
					cout << "\nLas posiciones se ingresan (fila,columna) iniciando x=1 y y=1\n\n";
					
					cout << "Posicion fila a mover: ";
					cin >> moverX;

					cout << "Posicion columna a mover: ";
					cin >> moverY;
					
					cout << "\n\nLos movimientos pueden ser: arriba, abajo, derecha e izquierda\n";
					cout << "Movimiento a realizar: ";
					cin >> opcion;
					
					mover(moverX, moverY,opcion, matrizManual);

				} while (moverX!=88);

								

			}
			else if (llenado == 2) {
				int moverX;
				int moverY;
				string opcion;
				

				cout << "Ingresa el alto del tablero" << endl;
				cin >> alto;
				cout << "Ingresa el ancho del tablero" << endl;
				cin >> ancho;
				matrizAleatoria = crearMatrizAleatoria(alto,ancho);
				cout << "\n";

				do {
					cout << "\nLas posiciones se ingresan (fila,columna) iniciando x=1 y y=1\n\n";

					cout << "Posicion fila a mover: ";
					cin >> moverX;

					cout << "Posicion columna a mover: ";
					cin >> moverY;
					
					
					cout << "\n\nLos movimientos pueden ser: arriba, abajo, derecha e izquierda\n";
					cout << "Movimiento a realizar: ";
					cin >> opcion;

					mover(moverX, moverY, opcion, matrizAleatoria);

				} while (moverX != 88);
			}

									
		}
		else if (opcion == 2) {
			cout << "\n--------------------------- " << endl;
			cout << "Reporte de partidas " << endl;
			matrizNombres->MostrarJugadores();
			cout << "--------------------------- ";
			cout << "\n\n";


		}
		else if (opcion == 3) {
			salir = true;
			cout << "Vuelve pronto." << endl;
		}

	} while (salir == false);


	return 0;
}