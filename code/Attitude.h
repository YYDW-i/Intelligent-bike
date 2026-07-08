/*
 * Attitude.h
 *
 *  Created on: 2026年4月8日
 *      Author: ganbencheng
 */

#ifndef CODE_ATTITUDE_H_
#define CODE_ATTITUDE_H_

#include "zf_common_headfile.h"

#define KI          0.001f
//加速度观测值修正积分系数
#define KP          20.0f
//比例系数KP


// 定义欧拉角结构体
typedef struct {
    float pitch;
    float roll;
    float yaw;
} EulerAngle;

// 四元数结构体
typedef struct {
    float w;
    float x;
    float y;
    float z;
} Quaternion;
// 使用四元数更新姿态

typedef struct
{
    float acc_x,acc_y,acc_z;
    float gyro_x,gyro_y,gyro_z;
} Raw_data;

extern EulerAngle eulerangle;
extern Raw_data imu_data;
extern Quaternion qq;


float fast_sqrt(float x);
void change(Raw_data *data);
void angular_velocity_correction(Raw_data *data,float w, float q1, float q2, float q3);
void update_quaternion(Quaternion* q, float gyro_x, float gyro_y, float gyro_z);
void quaternion_to_euler(Quaternion* q);
void update_imu(void);



#endif /* CODE_ATTITUDE_H_ */
