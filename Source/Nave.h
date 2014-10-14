#ifndef _NAVE_H_
#define  _NAVE_H_
#include "sprite.h"
#include <SDL.h>

class Nave{
	Sprite * sprite;
	int x;
	int y;

public:
	void mover (int posicion);
	Nave(SDL_Surface*screen, char*rutaImagen);//constructor
	void pintar();


};



#endif