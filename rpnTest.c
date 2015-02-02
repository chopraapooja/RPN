#include <assert.h>
#include "rpn.h"

typedef char* String;

void test_split0() {
	String *splittedExpr;
	String expression = "2 3 +";
	int length = split(expression, &splittedExpr);
	assert(length == 3);
}

void test_split1() {
	String *splittedExpr;
	String expression = "2 3 +";

	split(expression, &splittedExpr);
	assert(strcmp(splittedExpr[0],"2")==0);
	assert(strcmp(splittedExpr[1],"3")==0);
	assert(strcmp(splittedExpr[2],"+")==0);
}

void test_split2() {
	String *splittedExpr;
	String expression = "2 3 4 + -";

	split(expression, &splittedExpr);
	assert(strcmp(splittedExpr[0],"2")==0);
	assert(strcmp(splittedExpr[1],"3")==0);
	assert(strcmp(splittedExpr[2],"4")==0);
	assert(strcmp(splittedExpr[3],"+")==0);
	assert(strcmp(splittedExpr[4],"-")==0);
}


void test_split3() {
	String *splittedExpr;
	String expression = "1 2 3 4 5 * * * *";

	split(expression, &splittedExpr);
	assert(strcmp(splittedExpr[0],"1")==0);
	assert(strcmp(splittedExpr[1],"2")==0);
	assert(strcmp(splittedExpr[2],"3")==0);
	assert(strcmp(splittedExpr[3],"4")==0);
	assert(strcmp(splittedExpr[4],"5")==0);
	assert(strcmp(splittedExpr[5],"*")==0);
	assert(strcmp(splittedExpr[6],"*")==0);
	assert(strcmp(splittedExpr[7],"*")==0);
	assert(strcmp(splittedExpr[8],"*")==0);
}

void test_split4() {
	String *splittedExpr;
	String expression = "";
	int length = split(expression, &splittedExpr);
	assert(length == 0);
	// assert(strcmp(splittedExpr[0],"")==0);
}

void test_split5() {
	String *splittedExpr;
	String expression = " ";
	int length = split(expression, &splittedExpr);
	assert(length == 0);
}