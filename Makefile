NAME = libftprintf.a
CC = cc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar
AR_FLAGS = rcs
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = ft_printf.c \
	  ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CC_FLAGS) -I . -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
