#ifndef _MODULESCENE_H_
#define _MODULESCENE_H_

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status Update();
	SDL_Texture* graphics = nullptr;
};

#endif // !_MODULESCENE_H_


