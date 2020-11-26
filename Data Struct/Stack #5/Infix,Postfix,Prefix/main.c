/*
Filename: UyActivity
Description: Infix Postfix & Prefix Conversion
Programmer: Neo Frank D. Uy
Date: 11-10-2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256

struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;
struct node *push(struct node *,char);
struct node *pop(struct node *);
char peek(struct node *);
int is_operator(char);
int precedence(char);
void Infix_Postfix(char[]);
void Infix_Prefix(char[]);
char removeSpace(char[]);

int main()
{
    int i;
    char par[SIZE];
    char inf[SIZE];

    printf("Enter Infix Expression: ");
    gets(par);
    strcpy(inf,par);
    removeSpace(inf);

    for(i=0;i<strlen(par);i++)
    {
        if (par[i] == '(' || par[i] == '[' || par[i] == '{' )
        {
                 top = push(top,par[i]); // Push { [ ( //
        }
        else if (par[i] == ')' || par[i] == ']' || par[i] == '}')
        {
            if (par[i] == ')' && peek(top) == '(') // Pair Checker of ( ) //
            {
                top = pop(top); // remove //
            }
            else if (par[i] == ']' && peek(top) == '[') // Pair Checker of [ ] //
            {
                top = pop(top); // remove //
            }
            else if (par[i] == '}' && peek(top) == '{') // Pair Checker of { } //
            {
                top = pop(top); // remove //
            }
        }
    }
    if (top == NULL)
    {
        printf("\nValid Statement\n"); // True //
        puts(inf);
        Infix_Postfix(inf);
        Infix_Prefix(inf);
    }
    else
    {
        printf("\nInvalid Statement"); // False //
        system("cls");
        main();
    }

    return 0;
}

char removeSpace(char inf[SIZE]) // Remove Blank Space //
{
    int count = 0;
    int i;

    for (i=0;i<inf[i];i++)
    {
        if (inf[i] != ' ') // Finding if there is a Blank Space //
        {
            inf[count++] = inf[i];
        }
    }
    inf[count] = '\0'; // Make last Index to NULL //
    return inf;
}

struct node *push(struct node *top,char infx) // Insert Operation //
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = infx;

    if (top == NULL)
    {
        new_node -> next = NULL;
    }
    else
    {
        new_node -> next = top;
    }
    top = new_node;
    return top;
};

struct node *pop(struct node *top) // Remove Operation //
{
    struct node *ptr;

    if (top == NULL) // Empty Stack //
    {
        printf("Hubas WALAY Sulod Oi!");
    }
    else
    {
        ptr = top;
        top = top -> next;
        free(ptr);
    }
    return top;
};

char peek(struct node *top) // Return Value //
{
    if (top == NULL) // Empty Stack //
    {
        return 0;
    }
    else
    {
        return top -> data; // Return Value //
    }
};

int is_operator(char oper) // Is to Check there is a Operator //
{
    if (oper == '/' || oper =='*' || oper == '+' || oper == '-') // True //
    {
        return 1;
    }
    else // False //
    {
        return 0;
    }
}

int precedence(char exp) // Is to Check The Priority of the Operator //
{
    if (exp == '/' || exp == '*' || exp == '^') // High Priority //
    {
        return 1;
    }
    else // Low Priority //
    {
        return 0;
    }
}

