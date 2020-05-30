#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Sierra : public ObjetoMovil
{
public:
	Sierra();
	virtual ~Sierra();
	void Mueve(float t);
	void Dibuja();

private:
	friend class Interaccion;
	SpriteSequence sprite;
};


