#include "cube.h"

int chimicolor(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

// int keyhook(int keysym, void *data)
// {
//     t_cube *cube = data;
//     mlx_destroy_window(cube->mlx, cube->window);
// }

void draw_to_img(t_image *img, int x, int y, int color)
{
    char *ptr;

    ptr = img->addr + (img->line_len * y) + (x * (img->bpp / 8));
    *(int *)ptr = color;
}

int movehook(int keysim, void *data)
{
    static int rat;
    t_cube *cube = (t_cube *)data;

    if (keysim = 65363)
    {
        rat += 20;
        mlx_destroy_image(cube->mlx, cube->img.img_ptr);
        // triangle(data, rat);
        player_rays(cube, 0);
        mlx_put_image_to_window(cube->mlx, cube->window, cube->img.img_ptr, 0, 0);
    }
}

void player_rays(t_cube *cube, int fov)
{

    cube->img.img_ptr = mlx_new_image(cube->mlx, WIDTH, HIGHT);
    cube->img.addr = mlx_get_data_addr(cube->img.img_ptr, &(cube->img.bpp), &(cube->img.line_len), &(cube->img.endian));
    int x = cube->player.posx;
    int y = cube->player.posy;
    draw_to_img(&(cube->img), x , y, chimicolor(224, 33, 5));

    double angle = 90;
    int rays = 100;
    double angle_rad = (angle * M_PI) / 180;
    double ffov = (fov * M_PI) / 180;
    double startangle = angle_rad - (ffov / 2);
    double endangle = angle_rad + (ffov / 2);
    double angletep = ffov / rays;
    
    // int fov = 60;
    for(int t = 0; t < rays ; t++)
    {
        double currang = startangle + t * angletep;
        double rayx = cos(currang);
        double rayy = sin(currang);
        
        int p = 0;
        while(p < 100)
        {
            double nextx = x + rayx * p;
            double nexty = y - rayy * p;
            

            draw_to_img(&(cube->img), nextx , nexty, chimicolor(224, 33, 5));
            p++;
        }
    }
}

void triangle(t_cube *cube,int rat)
{

    cube->img.img_ptr = mlx_new_image(cube->mlx, WIDTH, HIGHT);
    cube->img.addr = mlx_get_data_addr(cube->img.img_ptr, &(cube->img.bpp), &(cube->img.line_len), &(cube->img.endian));
    int x = WIDTH / 2 + rat;
    int y = HIGHT / 4 - rat;
    int ratio = 0;
    int drawer = 0;
    while (y < HIGHT - (HIGHT / 4))
    {
        drawer = x - ratio;
        while (drawer <= x + ratio)
        {
            // mlx_pixel_put(cube.mlx, cube.window, drawer, y, chimicolor(224, 33, 5));
            draw_to_img(&(cube->img), drawer, y, chimicolor(224, 33, 5));
            drawer++;
        }
        ratio++;
        y++;
    }
}

int main()
{
    t_cube cube;

    cube.mlx = mlx_init();
    cube.window = mlx_new_window(cube.mlx, WIDTH, HIGHT, "WINDOW!");
    cube.player.posx = 150;
    cube.player.posy = 150;

    // cube.img.img_ptr = mlx_new_image(cube.mlx, WIDTH, HIGHT);
    // cube.img.addr = mlx_get_data_addr(cube.img.img_ptr, &(cube.img.bpp), &(cube.img.line_len), &(cube.img.endian));

    // triangle(&cube, 0);
    player_rays(&cube, 70);
    // mlx_hook(cube.window, 02, (1L<<0), &keyhook, &cube);
        mlx_put_image_to_window(cube.mlx, cube.window, cube.img.img_ptr, 0, 0);

    // printf("we out here\n\n");
    // mlx_key_hook(cube.window, &movehook, &cube);
    // mlx_put_image_to_window(cube.mlx, cube.window, cube.img.img_ptr, 0, 0);

    mlx_loop(cube.mlx);
}