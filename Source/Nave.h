#ifndef _NAVE_H_
#define _NAVE_H_
#include "Objeto.h"
#include "config.h"



class Nave {
	Objeto * nave;
	Objeto * bala[MAXIMO_DE_BALAS];
	int balaVisibles;

public: 

	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	 void Pintar (int tipoNave);
	 void Disparar(int tipoNave,int Balas);
	 void AutoDispara(int Balas);

	 void  MoverIzquierda(int velocidad);
	 void MoverDerecha(int velocidad);
	 void MoverArriba(int velocidad);
	 void MoverAbajo(int velocidad);

	 Objeto * GetNaveObjeto();

};

#endif