void Infix_Postfix(char inf[SIZE]) // Postfix Conversion //
{
    int i;
    int k = 0;
    int flag = 0;
    char post[SIZE];

    for (i=0;inf[i]!='\0';i++)
    {
        if (inf[i] =='*'|| inf[i] =='/'|| inf[i] =='+'|| inf[i] =='-'|| inf[i] =='(') // If Encounters this Operators //
        {
            if(flag == 0) // If Flag in 0 Equals to First Element of the Expression //
            {
                top = push(top,inf[i]); // Push to top the first element of the Expression //
                flag++; // Increment Flag to Next Element of Expression //
            }
            else if(flag>0)
            {
                if(is_operator(inf[i]) == 1) // Find If There Is a and Operator //
                {
                    if(is_operator(peek(top)) == 1) // If There is a Valid Operator //
                    {
                        if(precedence(peek(top)) >= precedence(inf[i])) // Check The Priority of the Operator //
                        {
                            post[k++] = peek(top); // Store to Post Variable //
                            top = pop(top); // Remove the Operator //
                            top = push(top,inf[i]); // Insert to The Stack //
                            flag--; // Decrement Flag //
                        }
                            else
                            {
                            top = push(top,inf[i]); // Insert to Stack //
                            }
                    }
                    else
                    {
                        top = push(top,inf[i]); // Insert to Stack //
                        flag++; // Increment Flag //
                    }
                }
            }
        }
        else if (inf[i] == ')') // If Encounters Close Parenthesis //
        {
            while(top->data != '(') // If Encounters Open Parenthesis //
            {
                post[k++] = peek(top);
                top = pop(top); // Remove //
            }
                top = pop(top); // Remove //
                flag--; // Decrement Flag //
        }
        else if ((inf[i] >= 'a' || inf[i] <= 'z') || (inf[i] >= 'A' || inf[i] <= 'Z') || (inf[i] >= '0' || inf[i] <= '9')) // Check if there is a Characters and Numbers //
        {
            post[k++] = inf[i]; // Assign to Post Variable //
        }
    }
    if (top != NULL)
    {
        while (top != NULL)
        {
            post[k++] = peek(top); // Return the Value from the Stack //
            top = pop(top); // Remove from Stack //
        }
    }
    post[k] = '\0'; // Make into NULL the last element of the Expression //
    printf("\nPostfix Expression: "); // Display //
    puts(post);
}

void Infix_Prefix(char inf[SIZE]) // Infix to Prefix Conversion //
{
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;

    char pre[SIZE];
    char rever[SIZE];

    for (i=strlen(inf)-1; i>=0; i--) // Reverse the Infix Expression //
    {
        rever[j] = inf[i];
        j++;
    }
    rever[j] = '\0'; // Make into NULL the last element of the Expression //

    for(i=0; rever[i] != '\0' ;i++)
    {
         if(rever[i] =='*' || rever[i] == '/' || rever[i] == '+' || rever[i] == '-' || rever[i] == ')') // If Encounters this Operators //
         {
             if (flag == 0) // If Flag in 0 Equals to First Element of the Expression //
             {
                 top = push(top,rever[i]); // Push to top the first element of the Expression //
                 flag++; // Increment Flag to Next Element of Expression //
             }
             else if (flag > 0)
             {
                 if (is_operator(rever[i]) == 1) // Find If There Is a and Operator //
                 {
                     if(precedence(peek(top)) == 1) // If There is a Valid Operator //
                     {
                         if(precedence(peek(top)) >= precedence(rever[i])) // Check The Priority of the Operator //
                         {
                            pre[k++] = peek(top); // Store to Post Variable //
                            top = pop(top); // Remove the Operator //
                            top = push(top,rever[i]); // Insert to The Stack //
                            flag--; // Decrement Flag //
                         }
                         else
                         {
                             top = push(top,rever[i]); // Insert to Stack //
                         }
                     }
                else
                {
                    top = push(top,rever[i]); // Insert to Stack //
                    flag++; // Increment Flag //
                }
            }
            else
            {
                top = push(top,rever[i]); // Insert to Stack //
            }
        }
    }
    else if (rever[i]=='(') // If Encounters Open Parenthesis //
        {

            while(top -> data != ')') // If Encounters Close Parenthesis //
            {
                pre[k++] = peek(top);
                top = pop(top); // Remove //
            }
                top = pop(top); // Remove //
                flag--; // Decrement Flag //
            }
        else if ((rever[i] >= 'a' || rever[i] <= 'z') || (rever[i] >= 'A' || rever[i] <= 'Z') || (rever[i] >= '0' || rever[i] <= '9')) // If Encounters this Operators //
        {
            pre[k++] = rever[i]; // Assign to Post Variable //
        }
    }
    if (top != NULL)
    {
        while(top != NULL)
        {
            pre[k++] = peek(top); // Return the Value from the Stack //
            top = pop(top); // Remove from Stack //
        }
    }

    pre[k] = '\0';
    j = 0;

    for(i=strlen(pre)-1;i>=0;i--) // Reverse to Prefix Expression //
    {
        rever[j] = pre[i]; // Store to Rever Variable  //
        j++;
    }
    rever[j] = '\0'; // Make into NULL the last element of the Expression //
    printf("\nPrefix Expression: "); // Display //
    puts(rever);
}
