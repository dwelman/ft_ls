/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:05:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/10 11:53:38 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_count_files(char *path, int all)
{
	DIR				*dirp;
	struct dirent	*entry;
	int				count;

	count = 0;
	if (path)
	{
		dirp = opendir(path);
		while ((entry = readdir(dirp)) != NULL)
		{
			if (*entry->d_name != '.')
			{
				count++;
			}
			else if (all)
				count++;
		}
		closedir(dirp);
	}
	return (count);
}
