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
	Status s = evaluate("2 3 +");
	assert(s.result == 5);
	assert(s.error == 0);
}

void test_evaluate_2_3_minus_is_negative_1() {
	Status s = evaluate("2 3 -");
	assert(s.result == -1);
	assert(s.error == 0);
}

void test_evaluate_2_3_multiply_is_6() {
	Status s = evaluate("2 3 *");
	assert(s.result == 6);
	assert(s.error == 0);
}


void test_evaluate_2_3_divide_is_0() {
	Status s = evaluate("2 3 /");
	assert(s.result == 0);
	assert(s.error == 0);
}

void test_evaluate_6_3_divide_is_2() {
	Status s = evaluate("6 3 /");
	assert(s.result == 2);
	assert(s.error == 0);
}

void test_evaluate_2_3_4_plus_minus_is_negative_5() {
	Status s = evaluate("2 3 4 + -");
	assert(s.result == -5);
	assert(s.error == 0);
}

void test_evaluate6() {
	Status s = evaluate("1 2 3 4 5 * * * *");
	assert(s.result == 120);
	assert(s.error == 0);
}

void test_evaluate7() {
	Status s = evaluate("2 2 2 * 2 - 3 + +");
	assert(s.result == 7);
	assert(s.error == 0);
}

void test_evaluate8() {
	Status s = evaluate("2 2 2 2 2 * * 2 + + 2 - *");
	assert(s.result == 20);
	assert(s.error == 0);
}

void test_evaluate9() {
	Status s = evaluate("2 2 - 2 2 2 * 2 - - -");
	assert(s.result == 0);
	assert(s.error == 0);
}

void test_evaluate10() {
	Status s = evaluate(" 3   2    - ");
	assert(s.result == 1);
	assert(s.error == 0);
}