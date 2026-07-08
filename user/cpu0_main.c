/*********************************************************************************************************************
* TC264 Opensourec Library 閿熸枻鎷烽敓鏂ゆ嫹TC264 閿熸枻鎷锋簮閿熻В锛夐敓鏂ゆ嫹涓�閿熸枻鎷烽敓鏂ゆ嫹閿熻妭瀹樺嚖鎷� SDK 閿熸帴鍙ｇ殑纰夋嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷锋簮閿熸枻鎷�
* Copyright (c) 2022 SEEKFREE 閿熸枻鎷风吔钀嶉敓锟�
*
* 閿熸枻鎷烽敓渚ョ》鎷烽敓鏂ゆ嫹 TC264 閿熸枻鎷锋簮閿熸枻鎷烽敓鎻紮鎷烽敓鏂ゆ嫹閿燂拷
*
* TC264 閿熸枻鎷锋簮閿熸枻鎷� 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿燂拷
* 閿熸枻鎷烽敓鏂ゆ嫹閿熺殕闈╂嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷峰脖顫嫹閿熸枻鎷烽敓锟� GPL閿熸枻鎷稧NU General Public License閿熸枻鎷烽敓鏂ゆ嫹 GNU閫氶敓鐭櫢鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹璇侀敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷�
* 閿熸枻鎷� GPL 閿熶茎纰夋嫹3閿熻姤锛堥敓鏂ゆ嫹 GPL3.0閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽�夐敓鏂ゆ嫹妯￠敓鏂ゆ嫹榄忛瓘閿熸枻鎷烽敓鏂ゆ嫹闄屽Ч鎾呮嫹閿熸枻鎷烽敓鏂ゆ嫹璺敓鏂ゆ嫹閿熸枻鎷烽敓锟�/閿熸枻鎷烽敓鐫潻鎷烽敓鏂ゆ嫹
*
* 閿熸枻鎷烽敓鏂ゆ嫹婧愰敓鏂ゆ嫹濮嗛敓鏂ゆ嫹閿熸枻鎷烽敓杈冿綇鎷烽敓鏂ゆ嫹閿熸枻鎷疯妸閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷疯尗閿熸枻鎷烽敓鏂ゆ嫹閿熻娇杈炬嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽瓘钄氳皨閿熻锟�
* 閿熸枻鎷烽敓鏂ゆ嫹娌￠敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鐨嗕紮鎷烽敓缁炵尨鎷烽敓鎴鎷烽敓鏂ゆ嫹閫旈敓渚ユ唻鎷疯瘉
* 閿熸枻鎷烽敓鏂ゆ嫹缁嗛敓鏂ゆ嫹閿熸枻鎷锋腑閿燂拷 GPL
*
* 閿熸枻鎷峰簲閿熸枻鎷烽敓鏂ゆ嫹閿熺Ц纰夋嫹閿熸枻鎷烽敓鏂ゆ嫹婧愰敓鏂ゆ嫹閿熼叺顑ユ唻鎷风洀閿熸彮浼欐嫹閿燂拷 GPL 閿熶茎闈╂嫹閿熸枻鎷�
* 閿熸枻鎷烽敓鐭紮鎷锋牎閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷�<https://www.gnu.org/licenses/>
*
* 閿熸枻鎷烽敓鏂ゆ嫹娉ㄩ敓鏂ゆ嫹閿熸枻鎷�
* 閿熸枻鎷烽敓鏂ゆ嫹婧愰敓鏂ゆ嫹浣块敓鏂ゆ嫹 GPL3.0 閿熸枻鎷锋簮閿熸枻鎷烽敓鏂ゆ嫹璇佸崗閿熸枻鎷� 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹涓洪敓鏂ゆ嫹閿熶茎鐗堟湰
* 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹鑻遍敓渚ュ府鎷烽敓鏂ゆ嫹 libraries/doc 閿熶茎纭锋嫹閿熸枻鎷烽敓閾扮鎷� GPL3_permission_statement.txt 閿熶茎纭锋嫹閿熸枻鎷�
* 閿熸枻鎷烽敓鏂ゆ嫹璇侀敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹 libraries 閿熶茎纭锋嫹閿熸枻鎷烽敓鏂ゆ嫹 閿熸枻鎷烽敓鏂ゆ嫹閿熶茎纭锋嫹閿熸枻鎷烽敓閾扮鎷� LICENSE 閿熶茎纭锋嫹
* 閿熸枻鎷疯繋閿熸枻鎷蜂綅浣块敓鐭鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹 閿熸枻鎷烽敓鐫潻鎷烽敓鏂ゆ嫹閿熸枻鎷锋椂閿熸枻鎷烽敓璇繚閿熸枻鎷烽敓鏂ゆ嫹鐓借悕閿熸枻鎷烽檶閿熼ズ顭掓嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓锟�
*
* 閿熶茎纭锋嫹閿熸枻鎷烽敓鏂ゆ嫹          cpu0_main
* 閿熸枻鎷峰徃閿熸枻鎷烽敓鏂ゆ嫹          閿熺即璁规嫹閿熸枻鎷风吔钀嶉敓鏂ゆ嫹閿熸枻鎷疯柊閿熷壙锟�
* 閿熻姤鏈敓鏂ゆ嫹鎭�          閿熶粙鐪� libraries/doc 閿熶茎纭锋嫹閿熸枻鎷烽敓鏂ゆ嫹 version 閿熶茎纭锋嫹 閿熻姤鏈閿熸枻鎷�
* 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹          ADS v1.10.2
* 閿熸枻鎷烽敓鏂ゆ嫹骞冲彴          TC264D
* 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹          https://seekfree.taobao.com/
*
* 閿熺潾鏀圭》鎷峰綍
* 閿熸枻鎷烽敓鏂ゆ嫹              閿熸枻鎷烽敓鏂ゆ嫹                閿熸枻鎷锋敞
* 2022-09-15       pudding            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"

#define MAX_DUTY            (30)
#pragma section all "cpu0_dsram"

#define OSCILLOSCOPE_CHANNEL_NUM    ( 4 )
seekfree_assistant_oscilloscope_struct oscilloscope_config;

float oscilloscope_buffer[OSCILLOSCOPE_CHANNEL_NUM];

double longitude1=0;
double latitude1=0;

#define IPS200_TYPE     (IPS200_TYPE_SPI)

int temp=0;

#define LED1                        ( P20_9 )



#define WIFI_SSID_TEST          "ChengPura80"
#define WIFI_PASSWORD_TEST      "gan123456"
#define UDP_TARGET_IP           "192.168.43.5"             // 连接目标的 IP
#define UDP_TARGET_PORT         "8086"                      // 连接目标的端口
#define WIFI__LOCAL_PORT        "6666"                      // 本机的端口 0：随机  可设置范围2048-65535  默认 6666

uint8 wifi_spi_test_buffer[] = "this is wifi spi test buffer";
uint8 wifi_spi_get_data_buffer[256];
uint32 data_length = 0;

  int core0_main(void)
{
    clock_init();
    debug_init();

    gpio_init(MOTOR_KEY,GPI,GPIO_HIGH,GPI_PULL_UP);
    gpio_init(MODE_KEY,GPI,GPIO_HIGH,GPI_PULL_UP);
    gpio_init(BUZZER,GPO,GPIO_LOW,GPO_PUSH_PULL);
    Param_init();
    Servo_init();                        //舵机初始化
    servo_pid_init();                    //舵机pid参数初始化
    small_driver_uart_init();            //电机串口传输初始化
    PID_Init(&motor_pid,10,0.1,0,0);     //电机闭环PID初始化
    encoder_dir_init(TIM2_ENCODER,TIM2_ENCODER_CH1_P33_7,TIM2_ENCODER_CH2_P33_6);   //编码器初始化

    gnss_init(TAU1201);                  //GPS初始化
    imu660rb_init();                     //陀螺仪初始化
    pit_ms_init(CCU60_CH0,1);            //陀螺仪取数据初始化（1ms）
    pit_ms_init(CCU60_CH1,2);            //任务定时器初始化（2ms）
    pit_ms_init(CCU61_CH0,10);          //编码器采集数据(10ms)


    uint32 motor_key_time = 0;


    /*uint16_t data[128];
    int16_t data_index = 0;
        for( ; 64 > data_index; data_index ++)
            data[data_index] = data_index;
        for(data_index = 64; 128 > data_index; data_index ++)
            data[data_index] = 128 - data_index;*/

        ips200_set_dir(IPS200_PORTAIT);
        ips200_set_color(RGB565_RED, RGB565_BLACK);
        ips200_init(IPS200_TYPE);

