#ifndef CONVERTER_H
#define CONVERTER_H
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../Math/Vec2.h"
#include <SDL_rect.h>
//Remove this
class Converter
{
public:
	static vec2 GetMiddleOfSquare(vec2 ScreenCoordinatesPos_);
	static vec2 ConvertedScreenCoordinates(); // fill this in when you need it 
	static bool inRange(vec2 low_, vec2 high_, vec2 vector_);
};

#endif // !COORDINATEHANDLER