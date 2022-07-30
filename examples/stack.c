#include "../libs/libft/libft.h"
#include <stdio.h>

// cc examples/stack.c -C -g3 ./libs/libft/*.c -o stack

typedef struct s_stack {
	int size;
	int top;
	char **items;
}	t_stack;

t_stack	*init_stack(int stack_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->items = (char **)malloc(sizeof(char *) * (stack_size + 1));
	stack->items[stack_size] = NULL;
	stack->top = -1;
	stack->size = stack_size;
	return (stack);
}

int	get_size(t_stack *stack)
{
	return (stack->top + 1);
}

int	is_full(t_stack *stack)
{
	return ((stack->top + 1) == stack->size);
}

int	is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int	push(t_stack *stack, char *el)
{
	if (is_full(stack))
		return (1);
	stack->items[++stack->top] = ft_strdup(el);
	printf("pushed element %s to stack\n", stack->items[stack->top]);
	return (0);
}

char	*pop(t_stack *stack)
{
	if (is_empty(stack))
		return (NULL);
	return (stack->items[stack->top--]);
}

char	*check(t_stack *stack)
{
	if (is_empty(stack))
		return (NULL);
	return (stack->items[stack->top]);
}

int	free_stack(t_stack *stack)
{
	while (--stack->size > -1)
		free(stack->items[stack->size]);
	free(stack->items);
	free(stack);
	return (0);
}

int	main(void)
{
	t_stack	*st;
	char *out;

	st = init_stack(5);
	push(st, "hello");
	push(st, "wild");
	push(st, "overflow");
	push(st, "test");
	for (int i = 0; i < 10; i++)
	{
		out = check(st);
		printf("out: %s\n", out);
		pop(st);
		out = check(st);
		printf("check: %s\n", out);
	}
	free_stack(st);
}
