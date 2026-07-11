/*
 * task.h
 *
 *  Created on: 2026��3��13��
 *      Author: ganbencheng
 */

#ifndef CODE_TASK_H_
#define CODE_TASK_H_

#include "zf_common_headfile.h"
typedef struct
{
        int speed_pre_flag;
        int speed_flag;
        int servo_flag;
        int servo_angle_count;
        int servo_turn_count;
        int servo_turn_add_count;
        int task2_turn_flag;
        int task_flag;
        int task;

} Data_Param;


extern float turn_angle;  //decide where the bike turn to

extern float first_line_distence;// the length is meter
extern float first_begin_latitude;
extern float first_begin_longitude;
extern int turn1_success;
extern float first_turn_circle; //the half length of the circle meters


extern Data_Param param;
extern float set_gyro_out;
extern float set_angle_out;
extern float set_turn_out;
extern float set_turn_true_out;
extern uint32 miniseconds;
extern float time;
extern float init_distance;
extern float WHEEL_CIRCUMFERENCE_M; //circle length of the wheel
extern float gyro_rate;

extern float new_gyro;
extern float change_yaw;

extern double grass_latitude; //the latitude of the grass
extern double grass_longitude; //the longitude of the grass

void Task_doing(void);
void Param_init(void);
float distance_calculate(uint32_t miniseconds, uint8_t reset);
void detect_line_first_turn1(void);
void detect_line_first_turn2(float lastdistence);
void detect_line_first_turn2_3(float lastdistence);
void task_2_route_set(void);
void task_3_route_set(void);
void task1_servo(void);
void task2_servo(void);
void task3_servo(void);
void BUZZER_DO(void);
float speed_2(void);
void speed_add(float speed);

#endif /* CODE_TASK_H_ */
