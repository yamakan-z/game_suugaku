//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"
#include "GameHead.h"
#include "ball2.h"
#include "orizin2.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void Cball::Init()
{
    pos.x = 0.0;
    pos.y = 0.0;
    vec.x = 0.0;
    vec.y = 0.0;
    acc.x = 0.0;
    acc.y = 0.0;
}


//アクション
void Cball::Action()
{
    //移動ベクトル初期化
    vec.x = 0.0f;
    vec.y = 0.0f;

    //移動処理
    /*if (Input::GetVKey(VK_RIGHT) == true)
    {
        vec.x += 2.0;
    }
    if (Input::GetVKey(VK_LEFT) == true)
    {
        vec.x -= 2.0;
    }
    if (Input::GetVKey(VK_UP) == true)
    {
        vec.y -= 2.0;
    }
    if (Input::GetVKey(VK_DOWN) == true)
    {
        vec.y += 2.0;
    }*/

    //ウィンドウの端に行くと反射
    /*if (pos.x + 72.0f > 800.0f)
    {
        vec.x = -vec.x;

    }
    if (pos.y + 72.0f > 600.0f)
    {
        vec.y = -vec.y;
    }
    if (pos.x < 0.0f)
    {
        vec.x = -vec.x;
    }
    if (pos.y < 0.0f)
    {
        vec.y = -vec.y;
    }*/

    //反射処理
    //if (pos.x < 0 || pos.x>736)vec.x = -vec.x;
    //if (pos.y < 0 || pos.y>535)vec.y = -vec.y;



    ((UserData*)Save::GetData())->bx = pos.x;
    ((UserData*)Save::GetData())->by = pos.y;
    ((UserData*)Save::GetData())->b_x2 = vec.x;
    ((UserData*)Save::GetData())->b_y2 = vec.y;

    //移動処理
   //Move(&pos, &vec, acc);
   //移動処理（摩擦あり）
    Move(&pos.x, &vec.x, acc.x,0.9f);
    Move(&pos.y, &vec.y, acc.y,0.9f);

}

//ドロー
void Cball::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置

    dst.m_top = 0.0f+300.0f + pos.y;
    dst.m_left = 0.0f+300.0f + pos.x;
    dst.m_right = 64.0f+300.0f + pos.x;
    dst.m_bottom = 64.0f +300.0f+ pos.y;

    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 64.0f;
    src.m_bottom = 64.0f;

    Draw::Draw(1, &src, &dst, c, 0.0f);

}