#pragma once

#include <iostream>

/**
 * @brief Klasa reprezentująca zaimplementowany wektor
 * @tparam T Określa typ przechowywany typ danych
 */
template<typename T>
class BetterVector{
private:
    T* data; /** Wskaźnik do tablicy przechowującej dane */
    size_t actualSize; /** Ilość przechowywanych danych */
    size_t maxSize; /** Maksymalny rozmiar kontenera */
public:
    /**
     * @brief Konstruktor domyślny, przypisujący początkowe wartości parametrom
     */
    BetterVector() : actualSize(0), maxSize(0), data(nullptr){}

    /**
     * @brief Destruktor - usuwa pamięć przechowywanych danych
     */
    ~BetterVector() { delete [] data; }

    /**
     * @brief Konstruktor kopiujący
     * @param other Wektor, który jest kopiowany
     */
    BetterVector(const BetterVector& other) : maxSize(other.maxSize), actualSize(other.actualSize){
        data = new T[maxSize];
        copy(other.data, data, actualSize);
    }

    /**
     * @brief Operator kopiujący
     * @param other Wektor, który jest kopiowany
     * @return Referencja do skopiowanego obiektu
     */
    BetterVector& operator=(const BetterVector& other){
        if(this != &other){
            delete [] data;
            maxSize = other.maxSize;
            actualSize = other.actualSize;
            data = new T[maxSize];
            copy(other.data, data, actualSize);
        }
        return *this;
    }

    /**
     * @brief Konstruktor przenoszący
     * @param other Wektor, który jest przenoszony
     */
    BetterVector(BetterVector&& other) noexcept
        : data(other.data), actualSize(other.actualSize), maxSize(other.maxSize){
        clearH(other);
    }

    /**
     * @brief Operator przenoszący
     * @param other Wektor, który jest przenoszony
     * @return Referencja do skopiowanego obiektu
     */
    BetterVector& operator=(BetterVector&& other) noexcept{
        if(this != &other){
            delete [] data;
            data = other.data;
            maxSize = other.maxSize;
            actualSize = other.actualSize;
            clearH(other);
        }
        return *this;
    }

    /**
     * @brief Czyści całkowicie dane obiektu, ustawia `data` na nullptr - przydatne dla konstruktora/operatora przenoszącego
     * @param obj Czyszczony obiekt
     */
    void clearH(BetterVector& obj){
        obj.data = nullptr;
        obj.actualSize = 0;
        obj.maxSize = 0;
    }

    /**
     * @brief Usuwa wszystkie elementy z wektora
     */
    void clear(){
        actualSize = 0;
    }

    /**
     * @brief Zwiększa pojemność wektora do co najmniej wartości new_capacity, jeżeli aktualnie pojemność jest mniejsza
     * @param newCapacity Nowa alokowana wielkość
     */
    void reserve(size_t newCapacity){
        if(maxSize < newCapacity){
            maxSize = newCapacity;
            reallocMemory();
        }
    }

    /**
     * @brief Umożliwia stworzenie nowego elementu bezpośrednio na końcu wektora, konstruowane bezpośrednio w pamięci
     * @tparam Args ... Typ elementów przyjmujący jego dowolną ilość
     * @param args Tworzony element
     */
    template<typename... Args>
    void emplace_back(Args&&... args){
        push_back(T(std::forward<Args>(args)...));
    }

    /**
     * @brief Dodaje każdą odpowiednią wartość wektora do drugiego wektora, gdy są tej samej wielkości
     * @param other Drugi wektor
     * @return Stworzony wektor - suma wartości
     */
    BetterVector operator+(const BetterVector& other){
        BetterVector<T> v;
        if(other.actualSize == actualSize){
            for(size_t i = 0; i < actualSize; i++)
                v.push_back(data[i] + other.data[i]);
        }

        return v;
    }

    /**
     * @brief Odejmuje każdą odpowiednią wartość wektora od drugiego wektora, gdy są tej samej wielkości
     * @param other Drugi wektor
     * @return Stworzony wektor - różnica wartości
     */
    BetterVector operator-(const BetterVector& other){
        BetterVector<T> v;
        if(other.actualSize == actualSize){
            for(size_t i = 0; i < actualSize; i++)
                v.push_back(data[i] - other.data[i]);
        }

        return v;
    }

