#ifndef CUBE_H
#define CUBE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/aimane-jadid/Desktop/minilibx-linux/mlx.h"

#define HIGHT 500
#define WIDTH 500

typedef struct t_image{
    void *img_ptr;
    char *addr;
    int bpp;
    int line_len;
    int endian;
}t_image;


typedef struct s_test{
    void *mlx;
    void *window;
    t_image img;
}t_cube;

#endif