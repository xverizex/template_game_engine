## My template for future games.

This is my favority activity - building apps. And now I want to create a template for further games.

To set up your game you should write in this code.

*Game/Core/GameConfig.cpp*
```
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

void GameConfig::list_of_levels ()
{
        n_levels.resize (N_LEVELS);
        n_levels[LEVEL_GAME] = new GameLevel ();
}

void GameConfig::entry_point ()
{
        cur_level = n_levels[LEVEL_GAME];

        cur_level->load_assets ();
}

void GameConfig::switch_level ()
{
        cur_level->unload_assets ();
        cur_level = n_levels[cur_level->new_level];
        cur_level->load_assets ();
```

You are self which shaders will be added in game, see *GameConfig::init_shaders*.

Now, you should put all resource files into `pre_assets`. See `utils/build_data_file`.
