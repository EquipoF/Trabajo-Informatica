#include "Mundo.h"
#include "Interaccion.h"
#include <stdlib.h> 
#include "ETSIDI.h"
#include "glut.h"

#include <iostream>
using namespace std;

#define DIFF_TIEMPO 0.015 //tiempo en segundos que transcurre cada instante del juego. Diferencial de tiempo

void Mundo::Dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	
	//aqui es donde hay que poner el codigo de dibujo
	caja.Dibuja();
	personaje.Dibuja();

	plataformas.Dibuja();
	pinchos.Dibuja();
	powerUps.Dibuja();

	sierra.Dibuja();
	sierra2.Dibuja();
	finalnivel.Dibuja();

	//dibujo del fondo
	/*glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/montañas.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1);		glVertex2f(-15, -7);
	glTexCoord2d(1, 1);		glVertex2f(15, -7);
	glTexCoord2d(1, 0);		glVertex2f(15, 43);
	glTexCoord2d(0, 0);		glVertex2f(-15, 43);
	glEnd();

	

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	*/
}

void Mundo::SetOjo()
{
	x_ojo = 0.0f;
	y_ojo = 20.0f;	//0 para real, 20 para pruebas. Para probar comentar la muerte del personaje debido a la camara
	z_ojo = 80.0f; //20 para real, 80 para pruebas
}

float Mundo::GetOjo()
{
	return 0.0f;
}

void Mundo::Mueve()
{
	//Avance de la cámara
	if (y_ojo < 36)
	{
		SetVelMundo(0.0);//Aqui se cambia la velocidad de subida del mundo
	}
	else if (y_ojo >= 36)
	{
		SetVelMundo(0); 
	}
	
	//Movimiento del personaje
	personaje.Mueve(DIFF_TIEMPO, plataformas);

	//Movimiento de las trampas
	sierra.Mueve(0.025);
	sierra2.Mueve(0.025);

	//Movimiento de las plataformas
	for (int plat = 0; plat < plataformas.GetNum(); plat++ ) {
		if (plataformas.lista[plat]->GetMovil() == true) 
		{
			plataformas.lista[plat]->Mueve(DIFF_TIEMPO);
		}
	}

	//Movimiento de los pinchos
	for (int pin = 0; pin < pinchos.GetNum(); pin++) {
		if (pinchos.lista[pin]->GetMovil() == true)
		{
			pinchos.lista[pin]->Mueve(DIFF_TIEMPO);
		}
	}

	//Interacción powerUps & personaje
	int powerUpChocado = Interaccion::Choque(powerUps, personaje);
	if (powerUpChocado != -1) //Si choca con algún bonus
	{
		powerUps.EliminarRectangulo(powerUpChocado);
		personaje.SetPowerUpDisponible(1);
	}


	//Comprobaciones de interacciones entre objetos contenidos en el mundo para cambiar ele satdo del mundo
	Vector2D perpos = personaje.GetPos();
	if (perpos.y < y_ojo-9.0f)// muerte si la camara pasa al personaje
	{
		//muerte = true;			//<-----------------------------------------Comentar esta línea para pruebas viendo todo el mapa
	}

	if (Interaccion::Choque(sierra, personaje)) //Hacer listas de sierras
	{
		muerte = true;
	}
	if (Interaccion::Choque(sierra2, personaje))
	{
		muerte = true;
	}
	int pinchoChocado = Interaccion::Choque(pinchos, personaje);
	if (pinchoChocado != -1)
	{
		if(pinchos.lista[pinchoChocado]->GetAtravesar() == false)
		muerte = true;
	}



	if (Interaccion::Choque(finalnivel, personaje) && nivel <= 2)// de momento cambia de nivel al llegar a una altura
	{
		nivel++;
		CargarNivel();
	}
	if (Interaccion::Choque(finalnivel, personaje) && nivel == 3)
	{
		final = true;
	}


	tiempo++;
	cout << tiempo << endl;
}

void Mundo::Inicializa()
{
	/*x_ojo = 0.0f;
	y_ojo = 20.0f;	//0 para real, 20 para pruebas. Para probar comentar la muerte del personaje debido a la camara
	z_ojo = 80.0f; //20 para real, 80 para pruebas*/

	nivel = 1;

	/*personaje.Inicializa();
	sierra.SetPos(4.0f, 1.0f);
	sierra2.SetPos(-6.0f, 10.0f);*/
	finalnivel.SetPos(6.0f, -2.0f);
	muerte = false;
	final = false;

	tiempo = 0.0f;

	CargarNivel();

	//Plataformas	
}

void Mundo::Tecla(unsigned char key)
{
	personaje.Tecla(key);
}

