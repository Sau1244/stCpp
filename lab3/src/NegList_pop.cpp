#include "NegList.h"

void NegList::pop(){
    size--;
    int *temp = new int[size];

    for(int i = 0; i < size; i++)
        temp[i] = list[i];

    delete [] list;
    list = nullptr;

    list = temp;
}