#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "Game.h"
#include <SDL.H>
#include <SDL_image.h>

CGame::CGame(){
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	//delete(Nave);
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{

		printf("Error %s ", SDL_GetError());

		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	if (screen == NULL)
	{

		printf("Error %s ", SDL_GetError());

		exit(EXIT_FAILURE);

	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);
	atexit(SDL_Quit);

	nave = new Nave(screen,"../Data/Minave.bmp");

}

bool CGame::Start()
{

	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
		
		//Maquina de estados
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			Iniciando();
			{
				///nave = IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
			//	SDL_Rect fuente;
				//fuente.x = 582;
				//fuente.y = 383;
				//fuente.w = 321;
				//fuente.h = 16;
				//SDL_Rect destino;
				//destino.x = 100;
				//destino.y = 100;
				//destino.w = 100;
				//destino.h = fuente.h;
				///SDL_BlitSurface(nave, &fuente, screen, &destino);	
			}

			estado=Estado::ESTADO_MENU;
			
		
			break;
		case Estado::ESTADO_MENU: //MENÚ
		//	nave->PintarModulo(0,0,0,64,64);
			//nave->PintarModulo(0,100,100);
			SDL_FillRect( screen,NULL, SDL_MapRGB(screen->format,0,0,0));
			keys = SDL_GetKeyState(nullptr);
			if (keys[SDLK_RIGHT]){
				nave->mover(1);
			}
			nave->pintar();

			break;
		case Estado::ESTADO_JUGANDO:	//JUGAR	
			break;
		case Estado::ESTADO_FINALIZANDO: //FINALIZAR
			break;
		case Estado::ESTADO_TERMINANDO: //SALIR
				salirJuego = true;
			break;
		};
		while (SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT) {salirJuego=true;}
			if(event.type==SDL_KEYDOWN){  }
		}

		SDL_Flip(screen);
    }
	return true;
}

