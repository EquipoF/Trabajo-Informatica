#pragma once
#include "Rectangulo.h"

class Caja
{
public:
	Caja();
	virtual ~Caja();
	void Dibuja();

private:
	float alto, ancho;
	Rectangulo suelo, techo, paredI, paredD;
};

