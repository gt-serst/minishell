/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-plae <mde-plae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:47:10 by mde-plae          #+#    #+#             */
/*   Updated: 2023/11/10 15:11:50 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	ft_err_msg(int err_code, char *err_msg)
{
	t_err error_messages[] = {
		{ENO_FILE_NOT_FOUND, "Fichier non trouvé."},
		{ENO_PERMISSION_DENIED, "Permission refusée."},
		{ENO_MEMORY_ERROR, "Erreur mémoire."},

	};
}
