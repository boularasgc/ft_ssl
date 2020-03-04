/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 21:21:01 by mboulara          #+#    #+#             */
/*   Updated: 2019/10/21 12:26:46 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		str_handler(int *argc, const char **argv, t_cx *data, t_cyph_f f)
{
	int s;

	data->flag |= s_FLAG;
	s = ft_strchr(argv[0], 's') - argv[0];
	if (argv[0][s + 1] != '\0')
		data->line = ft_strcpy(data->line, &argv[0][++s]);
	else if (*argc >= 2)
	{
		data->line = ft_strdup(argv[1]);
		*argc -= 2;
	}
	else
		return (print_usage_commands(*data));
	return (f(*data));
}
