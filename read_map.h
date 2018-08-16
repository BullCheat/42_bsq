/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:29:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:20:16 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H
# include "map.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "first_line.h"

t_map	*read_map(int filedes);
void	*allocate(unsigned long size);

#endif
