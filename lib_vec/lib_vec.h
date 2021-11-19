#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct s_vec2
{
	float				x;
	float				y;
}						t_vec2;

typedef struct s_ivec3
{
	int					x;
	int					y;
	int					z;
}						t_ivec3;

typedef struct s_ivec2
{
	int					x;
	int					y;
}						t_ivec2;

float	lerp(float a, float b, float f);
t_vec3	vec_interpolate(t_vec3 a, t_vec3 b, float f);
void	vec2_normalize(t_vec2 *vec);
void	vec_normalize(t_vec3 *vec);
float	vec_length(t_vec3 vec);
float	vec2_length(t_vec2 vec);
float	vec_dot(t_vec3 ve1, t_vec3 ve2);
int		vec_cmp(t_vec3 ve1, t_vec3 ve2);
void	vec2_avg(t_vec2 *res, t_vec2 ve1, t_vec2 ve2);
void	vec_avg(t_vec3 *res, t_vec3 ve1, t_vec3 ve2);
void	vec2_add(t_vec2 *res, t_vec2 ve1, t_vec2 ve2);
void	vec2_mult(t_vec2 *res, float mult);
void	vec_add(t_vec3 *res, t_vec3 ve1, t_vec3 ve2);
void	vec2_sub(t_vec2 *res, t_vec2 ve1, t_vec2 ve2);
void	vec_sub(t_vec3 *res, t_vec3 ve1, t_vec3 ve2);
void	vec_cross(t_vec3 *res, t_vec3 u, t_vec3 v);
void	vec_rot(t_vec3 *res, t_vec3 ve1, float ang);
float	vec_angle(t_vec3 v1, t_vec3 v2);
void	vec_mult(t_vec3 *res, float mult);
void	vec_div(t_vec3 *res, float div);

#endif
