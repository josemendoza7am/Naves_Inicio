#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame()
{
	tiempoFrameInicial= 0;
	estado = ESTADO_INICIANDO;
	atexit(SDL_Quit);

}


// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete nave;
	//delete (keys);
	
	delete *enemigoArreglo;
	SDL_FreeSurface(screen);
	SDL_Quit();
}


void CGame::Iniciando()
{
	if (SDL_Init(SDL_INIT_VIDEO)){

		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);
	/*if (screen == NULL)
	{
		screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	}
	if (screen == NULL)
	{
		screen = SDL_SetVideoMode(640, 480, 24, SDL_SWSURFACE);
	}*/
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mi primer Juego", NULL);

	nave = new Nave(screen, "../Data/minave.bmp", (WIDTH_SCREEN / 2) , (HEIGHT_SCREEN - 80),MODULO_MINAVE_NAVE);
	menu = new Objeto (screen,"../Data/fondo menu.bmp ",0,0,MODULO_MENU_FONDO_MENU);
	textos = new Objeto(screen,"../data/MENU  SPACE WAR.bmp",0,0,-1);
	fondo = new Objeto (screen,"../data/fondo juego.bmp " ,0,0,MODULO_MENU_FONDO_MENU);


	for (int i = 0; i < 10; i++)
	{
		enemigoArreglo[i] = new Nave (screen, "../Data/enemigo.bmp", i * 60, 0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->GetNaveObjeto()-> SetAutoMovimiento(false);
		enemigoArreglo[i]-> GetNaveObjeto()->SetPasoLimite(4);
	}

	tick=0;

	opcionSeleccionada =MODULO_TEXTOS_MENU_OPCION1;
	

	//delete nave;
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	int i = 0;
	while (salirJuego == false){

		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			printf("1. ESTADO_INICIANDO");
			Iniciando();
			InicializandoStage();
			estado = ESTADO_MENU; //COMENTADO PARA QUE NOS MANDE AL JUEGO EN LUGAR Q EL MENU
		//	estado = ESTADO_JUGANDO;
			
			break;
		case Estado::ESTADO_MENU: //MENÚ
			menu->Pintar();
			textos-> Pintar(MODULO_TEXTOS_TITULO,100,50);
			textos->Pintar(MODULO_TEXOS_NOMBRE,300,390);
			//textos-> Pintar(MODULO_TEXTOS_MENU_OPCION1,400,100);
			//textos->Pintar(MODULO_TEXTOS_MENU_OPCION2,400,150);

			Menu();

			break;
		case ESTADO_PRE_JUGANDO:
			NivelActual=0;
			estado= ESTADO_JUGANDO;

			break;

		case Estado::ESTADO_JUGANDO:	//JUGAR	
			
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]-> GetNaveObjeto() -> Actualizar();
			}
			MoverEnemigo();
			fondo->Pintar();
			//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_LEFT])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_IZQUIERDO))
					nave->MoverIzquierda(nivel[NivelActual].VelocidadNavePropia);

			}

			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_DERECHO))
					nave->MoverDerecha(nivel[NivelActual].VelocidadNavePropia);

			}//Los 3 casos siguientes son el primero aplicado a las demás direcciones


			//Mover en Y, arriba y abajo (opcional)
			if (keys[SDLK_UP])
			{
			if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_SUPERIOR))
				nave->MoverArriba(nivel[NivelActual].VelocidadNavePropia);
			}

			if (keys[SDLK_DOWN])
			{
			if (!EsLimitePantalla(nave->GetNaveObjeto(), BORDE_INFERIOR))
				nave->MoverAbajo(nivel[NivelActual].VelocidadNavePropia);
			}
			//Aqui termina Y
			if (keys[SDLK_SPACE]){
				nave->Disparar(NAVE_PROPIA, nivel[NivelActual].BalasMaximas);
			}

			nave-> Pintar(NAVE_PROPIA);

			
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Pintar(NAVE_ENEMIGO);
				enemigoArreglo[i]->AutoDispara(nivel[NivelActual].BalasMaximas);
			}

			if (keys[SDLK_SPACE]) //Para evitar que se cicle en un estado, Pulsamos la tecla Abajo (en ese caso) y esa tecla nos dice que estamos en ESTADO_JUGANDO y nos manda a ESTADO_TERMINANDO;
			{
				
			}
			break;

		case Estado::ESTADO_TERMINANDO: //SALIR
			break;

		case Estado::ESTADO_FINALIZANDO: //FINALIZAR
			break;
		}

		while (SDL_PollEvent(&event)) //SDL creará una lista de eventos ocurridos
		{
			if (event.type == SDL_QUIT) { salirJuego = true; }     //Si se detecta una salida de SDL o...
			if (event.type == SDL_KEYDOWN) {} //... una dirección (abajo) del teclado.
		}

		SDL_Flip(screen);

	


		// CALCULANDO FPS
		tiempoFrameFinal=SDL_GetTicks();
		while (tiempoFrameFinal < (tiempoFrameInicial+ FPS_DELAY)){
			tiempoFrameFinal=SDL_GetTicks();
			SDL_Delay(1);
		}

		printf("Frames:%d Tiempo:%d Tiempo promedio:%f tiempo por Frame:%d FPS:%f \n",tick,SDL_GetTicks(), (float)SDL_GetTicks()/(float)tick,tiempoFrameFinal-tiempoFrameInicial, 1000.0f/(float)(tiempoFrameFinal-tiempoFrameInicial));
		tiempoFrameInicial=tiempoFrameFinal;//marcamos el inicio nuevamente
		tick++;

	}

	return true;
}

