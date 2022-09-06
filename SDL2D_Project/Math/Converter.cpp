#include "Converter.h"

vec2 Converter::GetMiddleOfSquare(vec2 ScreenCoordinatesPos_)
{
	vec2 ConvertedPos;
	ConvertedPos.x = ScreenCoordinatesPos_.x + Tile::getWidth() / 2;
	ConvertedPos.y = ScreenCoordinatesPos_.y + Tile::getHeight()/ 2;
	return ConvertedPos;
}

vec2 Converter::ConvertedScreenCoordinates()
{
	//Fill this in when you need it 
	return vec2();
}

bool Converter::inRange(vec2 low_, vec2 high_, vec2 vec)
{
	return (low_.x <= vec.x && low_.y <= vec.y 
		&& high_.x >= vec.x && high_.y >= vec.y);
}
