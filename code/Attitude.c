/*
 * Attitude.c
 *
 *  Created on: 2026年4月8日
 *      Author: ganbencheng
 */
#include "math.h"
#include "zf_common_headfile.h"

float the_time = 0;
#define M_PI 3.1415926
float dt_1 = 0.001;   //设置1ms的数据读取时间


EulerAngle eulerangle;
Raw_data imu_data;
Quaternion qq = {1.0,0.0,0.0,0.0};

float fast_sqrt(float x)
{
    float halfx = 0.5f * x;
    float y = x;
    long i = *(long *) &y;
    i = 0x5f3759df - (i >> 1);  //0x5f3759df是一个平方根倒数速算法
    y = *(float *) &i;
    y = y * (1.5f - (halfx * y * y));
    return y;
}

void change(Raw_data *data)
{
    data->acc_x = ((float)imu660rb_acc_x)/imu660rb_transition_factor[0];     //将加速度数据单位转成g（m/s2）
    data->acc_y = ((float)imu660rb_acc_y)/imu660rb_transition_factor[0];
    data->acc_z = ((float)imu660rb_acc_z)/imu660rb_transition_factor[0];
    data->gyro_x = ((float)imu660rb_gyro_x)/imu660rb_transition_factor[1];     //将角速度数据单位转成 度/s
    data->gyro_y = ((float)imu660rb_gyro_y)/imu660rb_transition_factor[1];
    data->gyro_z = ((float)imu660rb_gyro_z)/imu660rb_transition_factor[1];
}


void angular_velocity_correction(Raw_data *data,float w, float q1, float q2, float q3)
{



    //这个函数用于角速度观测值的互补修正

    // 归一化加速度
    float omega_mag = fast_sqrt(data->acc_x*data->acc_x + data->acc_y*data->acc_y + data->acc_z*data->acc_z);



    float ki = KI;
    float kp = KP;

    float vx = 2*(q1*q3 - w*q2);
    float vy = 2*(q2*q3 + w*q1);
    float vz = 1 - 2*(q1*q1 + q2*q2);
    //在物体坐标系下的加速度分量（只考虑重力影响无惯性力）



    float ex = (data->acc_y*omega_mag)*vz - (data->acc_z*omega_mag)*vy;
    float ey = (data->acc_z*omega_mag)*vx - (data->acc_x*omega_mag)*vz;
    float ez = (data->acc_x*omega_mag)*vy - (data->acc_y*omega_mag)*vx;
    //这个由四元数解算姿态得到的物体坐标系的加速度分量 与 测得的加速度分量叉乘 得出误差矢量（矢量自己叉乘等于自己）



    static float accex = 0;
    static float accey = 0;
    static float accez = 0;



    accex += ki*ex;
    accey += ki*ey;
    accez += ki*ez;
    //加速度误差修正


    data->gyro_x += kp*ex + accex;
    data->gyro_y += kp*ey + accey;
    data->gyro_z += kp*ez + accez;
    //角速度修正


}


// 使用四元数更新姿态
void update_quaternion(Quaternion* q, float gyro_x, float gyro_y, float gyro_z)
{
    //转弧度制
    gyro_x /= (180/M_PI);
    gyro_y /= (180/M_PI);
    gyro_z /= (180/M_PI);



    // 四元数导数
    Quaternion dq;
    dq.w = -0.5f * (q->x*gyro_x + q->y*gyro_y + q->z*gyro_z);
    dq.x =  0.5f * (q->w*gyro_x + q->y*gyro_z - q->z*gyro_y);
    dq.y =  0.5f * (q->w*gyro_y - q->x*gyro_z + q->z*gyro_x);
    dq.z =  0.5f * (q->w*gyro_z + q->x*gyro_y - q->y*gyro_x);

    /*static uint32_t last_timestamp_1 = 0;

    // 获取当前高精度时间戳
    uint32_t current_timestamp_1 = uapi_tcxo_get_us();


    // 计算时间间隔（处理定时器溢出）
    uint32_t delta_ticks_1 = current_timestamp_1 - last_timestamp_1;
    last_timestamp_1 = current_timestamp_1;
    float dt_1 = delta_ticks_1 / 1000000.0f;  // 转换为秒*/




    q->w += dq.w * dt_1;
    q->x += dq.x * dt_1;
    q->y += dq.y * dt_1;
    q->z += dq.z * dt_1;


    // 归一化四元数
    float norm = fast_sqrt(q->w*q->w + q->x*q->x + q->y*q->y + q->z*q->z);
    //if(norm < 0.00001){
        //return ;
    //}
    q->w *= norm;
    q->x *= norm;
    q->y *= norm;
    q->z *= norm;
}

// 四元数转欧拉角
void quaternion_to_euler(Quaternion* q)
{

    // 横滚角 (x轴旋转)
    float sinr_cosp = 2.0f * (q->w * q->x + q->y * q->z);
    float cosr_cosp = 1.0f - 2.0f * (q->x * q->x + q->y * q->y);
    eulerangle.pitch = atan2f(sinr_cosp, cosr_cosp);

    // 俯仰角 (y轴旋转)
    float sinp = 2.0f * (q->w * q->y - q->z * q->x);
    if (fabsf(sinp) >= 1.0f)
        eulerangle.roll = copysignf(M_PI/2.0f, sinp); // 使用90度
    else
        eulerangle.roll = asinf(sinp);

    // 航向角 (z轴旋转)
    float siny_cosp = 2.0f * (q->w * q->z + q->x * q->y);
    float cosy_cosp = 1.0f - 2.0f * (q->y * q->y + q->z * q->z);
    eulerangle.yaw = atan2f(siny_cosp, cosy_cosp);

    // 转换为角度
    eulerangle.roll *= 180.0f / M_PI;
    eulerangle.pitch *= 180.0f / M_PI;
    eulerangle.yaw *= 180.0f / M_PI;

}

void update_imu(void)
{
    change(&imu_data);
    angular_velocity_correction(&imu_data,qq.w,qq.x,qq.y,qq.z);
    update_quaternion(&qq,imu_data.gyro_x,imu_data.gyro_y,imu_data.gyro_z);
    quaternion_to_euler(&qq);
}


