#include "../ƒwƒbƒ_[/SceneManager.h"

SceneManager::SceneManager()
{
	didPlayed = saveData.IsSelectedLoad();
}

void SceneManager::UpDate()
{
	SceneShift();
    sceneSituation->UpDate();

		if (sceneNum == SceneNum::MAIN)
		{
			whatTime = std::dynamic_pointer_cast<GameMain>(sceneSituation)->CheckWhatTime();
		}
		else if (sceneNum == SceneNum::RESULT)
		{
			whatTime = std::dynamic_pointer_cast<Result>(sceneSituation)->CheckWhatTime();
		}
}

void SceneManager::Draw()
{   
    sceneSituation->Draw();
}

void SceneManager::SceneShift()
{
	switch (sceneNum)
	{
	case TITLE:
		if (sceneSituation->CanSceneShift())
		{
			sceneNum = SceneNum::MAIN;
            sceneSituation = std::make_shared<GameMain>(didPlayed);
		}

		break;

	case MAIN:

		if (sceneSituation->CanSceneShift())
		{
			sceneNum = SceneNum::RESULT;
			
			Selected selectedTemp = std::dynamic_pointer_cast<GameMain>(sceneSituation)->CheckEnding();

            sceneSituation = std::make_shared<Result>(selectedTemp);
		}
		break;

	case RESULT:
		
		whatTime = std::dynamic_pointer_cast<Result>(sceneSituation)->CheckWhatTime();

		break;
		
	case NONE:
		assert(0);
		break;

	default:
		assert(0);
		break;
	}
}
