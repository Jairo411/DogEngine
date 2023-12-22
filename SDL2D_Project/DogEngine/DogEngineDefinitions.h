#ifndef DOGENGINEDEFINITIONS
#define DOGENGINEDEFINITIONS
#include <SDL_image.h>
#include <glm/glm.hpp>
#include <utility>
typedef std::pair<bool, float> inputVals;
typedef std::pair<SDL_Rect, SDL_Rect> SpriteRect;
typedef glm::mat3x3 Mat3;
typedef glm::vec2 vector2;
enum class RenderAPI : int
{
	SDLAPI = 0,
	OPENGLAPI = 1,
	VULKANAPI = 2,
};
#endif // !DOGENGINEDEFINITIONS