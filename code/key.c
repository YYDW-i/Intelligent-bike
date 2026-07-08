/*
 * key.c
 *
 *  Created on: 2026年6月25日
 *      Author: ganbencheng
 */
#include "zf_common_headfile.h"

Button_t motor_key = {0,0,0,0};


int Key_Scan(Button_t *btn, int raw_level)
{
    // 如果当前读取的电平和上次不同，重置计数器
    if (raw_level != btn->last_read) {
            btn->debounce_cnt = 0;
            btn->last_read = raw_level;
        }
     else {
            // 电平稳定，开始计数
     if (btn->debounce_cnt < 20) {  // 20次 = 100ms（假设5ms调用一次）
                btn->debounce_cnt++;
            }
            // 计数器达到阈值，认为电平稳定
     if (btn->debounce_cnt == 20) {
                btn->stable_state = raw_level;
            }
        }
      return btn->stable_state;
}









