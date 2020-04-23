#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
public:
	ObjetoMovil();
	~ObjetoMovil();

	virtual void Mueve(float t);

	void SetPos(float Inx, float yIn);	void SetPos(Vector2D posIn);
	void SetVel(float vxIn, float vyIn);	void SetVel(Vector2D velIn);
	void SetAcc(float axIn, float ayIn);	void SetAcc(Vector2D accIn);

	Vector2D GetPos();
	Vector2D GetPosAnt();
	Vector2D GetVel();
	Vector2D GetAcc();

protected:
	Vector2D posicion;
	Vector2D posicionAnterior;
	Vector2D velocidad;
	Vector2D aceleracion;
};

