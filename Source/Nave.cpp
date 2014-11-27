#include "nave.h"
#include "config.h"


Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	nave= new Objeto(screen,rutaImagen,x,y,module);
	bala =new Objeto (screen, "../data/balas.bmp",0,0, MODULO_BALAS_BALA);
	bala-> SetVisible(false);
}

void Nave:: Pintar (){
	nave ->Pintar();
	bala->Pintar();
	bala->MoverY(-10);
}

void Nave::Disparar(){
	bala->SetVisible(true);
	bala->PonerEn (nave->ObtenerX()+nave->ObtenerW()/2,nave->ObtenerY());
	
}

void Nave:: MoverAbajo(){nave->MoverY(10);}
void Nave:: MoverArriba(){nave->MoverY(-10);}
void Nave:: MoverDerecha(){nave->MoverX(10);}
void Nave::MoverIzquierda(){nave->MoverX(-10);}

Objeto*Nave::GetNaveObjeto(){
	return nave;
}