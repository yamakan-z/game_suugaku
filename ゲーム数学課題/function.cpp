#include "orizin2.h"
#include <math.h>

//���W+�x�N�g��
Point Add_Point_Vector(Point p, Vector v)
{
	Point r;
	r.x = p.x + v.x;
	r.y = p.y + v.y;

	return (r);
}

//�x�N�g��+�x�N�g��
Vector Add_Vector_Vector(Vector v0, Vector v1)
{
	Vector r;
	r.x = v0.x + v1.x;
	r.y = v0.y + v1.y;

	return (r);
}

//�x�N�g���~�X�J���[
Vector Mul_Vector_Scaler(Vector v, float s)
{
	Vector r;
	r.x = v.x * s;
	r.y = v.y * s;

	return (r);
}

//�x�N�g���̒������擾
float Vector_Lenght(Vector v)
{
	float l = sqrtf(v.x * v.x + v.y * v.y);
	return (l);
}

//�x�N�g���𐳋K��
Vector Vector_Normalize(Vector v)
{
	float l = Vector_Lenght(v);
	Vector n;
	n.x = v.x/ l;
	n.y = v.y / l;

	return (n);
}

//�x�N�g���̒�����ݒ�
Vector Vector_SetLenght(Vector v, float lenght)
{
	v = Vector_Normalize(v);
	v = Mul_Vector_Scaler(v, lenght);

	return (v);
}

//�ړ������֐��i1�����j
void Move(float* pos, float* speed, float acc)
{
	//�����x�̉e����K�x�ɗ^����
	*(speed) += acc;

	//���x�̉e�������W�ɗ^����
	*(pos) += *(speed);
}

//�ړ������֐��i2�����j
void Move(Point* pos, Vector* speed, Vector acc)
{
	//�����x�̉e����K�x�ɗ^����
	*(speed) = Add_Vector_Vector(*(speed), acc);

	//���x�̉e�������W�ɗ^����
	*(pos) = Add_Point_Vector(*(pos), *(speed));
}

//�ړ������i���C����j
void Move(float* pos, float* speed, float acc, float fri)
{
	//�����x�̉e����K�x�ɗ^����
	*(speed) += acc;

	//���x�ɖ��C�̉e����^����
	*(speed) *= fri;

	//���x�̉e�������W�ɗ^����
	*(pos) += *(speed);
}