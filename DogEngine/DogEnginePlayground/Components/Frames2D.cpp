#include "Frames2D.h"

Frames2D::Frames2D() : frames(0) , currentFrame(0),currentFrameTime(0.f)
{

}

void Frames2D::AddFrame(int textureID, int x, int y, int width, int height, float frameTime)
{
	FrameData data;

	data.id = textureID;
	data.xPos = x;
	data.yPos = y;
	data.width = width;
	data.height = height;
	data.displayTimeSeconds = frameTime;

	frames.push_back(data);
}

const FrameData* Frames2D::GetCurrentFrame() const
{
	if (frames.size()>0)
	{
		return &frames[currentFrame];
	}

	return nullptr;
}

bool Frames2D::UpdateFrame(float deltaTime)
{
	if (frames.size()>0)
	{
		currentFrameTime += deltaTime;

		if (currentFrameTime>=
			frames[currentFrame].displayTimeSeconds)
		{
			currentFrame = 0.f;
			IncrementFrame();
			return true;
		}
	}
	return false;
}

void Frames2D::Reset()
{
	currentFrame = 0;
	currentFrameTime = 0.0f; // going to change this to uint32
}

void Frames2D::IncrementFrame()
{
	currentFrame = (currentFrame + 1) % frames.size();
}
