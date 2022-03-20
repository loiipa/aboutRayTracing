
#include <iostream>

int		main(void)
{
	const int	image_width = 256;
	const int	image_height = 256;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j)
	{
		//std::cerr - 에러로 인식해서 출력하게 만드는 것 같음. cout에는 안담기니 .ppm에는 이런 값이 없는듯.
		//\r : 캐리지 리턴
		//std::flush - endl과 비슷한데, 버퍼를 개행 없이 바로 비우는 역할.
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i)
		{
			auto	r = double(i) / (image_width - 1);
			auto	g = double(j) / (image_height - 1);
			auto	b = 0.25;

			int		ir = static_cast<int>(255.999 * r);
			int		ig = static_cast<int>(255.999 * g);
			int		ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	std::cerr << "\nDone.\n";
}
