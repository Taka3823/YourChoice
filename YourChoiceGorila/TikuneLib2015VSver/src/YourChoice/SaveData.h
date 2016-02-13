#pragma once
#include <fstream>
#include <list>
#include "../tikuneLib/�w�b�_�[/Common.h"

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

	//��̃��[�h�����̂܂܂����̈����ɓ����ƃ��U���g�Ŏg����
	void TextRead(std::ifstream);

	std::list<std::string> GetDrawText()
	{
		return drawText;
	}



	//����̎�����
	//TextRead�ɂ͓�̖������������Ă���B
	//��̓��C���ł̎d���B
	//��蕶��`�悷��Ƃ��ɂ�drawtext��sentence�����Ďg���B
	//������̓��U���g�B
	//�I����e�����܂����炻�̌��ʂ�drawText�ɑI�����ʂ��O��̂����������g�p����B
	//���U���g�ƃ��C���ŕʂ̃C���X�^���X���g���̂ŕʕ��Ƃ��Ĉ������

	//���Ƃ���ȁA���ڂ̌Œ蕶�͂������������낵��
	//�g���^�C�~���O�͕ʂ̂Ƃ��i�������C���j�ł���Ă���邩����v

	//��������ϐ��ӂ₹�΂Ȃ�Ƃ��Ȃ�

};