/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:43:13 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/13 12:30:58 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	push_back(t_info *info, int in, int filec, int amount)
{
	int	i;
	int	j;
	int	k;
	int	diff;

	i = ft_strchr(info->list[in], '\t') - info->list[in];
	j = ft_strlen(info->list[in]);
	diff = amount - ft_strlen(info->size[in]);
	while (j != i)
	{
		info->list[in][j + amount] = info->list[in][j];
		j--;
	}
	j = 0;
	k = 0;
	while (i < ft_strlen(info->list[in]) && info->size[in][j])
		if (k++ < diff)
			info->list[in][i++] = ' ';
		else
			info->list[in][i++] = info->size[in][j++];
	info->list[in][i] = ' ';
}

void	pad_size(t_info *info, int filec)
{
	int	i;
	int	longest;
	int	diff;

	i = -1;
	longest = 0;
	while (++i < filec)
		if (ft_strlen(info->size[i]) > ft_strlen(info->size[longest]))
			longest = i;
	longest = ft_strlen(info->size[longest]);
	i = -1;
	while (++i < filec)
		push_back(info, i, filec, longest + 2);
}
