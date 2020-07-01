#include "Archivo.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Archivo::Archivo()
{

}

Archivo::~Archivo()
{

}

void Archivo::insertarElemento(Nodo*& cabecera, int puntuacion) //MENOR A MAYOR (CAMBIAR ***) 
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->puntuacion = puntuacion;

    fflush(stdin);
    cout << "Introduzca su nombre: ";
    cin >> nuevo_nodo->nombre;


    Nodo* aux1 = cabecera;
    Nodo* aux2 = 0;


    while ((aux1 != NULL) && (aux1->puntuacion < puntuacion)) //***
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (cabecera == aux1)
    {
        cabecera = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

}

void Archivo::mostrarElemento(Nodo* cabecera)
{
    Nodo* actual = new Nodo();
    actual = cabecera;

    while (actual != NULL)
    {
        cout << actual->nombre << " ";
        cout << actual->puntuacion << "\n";

        actual = actual->siguiente;
    }
}

void Archivo::guardarLista(Nodo* cabecera)
{
    Nodo* actual = new Nodo();
    actual = cabecera;

    ofstream datos;

    datos.open("Datos.txt", ios::out);

    if (datos.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    while (actual != NULL)
    {
        datos << actual->nombre << " " << actual->puntuacion << "\n";

        actual = actual->siguiente;
    }
}

void Archivo::cargarLista(Nodo*& cabecera) //MENOR A MAYOR
{
    ifstream datos;
    int puntuacion;
    string nombre, line;

    datos.open("Datos.txt", ios::in);

    if (datos.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }


    while (datos >> nombre >> puntuacion)
    {
        Nodo* nuevo_nodo = new Nodo();
        nuevo_nodo->puntuacion = puntuacion;
        nuevo_nodo->nombre = nombre;


        Nodo* aux1 = cabecera;
        Nodo* aux2 = 0;


        while ((aux1 != NULL) && (aux1->puntuacion < puntuacion)) //***
        {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if (cabecera == aux1)
        {
            cabecera = nuevo_nodo;
        }
        else
        {
            aux2->siguiente = nuevo_nodo;
        }

        nuevo_nodo->siguiente = aux1;
    }

    datos.close();
}