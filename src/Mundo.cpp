#include "Mundo.h"
#include "Interaccion.h"

#include <stdlib.h> 
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Archivo.h"

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
	sierras.Dibuja();
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
	Archivo archivo;
	Nodo* cabecera = NULL;

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

	//Movimiento de las sierras
	for (int sier = 0; sier < sierras.GetNum(); sier++) {
		sierras.lista[sier]->Mueve(DIFF_TIEMPO);
	}

	//Movimiento de las plataformas
	for (int plat = 0; plat < plataformas.GetNum(); plat++ ) {
		plataformas.lista[plat]->Mueve(DIFF_TIEMPO);
	}

	//Movimiento de los pinchos
	for (int pin = 0; pin < pinchos.GetNum(); pin++) {
		pinchos.lista[pin]->Mueve(DIFF_TIEMPO);
	}

	//Interacción powerUps & personaje
	int powerUpChocado = Interaccion::Choque(powerUps, personaje);
	if (powerUpChocado != -1) //Si choca con algún bonus
	{
		powerUps.EliminarRectangulo(powerUpChocado);
		personaje.SetPowerUpDisponible(1);
	}

	//Comprobaciones de muete del personaje
	Vector2D perpos = personaje.GetPos();
	if (perpos.y < y_ojo-9.0f)// muerte si la camara pasa al personaje
	{
		//muerte = true;			//<-----------------------------------------Comentar esta línea para pruebas viendo todo el mapa
	}

	for (int sier = 0; sier < sierras.GetNum(); sier++) {
		if (Interaccion::Choque(*sierras.lista[sier], personaje) == true)
		{
			muerte = true;
		}
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
	

	if (final == true || muerte == true) //quitar variable de muerte, no tiene sentido, para pruebas ok
	{
		archivo.cargarLista(cabecera);
		archivo.insertarElemento(cabecera, tiempo); //En la segunda posicion meter la variable de puntuacion
		archivo.guardarLista(cabecera); 
	}

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
	finalnivel.SetPos(6.0f, 41.4f);
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
	sierras.DestruirContenido();
	
	//Caja
	{
		for (int lado = 0; lado < caja.ladosCaja.GetNum(); lado++) {
			plataformas.Agregar(caja.ladosCaja.lista[lado]);
		}
	}

	if (nivel == 1)
	{
		//Sierras
		{
			Sierra* sierra1 = new Sierra(true, 4, 1, 8, -8, 1, 1, -2, 0);
			sierras.Agregar(sierra1);

			Sierra* sierra2 = new Sierra(true, -6, 10, -6, -6, 14, 6, 0, -2);
			sierras.Agregar(sierra2);

			Sierra* sierra3 = new Sierra(true, -4, 30, 8, -8, 1, 1, -2, 0);
			sierras.Agregar(sierra3);
		}

		muerte = false;
		SetOjo();

		personaje.Inicializa();

		//Plataformas
		{
			//Hacer un rectángulo movil
			Rectangulo* recM1 = new Rectangulo(3.0f, 0.7f, Vector2D(1.0f, -4.0f), true, 10, -10, -4, -4, -2, 0); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
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

			//Plataforma 100% normales
			Rectangulo* rec5 = new Rectangulo(1.0f, 1.0f, Vector2D(0.0f, 2.5f));
			plataformas.Agregar(rec5);

			//COnvertir una plataforma en power up
			Rectangulo rec6 = Rectangulo(1.0f, 1.0f, Vector2D(-3.0f, 2.5f));
			PowerUp* recP6 = new PowerUp(rec6);
			powerUps.Agregar(recP6);

			//Plataformas surtidas
			Rectangulo* rec7 = new Rectangulo(3.0f, 0.7f, Vector2D(-7.0f, 4.0f));
			plataformas.Agregar(rec7);
			Pinchos* recP7 = new Pinchos(*rec7, true, 1, 0.0f);
			pinchos.Agregar(recP7);

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
		
		//sierras
		Sierra* sierra1 = new Sierra(true, -6, 20.5, 10, -10, 1, 1, 2, 0);
		sierras.Agregar(sierra1);

		Sierra* sierra2 = new Sierra(true, 4, 10, -6, -6, 14, 6, 0, -2);
		sierras.Agregar(sierra2);

		//power ups
		Rectangulo rec6 = Rectangulo(1.0f, 1.0f, Vector2D(-3.0f, 15.5f));
		PowerUp* recP6 = new PowerUp(rec6);
		powerUps.Agregar(recP6);

		Rectangulo rec7 = Rectangulo(1.0f, 1.0f, Vector2D(1.0f, 3.0f));
		PowerUp* recP7 = new PowerUp(rec7);
		powerUps.Agregar(recP7);

		//Plataformas
		RandPlatforms();
		Rectangulo* rec33 = new Rectangulo(15.0f, 0.7f, Vector2D(4.0f, 40.5f));
		plataformas.Agregar(rec33);
	}
	if (nivel == 3)
	{
		SetOjo();

		personaje.Inicializa();

		//sierras
		Sierra* sierra1 = new Sierra(true, 6, 10, 10, -10, 1, 1, 2, 0);
		sierras.Agregar(sierra1);

		Sierra* sierra2 = new Sierra(true, 4, 20.5, -6, -6, 29, 15, 0, -2);
		sierras.Agregar(sierra2);

		Sierra* sierra3 = new Sierra(true, 6, 33, 10, -10, 1, 1, 2, 0);
		sierras.Agregar(sierra3);

		//power ups
		Rectangulo rec6 = Rectangulo(1.0f, 1.0f, Vector2D(-3.0f, 8.5f));
		PowerUp* recP6 = new PowerUp(rec6);
		powerUps.Agregar(recP6);

		Rectangulo rec7 = Rectangulo(1.0f, 1.0f, Vector2D(3.0f, 4.0f));
		PowerUp* recP7 = new PowerUp(rec7);
		powerUps.Agregar(recP7);

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
			if (tipo <= 10)// Plataforma movil
			{
				//RectanguloMovil* recM1 = new RectanguloMovil(*rec, 10, -10, /*rec->GetCentro().y*/8, /*rec->GetCentro().y*/-8, 2.0f, 0.0f); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				//plataformas.Agregar(recM1);
				//Hacer un rectángulo movil
				Rectangulo* recM = new Rectangulo(ancho, 0.7f, Vector2D(lateral, altura), true, 10, -10, -4, -4, -2, 0); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				plataformas.Agregar(recM);
			}
			if (tipo <= 20 && tipo > 10)// Pinchos
			{
				plataformas.Agregar(rec);
				Pinchos* recP = new Pinchos(*rec, true, 1, 0.0f); //rectángulo r4 y entran y salen, no es estático. //1-> arriba, 2->abajo, 3-> dcha, 4-> izq.
				pinchos.Agregar(recP);
			}
			else if (tipo > 20)// Plataforma normal
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
			if (tipo <= 10)// Plataforma movil
			{
				//RectanguloMovil* recM1 = new RectanguloMovil(*rec, 10, -10, /*rec->GetCentro().y*/8, /*rec->GetCentro().y*/-8, 2.0f, 0.0f); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				//plataformas.Agregar(recM1);
				Rectangulo* recM = new Rectangulo(ancho, 0.7f, Vector2D(lateral, altura), true, 10, -10, -4, -4, -2, 0); //Si no se mueve en una dirección, poner como límites su coordenada en esa dimensión
				plataformas.Agregar(recM);
			}
			else if(tipo >= 20)// Plataforma normal
			{
				plataformas.Agregar(rec);
			}
		}		
	}
}