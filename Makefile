RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
RESET	= \033[0;37m
SKY		= \033[1;36m

NAME = ft_ping

TMP = objs

CC = cc

RM = rm -rf

CFLAGS = -I/usr/include/netinet  -I./includes -Wall -Wextra -Werror #-fsanitize=address

SRCS = $(wildcard ./src/*.c)

OBJS = $(patsubst ./src/%.c, ./$(TMP)/%.o, $(SRCS))

HEADER = $(wildcard ./includes/*)

./$(TMP)/%.o: ./src/%.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "$(YELLOW)💡 Created ➡️  $(SKY)$(notdir $@)$(RESET)"

all: $(NAME)

$(NAME): $(TMP) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) successfully created$(RESET)"

$(TMP):
	@mkdir -p $(TMP)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TMP)
	@echo "$(RED)♨️  Cleaned temporary files 🗑$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)♨️  Fully cleaned 🗑$(RESET)"

re: fclean all

.PHONY: all clean fclean re
