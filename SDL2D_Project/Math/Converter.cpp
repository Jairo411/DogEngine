#include "Converter.h"

Vec2 Converter::GetMiddleOfSquare(Vec2 ScreenCoordinatesPos_)
{
	Vec2 ConvertedPos;
	ConvertedPos.x = ScreenCoordinatesPos_.x + Tile::getWidth() / 2;
	ConvertedPos.y = ScreenCoordinatesPos_.y + Tile::getHeight()/ 2;
	return ConvertedPos;
}

Vec2 Converter::ConvertedScreenCoordinates()
{
	//Fill this in when you need it 
	return Vec2();
}
