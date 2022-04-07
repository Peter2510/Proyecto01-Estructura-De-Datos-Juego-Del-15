#include <ctime> 
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
			
			
			int llenado;

			cout << "Selecciona la forma de llenar el tablero\n";
			cout << "1. Llenar de forma manual\n";
			cout << "2. Llenar de forma aleatoria\n";
			cout << "3. Carga de archivo\n";
			
			cin >> llenado;
			cout << "\n";

			cout << "Las posiciones se ingresan (fila,columna) iniciando x=1 y y=1\n\n";

			if (llenado == 1) {
				
				int moverX;
				int moverY;
				string opcion;
				string continuar = "si";
				int punteo = 0;
				int tiros = 0;
				unsigned t0, t1;

				t0 = clock();

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
					
					cout << "\n\nLos movimientos pueden ser: arriba, abajo, derecha o izquierda\n";
					cout << "Movimiento a realizar: ";
					cin >> opcion;
					
					mover(moverX, moverY,opcion, matrizManual);

					cout << "\nDesea continuar?\n";
					cout << "si\n";
					cout << "no\n";
					cin >> continuar;
					mostrarElTablero(matrizManual);
					tiros++;
				} while (continuar != "no");
				
				punteo = obtenerPunteo(alto, ancho, matrizManual);
				cout << "Movimientos realizados = " << tiros;
				//tiempo de partida
				t1 = clock();
				double time = (double(t1 - t0) / CLOCKS_PER_SEC);
				cout << "\nTiempo de partida : " << time << " segundos" << endl;
				delete matrizManual;

				// se crea el jugador
				if (contadorJugadorX == 0) {
					matrizNombres = crearJugador(contadorJugadorX,0 , nombre,punteo,time);
					contadorJugadorX++;
				}
				else {
					matrizNombres->insertarJugador(contadorJugadorX, 0, nombre,punteo,time);
					contadorJugadorX++;
				}

				
								

			}
			else if (llenado == 2) {
				int moverX;
				int moverY;
				string opcion;
				string continuar = "si";
				int punteo = 0;
				int tiros = 0;

				unsigned t0, t1;
				
				t0 = clock();
							

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
										
					cout << "\n\nLos movimientos pueden ser: arriba, abajo, derecha o izquierda\n";
					cout << "Movimiento a realizar: ";
					cin >> opcion;

					mover(moverX, moverY, opcion, matrizAleatoria);
					
					cout << "\nDesea continuar?\n";
					cout << "si\n";
					cout << "no\n";
					cin >> continuar;
					mostrarElTablero(matrizAleatoria);

				} while (continuar != "no");

				//VER EL ORDEN
				cout << "\n";
				
				cout << "Movimientos realizados = " << tiros;
				
				punteo = obtenerPunteo(alto,ancho,matrizAleatoria);

				//calcular tiempo
				t1 = clock();
				double time = (double(t1 - t0) / CLOCKS_PER_SEC);
				cout << "\nTiempo de partida : " << time << " segundos" << endl;
				
				// se crea el jugador
				if (contadorJugadorX == 0) {
					matrizNombres = crearJugador(contadorJugadorX,0 , nombre,punteo,time);
					contadorJugadorX++;
					
				}
				else {
					
					matrizNombres->insertarJugador(contadorJugadorX,0 , nombre,punteo,time);
					contadorJugadorX++;
				}
				delete matrizAleatoria;
			}
			else if (llenado == 3) {
			cout << "Se carga el archivo\n";
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