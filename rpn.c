#include <stdlib.h>
#include "stack.h"

typedef char* String;
int isOperation(String token);
int operate(int op1, int op2, String operation);

int evaluate(String expression) {
	String *splittedExpr,oper;
	Stack stack = createStack();
	int i=0,op1,op2;
	split(expression, &splittedExpr);
	
	while((splittedExpr[i] != NULL)) {
		if(!isOperation(splittedExpr[i])){
			push(&stack, splittedExpr[i]);
		}
		else {
			op1 = atoi((char*)pop(&stack));
			op2 = atoi((char*)pop(&stack));
			oper = splittedExpr[i];
			return operate(op1,op2,oper);
		}
		i++;
	}
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

int split(String expression, String **splitted){
	String seprator = " ";
	String *splittedExpr = malloc(sizeof(String*)*10);
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