    /**
     * @brief Mnoży każda kolejną wartość wektora o skalar
     * @tparam Scalar Typ skalaru
     * @param scalar Skalar mnożący
     * @return Stworzony wektor - iloczyn przez skalar
     */
    template<typename Scalar, typename = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
    BetterVector operator*(const Scalar& scalar){
        BetterVector<decltype(std::declval<T>()*std::declval<Scalar>())> v;
        for(size_t i = 0; i < actualSize; i++)
            v.push_back(this->data[i]*scalar);

        return v;
    }

    /**
     * @brief Podwaja maksymalny rozmiar tablicy. Gdy wartość wynosi 0, przypisuje mu 1.
     */
    void doubleMaxSize(){
        maxSize = maxSize ? maxSize * 2 : 1;
    }

    /**
     * @brief Kopiuje wartości ze źródła do nowej tablicy
     * @param dataSource Źródło, z którego wartości są kopiowane
     * @param newData Nowy kontener, do której wartości są kopiowane
     * @param size Aktualna ilość przechowywanych danych - `actualSize`
     */
    void copy(T* dataSource, T* newData, size_t size){
        for(size_t i = 0; i < size; i++){
            newData[i] = dataSource[i];
        }
    }

    /**
     * @brief Alokuje pamięć, gdy zwiększa się jej maksymalna wielkość. Nadpisuje dane.
     */
    void reallocMemory(){
        T *newBegin = new T[maxSize];
        if(data){
            copy(data, newBegin, actualSize);
            delete[] data;
        }
        data = newBegin;
    }

    /**
     * @brief Dodaje element na koniec kontenera, zwiększa się `actualSize`
     * @param newElement Dodawany element
     */
    void push_back(const T& newElement) {
        if(actualSize == maxSize){
            doubleMaxSize();
            reallocMemory();
        }
        data[actualSize++] = newElement;
    }

    /**
     * @brief Zmniejsza wartość `actualSize`
     */
    void pop_back(){
        if(actualSize) --actualSize;
    }

    /**
     * @brief Operator [] pozwala dostać się do konkretnego elementu
     * @param index Indeks konkretnego elementu
     * @return Referencja konkretnego elementu
     */
    T& operator[](size_t index){
        return data[index];
    }

    /**
     * @brief Zwraca aktualną wielkość kontenera
     * @return Ilość przechowywanych elementów
     */
    size_t size() const{ return actualSize; }

    /**
     * @brief Zwraca zaalokowaną wielkość kontenera
     * @return Maksymalna ilość kontenera
     */
    size_t capacity() const{ return maxSize; }

    /**
     * @brief Sprawdza, czy kontener jest pusty
     * @return Wartość logiczna: true - pusty, false - zawiera elementy
     */
    bool empty() const{ return !actualSize; }

    /**
     * @brief Pierwszy element kontenera
     * @return Referencja do pierwszego elementu
     */
    T& front(){ return *data; }

    /**
     * @brief Ostatni element kontenera
     * @return Referencja do ostatniego elementu
     */
    T& back(){ return *(data + actualSize - 1); }

    /**
     * @brief `const` pierwszego elementu kontenera
     * @return Referencja `const` do pierwszego elementu
     */
    const T& front() const{ return *data; }

    /**
     * @brief `const` ostatniego elementu kontenera
     * @return Referencja `const` do ostatniego elementu
     */
    const T& back() const{ return *(data + actualSize - 1); }

    /**
     * @brief Iterator pierwszego elementu kontenera
     * @return Referencja do pierwszego elementu
     */
    T* begin(){ return data; }

    /**
     * @brief Iterator ostatniego elementu kontenera
     * @return Referencja do ostatniego elementu
     */
    T* end(){ return data + actualSize; }

    /**
     * @brief Iterator `const` pierwszego elementu kontenera
     * @return Referencja `const` do pierwszego elementu
     */
    const T* begin() const{ return data; }

    /**
     * @brief `const` ostatniego elementu kontenera
     * @return Referencja `const` do ostatniego elementu
     */
    const T* end() const{ return data + actualSize ; }
};