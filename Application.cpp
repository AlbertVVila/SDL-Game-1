#pragma once
#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleScene.h"

using namespace std;

Application::Application()
{
	// Order matters: they will Init/start/update in this order
	modules.push_back(window = new ModuleWindow());
	modules.push_back(renderer = new ModuleRender());
	modules.push_back(textures = new ModuleTextures());
	modules.push_back(input = new ModuleInput());
	modules.push_back(scene = new ModuleScene());

	// Homework: Create a new module to handle music and sound effects
}

Application::~Application()
{
	//TODO: from end -> being reverse order, delete list modules
	for (list<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend(); ++it)
		delete *it;

	modules.clear();
}

bool Application::Init()
{
	bool ret = true;

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Init();
	
	if (!ret) return ret;

	ret = Start();

	return ret;
}

bool Application::Start()
{
	bool ret = true;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret; ++it)
		ret = (*it)->Start();

	return ret;
}


// TODO 4: We need to have three updates, add them: PreUpdate Update PostUpdate


update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PreUpdate();

	if (ret != UPDATE_CONTINUE) return ret;

	for(list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->Update();

	if (ret != UPDATE_CONTINUE) return ret;

	for (list<Module*>::iterator it = modules.begin(); it != modules.end() && ret == UPDATE_CONTINUE; ++it)
		ret = (*it)->PostUpdate();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(list<Module*>::reverse_iterator it = modules.rbegin(); it != modules.rend() && ret; ++it)
		ret = (*it)->CleanUp();

	return ret;
}
