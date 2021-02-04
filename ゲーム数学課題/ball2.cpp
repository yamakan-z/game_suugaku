//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"
#include "GameHead.h"
#include "ball2.h"
#include "orizin2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void Cball::Init()
{
    pos.x = 0.0;
    pos.y = 0.0;
    vec.x = 0.0;
    vec.y = 0.0;
    acc.x = 0.0;
    acc.y = 0.0;
}


//�A�N�V����
void Cball::Action()
{
    //�ړ��x�N�g��������
    vec.x = 0.0f;
    vec.y = 0.0f;

    //�ړ�����
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

    //�E�B���h�E�̒[�ɍs���Ɣ���
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

    //���ˏ���
    //if (pos.x < 0 || pos.x>736)vec.x = -vec.x;
    //if (pos.y < 0 || pos.y>535)vec.y = -vec.y;



    ((UserData*)Save::GetData())->bx = pos.x;
    ((UserData*)Save::GetData())->by = pos.y;
    ((UserData*)Save::GetData())->b_x2 = vec.x;
    ((UserData*)Save::GetData())->b_y2 = vec.y;

    //�ړ�����
   //Move(&pos, &vec, acc);
   //�ړ������i���C����j
    Move(&pos.x, &vec.x, acc.x,0.9f);
    Move(&pos.y, &vec.y, acc.y,0.9f);

}

//�h���[
void Cball::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu

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