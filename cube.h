#ifndef CUBE_H
#define CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "/home/aimane-jadid/Desktop/minilibx-linux/mlx.h"

#define HIGHT 500
#define WIDTH 500
#define M_PI 3.14159265358979323846

typedef struct t_image{
    void *img_ptr;
    char *addr;
    int bpp;
    int line_len;
    int endian;
}t_image;

typedef struct s_plater{
    int posx;
    int posy;
}t_player;

typedef struct s_test{
    void *mlx;
    void *window;
    t_image img;
    t_player player;
}t_cube;

void triangle(t_cube *cube,int rat);
void player_rays(t_cube *cube, int rat);

#endif