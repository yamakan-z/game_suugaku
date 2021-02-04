//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/UserData.h"
#include "GameHead.h"
#include "gazou.h"
#include "orizin2.h"
#include <math.h>



//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
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
//�A�N�V����
void Cgazou::Action()
{
    //�ړ��x�N�g��������
    vec.x = 0.0f;
    vec.y = 0.0f;
    //�ړ�����
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
    //    //�p�x������
    //    if (Input::GetVKey(VK_RIGHT) == true)
    //    {
    //        rad += 2.0;
    //    }
    //    if (Input::GetVKey(VK_LEFT) == true)
    //    {
    //        rad -= 2.0;
    //    }

    //    //360���𒴂���ƂO�ɖ߂�
    //    if (rad > 360.0f || rad < -360.0f)
    //    {
    //        rad = 0.0f;
    //    }
    //    

    //    //�X�y�[�X�L�[�ł͂���
    //    if (Input::GetVKey(VK_SPACE) == true)
    //    {
    //        vec.x = cos(rad * 3.14 / 180.0f);
    //        vec.y = -sin(rad * 3.14 / 180.0f);
    //        //�x�N�g���̒�����ݒ�
    //        vec = Vector_SetLenght(vec, 10.0f);
    //    }
    //}
   
    //�ړ��x�N�g���̐ݒ�
   //vec.x = cos(RADIAN(rad));
   //vec.y = -sin(RADIAN(rad));
   

    //�E�B���h�E�̒[�ɍs���Ɣ���
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


     //�ړ�����
   //Move(&pos, &vec, acc);
   //�ړ������i���C����j
    Move(&pos.x, &vec.x, acc.x, 0.9f);
    Move(&pos.y, &vec.y, acc.y, 0.9f);


    




    ////���ˏ���
    //if (pos.x < 0 || pos.x>736)vec.x = -vec.x;
    //if (pos.y < 0 || pos.y>535)vec.y = -vec.y;


    //�ړ��x�N�g�������̒l���Ⴏ���0.0f�ɂ���
    //fabs:��Βl
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
    

    

    if (l < 64.0f)//���肷��~�̑傫����64�s�N�Z���̏ꍇ
    {
        //���݂��̒��S�x�N�g��
        Vector vec;
       vec.x= ((UserData*)Save::GetData())->ax-((UserData*)Save::GetData())->bx;
       vec.y= ((UserData*)Save::GetData())->ay-((UserData*)Save::GetData())->by;

       
        vec = Vector_SetLenght(vec, 64.0f);//

        ////�����Ă�I�u�W�F�N�g���~������
        //((UserData*)Save::GetData())->b_x = 0.0f;
        //((UserData*)Save::GetData())->b_y = 0.0f;
    }

    //���S�̓�_�ԋ���
    //float l=sqrtf((ax-bx)*(ax-bx)+(ay-by)*(ay-by));

}

//�h���[
void Cgazou::Draw()
{
    //�`�ʃJ���[���
    float c[4] = { 1.0f,1.0f,1.0f,1.0f };

    RECT_F src;//�`�ʌ��̐؂���ʒu
    RECT_F dst;//�`���̕\���ʒu

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