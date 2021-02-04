#pragma once
//�u�b�v�u���v�u���v���t���[�����ɕϊ�����}�N��

//fps��
#define FPS (60)

//�b
#define SECOND(_sec) ((_sec)*FPS)
//��
#define MINUTE(_min) (SECOND((_min)*60))
//��
#define HOUR(_hour) (MINUTE((_hour)*60))

//�����̃}�N��
//m��̋����}�N��

//mm
#define MM(_mm) (CM(0.1f*(_mm)))
//cm
#define CM(_cm) (M(0.01f*(_cm)))
//m
#define M(_m) (_m)
//km
#define KM(_km) (M(1000.0f*(_km)))

//���x�}�N��
//m/s
#define M_S(_speed)  (M(_speed)/SECOND(1.0f))
//km/h
#define KM_H(_speed) (KM(_speed)/HOUR(1.0f))

//�����x�̃}�N��
#define M_S2(_acc) (M(_acc)/(SECOND(1.0f)*SECOND(1.0f)))