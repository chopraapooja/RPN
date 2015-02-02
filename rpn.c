#include <stdlib.h>

typedef char* String;


int evaluate(String expression) {
	String *splittedExpr;
	split(expression, &splittedExpr);

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