#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

class Personaje : public ObjetoMovil
{
public:
	Personaje();
	virtual ~Personaje();
	void Dibuja();
private:
	Rectangulo cuerpo;
};

