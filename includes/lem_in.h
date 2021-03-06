/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:46:32 by pbie              #+#    #+#             */
/*   Updated: 2018/11/01 12:06:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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
# define HT_PRIME_1 151
# define HT_PRIME_2 163
# define HT_INITIAL_BASE_SIZE 53

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <err.h>
# include <math.h>
# include "../libft/includes/libftprintf.h"

typedef int	t_bool;

typedef struct		s_link
{
	char			*key;
	struct s_link	*next;
}					t_link;

typedef struct		s_ant
{
	int				num;
	t_bool			moved;
}					t_ant;

typedef struct		s_room
{
	char			*name;
	t_ant			*ant;
	t_bool			start;
	t_bool			end;
	t_bool			occupied;
	t_bool			visited;
	t_bool			hidden;
	t_link			*link;
	struct s_room	*parent;
	struct s_room	*end_parent;
}					t_room;

typedef struct		s_qv
{
	t_room			*room;
	int				level;
	struct s_qv		*prev;
	struct s_qv		*next;
}					t_qv;

typedef struct		s_a_list
{
	t_ant			*ant;
	struct s_a_list	*next;
}					t_a_list;

typedef struct		s_paths
{
	t_qv			*path;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_bfs
{
	t_qv			*s_vis;
	t_qv			*s_que;
	t_qv			*e_vis;
	t_qv			*e_que;
	t_room			*tmp_room;
	t_bool			end_found;
	t_link			*links;
}					t_bfs;

typedef struct		s_data
{
	int				ants;
	int				ant_num;
	int				end_ants;
	int				num_rooms;
	char			*start;
	char			*end;
	t_a_list		*moved;
	t_paths			*paths;
	t_qv			*rooms;
}					t_data;

typedef struct		s_parse
{
	char			*line;
	int				lines;
	int				rooms;
	t_bool			ants_done;
	t_bool			rooms_done;
	t_bool			start_found;
	t_bool			end_found;
}					t_parse;

typedef struct		s_move
{
	t_qv			*tmp_path;
	int				print_space;
	t_bool			moved_an_ant;
}					t_move;

int					list_length(t_qv *list);
t_a_list			*add_to_moved(t_a_list *moved, t_ant *ant, t_data *data);
t_a_list			*remove_from_moved(t_a_list *moved, int ant_num);
t_a_list			*clear_moved(t_a_list *moved, t_data *data);
t_bool				ft_is_num(const char *string);
t_bool				ft_only_white(char *s);
t_bool				is_ants(char *line, t_data *data);
t_bool				is_command(const char *line);
t_bool				is_comment(char *line);
t_bool				is_link(char *line);
t_bool				is_room(const char *line);
t_bool				move_ants(t_qv *path, t_data *data);
t_link				*l_new(char *key);
t_room				*find_room(t_qv *rooms, char *key);
t_qv				*add_to_start(t_qv *head, t_qv *new_link);
t_qv				*new_link(t_room *room, int level);
t_qv				*remove_from_queue(t_qv *start);
t_qv				*which_queue(t_qv *start, t_qv *end);
void				add_to_end(t_qv *head, t_qv *new_link);
void				add_to_q(t_qv *start, t_qv *new_link);
void				bfs(t_data *data);
void				construct_paths(t_room *end, t_data *data);
void				error(const char *msg, t_data *data, char *line);
void				error_empty();
void				ft_free_matrix(char **matrix);
void				handle_move(t_move *m, t_data *data);
void				handle_start(t_move *m, t_data *data);
void				l_add_end(t_room *room, t_link *new_link);
void				l_free(t_link *start);
void				link_parse(t_parse *p, t_data *data);
void				parse(t_data *data);
void				parse_ants(char *line, t_data *data);
void				path_error(const char *msg, t_data *data, t_bfs *bfs);
void				print_links(t_room *room);
void				print_move(int ant_num, char *room_name);
void				print_path(t_qv *path);
void				room_parse(t_parse *p, t_data *data);
void				set_found_command(t_parse *p);
void				traversal(t_data *data);

#endif
