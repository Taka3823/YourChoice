#include "../ヘッダー/GameMain.h"

GameMain::GameMain(bool didPlayed_)
{
	saveData.TextRead(saveData.LoadMaintext(didPlayed_));
	textData = saveData.GetDrawText();

	didPlayed = didPlayed_;

	CFont::FontGet().size(fontSize);
}

void GameMain::UpDate()
{
	mousePos = CApp::Get().mousePosition();

	/******************************
	TODO
	今は１０秒で強制リザルトだが、
	文章の最後が出てから５秒カウントに変える

	/*******************************/

	if (!didPlayed)
	{
		//一回目のプレイ時
		timeCount += 1;

		if (timeCount % 60 == 0)
		{
			drawTime -= 1;
		}

		//if (timeCount >= TimeRimmit)
		if(timeCount >= AllTimeRimmit)
		{
			selected = Selected::DID_NOT_CHOOCE;
			choiced = true;
		}

		if (RectToPoint(mousePos, boxPos[0], boxSize))
		{
			if (CApp::Get().isPushButton(Mouse::LEFT))
			{
				if (!choiced)
				{
					selected = Selected::ONE_PERSON;
					choiced = true;
				}
			}
		}

		if (RectToPoint(mousePos, boxPos[1], boxSize))
		{
			if (CApp::Get().isPushButton(Mouse::LEFT))
			{
				if (!choiced)
				{
					selected = Selected::CHOOSE_A_LOT;
					choiced = true;
				}
			}
		}
	}
	else if (didPlayed)
	{
		//二回目のプレイ時
		timeCount += 1;
		if (timeCount >= SecondPlayTimeRimmit)
		{
			whatTime = true;
		}
	}

	if (choiced)
	{
		EffectHandMove();
	}
}

void GameMain::Draw()
{
	DrawBackGround(backGround,bgSize);

	Vec2f pos = Vec2f(-WIDTH / 2, 350);
	
	/**/
	for (auto tex = textData.begin(); tex != textData.end(); ++tex)
	{
		CFont::FontGet().draw(*tex, pos, Color::white);
		pos.y() -= fontSize;
	}
	/**/

	/**
	for (auto tex = textData.begin(); tex != textData.end(); )
	{
		drawTimeCount += 1;
		CFont::FontGet().draw(*tex, pos, Color::white);
		//pos.y() -= fontSize;

		if (drawTimeCount >= DrawTimeRimmit)
		{
			textData.erase(tex);
			++tex;
			drawTimeCount = 0;
		}
	}
	/**/


	if (drawTime <= 5)
	{
		CFont::FontGet().draw(std::to_string(drawTime), Vec2f(0, -300), Color::white);
	}

	if (!didPlayed)
	{
		drawTextureBox(boxPos[0].x(), boxPos[0].y(),
			           boxSize.x(), boxSize.y(),
			           0, 0,
			           256, 256,
			           oneHand,
			           Color::white);

		drawTextureBox(boxPos[1].x(), boxPos[1].y(),
			           boxSize.x(), boxSize.y(),
			           0, 0,
		 	           256, 256,
			           twoHand,
			           Color::white);
	}
}

void GameMain::EffectHandMove()
{
	effectTimeCount += 1;

	if (selected == Selected::ONE_PERSON)
	{
		if (!(boxPos[0].x() >= TheFinalPlace[0].x() &&
			  boxPos[0].y() >= TheFinalPlace[0].y()))
		{
			boxPos[0].x() += MoveSpeed;
			boxPos[0].y() += MoveSpeed;
		}

		boxPos[1].y() -= MoveSpeed;

		if (effectTimeCount >= effectTimeRimmit)
		{
			canSceneShift = true;
		}
	}
	else if (selected == Selected::CHOOSE_A_LOT)
	{
		if (!(boxPos[1].x() <= TheFinalPlace[1].x() &&
			  boxPos[1].y() >= TheFinalPlace[1].y()))
		{
			boxPos[1].x() -= MoveSpeed;
			boxPos[1].y() += MoveSpeed;
		}

		boxPos[0].y() -= MoveSpeed;

		if (effectTimeCount >= effectTimeRimmit)
		{
			canSceneShift = true;
		}
	}
	else if (selected == Selected::DID_NOT_CHOOCE)
	{
		timeCount = 0;

		boxPos[0].y() -= MoveSpeed;
		boxPos[1].y() -= MoveSpeed;

		if (effectTimeCount >= effectTimeRimmit)
		{
			canSceneShift = true;
		}
	}
	else
	{
		assert(0);
	}
}