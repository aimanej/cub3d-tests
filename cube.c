#include "cube.h"


int chimicolor(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

int keyhook(int keysym, void *data)
{
    t_cube *cube = data;
    mlx_destroy_window(cube->mlx, cube->window);
}

void draw_to_img(t_image *img,int x, int y, int color)
{
    char *ptr;

    ptr = img->addr + (img->line_len * y) + (x * (img->bpp / 8));
    *(int *)ptr = color;

}

int main()
{
    t_cube cube;

    cube.mlx = mlx_init();
    cube.window = mlx_new_window(cube.mlx, WIDTH, HIGHT, "WINDOW!");
    int x = WIDTH / 2;
    int y = HIGHT / 4;
    int ratio = 0;
    int drawer = 0;

    cube.img.img_ptr = mlx_new_image(cube.mlx, WIDTH, HIGHT);
    cube.img.addr =  mlx_get_data_addr(cube.img.img_ptr, &(cube.img.bpp), &(cube.img.line_len), &(cube.img.endian));
    while(y < HIGHT - (HIGHT / 4))
    {
        drawer = x - ratio;
        while(drawer <= x + ratio)
        {
            // mlx_pixel_put(cube.mlx, cube.window, drawer, y, chimicolor(224, 33, 5));
            draw_to_img(&(cube.img), drawer, y, chimicolor(224, 33, 5));
            drawer++;
        }
        ratio++;
        y++;
    }
    mlx_put_image_to_window(cube.mlx, cube.window, cube.img.img_ptr, 0, 0);
    mlx_hook(cube.window, 02, (1L<<0), &keyhook, &cube);

    mlx_loop(cube.mlx);

}