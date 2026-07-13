#include "zf_common_headfile.h"
#define AVOID_ANGLE  15

double dir=0;  //take as the duo jiao
double third_subject_angle = 180;   //小车到终点的方向和正北方向的顺时针夹角
double pre_latitude = 0;
double pre_longitude = 0;
double aa = 0.4;

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





