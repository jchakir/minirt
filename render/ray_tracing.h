/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:06:55 by jchakir           #+#    #+#             */
/*   Updated: 2022/06/09 15:06:09 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include "../linear_algebra/linear_algebra.h"
# include "../includes/miniRT.h"
# include <limits.h>
# include <float.h>
# include <stdbool.h>

# define TRANSPARENCY 200

enum {
	PLANE,
	SPHERE,
	CYLINDER
};

typedef struct s_quadratic {
	double	delta;
	double	a;
	double	b;
	double	c;
	double	x1;
	double	x2;
	double	r;
}	t_quadratic;

void		get_pixel_coord(int x, int y, t_vector *ray, t_data data);

// Rendering geometric forms
t_solution	*plane_rendering(t_data data, t_vector ray, t_point origin);
t_solution	*sphere_rendering(t_data data, t_vector ray, t_point origin);
t_solution	*cylinder_rendering(t_data data, t_vector ray, t_point origin);

// Rendering the shadow of the geometric forms
t_solution	*plane_rendering_shadow(t_data data, t_vector ray,
				t_point origin, t_solution *sol);
t_solution	*sphere_rendering_shadow(t_data data, t_vector ray,
				t_point origin, t_solution *sol);
t_solution	*cylinder_rendering_shadow(t_data data, t_vector ray,
				t_point origin, t_solution *sol);

// Plane utils
double		plane_intersection(t_data data, t_vector ray, t_point origin);
double		plane_ratio(t_data data, t_vector ray, double t);
t_solution	*s_filling_plane(t_data data, t_vector ray, int id, t_point origin);

// Sphere Utils
double		sphere_q4_equation(t_data data, t_vector ray, t_point origin);
double		sphere_ratio(t_data data, t_vector ray, double t);
t_solution	*s_filling_sphere(t_data data, t_vector ray,
				int id, t_point origin);

// Cylinder utils
double		cylinder_q4_equation(t_data data, t_vector ray, t_point origin);
double		cylinder_ratio(t_data data, t_vector ray, double t);
t_solution	*s_filling_cylinder(t_data data, t_vector ray,
				int id, t_point origin);
int			get_solutions(t_data data, t_vector ray,
				t_point origin, t_quadratic *q);
t_point		get_p(t_data data, t_point origin, t_vector ray, double x);

// Ray Tracing Utils
int			create_trgb(int t, t_rgb colors,
				double ratio_color, double ratio_light);
t_solution	*get_min_ll(t_solution *s);
t_solution	*get_min_ll_shadow(t_solution *s, t_solution *sol);
void		transform_cam_world(t_data data);
t_solution	*get_min(t_solution **arrt);
t_solution	*get_min_ll(t_solution *s);
t_solution	*get_min_ll_shadow(t_solution *s, t_solution *sol);
int			shadow_rending(t_data data, t_solution *s, t_vector ray);

#endif