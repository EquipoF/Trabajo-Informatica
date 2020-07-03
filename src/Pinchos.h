#pragma once
#include "Rectangulo.h"
#include "ETSIDI.h"

using ETSIDI::Sprite;

class Pinchos: public Rectangulo
{
public:
	Pinchos();
	Pinchos(Rectangulo rectanguloIn,bool movilIn=false,unsigned int lado=0, float tiniIn=0);
	virtual ~Pinchos();

	void Mueve(float t);
	void Dibuja();

	int GetEstado();

private:
	int estado; //guardados, saliendo, fuera
	float tini; //tiempo inicial para que no vayan todos los pinchos a la vez

	void Salir(float t); //Devuelve si están metidos, saliendo o fuera del suelo
	Sprite sprite;
};

