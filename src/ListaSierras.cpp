#include "ListaSierras.h"

ListaSierras::ListaSierras()
{

}

ListaSierras::~ListaSierras()
{

}

bool ListaSierras::Agregar(Sierra* rec)
{
	lista.push_back(rec);
	return true;
}

void ListaSierras::Dibuja()
{
	for (int i = 0; i < lista.size(); i++)
	{
		lista[i]->Dibuja();
	}
}

void ListaSierras::EliminarSierra(int ind)
{
	if ((ind < 0) || (ind >= lista.size()))
		return;

	delete lista[ind];
	lista.erase(lista.begin() + ind);
}

int ListaSierras::GetNum(void) {
	return lista.size();
}

void ListaSierras::DestruirContenido()
{
	lista.clear();
}