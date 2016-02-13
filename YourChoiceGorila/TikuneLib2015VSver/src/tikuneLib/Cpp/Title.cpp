#include "../ƒwƒbƒ_[/Title.h"

void Title::UpDate()
{
	mousePos = CApp::Get().mousePosition();

	if (RectToPoint(mousePos,iconPos,iconSize))
	{
		if (CApp::Get().isPushButton(Mouse::LEFT))
		{
			canCountWaitTime = true;
		}
	}

	if (canCountWaitTime)
	{
		WaitTimeCount();
	}
}

void Title::Draw()
{
	DrawBackGround(backGround,bgSize);

	drawTextureBox(iconPos.x(),iconPos.y(),
		           iconSize.x(),iconSize.y(),
		           0,0,
		           196,196,
		           icon,
		           Color::white);


    CFont::FontGet().draw("YourChoice", 
		                  Vec2f(-400, 300), 
		                  Color::white);
}

void Title::WaitTimeCount()
{
	waitTime += 1;
	if (waitTime >= WAIT_TIME)
	{
		canSceneShift = true;
	}
}