#include "structures.h"
#include "utils.h"

// 실제 t 값을 구해버리기
double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	ac;

	double	a;
	double	b;
	double	c;
	double	discriminant;

	ac = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2 * vdot(ray->dir, ac);
	c = vdot(ac, ac) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	// a = 1, b = 1, c = 0이면 -1 만족하는거같은데.. 
	if (discriminant < 0)
		return (-1.0);
	else
		return ( (-b -sqrt(discriminant)) /  (2.0 * a) );
}
