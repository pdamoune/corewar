/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:24:14 by pdamoune          #+#    #+#             */
/*   Updated: 2017/08/17 16:02:55 by pdamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRF_H
# define FT_PRF_H
# include "prf_color.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define AP				g_ap
# define FORM			g_form
# define ARG			g_arg

# define BUFFER			FORM.buffer
# define I				FORM.iformat
# define J				FORM.ibuffer
# define RET			FORM.ret
# define FD				FORM.fd

# define FLAG			ARG.flags
# define WIDTH			ARG.width
# define PRECI 			ARG.precision
# define MOD			ARG.modifier
# define TYPE			ARG.type

# define SIZE_BUF		150
# define ABS(X) 		X < 0 ? -X : X
# define TEST_COMB(X)	(1 << X)

/*
**	MACRO FLAGS.
**	The 5 first are the basic one of PRINTF
**	The other one are used to set up the hole padding.
*/

# define MINUS			(1 << 0)
# define ZERO			(1 << 1)
# define HASHTAG		(1 << 2)
# define SPACE			(1 << 3)
# define PLUS			(1 << 4)
# define NEGATIVE		(1 << 5)
# define OCTAL			(1 << 6)
# define BINARY			(1 << 7)
# define HEXA			(1 << 8)
# define PRECISION		(1 << 9)
# define MODIFIER		(1 << 10)
# define BIN_SP			(1 << 11)
# define BIN_HGT		(1 << 12)

# define FLAG_MINUS		(FLAG & MINUS)
# define FLAG_ZERO		(FLAG &	ZERO)
# define FLAG_HASHTAG	(FLAG & HASHTAG)
# define FLAG_SPACE		(FLAG & SPACE)
# define FLAG_PLUS		(FLAG & PLUS)
# define FLAG_NEGATIVE	(FLAG & NEGATIVE)
# define FLAG_OCTAL		(FLAG & OCTAL)
# define FLAG_BINARY	(FLAG & BINARY)
# define FLAG_HEXA		(FLAG & HEXA)
# define FLAG_PRECISION	(FLAG & PRECISION)
# define FLAG_MODIFIER	(FLAG & MODIFIER)
# define FLAG_BIN_SP	(FLAG & BIN_SP)
# define FLAG_BIN_HGT	(FLAG & BIN_HGT)
# define FLAG_SIGN		(FLAG & SIGN_FLAG)
# define SIGN_FLAG		0b111000

/*
**	MACRO MODIFIERS.
*/

# define CHAR			(1 << 0)
# define SHORT			(1 << 1)
# define LONG			(1 << 2)
# define LONG_LONG		(1 << 3)
# define MAX_T			(1 << 4)
# define SIZE_T			(1 << 5)
# define __MAX			(1 << 6)
# define MFD			(1 << 7)

# define MOD_HH			(MOD & CHAR)
# define MOD_H			(MOD & SHORT)
# define MOD_L			(MOD & LONG)
# define MOD_LL			(MOD & LONG_LONG)
# define MOD_J			(MOD & MAX_T)
# define MOD_Z			(MOD & SIZE_T)
# define MOD_K			(MOD & __MAX)
# define MOD_FD			(MOD & MFD)

/*
**	MACRO to set the flags of the differents types.
*/

# define TWO_FLAG		~(0b11100)
# define THREE_FLAG		~(0b11000)
# define FOUR_FLAG		~(0b00100)
# define FIVE_FLAG		~(0b00000)
# define NEG_FLAG		~(0b11000)

/*
**	Definition structures and unions.
*/

typedef struct s_conv	t_conv;
typedef struct s_form	t_form;
typedef struct s_arg	t_arg;
typedef	union u_data	t_data;

struct		s_conv
{
	int		id;
	void	(*fonction)();
};

struct		s_form
{
	char	buffer[SIZE_BUF];
	int		iformat;
	int		ibuffer;
	int		ret;
	int		fd;
};

struct		s_arg
{
	int		flags;
	int		width;
	int		precision;
	int		modifier;
	int		type;
};

union		u_data
{
	void			*ptr;
	wchar_t			*us;
	intmax_t		si;
	uintmax_t		ui;
	__uint128_t		vui;
};

/*
**	Declaration GLOBALS.
*/

t_arg		g_arg;
t_form		g_form;
va_list		g_ap;

/*
**	Mains Functions.
*/

int			ft_prf(const char *format, ...);
int			prf_parsing(const char *format);
void		prf_conversion(void);
void		prf_set_padding(char **data, int len);

/*
**	Padding Functions.
*/

void		prf_set_precision(int len, int c);
void		prf_set_prefixe(void);
void		prf_set_x(char *str);
void		prf_fill_c(int c);
void		prf_fill_data(char **data, int len);
int			prf_fill_wchar(int data);
int			prf_fill_buffer(const char *format);

/*
**	LIB PRINTF Functions.
*/

void		prf_color(const char *format);
void		prf_lltoa_base(char *result, long long n, unsigned int base);
void		prf_ulltoa_base(char *result, uintmax_t n, unsigned int base);
void		prf__ulltoa_base(char *result, __uint128_t n, unsigned int base);
void		prf_set_arg(t_data *data, int c);
size_t		prf_strlen_wchar(int *str);
int			prf_wctoa(char **wc_conv, unsigned int wc);

/*
**	Conversions Functions.
*/

void		prf_type_s(void);
void		prf_type_c(void);
int			prf_type_uc(void);
int			prf_type_us(void);
void		prf_type_d(void);
void		prf_type_u(void);
void		prf_type_x(void);
void		prf_type_o(void);
void		prf_type_b(void);

/*
**	LIBFT Functions.
*/

void		prf_bzero(void*s, size_t n);
int			prf_isdigit(int c);
int			prf_isspace(int c);
int			prf_isblank(int c);
int			prf_atoi(const char *str);
int			prf_strncmp(const char *str1, const char *str2, size_t n);
void		prf_strtoupper(char *str);
int			prf_toupper(int c);
size_t		prf_strlen(const char *str);
char		*prf_strrev(char *str);

#endif
