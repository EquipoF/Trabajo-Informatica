#pragma once
#include "ObjetoMovil.h"
#include "Rectangulo.h"

class RectanguloMovil : public Rectangulo
{
public:
	RectanguloMovil(Rectangulo rectanguloIn, float limDchaIn, float limIzqIn, float limArribaIn, float limAbajoIn, float velxIn, float velYIn); //Constructor con los l�mites; cambiar orden (rec, vel, xlim, ylim)
	virtual ~RectanguloMovil();

	void Mueve(float t);
};

