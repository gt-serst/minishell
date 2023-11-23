# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 10:54:47 by gt-serst          #+#    #+#              #
#    Updated: 2023/11/23 10:14:23 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell

LIBFT			:= libft.a
LIBFT_PATH		:= "Libft"

CC				:= cc

CFLAGS			:= -Wall -Wextra -Werror

BUILTINS		:=	srcs/builtins/cd.c\
					srcs/builtins/env.c\
					srcs/builtins/exit.c\
					srcs/builtins/pwd.c\
					srcs/builtins/echo.c\
					srcs/builtins/env_utils.c\
					srcs/builtins/export.c\
					srcs/builtins/unset.c

CLEANING		:=	srcs/cleaning/shell_cleaner.c

EXECUTION		:=	srcs/execution/exec_builtins.c\
					srcs/execution/exec_simple_cmd.c\
					srcs/execution/exec_pipe.c\
					srcs/execution/exec_utils.c\
					srcs/execution/exec.c\
					srcs/execution/path_to_cmd.c

EXPANDING		:=	srcs/expanding/expand_args.c\
					srcs/expanding/expand_utils.c\
					srcs/expanding/expand.c\
					srcs/expanding/heredoc_redir.c\
					srcs/expanding/other_redir.c\
					srcs/expanding/redir.c

PARSING			:=	srcs/parsing/ast_builder.c\
					srcs/parsing/ast_cleaner.c\
					srcs/parsing/nd_utils.c\
					srcs/parsing/parser_handler.c\
					srcs/parsing/parser_utils.c\
					srcs/parsing/parser.c

TOKENIZATION	:=	srcs/tokenization/tk_utils.c\
					srcs/tokenization/tokenizer_handler.c\
					srcs/tokenization/tokenizer_utils.c\
					srcs/tokenization/tokenizer.c

SRCS			:=	$(BUILTINS)\
					$(CLEANING)\
					$(EXECUTION)\
					$(EXPANDING)\
					$(PARSING)\
					$(TOKENIZATION)\
					srcs/main.c\
					srcs/init.c\
					srcs/utils.c\
					srcs/main_output.c\
					srcs/errors.c

OBJS			:=	$(SRCS:.c=.o)

READLINE_PATH	:=	/Users/$(USER)/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_PATH)/$(LIBFT) -L$(LIBFT_PATH) -lreadline -L$(READLINE_PATH)/lib -g3 -fsanitize=address

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
