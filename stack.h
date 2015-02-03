typedef struct Stack Stack;
typedef struct Node Node;

struct Node{
	void *data;
	Node *back;
};

struct Stack {
	Node* top;
	int height;
};

Stack createStack(void);
int push(Stack*, void *);
void * pop(Stack *);