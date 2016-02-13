#pragma once

//*************************************//
//汎用的なenumや、関数を宣言しておくヘッダー //
//************************************//

#include "../../lib/framework.hpp"

//１秒のフレーム数
const int ONE_SECOND = 60;

//Windowのサイズ
//プロジェクトによって変更可
enum Window
{
	WIDTH = 900,
	HEIGHT = 900
};

enum SceneNum
{
	TITLE = 0,
	MAIN,
	RESULT,

	NONE = -1
};

//TODO
//シングルトンにしといて
//マウスポジションを

//四角と四角の当たり判定
bool RectToRect(Vec2f myPos_,Vec2f otherPos_,
                Vec2f mySize_,Vec2f otherSize_);

//CenterDrawに合わせた当たり判定
//※実際に使うかは不明

//円と円の当たり判定
bool CircleToCircle(Vec2f my_pos_,  Vec2f other_pos_,
                    float my_size_, float other_size_);
//四角と点の当たり判定
bool RectToPoint(Vec2f myPos_, Vec2f otherPos_, Vec2f otherSize_);

//描画画面の描画位置を中心にする
//※画像の切り出し位置は(0,0)であること。
//異なる場合はケースバイケースでその都度自作すること。
void CenterDraw(Vec2f drawPos_,Vec2f drawSize_,
                Vec2f graphSize_,Texture graph_);

class CFont
{
private:
    CFont(){}

public:
    static Font& FontGet()
    {
        static Font font("res/Font/yugothic.ttf");
        return font;
    }
};

void DrawBackGround(Texture graph_, Vec2f graphSize_);


enum Selected
{
	ONE_PERSON = 0,
	CHOOSE_A_LOT,
	DID_NOT_CHOOCE
};
