/*
 * key.h
 *
 *  Created on: 2026年6月25日
 *      Author: ganbencheng
 */

#ifndef CODE_KEY_H_
#define CODE_KEY_H_

typedef struct {
    int current_state;   // 当前稳定状态（0/1）
    int last_read;       // 上次读取的原始电平
    int debounce_cnt;   // 消抖计时计数器
    int stable_state;    // 稳定后的状态（供外部读取）
} Button_t;

extern Button_t motor_key;


int Key_Scan(Button_t *btn, int raw_level);



#endif /* CODE_KEY_H_ */
