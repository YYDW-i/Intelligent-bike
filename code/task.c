#include "zf_common_headfile.h"

#define task_one       1
#define task_two       2
#define task_three     3
#define task_four      4


int task2 = 0;
int task3 = 0;

int buzzer_count =0;
int buzzer_flag = 0;

int16 set_newspeed =0;
float set_gyro_out = 0;
float set_angle_out = 0;
float set_turn_out = 0;
float set_turn_true_out = 0;

float new_gyro = 0;
float now_distance = 0;

Data_Param param;
float gyro_out_max = 45;
float gyro_out_min = -45;

float first_line_distence=15.0;// the length is meter
float first_begin_latitude=-1;
float first_begin_longitude=-1;
int turn1_success=0;
float first_turn_circle = 6.5;//3;//2.462; //the half length of the circle meters
float turn_angle=0.0;
float last_distance = 0;
int change_flag = 0;

int gnssflag = 0;
uint32 miniseconds=0;
float time = 0;
float init_distance=0;
float WHEEL_CIRCUMFERENCE_M=0.24; //circle length of the wheel
float change_yaw = 0.0f;

double s_latitude = 0;    //锟缴硷拷锟侥碉拷一锟斤拷锥桶锟斤拷锟斤拷锟斤拷
double s_longitude = 0;

double grass_latitude = 39.72683; //the latitude of the grass
double grass_longitude = 116.163574; //the longitude of the grass

void Task_doing()  //锟斤拷时锟斤拷锟叫断猴拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷执锟叫ｏ拷2ms
{
    //gnss_main_round(0,0);
    miniseconds += 2;
    time += 0.002;
    distance_calculate(miniseconds,0);
    // 锟斤拷锟斤拷锟斤拷锟侥ｏ拷锟�
    if(param.speed_flag)
    {
        set_newspeed = (int16)motor_pid_control(&motor_pid,(float)encoder_data);
            if(set_newspeed > 7000)
                {
                    set_newspeed = 7000;
                }else if(set_newspeed < -7000){
                    set_newspeed = -7000;
                }
            driver_speed_set(set_newspeed);
    }else{
        driver_speed_set(0);
    }

    //锟斤拷目一锟斤拷锟斤拷
    if(param.task == task_one)
    {

        if(param.speed_flag)
    {
        motor_pid.set_speed = -400;
    }

    task1_servo();

    if(turn1_success == 0)
    {
        detect_line_first_turn1();
    }   else if(turn1_success == 1)
    {
        detect_line_first_turn2(last_distance);
    }
  }

    //锟斤拷目锟斤拷锟斤拷锟斤拷
    if(param.task == task_two)
    {
        task2_servo();
        if(param.speed_flag)
        {
         motor_pid.set_speed = speed_2();//-150;//-100;//-150;
        }else{
            motor_pid.set_speed = 0;
        }

        task_2_route_set();
        BUZZER_DO();
    }

    //锟斤拷目锟斤拷锟斤拷锟斤拷
    if(param.task == task_three)
    {
        if(param.speed_flag)
            {
                motor_pid.set_speed = -400;
            }
            servo_pid_change(&servo3_param);
            task3_servo();
            low_pass_gnss();      //gps filter
            if(turn1_success == 0)
            {
                detect_line_first_turn1();
                if((get_two_points_distance(gnss.latitude,gnss.longitude,grass_latitude,grass_longitude) > 1.3) && gnssflag == 0)
                {
                    turn_angle = 0 + 0 * third_grass_getkangle(grass_latitude,grass_longitude);
                }else if(get_two_points_distance(gnss.latitude,gnss.longitude,grass_latitude,grass_longitude) < 1.3)
                {
                    turn_angle = 0;
                    gnssflag = 1;
                }
            }else if(turn1_success == 1)
            {
                detect_line_first_turn2_3(last_distance);
            }
            task_3_route_set();

    }
}




void Param_init(void)
{
    param.speed_flag = 0;
    param.servo_flag = 1;
    param.servo_angle_count = 0;
    param.servo_turn_count = 0;
    param.servo_turn_add_count = 0;
    param.task_flag = 0;
    param.task = 3;
    param.task2_turn_flag = 0;
}

