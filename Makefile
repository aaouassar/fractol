NAME = fractol

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRC = Mandelbrot.c  Julia.c scroll.c helpful.c main.c


OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	 gcc $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all