#include "NegList.h"

NegList::NegList() : list(nullptr), size(0) {}

NegList::~NegList() {
    delete [] list;
}

int NegList::getSize() const{
    return size;
}

void NegList::setInspector(ListInspector *k){}