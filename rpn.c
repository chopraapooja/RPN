#include <stdlib.h>
#include "stack.h"
#include "rpn.h"

typedef char* String;
int isOperation(String token);
int operate(int op1, int op2, String operation);
void onOperation(Stack *stack,  String operation);
void onOperand(Stack *stack, String operandStr);
int parseInt(void *intRef);

int parseInt(void *intRef) {
	int a=*((int*)intRef);
	return a;
}

void pushInt(Stack *stack, int number) {
	int *answer = malloc(sizeof(int));
	*answer = number;
	printf("Address of stack in pushINT %p\n",stack );


	printf("INSIDE PUSH_INT\n");
	printf("Address of answer: %p\n", &answer);
	printf("Value of answer: %p\n", answer);
	printf("Value of *answer: %d\n", *answer);
	printf("Value of stack: %p\n", stack);
	push(stack, answer);

}

void onOperation(Stack *stack,  String operation){

	int op1, op2, *answer, ans;
	printf("Address of stack in onOperation %p\n",stack );
	
	op1 = parseInt(pop(stack));
	op2 = parseInt(pop(stack));
	// printf("AT THE BEGINNING OPERATION IS : %p\n", operation);
	// printf("AT THE BEGINNING OPERATION CONTAINS : [[%s]]\n", operation);

	ans = operate(op1,op2,operation);
	printf("before HAHAHAHAHAHA %s\n", operation);

	pushInt(stack, ans);
	printf("HAHAHAHAHAHA %s\n", operation);

	// printf("AT THE END OPERATION IS : %p\n", operation);
	// // printf("AT THE END OPERATION CONTAINS : [[%s]]\n", operation);
	// answer = malloc(sizeof(int));
	// printf("Answer is: %d\n", ans);
	// *answer = ans;
	// push(stack, answer);
}

void onOperand(Stack *stack, String operandStr) {

	int *operand = malloc(sizeof(int));
	printf("Address of stack in onOperand %p\n",stack );

	*operand = atoi(operandStr);
	push(stack, operand);
}

Status evaluate(String expressionStr) {
	String *expression,str;
	Stack stack = createStack();
	int i=0,*result;
	Status status;
	// printf("Address of stack in evaluate %p\n",&stack );
	// Stack *stack = malloc(sizeof(Stack));
	// stack->top = fooStack.top;
	// stack->height = fooStack.height;

	split(expressionStr, &expression," ");
	while((expression[i] != NULL)) {
		printf("THIS %s\n",expression[i]);

		if(isOperation(expression[i])){
			strcpy(str, expression[i]);
			onOperation(&stack, str);
		}
		else {
			onOperand(&stack,expression[i]);
		}
		i++;
	}
	result = (int*)pop(&stack);
	status.result = *result;
	status.error = 0;
	return status;
}

int operate(int op1, int op2, String operation) {
	switch(operation[0]){
		case '+': return op2 + op1; 
		case '*': return op2 * op1;
		case '-': return op2 - op1;
		case '/': return op2 / op1;
		default : return;
	}
}

int isOperation(String token) {
	switch(token[0]){
		case '+': return 1; 
		case '*': return 1;
		case '-': return 1;
		case '/': return 1;
		default : return 0;
	}
}

int split(String expression, String **splitted, String _seprator){
	String seprator = _seprator;
	String *splittedExpr = malloc(sizeof(String*)*20);
	String token,expr[50];
	int i=0;

	strcpy(expr, expression);
	token = strtok(expr, seprator);
	while( token != NULL ) 
   	{
   		// printf("Inside split, i is %d\n", i);
		splittedExpr[i++] = token;
		// printf("Split Expression of %d is %s\n", i, splittedExpr[i-1]);
      	token = strtok(NULL, seprator);
   	}
   	// printf("Inside split, i is %d\n", i);

   	*splitted = splittedExpr;
   	splittedExpr[i] = NULL;
   	return i;
}