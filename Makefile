NAME        = pipex
BONUS_NAME  = pipex
MAND_BUILD  = .mandatory_build
BONUS_BUILD = .bonus_build

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I. -I$(LIBFT_DIR)

# ----------------------------- COMMON FILES --------------------------------- #

COMMON_SRCS = command_utils.c \
              path_utils.c \
			  parse1.c \
			  parse2.c \
			  command_exec.c

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

# ----------------------------- MANDATORY ------------------------------------ #

SRCS        = pipex.c \
			  process_exec.c
OBJS        = $(SRCS:.c=.o)

# ------------------------------ BONUS --------------------------------------- #

BONUS_SRCS  = pipex_bonus.c \
			  pipex_bonus_runtime.c \
			  pipex_bonus_children.c \
			  pipex_here_doc.c \
			  pipex_here_doc_utils.c
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# ---------------------------------------------------------------------------- #

all: $(MAND_BUILD)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MAND_BUILD): $(LIBFT) $(OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(COMMON_OBJS) $(LIBFT) -o $(NAME)
	@touch $(MAND_BUILD)
	@rm -f $(BONUS_BUILD)

bonus: $(BONUS_BUILD)

$(BONUS_BUILD): $(LIBFT) $(BONUS_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(COMMON_OBJS) $(LIBFT) -o $(NAME)
	@touch $(BONUS_BUILD)
	@rm -f $(MAND_BUILD)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS) $(COMMON_OBJS)
	rm -f $(MAND_BUILD) $(BONUS_BUILD)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
