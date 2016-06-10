/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 15:28:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/10 17:17:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_view_print(struct stat stats, struct dirent *cur, t_info *info)
{
	char	*mtime;
	
	ft_printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
	ft_printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf( (stats.st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf("\t%d",(int)stats.st_nlink);
	ft_printf("\t%d", stats.st_uid);
	ft_printf("\t%d", stats.st_gid);
    ft_printf("\t%d",(int)stats.st_size);
	mtime = ft_strchr(ctime(&stats.st_mtime), ' ') + 1;
	ft_bzero(&mtime[ft_strlen(mtime) - 9], 9);
	ft_printf("\t%s", mtime);
	ft_printf("\t%s\n", cur->d_name);
	
  //  printf("File inode: \t\t%d\n",stats.st_ino);
   	//else errors
}

char	*build_path(struct dirent *cur, char **path, int fr)
{
	char	*new;

	new = ft_strnew(ft_strlen(*path) + ft_strlen(cur->d_name) + 1);
	ft_strcpy(new, *path);
	if (new[ft_strlen(*path) - 1] != '/')
		ft_strcat(new, "/");
	ft_strcat(new, cur->d_name);
	if (fr)
		free(*path);
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
		while ((cur = readdir(dir)) != NULL)
		{
			f_path = build_path(cur, &path, 0);
			stat(f_path , &stats);
			free(f_path);
			if (S_ISDIR(stats.st_mode) && *cur->d_name != '.')
			{
				f_path = build_path(cur, &path, 0);
				list_path(f_path, info);
			}
		}
		closedir(dir);
	}
}

void	list_path(char *path, t_info *info)
{
	struct dirent	*cur;
	DIR				*dir;
	struct stat		stats;
	char			*f_path;

	if (path)
	{
		ft_printf("\n%s\n", path);
		dir = opendir(path);
		while ((cur = readdir(dir)) != NULL)
		{
			f_path = build_path(cur, &path, 0);
			stat(f_path , &stats);
			free(f_path);
			if (info->f_lst && *cur->d_name != '.' || info->f_a)
			{
				if (info->f_t == 0)
					list_view_print(stats, cur, info);
			}
			else if (*cur->d_name != '.' || info->f_a)
				ft_printf("%s\n", cur->d_name);
			//if	(info->f_t)
				//sort_print
		}
		closedir(dir);
		if (info->f_rec)
			subdir_list(path, info);
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	info.f_rec = 1;
	info.f_a = 0;
	info.f_lst = 1;
	info.f_t = 0;
	list_path(argv[1], &info);
	return (0);
}
