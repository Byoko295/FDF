#include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int main(void)
{
    void *mlx;
    void *mlx_win;
    int step;
    int times;

    step = 0;
    times = 15;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    while(times){
        /*change to landscaper */
    mlx_string_put(mlx,mlx_win,500,20+step,0xead0a8,"0");
    mlx_string_put(mlx,mlx_win,500,35+step,0xb69f66,"1");
    mlx_string_put(mlx,mlx_win,500,50+step,0x6b5428,"1");
    mlx_string_put(mlx,mlx_win,500,65+step,0x76552b,"0");
    mlx_string_put(mlx,mlx_win,500,80+step,0x402905,"0");
    step += 60;    
    times--;
    usleep(80000);
}
    sleep(40);
    mlx_destroy_window(mlx, mlx_win);
}


