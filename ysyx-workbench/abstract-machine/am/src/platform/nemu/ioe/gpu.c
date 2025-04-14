#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init()
{
  int i;
  uint32_t screen_info = inl(VGACTL_ADDR);
  int w = screen_info >> 16;    // 从VGACTL_ADDR高16位获取宽度
  int h = screen_info & 0xffff; // 从VGACTL_ADDR低16位获取高度
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (i = 0; i < w * h; i++)
    fb[i] = i;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  uint32_t screen_info = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T){
      .present = true, .has_accel = false, .width = screen_info >> 16, .height = screen_info & 0xffff, .vmemsz = 0};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl)
{
  uint32_t x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  uint32_t screen_w = inl(VGACTL_ADDR) >> 16;
  uint32_t screen_h = inl(VGACTL_ADDR) & 0xffff;

  // 确保坐标和尺寸在有效范围内
  uint32_t copy_w = (x + w <= screen_w) ? w : screen_w - x;
  uint32_t copy_h = (y + h <= screen_h) ? h : screen_h - y;

  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for (uint32_t j = 0; j < copy_h; j++)
  {
    for (uint32_t i = 0; i < copy_w; i++)
    {
      fb[(y + j) * screen_w + (x + i)] = pixels[j * w + i];
    }
  }

  if (ctl->sync)
  {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status)
{
  status->ready = true;
}
