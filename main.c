#include<stdio.h>

typedef struct node {
    int value;
    struct node *next;
}Node;

Node* CreateNewElement(int);
Node* PushElement(Node*, Node*);
Node* PushLastElement(Node*, Node*);
void PrintElement(Node*);
void PrintList(Node*);
void ReversePrintList(Node*);
void DeleteList(Node*);
int PopElement(Node**);
int PopLastElement(Node*);


int main()
{
    Node *head, *element2, *element3;
    int poppedValue = 0;
    head = CreateNewElement(1);
    element2 = CreateNewElement(2);
    element3 = CreateNewElement(3);
    head = PushElement(head, element2);
    head = PushElement(head, element3);
    PrintList(head);
    poppedValue = PopElement(&head);
    printf("poped element: %d\n", poppedValue);
    PrintList(head);
    DeleteList(head);
}

Node* CreateNewElement(int index)
{
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->value = index;
    newElement->next = NULL;
    return newElement;
}

Node* PushElement(Node* oldHead, Node* newHead)
{
    newHead->next = oldHead;
    return newHead;
}

Node* PushLastElement(Node* head, Node* newElement)
{
    Node* lastElement = head;
    while (lastElement->next != NULL)
    {
        lastElement = lastElement->next;
    }
    lastElement->next = newElement;
    return head;
}

int PopElement(Node** list)
{
    Node* temp = *list;
    int retVal;
    retVal = temp->value;
    *list = temp->next;
    free(temp);
    return retVal;
}

int PopLastElement(Node* list)
{
    int retVal;
    Node* lastElement = list;
    Node* beforeLastElement = NULL;
    while (lastElement->next != NULL)
    {
        beforeLastElement = lastElement;
        lastElement = lastElement->next;
    }
    if(beforeLastElement != NULL)
        beforeLastElement->next = NULL;
    retVal = lastElement->value;
    free(lastElement);
    return retVal;
}

void PrintElement(Node* newElement)
{
    printf("the value of the element is: %d\n", newElement->value);
    printf("the next element address of the element is: %p\n", newElement->next);
}

void PrintList(Node* element)
{
    while (element != NULL)
    {
        PrintElement(element);
        element = element->next;
    }
}

void ReversePrintList(Node* element)
{
    if (element != NULL)
    {
        ReversePrintList(element->next);
        PrintElement(element);
    }
}

void DeleteList(Node* element)
{
    Node* next;
    while (element != NULL)
    {
        next = element->next;
        free(element);
        element = next;
    }
}
