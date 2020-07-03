#pragma once
#include "Sierra.h"
#include <vector>

class ListaSierras
{
public:
	friend Interaccion;
	friend class Mundo;

	ListaSierras();
	virtual ~ListaSierras();

	bool Agregar(Sierra* rec);
	void Dibuja();
	void EliminarSierra(int ind);
	void DestruirContenido();

	int GetNum();

private:
	std::vector<Sierra*> lista;
};

