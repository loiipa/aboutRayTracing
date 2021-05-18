#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.hpp"

#include <memory>			//shared_ptr
#include <vector>

//스마트 포인터, 여러개의 스마트포인터가 하나의 객체를 같이 소유할 수 있음.
//shared_ptr<A>(x) -> x는 A를 가르킴
//x.use_count() -> shared_ptr의 참조개수가 몇 개인지를 알 수 있음.
using std::shared_ptr;
//생성자의 인자들을 받아서 객체와 shared_ptr의 제어블록까지 한 번에 동적할당 한 후 만들어진 shared_ptr을 리턴함
using std::make_shared;

class hittable_list : public hittable
{
	public:
		hittable_list() {}
		hittable_list(shared_ptr<hittable> object) { add(object); }

		void clear() {objects.clear(); }
		void add(shared_ptr<hittable> object) { objects.push_back(object); }

		virtual bool hit
			(const ray& r, double t_min, double t_max, hit_record& rec) const override;

	public:
		std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
	hit_record temp_rec;
	bool hit_anything = false;
	auto closest_so_far = t_max;

	for (const auto& object : objects)
	{
		if (object->hit(r, t_min, closest_so_far, temp_rec))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}

	return hit_anything;
}




#endif
