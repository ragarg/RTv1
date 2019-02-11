/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:46:47 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/20 16:51:37 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_fd_list
{
	int					fd;
	int					start;
	char				*buff;
	struct s_fd_list	*next;
	struct s_fd_list	*previous;
}				t_fd_list;

# define BUFF_SIZE 4096

int			get_next_line(int const fd, char **line);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *destptr, const char *srcptr);
char			*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char			*ft_strcat(char *destptr, const char *srcptr);
char			*ft_strncat(char *destptr, const char *srcptr, size_t num);
size_t			ft_strlcat(char *destptr, const char *srcptr, size_t num);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strrchr(const char *string, int symbol);
char			*ft_strstr(const char *string1, const char *string2);
char			*ft_strnstr(const char *string1, const char *string2,
							size_t num);
int				ft_strcmp(const char *string1, const char *string2);
int				ft_strncmp(const char *string1, const char *string2,
						size_t num);
int				ft_atoi(const char *string);
int				ft_isalpha(int ch);
int				ft_isdigit(int num);
int				ft_isalnum(int ch);
int				ft_isascii(int ch);
int				ft_isprint(int ch);
int				ft_toupper(int character);
int				ft_tolower(int character);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memccpy(void *dest, const void *src, int c, size_t num);
void			*ft_memmove(void *dst, const void *src, size_t num);
void			*ft_memchr(const void *ptr, int value, size_t num);
int				ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
void			*ft_memset(void *dest, int c, size_t num);
int				ft_atoi(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
char			*ft_strndup(const char *src, size_t num);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_striter(char *s, void (*f)(char *));
t_list			*ft_lstnew(void const *content, size_t content_size);
int				get_next_line(const int fd, char **line);

#endif
