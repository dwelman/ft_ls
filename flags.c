/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 09:19:14 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/09 13:32:04 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_flags(t_info *info, char *str)
{
	int	i;
	int	is_dash;

	i = 0;
	is_dash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'l')
			info->f_lst = 1;
		else if (str[i] == 'R')
			info->f_rec = 1;
		else if (str[i] == 'a')
			info->f_a = 1;
		else if (str[i] == 'r')
			info->f_r = 1;
		else if (str[i] == 't')
			info->f_t = 1;
		else if (str[i] == '-' && is_dash == 0)
			is_dash = 1;
		else
		{
			ft_printf("./ft_ls: illegal option -- %c\n", str[i]);
			exit(-1);
		}
		i++;
	}
}
