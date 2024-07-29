#include <stdio.h>
#define N 5
int top = -1;
int stack[N];

void push()
{

    if (top == N - 1)
    {
        printf("stack is full.\n");
    }
    else
    {

        top++;

        printf("Enter the %d element of stack", top);
        scanf("%d", &stack[top]);
    }
}
void pop()
{

    if (top == -1)
    {
        printf("stack is empty.\n");
    }
    else
    {
        top--;
    }
}

void display()
{

    if (top == -1)
    {
        printf("stack is empty.\n");
    }
    else
    {
        printf("stack elements are.\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d \t", stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    int choice;
    while (1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("Enter your choice.");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Visit again.");

            goto exit;
        }
    }
    exit:

    return 0;
}