//--------------------------------------------------------------------------------------------
        // 设置逐飞助手使用DEBUG串口进行收发
        seekfree_assistant_interface_init(SEEKFREE_ASSISTANT_DEBUG_UART);
        seekfree_assistant_oscilloscope_config(&oscilloscope_config, OSCILLOSCOPE_CHANNEL_NUM, oscilloscope_buffer);

//--------------------------------------------------------------------------------------------
    /*while(wifi_spi_init(WIFI_SSID_TEST, WIFI_PASSWORD_TEST))
        {
            printf("\r\n connect wifi failed. \r\n");
            system_delay_ms(100);                                                   // 初始化失败 等待 100ms
        }

        printf("\r\n module version:%s",wifi_spi_version);                          // 模块固件版本
        printf("\r\n module mac    :%s",wifi_spi_mac_addr);                         // 模块 MAC 信息
        printf("\r\n module ip     :%s",wifi_spi_ip_addr_port);                     // 模块 IP 地址

        // zf_device_wifi_spi.h 文件内的宏定义可以更改模块连接(建立) WIFI 之后，是否自动连接 TCP 服务器、创建 UDP 连接
        if(0 == WIFI_SPI_AUTO_CONNECT)                                              // 如果没有开启自动连接 就需要手动连接目标 IP
        {
            while(wifi_spi_socket_connect(                                          // 向指定目标 IP 的端口建立 UDP 连接
                "UDP",                                                              // 指定使用UDP方式通讯
                UDP_TARGET_IP,                                                      // 指定远端的IP地址，填写上位机的IP地址
                UDP_TARGET_PORT,                                                    // 指定远端的端口号，填写上位机的端口号，通常上位机默认是8080
                WIFI__LOCAL_PORT))                                                  // 指定本机的端口号
            {
                // 如果一直建立失败 考虑一下是不是没有接硬件复位
                printf("\r\n Connect UDP Servers error, try again.");
                system_delay_ms(100);                                               // 建立连接失败 等待 100ms
            }
        }


        // 发送测试数据至服务器
        data_length = wifi_spi_send_buffer(wifi_spi_test_buffer, sizeof(wifi_spi_test_buffer));
        wifi_spi_udp_send_now();
        if(!data_length)
        {
            printf("\r\n send success.");
        }
        else
        {
            printf("\r\n %ld bytes data send failed.", data_length);
        }*/


    cpu_wait_event_ready();

    while (TRUE)
    {
        //读电机按钮
        if(gpio_get_level(MOTOR_KEY) == 0)
        {
            param.speed_pre_flag = 1;
        }

        if(param.speed_pre_flag == 1 && gpio_get_level(MOTOR_KEY))
        {
            if(param.speed_flag == 1)
            {
                param.speed_flag = 0;
            }else if(param.speed_flag == 0)
            {
                param.speed_flag = 1;
            }
            param.speed_pre_flag = 0;
        }

        //读取任务按钮
        if(gpio_get_level(MODE_KEY) == 0)
        {
            param.task_flag = 1;
        }
        if(gpio_get_level(MODE_KEY) && param.task_flag == 1)
       {
            param.task ++;
            if(param.task > 4)
            {
               param.task = 0;
            }
            param.task_flag = 0;
       };



        //float speed_value=0;
        //speed_value = motor_pid_control(motor_pid,motor_value.receive_left_speed_data);
        //small_driver_set_duty(speed_value,0);
        //small_driver_set_duty(1000,0);

        temp = gnss_data_parse();

        //roll_output
        ips200_show_string(0,16*8,"ROLL:");
        ips200_show_float(40,16*8,eulerangle.roll,4,6);
        //yaw_output
        ips200_show_string(0,16*9,"YAW:");
        ips200_show_float(35,16*9,eulerangle.yaw,4,6);
        //clock_output
        ips200_show_string(0,16*5,"SYSTEM_CLOCK:");
        ips200_show_float(110,16*5,time,4,6);
        //distance_output
        ips200_show_string(0,16*6,"DISTANCE:");
        ips200_show_float(75,16*6,init_distance,4,5);
        //speed
        ips200_show_string(0,16*7,"SPEED:");
        ips200_show_float(50,16*7,speed(),4,5);


        ips200_show_float(0,16*1,set_angle_out,4,6);
        ips200_show_float(0 ,16*2,set_turn_true_out,4,6);
        ips200_show_float(0 ,16*3,set_turn_out,4,6);

        ips200_show_int(0,16*4,(int32)encoder_data,6);

        //task_output
        ips200_show_string(75,0,"TASK:");
        switch(param.task)
        {
            case 0: ips200_show_string(125,0,"TASK0");
                break;
            case 1: ips200_show_string(125,0,"TASK1");
                break;
            case 2: ips200_show_string(125,0,"TASK2");
                break;
            case 3: ips200_show_string(125,0,"TASK3");
                break;
            case 4: ips200_show_string(125,0,"TASK4");
                break;
        }

        //gnss_out
        ips200_show_string(0,16*10,"latitude:");
        ips200_show_float(75,16*10,gnss.latitude,4,6);

        ips200_show_string(0,16*11,"longitude");
        ips200_show_float(75,16*11,gnss.longitude,4,6);


       /* data_length = wifi_spi_read_buffer(wifi_spi_get_data_buffer, sizeof(wifi_spi_get_data_buffer));
                if(data_length)                                                         // 如果接收到数据 则进行数据类型判断
                {
                    printf("\r\n Get data: <%s>.", wifi_spi_get_data_buffer);
                    if(!wifi_spi_send_buffer(wifi_spi_get_data_buffer, data_length))
                    {
                        wifi_spi_udp_send_now();
                        printf("\r\n send success.");
                        memset(wifi_spi_get_data_buffer, 0, data_length);          // 数据发送完成 清空数据
                    }
                    else
                    {
                        printf("\r\n %ld bytes data send failed.", data_length);
                    }
                }
                system_delay_ms(100);*/

        oscilloscope_buffer[0] = imu_data.gyro_y;
        oscilloscope_buffer[1] = new_gyro;
        oscilloscope_buffer[2] += 0;
        oscilloscope_buffer[3] += 0;

        seekfree_assistant_oscilloscope_send(&oscilloscope_config);
        system_delay_ms(20);

    }
}

#pragma section all restore
// **************************** 閿熸枻鎷烽敓鏂ゆ嫹閿熸枻鎷烽敓鏂ゆ嫹 ****************************
