
#include "sprite.h"
#include <SDL.h>

Sprite::Sprite(SDL_Surface * screen){
	
	this ->screen=screen;

}

Sprite ::~Sprite(){
	SDL_FreeSurface(imagen);
}

void Sprite::CargaImagen(char * nombre){
	imagen=SDL_LoadBMP(nombre);


/*
}

void Sprite :: PintarModulo(int nombre, int  x, int y, int w, int h)
{
	SDL_Rect src;
src.x=x;
src.y=y;
src.w=w;
src.h=h;

SDL_BlitSurface(imagen, &src,screen, NULL);
}*/
}
void Sprite :: PintarModulo(int nombre, int  x, int y)
{
	SDL_Rect src;
	src.x=spriteDef.modulos[nombre].x;
	src.y=spriteDef.modulos[nombre].y;
	src.w=spriteDef.modulos[nombre].w;
	src.h=spriteDef.modulos[nombre].h;
	SDL_Rect dest;
	dest.x=x;
	dest.y=y;
	SDL_BlitSurface(imagen, &src,screen,&dest);
}
int Sprite::widthModule(int module){

	return spriteDef.modulos[module].w;
}
int Sprite::Heightmodule(int module){
	return spriteDef.modulos[module].h;
}