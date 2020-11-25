#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void create();
int stackEmpty();
int stackFull();
void push(struct stack *p, char courseName, float coursePrice);
void pop();
void display();

int count = 0;

//struct definition for stack
struct stack{
    int top;
    char courseName[MAX];
    float coursePrice;
};

//create empty stack
void create(struct stack *p)
{
    p -> top = -1;
}

//verify that stack is empty or not
int stackEmpty(struct stack *p)
{
    if(p -> top == -1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
}

//verify stack is full or not
int stackFull(struct stack *p)
{
    if(p -> top == MAX)
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
}

//push operation
void push(struct stack *p, char courseName, float coursePrice)
{
    if(stackFull(p) == 1)
    {
        printf("Stack is full");
    }
    else
    {
        /*
        printf("Enter course: ");
        gets(&courseName);
        printf("Enter course price: ");
        scanf("%f", &coursePrice);
        */
        p -> top++;
        p -> courseName[p -> top] = coursePrice;
    
    }
    count++;
}

//pop operation
void pop(struct stack *p)
{
    if(stackEmpty(p) == 1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nPopped course: %c (%.2f)\n", p -> courseName[p -> top], p -> coursePrice);
        p -> top--;
        count--;
    }
    
}

void display(struct stack *p)
{
    int x;

    if(p == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\n\nCourse List & Price\n\n");

        for (x = p -> top; x >= 0; x--)
        {
            printf(" %c (%.2f) ", p -> courseName[x], p -> coursePrice);
        }
        printf("\n");
    }
    
}

int main()
{
    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    create(p);

    printf("COURSE LIST & PRICE");
    display(p);
}