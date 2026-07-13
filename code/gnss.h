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

extern double third_subject_getkangle(double s_latitude,double s_longitude);
extern double third_grass_getkangle(double grass_latitude,double grass_longitude);
void low_pass_gnss(void);

#endif /* CODE_GNSS_H_ */
