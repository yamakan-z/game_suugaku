#include <stdio.h>
#include <conio.h>
#include "ヘッダー1.h"

void Move(float* pos, float* speed, float acc);

int main()
{

	//printf("1mm->%f\n", MM(1.0f));
	//printf("1cm->%f\n", CM(1.0f));
	//printf("1m->%f\n", M(1.0f));
	//printf("1km->%f\n", KM(1.0f));

	//速度を算出
	//30/sを30/fにする。
	//float speed = M(30.0f) / SECOND(1.0f);
	//printf("30/s->%f\n", speed);
	printf("30/s->%f\n", M_S(30.0f));
	printf("60km/h-> %f\n", KM_H(60.0f));

	//加速度を算出
	//float acceleration = M(3.6f) / (SECOND(1.0f) * SECOND(1.0f));
	//printf("3.6m/s^2→%f\n", acceleration);

	printf("3.6m/s^2→%f\n", M_S2(3.6f));


	//移動処理を120フレーム呼び出した処理のプログラム例
	//for文で、120回繰り返して再現

	float pos = 0.0f;//位置
	float speed = M_S(30.0f);//加速度（30ｍ/ｓ）
	float acc = M_S2(2.0f);//加速度（2m/s^s)

	//2秒間移動処理を行う
	for (int h = 0;h < SECOND(2);++h) {

		//移動前の情報
		printf("%f秒:座標%f 速度%f→", (float)h / SECOND(1.0f), pos, speed);

		//移動処理
		Move(&pos, &speed, acc);

		//移動後の情報
		printf("座標:%f 速度%f \n", pos, speed);

	
	}
	
	_getch();

	return 0;

}

