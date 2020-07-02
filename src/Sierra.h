#pragma once
#include "Entidad.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Sierra : public Entidad
{
public:
	Sierra();
	Sierra(bool movilIn, float posXIn,float posYIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn, float velXIn, float velYIn);
	virtual ~Sierra();

	virtual void Dibuja();

private:
	friend class Interaccion;

	SpriteSequence sprite;
};


