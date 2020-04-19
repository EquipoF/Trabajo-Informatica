#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();

	virtual void mueve(float t);

	void setPos(float ix, float iy);	void setPos(Vector2D pos);
	void setVel(float vx, float vy);	void setVel(Vector2D vel);
	void setAcc(float ax, float ay);	void setAcc(Vector2D acc);

	Vector2D getPos();
	Vector2D getVel();
	Vector2D getAcc();

protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	friend class Interaccion;
};

