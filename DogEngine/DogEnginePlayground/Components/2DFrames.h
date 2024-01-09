#ifndef ANIMATION2D_H
#define ANIMATION2D_H

#include <vector>

struct FrameData
{
	int id; //Texure id <-pointer
	int xPos; // x position 
	int yPos; // y position 
	int width;
	int height;
	float displayTimeSeconds; // amount of frames & how long to display picture
};

class Animation
{
public:
	Animation();
	void AddFrame(int textureID, int x, int y,
		int width, int height, float frameTime);
	const FrameData* GetCurrentFrame() const;
	bool UpdateFrame(float deltaTime);
	void Reset();

private:
	void IncrementFrame();

	//Stores all frames for our animation 

	std::vector<FrameData> frames;

	int currentFrame;

	float currentFrameTime;
};


#endif