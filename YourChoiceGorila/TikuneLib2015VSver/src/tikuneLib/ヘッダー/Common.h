#pragma once

//*************************************//
//�ėp�I��enum��A�֐���錾���Ă����w�b�_�[ //
//************************************//

#include "../../lib/framework.hpp"

//�P�b�̃t���[����
const int ONE_SECOND = 60;

//Window�̃T�C�Y
//�v���W�F�N�g�ɂ���ĕύX��
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
//�V���O���g���ɂ��Ƃ���
//�}�E�X�|�W�V������

//�l�p�Ǝl�p�̓����蔻��
bool RectToRect(Vec2f myPos_,Vec2f otherPos_,
                Vec2f mySize_,Vec2f otherSize_);

//CenterDraw�ɍ��킹�������蔻��
//�����ۂɎg�����͕s��

//�~�Ɖ~�̓����蔻��
bool CircleToCircle(Vec2f my_pos_,  Vec2f other_pos_,
                    float my_size_, float other_size_);
//�l�p�Ɠ_�̓����蔻��
bool RectToPoint(Vec2f myPos_, Vec2f otherPos_, Vec2f otherSize_);

//�`���ʂ̕`��ʒu�𒆐S�ɂ���
//���摜�̐؂�o���ʒu��(0,0)�ł��邱�ƁB
//�قȂ�ꍇ�̓P�[�X�o�C�P�[�X�ł��̓s�x���삷�邱�ƁB
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
