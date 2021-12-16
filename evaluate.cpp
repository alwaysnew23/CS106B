/**
 * Author: Vincent X
 * Date:   2021-12-16
 * 
 * Stanford CS106X lecture 9
 * 
 * Evaluates mathematical expressions that use addition and multiplication
 * Assumes:
 * - expression is "fully parenthesized"
 * - expression format is valid
 * - all numbers in expression are single-digit non-negative
 * 
 * Examples:
 * "7"                    => 7
 * "(2+2)"                => 4
 * "(1+(2*4))"            => 9
 * "((1+3)+((1+2)*5))"    => 19
 */

#include <iostream>
#include <string>

using namespace std;

int evalHelper(const string& exp, int& index);
int evaluate(const string& exp);

int main() {

    string a = "((1+3)+((1+2)*5))";

    cout << evaluate(a) << endl;;
    
    
    return 0;
}

int evalHelper(const string& exp, int& index) {
    if (isdigit(exp[index])) {
        return exp[index++] - '0';
    } else {       // non digit, must be '('
        index++;   // skip (
        int left = evalHelper(exp, index); // it can be a digit or a '('
        char op = exp[index++];
        int right = evalHelper(exp, index);
        index++;   // skip ), prepare for the next operaion if there is any

        if (op == '+') return left + right;
        else return left * right;   // op == '*'
    }
}

int evaluate(const string& exp) {
    int index = 0;
    return evalHelper(exp, index);
}