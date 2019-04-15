/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:55:49 by vkremen           #+#    #+#             */
/*   Updated: 2018/11/22 11:55:53 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# define SIGN(x) (x == '-' ? 1 : 0)

typedef	struct		s_struct
{
	int				plus;
	int				minus;
	int				sh;
	int				zero;
	int				space;
	int				prec;
	int				width;
}					t_struct_d;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				g_buff[10000];
int					g_step;
int					g_null;
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char const s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void	const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strrvr(char *str);
char				*ft_strcap(char *str);
char				*ft_strrep(char *str, int f, int c);
int					*ft_range(int min, int max);
char				*ft_slice(char *str, size_t start, size_t finish);
int					ft_printf(char *format, ...);
void				ft_printf_parcing(char *format, va_list ap);
int					find_len_type(char *format, int start);
void				find_type(char *res, va_list ap);
void				fill_buff(char *str);
void				check_type(char *type, char *res, va_list ap);
void				find_flags(char *res, t_struct_d *x);
void				find_flag_width(char *res, t_struct_d *x);
void				find_flag_precision(char *res, t_struct_d *x);
char				*return_int(va_list ap, char *type, t_struct_d x);
char				*return_unsigned(va_list ap, char *type, t_struct_d x);
char				*ft_itoa_base(unsigned long long int num, int base,
									char letter);
void				ft_num_base(unsigned long long num, int base,
									char **answer, char *str);
char				*return_oct(va_list ap, char *type, t_struct_d x);
char				*return_hex(va_list ap, char *type, t_struct_d x);
char				*return_other(va_list ap, char *type, t_struct_d x);
char				*ft_itoa_float(long double n, int prec);
char				*fill_answer(long double n, int lenbp, int lenap, int sign);
char				*return_answer(int lenbp, char **answer, int prec);
void				change_answer(char *answer, int x, int buff, int prec);
void				find_struct_int(char *num, char *type, t_struct_d x);
void				start_printf_int(char *num, t_struct_d x);
void				printf_all_flags(char *num, t_struct_d x);
void				printf_flag_plus(char *num, t_struct_d x);
void				printf_flag_minus(char *num, t_struct_d x);
void				printf_other_flags_part_1(char *num, t_struct_d x);
void				printf_other_flags_part_2(char *num, t_struct_d x);
void				start_printf_unsigned(char *num, t_struct_d x);
void				printf_all_flags_unsigned_oct_hex(char *num, t_struct_d x,
									int base, char *fl);
void				printf_flag_plus_unsigned(char *num, t_struct_d x);
void				printf_other_flags_unsigned(char *num, t_struct_d x);
void				start_printf_oct_hex(char *num, t_struct_d x,
									int base, char *fl);
void				pritf_flag_zero_oct_hex(char *num, t_struct_d x);
void				printf_other_flags_hex_part_1(char *num, t_struct_d x,
									char *fl);
void				printf_other_flags_hex_part_2(char *num, t_struct_d x,
									char *fl);
void				printf_other_flags_oct(char *num, t_struct_d x);
void				start_printf_float(char *num, t_struct_d x);
void				printf_flag_plus_float(char *num, t_struct_d x);
int					len_num_befor_point(char *num);
void				printf_flag_minus_float(char *num, t_struct_d x);
void				printf_other_flags_float(char *num, t_struct_d x);
void				start_printf_char_str(char *num, t_struct_d x, char *type);
void				printf_flag_minus_str(char *num, t_struct_d x);
void				printf_other_flags_str(char *num, t_struct_d x);
void				start_printf_pointer_percent(char *num, t_struct_d x,
									char *fl, char *type);
void				printf_other_flags_pointer(char *num, t_struct_d x,
									char *fl);
void				start_printf_percent(t_struct_d x);

#endif