bool CGame::EsLimitePantalla(Objeto * objeto, int bandera)
{
	if (bandera & BORDE_IZQUIERDO)
		if (objeto->ObtenerX() <= 0)
			return true;
	if (bandera & BORDE_SUPERIOR)
		if (objeto->ObtenerY() <= 0)
			return true;
	if (bandera & BORDE_DERECHO)
		if (objeto->ObtenerX() >= WIDTH_SCREEN - objeto->ObtenerW())
			return true;
	if (bandera & BORDE_INFERIOR)
		if (objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH())
			return true;
	return false;
}

void CGame::MoverEnemigo()
{
	
	for (int i = 0; i < 10; i++)

	{
		//// paso 0
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 0)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))
			{
				enemigoArreglo[i]->GetNaveObjeto()->MoverX(nivel[NivelActual].VelocidadNaveEnemigo);
			}
			else
			{
			enemigoArreglo[i]->GetNaveObjeto()-> IncrementarPasoActual();
			}
			//// paso 1
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 1)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_INFERIOR))
			{	enemigoArreglo[i]->GetNaveObjeto()->MoverY(nivel[NivelActual].VelocidadNaveEnemigo);//ABAJO
		}
			else
			{
		
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}

		//// paso 2
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 2)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_IZQUIERDO))
				enemigoArreglo[i]->GetNaveObjeto()->MoverX(-nivel[NivelActual].VelocidadNaveEnemigo);//IZQUIERDA
			
			else
			{
				
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}
			//// paso 3
		if (enemigoArreglo[i]->GetNaveObjeto()->ObtenerPasoActual() == 3)
			if (!EsLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(), BORDE_SUPERIOR))
				{enemigoArreglo[i]->GetNaveObjeto()->MoverY(-nivel[NivelActual].VelocidadNaveEnemigo);//ABAJO
		}
			else
			{
		
				enemigoArreglo[i]->GetNaveObjeto()->IncrementarPasoActual();
			}
	}

}

bool Objeto::EstaColisionando(Objeto * b)
{
	return false;
}

void CGame::Menu()
	{
		for (int i = MODULO_TEXTOS_MENU_OPCION1, j=0 ; i <= MODULO_TEXTOS_MENU_OPCION2;i++, j++)
	{
				keys = SDL_GetKeyState(NULL);
				if (keys[SDLK_UP])
	{
		opcionSeleccionada = MODULO_TEXTOS_MENU_OPCION1;
	/* if (i == opcionSeleccionada)
	textos->Pintar(i + 2, 312, 250 + (j * 30));
	else
		textos->Pintar(i, 310, 250 + (j * 30));*/
	}

		if (keys[SDLK_DOWN])
	{
		opcionSeleccionada = MODULO_TEXTOS_MENU_OPCION2;
		/*if (i == opcionSeleccionada)
		textos->Pintar(i + 2, 308, 250 + (j * 30));
		else
		textos->Pintar(i, 310, 250 + (j * 30));*/

	}

		/*if (i == opcionSeleccionada)
		textos->Pintar(i + 2, 308, 250 + (j * 30));
		else
		textos->Pintar(i, 310, 250 + (j * 30));*/

		if (i == opcionSeleccionada)
		textos->Pintar(i + 2, 312, 250 + (j * 30));
		else
		textos->Pintar(i, 310, 250 + (j * 30));


		if (keys[SDLK_RETURN])
			{
		if (opcionSeleccionada == MODULO_TEXTOS_MENU_OPCION1)
			{
				estado = Estado::ESTADO_PRE_JUGANDO;
	}

			if (opcionSeleccionada == MODULO_TEXTOS_MENU_OPCION2)
		{
		estado = Estado::ESTADO_FINALIZANDO;
		}
	}// sdlk_return
	}//for
}//void