#pragma once
#include "Rectangulo.h"
#include "Interaccion.h"
#include <vector>

class ListaRectangulos
{
public:
	ListaRectangulos();
	virtual ~ListaRectangulos();

	bool agregar(Rectangulo* rec);
	void dibuja();
	void eliminarRectangulo(int ind);
	int getNum();
	void choque(Personaje &person);

private:
	std::vector<Rectangulo*> lista;
	friend class Interaccion;
};