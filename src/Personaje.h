#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

#define ALTO 2.0
#define ANCHO 1.0
#define GRAVEDAD -2.0

class Personaje : public ObjetoMovil
{
public:
	Personaje();
	virtual ~Personaje();
	void Dibuja();
	void mueve(float t);

private:
	Rectangulo cuerpo;
	int saltosRestantes;
};

