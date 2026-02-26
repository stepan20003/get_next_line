/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ststepan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:48:56 by ststepan          #+#    #+#             */
/*   Updated: 2026/02/25 16:48:58 by ststepan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


char    *ft_get_line(char *remainder)
{
    int i;
    int j;
    char *p;
    i = 0;
    j=0;
    if(!remainder || !remainder[0])
        return(NULL);
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (remainder[i] == '\n')
        i++;
    p = malloc(i+1);
    if (!p)
        return(NULL);
    i = 0;
    while (remainder[i] && remainder[i] != '\n')
        p[j++]=remainder[i++];
    if (remainder[i] == '\n')
        p[j++] = '\n';
    p[j]='\0';
    return(p);
}
char *ft_get_remainder(char *remainder)
{
    int i;
    int j;
    char *p;
    i = 0;

    if(!remainder || !remainder[0])
        return(free(remainder),NULL);
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (remainder[i] == '\n')
        i++;
    if (!remainder[i])
        return (free(remainder), NULL);
    p = malloc(ft_strlen(&remainder[i])+1);
    if (!p)
        return(NULL);
     j = 0;
    while (remainder[i])
        p[j++] = remainder[i++];
    p[j] = '\0';
    return(free(remainder),p);
}
char *get_next_line(int fd)
{
    static char *remainder;
    char buffer[BUFFER_SIZE +1];
    char *line;
    int byites;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    byites =1;
    while(!ft_strchr(remainder,'\n') && byites != 0)
    {
        byites=read(fd,buffer,BUFFER_SIZE);
    if(byites<0)
        return(NULL);
    buffer[byites]= '\0';
    remainder=ft_strjoin(remainder,buffer);
    }
    line=ft_get_line(remainder);
    remainder=ft_get_remainder(remainder);
    return(line);
}