/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:56:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 15:00:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	meta
{
	char		empty;
	char		obstacle;
	char		full;
	int			width;
	int			height;
}				meta;

typedef struct	map
{
	meta		meta;
	char		*tab;
}				map;
