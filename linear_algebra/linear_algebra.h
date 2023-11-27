/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_algebra.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:52 by jchakir           #+#    #+#             */
/*   Updated: 2022/06/08 22:48:49 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALGEBRA_H
# define LINEAR_ALGEBRA_H

# include "../includes/miniRT.h"

typedef double	t_matrix;

//Vectors
void		normalize(t_vector *vector);
t_vector	get_normalized_vector(t_vector orig);
t_vector	get_reversed_vector(t_vector orig);
double		norm(t_vector vector);
double		norm_p(t_point point);
t_vector	cross_2v(t_vector u, t_vector v);
t_vector	vector_p1_p2(t_point p1, t_point p2);
t_vector	vector_0_p(t_point p);
t_vector	vector_p_0(t_point p);
double		dot_v_v(t_vector v1, t_vector v2);
double		dot_p_p(t_point p1, t_point p2);
double		dot_v_p(t_vector v, t_point p);

//Points
double		norm_0_p(t_point p);
double		norm_0_p_pow_2(t_point p);
double		norm_p1_p2(t_point p1, t_point p2);
void		subtract__point_reference_(t_point *point, t_point reference);
void		add__point_to_reference_(t_point *point, t_point reference);
t_point		scalaire(t_vector ray, double scalare);

//Matrix
t_matrix3x3	set_matrix(t_vector u, t_vector v, t_vector w);
t_matrix3x3	get_matrix_inverse(t_matrix3x3 origin);
t_matrix3x3	get_transform_matrix(t_vector cam);
void		matrix3x3_multiply_to_vector(t_vector *v, t_matrix3x3 m);
void		matrix3x3_multiply_to_point(t_point *p, t_matrix3x3 m);

// Math utils
double		ft_max(double a, double b);
double		ft_min(double a, double b);

#endif