float distance_calculate(uint32_t miniseconds, uint8_t reset)
{
    static uint8_t initialized = 0;
    static uint32_t last_time = 0;
    static float last_speed = 0.0f;

    float current_speed = speed_calculate();

    if (reset)
    {
        initialized = 0;
        last_time = miniseconds;
        last_speed = current_speed;
        init_distance = 0.0f;
        return init_distance;
    }

    if (!initialized)
    {
        initialized = 1;
        last_time = miniseconds;
        last_speed = current_speed;
        init_distance = 0.0f;
        return init_distance;
    }

    uint32_t delta_ms = miniseconds - last_time;

    float delta_t = delta_ms / 1000.0f;   // ms 转 s

    // 锟斤拷锟轿伙拷锟斤拷
    float average_speed = (last_speed + current_speed) / 2.0f;

    // 转/锟斤拷 锟斤拷 锟斤拷 锟斤拷 锟斤拷锟斤拷锟杰筹拷 = 锟斤拷锟斤拷
    init_distance += average_speed * delta_t * WHEEL_CIRCUMFERENCE_M;

    last_time = miniseconds;
    last_speed = current_speed;

    return init_distance;   // 锟斤拷位锟斤拷m
}


void detect_line_first_turn1(void){
    float distence_gnss=-1;
    if(first_begin_latitude!=-1&&first_begin_longitude!=-1){
        distence_gnss=get_two_points_distance(gnss.latitude,gnss.longitude,first_begin_latitude,first_begin_longitude);
    }
    float distence_guandao=init_distance;
    if(distence_guandao > first_line_distence){
        if(distence_gnss == -1||distence_gnss>first_line_distence){
            change_flag = 1;
            turn1_success = 1;
            last_distance = init_distance;
        }
    }
}

//the first subject 's second turn
void detect_line_first_turn2(float lastdistence){

    int turn_flag_1 = 0;
    if((eulerangle.yaw > 160 && eulerangle.yaw <= 180) || (eulerangle.yaw < -160 && eulerangle.yaw > -180))
    {
        turn_flag_1 = 1;
    }

    if(init_distance-lastdistence > first_turn_circle && turn_flag_1 == 1)
    {
        turn_angle = 180;
        change_flag = 0;
        turn1_success=2;
    }
}


void detect_line_first_turn2_3(float lastdistence){

    int turn_flag_1 = 0;
    if((eulerangle.yaw > 160 && eulerangle.yaw <= 180) || (eulerangle.yaw < -160 && eulerangle.yaw > -180))
    {
        turn_flag_1 = 1;
    }

    if(init_distance-lastdistence > first_turn_circle && turn_flag_1 == 1)
    {
        double kk = 0;
        change_flag = 0;
        if(third_subject_getkangle(s_latitude,s_longitude) > 90)
        {
            turn_angle = 180 + kk*(third_subject_getkangle(s_latitude,s_longitude) - 180);
        }else if(third_subject_getkangle(s_latitude,s_longitude) < 90)
        {
            turn_angle = 180 + kk*(third_subject_getkangle(s_latitude,s_longitude) + 180);
        }
    }
    if((eulerangle.yaw > 170 || eulerangle.yaw < -170))
    {
        turn_angle = 180;
        turn1_success = 2;
    }
}

void task_2_route_set(void)
{

    if(task2 == 0 && param.speed_flag)
    {
        turn_angle = 0;
        task2 ++;
    }
    if(task2 == 1 && init_distance > 0.2)
    {
        buzzer_flag = 1;
        turn_angle = 30;
        task2 ++;
    }
    if(task2 == 2 && init_distance > (0.2 + 1.80))
    {
        buzzer_flag = 1;
        turn_angle = -60;
        task2 ++;
    }
    if(task2 == 3 && init_distance > (0.2 + 1.80 + 2.20))
    {
        buzzer_flag = 1;
        param.task2_turn_flag = 1;
        task2 ++;
    }
    if(task2 == 4 && init_distance > (0.2 + 1.80 + 2.20 + 3))
    {
        buzzer_flag = 1;
        param.task2_turn_flag = 0;
        turn_angle = -120;
        task2 ++;
    }
    if(task2 == 5 && init_distance > (0.2 + 1.80 + 2.20 + 3 + 3))
    {
        buzzer_flag = 1;
        turn_angle = 135;
        task2 ++;
    }

}

