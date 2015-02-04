#include <stdlib.h>
#include "stack.h"
#include "rpn.h"

typedef char* String;
int isOperation(String token);
int operate(int op1, int op2, String operation);



Status evaluate(String expression) {
	String *splittedExpr,oper;
	Stack stack = createStack();
	int i=0,op1,op2,*result,*answer,*operand;
	Status status;
	split(expression, &splittedExpr," ");
		
	while((splittedExpr[i] != NULL)) {
		if(!isOperation(splittedExpr[i])){
			operand = malloc(sizeof(int));
			*operand = atoi(splittedExpr[i]);
			push(&stack, operand);
		}
		else {
			op1 = *((int*)pop(&stack));
			op2 = *((int*)pop(&stack));
			oper = splittedExpr[i];

			answer = malloc(sizeof(int));
			*answer = operate(op1,op2,oper);
			push(&stack, answer);
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
		splittedExpr[i++] = token;
      	token = strtok(NULL, seprator);
   	}
   	*splitted = splittedExpr;
   	splittedExpr[i] = NULL;
   	return i;
}