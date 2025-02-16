NAME    = so_long
# BNAME   = checker
CC      = cc
FLAGS   = -Wall -Wextra -Werror #-fsanitize=address -g3
RM      = rm -f

SRCS    = 	main.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c \
			parsing/parsing_01.c 

# BSRCS   = 
OBJS    = $(SRCS:.c=.o)
# BOBJS   = $(BSRCS:.c=.o)

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

# bonus: $(BNAME)

# $(BNAME): $(BOBJS)
# 	@$(CC) $(FLAGS) -o $(BNAME) $(BOBJS)

clean:
	@$(RM) $(OBJS) 
# $(BOBJS)

fclean: clean
	@$(RM) $(NAME) 
# $(BNAME)

re: fclean all