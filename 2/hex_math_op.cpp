#include "hex.hpp"

int to_dec(int a) {
    return (a>=65) ? a-55 : a-48;
}

int to_hex(int a) {
    return (a>9) ? a+55 : a+48;
}

Hex Hex::operator+(const Hex& other) {
    size_t rd{}, maxlen, minlen;
    bool first = _size > other._size;
    maxlen = first ? _size : other._size;
    minlen = first ? other._size : _size;
    Hex result(maxlen, 0);
    for (size_t i{}; i<minlen; ++i) {
        size_t sum = to_dec(_array[i])+to_dec(other._array[i])+rd;
        rd = sum / 16;
        result._array[i]=to_hex(sum%16);
    }
    size_t counter{minlen};
    while (counter<maxlen and rd>0) {
        size_t n = first ? to_dec(_array[counter]) : to_dec(other._array[counter]);
        size_t sum = n + rd;
        rd = sum/16;
        result._array[counter]=to_hex(sum%16);
        ++counter;
    }
    if (rd>0) {
        ++result._size;
        unsigned char* arr_upd = new unsigned char[_size];
        for (size_t i{}; i<result._size-1; ++i)
            arr_upd[i] = result._array[i];
        arr_upd[result._size-1] = to_hex(rd);
        delete result._array;
        result._array = arr_upd;
    }
    return result;
}

Hex Hex::operator-(const Hex& other) {
    if (_size < other._size)
        throw std::invalid_argument("Minuend is smaller than subtrahend");
    Hex result(_size, 0);
    bool rd{false};
    for (size_t i{}; i<_size; ++i) {
        long long n = to_dec(_array[i]);
        if (i<other._size) {
            n-=to_dec(other._array[i]);
        }
        if (rd) {
            --n;
            rd=false;
        }
        if (n<0) {
            n+=16;
            rd=true;
        }
        result._array[i]=to_hex(n);
    }
    if (rd)
        throw std::invalid_argument("Minuend is smaller than subtrahend");
    long long counter{-1};
    for (size_t i{_size-1}; i>0; --i) {
        if (to_dec(result._array[i])!=0) {
            break;
        } else {
            counter = i;
        }
    }
    if (counter!=-1) {
        result._size = counter;
        unsigned char* arr_upd = new unsigned char[_size];
        for (size_t i{}; i<result._size; ++i)
            arr_upd[i] = result._array[i];
        delete result._array;
        result._array = arr_upd;
    }
    return result;
}

void Hex::operator=(const Hex& other) {
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i{_size-1}; i>0; --i) 
        _array[i] = other._array[i];
}