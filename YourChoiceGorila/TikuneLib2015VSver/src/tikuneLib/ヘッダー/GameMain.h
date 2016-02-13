#pragma once
#include "SceneBase.h"
#include "../../YourChoice/SaveData.h"

class GameMain : public SceneBase
{
private:
	bool canSceneShift = false;

	bool isEndEffectTime = false;

	int fontSize = 35;

	SaveData saveData;

	std::list<std::string> textData;

	int timeCount = 0;
	int drawTime = 12;
	
	//五秒
	const int TimeRimmit = 300;
	//六秒
	const int SecondPlayTimeRimmit = 240;
	//デバッグ用
	const int AllTimeRimmit = 720;

	bool didPlayed;

	Texture oneHand = Texture("res/Texture/OneHand.png");
	Texture twoHand = Texture("res/Texture/TwoHand.png");

	Vec2f boxPos[2] =
	{
		Vec2f(-350,-300),
		Vec2f( 100,-300)
	};

	Vec2f boxSize = Vec2f(300, 300);

	Vec2f mousePos;

	Selected selected;

	//ウィンドウ閉じる命令用
	bool whatTime = false;

	bool choiced = false;

	int effectTimeCount = 0;
	const int effectTimeRimmit = 240;

	const int MoveSpeed =2;

	const Vec2f TheFinalPlace[2] =
	{
		Vec2f(-192, -128),
		Vec2f(-64,-128)
	};

	int drawTimeCount = 0;
	//4秒
	const int DrawTimeRimmit = 240;


public:
	GameMain(bool);

	void UpDate();
	void Draw();
	
	bool CanSceneShift()
	{
		return canSceneShift;
	}

	bool CheckWhatTime()
	{
		return whatTime;
	}
	Selected CheckEnding()
	{
		return selected;
	}

	void EffectHandMove();

};