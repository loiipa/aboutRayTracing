#include "trace.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	//v - 2 * dot(v, n) * n? 부호 반대 아닌가..
	return (vminus(v, vmult(n, vdot(v, n) * 2)));

}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	double		kd;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	double		ksn;
	double		ks;

	// 교점에서 출발하여 광원을 향하는 벡터(정규화 됨)
	light_dir = vunit( vminus(light->origin, scene->rec.p) );
	// cosΘ는 Θ 값이 90도 일 때 0이고, Θ가 둔각이 되면 음수가 되므로 0.0보다 작은 경우는 0.0으로 대체
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diffuse = vmult(light->light_color, kd);

	view_dir = vunit(vminus(light->origin, scene->rec.p));
	reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
	ksn = 64;
	ks = 0.5;
	// spec ->(빛이 들어오는 비율)^64
	// 뭔가 정규 분포도 같이 빛을 퍼뜨리는 역할을 하는 듯.
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
	//specular -> 원래 색깔에 spec을 적용?
	specular = vmult(vmult(light->light_color, ks), spec);

	return (vplus(diffuse, specular));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT_POINT)
			light_color = vplus(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	// 모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 괍해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}
