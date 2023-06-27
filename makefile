NAME = libftprintf.a
cc = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_print.h ft_print.c ft_print_utils.c ft_printf_utils_2.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)
%.o:	%.c
	cc $(FLAGS) -I ./ -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean 
	rm -f $

re: fclean all