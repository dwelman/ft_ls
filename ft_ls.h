/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:38:24 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/11 16:36:27 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>

typedef struct	s_info
{
	int				f_lst;
	int				f_rec;
	int				f_a;
	int				f_r;
	int				f_t;
	int				flags;
	int				argc;
	char			**argv;
	struct stat		**stats;
	char			**file;
	char			**list;
	int				f;
}				t_info;

void			get_flags(t_info *info, char *str);

void			init_info(t_info *info, int argc, char **argv);

int				ft_count_files(char *path, int all);

void			bubblesort(t_info *info, int filec, int (*cmp)(time_t, time_t));

void			list_path(char *path, t_info *info);

char			*build_path(struct dirent *cur, char *path);

int				cmp(time_t f1, time_t f2);

void			sort_print(t_info *info, int filec);

void			list_view_print(struct stat stats, struct dirent *cur,
					t_info *info);

void			build_l(struct stat stats, struct dirent *cur,
					t_info *info, int i);

int				rev_cmp(time_t f1,  time_t f2);

int				cmp(time_t f1,  time_t f2);

#endif
