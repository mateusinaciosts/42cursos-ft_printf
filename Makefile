NAME		= libftprintf.a
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SOURCES		= ft_printf.c	ft_printf_utils.c	ft_printf_utils_2.c
OBJECTS		= $(SOURCES:%.c=%.o)

all:		$(NAME)	

$(NAME):	$(OBJECTS)
			ar -rcs $(NAME) $(OBJECTS)

%.o:		%.c
			$(CC) $(FLAGS) -I ./ -c $< -o $@
clean:
	$(RM) $(OBJECTS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean	all
