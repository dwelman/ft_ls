/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:38:24 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/11 10:54:15 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <time.h>

typedef struct	s_info
{
	int			f_lst;
	int			f_rec;
	int			f_a;
	int			f_r;
	int			f_t;
	int			i;
	int			argc;
	DIR			*dir;
	char		**argv;
}				t_info;

void			get_flags(t_info *info, char *str);

void			init_info(t_info *info, int argc, char **argv);

int				ft_count_files(char *path, int all);

void			bubblesort(time_t **times, char **files,
					int elem, int (*cmp)(time_t, time_t));

void			list_path(char *path, t_info *info);

void			sort_print(t_info *info);

char			**ret_arr(int count);

time_t			**ret_arr_time(int size);

char			*build_path(struct dirent *cur, char **path, int fr);

int				cmp(time_t f1, time_t f2);

#endif
