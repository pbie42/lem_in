/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:46:32 by pbie              #+#    #+#             */
/*   Updated: 2018/09/30 14:55:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#define TRUE 1
#define FALSE 0
#define STOP "\033[0;0m"
#define EOC "\033[39m"
#define EOBG "\033[49m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[1m"
#define BLACK "\033[30m"
#define WHITE "\033[97m"
#define BWHITE "\033[1;97m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define BRED "\033[1;31m"
#define GREEN "\033[32m"
#define BGREEN "\033[1;32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define BMAGENTA "\033[1;35m"
#define CYAN "\033[36m"
#define BCYAN "\033[1;36m"
#define GRAY "\033[37m"
#define BGBLACK "\033[40m"
#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGBLUE "\033[44m"
#define BGMAGENTA "\033[45m"
#define BGCYAN "\033[1;46m"
#define BGLIGHT "\033[1;47m"
#define BGGRAY "\033[47m"
#define INVWHITE "\033[7;97m"
#define INVCYAN "\033[7;36m"
#define INVRED "\033[7;31m"
#define INVMAGENTA "\033[7;35m"
#define HT_PRIME_1 151
#define HT_PRIME_2 163
#define MINDIFF 2.25e-308
#define HT_INITIAL_BASE_SIZE 53

#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <ftw.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <termios.h>
#include <err.h>
#include <math.h>
#include "../libft/includes/libftprintf.h"

typedef int t_bool;

typedef struct s_h_item
{
	char *key;
	char *value;
} t_h_item;

typedef struct s_h_table
{
	int size;
	int base_size;
	int count;
	t_h_item **items;
} t_h_table;

typedef struct s_parse
{
	t_bool start;
	t_bool end;
	char *line;
	struct s_parse *next;

} t_parse;

void error(void);
t_h_table *ht_new(void);
t_h_item *ht_new_item(const char *k, const char *v);
void ht_free_item(t_h_item *i);
void ht_free_hash_table(t_h_table *ht);
int ht_hash(const char *s, const int a, const int m);
int ht_get_hash(const char *s, const int buckets, const int attempt);
void ht_insert(t_h_table *ht, const char *key, const char *value);
char *ht_search(t_h_table *ht, const char *key);
t_h_table *ht_new_sized(const int base_size);
t_h_table *ht_new(void);
void ht_resize(t_h_table *ht, const int base_size);
void ht_resize_up(t_h_table *ht);
long int ft_pow(int x, int n);
double ft_sqroot(double square);
double ft_floor(double x);
int ft_is_prime(const int x);
int ft_next_prime(int x);

#endif
