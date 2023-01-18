#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head;

// initialize head

void initList()
{
    head = (Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->next = NULL;
}

// insert aNode to the next of Target
Node *insertNode(Node *Target, Node *aNode)
{
    Node *New;
    Node *Right;

    New = (Node *)malloc(sizeof(Node));
    *New = *aNode;

    Right = Target->next;
    Target->next = New;
    New->next = Right;
    New->prev = Target;

    if (Right)
    {
        Right->prev = New;
    }
    return New;
}

void printList(Node *Now)
{
    for (Now = head->next; Now; Now = Now->next)
    {
        printf("%d", Now->value);
    }
}

Node *appendNode(Node *newNode)
{
    Node *last;
    for (last = head; last->next; last = last->next)
    {
        ;
    }
    insertNode(last, newNode);
}

int deleteNode(Node *target)
{
    Node *former, *latter;
    if (target == NULL || target == head)
    {
        return 0;
    }

    former = target->prev;
    latter = target->next;

    former->next = latter;
    if (latter)
    {
        latter->prev = former;
    }
    free(target);
    return 1;
}

Node *findNodeByIndex(int idx)
{
    Node *curr = head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->next;
        if (curr == NULL)
            return NULL;
    }
    return curr;
}

int main()
{
    initList();
    Node nNode;

    for (int i = 0; i < 10; i++)
    {
        nNode.value = i;
        appendNode(&nNode);
    }

    printList(head);

    printf("\n");
    printList(head);

    printf("\n");
    printf("%d", findNodeByIndex(4)->value);

    Node *nodeToDelete = findNodeByIndex(2);
    deleteNode(nodeToDelete);

    printf("\n");
    printf("\n");
    printList(head);

    return 0;
}