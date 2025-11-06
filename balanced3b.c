#include <stdio.h>
#include <string.h>

#define MAX 100   

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}


char pop() {
    if (top == -1) {
        return '\0'; 
    } else {
        return stack[top--];
    }
}


int isBalanced(char exp[]) {
    char temp;
    for (int i = 0; i < strlen(exp); i++) {
        char ch = exp[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            temp = pop();
            if ((ch == ')' && temp != '(') ||
                (ch == '}' && temp != '{') ||
                (ch == ']' && temp != '[')) {
                return 0; 
            }
        }
    }

    
    return (top == -1);
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("✅ Expression is balanced.\n");
    else
        printf("❌ Expression is NOT balanced.\n");

    return 0;
}
