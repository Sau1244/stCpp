#include "NegList.h"

int NegList::operator[](int i) const{
    return (i < 0 ? list[size + i] : list[i]);
}
