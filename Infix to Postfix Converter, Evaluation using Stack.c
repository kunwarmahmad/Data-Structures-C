/*Data Structures and Algorithm
ASSIGNMENT # 1
Created By
FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)*/

#include<stdio.h>

char stack[100];
int top = -1;

//-------------------------------------------PUSH Function--------------------------------------------
void push(char x)
{
    stack[++top] = x;
}

//-------------------------------------------POP Function--------------------------------------------
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

//------------------------------------Precedence Priority Function------------------------------------
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

//-------------------------------------------Infix to Postfix Function--------------------------------------------
void infix_to_postfix(char *e, char *pfx)
{
    int k = 0,x = 0;;
    printf("Converted Postfix Expression : ");

    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c ",*e);
            pfx[k++] = *e;
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                printf("%c ", x);
                pfx[k++] = x;
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                char c = pop();
                printf("%c ",c);
                pfx[k++] = c;
            }
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        char c = pop();
        printf("%c ",c);
        pfx[k++] = c;
    }
    pfx[k] = '\0';

}

//-------------------------------------------Postfix Evaluation Function--------------------------------------------
void eval_postfix(char *pfx)
{
    char *e;
    int n1,n2,n3,num,k=0;
    for(int i = 0; i < strlen(pfx); i++)
    {
        char c = pfx[i];
        if(isdigit(c))
        {
            num = c - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(c)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe Evaluation of PSN Expression %s  =  %d\n\n",pfx,pop());

}

//-------------------------------------------Main Function--------------------------------------------
int main()
{
    start();
    char exp[100], pfx[100];
    char *e, x;
    int n1,n2,n3,num,k=0;

    printf("Enter infix Expression : ");
    scanf("%s",exp);
    e = exp;

    infix_to_postfix(e,pfx);

    eval_postfix(pfx);

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to exit....................");
    getch();
    ex_it();

    return 0;
}


//----------------------------------------------Starting Page-------------------------------------------------------
void start()
{
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t###################################################################################################################\n");
    printf("\t\t\t\t#  _____________________________________________________________________________________________________________  #\n");
    printf("\t\t\t\t# | ___________________________________________________________________________________________________________ | #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                    Data Structures and Algorithm                         ::                || #\n");
    printf("\t\t\t\t# ||             ::                             ASSIGNMENT # 1                               ::                || #\n");
    printf("\t\t\t\t# ||             ::                    Hafiz Kunwar Muhammad Ahmad                           ::                || #\n");
    printf("\t\t\t\t# ||             ::                             FA20-BSE-064                                 ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||___________________________________________________________________________________________________________|| #\n");
    printf("\t\t\t\t# |_____________________________________________________________________________________________________________| #\n");
    printf("\t\t\t\t#                                                                                                                 #\n");
    printf("\t\t\t\t###################################################################################################################\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}


//--------------------------------------------- Exit Function----------------------------------------------------------
void ex_it()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t  _____________________________________________________________________________________________________________  \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                              THANK YOU                                                      | \n");
    printf("\t\t\t\t |                                 MADE BY: FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)                          | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to exit....................");
    getch();
}

