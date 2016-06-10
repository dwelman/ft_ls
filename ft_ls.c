/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:36:58 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/10 10:31:34 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_none(t_info *info)
{
	struct dirent	*dent;

	if (info->argc > 2)
		while (info->i < info->argc)
		{
			if (info->dir != NULL)
			{
				ft_printf("%s:\n", info->argv[info->i]);
				while ((dent = readdir(info->dir)) != NULL)
				{
					if (*dent->d_name != '.' || info->f_a == 1)
						ft_printf("%s\n", dent->d_name);
				}
				if (info->i < info->argc - 1)
					ft_putchar('\n');
			}
			else
				ft_printf("%s : No such file or directory\n", info->argv[info->i]);
			info->dir = opendir(info->argv[++info->i]);
		}
	else
		while ((dent = readdir(info->dir)) != NULL || info->f_a == 1)
			if (*dent->d_name != '.')
				ft_printf("%s\n", dent->d_name);
}

void	handle_disp(t_info *info)
{
	if (info->f_rec == 1)
	{

	}
}

int		main(int argc, char **argv)
{
	t_info			info;
	int				done;

	init_info(&info, argc, argv);
	done = 0;
	info.i = 1;
	while (info.i < info.argc && done == 0)
	{
		if (info.argv[info.i][0] == '-')
		{
			get_flags(&info, info.argv[info.i]);
			info.i++;
		}
		else
			done = 1;
	}
	if (info.i >= argc)
	{
		info.dir = opendir(".");
		info.i = 1;
	}
	else
		info.dir = opendir(info.argv[info.i]);
	ls_none(&info);
	if (info.dir != NULL)
		closedir(info.dir);
	return (0);
}
