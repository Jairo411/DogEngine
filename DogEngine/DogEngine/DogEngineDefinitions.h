#ifndef DOGENGINEDEFINITIONS
#define DOGENGINEDEFINITIONS
#include <SDL_image.h>
#include <glm/glm.hpp>
#include <utility>
#include <string>
/*02-01-2023 
* just a side note, I know I using other libraries variables and typedefing them to my 
* own defintions, this is simply to avoid typing all the namespaces. In no way am I plagiarizing 
* glm math code as my own.
*
*/
	typedef std::pair<bool, float> inputVals;
	typedef std::pair<SDL_Rect, SDL_Rect> SpriteDisplayRect;
	typedef glm::mat3x3 Mat3;
	typedef glm::vec2 vector2;
	const std::string projectParentDirectory = "DogEngine/"; // I don't think this should be here 
	enum class RenderAPI : int
	{
	SDLAPI = 0,
	OPENGLAPI = 1,
	VULKANAPI = 2,
	};
	

#endif // !DOGENGINEDEFINITIONS