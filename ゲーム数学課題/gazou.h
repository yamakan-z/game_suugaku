#pragma once


//使用するヘッダーファイル
#include "GameL/SceneObjManager.h"
#include "orizin2.h"

//使用するネームスペース
using namespace GameL;

class Cgazou :public CObj
{
public:
	Cgazou() {};
	~Cgazou() {};
	void Init();  //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー
	//角度
	float rad;



	Point pos;
	Vector vec;
	Vector acc;

private:
	
};