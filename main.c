/**
 * @file      : main.c
 * @brief     : 程序入口文件
 * @author    : huenrong (huenrong1028@outlook.com)
 * @date      : 2023-02-12 15:39:12
 *
 * @copyright : Copyright (c) 2023 huenrong
 *
 * @history   : date       author          description
 *              2023-02-12 huenrong        创建文件
 *
 */

#include <stdio.h>
#include <unistd.h>

#define LOG_TAG "main"
#include "elog.h"

/**
 * @brief  初始化easy_logger
 */
static void easy_logger_init(void)
{
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, (ELOG_FMT_ALL & ~(ELOG_FMT_P_INFO | ELOG_FMT_T_INFO)));
    elog_set_fmt(ELOG_LVL_WARN, (ELOG_FMT_ALL & ~(ELOG_FMT_P_INFO | ELOG_FMT_T_INFO)));
    elog_set_fmt(ELOG_LVL_INFO, (ELOG_FMT_ALL & ~(ELOG_FMT_P_INFO | ELOG_FMT_T_INFO)));
    elog_set_fmt(ELOG_LVL_DEBUG, (ELOG_FMT_ALL & ~(ELOG_FMT_P_INFO | ELOG_FMT_T_INFO)));
    elog_set_fmt(ELOG_LVL_VERBOSE, (ELOG_FMT_ALL & ~(ELOG_FMT_P_INFO | ELOG_FMT_T_INFO)));
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();
}

/**
 * @brief  : 程序入口
 * @param  : argc: 输入参数, 参数个数
 * @param  : argv: 输入参数, 参数列表
 * @return : 成功: 0
 *           失败: 其它
 */
int main(int argc, char *argv[])
{
    easy_logger_init();

    while (true)
    {
        log_a("Hello EasyLogger!");
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");

        sleep(2);
    }

    return 0;
}
