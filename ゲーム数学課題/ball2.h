#pragma once


//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"
#include "orizin2.h"

//使用するネームスペース
using namespace GameL;

class Cball :public CObj
{
public:
	Cball() {};
	~Cball() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
	Point pos;
	Vector vec;
	Vector acc;

	
	
private:
	
};