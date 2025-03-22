#include "NegList.h"

void NegList::append(int num){
    size++;
    int *temp = new int[size];

    for(int i = 0; i < size - 1; i++)
        temp[i] = list[i];

    temp[size - 1] = num;

    delete [] list;

    list = temp;
}
