#include "../ヘッダー/Common.h"

bool RectToRect(Vec2f myPos_, Vec2f otherPos_,
    Vec2f mySize_, Vec2f otherSize_)
{
    return (
        myPos_.x() + mySize_.x() > otherPos_.x() &&
        myPos_.x() < otherPos_.x() + otherSize_.x() &&
        myPos_.y() + mySize_.y() > otherPos_.y() &&
        myPos_.y() < otherPos_.y() + otherSize_.y()
        );
}

bool CircleToCircle(Vec2f myPos_, Vec2f otherPos_,
    float mySize_, float otherSize_)
{
    return (
        (myPos_.x() - otherPos_.x()) * (myPos_.x() - otherPos_.x()) +
        (myPos_.y() - otherPos_.y()) * (myPos_.y() - otherPos_.y()) <
        (mySize_ - otherSize_) * (mySize_ - otherSize_)
        );
}

bool RectToPoint(Vec2f myPos_, Vec2f otherPos_, Vec2f otherSize_)
{
    return (
        myPos_.x() > otherPos_.x() &&
        myPos_.x() < otherPos_.x() + otherSize_.x() &&
        myPos_.y() > otherPos_.y() &&
        myPos_.y() < otherPos_.y() + otherSize_.y()
        );
}


//第一引数・・・実際の描画位置
//第二引数・・・実際の描画サイズ
//第三引数・・・画像のサイズ
//第四引数・・・描画する画像のID
void CenterDraw(Vec2f drawPos_, Vec2f drawSize_, Vec2f graphSize_, Texture graph_)
{
    drawTextureBox(drawPos_.x() / 2, drawPos_.y() / 2,
        drawSize_.x(), drawSize_.y(),
        0, 0,
        graphSize_.x(), graphSize_.y(),
        graph_,
        Color::white);
}

//TODO
//一回使ったらシーンが変わったり次に初期化されるまで
//使用しないようにする関数を追加する

//一秒
bool OneSecond(int time_)
{
    int time = 0;
    time_ += 1;


    if (time_ >= 60)
    {
        return true;
    } 
    return false;
}

void DrawBackGround(Texture graph_, Vec2f graphSize_)
{
	drawTextureBox(-Window::WIDTH / 2, -Window::HEIGHT / 2,
		Window::WIDTH, Window::HEIGHT,
		0, 0,
		graphSize_.x(), graphSize_.y(),
		graph_);
}



