#pragma once
#include "Entidad.h"
#include <vector>

class ListaEntidades
{
public:
	friend class Interaccion;
	//friend Personaje;
	ListaEntidades();
	virtual ~ListaEntidades();

	bool Agregar(Entidad* ent);
	void Dibuja();
	void EliminarEntidad(int ind);
	void DestruirContenido();

	int GetNum();

	//private:
	std::vector<Entidad*> lista;
};