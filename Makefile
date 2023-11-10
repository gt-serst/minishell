# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 10:54:47 by gt-serst          #+#    #+#              #
#    Updated: 2023/11/10 15:16:23 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell

LIBFT			:= libft.a
LIBFT_PATH		:= "Libft"

CC				:= gcc

CFLAGS			:= -Wall -Wextra -Werror

BUILTINS		:=	srcs/builtins/cd.c\
					srcs/builtins/env.c\
					srcs/builtins/exit.c\
					srcs/builtins/pwd.c\
					srcs/buitins/echo.c\
					srcs/builtins/env_utils.c\
					srcs/builtins/export.c\
					srcs/builtins/unset.c

CLEANING		:=	srcs/cleaning/shell_cleaner.c

EXECUTION		:=	srcs/execution/exec_builtins.c\
					srcs/execution/exec_simple_cmd.c\
					srcs/execution/exec_pipe.c\
					srcs/execution/exec_utils.c\
					srcs/execution/exec.c

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

ERRORS			:=	srcs/errors/exec_err.c\
					srcs/errors/expand.err.c\
					srcs/errors/main_err.c\
					srcs/errors/parsing_err.c\
					srcs/errors/token_err.c

SRCS			:=	$(BUILTINS)\
					$(CLEANING)\
					$(EXECUTION)\
					$(EXPANDING)\
					$(PARSING)\
					$(TOKENIZATION)\
					$(ERRORS)\
					srcs/main.c\ 
					srcs/init.c\ 	
					srcs/utils.c\
					srcs/main_output.c

OBJS			:=	$(SRCS:.c=.o)

READLINE_PATH	:=	/Users/$(USER)/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_PATH)/$(LIBFT) -L$(LIBFT_PATH) -lreadline -L$(READLINE_PATH)/lib

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
