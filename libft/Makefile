NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .

AR = ar
ARFLAGS = rcs
RM = rm -f

# -------------------- LIBFT (root) --------------------
LIBC =  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstmap.c

# -------------------- FT_PRINTF (subdir) --------------------
PRINTF_DIR = libftprintf
PRINTF_SRC = ft_printf.c \
       ft_printf_characters.c \
       ft_printf_decimals.c \
       ft_printf_lowercase_hexadecimals.c \
       ft_printf_uppercase_hexadecimals.c \
       ft_printf_pointers.c \
       ft_printf_percentage.c \
       ft_printf_strings.c \
       ft_printf_unsigned_decimals.c \
       ft_count_hexa.c \
       ft_hexa_lower.c \
       set_flags.c \
       ft_printf_all.c \
       precision_flag.c \
       width_flag.c \
       max.c \
       zero_flag.c \
       ft_strlen_v2.c \
       ft_string.c \
       plus_or_space_flag.c \
       plus_or_space_flag_count.c

PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRC))

# -------------------- GET_NEXT_LINE (subdir) --------------------
GNL_DIR = getNextLine
GNL_SRCS = $(GNL_DIR)/get_next_line.c

# Optional bonus file (if you want `make bonus` to include it too)
GNL_BONUS_SRCS = $(GNL_DIR)/get_next_line_bonus.c

# -------------------- SRCS/OBJS --------------------
SRCS = $(LIBC) $(PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = $(LIBC) $(BONUS) $(PRINTF_SRCS) $(GNL_SRCS) $(GNL_BONUS_SRCS)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# -------------------- RULES --------------------
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
