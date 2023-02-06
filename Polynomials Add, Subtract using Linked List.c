/*Data Structures and Algorithm
ASSIGNMENT # 2
Created By
FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coff;
    int exp;
    struct node *next;
};
struct node *head = 0, *newnode, *temp;
struct node *head2 = 0, *newnode2, *temp2;
struct node *head3 = 0, *newnode3, *temp3;

void link1()
{
    int opt = 1;
    //Creation of Linked List
    printf("\n\nEnter Polynomial 1 : ");
    while(opt)
    {
        newnode = (struct node*) malloc(sizeof(struct node));

        printf("Enter Cofficient : ");
        scanf("%d", &newnode->coff);
        printf("Enter Exponent : ");
        scanf("%d", &newnode->exp);
        newnode->next = 0;

        if(head == 0)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to continue adding terms ? (0 NO,1 YES)");
        scanf("%d", &opt);
    }
}

void link2()
{
    int opt2 = 1;
    printf("\n\nEnter Polynomial 2 : ");
    while(opt2)
    {
        newnode2 = (struct node*) malloc(sizeof(struct node));

        printf("Enter Cofficient : ");
        scanf("%d", &newnode2->coff);
        printf("Enter Exponent : ");
        scanf("%d", &newnode2->exp);
        newnode2->next = 0;

        if(head2 == 0)
        {
            head2 = newnode2;
            temp2 = head2;
        }
        else
        {
            temp2->next = newnode2;
            temp2 = newnode2;
        }
        printf("\nDo you want to continue adding terms ? (0 NO,1 YES)");
        scanf("%d", &opt2);
    }
}

void resultAdd()
{
    temp = head;
    temp2 = head2;
    //temp3 = head3;

    while(temp && temp2)
    {
        if(temp->exp > temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp->exp;
            newnode3->coff = temp->coff;
            newnode3->next = 0;
            temp = temp->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
        else if(temp->exp == temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp->exp;
            newnode3->coff = temp->coff + temp2->coff;
            newnode3->next = 0;
            temp = temp->next;
            temp2 = temp2->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
        else if(temp->exp < temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp2->exp;
            newnode3->coff = temp2->coff;
            newnode3->next = 0;
            temp2 = temp2->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
    }
    while(temp!=0)
    {
        newnode3 = (struct node*) malloc(sizeof(struct node));
        newnode3->exp = temp->exp;
        newnode3->coff = temp->coff;
        newnode3->next = 0;
        temp = temp->next;
        if(head3 == 0)
        {
            head3 = newnode3;
            temp3 = head3;
        }
        else
        {
            temp3->next = newnode3;
            temp3 = newnode3;
        }
    }
    while(temp2!=0)
    {
        newnode3 = (struct node*) malloc(sizeof(struct node));
        newnode3->exp = temp2->exp;
        newnode3->coff = temp2->coff;
        newnode3->next = 0;
        temp2 = temp2->next;
        if(head3 == 0)
        {
            head3 = newnode3;
            temp3 = head3;
        }
        else
        {
            temp3->next = newnode3;
            temp3 = newnode3;
        }
    }
}

void displayAdd()
{
    temp3 = head3;
    while(temp3!=0)
    {
        if(temp3->coff!=0)
        {
            printf("(%d)", temp3->coff);
            if(temp3->exp!=0)
                printf("x^%d", temp3->exp);
            if(temp3->next!=0)
                printf(" + ");
        }
        temp3 = temp3->next;
    }
}


void resultSub()
{
    temp = head;
    temp2 = head2;
    //temp3 = head3;

    while(temp && temp2)
    {
        if(temp->exp > temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp->exp;
            newnode3->coff = temp->coff;
            newnode3->next = 0;
            temp = temp->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
        else if(temp->exp == temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp->exp;
            newnode3->coff = temp->coff - temp2->coff;
            newnode3->next = 0;
            temp = temp->next;
            temp2 = temp2->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
        else if(temp->exp < temp2->exp)
        {
            newnode3 = (struct node*) malloc(sizeof(struct node));
            newnode3->exp = temp2->exp;
            newnode3->coff = temp2->coff;
            newnode3->next = 0;
            temp2 = temp2->next;
            if(head3 == 0)
            {
                head3 = newnode3;
                temp3 = head3;
            }
            else
            {
                temp3->next = newnode3;
                temp3 = newnode3;
            }
        }
    }
    while(temp!=0)
    {
        newnode3 = (struct node*) malloc(sizeof(struct node));
        newnode3->exp = temp->exp;
        newnode3->coff = temp->coff;
        newnode3->next = 0;
        temp = temp->next;
        if(head3 == 0)
        {
            head3 = newnode3;
            temp3 = head3;
        }
        else
        {
            temp3->next = newnode3;
            temp3 = newnode3;
        }
    }
    while(temp2!=0)
    {
        newnode3 = (struct node*) malloc(sizeof(struct node));
        newnode3->exp = temp2->exp;
        newnode3->coff = temp2->coff;
        newnode3->next = 0;
        temp2 = temp2->next;
        if(head3 == 0)
        {
            head3 = newnode3;
            temp3 = head3;
        }
        else
        {
            temp3->next = newnode3;
            temp3 = newnode3;
        }
    }
}

void displaySub()
{
    temp3 = head3;
    while(temp3!=0)
    {
        if(temp3->coff!=0)
        {
            printf("(%d)", temp3->coff);
            if(temp3->exp!=0)
                printf("x^%d", temp3->exp);
            if(temp3->next!=0)
                printf(" + ");
        }
        temp3 = temp3->next;
    }
}


void display()
{
    temp = head;
    while(temp!=0)
    {
        printf("%dx%d ", temp->coff, temp->exp);
        temp=temp->next;
    }
}

void display2()
{
    temp2 = head2;
    while(temp2!=0)
    {
        printf("%dx%d ", temp2->coff, temp2->exp);
        temp2=temp2->next;
    }
}


int main()
{
    int choice;
    link1();
    link2();

    printf("\n\nEntered Polynomial 1: ");
    display();
    printf("\n\nEntered Polynomial 2: ");
    display2();


    menu();
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        printf("\n\nResult Polynomial : ");
        resultAdd();
        displayAdd();
        break;

    case 2:
        printf("\n\nResult Polynomial : ");
        resultSub();
        displaySub();
        break;

    }


    return 0;
}



void menu()
{

    printf("\n\n\n               ");
    printf("\t\t\t                                    _______Polynomial Linked List_______\n\n               ");
    printf("\t\t\t                                    1 - Add two Polynomials\n               ");
    printf("\t\t\t                                    2 - Subtract two Polynomials\n\n               ");
    printf("\t\t\t                                    ___________**********___________\n\n\n               \t\t\t\t\t\t\tPress : ");
}