void task_3_route_set(void)
{
    if(task3 == 0 && turn1_success == 2)
    {
        turn_angle = 180;
        now_distance = init_distance;
        task3 ++;
    }
    if(task3 == 1 && init_distance - now_distance > 1.7)
    {
        turn_angle = -160;
        now_distance = init_distance;
        task3 ++;
    }
    if(task3 == 2 && init_distance - now_distance > 2)
    {
        turn_angle = 160;
        now_distance = init_distance;
        task3 ++;
    }
    if(task3 == 3 && init_distance - now_distance > 2)
    {
        turn_angle = -160;
        now_distance = init_distance;
        task3 ++;
    }
    if(task3 == 4 && init_distance - now_distance > 2)
    {
        turn_angle = -160;
        now_distance = init_distance;
        task3 ++;
    }
}

void task1_servo(void)
{
    //锟斤拷锟狡斤拷锟斤拷锟斤拷
        if(param.servo_flag )
        {
            param.servo_angle_count++;
            param.servo_turn_count++;
            param.servo_turn_add_count++;
            //锟斤拷锟劫度伙拷锟斤拷锟斤拷
            if(imu_data.gyro_y > 230)
            {imu_data.gyro_y = 230;}
            else if(imu_data.gyro_y < -230)
            {
                imu_data.gyro_y = -230;
            }
           new_gyro = servo_gyro_filter(imu_data.gyro_y,&new_gyro,0.08);// 锟斤拷通锟剿诧拷
           set_gyro_out = gyro_circle_conetrol(&servo_param,new_gyro);     //2ms一锟斤拷
           if(set_gyro_out>gyro_out_max)
           {
               set_gyro_out = gyro_out_max;
           }else if(set_gyro_out<gyro_out_min)
           {
               set_gyro_out = gyro_out_min;
           }

           Servo_control((double)set_gyro_out);

           //锟角度伙拷锟斤拷锟斤拷
           if(param.servo_angle_count > 2)  //4ms锟斤拷锟斤拷一锟斤拷
           {
               param.servo_angle_count = 0;
               set_angle_out = angle_circle_conetrol(&servo_param,eulerangle.roll);
               servo_param.set_gyro = set_angle_out;
           }

           //位锟矫伙拷锟斤拷锟斤拷

           if(param.servo_turn_add_count > 4)
           {
               param.servo_turn_add_count = 0;
               if(set_turn_out>set_turn_true_out)
               {
                   set_turn_true_out += 0.4;
               }else if(set_turn_out<set_turn_true_out)
               {
                   set_turn_true_out -= 0.4;
               }else{
                   set_turn_out = set_turn_true_out;
               }
               if(set_turn_true_out>45)
               {
                   set_turn_true_out = 45;
               }else if(set_turn_true_out<-45)
               {
                   set_turn_true_out = -45;
               }

               servo_param.set_angle = set_turn_true_out;

           }

           if(param.servo_turn_count > 15) //30ms执锟斤拷一锟斤拷
           {
               param.servo_turn_count = 0;

               /*//偏锟斤拷锟斤拷转锟斤拷
               if(eulerangle.yaw > 90 && eulerangle.yaw <= 180)
               {
                   change_yaw = eulerangle.yaw - 180;
               }else if(eulerangle.yaw < -90 && eulerangle.yaw >= -180)
               {
                   change_yaw = 180 + eulerangle.yaw;
               }else{
                   change_yaw = eulerangle.yaw;
               }*/

               if(change_flag == 0)
               {
                   set_turn_out = turn_circle_control(&servo_param,eulerangle.yaw);
               }else if(change_flag == 1)
               {
                   set_turn_out = 6.5;//3.5;
               }
           }

        }

        servo_param.set_turn = turn_angle;
}

