#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Sierra : public ObjetoMovil
{
public:
	Sierra();
	Sierra(bool movilIn, float posXIn,float posYIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn, float velXIn, float velYIn);
	virtual ~Sierra();

	void Mueve(float t);

	void Dibuja();

	bool GetMovil();

private:
	friend class Interaccion;

	//VAriable para definir si la sierra se mueve o es estática
	bool movil;

	//Límites de mvto.
	float limDcha;		 float limIzq;
	float limArriba;	 float limAbajo;

	SpriteSequence sprite;
};


