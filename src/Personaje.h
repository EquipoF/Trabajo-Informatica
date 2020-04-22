#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

#define ALTO 2.0
#define ANCHO 1.0

class Personaje : public ObjetoMovil
{
public:
	friend class Mundo;
	friend class Interaccion;
	Personaje();
	virtual ~Personaje();
	void Dibuja();
	void mueve(float t);

private:
	Rectangulo cuerpo;
};

