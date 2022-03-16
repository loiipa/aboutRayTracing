#include "structures.h"
#include "utils.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray)
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

	return (discriminant > 0);
}
