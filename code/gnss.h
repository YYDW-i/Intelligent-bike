/*
 * gnss.h
 *
 *  Created on: 2026��3��4��
 *      Author: dell
 */

#ifndef CODE_GNSS_H_
#define CODE_GNSS_H_

#include "zf_common_typedef.h"

extern double third_subject_angle;
extern double pre_latitude ;
extern double pre_longitude ;
extern double aa ;

extern double change_gnss_to_duo( double desired_heading);
extern double turn_to(double object_latitude,double object_longitude);
extern double gnss_main_round(double object_latitude,double object_longitude);
extern void surround_left(double object_latitude,double object_longitude);
extern void surround_right(double object_latitude,double object_longitude);
extern void surround_left_second(double object_latitude,double object_longitude);
extern double third_subject_getkangle(double s_latitude,double s_longitude);
extern double third_grass_getkangle(double grass_latitude,double grass_longitude);

#endif /* CODE_GNSS_H_ */
