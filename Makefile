NAME 			= fractol
INCLUDE 		= ./include/

#compilation
CC 				= cc
CF 				= -Wall -Wextra -Werror -Ofast
RM 				= rm -rf
CI				= ./include/fractol.h

SRC 			=		utils.c \
						fractol.c \
						main.c \
						events.c \
						julia_set.c

$(NAME):	 $(SRC) $(CI)
			make -C ./minilibx
			$(CC) $(CF)  -I $(INCLUDE) -o $(NAME) $(SRC)  -Lminilibx -lmlx -framework OpenGL -framework AppKit

all:			$(NAME) 


re:				fclean all

clean:
				make -C ./minilibx clean
				

fclean:			clean
				$(RM) $(NAME)
.PHONY:			all clean fclean re 

