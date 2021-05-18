#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926536897932385;

inline double degrees_to_radians(double degrees)
{
	return degrees * pi / 180;
}

#include "ray.hpp"
#include "vec3.hpp"

#endif
