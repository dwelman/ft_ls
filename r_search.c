/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:28:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/11 15:48:52 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*build_path(struct dirent *cur, char *path)
{
	char	*new;
	int		p_len;

	p_len = ft_strlen(path);
	if (p_len == 0)
		return (NULL);
	new = ft_strnew(p_len + cur->d_namlen + 1);
	ft_strcpy(new, path);
	if (new[ft_strlen(path) - 1] != '/')
		ft_strcat(new, "/");
	ft_strcat(new, cur->d_name);
	new[p_len + ft_strlen(cur->d_name) + 1] = '\0';
	return (new);
}

void	subdir_list(char *path, t_info *info)
{
	struct dirent	*cur;
	DIR				*dir;
	struct stat		stats;
	char			*f_path;

	if (path)
	{
		dir = opendir(path);
		if (dir != NULL)
		{
			while ((cur = readdir(dir)) != NULL)
			{
				f_path = build_path(cur, path);
				stat(f_path, &stats);
				free(f_path);
				if (S_ISDIR(stats.st_mode) && *cur->d_name != '.')
				{
					f_path = build_path(cur, path);
					list_path(f_path, info);
				}
			}
			closedir(dir);
		}
	}
}

char	*init_dir_inf(t_info *info, char *path, int *f)
{
	*f = ft_count_files(path, 1);
	info->stats = (struct stat**)malloc(sizeof(struct stat*) * *f + 1);
	info->list = (char**)malloc(sizeof(char*) * *f + 1);
	info->file = (char**)malloc(sizeof(char*) * *f + 1);
	if (info->f_rec)
		ft_printf("\n%s\n", path);
	return (ft_strdup(path));
}

void	store_stat(t_info *info, struct dirent *cur, char *c_path, int i)
{
	char	*f_path;

	f_path = build_path(cur, c_path);
	info->stats[i] = (struct stat*)malloc(sizeof(struct stat));
	stat(f_path, info->stats[i]);
	free(f_path);
	build_l(*info->stats[i], cur, info, i);
}

void	list_path(char *path, t_info *info)
{
	DIR				*dir;
	char			*c_path;
	int				i;
	int				f;
	struct dirent	*cur;

	i = -1;
	c_path = init_dir_inf(info, path, &f);
	dir = opendir(c_path);
	if (dir != NULL)
	{
		while ((cur = readdir(dir)) != NULL && ++i < f)
			store_stat(info, cur, c_path, i);
		closedir(dir);
		sort_print(info, f);
		if (info->f_rec)
			subdir_list(c_path, info);
		free(c_path);
	}
}
