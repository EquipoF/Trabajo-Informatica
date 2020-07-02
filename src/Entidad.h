#pragma once
#include "ObjetoMovil.h"

/*
Clase para abstraer otras clases como rectángulo, personaje  o sierra.
*/

class Entidad: public ObjetoMovil
{
public:
	Entidad();
	virtual ~Entidad();

	//Métodos virtual por que se sobreescriben en las clases heredadas;
	//ya que esta clase está para sobreescribirla.
	virtual void Dibuja();
	virtual void Mueve(float t);

	//Funciones Get y Set INLINE
	bool GetMovil() { return movil; }
	bool GetAtravesar() { return atravesar; }

protected:
	bool movil; //define si la entidad se mueve o no
	bool atravesar; //define si se atraviesa o no

	//Dado que hay muchas entidades que tienen límites de movimiento, se definen en esta clase abstracta

	//Límites de mvto.
	float limDcha;		 float limIzq;
	float limArriba;	 float limAbajo;
};