#pragma once
#include "Rectangulo.h"

class Pinchos: public Rectangulo
{
public:
	Pinchos();
	Pinchos(Rectangulo rectanguloIn,bool movilIn=false,unsigned int lado=0, float tiniIn=0);
	virtual ~Pinchos();

	void Mueve(float t);
	void Salir( float t); //Devuelve si están metidos, saliendo o fuera del suelo
	void Dibuja();

	int GetEstado();

private:
	int estado; //guardados, saliendo, fuera
	float tini; //tiempo iinicial para que bno vayan todos los pinchos a la vez
};

