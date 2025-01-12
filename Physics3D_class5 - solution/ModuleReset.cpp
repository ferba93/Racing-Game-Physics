#include "Application.h"
#include "ModuleReset.h"
#include "ModulePlayer.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysics3D.h"

ModuleReset::ModuleReset(Application* app, bool start_enabled) : Module(app, start_enabled) {}

ModuleReset::~ModuleReset(){}

bool ModuleReset::Start() {
	reset = false;
	return true;
}

update_status ModuleReset::Update(float dt) {
	if (reset == true) {
		App->player->CleanUp();
		App->scene_intro->CleanUp();
		App->physics->CleanUp();
		App->physics->Start();
		App->scene_intro->Start();
		App->player->Start();
		App->player->checkpoints = 0;
		App->player->last_checkpoint_pos = { 0, 0, 0 };
		reset = false;
	}
	return UPDATE_CONTINUE;
}

bool ModuleReset::CleanUp() { return true; }
