#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{

}

ListaEntidades::~ListaEntidades()
{

}

bool ListaEntidades::Agregar(Entidad* ent)
{
	lista.push_back(ent);
	return true;
}

void ListaEntidades::Dibuja()
{
	for (int i = 0; i < lista.size(); i++)
	{
		lista[i]->Dibuja();
	}
}

void ListaEntidades::EliminarEntidad(int ind)
{
	if ((ind < 0) || (ind >= lista.size()))
		return;

	delete lista[ind];
	lista.erase(lista.begin() + ind);
}

int ListaEntidades::GetNum(void) {
	return lista.size();
}

void ListaEntidades::DestruirContenido()
{
	int numero = lista.size();

	for (int i = 0; i < numero; i++)
	{
		EliminarEntidad(i);
	}

	numero = 0;
}