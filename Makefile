# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbourkan <hbourkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 18:41:50 by hbourkan          #+#    #+#              #
#    Updated: 2022/06/09 18:04:52 by hbourkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGl -framework AppKit

LIBFT = libft/libft.a

# Color
BLACK = \e[30m
RED = \e[31;52m
RED_BOLD = \e[1;31m

GREEN = \e[32m
GREEN_BOLD = \e[1;32m
YELLOW = \e[33m
YELLOW_UNDERLINE = \e[4;33m
BLUE = \e[34m
BLUE_BOLD = \e[1;34m
MAGENTI = \e[35m
MAGENTI_BOLD = \e[1;35m
CYAN = \e[36m
WHITE = \e[37m
RESET= \e[0m

CFILES = main.c \
		utils/get_next_line.c \
		utils/ft_isfloat.c \
		utils/get_next_line_str.c \
		parser/ambient_light.c \
		parser/camera.c \
		parser/light.c \
		parser/sphere.c \
		parser/plane.c \
		parser/cylinder.c \
		parser/utils.c \
		parser/get_data.c \
		parser/parse_config.c \
		parser/input_verification.c \
		memory_mng/free_tab.c  \
		memory_mng/free_list.c \
		linear_algebra/add_or_subtract_to_point.c \
		linear_algebra/cross_product_vectors.c \
		linear_algebra/dot_product_vectors.c \
		linear_algebra/get_matrix_inverse.c \
		linear_algebra/get_transform_matrix.c \
		linear_algebra/matrix3x3_multiply.c \
		linear_algebra/operations_on_vectors.c \
		linear_algebra/points_to_vector.c \
		linear_algebra/vector_normalize.c \
		linear_algebra/max_min.c \
		render/ray_tracing.c \
		render/plane_render.c \
		render/sphere_render.c \
		render/cylinder_render.c \
		render/plane_render_shadow.c \
		render/sphere_render_shadow.c \
		render/cylinder_render_shadow.c \
		render/cylinder_utils.c \
		render/ray_tracing_utils.c \
		render/shadow_utils.c \
		render/frame_render.c \
		render/transform_cam_world.c \
		list_mng/list_spheres.c \
		list_mng/list_planes.c \
		list_mng/list_cylinders.c \
		list_mng/list_s.c \


OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	@printf "✅ $(GREEN_BOLD)Compiling object files finished$(RESET)\n"
	@cd libft/ && make 
	@printf "✅ $(MAGENTI_BOLD)Libft ready to link$(RESET)\n"
	@cc $(OFILES) $(FLAGS) $(MLX) $(LIBFT) -o $(NAME)
	@printf "✅ $(BLUE_BOLD)$(NAME) Created$(RESET)\n"
	
%.o : %.c
	@cc $(FLAGS) -c  $< -o $@
	@printf "🚀 $(CYAN)Generating $(YELLOW_UNDERLINE)$@ $(RESET)$(CYAN)from $(YELLOW_UNDERLINE)$<$(RESET) 🔥\n"
	
clean:
	@rm -f $(OFILES)
	@printf "🗑 $(RED_BOLD) Object files successfully cleaned\n"
	@cd libft/ && make clean
	@printf "🗑 $(RED_BOLD) Libft object files successfully cleaned\n"
	

fclean: clean
	@rm -f $(NAME)
	@printf "🗑 $(RED_BOLD) $(NAME) successfully deleted\n"
	@cd libft/ && make fclean
	@printf "🗑 $(RED_BOLD) Libft library successfully deleted\n"


re: fclean all