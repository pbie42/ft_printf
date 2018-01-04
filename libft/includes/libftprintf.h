/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:25:33 by pbie              #+#    #+#             */
/*   Updated: 2018/01/03 12:57:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define BUFF_SIZE 32

# define TRUE 1
# define FALSE 0
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BWHITE "\033[1;97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define BRED "\033[1;31m"
# define GREEN "\033[32m"
# define BGREEN "\033[1;32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BMAGENTA "\033[1;35m"
# define CYAN "\033[36m"
# define BCYAN "\033[1;36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[1;46m"
# define BGLIGHT "\033[1;47m"
# define BGGRAY "\033[47m"
# define INVWHITE "\033[7;97m"
# define INVCYAN "\033[7;36m"
# define INVRED "\033[7;31m"
# define INVMAGENTA "\033[7;35m"

# include <inttypes.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef int					t_bool;

typedef unsigned int		t_ui;

typedef unsigned long long int					t_ulli;

typedef struct		s_pf_flags
{
	t_bool			minus;
	t_bool			plus;
	t_bool			hash;
	t_bool			zero;
	t_bool			space;
}					t_pf_flags;

typedef struct		s_pf_lmods
{
	t_bool			hh;
	t_bool			h;
	t_bool			l;
	t_bool			ll;
	t_bool			j;
	t_bool			z;
	t_bool			p;
}					t_pf_lmods;

typedef struct		s_pf_cspecs
{
	t_bool			s;
	t_bool			lg_s;
	t_bool			p;
	t_bool			d;
	t_bool			lg_d;
	t_bool			i;
	t_bool			o;
	t_bool			lg_o;
	t_bool			u;
	t_bool			lg_u;
	t_bool			x;
	t_bool			lg_x;
	t_bool			c;
	t_bool			lg_c;
	t_bool			percent;
}					t_pf_cspecs;

typedef struct		s_pf_item
{
	t_pf_flags		*flags;
	t_pf_lmods		*lenmods;
	t_pf_cspecs		*cspecs;
	int				field_w;
	int				precision;
	int				bytes;
	intmax_t		num;
}					t_pf_item;

typedef struct		s_pf
{
	int				pos;
	int				bytes;
	t_bool			len_error;
	const char		*format;
}					t_pf;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	t_list			*list;
	t_list			*begin;
	char			*l;
}					t_gnl;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_check_white(char *s);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				char_swap(char *p1, char *p2);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_non_white(char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(const char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_wordcount(char const *s, char c);
void				ft_swap(int *a, int *b);
char				*ft_strndup(const char *s1, size_t n);
int					ft_get_next_line(int const fd, char **line);
void				ft_putstrtab(char **tab);
int					ft_tablen(char **tab);
void				ft_exit(const char *message);
char				**ft_buildtab(int j);
int					ft_includes_char(char *s, char c);
void				ft_putendlnbr(char *s, int num);
int					ft_printf(const char *format, ...);
void				check_format(const char *format);
int					ft_isconversion(char c);
int					ft_islmod(char c);
int					ft_isflag(char c);
void				handle_flag(t_pf *pf, t_pf_item *pfi);
void				handle_identifier(t_pf *pf, va_list args);
void				handle_precision(t_pf *pf, t_pf_item *pfi);
void				handle_field_width(t_pf *pf, t_pf_item *pfi);
void				handle_len_mod(t_pf *pf, t_pf_item *pfi);
void				handle_conversion(t_pf *pf, t_pf_item *pfi);
t_pf_item			*init_pfi(t_pf_item *pfi);
void				print_pfi(t_pf_item *pfi);
void				print_percentage(t_pf_item *pfi);
void				print_identifier(t_pf_item *pfi, va_list args);
void				print_invalid_identifier(t_pf *pf, t_pf_item *pfi);
void				print_int(t_pf_item *pfi, intmax_t num);
void				print_unsigned_int(t_pf_item *pfi, intmax_t num);
void				print_long(t_pf_item *pfi, long num);
void				print_address(t_pf_item *pfi, long int num);
void				print_hex(t_pf_item *pfi, intmax_t n);
void				print_hex_long(t_pf_item *pfi, long long int num);
void				print_hex_long_prefix(t_pf_item *pfi);
void				print_oct(t_pf_item *pfi, intmax_t n);
void				print_char(t_pf_item *pfi, unsigned char c);
void				print_string(t_pf_item *pfi, char *s);
void				print_wide_char(t_pf_item *pfi, wint_t wide);
void				print_prefix(t_pf_item *pfi);
void				print_int_zero_space(t_pf_item *pfi, int i, int prcsn);
void				print_zero_space(t_pf_item *pfi);
void				print_zero_byte(t_pf_item *pfi);
void				print_plus_byte(t_pf_item *pfi);
void				print_x_ul(t_pf_item *pfi, char *num);
void				print_o_ul(t_pf_item *pfi, char *num);
void				print_space_byte(t_pf_item *pfi);
void				print_hex_max(t_pf_item *pfi, intmax_t num);
void				print_wide_string(t_pf_item *pfi, wchar_t *ws);
void				get_int_type(t_pf_item *pfi);
int					int_length(intmax_t num);
int					long_length(long num);
char				*ft_dec_to_hex(uintmax_t n);
char				*ft_dec_to_hex_long(t_ulli n);
char				*ft_dec_to_hex_max(uintmax_t n);
char				*ft_address_to_hex(long int n);
intmax_t			ft_dec_to_oct(intmax_t decimal_number);
uintmax_t			unsigned_int_setup(t_pf_item *pfi, intmax_t num);
void				ft_strrev(char *s);
char				*ft_strupper(char *s);
char				*ft_strlower(char *s);
char				*ft_llitoa(intmax_t n);
void				free_pfi(t_pf_item *pfi);
int					get_wide_char_length(wint_t wide);
t_bool				ft_not_conversion_space(char c);
int					ft_ws_strcmp(const wchar_t *s1, const wchar_t *s2);
int					ft_ws_width(wchar_t *ws);
int					print_zero_space_ws(t_pf_item *pfi, int width);
char				*oct_malloc(char *str);
char				*oct_change(t_pf_item *pfi, intmax_t n);

#endif
