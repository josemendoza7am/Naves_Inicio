#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <SDL.h>
#include "SpriteDef.h"


class Sprite{
	SDL_Surface*imagen;
	SDL_Surface * screen;
	SpriteDef spriteDef;

public:
	Sprite(SDL_Surface * screen);
	~Sprite();
	void CargaImagen(char * nombre);
	void PintarModulo(int nombre,int x,int y,int w, int h);
	void PintarModulo(int nombre,int x,int y);
	int widthModule(int module);
	int Heightmodule(int module);
};


#endif

