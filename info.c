/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 11:44:14 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/09 13:26:36 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_info(t_info *info, int argc, char **argv)
{
	info->f_lst = 0;
	info->f_rec = 0;
	info->f_a = 0;
	info->f_r = 0;
	info->f_t = 0;
	info->argc = argc;
	info->argv = argv;
}
