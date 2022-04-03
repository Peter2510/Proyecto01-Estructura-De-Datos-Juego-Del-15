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

			if (llenado == 1) {
				
				int moverX;
				int moverY;

				cout << "Ingresa el alto del tablero" << endl;
				cin >> alto;
				cout << "Ingresa el ancho del tablero" << endl;
				cin >> ancho;
				cout << "\n";
				matrizManual = crearMatrizManual(alto, ancho);
				
				cout << "Posicion X a mover: "; 
				cin >> moverX;

				cout << "Posicion Y a mover: ";
				cin >> moverY;
				cout << "\n";
				mover(moverX,moverY, matrizManual);
				//mover(0,1, matrizManual);

			}
			else if (llenado == 2) {
				cout << "Ingresa el alto del tablero" << endl;
				cin >> alto;
				cout << "Ingresa el ancho del tablero" << endl;
				cin >> ancho;
				matrizAleatoria = crearMatrizAleatoria(alto,ancho);
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