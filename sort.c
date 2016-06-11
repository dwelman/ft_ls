/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 08:38:23 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/11 10:54:04 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void swap_file(void **f1, void **f2)
{
	char	*temp;

	temp = *f1;
	*f1 = *f2;
	*f2 = temp;
}

void

int		rev_cmp(time_t f1,  time_t f2)
{
	if (ft_atoi(f1) > ft_atoi(f2))
		return (1);
	else
		return (0);
}

int		cmp(time_t f1,  time_t f2)
{
	if (ft_atoi(f1) < ft_atoi(f2))
		return (0);
	else
		return (1);
}

void	bubblesort(time_t **times, char **files,
		int elem, int (*cmp)(time_t, time_t))
{
	int		i;
	int		swapped;
	char	*fn;
	char	*tm

	i = 0;
	fn = *files;
	tm = *times;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (i + 1 < elem)
		{
			if (cmp(tm[i], tm[i + 1]))
			{
				swap(&tm[i], &tm[i + 1]);
				swap(&files[i], &files[i + 1]);
				swapped = 1;
			}
			i++;
		}
		i = 0;
    }
}
