#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 20

struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push (STACK *s, float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float compute(float oper1, char symbol,float oper2)
{
    switch(symbol)
    {
        case '+':return oper1 + oper2;
        case '-':return oper1 - oper2;
        case '*':return oper1 * oper2;
        case '/':return oper1 / oper2;
        case '^':return pow(oper1,oper2);
    }
    return 0;
}
float EVAL_postfix(STACK *s,char postfix[SIZE])
{
    char symbol;
    int i;
    float oper1, oper2, res;
    for (i=0; postfix[i]!= '\0'; i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            push(s, symbol - '0');
        }
        else
        {
            oper2 = pop(s);
            oper1 = pop(s);
            res = compute (oper1, symbol, oper2);
            push(s, res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[SIZE];
    float result;
    STACK s;
    s.top = -1;
    printf("read postfix expression:");
    scanf("%s",postfix);
    result = EVAL_postfix(&s, postfix);
    printf("the final answer is = %.2f\n",result);
    return 0;
}
