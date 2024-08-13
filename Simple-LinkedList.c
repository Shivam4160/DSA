#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *ptr;
};

void Insert_Front(int Element)
{
}
void Delete_Front()
{
}
void Insert_Mid(int Element,int Position)
{
}
void Delete_Mid(int Element,int Position)
{
}
void Insert_End(int Element)
{
}
void Delete_End()
{
}

void Display(int Element)
{
}
int main()
{
    int Choice, Element, Position;

    while (1)
    {
        printf("\n1.Insert Front");
        printf("\n2.Delete Front");
        printf("\n3.Insert Mid");
        printf("\n4.Delete Mid");
        printf("\n5.Insert End");
        printf("\n6.Delete End");
        printf("\n7.Display");
        printf("\n8.Exit");

        printf("\nEnter your Choice:");
        scanf("%d", &Choice);

        if (!(Choice < 8 || Choice > 0))
        {
            printf("Invalid Choice!! Enter Again..");

            continue;
        }

        switch (Choice)
        {
        case 1:

            printf("Enter the Element you want to add from front:");
            scanf("%d", &Element);

            Insert_Front(Element);
            break;
        case 2:

            Delete_Front();
            break;
        case 3:
            printf("Enter the Element you want to add from front:");
            scanf("%d", &Element);

            Insert_Mid(Element,Position);
            break;

        case 4:

            Delete_Mid(Position);
            break;
        case 5:
            printf("Enter the Element you want to add from front:");
            scanf("%d", &Element);

            Insert_End(Element);
            break;
        case 6:

            Delete_End();
            break;
        case 7:

            Display();
            break;
        case 8:

            goto Exit;
        }
    }

Exit:
    return 0;
}