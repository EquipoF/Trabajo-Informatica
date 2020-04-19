#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

#define ALTO 14.0
#define ANCHO 10.0

class Personaje : public ObjetoMovil
{
public:
	Personaje();
	virtual ~Personaje();
	void Dibuja();
	void mueve(float t);

private:
	Rectangulo cuerpo;
};

