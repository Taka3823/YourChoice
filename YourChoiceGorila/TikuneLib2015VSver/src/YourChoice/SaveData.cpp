#include "SaveData.h"

//メインからリザルトの移行時に使用
//isSelectedのセッターもセットで稼働
void SaveData::Save(bool isSelected_)
{
	std::ofstream playedFile("res/selected.txt");

	playedFile << isSelected_;
}

bool SaveData::IsSelectedLoad()
{
	std::ifstream file("res/selected.txt");

	file >> isSelected;

	return isSelected;
}

//リザルトのコンストラクタに使用
std::ifstream SaveData::LoadResultText(Selected selected_)
{

	if (selected_ == Selected::ONE_PERSON)
	{
	    std::ifstream file("res/ChoicesResult/ChooseOnePerson.txt");
	    
		return file;
	}
	else if (selected_ == Selected::CHOOSE_A_LOT)
	{
		std::ifstream file("res/ChoicesResult/ChooseALot.txt");
		return file;
	}
	else if (selected_ == Selected::DID_NOT_CHOOCE)
	{
		std::ifstream file("res/ChoicesResult/DidNotChoose.txt");
		return file;
	}
	else
	{
		assert(0);
	}
}

std::ifstream SaveData::LoadMaintext(bool didPlayed_)
{
	if (!didPlayed_)
	{
		std::ifstream file("res/Sentence/ShipSentence.txt");
	
		return file;
	}
	else if (didPlayed_)
	{
		std::ifstream file("res/SelectedText.txt");

		return file;
	}
	else
	{
		assert(0);
	}

	std::ifstream file("res/SelectedText.txt");
	return file;
}

void SaveData::TextRead(std::ifstream file_)
{
	assert(file_);

	std::string str;

	while (!file_.eof())
	{
		std::getline(file_,str);

		drawText.push_back(str);
	}
}