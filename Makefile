# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 16:03:44 by jmoucach          #+#    #+#              #
#    Updated: 2019/04/26 16:03:46 by jmoucach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
#								Colors										   #
################################################################################

RED= \033[31m
WHITE= \033[0m
GREEN= \033[32m
CYAN= \033[36m
BLUE= \033[34m
YELLOW= \033[33m
MAGENTA= \033[35m

################################################################################
#								Macros										   #
################################################################################
NAME= fractol
CC= gcc
CFLAGS= -Wall -Wextra -Werror
FRAMEWORK= -framework OpenGL -framework AppKit
SRC_DIR= src/
SRC= setup/main.c\
	 setup/parsing.c\
	 setup/threads.c\
	 setup/init.c\
	 draw/put_pixel.c\
	 draw/bressenham.c\
	 draw/draw_hud.c\
	 fractals/sierpinski_triangle.c\
	 fractals/mandelbrot_set.c\
	 fractals/burning_ship_set.c\
	 fractals/mandelbar_set.c\
	 fractals/julia_set.c\
	 fractals/barnsley_fern.c\
	 handler/deal_key.c\
	 handler/key_handler.c\
	 handler/deal_key_sierpinski.c\
	 handler/mouse_move.c\
	 hud/hud.c\
	 hud/info.c
SRCS= $(addprefix $(SRC_DIR),$(SRC))
OBJ_DIR= obj/
OBJ= $(SRC:.c=.o)
OBJ_SUBDIRS= fractals handler draw setup hud
OBJS= $(addprefix $(OBJ_DIR), $(OBJ))
SUBDIRS= $(foreach dir, $(OBJ_SUBDIRS), $(OBJ_DIR)$(dir))
LIB= -L /usr/local/lib -lmlx\
	 -L libft -lft
INCLUDES=	hdr/fractol.h\
			hdr/proto.h\
			hdr/struct.h\
			hdr/keycode.h

###############################################################################
#								Rules										  #
###############################################################################

all: $(SUBDIRS) $(NAME)

$(NAME): $(OBJS)
	@ echo "$(BLUE)Creating libft$(WHITE)"
	@ make -C libft
	@ echo "$(GREEN)Libft created$(WHITE)"
	@ echo "$(YELLOW)Creating $@ executable$(WHITE)"
	@ $(CC) -o $@ $(CFLAGS) $(OBJS) $(LIB) $(FRAMEWORK)
	@echo "$(GREEN)$@ executable created$(WHITE)"

$(SUBDIRS):
	@ mkdir -p $(SUBDIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES) Makefile
	@ $(CC) -o $@ -c $< $(CFLAGS)
	@ echo "$(GREEN)[✔]$(WHITE)$@"

clean:
	@ echo "$(YELLOW)Deleting objects$(WHITE)"
	@ for i in $(OBJ); do \
		echo "$(RED)-Deleting $$i$(WHITE)"; \
	done;
	@ echo "$(GREEN)Objects deleted$(WHITE)"
	@ rm -rf $(OBJ)

fclean: clean
	@ echo "$(BLUE)Cleaning libft$(WHITE)"
	@ make -C libft fclean
	@ echo "$(YELLOW)Deleting obj directory$(WHITE)"
	@ rm -rf obj
	@ echo "$(GREEN)Obj directory deleted$(WHITE)"
	@ echo "$(GREEN)Executable deleted$(WHITE)"
	@ rm -rf $(NAME)

re: fclean all