void Mundo::SetVelMundo(float velocidad)
{
	y_ojo = y_ojo + velocidad;
}

bool Mundo::GetMuerte()
{
	return muerte;
}

bool Mundo::GetFinal()
{
	return final;
}

void Mundo::CargarNivel()
{
	plataformas.DestruirContenido();
	pinchos.DestruirContenido();
	powerUps.DestruirContenido();
	
	//Caja
	{
		for (int lado = 0; lado < caja.ladosCaja.GetNum(); lado++) {
			plataformas.Agregar(caja.ladosCaja.lista[lado]);
		}
	}

	if (nivel == 1)
	{
		SetOjo();

		personaje.Inicializa();
		sierra.SetPos(4.0f, 1.0f);
		sierra2.SetPos(-6.0f, 10.0f);	

	//Plataformas
	{
		//Primer rectángulo
		Rectangulo rec1 = Rectangulo(3.0f, 0.7f, Vector2D(1.0f, -4.0f));
		//Lo hago móvil
		RectanguloMovil* recM1 = new RectanguloMovil(rec1, 10, -10, rec1.GetCentro().y, rec1.GetCentro().y, 2.0, 0); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
		plataformas.Agregar(recM1);

		//Plataformas 100% normales
		Rectangulo* rec2 = new Rectangulo(3.0f, 0.7f, Vector2D(4.0f, -1.0f));
		plataformas.Agregar(rec2);
		Rectangulo* rec3 = new Rectangulo(3.0f, 0.7f, Vector2D(7.0f, 2.0f));
		plataformas.Agregar(rec3);

		//Poner pinchos en una platafomra
		Rectangulo* rec4 = new Rectangulo(1.0f, 1.0f, Vector2D(3.0f, 2.5f));
		plataformas.Agregar(rec4);
		Pinchos* recP4 = new Pinchos(*rec4, true, 1, 0.0f); //rectángulo r4 y entran y salen, no es estático. //1-> arriba, 2->abajo, 3-> dcha, 4-> izq.
		pinchos.Agregar(recP4);

		//Plataforma 100% normale
		Rectangulo* rec5 = new Rectangulo(1.0f, 1.0f, Vector2D(0.0f, 2.5f));
		plataformas.Agregar(rec5);

		//COnvertir una plataforma en power up
		Rectangulo rec6 = Rectangulo(1.0f, 1.0f, Vector2D(-3.0f, 2.5f));
		PowerUp* recP6 = new PowerUp(rec6);
		powerUps.Agregar(recP6);

		//Plataformas 100% normales
		Rectangulo* rec7 = new Rectangulo(3.0f, 0.7f, Vector2D(-7.0f, 4.0f));
		plataformas.Agregar(rec7);
		Rectangulo* rec8 = new Rectangulo(3.0f, 0.7f, Vector2D(-8.5f, 6.0f));
		plataformas.Agregar(rec8);
		Rectangulo* rec9 = new Rectangulo(3.0f, 0.7f, Vector2D(-10.0f, 8.0f));
		plataformas.Agregar(rec9);
		Rectangulo* rec10 = new Rectangulo(3.0f, 0.7f, Vector2D(-5.0f, 9.0f));
		plataformas.Agregar(rec10);
		Rectangulo* rec11 = new Rectangulo(3.0f, 0.7f, Vector2D(1.0f, 9.0f));
		plataformas.Agregar(rec11);
		Rectangulo* rec12 = new Rectangulo(1.5f, 0.7f, Vector2D(4.0f, 11.0f));
		plataformas.Agregar(rec12);
		Rectangulo* rec13 = new Rectangulo(1.5f, 0.7f, Vector2D(6.0f, 13.0f));
		plataformas.Agregar(rec13);
		Rectangulo* rec14 = new Rectangulo(1.5f, 0.7f, Vector2D(4.0f, 15.0f));
		plataformas.Agregar(rec14);
		Rectangulo* rec15 = new Rectangulo(7.0f, 0.7f, Vector2D(-3.0f, 13.0f));
		plataformas.Agregar(rec15);
		Rectangulo* rec16 = new Rectangulo(3.0f, 0.7f, Vector2D(-7.0f, 15.0f));
		plataformas.Agregar(rec16);
		Rectangulo* rec17 = new Rectangulo(3.0f, 0.7f, Vector2D(-8.5f, 17.0f));
		plataformas.Agregar(rec17);
		Rectangulo* rec18 = new Rectangulo(3.0f, 0.7f, Vector2D(-10.0f, 19.0f));
		plataformas.Agregar(rec18);
		Rectangulo* rec19 = new Rectangulo(1.0f, 1.0f, Vector2D(-6.0f, 20.0f));
		plataformas.Agregar(rec19);
		Rectangulo* rec20 = new Rectangulo(1.0f, 1.0f, Vector2D(-4.0f, 22.0f));
		plataformas.Agregar(rec20);
		Rectangulo* rec21 = new Rectangulo(1.0f, 1.0f, Vector2D(-2.0f, 24.0f));
		plataformas.Agregar(rec21);
		Rectangulo* rec22 = new Rectangulo(1.5f, 0.7f, Vector2D(1.0f, 24.0f));
		plataformas.Agregar(rec22);
		Rectangulo* rec23 = new Rectangulo(2.0f, 0.7f, Vector2D(-2.0f, 27.0f));
		plataformas.Agregar(rec23);
		Rectangulo* rec24 = new Rectangulo(2.0f, 0.7f, Vector2D(2.0f, 29.0f));
		plataformas.Agregar(rec24);
		Rectangulo* rec25 = new Rectangulo(2.0f, 0.7f, Vector2D(-1.0f, 31.0f));
		plataformas.Agregar(rec25);
		Rectangulo* rec26 = new Rectangulo(1.0f, 1.0f, Vector2D(2.0f, 32.5f));
		plataformas.Agregar(rec26);
		Rectangulo* rec27 = new Rectangulo(1.0f, 1.0f, Vector2D(0.0f, 34.5f));
		plataformas.Agregar(rec27);
		Rectangulo* rec28 = new Rectangulo(1.0f, 1.0f, Vector2D(4.0f, 34.5f));
		plataformas.Agregar(rec28);
		Rectangulo* rec29 = new Rectangulo(1.0f, 1.0f, Vector2D(2.0f, 36.5f));
		plataformas.Agregar(rec29);
		Rectangulo* rec30 = new Rectangulo(1.0f, 1.0f, Vector2D(-1.0f, 37.5f));
		plataformas.Agregar(rec30);
		Rectangulo* rec31 = new Rectangulo(1.0f, 1.0f, Vector2D(-3.0f, 37.5f));
		plataformas.Agregar(rec31);
		Rectangulo* rec32 = new Rectangulo(2.0f, 0.7f, Vector2D(-6.0f, 38.5f));
		plataformas.Agregar(rec32);
		Rectangulo* rec33 = new Rectangulo(15.0f, 0.7f, Vector2D(4.0f, 40.5f));
		plataformas.Agregar(rec33);
		}
	}

	if (nivel == 2)
	{
		SetOjo();

		personaje.Inicializa();
		sierra.SetPos(4.0f, 14.0f);
		sierra2.SetPos(-6.0f, 25.0f);

		//Plataformas
		RandPlatforms();
		Rectangulo* rec33 = new Rectangulo(15.0f, 0.7f, Vector2D(4.0f, 40.5f));
		plataformas.Agregar(rec33);
	}
	if (nivel == 3)
	{
		SetOjo();

		personaje.Inicializa();

		//Plataformas
		RandPlatforms();
		Rectangulo* rec33 = new Rectangulo(15.0f, 0.7f, Vector2D(4.0f, 40.5f));
		plataformas.Agregar(rec33);
	}
}

