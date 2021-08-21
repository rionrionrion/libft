
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old_lst;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		old_lst = *lst;
		*lst = old_lst->next;
		free(old_lst);
	}
	lst = NULL;
}
