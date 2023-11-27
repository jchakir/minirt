/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:42:40 by hbourkan          #+#    #+#             */
/*   Updated: 2022/06/09 15:17:32 by hbourkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 1
# define IMAGE_WIDTH 1000
# define IMAGE_HEIGHT 1000

typedef struct s_matrix3x3
{
	double	u[3];
	double	v[3];
	double	w[3];
}	t_matrix3x3;

// Mlx

typedef struct s_mlx {
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*image_ptr;
	int				size;
	int				pos;
	int				bit;
	int				endian;
}	t_mlx;

// Elements utils
typedef struct s_point {
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector {
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_solution {
	bool				solution;
	double				t;
	int					color;
	int					type;
	int					id;
	t_rgb				rgb;
	struct s_solution	*next;
}	t_solution;

// Elements
typedef struct s_ambient_light {
	double			ratio;
	struct s_rgb	rgb;
}	t_ambient_light;

typedef struct s_camera {
	struct s_point	point;
	struct s_vector	vector;
	double			fov;
}	t_camera;

typedef struct s_light {
	struct s_point	point;
	double			ratio;
}	t_light;

typedef struct s_sphere {
	struct s_point	point;
	double			diameter;
	struct s_rgb	rgb;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane {
	struct s_point	point;
	struct s_vector	vector;
	struct s_rgb	rgb;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder {
	struct s_point		point;
	struct s_vector		vector;
	double				diameter;
	double				height;
	struct s_rgb		rgb;
	struct s_cylinder	*next;
}	t_cylinder;

// Pointer to every element
typedef struct s_data {
	struct s_ambient_light	*amb_light;
	struct s_camera			*camera;
	struct s_light			*light;
	struct s_sphere			*sphere;
	struct s_plane			*plane;
	struct s_cylinder		*cylinder;
	double					tanfov;
	double					aspect_ratio;
}	t_data;

void		ray_tracer(t_data data, t_mlx ml, t_point origin);

// Get_next_line functions
char		*get_next_line(int fd);
char		*get_next_line_str(char **str);
char		*with_newline(char **storage);
char		*no_newline(char **storage);
void		loop(char **storage, char **buffer, int fd);
char		*ft_strjoin_gnl(char *s1, char *s2);

// Memory management functions
void		free_tab(char **tab);
void		free_solution(t_solution *s);

// Parser functions
void		parse_ab_light(char **subline, t_data *data);
void		parse_camera(char **subline, t_data *data);
void		parse_light(char **subline, t_data *data);
t_sphere	*parse_sphere(char **subline);
t_plane		*parse_plane(char **subline);
t_cylinder	*parse_cylinder(char **subline);
int			get_tab_size(char **sublines);
void		check_buffer(char *buffer);
char		*read_file(int fd);
void		parse_config(t_data *data, char *buffer);
void		get_xyz_points(t_point *xyz, char *subline);
void		get_xyz_vectors(t_vector *xyz, char *subline);
void		get_rgb_colors(t_rgb *rgb, char *subline);

// List management
void		add_spheres_back(t_sphere **spheres, t_sphere *new);
void		add_planes_back(t_plane **planes, t_plane *new);
void		add_cylinders_back(t_cylinder **cylinders, t_cylinder *new);
void		add_s_back(t_solution **s, t_solution *new);
t_solution	*copy_list(t_solution *temp);

// Utils functions
double		ft_atof(char *s);
int			ft_isfloat(char *str);
int			is_int(char *str);
void		ft_error(char *error_msg);
int			check_commas(char *subline);
double		norm(t_vector vector);

// Render functions
void		create_frame(t_data data);

#endif