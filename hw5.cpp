#include <iostream> 
#include <string>
#include <fstream>
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
    void infix2postfix(string infix, string& result) {
        Stack stack;

        for( int i = 0; i < infix.size(); i++) {
            //If scanned character is an operand, output it 
            if(isOperand(infix[i])) {
                result += (infix[i]);   
            }
            else {
            if(infix[i] == '(') {
                stack.add(infix[i]);
            }


            if(infix[i] == ')') {
                while(!stack.isEmpty() && stack.Top() != '(') {
                    result+= stack.Top();
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
                        result+=stack.Top();
                        stack.pop();
                    }
                    stack.add(infix[i]);
                }
            }
        }
        while(!stack.isEmpty()) {
            result += stack.Top();
            stack.pop();
        }

    }
}





int main(int argc, char** argv) {

    //program takes 3 arguments
    if( argc != 4) {
        return 1;
    }
    int part = stoi(argv[1]);
    string expression = argv[2];
    string output = argv[3];

    ofstream outputFile(output);

    string postfix = "";
    if(part == 2) {
        infix2postfix(expression,postfix);
        outputFile << postfix << endl;
    }

}