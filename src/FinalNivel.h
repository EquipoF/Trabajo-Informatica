#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class FinalNivel: public ObjetoMovil
{
public:
	FinalNivel();
	virtual ~FinalNivel();
	void Dibuja();

private:
	friend class Interaccion;
	SpriteSequence sprite;
};
