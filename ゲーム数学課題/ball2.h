#pragma once


//�g�p����w�b�_�[�t�@�C��
#include "GameL/SceneObjManager.h"
#include "orizin2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class Cball :public CObj
{
public:
	Cball() {};
	~Cball() {};
	void Init();  //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[
	Point pos;
	Vector vec;
	Vector acc;

	
	
private:
	
};