#pragma once
#include "Rectangulo.h"
#include <vector>
#include "ETSIDI.h"
#include "glut.h"

class ListaRectangulos
{
public:
	friend Interaccion;
	//friend Personaje;
	ListaRectangulos();
	virtual ~ListaRectangulos();

	bool Agregar(Rectangulo* rec);
	void Dibuja();
	void EliminarRectangulo(int ind);
	void DestruirContenido();

	int GetNum();

//private:
	std::vector<Rectangulo*> lista;
};