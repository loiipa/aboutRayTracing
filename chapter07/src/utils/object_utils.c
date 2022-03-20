#include "utils.h"

// object연결해주기
void	oadd(t_object **list, t_object *newobj)
{
	t_object	*cur;

	// 맨 앞
	if (*list == NULL)
	{
		*list = newobj;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = newobj;
}

t_object	*olast(t_object *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
