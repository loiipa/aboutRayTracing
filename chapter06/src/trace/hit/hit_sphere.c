#include "structures.h"
#include "utils.h"
#include "trace.h"

// 만나면 true 아니면 false
// b-> half b로 변경
t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3	ac;

	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

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
