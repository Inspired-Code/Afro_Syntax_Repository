/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmodise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:38:02 by mmodise           #+#    #+#             */
/*   Updated: 2016/04/29 15:03:03 by mmakwakw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "grimly.h"
#include <stdlib.h>

void getnumdigit ( char *array, int *num1, int *num2 , int length)
{
	int i; 
	int j;

	i = 0;
	while (array[i] != 'x')
	i++;
	*num1  = i -1;
	j = 0;
	while (i < (length - 6))
	{
		i++;
		j++;
	}
	*num2 = j - 2;
}

void numstr ( char *array, char *num1, char *num2 , int length)
{
	int i; 
	int j; 

	i =0;
	while (array[i] != 'x')
	{
		num1[i] = array[i];
		i++;
	}
	i ++;
	j = 0;
	while (i < (length - 6))
	{
		num2[j] = array[i];
		i++;
		j++;
	}
}

char *listtoarray (t_list *list, int length)
{
	int i;
	char *array;
	t_list *temp;

	array = (char*) malloc (length * sizeof(char));
	temp = list;
	i = 0;
	while(temp != NULL)
	{
		array[i] = temp->data;
		write (1, &array[i], 1);
		temp = temp->next;
		i++;
	}
	array[length] = '\0';
	return (array);
}

void arraydispaly (char **array, int row, int col)
{
	int i; 
	int j; 
	
	i = 0;
	while (i < row)
	{ 
		j = 0;
		while (j < col)
		{
			write (1, &array[i][j],1);
			j++;
		}
		write (1, "\n",1);
		i++;
	}
}

int arraycheck (char **array, char *charectors, int row, int col)
{
	int i;
	int j;
	int state;
	i = 0;
	state = 1; 
	while (i < row && state == 1 ) 
	{
		j = 0;
		while (j < col && state == 1)
		{	
			if (array[i][j] != charectors[0] ||array[i][j] != charectors[1] ||
				array[i][j] != charectors[2] ||array[i][j] != charectors[3] ||
				array[i][j] != charectors[4] )
			{
				state = 1; 
			}
			j++;
		}
		i++;
	}
	return (state);
}

int main (int argc, char **argv)
{
	int fd;
	int i;
	int j;
	int state;
	int row;
   	int col;	
	char c;
	int length;
	char *charectors;
	char *array;
	t_list *infolist; 
	char *num1;
	char *num2;
	int num1digit;
   	int	num2digit;
	char ** maze;

	if (argc > 1)
	{
		fd = open (argv[1], O_RDONLY);
		if (fd != -1)
		{
			read(fd, &c, 1);
			infolist = ft_create_elem(c);
			length = 1;  
			while (c != '\n')
			{
				read(fd, &c, 1);
				ft_list_push_back(&infolist,c);
				length++;
			}
			array = listtoarray (infolist, length);
			charectors= (char*) malloc (5 * sizeof(char));
			charectors[0] = array[length -6];
		   	charectors[1]= array[length -5];
 			charectors[2] =  array[length -4];
 			charectors[3]= array[length -3] ;
			charectors[4] = array[length -2];
			
			getnumdigit ( array, &num1digit, &num2digit, length);	
			num1= (char*) malloc (num1digit * sizeof(char));
			num2= (char*) malloc (num2digit * sizeof(char));
			numstr (array, num1, num2 , length);

			row = ft_atoi(num1);
			col = ft_atoi(num2);
			
			if (row * col < 1000000000)
			{
				maze= (char**) malloc (row * sizeof(char*));
				i = 0; 
				while (i < row)
				{
					maze[i]= (char*) malloc (col * sizeof(char));
					i++;
				}
				i = 0;
				j = 0;
				state = 1;
				while (read(fd, &c, 1) && state  == 1)
				{
					if (c != '\n' && j == col)
					{
						state = 0;
						write (1, "MAP ERROR\n", 10);
					}
					else if (c == '\n' && j < col)
					{
						state = 0;
						write (1, "MAP ERROR\n", 10);
					}
					else if (c == '\n' && j == col) 
					{
						j = 0;
						i++;
					}
					else 
					{
						maze[i][j] = c; 
						j++;
					}
				}

				arraydispaly (maze, row, col);
			}
			else 
			{
				write (1, "MAP ERROR\n", 10);
			}
		}
	}
	return (0);
}
