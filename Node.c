#include <stdio.h>

struct Node
{
    int Data;
    char A;
    struct Node *ptr;
};

int main()
{
    struct Node ob, ob2;

    ob.A = 'A';
    ob.Data = 65;
    ob.ptr = NULL;

    ob2.A = 'a';
    ob2.Data = 97;
    ob2.ptr = NULL;

    printf("ob.A:%c\t\tob.Data:%d\nob2.A:%c\t\tob2.Data:%d\n", ob.A, ob.Data, ob2.A, ob2.Data);

    ob.ptr = &ob2;
    ob2.ptr = &ob;

    printf("ob.A:%c\t\tob.Data:%d\nob2.A:%c\t\tob2.Data:%d", ob.ptr->A, ob.ptr->Data, ob2.ptr->A, ob2.ptr->Data);
    return 0;
}
