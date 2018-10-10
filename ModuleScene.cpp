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
	//App->renderer->Blit(graphics, 50, 50,);

	return UPDATE_CONTINUE;
}