void task2_servo(void)
{
    //锟斤拷锟狡斤拷锟斤拷锟斤拷
        if(param.servo_flag )
        {
            param.servo_angle_count++;
            param.servo_turn_count++;
            param.servo_turn_add_count++;

           //锟角度伙拷锟斤拷锟斤拷
           if(param.servo_angle_count > 2)  //4ms锟斤拷锟斤拷一锟斤拷
           {
               param.servo_angle_count = 0;
               set_angle_out = angle_circle_conetrol(&servo2_param,eulerangle.roll);
               servo2_param.set_gyro = set_angle_out;
               if(set_angle_out > 75)
               {
                   set_angle_out = 75;
               }else if(set_angle_out < -75)
               {
                   set_angle_out = -75;
               }
               Servo_control((double)set_angle_out);
           }

           //位锟矫伙拷锟斤拷锟斤拷

           if(param.servo_turn_add_count > 5)
           {
               param.servo_turn_add_count = 0;
               if(set_turn_out>set_turn_true_out)
               {
                   set_turn_true_out += 0.1;
               }else if(set_turn_out<set_turn_true_out)
               {
                   set_turn_true_out -= 0.1;
               }else{
                   set_turn_out = set_turn_true_out;
               }
               if(set_turn_true_out>45)
               {
                   set_turn_true_out = 45;
               }else if(set_turn_true_out<-45)
               {
                   set_turn_true_out = -45;
               }

               servo2_param.set_angle = set_turn_true_out;

           }

           if(param.servo_turn_count > 20) //80ms执锟斤拷一锟斤拷
           {
               param.servo_turn_count = 0;
              if(param.task2_turn_flag == 0)
              {
              set_turn_out = turn_circle_control(&servo2_param,eulerangle.yaw);
              }else if(param.task2_turn_flag == 1)
              {
                  set_turn_out = 3.5;//0.5;
              }

           }

        }
        servo2_param.set_turn = turn_angle;
}


void task3_servo(void)
{
    //锟斤拷锟狡斤拷锟斤拷锟斤拷
        if(param.servo_flag )
        {
            param.servo_angle_count++;
            param.servo_turn_count++;
            param.servo_turn_add_count++;
            //锟斤拷锟劫度伙拷锟斤拷锟斤拷
            if(imu_data.gyro_y > 230)
            {imu_data.gyro_y = 230;}
            else if(imu_data.gyro_y < -230)
            {
                imu_data.gyro_y = -230;
            }
           new_gyro = servo_gyro_filter(imu_data.gyro_y,&new_gyro,0.08);// 锟斤拷通锟剿诧拷
           set_gyro_out = gyro_circle_conetrol(&servo3_param,new_gyro);     //2ms一锟斤拷
           if(set_gyro_out>gyro_out_max)
           {
               set_gyro_out = gyro_out_max;
           }else if(set_gyro_out<gyro_out_min)
           {
               set_gyro_out = gyro_out_min;
           }

           Servo_control((double)set_gyro_out);

           //锟角度伙拷锟斤拷锟斤拷
           if(param.servo_angle_count > 2)  //4ms锟斤拷锟斤拷一锟斤拷
           {
               param.servo_angle_count = 0;
               set_angle_out = angle_circle_conetrol(&servo3_param,eulerangle.roll);
               servo3_param.set_gyro = set_angle_out;
           }

           //位锟矫伙拷锟斤拷锟斤拷

           if(param.servo_turn_add_count > 4)
           {
               param.servo_turn_add_count = 0;
               if(set_turn_out>set_turn_true_out)
               {
                   set_turn_true_out += 0.4;
               }else if(set_turn_out<set_turn_true_out)
               {
                   set_turn_true_out -= 0.4;
               }else{
                   set_turn_out = set_turn_true_out;
               }
               if(set_turn_true_out>45)
               {
                   set_turn_true_out = 45;
               }else if(set_turn_true_out<-45)
               {
                   set_turn_true_out = -45;
               }

               servo3_param.set_angle = set_turn_true_out;

           }

           if(param.servo_turn_count > 15) //30ms执锟斤拷一锟斤拷
           {
               param.servo_turn_count = 0;


               if(change_flag == 0)
               {
                   set_turn_out = turn_circle_control(&servo3_param,eulerangle.yaw);
               }else if(change_flag == 1)
               {
                   set_turn_out = 6.5;//3.5;
               }
           }

        }

        servo3_param.set_turn = turn_angle;
}


void BUZZER_DO(void)
{
    if(buzzer_flag == 1)
  {
    buzzer_count ++;
    if(buzzer_count < 80)
    {
        gpio_set_level(BUZZER,GPIO_HIGH);
    }else{
        buzzer_count = 0;
        gpio_set_level(BUZZER,GPIO_LOW);
        buzzer_flag = 0;
    }
  }
}


float speed_2(void)
{
    float angle = 0;
    float speed = 0;
    if(eulerangle.roll > 0)
    {
        angle = eulerangle.roll;
    }else if(eulerangle.roll < 0)
    {
        angle = - eulerangle.roll;
    }

    speed = -150 - 3 * angle;
    return speed;
}






