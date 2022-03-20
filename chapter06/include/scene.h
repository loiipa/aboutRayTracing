#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

// 캔버스 생성자
t_canvas	canvas(int width, int height);

// 카메라 생성자
t_camera	camera(t_canvas *canvas, t_point3 orig);

t_sphere	sphere(t_point3 center, double radius);

#endif
