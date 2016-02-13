#include "../ƒwƒbƒ_[/Result.h"

Result::Result(Selected selected_)
{
	CFont::FontGet().size(fontSize);
	
	selectedEnding = selected_;

	saveData.TextRead(saveData.LoadResultText(selectedEnding));
//	saveData.Save(true);
	
	textData = saveData.GetDrawText();
}

void Result::UpDate()
{
	timeCount += 1;

	if (timeCount >= TimeRimmit)
	{
		whatTime = true;
	}

}

void Result::Draw()
{
	Vec2f pos = Vec2f(-WIDTH / 2, 350);

	for (auto tex = textData.begin(); tex != textData.end(); ++tex)
	{
		CFont::FontGet().draw(*tex, pos, Color::white);
		pos.y() -= fontSize;
	}
}