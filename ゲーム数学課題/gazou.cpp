//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"
#include "GameHead.h"
#include "gazou.h"
#include "orizin2.h"
#include <math.h>



//使用するネームスペース
using namespace GameL;

//イニシャライズ
void Cgazou::Init()
{
    pos.x = 0.0;
    pos.y = 0.0;
    vec.x = 0.0;
    vec.y = 0.0;
    acc.x = 0.0;
    acc.y = 0.0;
    rad = 0.0f;
   
}
//アクション
void Cgazou::Action()
{
    //移動ベクトル初期化
    vec.x = 0.0f;
    vec.y = 0.0f;
    //移動処理
    if (Input::GetVKey(VK_RIGHT) == true)
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
    }
    //if (vec.x == 0.0f && vec.y == 0.0f)
    //{
    //    //角度をつける
    //    if (Input::GetVKey(VK_RIGHT) == true)
    //    {
    //        rad += 2.0;
    //    }
    //    if (Input::GetVKey(VK_LEFT) == true)
    //    {
    //        rad -= 2.0;
    //    }

    //    //360°を超えると０に戻す
    //    if (rad > 360.0f || rad < -360.0f)
    //    {
    //        rad = 0.0f;
    //    }
    //    

    //    //スペースキーではじく
    //    if (Input::GetVKey(VK_SPACE) == true)
    //    {
    //        vec.x = cos(rad * 3.14 / 180.0f);
    //        vec.y = -sin(rad * 3.14 / 180.0f);
    //        //ベクトルの長さを設定
    //        vec = Vector_SetLenght(vec, 10.0f);
    //    }
    //}
   
    //移動ベクトルの設定
   //vec.x = cos(RADIAN(rad));
   //vec.y = -sin(RADIAN(rad));
   

    //ウィンドウの端に行くと反射
    if (pos.x + 64.0f > 800.0f)
    {
        vec.x = -vec.x;

    }
    if (pos.y + 64.0f > 600.0f)
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
    }


     //移動処理
   //Move(&pos, &vec, acc);
   //移動処理（摩擦あり）
    Move(&pos.x, &vec.x, acc.x, 0.9f);
    Move(&pos.y, &vec.y, acc.y, 0.9f);


    




    ////反射処理
    //if (pos.x < 0 || pos.x>736)vec.x = -vec.x;
    //if (pos.y < 0 || pos.y>535)vec.y = -vec.y;


    //移動ベクトルが一定の値より低ければ0.0fにする
    //fabs:絶対値
    if (fabs(vec.x) < 0.001f)vec.x = 0.0f;
    if (fabs(vec.y) < 0.001f)vec.y = 0.0f;
    
   

    ((UserData*)Save::GetData())->ax=pos.x;
    ((UserData*)Save::GetData())->ay=pos.y;
    ((UserData*)Save::GetData())->b_x = vec.x;
    ((UserData*)Save::GetData())->b_y = vec.y;

    float l = sqrtf((((UserData*)Save::GetData())->ax - ((UserData*)Save::GetData())->bx)*
                    (((UserData*)Save::GetData())->ax - ((UserData*)Save::GetData())->bx)+
                    (((UserData*)Save::GetData())->ay - ((UserData*)Save::GetData())->by)*
                    (((UserData*)Save::GetData())->ay - ((UserData*)Save::GetData())->by));
    

    

    if (l < 64.0f)//判定する円の大きさが64ピクセルの場合
    {
        //お互いの中心ベクトル
        Vector vec;
       vec.x= ((UserData*)Save::GetData())->ax-((UserData*)Save::GetData())->bx;
       vec.y= ((UserData*)Save::GetData())->ay-((UserData*)Save::GetData())->by;

       
        vec = Vector_SetLenght(vec, 64.0f);//

        ////動いてるオブジェクトを停止させる
        //((UserData*)Save::GetData())->b_x = 0.0f;
        //((UserData*)Save::GetData())->b_y = 0.0f;
    }

    //中心の二点間距離
    //float l=sqrtf((ax-bx)*(ax-bx)+(ay-by)*(ay-by));

}

//ドロー
void Cgazou::Draw()
{
    //描写カラー情報
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//描写元の切り取り位置
    RECT_F dst;//描画先の表示位置

    dst.m_top = 0.0f+pos.y;
    dst.m_left = 0.0f+pos.x;
    dst.m_right = 64.0f+pos.x;
    dst.m_bottom = 64.0f+pos.y;

    src.m_top = 0.0f;
    src.m_left = 0.0f;
    src.m_right = 64.0f;
    src.m_bottom = 64.0f;

    Draw::Draw(0, &src, &dst, c, 0.0f);

}