
#pragma once 
#include <memory>
#include "SceneBase.h"
#include "Title.h"
#include "GameMain.h"
#include "Result.h"


#include "../../YourChoice/SaveData.h"

class SceneManager : public SceneBase
{
private:

    std::shared_ptr <SceneBase> sceneSituation = std::make_shared<Title>(); 
    SceneNum sceneNum = SceneNum::TITLE;
	SaveData saveData;

	bool didPlayed;

	bool whatTime = false;

public:

	SceneManager();

    void UpDate();

    void Draw();

    void SceneShift();

	bool CheckWhatTime()
	{
		return whatTime;
	}

};