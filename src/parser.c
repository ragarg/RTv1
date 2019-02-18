/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:14:19 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 16:05:45 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char			*get_word(char *line)
{
	while (*line && *line != ' ')
		line++;
	while (*line == ' ')
		*line++ = '\0';
	return (line);
}

static void		get_sphere(t_param *p, int fd, char *line)
{
	char	*word2;
	char	*word3;

	sp_real(p);
	if ((get_next_line(fd, &line)) == -1)
		STOP;
	while (line && *line && *line != ' ')
	{
		word2 = get_word(line);
		word3 = get_word(word2);
		if (*word3 == '0' && *(word3 + 1) == 'x')
			word3 += 2;	
//		printf("%s  %s  %s\n", line, word2, word3);
		if (!ft_strcmp(line, "color"))
			p->sp[p->sp_count - 1].color = ft_atoi_base(word3, 16);
		else if (!ft_strcmp(line, "center"))
			p->sp[p->sp_count - 1].cen = get_vec(word3);
		else if (!ft_strcmp(line, "radius"))
			p->sp[p->sp_count - 1].rad = get_double(word3);
		else if (!ft_strcmp(line, "specular"))
			p->sp[p->sp_count - 1].specular = get_double(word3);
		else if (!(*line == '/' && *(line + 1) == '/'))
			STOP;
		if ((get_next_line(fd, &line)) == -1)
			STOP;
	}
}

static void		get_light(t_param *p, int fd, char *line)
{
	char	*word2;
	char	*word3;

	l_real(p);
	p->l[p->l_count - 1].pos = vec_new(0.0, 0.0, 0.0);
	p->l[p->l_count - 1].intens = 0.5;
	p->l[p->l_count - 1].dir = vec_new(0.0, 0.0, 1.0);
	if ((get_next_line(fd, &line)) == -1)
		STOP;
	while (line && *line && *line != ' ')
	{
		word2 = get_word(line);
		word3 = get_word(word2);
//		printf("%s  %s  %s\n", line, word2, word3);
		if (!ft_strcmp(line, "type"))
		{
			if (!ft_strcmp(word3, "ambient"))
				p->l[p->l_count - 1].type = ambient;
			else if (!ft_strcmp(word3, "point"))
				p->l[p->l_count - 1].type = point;
			else if (!ft_strcmp(word3, "direct"))
				p->l[p->l_count - 1].type = direct;
			else
				STOP;
		}
		else if (!ft_strcmp(line, "position"))
			p->l[p->l_count - 1].pos = get_vec(word3);
		else if (!ft_strcmp(line, "intensity"))
			p->l[p->l_count - 1].intens = get_double(word3);
		else if (!ft_strcmp(line, "direction"))
			p->l[p->l_count - 1].dir = get_vec(word3);
		else if (!(*line == '/' && *(line + 1) == '/'))
			STOP;
		if ((get_next_line(fd, &line)) == -1)
			STOP;
	}
}

void			read_file(t_param *p, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		STOP;
	if ((get_next_line(fd, &line)) == -1)
		STOP;
	while (line)
	{
//		printf("%s\n", line);
		if (!ft_strcmp(line, "/light"))
			get_light(p, fd, line);
		else if (!ft_strcmp(line, "/sphere"))
			get_sphere(p, fd, line);
		else if (!(*line == '/' && *(line + 1) == '/'))
		{
			while (line[i] == ' ')
				i++;
			if (line[i])
				STOP;
			i = 0;
		}
		if ((get_next_line(fd, &line)) == -1)
			STOP;
	}
}
