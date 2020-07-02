#pragma once
#include "Rectangulo.h"
#include <vector>

class ListaRectangulos
{
public:
	friend Interaccion;
	friend class Mundo;
	friend class Personaje;

	ListaRectangulos();
	virtual ~ListaRectangulos();

	bool Agregar(Rectangulo* rec);
	void Dibuja();
	void EliminarRectangulo(int ind);
	void DestruirContenido();

	int GetNum();

private:
	std::vector<Rectangulo*> lista;
};