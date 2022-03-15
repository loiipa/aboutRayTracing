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

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));

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
			pixel_color = ray_color(&ray);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
