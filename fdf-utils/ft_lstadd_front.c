/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:35:21 by mbenouis          #+#    #+#             */
/*   Updated: 2024/12/09 01:09:24 by mbenouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
void print_list(t_list *a)
{

	while(a)
	{
		printf("%s\n",(char *)a->content);
		a = a->next;
	}
}

int main(void){
	t_list *a;
	char *l;

	l = "dfsadfds";
	a = ft_lstnew((void *)l);
	print_list(a);
	ft_lstadd_front(&a,ft_lstnew("asdasdasd"));
	print_list(a);
	return 0;
}*/
