#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

int	main(void)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;
	t_object	*world;

	// scene setting;
	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));

	// world
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2)));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990)));
	// ppm 파일 형식에 맞게 세팅
	printf("P3\n");
	printf("%d %d\n", canv.width, canv.height);
	printf("255\n");

	j = canv.height - 1;

	// RGB 매기기
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			ray = ray_primary(&cam, u, v);
			// pixel_color = ray_color(&ray);
			pixel_color = ray_color(&ray, world);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
