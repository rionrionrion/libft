
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*old_lst;

	if (!f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	while (lst)
	{
		old_lst = ft_lstnew(f(lst->content));
		if (old_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, old_lst);
		lst = lst->next;
	}
	return (new_lst);
}
