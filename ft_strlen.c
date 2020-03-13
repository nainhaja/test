/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:45:12 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/22 21:44:03 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
# include <stdlib.h>
#include <stdio.h>
size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int main()
{
	//typedef struct Coordonnees Coordonnees;
typedef struct Coordonnees
{
    int x;
    int y;
}Coordonnees;
 Coordonnees point;
    
    point.x = 10;
    point.y = 20;

//printf("hh %d %d",2*64 + 52,180);
}
