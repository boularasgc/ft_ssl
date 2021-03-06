/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboulara <mboulara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:51:55 by mboulara          #+#    #+#             */
/*   Updated: 2019/10/22 07:59:14 by mboulara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define RESET "\x1B[0m"

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef	struct		s_cx
{
	char			*line;
	char			*func_name;
	unsigned char	flag;
	char			*file;
}					t_cx;

typedef int	(*t_cyph_f)(t_cx data);

typedef	struct		s_command
{
	char			*cyp_name;
	int				ret;
	t_cyph_f		func;
}					t_command;

typedef	enum		e_hash_flags
{
	p_FLAG = 1,
	q_FLAG = 2,
	r_FLAG = 4,
	s_FLAG = 8,
	f_FLAG = 16,
}					t_hash_flags;

int					parse_command(int argc, const char *argv[]);
int					parse_hash_flags(int argc, const char *argv[],
					t_cx data, t_cyph_f	f);
int					read_stdin(t_cx *data, t_cyph_f f);
int					read_file(const char **argv, t_cx *data, t_cyph_f f);
int					str_handler(int *argc, const char **argv, t_cx *data,
					t_cyph_f f);
int					ft_ssl(int cnt, const char **argv);
int					message_digest_md5(t_cx data);
int					message_digest_sh256(t_cx data);
int					message_digest_sh224(t_cx data);
int					print_usage_commands(t_cx data);
char				*stdjoin(char *des, char *src);
#endif
