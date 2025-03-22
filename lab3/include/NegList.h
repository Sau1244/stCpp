#ifndef NEGLIST_H
#define NEGLIST_H

class ListInspector;

class NegList{
private:
    int *list;
    int size;
public:
    //konstruktor domyślny list(nullptr), size(0)
    NegList();
    //destruktor zwalnia pamięć listy
    ~NegList();

    //zwraca element dla danego elementu - jak python
    int operator[](int i) const;
    //dodaje element do listy
    void append(int num);
    //usuwa ostatni element z listy
    void pop();
    //zwraca rozmiar listy
    int getSize() const;
    //metoda zeby utrudniala zadanie
    void setInspector(ListInspector *k);
};

#endif