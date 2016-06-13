/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 08:38:23 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/13 09:04:22 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_char(char **f1, char **f2)
{
	char	*temp;

	temp = *f1;
	*f1 = *f2;
	*f2 = temp;
}

void	swap_stat(struct stat **f1, struct stat **f2)
{
	struct stat	*temp;

	temp = *f1;
	*f1 = *f2;
	*f2 = temp;
}

int		rev_cmp(time_t f1, time_t f2)
{
	if ((long int)f1 > (long int)f2)
		return (1);
	else
		return (0);
}

int		cmp(time_t f1, time_t f2)
{
	if ((long int)f1 < (long int)f2)
		return (1);
	else
		return (0);
}

void	bubblesort(t_info *info, int filec, int (*cmp)(time_t, time_t))
{
	int		i;
	int		swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (i + 1 < filec)
		{
			if (cmp(info->stats[i]->st_mtime, info->stats[i + 1]->st_mtime))
			{
				swap_char(&info->file[i], &info->file[i + 1]);
				if (info->f_lst)
					swap_char(&info->list[i], &info->list[i + 1]);
				swap_stat(&info->stats[i], &info->stats[i + 1]);
				swapped = 1;
			}
			i++;
		}
		i = 0;
	}
}
