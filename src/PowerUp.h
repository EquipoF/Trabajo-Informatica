#pragma once

#include "Rectangulo.h"
#include "glut.h"

class PowerUp :	public Rectangulo
{
public:
	PowerUp();
	PowerUp(Rectangulo rectanguloIn);
	virtual ~PowerUp();

	void Dibuja();

};

