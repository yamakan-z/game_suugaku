#include "orizin1.h"
#include "orizin2.h"
#include <stdio.h>
#include<math.h>
#include <conio.h>

//二次元の移動処理
//45°の方向に2秒間移動した場合の処理
//初速度 30m/s 加速度 2m/s^s
int main()
{
	//初期化
	Point pos;
	pos.x = 0.0f;
	pos.y = 0.0f;

	Vector speed; //初速度(30m/s)
	speed.x = 1.0f;
	speed.y = 1.0f;
	speed = Vector_SetLenght(speed, M_S(30.0f));

	Vector acc;  //加速度(2m/s^s)
	acc.x = 1.0f;
	acc.y = 1.0f;
	acc = Vector_SetLenght(acc, M_S2(2.0f));


	//2秒間移動処理を行う
	for (int h = 0;h < SECOND(2);h++)
	{
		//移動前
		printf("%.2f秒：座標(%.2f.%.2f)速度(%.2f.%.2f)->",
			(float)h / SECOND(1.0f),
			pos.x, pos.y,
			speed.x, speed.y
		);
		//移動処理
		Move(&pos, &speed, acc);

		//移動後
		printf("座標(%.2f,%.2f)速度(%.2f,%.2f)\n",
			pos.x, pos.y,
			speed.x, speed.y);
		
	}
	_getch();
	return 0;
}