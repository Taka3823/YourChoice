#pragma once
#include <fstream>
#include <list>
#include "../tikuneLib/ヘッダー/Common.h"

class SaveData
{
private:
	std::string selectedResult;
	std::list<std::string> drawText;

	bool isSelected;

public:

	SaveData() {};

	void Save(bool);

	bool IsSelectedLoad();

	std::ifstream LoadResultText(Selected);

	std::ifstream LoadMaintext(bool didPlayed);

	//上のロードをそのままここの引数に入れるとリザルトで使える
	void TextRead(std::ifstream);

	std::list<std::string> GetDrawText()
	{
		return drawText;
	}



	//後日の自分へ
	//TextReadには二つの役割を持たせてある。
	//一つはメインでの仕事。
	//問題文を描画するときにはdrawtextにsentenceを入れて使う。
	//もう一つはリザルト。
	//選択内容が決まったらその結果でdrawTextに選択結果を三種のうちから一つを使用する。
	//リザルトとメインで別のインスタンスを使うので別物として扱えるよ

	//あとあれな、二回目の固定文章もそうだからよろしく
	//使うタイミングは別のとこ（多分メイン）でやってくれるから大丈夫

	//困ったら変数ふやせばなんとかなる

};