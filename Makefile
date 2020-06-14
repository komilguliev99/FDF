# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pelease <pelease@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 11:31:41 by dcapers           #+#    #+#              #
#    Updated: 2020/06/14 22:42:36 by pelease          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIST	=	 
DIRS	=	src/
SOURCE	=	$(addprefix $(DIRS), $(LIST))
OBJ		=	$(patsubst %.c,%.o,$(SOURCE))

LIB		= libft/libft.a
LDIRS	= libft/ 

LIB_ALL		= $(addsuffix .all,$(LDIRS))
LIB_CLEAN	= $(addsuffix .clean,$(LDIRS))
LIB_FCLEAN	= $(addsuffix .fclean,$(LDIRS))

INCS		= includes/
INCS_LIBFT	= $(addsuffix includes/,$(LDIRS))

FLAGS = -Wall -Wextra -Werror

all: $(LIB_ALL) $(NAME)

clean: $(LIB_CLEAN)
	rm -f $(OBJ) $(wildcard $(addsuffix *.d,$(DIRS)))

fclean: $(LIB_FCLEAN) clean
	rm -f $(NAME)

re:		fclean all

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INCS_LIBFT) -I $(INCS) -MD

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(OBJ) -o $(basename $(NAME)) $(LIB)

%.all:
	make -C $*

%.clean:
	make -C $* clean

%.fclean:
	rm -f $(addsuffix *.a,$*)

include $(wildcard $(addsuffix *.d,$(DIRS)))

.PHONY: all clean fclean re
