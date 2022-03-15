#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"

int	main(void)
{
	int			i;
	int			j;
	int			canvas_width;
	int			canvas_height;
	t_color3	pixel_color;

	// 캔버스의 크기
	canvas_width = 256;
	canvas_height = 256;

	// ppm 파일 형식에 맞게 세팅
	printf("P3\n");
	printf("%d %d\n", canvas_width, canvas_height);
	printf("255\n");

	j = canvas_height - 1;

	// RGB 매기기
	while (j >= 0)
	{
		i = 0;
		while (i < canvas_width)
		{
			pixel_color.x = (double)i / (canvas_width - 1);
			pixel_color.y = (double)j / (canvas_height - 1);
			pixel_color.z = 0.25;
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
