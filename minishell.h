/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:55:06 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/27 11:46:12 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "parsing/parsing.h"

typedef struct s_id
{
	pid_t		id;	
	struct s_id	*next;
}	t_id;

int		check_str(t_lst *str);
int		str_checker(char *str);
int		ft_lstsize(t_lst **lst);
int		ft_echo(t_parsing *pars);
int		ft_lstsize(t_lst	**lst);
int		ft_strcmp(char *s01, char *s02);
int		push(t_lst **stack, char *elem);
int		ft_unset(t_lst **lst, char *str);
int		first_func_utils(t_parsing *pars);
int		first_func(t_parsing *pars, int i, t_lst *lst);
int		find_redirs(int	*f, t_parsing *parse);
int		ft_export(t_lst **lst, t_lst **lst1, char *str1);
int		ft_cd(char *str, t_lst **lst, t_lst **lst1);
int		secend_func(t_parsing *pars, t_lst **lst, t_lst **lst1, int a);
int		secd_func_utils(t_parsing *pars, t_lst **lst, t_lst **lst1, int a);
int		check_cmd(int a, int b);

/*******************************************************/

char	*ft_pwd(t_lst *lst);
char	*shlvl(char *str);
char	*add_quotes_str(char *str);
char	*shlvl_with_quotes(char *str);
char	*ft_strchr_v2(const char *s, int c);
char	*find_path(char	**envp, char **cmd);
char	*strjoin_free(char *str1, char *str2, int i);

/*******************************************************/

char	**lst_to_char(t_lst *lst);

/*******************************************************/

void	tolowes(char *c);
void	free_id(t_id *id);
void	wait_id(t_id *id);
void	sig_handle(int sig);
void	sigquithandler(int sig);
void	b_sort(t_lst **lst);
void	swap_pwd(t_lst **lst);
void	free_tab(char	**tab);
void	ft_bzero(void *s, size_t n);
void	add_quotes_lst(t_lst **str);
void	ft_env(char **str, t_lst **lst);
void	addback_id(t_id *lst, t_id *new);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	change_env(char *str, t_lst **lst, char *cnt);
void	my_execv(char **str1, char **env, t_lst *lst);
void	print_lst(t_lst *lst, int i, t_parsing *pars);
void	execute_command(char	**envp, char	**cmd);
void	execute(t_parsing *parse, t_lst **lst, t_lst **lst1);
void	check_readline(t_lst **lst, t_lst **lst1, t_parsing *pars);

/*******************************************************/

t_lst	*ft_lstnew(char *nb);
pid_t	pipex(t_parsing	*parse, t_lst **lst, t_lst **lst1, int i);
pid_t	single_cmd(t_parsing *parse, t_lst **lst, t_lst **lst1, int i);
t_id	*init_id(pid_t id);

#endif