# NAME    = so_long
# # BNAME   = checker
# CC      = cc
# FLAGS   = -Wall -Wextra -Werror #-fsanitize=address -g3
# RM      = rm -f

# SRCS    = 	main.c \
# 			Get_next_line/get_next_line.c \
# 			Get_next_line/get_next_line_utils.c \
# 			utils/ft_putstr_fd.c \
# 			utils/ft_strlen.c \
# 			utils/ft_split.c \
# 			utils/utils_01.c \
# 			utils/ft_strchr.c \
# 			parsing/parsing_01.c \
# 			parsing/parsing_02.c  

# # BSRCS   = 
# OBJS    = $(SRCS:.c=.o)
# # BOBJS   = $(BSRCS:.c=.o)

# .c.o:
# 	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

# # bonus: $(BNAME)

# # $(BNAME): $(BOBJS)
# # 	@$(CC) $(FLAGS) -o $(BNAME) $(BOBJS)

# clean:
# 	@$(RM) $(OBJS) 
# # $(BOBJS)

# fclean: clean
# 	@$(RM) $(NAME) 
# # $(BNAME)

# re: fclean all

NAME    = so_long
CC      = cc
FLAGS   = -Wall -Wextra -Werror #-fsanitize=address -g3
RM      = rm -f

# Add MiniLibX library path here if needed
MINILIBX_PATH = minilibx-linux/libmlx.a

SRCS    = 	main.c \
			Get_next_line/get_next_line.c \
			Get_next_line/get_next_line_utils.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \
			utils/ft_split.c \
			utils/utils_01.c \
			utils/ft_strchr.c \
			parsing/parsing_01.c \
			parsing/parsing_02.c  

OBJS    = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(MINILIBX_PATH) -lmlx -lX11 -lXext

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
