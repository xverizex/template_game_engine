#include <Game/Core/GameConfig.h>
#include <Engine/Core/ShaderManager.h>
#include <Engine/Core/Global.h>
#include <Engine/Core/ScreenManager.h>
#include <vector>

void GameConfig::init_shaders ()
{
	std::vector<ShaderInfoFile> list_shaders;
	list_shaders.push_back ({SHADER_3D_WITHOUT_LIGHT, "shader_3d_without_light"});

	ShaderManager* shader_manager = Global::get_singleton<ShaderManager> ();

	shader_manager->set_shaders_and_compile (list_shaders);
}

void GameConfig::init_screen ()
{
	ScreenManager* screen_manager = Global::get_singleton<ScreenManager> ();

	screen_manager->set_screen_size (600, 1024, false);
}