void Mundo::RandPlatforms()//Crea plataformas de manera aleatoria
{
	int altura, lateral, ancho, tipo;
	
	for (altura = -4; altura <= 38; altura = altura ++)
	{
		tipo = rand() % 100;
		//izquierda
		if (altura % 2 == 0)
		{
			lateral = (rand() % 10) - 10;
			ancho = rand() % 4 + 1;
			Rectangulo* rec = new Rectangulo(ancho, 0.7f, Vector2D(lateral, altura));
			if (tipo <= 10)
			{
				RectanguloMovil* recM1 = new RectanguloMovil(*rec, 10, -10, /*rec->GetCentro().y*/8, /*rec->GetCentro().y*/-8, 2.0f, 0.0f); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				plataformas.Agregar(recM1);
			}
			else
			{
				plataformas.Agregar(rec);
			}
		}
		//derecha
		else
		{
			lateral = rand() % 10;
			ancho = rand() % 4 + 1;
			Rectangulo* rec = new Rectangulo(3.0f, 0.7f, Vector2D(lateral, altura));
			if (tipo <= 10)
			{
				RectanguloMovil* recM1 = new RectanguloMovil(*rec, 10, -10, /*rec->GetCentro().y*/8, /*rec->GetCentro().y*/-8, 2.0f, 0.0f); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				plataformas.Agregar(recM1);
			}
			else
			{
				plataformas.Agregar(rec);
			}
		}		
	}
}