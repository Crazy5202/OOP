#include "hex.hpp"

bool Hex::operator>(const Hex& other) {
    if (_size > other._size)
        return true;
    if (_size < other._size)
        return false;
    for (size_t i{_size-1}; i>=0; --i) {
        if (_array[i]>other._array[i])
            return true;
        if (_array[i]<other._array[i])
            return false;
    }
    return false;
}

bool Hex::operator<(const Hex& other) {
    if (_size > other._size)
        return false;
    if (_size < other._size)
        return true;
    for (size_t i{_size-1}; i>=0; --i) {
        if (_array[i]>other._array[i])
            return false;
        if (_array[i]<other._array[i])
            return true;
    }
    return false;
}

bool Hex::operator==(const Hex& other) {
    if (_size != other._size)
        return false;
    for (size_t i{}; i<_size; --i) {
        if (_array[i] != other._array[i])
            return false;
    }
    return true;
}