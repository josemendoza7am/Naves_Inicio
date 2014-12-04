#include "nave.h"
#include "config.h"


Nave::Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module){
	nave= new Objeto(screen,rutaImagen,x,y,module);
	for (int i=0; i<MAXIMO_DE_BALAS;i++){
		bala[i] =new Objeto (screen, "../data/balas.bmp",0,0, MODULO_BALAS_BALA);
		bala[i]-> SetVisible(false);
	}
	balaVisibles=0;
}

void Nave:: Pintar (int tipoNave){
	nave ->Pintar();
	for (int i = 0; i < MAXIMO_DE_BALAS; i++)
	{
		bala[i]->Pintar();
		switch (tipoNave)
		{
		case NAVE_PROPIA:
			bala[i]->MoverY(-10);
			break;

		case NAVE_ENEMIGO:
			bala[i]->MoverY(10);
			break;
		}
		
	}
	
}

void Nave::Disparar(int tipoNave, int Balas){
	
	bala[balaVisibles]->SetVisible(true);
	switch (tipoNave)
	{
	case NAVE_PROPIA:
		bala[balaVisibles]->PonerEn (nave->ObtenerX()+nave->ObtenerW()/2,nave->ObtenerY());
		break;
	case NAVE_ENEMIGO:
		bala[balaVisibles]->PonerEn (nave->ObtenerX()+nave->ObtenerW()/2,nave->ObtenerY()+nave->ObtenerH());
		break;
	}
	
	balaVisibles++;
	if (balaVisibles>= Balas)
	{
		balaVisibles=0;

	}

	
	
}

void Nave:: MoverAbajo(int velocidad){nave->MoverY(velocidad);}
void Nave:: MoverArriba(int velocidad){nave->MoverY(-velocidad);}
void Nave:: MoverDerecha(int velocidad){nave->MoverX(velocidad);}
void Nave::MoverIzquierda(int velocidad){nave->MoverX(-velocidad);}



Objeto*Nave::GetNaveObjeto(){
	return nave;
}

void Nave::AutoDispara(int Balas){
	if ((rand() % 100)<1)
		Disparar(NAVE_ENEMIGO,Balas);
}