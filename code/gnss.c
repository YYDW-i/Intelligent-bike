#include "zf_common_headfile.h"
#define AVOID_ANGLE  15

double dir=0;  //take as the duo jiao
double third_subject_angle = 180;   //小车到终点的方向和正北方向的顺时针夹角
double pre_latitude = 0;
double pre_longitude = 0;
double aa = 0.4;

double change_gnss_to_duo(double desired_heading){
    // 1. 閿熸枻鎷烽敓濮愯埅閿熸枻鎷风澘顒婃嫹閿熸彮浼欐嫹閿熸枻鎷烽敓锟� [-180,180]
    double diff = desired_heading - gnss.direction;
    while (diff > 180.0f) diff -= 360.0f;
    while (diff < -180.0f) diff += 360.0f;

    // 2. 鐩撮敓鏂ゆ嫹閿熸枻鎷蜂负杞敓鏂ゆ嫹鐗甸敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋竟鐚存嫹閿熸彮顎额亷鎷烽敓鏂ゆ嫹鎱曞祵榫嬮敓锟�
    double servo_angle = diff;

    // 3. 閿熺潾鍑ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓杞匡拷 [-90,90]
    if (servo_angle > 90.0f) servo_angle = 90.0f;
    if (servo_angle < -90.0f) servo_angle = -90.0f;

    // 4. 骞抽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹杞敓鏂ゆ嫹閿熸枻鎷烽敓缁烇綇鎷烽敓鏂ゆ嫹姝㈤敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
    //double delta = servo_angle - last_servo_angle;
    //if (delta > MAX_STEER_RATE) delta = MAX_STEER_RATE;
    //else if (delta < -MAX_STEER_RATE) delta = -MAX_STEER_RATE;
    //servo_angle = last_servo_angle + delta;
    //last_servo_angle = servo_angle;

    return servo_angle;
}

double turn_to(double object_latitude,double object_longitude){//one time
    double dist = (double)get_two_points_distance(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    if(dist>1){
        return -1;
    }
    double bearing = (double)get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);

    double car_heading=gnss.direction;
    // 4. 閿熸枻鎷烽敓濮愭柟浣嶉敓鏂ゆ嫹閿熻褰撳墠閿熸枻鎷烽敓鏂ゆ嫹鐗熼敓琛楃鎷烽敓鏂ゆ嫹閿熸彮浼欐嫹閿熸枻鎷烽敓锟� [-180, 180]
    double angle_diff = bearing - car_heading;
    while (angle_diff > 180.0f)  angle_diff -= 360.0f;
    while (angle_diff < -180.0f) angle_diff += 360.0f;

    // 5. 閿熸枻鎷烽敓鎹风尨鎷烽敓鏂ゆ嫹鍋忛敓鐙℃拝鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鍙嚖鎷烽敓鏂ゆ嫹
    double target_heading = car_heading;
    if (angle_diff >= 0)   // 閿ユ《閿熸枻鎷烽敓鎻鎷�
    {
        target_heading = car_heading - AVOID_ANGLE;   // 閿熸枻鎷烽敓鏂ゆ嫹杞�
    }
    else if (angle_diff < 0)  // 閿ユ《閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
    {
        target_heading = car_heading + AVOID_ANGLE;   // 閿熸枻鎷烽敓鏂ゆ嫹杞�
    }
    // 閿熸枻鎷蜂竴閿熸枻鎷烽敓鏂ゆ嫹 [0, 360)
    while (target_heading < 0.0f)    target_heading += 360.0f;
    while (target_heading >= 360.0f) target_heading -= 360.0f;

    // 6. 閿熸枻鎷烽敓鏂ゆ嫹閫夐敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹杞敓鏂ゆ嫹閿熸枻鎷烽敓缁烇綇鎷烽敓鏂ゆ嫹閿熸枻鎷风獊閿熸枻鎷�
    //static double last_heading = 0.0f;
    //double delta = target_heading - last_heading;
    //while (delta > 180.0f)  delta -= 360.0f;
    //while (delta < -180.0f) delta += 360.0f;
    //if (delta > MAX_STEER_RATE)
        //delta = MAX_STEER_RATE;
    //else if (delta < -MAX_STEER_RATE)
        //delta = -MAX_STEER_RATE;
    //target_heading = last_heading + delta;
    //last_heading = target_heading;

    return target_heading;
}


