#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

double calculateONP(const string& expression) {
    stack<double> stack;
    istringstream input(expression);
    string token;

    while (input >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double op2 = stack.top(); 
            stack.pop();
            double op1 = stack.top(); 
            stack.pop();

            if (token == "+") stack.push(op1 + op2);
            else if (token == "-") stack.push(op1 - op2);
            else if (token == "*") stack.push(op1 * op2);
            else if (op2 == 0){
                return false;
            }
            else stack.push(op1 / op2);    
                 
        } 
        else {
            stack.push(stod(token));
        }
    }

    return stack.top();
}

int main() {
    string expression;
    getline(cin, expression);
    double result = calculateONP(expression);
    cout << result;
    return 0;
}