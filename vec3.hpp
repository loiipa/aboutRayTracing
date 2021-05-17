#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3
{

	public:
		//인자값을 아무것도 넣지 않은 경우 0,0,0으로 초기화
		//생성자를 인자로 바로 초기화하는 방법을 모르겠음.
		vec3()
		{
			e[0] = 0;
			e[1] = 0;
			e[2] = 0;
		}
		//인자값을 넣었을 경우 e1,e2,e3로 초기화
		vec3(double e0, double e1, double e2)
		{
			e[0] = e0;
			e[1] = e1;
			e[2] = e2;
		}

		//x,y,z 함수를 불러들었을때 각각의 값을 리턴함.
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }

		//-vec인 경우
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		//배열일 경우 그 순서에 해당하는 값을 리턴 (0~2 범위를 초과할 경우는 어떤지 모르겠음)
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; }

		//vec1 += vec2 같은 경우
		vec3& operator+=(const vec3 &v)
		{
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		//vec1 *= vec2 같은 경우
		vec3& operator*=(const double t)
		{
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		//vec1 /= vec2 인 경우, *=을 이용하여 리턴
		vec3& operator/=(const double t) { return *this *= 1/t; }
		//vec의 벡터 길이 = sqrt(a^2 + b^2 + c^2)
		double length() const { return sqrt(length_sqared()); }
		double length_sqared() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];}

	//e[3] 선언
	public:
		double e[3];

};

using point3 = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v)
{
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v)
{
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t)
{
	return t * v;
}

inline vec3 operator/(vec3 v, double t)
{
	return (1 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v)
{
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], \
				u.e[2] * u.e[0] - u.e[0] * v.e[2], \
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

#endif
