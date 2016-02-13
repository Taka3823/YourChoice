#pragma once
#include "SceneBase.h"
#include "../../YourChoice/SaveData.h"

class Result : public SceneBase
{
private:
	bool canSceneShift = false;

	bool whatTime = false;

	int fontSize = 35;

	Selected selectedEnding;

	SaveData saveData;

	std::list<std::string> textData;

	int timeCount = 0;
	const int TimeRimmit = 360;

public:
	Result(Selected selected_);

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
};