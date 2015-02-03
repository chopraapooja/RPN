#include "stack.h"
#include <stdlib.h>


Stack createStack(void) {
	Stack s = {NULL,NULL};
	return s;
}
Node* create_node(void *data) {
	Node *n = malloc(sizeof(Node));
	n->data = data;
	n->back = NULL;
	return n;
}

int push(Stack *stack, void *element) {
	Node *node = create_node(element);
	node->back = stack->top;
	stack->top = node;
	return ++stack->height;
}

void * pop(Stack *stack) {
	void *element;
	if(!stack->top) return NULL;
	element = stack->top->data;
	stack->top = stack->top->back;
	return element;
}