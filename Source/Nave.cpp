#include "Nave.h"
#include "config.h"

Nave::Nave(SDL_Surface*screen, char* rutaImagen){

sprite=new Sprite (screen);
sprite->CargaImagen(rutaImagen);

x= (WIDTH_SCREEN/2)-(sprite->widthModule(0)/2);
y=(HEIGHT_SCREEN-80)-(sprite->Heightmodule(0));
}
void Nave::pintar(){
	sprite->PintarModulo(0,x,y);
}
void Nave :: mover(int posicion){
	x += posicion;
}