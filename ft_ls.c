/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:36:58 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/11 16:35:45 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	handle_disp(t_info *info)
{
	int	i;
	DIR	*cur;

	i = info->flags + 1;
	if (i >= info->argc)
	{
		list_path(".", info);
	}
	else
		while (i < info->argc)
		{
			cur = opendir(info->argv[i]);
			if (cur != NULL)
			{
				list_path(info->argv[i], info);
				closedir(cur);
			}
			else
				ft_printf("%s : No such file or directory\n", info->argv[i]);
			i++;
		}
}

int		main(int argc, char **argv)
{
	t_info			info;
	int				done;
	int				i;

	init_info(&info, argc, argv);
	done = 0;
	i = 1;
	while (i < info.argc && done == 0)
	{
		if (info.argv[i][0] == '-')
		{
			get_flags(&info, info.argv[i]);
			info.flags++;
			i++;
		}
		else
			done = 1;
	}
	handle_disp(&info);
	return (0);
}
