/*                                  Celeste Barrios
                                     * Project 3
                                     * MCS 360                              */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

// Most important function to convert our infix expression to postfix expression

int precedence(char token)
{
    if(token == '^')
        return 3;
    else if(token == '*' || token == '/')
        return 2;
    else if(token == '+' || token == '-')
        return 1;
    else
        return -1;
}

void InfixToPostfix(string str)
{
    stack<char> stack;
    stack.push('X');
    int l = str.length();
    string newstack;
    for(int i = 0; i < l; i++)
    {
        //add operand to string.
        if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z'))

            newstack+=str[i];

        //‘(‘ push it to the stack
        else if(str[i] == '(')

            stack.push('(');

        // ‘)’  pop
        //output string from the stack
        // run until ‘(‘ found
        else if(str[i] == ')')
        {
            while(stack.top() != 'X' && stack.top() != '(')
            {
                char token = stack.top();
                stack.pop();
                newstack += token;
            }
            if(stack.top() == '(')
            {
                char token = stack.top();
                stack.pop();

            }
        }

        //operator only
        else{
            while(stack.top() != 'X' && precedence(str[i]) <= precedence(stack.top()))
            {
                char token = stack.top();
                stack.pop();
                newstack += token;
            }
            stack.push(str[i]);
        }

    }
    //Pop out remaining

    while(stack.top() != 'X')
    {
        char token = stack.top();
        stack.pop();
        newstack += token;
    }

    cout << newstack<<" " << endl;

}
//implement newstack
int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i ";
    InfixToPostfix(expression);


    char str[] = "a+b*(c^d-e)^(f+g*h)-i";
    char *token;
    char *rest = str;

    while ((token = strtok_r( rest , "-+/*^()", &rest)))
       cout<<("%s\n", token)<<" "<<endl;


    return 0;
}
