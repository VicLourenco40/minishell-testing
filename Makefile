NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra $(IFLAGS)
IFLAGS = -I $(IDIR) -I $(LFTDIR)$(IDIR)
SDIR = src/
IDIR = include/
ODIR = obj/
OBJ = main.o echo.o cd.o pwd.o env.o
OBJS = $(patsubst %, $(ODIR)%, $(OBJ))
LFTDIR = libft/
LFT = $(patsubst %, $(LFTDIR)%, libft.a)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -fr $(ODIR)
	make $@ -C $(LFTDIR)

fclean: clean
	rm -fr $(NAME)
	make $@ -C $(LFTDIR)

re: fclean all

$(NAME): $(OBJS) $(LFT)
	$(CC) $(CFLAGS) -lreadline -o $@ $^

$(OBJS): $(ODIR)%.o: $(SDIR)%.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LFT):
	make -C $(LFTDIR)
