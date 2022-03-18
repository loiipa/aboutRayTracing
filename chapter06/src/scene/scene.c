#include "scene.h"

t_camera	camera(t_canvas *canvas, t_point3 orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;
	double		x;
	double		y;
	double		z;

	viewport_height = 2.0;
	focal_len = 1.0;

	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);

	x = 0 - cam.horizontal.x / 2 ;
	y = 0 - cam.vertical.y / 2;
	z = 0 - cam.focal_len;

	cam.left_bottom = point3(x, y, z);
	return (cam);
}
// 좌표가 1,2 정도되는 크기라도 어짜피 pixel을 정해진 크기에서 소숫점 단위로라도 쪼갬.
/*
	t_point3	orig;			// 카메라 원점(위치)
	double		viewport_h;		// 뷰포트 세로길이
	double		viewport_w;		// 뷰포트 가로길이
	t_vec3		horizontal;		// 수평길이 벡터
	t_vec3		vertical;		// 수직길이 벡터
	double		focal_len;		// 초점거리
	t_point3	left_bottom;	// 왼쪽 아래 코너점
*/
