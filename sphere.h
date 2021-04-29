#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

//hittable 상속
class sphere : public hittable
{
	public:
		sphere () {}
		sphere(point3 cen, double r)
		{
			center = cen;
			radius = r;
		}

		virtual bool hit(
			const ray&r, double t_min, double t_max, hit_record& rec) const override;

	public:
		point3 center;
		double radius;
};

bool sphere::hit(const ray&r, double t_min, double t_max, hit_record& rec) const
{
	vec3 oc = r.origin() - center;
	auto a = r.direction().length_sqared();
	auto half_b = dot(oc, r.direction());
	auto c = oc.length_sqared() - radius * radius;

	auto discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return false;
	auto sqrtd = sqrt(discriminant);

	//우선순위 1: -sqrtd, 2: +sqrtd
	auto root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return false;
	}

	rec.t = root;
	rec.p = r.at(rec.t);
	//법선벡터
	rec.normal = (rec.p - center) / radius;

	return true;
}
