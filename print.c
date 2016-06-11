/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:04:45 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/11 10:52:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*new_path(char *name, char *path)
{
	char	*new;

	new = ft_strnew(ft_strlen(name) + 1 + ft_strlen(path));
	*new = '.';
	*(new + 1) = '/';
	new = ft_strcat(new, path);
	new = ft_strcat(new, "/");
	new = ft_strcat(new, name);
	return (new);
}

void	sort_print(t_info *info)
{
	struct dirent	*dent;
	int				count;
	char			**files;
	time_t			**times;
	int				i;
	int				j = 0;
	struct stat		file_stat;
	char			*path;

	path = (char *)malloc(sizeof(char) * 2);
	path = ft_strcpy(path, ".");
	if (info->argc > 2)
		while (info->i < info->argc)
		{
			if (info->dir != NULL)
			{
				ft_printf("%s:\n", info->argv[info->i]);
				count = ft_count_files(info->argv[info->i], info->f_a);
				files = ret_arr(count);
				times = ret_arr_time(count);
				i = 0;
				while ((dent = readdir(info->dir)) != NULL)
				{
					if (*dent->d_name != '.' || info->f_a == 1)
					{
						stat(new_path(dent->d_name, info->argv[info->i]), &file_stat);
						files[i] = ft_strdup(dent->d_name);
						times[i] = &file_stat.st_atime;
						i++;
					}
				}
				if (info->i < info->argc - 1)
					ft_putchar('\n');
				bubblesort(times, files, i, &cmp);
			}
			else
				ft_printf("%s : No such file or directory\n", info->argv[info->i]);
			info->dir = opendir(info->argv[++info->i]);
		}
	else
		while ((dent = readdir(info->dir)) != NULL)
			if (*dent->d_name != '.' || info->f_a == 1)
				ft_printf("%s\n", dent->d_name);
}