double gnss_main_round(double object_latitude,double object_longitude){

    // 閿熸枻鎷烽敓鏂ゆ嫹娆犻敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷疯幐閿熸枻鎷烽敓锟�
    if (gnss_flag)
    {
        // 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹
        if (gnss_data_parse() == 0)   // 閿熸枻鎷烽敓鏂ゆ嫹閿熺即鐧告嫹
        {
            // 閿熷彨鏂鎷蜂綅閿熻鍑ゆ嫹閿熸枻鎷锋晥
            if (gnss.state)
            {
                
                double turn=change_gnss_to_duo(turn_to(object_latitude,object_longitude));

                return turn;
            }
            else
            {
                // 閿熸枻鎷蜂綅閿熸枻鎷锋晥
                zf_log(ZF_FALSE, "GPS no fix");
                return -1;
            }
        }
        else
        {
            // 閿熸枻鎷烽敓鏂ゆ嫹澶遍敓鏉帮綇鎷锋牎閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
            zf_log(ZF_FALSE, "GPS parse error");
            return -1;
        }

    }
    return -1;

    // 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋兇顭掓嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熼ズ鈽呮嫹榫嬮敓鏂ゆ嫹閿熸枻鎷疯嫅閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
}


void surround_left(double object_latitude,double object_longitude){
    double k=gnss_main_round(object_latitude,object_longitude);
    double direction;
    while(k==-1){
        k=gnss_main_round(object_latitude,object_longitude);
        direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    }
    dir=k;
    Servo_control(dir);
    gnss_data_parse();
    double cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    while(abs(cur_direction-direction)>200||abs(cur_direction-direction)<160){

        double distence=get_two_points_distance(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
        if(distence>2){    //plus is to right,minus is to left
            dir+=5;
            Servo_control(dir);
        }else if(distence<1.8){
            dir-=5;
            Servo_control(dir);
        }
        uint8 flag=gnss_data_parse();
        if(flag){
            zf_log(ZF_FALSE, "GPS parse error");
        }
        cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    }
    

}

void surround_right(double object_latitude,double object_longitude){
    gnss_data_parse();
    double cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    double direction=cur_direction;
    Servo_control(-dir);
    do{
        
        double distence=get_two_points_distance(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
        if(distence>2){    //plus is to right,minus is to left
            dir-=5;
            Servo_control(dir);
        }else if(distence<1.8){
            dir+=5;
            Servo_control(dir);
        }
        uint8 flag=gnss_data_parse();
        if(flag){
            zf_log(ZF_FALSE, "GPS parse error");
        }
        cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    }while(abs(cur_direction-direction)>5);
    

}

void surround_left_second(double object_latitude,double object_longitude){
    gnss_data_parse();
    double cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    double direction=cur_direction;
    Servo_control(dir);
    while(abs(cur_direction-direction)>200||abs(cur_direction-direction)<160){

        double distence=get_two_points_distance(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
        if(distence>2){    //plus is to right,minus is to left
            dir+=5;
            Servo_control(dir);
        }else if(distence<1.8){
            dir-=5;
            Servo_control(dir);
        }

        uint8 flag=gnss_data_parse();
        if(flag){
            zf_log(ZF_FALSE, "GPS parse error");
        }
        cur_direction=get_two_points_azimuth(gnss.latitude,gnss.longitude,object_latitude,object_longitude);
    }
    

}

double third_subject_getkangle(double s_latitude,double s_longitude)
{
    double fang=get_two_points_azimuth(gnss.latitude,gnss.longitude,s_latitude,s_longitude);
    if(fang-third_subject_angle>0){
        return fang-third_subject_angle-180;
    }else{
        return fang-third_subject_angle+180;
    }
}

double third_grass_getkangle(double grass_latitude,double grass_longitude)
{
    double fang=get_two_points_azimuth(gnss.latitude,gnss.longitude,grass_latitude,grass_longitude);
    if(fang - third_subject_angle < 180){
        return third_subject_angle-fang;
    }else{
        return 360-(fang-third_subject_angle);
    }
}

// join into the programming.

void low_pass_gnss(void)
{
    //gnss.latitude = (1 - aa) * pre_latitude + aa * gnss.latitude;
    //gnss.longitude = (1 - aa) * pre_longitude + aa * gnss.longitude;

}





