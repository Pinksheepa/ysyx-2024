#include <am.h>
#include <nemu.h>

void __am_timer_init()
{
  // 初始化定时器，不需要特殊处理
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime)
{
  // 从RTC_ADDR读取系统启动后经过的微秒数
  // 通常分为低32位和高32位
  uint32_t lo = inl(RTC_ADDR + 0); // 低32位
  uint32_t hi = inl(RTC_ADDR + 4); // 高32位

  // 合并为64位的微秒计数
  uptime->us = ((uint64_t)hi << 32) | lo;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc)
{
  // 设置一个默认的实时时钟时间
  // 在实际系统中，可能需要从硬件RTC读取
  rtc->year = 2023;
  rtc->month = 1;
  rtc->day = 1;
  rtc->hour = 0;
  rtc->minute = 0;
  rtc->second = 0;
}
