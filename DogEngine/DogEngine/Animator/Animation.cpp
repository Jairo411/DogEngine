#include "Animation.h"

Animation::Animation() : frames(0) , currentFrame(0),currentFrameTime(0.f)
{

}

void Animation::AddFrame(int textureID, int x, int y, int width, int height, float frameTime)
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

const FrameData* Animation::GetCurrentFrame() const
{
	if (frames.size()>0)
	{
		return &frames[currentFrame];
	}

	return nullptr;
}

bool Animation::UpdateFrame(float deltaTime)
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

void Animation::Reset()
{
	currentFrame = 0;
	currentFrameTime = 0.0f; // going to change this to uint32
}

void Animation::IncrementFrame()
{
	currentFrame = (currentFrame + 1) % frames.size();
}
