#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "vec3.hpp"

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

//눈의 시선이 구를 만났을 때를 판별
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
		//만나지 않을 경우 false를 반환
		if (root < t_min || t_max < root)
			return false;
	}

	rec.t = root;
	rec.p = r.at(rec.t);
	//외부방향의 법선벡터
	vec3 outward_normal = (rec.p - center) / radius;
	//외부에서 구를 만났을 땐 외부로 향하는 법선벡터, 내부에서 구를 만났을 땐 내부로 향하는 법선벡터.
	rec.set_face_normal(r, outward_normal);

	//법선벡터
	rec.normal = (rec.p - center) / radius;

	return true;
}

#endif
