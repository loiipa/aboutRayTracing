#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"

struct hit_record
{
	point3	p;
	vec3	normal;
	double	t;
	bool	front_face;

	//컴파일러에서 함수를 인라인 함수로 처리하도록 요청한다.
	inline void set_face_normal(const ray&r, const vec3& outward_normal)
	{
		//법선벡터와 광선의 내적이 음수인지(외부광선) 양수인지(내부광선)를 front_face에 담음
		front_face = dot(r.direction(), outward_normal) < 0;
		//외부광선이라면 그대로, 내부광선이라면 normal을 내부로 향하는 법선벡터로
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable
{
	public:
		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif
