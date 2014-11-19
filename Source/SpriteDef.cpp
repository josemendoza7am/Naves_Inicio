#include "SpriteDef.h"
#include "config.h"

SpriteDef::SpriteDef()
{
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_MENU_FONDO_MENU;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;

	modulos[2].id = MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTOS_TITULO;
	modulos[3].x = 3;
	modulos[3].y = 3;
	modulos[3].w = 236;
	modulos[3].h = 96;

	modulos[4].id = MODULO_TEXOS_NOMBRE;
	modulos[4].x = 3;
	modulos[4].y = 198;
	modulos[4].w = 257;
	modulos[4].h = 61;

	modulos[5].id = MODULO_TEXTOS_MENU_OPCION1;
	modulos[5].x = 309;
	modulos[5].y = 27;
	modulos[5].w = 153;
	modulos[5].h = 40;

	modulos[6].id = MODULO_TEXTOS_MENU_OPCION2;
	modulos[6].x = 309;
	modulos[6].y = 70;
	modulos[6].w = 135;
	modulos[6].h = 33;

	modulos[7].id = MODULO_TEXTOS_MENU_OPCION1_SELECCIONADO;
	modulos[7].x = 309;
	modulos[7].y = 210;
	modulos[7].w = 146;
	modulos[7].h = 40;

	modulos[8].id = MODULO_TEXTOS_MENU_OPCION2_SELECCIONADO;
	modulos[8].x = 309;
	modulos[8].y = 263;
	modulos[8].w = 136;
	modulos[8].h = 32;

}