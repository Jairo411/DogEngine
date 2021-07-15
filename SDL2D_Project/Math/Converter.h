#ifndef CONVERTER_H
#define CONVERTER_H
#include "../GameObjects/Map/TileSet/Tiles.h"
#include "../Math/Vec2.h"
#include <SDL_rect.h>
/*2021-07-09
	Serves an actual purpose, Might need to re-look this but, this can be fixed way later into the future.*/
class Converter
{
public:
	static Vec2 GetMiddleOfSquare(Vec2 ScreenCoordinatesPos_);
	static Vec2 ConvertedScreenCoordinates(); // fill this in when you need it 
	static bool inRange(Vec2 low_, Vec2 high_, Vec2 vector_);
};

#endif // !COORDINATEHANDLER