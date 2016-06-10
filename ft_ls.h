/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 07:38:24 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/10 09:04:14 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>

typedef struct	s_list
{
	void		*data;
	t_list		*next;
}				t_list;

typedef struct	s_info
{
	int			f_lst;
	int			f_rec;
	int			f_a;
	int			f_r;
	int			f_t;
	int			i;
	int			argc;
	char		**argv;
	DIR			*dir;
}				t_info;

typedef struct	s_file
{
	char		*name;
	char		*path;
	char		*username;
	char		*groupname;
	char		*date;
	char		permissions[12];
	int			byte_size;
	int			block_size;
	int			links;
	t_list		*sub_dir;
}				t_file;

void			get_flags(t_info *info, char *str);

void			init_info(t_info *info, int argc, char **argv);

#endif
