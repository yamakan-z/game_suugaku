#include <stdio.h>
#include <conio.h>
#include "�w�b�_�[1.h"

void Move(float* pos, float* speed, float acc);

int main()
{

	//printf("1mm->%f\n", MM(1.0f));
	//printf("1cm->%f\n", CM(1.0f));
	//printf("1m->%f\n", M(1.0f));
	//printf("1km->%f\n", KM(1.0f));

	//���x���Z�o
	//30/s��30/f�ɂ���B
	//float speed = M(30.0f) / SECOND(1.0f);
	//printf("30/s->%f\n", speed);
	printf("30/s->%f\n", M_S(30.0f));
	printf("60km/h-> %f\n", KM_H(60.0f));

	//�����x���Z�o
	//float acceleration = M(3.6f) / (SECOND(1.0f) * SECOND(1.0f));
	//printf("3.6m/s^2��%f\n", acceleration);

	printf("3.6m/s^2��%f\n", M_S2(3.6f));


	//�ړ�������120�t���[���Ăяo���������̃v���O������
	//for���ŁA120��J��Ԃ��čČ�

	float pos = 0.0f;//�ʒu
	float speed = M_S(30.0f);//�����x�i30��/���j
	float acc = M_S2(2.0f);//�����x�i2m/s^s)

	//2�b�Ԉړ��������s��
	for (int h = 0;h < SECOND(2);++h) {

		//�ړ��O�̏��
		printf("%f�b:���W%f ���x%f��", (float)h / SECOND(1.0f), pos, speed);

		//�ړ�����
		Move(&pos, &speed, acc);

		//�ړ���̏��
		printf("���W:%f ���x%f \n", pos, speed);

	
	}
	
	_getch();

	return 0;

}

