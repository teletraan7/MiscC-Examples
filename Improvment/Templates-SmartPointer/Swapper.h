#ifndef SWAPPER_H
#define SWAPPER_H

//This example is showing how you would create a template in a header file.
template <typename  T>
class Swapper
{
public:
    Swapper(T first, T second);
    void swap();
    T getFirst() const;
    T getSecond() const;
private:
    T first;
    T second;
};

template<typename T>
Swapper<T>::Swapper(T first, T second)
{
    this->first = first;
    this->second = second;
}

template<typename T>
void Swapper<T>::swap()
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
T Swapper<T>::getFirst() const
{
    return first;
}

template <typename T>
T Swapper<T>::getSecond() const
{
    return second;
}
#endif