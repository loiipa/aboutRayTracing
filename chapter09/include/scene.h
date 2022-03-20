#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

// 캔버스 생성자
t_canvas	canvas(int width, int height);

// 카메라 생성자
t_camera	camera(t_canvas *canvas, t_point3 orig);

t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

#endif
