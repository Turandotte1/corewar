/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:38:27 by mipham            #+#    #+#             */
/*   Updated: 2018/05/07 13:28:44 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft_all.h"
# include "op.h"
# include "asm_struct.h"

# define FC(x, y)			ft_putstr_color(x , y );

/*
** convert.c
*/
char		compile(t_champ *champ, char *path);

/*
** error.c
*/
void	asm_error(const char *str);
void	print_detailed_error(const char *av1);
void	free_champ(t_champ *champ);
void	close_asm(t_champ *champ, char *s);

/*
** get_instruct.c
*/
t_instruct	*new_instruct(void);
void		add_instruct_end(t_champ *champ, t_instruct *instruct);
int			get_instruct(t_champ *champ, char *line, int nb_bytes);
void		free_instructs(t_instruct *instructs);
int			params_size(t_instruct *instr);
/*
** get_label.c
*/

t_label	*new_label(void);
int		get_label_addr(t_label *labels, char *name);
int		label_value(t_param *param, int inst_addr, t_champ *c);
void	add_label_end(t_champ *champ, t_label *label);
void	free_labels(t_label *labels);

/*
** get_param_value.c
*/
int		check_params(t_instruct *inst);
void	param_value(t_param *param, int inst_addr, t_champ *c);
void	get_param_type(t_champ *c, t_param *param);
int		get_nb_bytes(t_instruct *instruct);
int		get_param(t_champ *c, t_instruct *inst, char *line);
/*
** method.c
*/
int		find_op(char *name);
char	*skip_comment_and_whitespace(char *str);
char	*trim_comment(char *line);
char	*get_name_or_comment(t_champ *c, char **content, char *str);
/*
** method2.c
*/
void	print_dbug(t_instruct *instr);
char	get_opc(t_instruct *instr);
int		get_progsize(t_champ *champ);
/*
** parse1.c
*/
void	parse_file(char *content, t_champ *champ);
char	*parse_header(char *content, t_champ *champ);
/*
** parse2.c
*/
char	*save_label_name(t_champ *champ, char *line, int nb_bytes);
void	parse_params(t_champ *champ);
void	parse_body(char *content, t_champ *champ);

#endif
