#include "stack.h"

int	main(void)
{
	t_stack stack;
	int	*data;

	init_stack(&stack);
	for (int i = 0; i < 10; i++)
		push(&stack, i);

	swap(&stack);
	rotate(&stack);

	data = stack.bottom->content;
	ft_printf("bottom: %d\n", *data);

	print_stack(stack);
	ft_lstclear(&stack.top, free);
	return (0);
}
