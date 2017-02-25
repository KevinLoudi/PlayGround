//
//  main.cpp
//  exercise
//
//  Created by KevinLiu on 17/2/3.
//  Copyright © 2017 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;

double solve(double num1,double num2, char op)
{
        //calculate
    switch(op)
    {
    case '+':
        return (num1+num2);
    case '-':
        return (num1-num2);

    case '*':
        return (num1*num2) ;
    case '/':
        return (num1/num2);
    default:
        cout << "Incorrect operation! " << endl;
        //cin >> num1 >> op >> num2;
        //solve(num1,num2,op);
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    double num1,num2,solution;
    char operation;

    //to decide whether continue or not
    char redo = 'N';

    cout << "Welcome to Calculator v2.0 by Shirley!" << endl;

    do
    {
    cout << "Please enter the equation you want to calculate:" << endl;
    cin >> num1 >> operation >> num2;

    solution = solve(num1,num2,operation);
    cout << "Answer is: " << solution << endl;

    //reset the value of redo
    cout << "enter 'Y' or 'y' to continue:" << endl;
    cin >> redo;

    }while(redo == 'Y'|| redo == 'y');

    return 0;
}
