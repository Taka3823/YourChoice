#pragma once
#include "Common.h"
#include "CApp.h"

class SceneBase
{
public:
	Texture backGround = Texture("res/Texture/BackGround_.png");
	Vec2f   bgSize = Vec2f(1024, 512);

	virtual ~SceneBase(){}

	virtual void UpDate() {};
	virtual void Draw() {};
	virtual bool CanSceneShift() 
	{
		bool canSceneShift = false;
		return canSceneShift;
	};
};

