#include "SLL.hpp"

void DeleteSLL(SLL_Node* &pHead)
{
    SLL_Node* temp = pHead;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        delete temp;
        temp = pHead;
    }
    pHead = nullptr;
}

void SortSLL(SLL_Node* &pHead)
{
    SLL_Node* i = pHead;
    while (i->next != nullptr)
    {
        SLL_Node min_ptr = i;
        SLL_Node j = i->next;
        while (j != nullptr)
        {
            if (j->data < min_ptr->data)
            {
                min_ptr = j;
            }
            j = j->next;
        }
        int temp = i->data;
        i->data = min_ptr->data;
        min_ptr->data = temp;
        i = i->next;
    }
}

void addBack(SLL_Node* pHead, int value)
{
    SLL_Node* temp = new SLL_Node;
    temp->data = value;
    temp->next = nullptr;
    if (pHead == nullptr)
    {
        pHead = temp;
        return;
    }
    pHead->next = temp;
}

void CreateRandomSLL(SLL_Node* &pHead)
{
    DeleteSLL(pHead);
    int n = 3 + srand() % 7;
    while (n--)
    {
        int randomValue = 1 + srand() % 99;
        addBack(pHead, randomValue);
    }
}