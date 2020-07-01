#pragma once
#include <string>

using namespace std;

//IMPLEMENTACION (Hay que usar esta estructura para implementarlo)

/*
#include <iostream>
#include <string>
#include <fstream>
#include "Archivo.h"

using namespace std;

int main()
{
	Archivo archivo;
	Nodo* cabecera = NULL;

	archivo.cargarLista(cabecera);
	archivo.insertarElemento(cabecera, 8); //En la segunda posicion meter la variable de puntuacion
	archivo.guardarLista(cabecera);
	archivo.mostrarElemento(cabecera);

}
*/

struct Nodo
{
	string nombre;
	int puntuacion;
	Nodo* siguiente;
};

class Archivo
{
public:
	Archivo();
	virtual ~Archivo();

	void insertarElemento(Nodo*&, int);
	void mostrarElemento(Nodo*);
	void guardarLista(Nodo*);
	void cargarLista(Nodo*&);
};

