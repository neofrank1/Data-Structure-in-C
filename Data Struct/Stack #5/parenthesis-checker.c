#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack*,char);
struct stack *pop(struct stack*);
char peek(struct stack*);
struct stack *checker(struct stack*);

int main(){
   top = checker (top);

   if(top == 0)
   {
       printf("Expression is valid\n**********************");
   }
   else if(top != 0 )
   {
       printf("Expression is invalid\n**********************");
   }

    return 0;

}
struct stack *push(struct stack *top,char exp){
    struct stack *new_stack;
    new_stack=(struct stack*)malloc(sizeof(struct stack));
    new_stack -> data = exp;
    if(top==NULL)
    {
        new_stack ->next = NULL;
    }
    else
    {
      new_stack -> next = top;
    }
    top = new_stack;
    return top;
}
struct stack *pop(struct stack *top){
    struct stack *ptr = top;

    top = ptr->next;
    free(ptr);
    return top;
}
char peek(struct stack *top){
    return top->data;

}
struct stack *checker(struct stack *top){
    int i;
    char expression [100];
    printf("enter expression: ");
    gets(expression);
    for(i=0; i<strlen(expression);i++)
    {
      if(expression[i]=='('||expression[i]=='['||expression[i]=='{')
            top = push(top,expression[i]);
         else if(expression[i]==')'||expression[i]==']'||expression[i]=='}')
        {
            if(expression[i]==')'&&peek(top)=='(')
                top=pop(top);
            else if (expression[i]==']'&&peek(top)=='[')
                top=pop(top);
            else if (expression[i]=='}'&&peek(top)=='{')
                top=pop(top);
        }
    }
    return top;

}


