/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_view_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 11:45:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/13 12:30:48 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_print(t_info *info, int filec)
{
	int	i;

	i = -1;
	if (info->f_lst)
	{
		ft_printf("total %d\n", info->blksize);
		pad_size(info, filec);
	}
	if (info->f_t)
	{
		if (info->f_r)
			bubblesort(info, filec, &rev_cmp);
		else
			bubblesort(info, filec, &cmp);
	}
	while (++i < filec)
		if (*info->file[i] != '.' || info->f_a)
		{
			if (info->f_lst)
				ft_printf("%s\n", info->list[i]);
			else
				ft_printf("%s\n", info->file[i]);
		}
	cleanup(info, filec);
}

char	*get_perm(struct stat stats, struct dirent *cur, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(len + 23);
	if (S_ISLNK(stats.st_mode))
		ret[i++] = 'l';
	else if (S_ISDIR(stats.st_mode))
		ret[i++] = 'd';
	else
		ret[i++] = '-';
	ret[i++] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
	ret[i++] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
	ret[i++] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
	ret[i++] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
	ret[i++] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
	ret[i++] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
	ret[i++] = (stats.st_mode & S_IROTH) ? 'r' : '-';
	ret[i++] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
	ret[i++] = ' ';
	return (ret);
}

void	get_name(t_info *info, struct dirent *cur, int in, struct stat stat_f)
{
	char		*name;
	char		*buff;
	struct stat	*stat_l;

	if (S_ISLNK(stat_f.st_mode) && info->f_lst)
	{
		buff = ft_strnew(100);
		readlink(info->f_path, buff, 100);
		name = ft_strnew(ft_strlen(cur->d_name) + 4 + 10);
		ft_strcpy(name, cur->d_name);
		ft_strcat(name, " -> ");
		ft_strcat(name, buff);
		info->file[in] = name;
		free(buff);
	}
	else
		info->file[in] = ft_strdup(cur->d_name);
}

void	build_l(struct stat stats, struct dirent *cur, t_info *info, int in)
{
	char			*ret;
	char			*mtime;
	struct passwd	*pw;
	struct group	*grp;
	int				i;

	pw = getpwuid(stats.st_uid);
	grp = getgrgid(stats.st_gid);
	mtime = ft_strchr(ctime(&stats.st_mtime), ' ') + 1;
	ft_bzero(&mtime[ft_strlen(mtime) - 9], 9);
	ret = get_perm(stats, cur, ft_strlen(pw->pw_name) + ft_strlen(grp->gr_name)
				+ ft_strlen(mtime) + ft_strlen(cur->d_name));
	i = ft_strlen(ret);
	ft_strcpy(&ret[i++], ft_itoa((int)stats.st_nlink));
	ft_strcat(ft_strcat(ret, "  "), pw->pw_name);
	ft_strcat(ft_strcat(ret, "  "), grp->gr_name);
	info->size[in] = ft_strnew(15);
	ft_strcpy(info->size[in], convert_uns(stats.st_size, 10, 0));
	ft_strcat(ret, "\t");
	ft_strcat(ret, mtime);
	ft_strcat(ret, " ");
	get_name(info, cur, in, stats);
	ft_strcat(ret, info->file[in]);
	info->list[in] = ret;
}
