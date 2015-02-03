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

void test_split6() {
	String *splittedExpr;
	String expression = "2 2 2 2 2 * * 2 + + 2 - *";

	split(expression, &splittedExpr);
	assert(strcmp(splittedExpr[0],"2")==0);
	assert(strcmp(splittedExpr[1],"2")==0);
	assert(strcmp(splittedExpr[2],"2")==0);
	assert(strcmp(splittedExpr[3],"2")==0);
	assert(strcmp(splittedExpr[4],"2")==0);
	assert(strcmp(splittedExpr[5],"*")==0);
	assert(strcmp(splittedExpr[6],"*")==0);
	assert(strcmp(splittedExpr[7],"2")==0);
	assert(strcmp(splittedExpr[8],"+")==0);
	assert(strcmp(splittedExpr[9],"+")==0);
	assert(strcmp(splittedExpr[10],"2")==0);
	assert(strcmp(splittedExpr[11],"-")==0);
	assert(strcmp(splittedExpr[12],"*")==0);
}
void test_evaluate0() {
	int result = evaluate("2 3 +");
	assert(result == 5);
}

void test_evaluate1() {
	int result = evaluate("2 3 -");
	assert(result == -1);
}

void test_evaluate2() {
	int result = evaluate("2 3 *");
	assert(result == 6);
}


void test_evaluate3() {
	int result = evaluate("2 3 /");
	assert(result == 0);
}

void test_evaluate4() {
	int result = evaluate("6 3 /");
	assert(result == 2);
}

void test_evaluate5() {
	int result = evaluate("2 3 4 + -");
	assert(result == -5);
}

void test_evaluate6() {
	int result = evaluate("1 2 3 4 5 * * * *");
	assert(result == 120);
}

void test_evaluate7() {
	int result = evaluate("2 2 2 * 2 - 3 + +");
	assert(result == 7);
}

void test_evaluate8() {
	int result = evaluate("2 2 2 2 2 * * 2 + + 2 - *");
	assert(result == 20);
}

void test_evaluate9() {
	int result = evaluate("2 2 - 2 2 2 * 2 - - -");
	assert(result == 0);
}



