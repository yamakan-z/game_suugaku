#include "orizin1.h"
#include "orizin2.h"
#include <stdio.h>
#include<math.h>
#include <conio.h>

//�񎟌��̈ړ�����
//45���̕�����2�b�Ԉړ������ꍇ�̏���
//�����x 30m/s �����x 2m/s^s
int main()
{
	//������
	Point pos;
	pos.x = 0.0f;
	pos.y = 0.0f;

	Vector speed; //�����x(30m/s)
	speed.x = 1.0f;
	speed.y = 1.0f;
	speed = Vector_SetLenght(speed, M_S(30.0f));

	Vector acc;  //�����x(2m/s^s)
	acc.x = 1.0f;
	acc.y = 1.0f;
	acc = Vector_SetLenght(acc, M_S2(2.0f));


	//2�b�Ԉړ��������s��
	for (int h = 0;h < SECOND(2);h++)
	{
		//�ړ��O
		printf("%.2f�b�F���W(%.2f.%.2f)���x(%.2f.%.2f)->",
			(float)h / SECOND(1.0f),
			pos.x, pos.y,
			speed.x, speed.y
		);
		//�ړ�����
		Move(&pos, &speed, acc);

		//�ړ���
		printf("���W(%.2f,%.2f)���x(%.2f,%.2f)\n",
			pos.x, pos.y,
			speed.x, speed.y);
		
	}
	_getch();
	return 0;
}