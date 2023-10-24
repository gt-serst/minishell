# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 10:54:47 by gt-serst          #+#    #+#              #
#    Updated: 2023/10/24 16:27:45 by gt-serst         ###   ########.fr        #
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

PARSING			:=

TOKENIZATION	:=	srcs/tokenization/tokenizer.c\
					srcs/tokenization/tokenizer_utils.c\
					srcs/tokenization/tk_utils.c\
					srcs/tokenization/tokenizer_handler.c

SRCS			:=	$(BUILTINS)\
					$(EXECUTOR)\
					$(EXPANDER)\
					$(PARSING)\
					$(TOKENIZATION)\
					srcs/main.c srcs/init.c srcs/errors.c\
					srcs/utils.c

OBJS			:=	$(SRCS:.c=.o)

READLINE_PATH	:=	/Users/$(USER)/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

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
