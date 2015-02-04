#include <assert.h>
#include "rpn.h"

typedef char* String;

void test_split_should_give_the_number_of_splitted_strings() {
	String *splittedExpr;
	String expression = "2 3 + 56 - -";
	int length = split(expression, &splittedExpr, " ");
	assert(length == 6);
}

void test_split_should_split_the_string_into_strings_by_provided_seprator() {
	String *splittedExpr;
	String expression = "2 3 +";

	split(expression, &splittedExpr, " ");
	assert(strcmp(splittedExpr[0],"2")==0);
	assert(strcmp(splittedExpr[1],"3")==0);
	assert(strcmp(splittedExpr[2],"+")==0);
}

void test_splitting_of_empty_string_with_space_will_give_0() {
	String *splittedExpr;
	String expression = "";
	int length = split(expression, &splittedExpr, " ");
	assert(length == 0);
}

void test_evaluate_2_3_plus_is_5() {
	int result = evaluate("2 3 +");
	assert(result == 5);
}

void test_evaluate_2_3_minus_is_negative_1() {
	int result = evaluate("2 3 -");
	assert(result == -1);
}

void test_evaluate_2_3_multiply_is_6() {
	int result = evaluate("2 3 *");
	assert(result == 6);
}


void test_evaluate_2_3_divide_is_0() {
	int result = evaluate("2 3 /");
	assert(result == 0);
}

void test_evaluate_6_3_divide_is_2() {
	int result = evaluate("6 3 /");
	assert(result == 2);
}

void test_evaluate_2_3_4_plus_minus_is_negative_5() {
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