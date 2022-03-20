#include "structures.h"
#include "utils.h"
#include "trace.h"

// 만나면 true 아니면 false
// b-> half b로 변경
t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3	ac;

	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_sphere	*sp;

	sp = world->element;

	ac = vminus(ray->orig, sp->center);
	a = vlength2(ray->dir);
	half_b = vdot(ray->dir, ac);
	c = vlength2(ac) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (FALSE);

	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;

	// t의 두개의 값 둘다 내 시아에서 안 보이는 경우는 FALSE
	// 작은값은 보인다 -> 작은값이 t
	// 작은값은 안보이고 큰값이 보인다 -> 큰값이
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}

	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);	// 법선벡터
	set_face_normal(ray, rec);
	return (TRUE);
}
