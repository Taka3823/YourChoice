#pragma once
#include "SceneBase.h"

//TODO
//SE‚Ì’Ç‰Á
//

class Title : public SceneBase
{
private:
	bool canSceneShift = false;

	Texture icon = Texture("res/Texture/GuideIcon.png");

	Vec2f iconPos = Vec2f(-64, -64);
	Vec2f iconSize = Vec2f(128,128);

	int waitTime = 0;
	const int WAIT_TIME = 60;

	bool canCountWaitTime = false;

	Vec2f mousePos;

public:
	Title()
    {
        CFont::FontGet().size(100);
    }

	void UpDate();
	void Draw();
	
	void WaitTimeCount();

	bool CanSceneShift()
	{
		return canSceneShift;
	}
};