#ifndef _NAVE_H_
#define _NAVE_H_
#include "Objeto.h"



class Nave {
	Objeto * nave;
	Objeto * bala;
	

public: 

	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	 void Pintar ();
	 void Disparar();
	 void  MoverIzquierda();
	 void MoverDerecha();
	 void MoverArriba();
	 void MoverAbajo();
	 Objeto * GetNaveObjeto();

};

#endif