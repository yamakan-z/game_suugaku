#pragma once
//「秒」「分」「時」をフレーム数に変換するマクロ

//fps数
#define FPS (60)

//秒
#define SECOND(_sec) ((_sec)*FPS)
//分
#define MINUTE(_min) (SECOND((_min)*60))
//時
#define HOUR(_hour) (MINUTE((_hour)*60))

//距離のマクロ
//m基準の距離マクロ

//mm
#define MM(_mm) (CM(0.1f*(_mm)))
//cm
#define CM(_cm) (M(0.01f*(_cm)))
//m
#define M(_m) (_m)
//km
#define KM(_km) (M(1000.0f*(_km)))

//速度マクロ
//m/s
#define M_S(_speed)  (M(_speed)/SECOND(1.0f))
//km/h
#define KM_H(_speed) (KM(_speed)/HOUR(1.0f))

//加速度のマクロ
#define M_S2(_acc) (M(_acc)/(SECOND(1.0f)*SECOND(1.0f)))