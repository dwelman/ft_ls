/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:44:14 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 10:46:17 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_info(t_info *info, int argc, char **argv)
{
	info->f_lst = 0;
	info->f_rec = 0;
	info->f_a = 0;
	info->f_r = 0;
	info->f_t = 0;
	info->argc = argc;
	info->argv = argv;
	info->flags = 0;
}

void	cleanup(t_info *info, int filec)
{
	int	i;

	i = -1;
	while (++i < filec)
	{
		free(info->file[i]);
		free(info->list[i]);
		free(info->size[i]);
	}
	free(info->file);
	free(info->list);
	free(info->size);
}
