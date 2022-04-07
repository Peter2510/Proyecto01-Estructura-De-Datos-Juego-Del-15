#pragma once
void crearMatrizOrtogonal(int x,int y);
matrizOrtogonal* crearJugador(int x, int y, string nombre,int punteo,double tiempoPartida);
matrizOrtogonal* crearMatrizManual(int x, int y);
matrizOrtogonal* crearMatrizAleatoria(int x, int y);
void mover(int x, int y,string opcion, matrizOrtogonal* m);
void mostrarElTablero(matrizOrtogonal* m);
int obtenerPunteo(int alto,int ancho,matrizOrtogonal* m);
