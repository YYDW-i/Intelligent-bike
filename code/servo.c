#include "zf_common_headfile.h"

#define PWM_CH1            (ATOM1_CH1_P33_9)

#define servo_zero_point   (395)
float Max_angle=50;
float gyro_rate = 0.0f;
uint32 Duty;

Servo_param servo_param;
Servo_param servo2_param;
Servo_param servo3_param;

void Servo_init()
{
    pwm_init(PWM_CH1,50,servo_zero_point+250);
}

void Servo_control(double Angle)
{

    if(Angle>Max_angle)
    {
        Angle=Max_angle;
    }
    else if(Angle<-Max_angle)
    {
        Angle=-Max_angle;
    }

    Duty=(uint32)((Angle)/180*1000+servo_zero_point);
    pwm_set_duty(PWM_CH1,Duty+250);
}

float gyro_circle_conetrol(Servo_param *PID,float now_gyro)       //角速度环
{
    //float dt = 0.002f;

    //float filter_now_gyro = servo_gyro_filter(now_gyro,&gyro_rate,0,dt,20.0f);

    float error =  PID->set_gyro - now_gyro;

    PID->gyro_integral += error;

    float derivative = error - PID->gyro_prev_error;

    PID->gyro_prev_error = error;

    float output = PID->gyro_kp * error + PID->gyro_ki * PID->gyro_integral + PID->gyro_kd * derivative;

    return output;
}

float angle_circle_conetrol(Servo_param *PID,float now_roll)       //角度环
{
    float error =  PID->set_angle - now_roll;

    PID->angle_integral += error;

    float derivative = error - PID->angle_prev_error;

    PID->angle_prev_error = error;

    float output = PID->angle_kp * error + PID->angle_ki * PID->angle_integral + PID->angle_kd * derivative;

    return output;
}

float turn_circle_control(Servo_param *PID,float now_yaw)
{
    float error = PID->set_turn - now_yaw;

    if(error > 180)
    {
        error -= 360 ;
    }else if(error < -180)
    {
        error += 360;
    }

    PID->turn_integral += error;

    float derivative = error - PID->turn_prev_error;

    PID->turn_prev_error = error;

    float output = PID->turn_kp * error + PID->turn_ki * PID->turn_integral + PID->turn_kd * derivative;

    return output;
}

void servo_pid_init(void)         //初始化舵机pid参数
{
    //任务一参数
    servo_param.angle_kp = 3.8;//3;//7.5;//5;//-12;//-15;
    servo_param.angle_ki = 0.01;//-0.05;
    servo_param.angle_kd = 3.2;//-0.4;//0;//1;
    servo_param.angle_integral = 0;
    servo_param.angle_prev_error = 0;
    servo_param.set_angle = 0;

    servo_param.gyro_kp = 0.17;//0.20;//-0.13;//-0.15;//0.15;
    servo_param.gyro_ki = 0;
    servo_param.gyro_kd = 0;
    servo_param.gyro_integral = 0;
    servo_param.gyro_prev_error = 0;
    servo_param.set_gyro = 0;

    servo_param.turn_kp = 0.32;//0.32;//0.33;//0.45;//0.3;//1;//-2;
    servo_param.turn_ki = 0.001;
    servo_param.turn_kd = 1.0;//2.8;//0.4;
    servo_param.turn_integral = 0;
    servo_param.turn_prev_error = 0;
    servo_param.set_turn = 0;

    //任务二参数
    servo2_param.angle_kp = 7;//2.5;//1.5;
    servo2_param.angle_ki = 0.02;//0.02;
    servo2_param.angle_kd = 0;
    servo2_param.angle_integral = 0;
    servo2_param.angle_prev_error = 0;
    servo2_param.set_angle = 0;

    servo2_param.turn_kp = 0.07;//0.07;
    servo2_param.turn_ki = 0.0001;
    servo2_param.turn_kd = 0.4;//0.2;
    servo2_param.turn_integral = 0;
    servo2_param.turn_prev_error = 0;
    servo2_param.set_turn = 0;

    //任务三参数
    servo3_param.angle_kp = 3.8;//7;//3;//7.5;//5;//-12;//-15;
    servo3_param.angle_ki = 0.01;//-0.05;
    servo3_param.angle_kd = 3.2;//1;//1;//-0.4;//0;//1;
    servo3_param.angle_integral = 0;
    servo3_param.angle_prev_error = 0;
    servo3_param.set_angle = 0;

    servo3_param.gyro_kp = 0.17;//0.23;//0.20;//-0.13;//-0.15;//0.15;
    servo3_param.gyro_ki = 0;
    servo3_param.gyro_kd = 0;
    servo3_param.gyro_integral = 0;
    servo3_param.gyro_prev_error = 0;
    servo3_param.set_gyro = 0;

    servo3_param.turn_kp = 0.32;//0.12;//0.33;//0.45;//0.3;//1;//-2;
    servo3_param.turn_ki = 0.001;
    servo3_param.turn_kd = 1.0;//0.5;//0.7;//0.4;
    servo3_param.turn_integral = 0;
    servo3_param.turn_prev_error = 0;
    servo3_param.set_turn = 0;

}


float servo_gyro_filter(float raw, float *filtered, float alpha)
{

    *filtered = alpha * raw + (1.0f - alpha) * (*filtered);
    return *filtered;
}

void servo_pid_change(Servo_param *param)
{
    param->gyro_kp = 0.23 - (-250 - encoder_data)*0.0001;
    //param->angle_kp = 3.5 - (-400-encoder_data)*0.001;
    //param->angle_kd = 3.2 + (-400-encoder_data)*0.001;
}

