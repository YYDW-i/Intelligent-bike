#ifndef CODE_MOTOR_H_
#define CODE_MOTOR_H_

#include "zf_common_headfile.h"


#define SMALL_DRIVER_UART                       (UART_2        )

#define SMALL_DRIVER_BAUDRATE                   (460800        )

#define SMALL_DRIVER_RX                         (UART2_TX_P10_5)

#define SMALL_DRIVER_TX                         (UART2_RX_P10_6)

typedef struct
{
    uint8 send_data_buffer[7];                  // 发送缓冲数组

    uint8 receive_data_buffer[7];               // 接收缓冲数组

    uint8 receive_data_count;                   // 接收计数

    uint8 sum_check_data;                       // 校验位

    int16 receive_left_speed_data;              // 接收到的左侧电机速度数据

    int16 receive_right_speed_data;             // 接收到的右侧电机速度数据

}small_device_value_struct;

extern small_device_value_struct motor_value;


typedef struct
{
    float Kp;       // 比例系数
    float Ki;       // 积分系数
    float Kd;       // 微分系数
    float set_speed; // 设定值
    float integral; // 积分项
    float prev_error; // 上一次误差
} PID_Controller;

extern PID_Controller motor_pid;
extern int16 encoder_data;
extern float true_speed;

void uart_control_callback(void);                                   // 无刷驱动 串口接收回调函数

void small_driver_set_duty(int16 left_duty, int16 right_duty);      // 无刷驱动 设置电机占空比

void small_driver_get_speed(void);                                  // 无刷驱动 获取速度信息

void small_driver_uart_init(void);   // 无刷驱动 串口通讯初始化

void driver_speed_set(float speed);     //设置电机速度


float motor_pid_control(PID_Controller *pid,float now_speed);        //电机PID闭环控制函数

void PID_Init(PID_Controller *pid,float kp,float ki,float kd,float setspeed);  //电机初始化函数

float speed_calculate(void);  //编码器速度计算

float speed(void);


#endif /* CODE_MOTOR_H_ */
