#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;

typedef struct s_ray		t_ray;

typedef struct s_camera		t_camera;

typedef struct s_canvas		t_canvas;

typedef struct s_sphere		t_sphere;

typedef struct s_hit_record	t_hit_record;

typedef struct s_object		t_object;

typedef struct s_light		t_light;

typedef struct s_scene		t_scene;

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

typedef int	t_object_type;
# define SP 0
# define LIGHT_POINT 1
# define EPSILON 1e-6	// 0.000001
# define LUMEN 3

struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct	s_camera
{
	t_point3	orig;			// 카메라 원점(위치)
	double		viewport_h;		// 뷰포트 세로길이
	double		viewport_w;		// 뷰포트 가로길이
	t_vec3		horizontal;		// 수평길이 벡터
	t_vec3		vertical;		// 수직길이 벡터
	double		focal_len;		// 초점거리
	t_point3	left_bottom;	// 왼쪽 아래 코너점
};

struct	s_canvas
{
	int		width;			// 캔버스 너비
	int		height;			// 캔버스 높이
	double	aspect_ratio;	// 종횡비
};

struct	s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

// 모든 것을 담는 구조체라고 보면 될듯
struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

#endif
