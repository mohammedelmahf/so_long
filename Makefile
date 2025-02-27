NAME    = so_long
CC      = cc
FLAGS   = -Wall -Wextra -Werror -fPIE
RM      = rm -f

# Path to MiniLibX
MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
MLX_INC = -I$(MLX_DIR)

SRCS    = 	main.c \
			Get_next_line/get_next_line.c \
			Get_next_line/get_next_line_utils.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \
			utils/ft_split.c \
			utils/utils_01.c \
			utils/ft_strchr.c \
			sources/mlx_lodaer/mlx_lodaer.c\
			sources/mlx_path/mlx_path01.c\
			sources/parsing/parsing_01.c \
			sources/parsing/parsing_02.c \
			sources/so_long_utils/so_long_utils_01.c

OBJS    = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) $(MLX_INC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) -pie

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
