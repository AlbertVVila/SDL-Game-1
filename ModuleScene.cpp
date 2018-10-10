#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"


ModuleScene::ModuleScene()
{

}


ModuleScene::~ModuleScene()
{
}

bool ModuleScene::Init()
{
	LOG("Creating Scene context");
	bool ret = true;
	graphics = App->textures->Load("sprites.png");
	return ret;
}

update_status ModuleScene::Update()
{
	SDL_Rect background;
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;
	App->renderer->Blit(graphics, 0, 0, &background);

	return UPDATE_CONTINUE;
}
