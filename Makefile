NAME			:= push_swap
CHECKER			:= checker

LIBFT			:= pf_libft/pf_libft.a
CC 				:= cc
CFLAGS 			:= -Wall -Wextra -Werror -g 
SRC 			:= src/main.c src/parse_utils.c src/errors.c \
				   src/instructions.c src/instructions_two.c \
				   src/instructions_three.c src/utils.c \
				   src/utils_two.c src/utils_three.c \
				   src/utils_four.c src/sort_helper.c src/min_max.c \
				   src/cost.c src/str_utils.c src/simplify.c \
				   src/sort.c
BSRC			:= bsrc/checker.c bsrc/errors.c bsrc/execute.c \
				   bsrc/instructions.c bsrc/instructions_three.c \
				   bsrc/instructions_two.c bsrc/parse_utils.c \
				   bsrc/parse_utils_two.c bsrc/get_next_line.c \
				   bsrc/get_next_line_utils.c

OBJ 			:= $(SRC:src/%.c=objects/%.o)
BOBJ 			:= $(BSRC:bsrc/%.c=bobjects/%.o)
OBJDIR 			:= objects
BOBJDIR			:= bobjects

DEF_COLOR		:= \033[0;39m
GRAY			:= \033[0;90m
RED				:= \033[0;91m
GREEN			:= \033[0;92m
YELLOW			:= \033[0;93m
BLUE			:= \033[0;94m
MAGENTA			:= \033[0;95m
CYAN			:= \033[0;96m
WHITE			:= \033[0;97m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJ)
	@echo "$(GREEN)Making binary : $(NAME)"
	@printf "$(MAGENTA)"
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)
	@printf "Done !$(DEF_COLOR)\n"

$(CHECKER): $(BOBJDIR) $(BOBJ)
	@echo "$(GREEN)Making binary : $(CHECKER)"
	@printf "$(MAGENTA)"
	@$(CC) $(BOBJ) $(CFLAGS) $(LIBFT) -o $(CHECKER)
	@printf "Done !$(DEF_COLOR)\n"

$(OBJDIR)/%.o: src/%.c
	@printf '$(YELLOW)Compiling : %-25s $(CYAN)-->	$(YELLOW)%-30s\n' "$<" "$@";
	@printf "$(BLUE)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(DEF_COLOR)"

$(BOBJDIR)/%.o: bsrc/%.c
	@printf '$(YELLOW)(Bonus) Compiling : %-25s $(CYAN)-->	$(YELLOW)%-30s\n' "$<" "$@";
	@printf "$(BLUE)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(DEF_COLOR)"

clean:
	@make -C pf_libft/ clean
	@rm -rf $(OBJDIR) $(BOBJDIR) 
	@printf "$(RED)Objects deleted !$(DEF_COLOR)\n"

fclean: clean
	@make -C pf_libft/ fclean
	@rm -rf $(NAME) $(CHECKER)
	@printf "$(RED)Library deleted !$(DEF_COLOR)\n"

bonus: $(LIBFT) $(CHECKER)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BOBJDIR):
	@mkdir -p $(BOBJDIR)

$(LIBFT):
	make -C pf_libft/

re: fclean all

.PHONY: all clean fclean re 
