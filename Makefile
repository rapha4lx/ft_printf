NAME=libftprintf.a

SRCS=ft_printf.c \
     ft_putchar.c \
     ft_putstr.c \
     ft_putnbr.c \
     ft_putnbr_unsigned.c \
     ft_pointer_address.c \
     ft_putnbr_base.c \
     ft_strlen.c

OBJS = $(SRCS:.c=.o)


CC= cc
FLAGS= -Wall -Werror -Wextra

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run: re
	clear
	$(CC) $(FLAGS) main.c $(NAME)
	./a.out

run2: re
	clear
	$(CC) main.c $(NAME) -l bsd
	./a.out

test: re
	clear
	bash run_docker.sh

t: re
	clear
	$(CC) main.c $(NAME) -l bsd
	./a.out
