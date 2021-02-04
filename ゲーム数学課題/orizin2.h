#pragma once

#define _USE_MATH_DEFINES
//���W�A���ϊ��p�}�N��
#define RADIAN(_deg)  (M_PI*(deg)/180.0f)

//�񎟌��ړ��ւ̑Ή�

//���W���̍\����
struct Point
{
	float x, y;
};

//�x�N�g���̍\����
struct Vector
{
	float x, y;
};

//���W+�x�N�g��
Point Add_Point_Vector(Point p, Vector v);
//�x�N�g��+�x�N�g��
Vector Add_Vector_Vector(Vector v0, Vector v1);
//�x�N�g���~�X�J���[
Vector Mul_Vector_Scaler(Vector v, float s);
//�x�N�g���̒������擾
float Vector_Lenght(Vector v);
//�x�N�g���𐳋K��
Vector Vector_Normalize(Vector v);
//�x�N�g���̒�����ݒ�
Vector Vector_SetLenght(Vector v, float lenght);

//�ړ�����
void Move(float* pos, float* speed, float acc);

void Move(Point* pos, Vector* speed, Vector acc);

//�ړ������i���C����j
void Move(float* pos, float* speed, float acc, float fri);