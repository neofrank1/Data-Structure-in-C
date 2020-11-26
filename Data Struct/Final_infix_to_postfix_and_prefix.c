//test infix to postfix and prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct stack {
    char data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack*,char);
struct stack *pop(struct stack*);
char peek(struct stack*);
int prio(char);
int isoperator(char);
struct stack *display(struct stack* );
void postfix(char[]);
void prefix(char[]);
struct stack *checker(struct stack*,char[]);
int main()
{
    int i,k=0;
    char infix[50],inf1x[50];

    printf("Enter Expression: ");
    gets(infix);
    fflush(stdin);
    top = checker (top,infix);
   if(top == 0)
   {
       printf("Expression is valid\n**********************\n");
      for(i=0;infix[i]!='\0';i++)
      {
          if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='0'&&infix[i]<='9')||infix[i]=='('||infix[i]==')'||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%')
          {
              inf1x[k]=infix[i];
              k++;
          }
      }
      inf1x[k]='\0';
      printf("Infix Expression: ");
     puts(inf1x);
    postfix(inf1x);
    prefix(inf1x);
   }
   else if(top != 0 )
   {
       printf("Expression is invalid\n**********************\n");
   }
    printf("\n\n\nPRESS ANY KEY TO EXIT\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\nGOOD BYE :)\n");
    getch();
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
int prio(char elem){
   if(elem=='*'||elem=='/'||elem=='%')
   {
       return 1;
   }
   else if(elem=='+'||elem=='-')
   {
       return 0;
   }
}
int isoperator(char op)
{
    if(op=='+'||op=='-'||op=='*'||op=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct stack *display(struct stack *top)
{
    struct stack *ptr = top;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
        return top;
    }
    else{
    printf("Stack: ");
    while(ptr->next!=NULL)
    {
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    printf("%c\n",ptr->data);
    return top;
    }
}
void postfix(char infx[50])
{
    int i=0,k=0, flag=0,flag1=0,flag2;
    char pofx[50];

    for(i=0;infx[i]!='\0';i++)
    {
        if(infx[i]=='*'||infx[i]=='/'||infx[i]=='+'||infx[i]=='-'||infx[i]=='(')
        {
            if(flag == 0 )
            {
                top=push(top,infx[i]);
                    flag++;
            }
            else if(flag>0)
            {
                if(isoperator(infx[i])==1)
                {
                    if(isoperator(peek(top))==1)
                    {
                        if(prio(peek(top))>=prio(infx[i]))
                        {
                            if(flag1>0)
                            {
                                pofx[k++]=peek(top);
                                top = pop(top);
                                if(prio(peek(top))>=prio(infx[i]))
                                {
                                    pofx[k++]=peek(top);
                                    top = pop(top);
                                    flag1--;
                                }
                                top = push(top,infx[i]);
                            }
                            else
                            {
                            pofx[k++]=peek(top);
                            top = pop(top);
                            top = push(top,infx[i]);
                            }
                        }
                        else
                        {
                            top = push(top,infx[i]);
                            flag1++;
                        }
                    }
                    else
                    {
                        top = push(top,infx[i]);
                        flag++;
                        flag2 = flag1;
                    }
                }
                else
                {
                    top = push (top,infx[i]);
                }
            }
        }
        else if(infx[i]==')')
        {
                while(top->data!='(')
                {
                    pofx[k++]=peek(top);
                        top=pop(top);
                }
                 top=pop(top);
                if(flag1>flag2)
                {
                    flag1=flag2;
                }
                if(top!=NULL)
                {
                     flag--;
                }
                else
                {
                    flag=0;
                }
        }
        else if((infx[i]>='a'&&infx[i]<='z')||(infx[i]>='A'&&infx[i]<='Z')||(infx[i]>='0'&&infx[i]<='9'))
        {
            pofx[k++]=infx[i];
        }
    }
    if(top!=NULL)
    {
        while(top!=NULL)
        {
            pofx[k++]=peek(top);
            top=pop(top);
        }
    }
  pofx[k]='\0';
        printf("\npostfix expression is ");
        puts(pofx);
}
void prefix(char infx[50])
{
    int i=0,j=0,k=0, flag=0,flag1=0;
    char prfx[50],rev[50];
     for(i=strlen(infx)-1;i>=0;i--)
    {
           rev[j]=infx[i];
            j++;
    }
    rev[j]='\0';
  for(i=0;rev[i]!='\0';i++)
    {
        if(rev[i]=='*'||rev[i]=='/'||rev[i]=='+'||rev[i]=='-'||rev[i]==')')
        {
            if(flag == 0 )
            {
                top=push(top,rev[i]);
                    flag++;
            }
            else if(flag>0)
            {
                if(isoperator(rev[i])==1)
                {
                    if(isoperator(peek(top))==1)
                    {
                        if(prio(peek(top))>prio(rev[i]))
                        {
                            if(flag1>0)
                            {
                                while(flag1>0)
                                {
                                if(prio(peek(top))>prio(rev[i]))
                                {
                                    prfx[k++]=peek(top);
                                    top = pop(top);
                                     flag1--;
                                }
                                }
                                top = push(top,rev[i]);
                            }
                            else
                            {
                            prfx[k++]=peek(top);
                            top = pop(top);
                            top = push(top,rev[i]);
                            }
                        }
                        else if(prio(peek(top))==prio(rev[i]))
                        {
                            top = push(top,rev[i]);
                            flag1++;
                        }
                        else
                        {
                            top = push(top,rev[i]);
                            flag1++;
                        }
                    }
                    else
                    {
                        top = push(top,rev[i]);
                        flag++;
                    }
                }
                else
                {
                    top = push (top,rev[i]);
                }
            }
        }
        else if(rev[i]=='(')
        {
                while(top->data!=')')
                {
                    prfx[k++]=peek(top);
                        top=pop(top);
                }
                 top=pop(top);
                 if(flag1>0)
                 {
                     flag1--;
                 }
               if(top!=NULL)
                {
                     flag--;
                }
                else
                {
                    flag=0;
                }
        }
        else if((rev[i]>='a'&&rev[i]<='z')||(rev[i]>='A'&&rev[i]<='Z')||(rev[i]>='0'&&rev[i]<='9'))
        {
            prfx[k++]=rev[i];
        }
    }
    if(top!=NULL)
    {
        while(top!=NULL)
        {
            prfx[k++]=peek(top);
            top=pop(top);
        }
    }
  prfx[k]='\0';
  j=0;
  for(i=strlen(prfx)-1;i>=0;i--)
    {
            rev[j]=prfx[i];
            j++;
    }
    rev[j]='\0';
        printf("\nprefix expression is ");
        puts(rev);
}
struct stack *checker(struct stack *top,char expression[50]){
    int i;

    for(i=0; i<strlen(expression);i++)
    {
      if(expression[i]=='('||expression[i]=='['||expression[i]=='{')
            top = push(top,expression[i]);
         else if(expression[i]==')'||expression[i]==']'||expression[i]=='}')
        {
            if(expression[i]==')'&&peek(top)=='(')
                top=pop(top);
                if(top==NULL)
                {
                    break;
                }
            else if (expression[i]==']'&&peek(top)=='[')
                top=pop(top);
                if(top==NULL)
                {
                    break;
                }
            else if (expression[i]=='}'&&peek(top)=='{')
                top=pop(top);
                if(top==NULL)
                {
                    break;
                }
        }
    }
    return top;
}


