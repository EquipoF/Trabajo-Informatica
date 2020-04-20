#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

#define ALTO 2.0f
#define ANCHO 1.0f

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

