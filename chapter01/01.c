#include <stdio.h>

int	main(void)
{
	int		i;
	int		j;
	double	r;
	double	g;
	double	b;
	int		canvas_width;
	int		canvas_height;

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
			r = (double)i / (canvas_width - 1);
			g = (double)j / (canvas_height - 1);
			b = 0.25;
			// 255.999인건 의도한 대로 나오기위함인가?
			printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			++i;
		}
		--j;
	}
	return (0);
}
