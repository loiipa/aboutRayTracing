#include "trace.h"

//ray 생성자(정규화 된 ray)
t_ray	ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = dir;
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

// primary_ray 생성자
t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;
	double	x;
	double	y;
	double	z;

	ray.orig = cam->orig;
	// (left_bottom + u * horizontal + v * vertical) - origin의 단위 벡터
	// vunit( (cam->left_bottom + cam->horizontal * u + cam->vertical * v) - origin )
	// 쉽게 말하면 내 눈~화면까지의 단위벡터인듯
	x = cam->left_bottom.x + cam->horizontal.x * u - cam->orig.x;
	y = cam->left_bottom.y + cam->vertical.y * v - cam->orig.y;
	z = cam->left_bottom.z - cam->orig.z;
	ray.dir = vunit(vec3(x, y, z));
	return (ray);
}
t_color3	ray_color(t_ray *r)
{
	double	t;
	// y의 값에 따라 색이 변함   -1 <= r->dir.y <= 1
	t = 0.5 * (r->dir.y + 1.0);
	return ( vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)) );
}


