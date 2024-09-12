Part 1: Write your OWN class stack. The class stack must have the following four public functions at least:
 - top(): returns the element t the top of the stack without removal.
 - pop(): remove the element at the current top of the stack and returns it
 - add(): add one element on the current top of the stack.
 - size(): returns the size of the stack

Part 2: Write a function that converts an expression in infix to postfix format using YOUR class stack. 
It should support all operations of +,-,*,/, and ^ with parenthesis and follow standard Math precedence ordering of PEMDAS.

The operands are single digit numbers. The input IS in correct format and you ARE NOT required to check the input correctness.
All operators are binary (have two operands) and you do not need to handle unary operators such as negation.

Examples:
- infix: (2)     postfix: 2
- infix: 2-3*4+5/6   postfix: 234*56/+
- infix; (2+3)^4*5   postfix: 23+4^5*

  Part3: Given an expression in postfix notation, use YOUR stack to:
  - check whether the input indeed follows a true postfix
  - evaluate the postfix expression
The operands are single digit numbers. The input may not be in correct format and you ARE required to check the input correctness.
All operators are binary (have 2 operands) and you do not need to handle unary operators such as negation.
If the input is valid it evaluates the expression otherwise it prints [nv] which means not valid.
The operands in input file are integer (e.g. 3). However your output should be in floating point format with 1 decimal place (e.g 3.0)

Examples:
- postfix: 23+-    evaluation: nv
- postfix: 23+     evaluation: 5.0
- postfix: 23+4^5* evaluation: 3125.0 
