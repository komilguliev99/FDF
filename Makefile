# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcapers <dcapers@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 11:31:41 by dcapers           #+#    #+#              #
#    Updated: 2020/06/16 04:29:08 by dcapers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIST	=	 main.c read_map.c utils.c draw_map.c
DIRS	=	src/
SOURCE	=	$(addprefix $(DIRS), $(LIST))
OBJ		=	$(patsubst %.c,%.o,$(SOURCE))

LDIRS	= libft/ 
LIBS	= libft/libft.a

LIB_ALL		= $(addsuffix .all,$(LDIRS))
LIB_CLEAN	= $(addsuffix .clean,$(LDIRS))
LIB_FCLEAN	= $(addsuffix .fclean,$(LDIRS))

INCS		= includes/
INCS_LIBFT	= libft/includes
INCS_MLX	= minilibx/

FLAGS = -Wall -Wextra -Werror

all: $(LIB_ALL) $(NAME)

clean: $(LIB_CLEAN)
	rm -f $(OBJ) $(wildcard $(addsuffix *.d,$(DIRS)))

fclean: $(LIB_FCLEAN) clean
	rm -f $(NAME)

re:		fclean all

%.o: %.c
	gcc $(FLAGS) -c $< -o $@  -I $(INCS) -I $(INCS_LIBFT) -I $(INCS_MLX) -MD

$(NAME): $(OBJ) $(LIBS)
	gcc $(FLAGS) $(OBJ) -o $(basename $(NAME)) -L $(LDIRS) -lft -L minilibx -lmlx_Linux -lXext -lX11 -lm

%.all:
	make -C $*

%.clean:
	make -C $* clean

%.fclean:
	rm -f $(addsuffix *.a,$*)

include $(wildcard $(addsuffix *.d,$(DIRS)))

.PHONY: all clean fclean re
