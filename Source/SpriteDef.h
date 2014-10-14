#ifndef _SPRITEDEF_H_
#define _SPRITEDEF_H_


class SpriteDef{

	struct Modulos
	{
		int id;
		int x;
		int w;
		int h;
		int y;
	};
	public:
	Modulos modulos  [1];
	SpriteDef();
};


#endif