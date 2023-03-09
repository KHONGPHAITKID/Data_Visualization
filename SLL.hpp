#ifndef _SLL_HPP_
#define _SLL_HPP_
#include <iostream>
#include <ctime>

struct SLL_Node
{
    int data;
    SLL_Node* next;
};

void DeleteSLL(SLL_Node* &pHead);

void SortSLL(SLL_Node* &pHead);

void addBack(SLL_Node* pHead, int value);

void CreateRandomSLL(SLL_Node* &pHead);

#endif