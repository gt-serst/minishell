# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 10:54:47 by gt-serst          #+#    #+#              #
#    Updated: 2023/10/23 14:46:50 by gt-serst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minishell

LIBFT			:= libft.a
LIBFT_PATH		:= "libraries/libft"

CC				:= gcc

CFLAGS			:= -Wall -Werror -Wextra

BUILTINS		:=

EXECUTOR		:=

EXPANDER		:=

PARSING			:=	parsing/parser_clear.c \
					parsing/parser_cmd.c \
					parsing/parser_err.c \
					parsing/parser_nd.c \
					parsing/parser_utils.c \
					parsing/parser.c

TOKENIZATION	:=	tokenization/tk_utils.c \
					tokenization/tokenizer_utils.c \
					tokenization/tokenizer.c \

SRCS			:=	$(BUILTINS)\
					$(EXECUTOR)\
					$(EXPANDER)\
					$(PARSING)\
					$(TOKENIZATION)\
					main.c minishell.c

OBJS			:=	$(SRCS:.c=.o)

READLINE_PATH	:=	/goinfre/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
