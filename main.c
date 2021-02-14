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

/// <summary>
/// function that creates element and initial it with index as value and NULL as next cell pointer
/// </summary>
/// <param name="index"> the initial value </param>
/// <returns> pointer to the created cell</returns>
Node* CreateNewElement(int index)
{
    Node* newElement = (Node*)malloc(sizeof(Node));
    newElement->value = index;
    newElement->next = NULL;
    return newElement;
}

/// <summary>
/// insert element in the head of the linked list
/// </summary>
/// <param name="oldHead"> the original list head pointer </param>
/// <param name="newHead"> the new element </param>
/// <returns> new linked list head pointer</returns>
Node* PushElement(Node* oldHead, Node* newHead)
{
    newHead->next = oldHead;
    return newHead;
}

/// <summary>
/// insert element in the tail of the linked list
/// </summary>
/// <param name="oldHead"> the original list head pointer </param>
/// <param name="newHead"> the new element </param>
/// <returns> list head pointer</returns>
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

/// <summary>
/// pop element from the head of the linked list
/// </summary>
/// <param name="list"> the address of the head pointer </param>
/// <returns> the value of the popped cell</returns>
int PopElement(Node** list)
{
    Node* temp = *list;
    int retVal;
    retVal = temp->value;
    *list = temp->next;
    free(temp);
    return retVal;
}

/// <summary>
/// pop element from the tail of the linked list
/// </summary>
/// <param name="list"> the linked list pointer </param>
/// <returns> the value of the popped cell</returns>
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

/// <summary>
/// function that print single Node element
/// </summary>
/// <param name="newElement"> the pointer for the Node element</param>
void PrintElement(Node* newElement)
{
    printf("the value of the element is: %d\n", newElement->value);
    printf("the next element address of the element is: %p\n", newElement->next);
}


/// <summary>
/// function that print linked list from head to tail
/// </summary>
/// <param name="element"> pointer to the linked list head</param>
void PrintList(Node* element)
{
    while (element != NULL)
    {
        PrintElement(element);
        element = element->next;
    }
}

/// <summary>
/// recursive print function that prints the linked list from the tail to head
/// </summary>
/// <param name="element"> linked list head pointer</param>
void ReversePrintList(Node* element)
{
    if (element != NULL)
    {
        ReversePrintList(element->next);
        PrintElement(element);
    }
}


/// <summary>
/// function that free all linked list allocated memory
/// </summary>
/// <param name="element"> linked list head pointer </param>
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
