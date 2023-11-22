#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
//Part One: Create Stack class
struct node{
    char data;
    node* next;
};
class Stack{
    private:
    node* top;
    public:
    Stack() { top = nullptr; }
    bool isEmpty() {
        return top == nullptr;
    }
    //removes element at top of stack AND returns it 
    char pop() {
        node* temp = new node;
        temp = top;
        top = top -> next;
        return temp->data;
        delete temp;
    }
    //returns element at the top of stack without removing
    char Top() {
        return top->data;
    }
    char getNextTop() {
        return top->next->data;
    }
    //Adds one element on the current top of stack
    void add(char value) {
        node* newNode = new node;
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
    }
    //Return size of stack
    int getSize() {
        int size = 0;
        node* current = top;
        while(current != nullptr) {
            size++;
            current = current -> next;
        }
        return size;
    }
    void print() {
        node* current = top;
        while( current != nullptr) {
            cout << current -> data << endl;
            current = current -> next;
        }
    }
};

struct nodeDouble {
    double data;
    nodeDouble* next;
};

class StackDouble {
    private:
    nodeDouble* top;

    public:
    StackDouble() { top = nullptr;}

    bool isEmpty() {
        return top == nullptr;
    }

    double pop() {
        double value;
        if(!isEmpty()) {
            nodeDouble* temp = top;
            value = temp->data;
            top = top -> next;
            delete temp;
        }
        
        return value;
    }

    double Top() {
        double ret;
        if(!isEmpty()) {
            ret = top->data;
        }
        return ret;
    }
    
    void add(double value) {
        nodeDouble* newNode = new nodeDouble;
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
    }

    int getSize() {
        int size = 0;
        nodeDouble* current = top;
        while(current != nullptr) {
            size++;
            current = current -> next;
        }
        return size;
    }


};

    bool isOperand(char x) {
        return  x == '0' || x == '1' ||x== '2'|| x == '3'|| x == '4'|| x == '5'|| x == '6'|| x == '7'|| x == '8'|| x == '9';
    }
    bool isOperator(char x) {
        return x == '^' || x == '*' || x == '/' || x == '+' || x == '-';
    }
    // +, -, *, /, and ^ with parentheses
    int precedence(char x) {
        if( x == '^') {
            return 3;
        }
        if( x == '*' || x == '/' ) {
            return 2;
        }
        if( x == '+' || x == '-') {
            return 1;
        }
        if( x == '(' || x == ')') {
            return 0;
        }
        
        return -1;
    }
 //Part Two: Write function that converts an expression in infix to postfix format
string infix2postfix(string infix) {
    Stack stack;
    string postfix = "";

    for( int i = 0; i < infix.size(); i++) {
        //If scanned character is an operand, output it 
        if(isOperand(infix[i])) {
            postfix += (infix[i]);   
        }
        else {
            if(infix[i] == '(') {
                stack.add(infix[i]);
            }
                    
            if(infix[i] == ')') {
                while(!stack.isEmpty() && stack.Top() != '(') {
                    postfix+= stack.Top();
                    stack.pop();
                }
                if(!stack.isEmpty() && stack.Top() == '(') {
                    stack.pop();
                }
            }

            if(isOperator(infix[i])) {
                if (stack.isEmpty()) {
                    stack.add(infix[i]);
                }
                else {
                    while(!stack.isEmpty() && (precedence(infix[i]) <= precedence(stack.Top()))) {
                        postfix+=stack.Top();
                        stack.pop();
                    }
                    stack.add(infix[i]);
                }
            }
        }

    }
    while(!stack.isEmpty()) {
        postfix += stack.Top();
        stack.pop();
    }

    return postfix;
}

double operation(double a, double b, char op) {
        double result = 0.0;

        switch(op) {
            case '+':
            result = a+b;
            break;
            case '-':
            result = a-b;
            break;
            case '*':
            result = a*b;
            break;
            case '/':
            result = b/a;
            break;
            case '^':
            result = pow(a,b);
            break;
        }

        return result;
    }

    


    double evalPostfix (string postfix) {
        StackDouble stack;
        double answer = 0.0;
        
        for( int i = 0; i < postfix.size(); i++) {
            //If element is a number, push to stack
            
            if(isOperand(postfix[i])) {
                double num = static_cast<double>(postfix[i] - '0');
                stack.add(num);
            }

            //if element is an operator, pop operands for the operator from the stack 
            if(isOperator(postfix[i])) {
                if(!stack.isEmpty()) {
                    double op1 = stack.Top();
                    stack.pop();

                    double op2 = stack.Top();
                    stack.pop();

                    double result = operation(op2, op1, postfix[i]);
                    stack.add(result);
                }
                
            }
        }

        if(stack.getSize() == 1) {
            answer = stack.Top();
        }
        else {
            cout << "nv";
        }

        return answer;
    }



int main(int argc, char** argv) {

    //program takes 3 arguments
    if( argc != 4) {
        return 1;
    }
    int part = stoi(argv[1]);
    string expression = argv[2];
    string output = argv[3];

    // int dot = output.find('.');
    // string outputName;
    // outputName = output.substr(0,dot) + ".txt";

    ofstream outputFile(output);

    string postfix;
    if(part == 2) {
        postfix = infix2postfix(expression);
        outputFile << postfix << endl;
        cout << postfix << endl;
    }

    double product;
    if( part == 3 ) {
        product = evalPostfix(expression);
        if(product == 0.0) {
            outputFile << "nv" << endl;
            cout << "nv" << endl;
        }
        else {
            outputFile << fixed << setprecision(1) << product << endl;
            cout << fixed << setprecision(1) << product << endl;
        }
    }

    outputFile.close();

}