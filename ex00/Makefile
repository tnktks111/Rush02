NAME = rush-02
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDE_DIR = includes

SRCS := $(shell find $(SRCS_DIR) -name "*.c")
OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -f $(NAME)

re: fclean all
