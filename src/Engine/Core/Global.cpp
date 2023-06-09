#include <Engine/Core/Global.h>
#include <Engine/Core/ShaderManager.h>
#include <Engine/Core/ScreenManager.h>

namespace Global {

template<typename T>
static T* m;

template<typename T>
void set_singleton (T* _sm)
{
	m<T> = _sm;
}

template<typename T>
T* get_singleton ()
{
	return m<T>;
}

}
