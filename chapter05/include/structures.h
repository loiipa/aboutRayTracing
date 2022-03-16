#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

typedef struct s_ray	t_ray;

typedef struct s_camera	t_camera;

typedef struct s_canvas	t_canvas;

typedef struct s_sphere	t_sphere;

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

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

#endif
