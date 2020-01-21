/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:36:29 by hmoulher          #+#    #+#             */
/*   Updated: 2018/11/15 12:59:29 by hmoulher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 42
# define INF 1.0/0.0
# define LINF -1.0/0.0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <time.h>

typedef	struct	s_list {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct    s_normfriendly
{
    int                i;
    int                j;
    int                printed_char;
}                t_norm;

typedef struct    s_parameters
{
    char    specifier;
    char    *flags;
    int        widist;
    size_t    width;
    int        prexist;
    size_t    precision;
    char    *lenght;
    char    *arg;
    int        sign;
    int        maj;
    int        masterflag[3];
    int        isp;
    int        ismaj;
}                t_parameters;

void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *s, size_t nbyte);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_atoi(const char *nptr);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char			*ft_reverse(char *str);
void			ft_sort_integer_table(int *tab, int size);
char			*ft_strcat_malloc(char *str, char *buff);
char			*ft_strndup(const char *s, int n);
struct    tm    *ft_localtime(time_t *timep);

int             get_next_line(const int fd, char **line);

//PRINTF_PART

int             ft_printf(const char *format, ...);
char            *ft_crea0(int size, char g);
void            ft_printsign(t_parameters *stock);
void            ft_widthower(t_parameters *stock);
void            ft_switchmaster(char **switcher, t_parameters *stock);
char            *ft_convhex(unsigned long long in, char x);
char            *ft_convbin(unsigned long long in);
void            ft_masterprec(t_parameters *stock);
void            ft_printprec(t_parameters *stock);
char            *ft_plus_ou_moins(char *acheker);
char            *ft_convhoc(unsigned long long in);
void            detect_sign_n_maj(t_parameters *param);
int                detect_specifier(const char *format, int i,
    t_parameters *param);
void            detect_flags(const char *format, int *ptr_i,
    t_parameters *param);
void            detect_width(const char *str, int *ptr_i,
    t_parameters *param, va_list arg);
void            detect_prec(const char *str, int *p_i,
    t_parameters *par, va_list arg);
void            detect_len_d(const char *format, int i,
    t_parameters *param, va_list arg);
void            detect_len_f(const char *format, int i,
    t_parameters *param, va_list arg);
void            detect_arg_csp(t_parameters *param, va_list arg);
void            detect_arg_none(t_parameters *param, va_list arg);
void            detect_arg_hh(t_parameters *param, va_list arg);
void            detect_arg_h(t_parameters *param, va_list arg);
void            detect_arg_ll(t_parameters *param, va_list arg);
void            detect_arg_l(t_parameters *param, va_list arg);
void            detect_arg_none_xo(t_parameters *param, va_list arg);
void            detect_arg_hh_xo(t_parameters *param, va_list arg);
void            detect_arg_h_xo(t_parameters *param, va_list arg);
void            detect_arg_ll_xo(t_parameters *param, va_list arg);
void            detect_arg_l_xo(t_parameters *param, va_list arg);
void            check_specifier(const char *format, int i, t_parameters *param);
void            detect_flags_2(const char *format, int *ptr_i,
    t_parameters *param);
void            detect_flags_3(const char *format, int *ptr_i,
    t_parameters *param);
void            detect_prec2(t_parameters *pm);
void            init_t_parameters(t_parameters *param);
void            free_struct(t_parameters *param);
void            check_maj_specifier(t_parameters *param);
char            *ft_strndup(const char *s, int n);
char            *ft_strjoin_free(char *str, char *buff);
char            *ft_strjoin_eerf(char *str, char *buff);
char            *ft_unitoa(unsigned long long n);
char            *ft_ftoa(long double f, size_t prec);
char            *ft_convhsuite(void);
void            ft_arrondisorsuite(t_parameters *stock, int *i);
void            n(t_parameters *param, t_norm *nrm);

#endif
