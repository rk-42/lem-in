/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:27:41 by rakrouna          #+#    #+#             */
/*   Updated: 2019/11/16 21:25:20 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# include <sys/uio.h>

# define BUFF_SIZE 32
# define TRUE 1
# define FALSE 0

typedef struct		s_list
{
	void			*obj;
	size_t			dim;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

int					ft_atoi(const char *str);
int					ft_printf(const char *format, ...);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_countchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_abs(int x);
int					free_split(char **strs);
int					ft_scmp(const char *s, const char *s1, const char *s2);
int					exceeds_int(char *nb);
int					ft_puterr(char const *s, int ex);
void				*ft_memccpy(void *dst, const void *src, int c,
		size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
char				*ft_strcat(char *restrict dest, const char *restrict src);
char				*ft_strchr(const char *s, int c);
char				*ft_strndup(const char *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
		size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				**ft_strduptab(char **tab);
char				*ft_strnchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew2(void *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_facteursp(int nb);
int					ft_is_prime(int nb);
int					ft_pgcd(int a, int b);
int					ft_ppcm(int a, int b);
int					ft_sqrt(int nb);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_fstrjoin(char *s1, char *s2);
int					ft_rech_dichotomique(char *s, char **tab);
void				ft_sort_integer_table(int *tab, int size);
char				*ft_strcapitalize(char *str);
void				ft_print_words_tables(char **tab);
void				ft_tri_bulle(char **tab);
t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_prefix(t_btree *root,
		void (*applyf)(void *));
char				*ft_strrev(char *str);
t_list				*ft_strsplitlst(char const *str, char c);
void				ft_printlst(t_list *begin);
int					get_next_line2(const int fd, char **line, char **pitcher);
char				**ft_get_table(int *pos, int sizev, int sizeh, char **tab);
int					ft_tabcmp(char **tab1, char **tab2);
void				ft_cpytabat(char **tab, char **tab2, int i, int j);
char				*ft_strdupplus(char *src, char c);
char				*ft_strdupstr(char *src, char *str, int m);
int					ft_tablen(char **tab);
int					ft_strcountword(char *str, char c);
char				**ft_reverse_tab(char **tab);
void				ft_putstrendt(char *str);
void				ft_putin(char *t, int i, char c);
void				ft_putendll(char const *s);
int					ft_strcount(char *str, char c);
void				ft_putendlll(char const *s);

#endif
