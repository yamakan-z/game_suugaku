//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING()

//GameLで使用するヘッダー
#include"GameL\DrawTexture.h"
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}
//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録（線なし背景）
	Draw::LoadImage(L"boll.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"ball2.png", 1, TEX_SIZE_512);

	//主人公オブジェクト作成
	Cgazou* fp = new Cgazou();
	Objs::InsertObj(fp, OBJ_GAZOU, 10);

	//ballオブジェクト作成
	Cball* ba = new Cball();
	Objs::InsertObj(ba, OBJ_BALL, 10);
}


//ゲーム実行中メソッド
void CSceneMain::Scene()
{

}