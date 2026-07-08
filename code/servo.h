/*
 * servo.h
 *
 *  Created on: 2026Äê3ÔÂ3ÈÕ
 *      Author: ganbencheng
 */

#ifndef CODE_SERVO_H_
#define CODE_SERVO_H

typedef struct
{
        float gyro_kp;
        float gyro_ki;
        float gyro_kd;
        float gyro_integral;
        float gyro_prev_error;
        float set_gyro;

        float angle_kp;
        float angle_ki;
        float angle_kd;
        float angle_integral;
        float angle_prev_error;
        float set_angle;

        float turn_kp;
        float turn_ki;
        float turn_kd;
        float turn_integral;
        float turn_prev_error;
        float set_turn;
}Servo_param;

extern Servo_param servo_param;
extern Servo_param servo2_param;
extern Servo_param servo3_param;

void Servo_control(float Angle);
void Servo_init(void);
float gyro_circle_conetrol(Servo_param *PID,float now_gyro);
float angle_circle_conetrol(Servo_param *PID,float now_roll);
void servo_pid_init(void);
float turn_circle_control(Servo_param *PID,float now_yaw);
float servo_gyro_filter(float raw, float *filtered, float alpha);
void servo_pid_change(void);

#endif /* CODE_SERVO_H_ */
