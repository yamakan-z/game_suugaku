//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING()

//GameL�Ŏg�p����w�b�_�[
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^�i���Ȃ��w�i�j
	Draw::LoadImage(L"boll.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"ball2.png", 1, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	Cgazou* fp = new Cgazou();
	Objs::InsertObj(fp, OBJ_GAZOU, 10);

	//ball�I�u�W�F�N�g�쐬
	Cball* ba = new Cball();
	Objs::InsertObj(ba, OBJ_BALL, 10);
}


//�Q�[�����s�����\�b�h
void CSceneMain::Scene()
{

}