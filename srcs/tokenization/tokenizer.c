/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:37:52 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/17 14:29:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tokenization.h"

char	*skip_spaces(char *cmd_line)
{// skip white spaces by returning a pointer to the location of the next word in the cmd
}

void	tokenizer(char *cmd_line)
{// core routine for the tokenizer, scan each part of the cmd line and give to each of them a type of tokens (identifier, separator,...)
	//skip_spaces(&cmd_line); send the address of the cmd_line char to keep the current location
	//separator_identifier(&cmd_line);
	//identifier_handler(&cmd_line);
}
