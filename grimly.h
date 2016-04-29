/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmodise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:32:48 by mmodise           #+#    #+#             */
/*   Updated: 2016/04/28 23:53:36 by mmodise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__GRIMLY_H_
# define	__GRIMLY_H_
# include <stdlib.h>

typedef struct 		s_list 
{	
		struct s_list 	*next;
		char			data; 	

}					t_list;

void    ft_list_push_back(t_list **begin_list, char data);
t_list  *ft_create_elem(char data);
int     ft_atoi(char *str);
int ft_strlen(char *str);
int     ft_pow(int pow, int in_v);

#endif 
