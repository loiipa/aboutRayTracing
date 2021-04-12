#include "color.h"
#include "vec3.h"
#include "ray.h"

#include <iostream>

color	ray_color(const ray& r)
{
	//y값이 달라지면 색도 같이 따라 바뀜. x, z는 상관없음.
	vec3 unit_direction = unit_vector(r.direction());
	//unit_direction.y() -> -1 ~ 1
	//t값을 0 ~ 1로 만들기 위한 작업임.
	//auto t = 0.5 * (unit_direction.y() + 1.0);
	auto t = 0.5 * ((unit_direction.x() + unit_direction.y())/2 + 1.0);
	//t=0 하얀색 -> t=1 blue값이 높은 색상
	//결국 하얀색 ~ 파란색으로 그라데이션이 만들어짐.
	//return (1.0 - t) * color (1.0, 1.0, 1.0) - t * color (0.5, 0.7, 1.0);
	return (1.0 - t) * color (1.0, 1.0, 1.0) + t * color (0.5, 0.7, 1.0);
}

int		main(void)
{
	//카메라 비율, 너비, 높이
	const auto aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = static_cast<int>(image_width / aspect_ratio);

	//화면의 실제 좌표, 화면 비율에 따라 화면 높이와 너비, 원점으로부터의 거리가 정해지면
	//원점을 기준으로 (-w/2, -h/2, -f)만큼 떨어져 있는 곳이 화면 왼쪽하단임을 알 수 있다.
	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	//horizontal - x축, verticla - y축
	auto origin = point3(0, 0, 0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j)
	{
		 std::cerr << "\rScanlines remaniing: " << j << ' ' << std::flush;
		 for (int i = 0; i < image_width; ++i)
		 {
			//예전에는 화면 좌표와 색상의 rgb값 중 일부가 동일했지만, 지금은 비율로 바뀜.
		 	auto u = double(i) / (image_width - 1);
		 	auto v = double(j) / (image_height - 1);
			//ray -> (원점, 벡터) -> 결국 해당 화면픽셀의 좌표값임.
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			//해당좌표에 무슨 색인지 알려줌 -> y값에 따라서 색상이 달라지는 함수임 지금은.
			color pixel_color = ray_color(r);
		 	write_color(std::cout, pixel_color);
		 }
	}
	std::cerr << "\nDone.\n";
}
