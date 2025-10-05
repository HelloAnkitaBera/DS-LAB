#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
// Stack for characters (operators)
char stack[SIZE];
int top = -1;
void push(char x) {
stack[++top] = x;

}
char pop() {
if (top == -1)
return -1;
else
return stack[top--];
}
int precedence(char x) {
if (x == '(') return 0;
if (x == '+' || x == '-') return 1;
if (x == '*' || x == '/') return 2;
if (x == '^') return 3;
return -1;
}
// ------------ INFIX TO POSTFIX ------------
void infixToPostfix(char* infix, char* postfix) {
char ch, x;
int i = 0, k = 0;
while ((ch = infix[i++]) != '\0') {
if (isalnum(ch)) {
postfix[k++] = ch;
} else if (ch == '(') {
push(ch);
} else if (ch == ')') {
while ((x = pop()) != '(') {
postfix[k++] = x;
}
} else {
while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
postfix[k++] = pop();
}
push(ch);
}
}
while (top != -1) {
postfix[k++] = pop();
}
postfix[k] = '\0';
}
// ------------ INFIX TO PREFIX ------------
void reverse(char* str) {
int n = strlen(str);
for (int i = 0; i < n/2; i++) {
char temp = str[i];
str[i] = str[n - i - 1];
str[n - i - 1] = temp;
}

}
void infixToPrefix(char* infix, char* prefix) {
char revInfix[SIZE], revPostfix[SIZE];
strcpy(revInfix, infix);
reverse(revInfix);
// Swap &#39;(&#39; and &#39;)&#39;
for (int i = 0; revInfix[i]; i++) {
if (revInfix[i] == '(') revInfix[i] = ')';
else if (revInfix[i] == ')') revInfix[i] = '(';
}
infixToPostfix(revInfix, revPostfix);
reverse(revPostfix);
strcpy(prefix, revPostfix);
}
// ------------ EVALUATE POSTFIX ------------
int stackEval[SIZE];
int topEval = -1;
void pushEval(int x) {
stackEval[++topEval] = x;
}
int popEval() {
return stackEval[topEval--];
}
int evalPostfix(char* postfix) {
int i = 0;
char ch;
while ((ch = postfix[i++]) != '\0') {
if (isdigit(ch)) {
pushEval(ch - '0');
} else {
int b = popEval();
int a = popEval();
switch (ch) {
case '+': pushEval(a + b); break;
case '-': pushEval(a - b); break;
case '*': pushEval(a * b); break;
case '/': pushEval(a / b); break;
case '^': {
int res = 1;
for (int j = 0; j < b; j++) res *= a;
pushEval(res);
break;
}
}

}
}
return popEval();
}
// ------------ EVALUATE PREFIX ------------
int evalPrefix(char* prefix) {
int len = strlen(prefix);
for (int i = len - 1; i >= 0; i--) {
char ch = prefix[i];
if (isdigit(ch)) {
pushEval(ch - '0');
} else {
int a = popEval();
int b = popEval();
switch (ch) {
case '+': pushEval(a + b); break;
case '-': pushEval(a - b); break;
case '*': pushEval(a * b); break;
case '/': pushEval(a / b); break;
case '^': {
int res = 1;
for (int j = 0; j < b; j++) res *= a;
pushEval(res);
break;
}
}
}
}
return popEval();
}
// ------------ MAIN MENU ------------
int main() {
char infix[SIZE], postfix[SIZE], prefix[SIZE];
int choice;
while (1) {
printf("\n--- Menu ---\n");
printf("1. Infix to Postfix\n");
printf("2. Infix to Prefix\n");
printf("3. Evaluate Postfix\n");
printf("4. Evaluate Prefix\n");
printf("5. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter Infix Expression: ");
scanf("%s", infix);

top = -1;
infixToPostfix(infix, postfix);
printf("Postfix: %s\n", postfix);
break;
case 2:
printf("Enter Infix Expression: ");
scanf("%s", infix);
top = -1;
infixToPrefix(infix, prefix);
printf("Prefix: %s\n", prefix);
break;
case 3:
printf("Enter Postfix Expression: ");
scanf("%s", postfix);
topEval = -1;
printf("Result: %d\n", evalPostfix(postfix));
break;
case 4:
printf("Enter Prefix Expression: ");
scanf("%s", prefix);
topEval = -1;
printf("Result: %d\n", evalPrefix(prefix));
break;
case 5:
exit(0);
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}