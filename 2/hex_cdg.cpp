#include "hex.hpp"

bool wrong_digit(int a) {
    if (a==0 or (a>=48 and a<=57) or (a>=65 and a<=70))
        return false;
    return true;
}

Hex::Hex() {
    _size = 0;
    _array = nullptr;
}

Hex::Hex(const size_t n, unsigned char t) {
    if (wrong_digit(t))
        throw std::invalid_argument("Input digit out of range");
    _size = n;
    _array = new unsigned char[_size];
    for (size_t i{}; i < _size; ++i)
        _array[i] = t;
}

Hex::Hex(const std::initializer_list<unsigned char>& t) {
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i{_size-1};
    for (auto& c : t) {
        if (wrong_digit(c))
            throw std::invalid_argument("Input digit out of range");
        _array[i--] = c;
    }
}

Hex::Hex(const std::string& t) {
    _array = new unsigned char[t.size()];
    _size  = t.size();
    size_t i{_size-1};
    for(auto& c: t) {
        if (wrong_digit(c))
            throw std::invalid_argument("Input digit out of range");
        _array[i--] = c;
    }
}

Hex::Hex(const Hex& other) {
    _size  = other._size;
    _array = new unsigned char[_size];
    for(size_t i{}; i<other._size; ++i) 
        _array[i] = other._array[i];
}

Hex::Hex(Hex&& other) noexcept {
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Hex::~Hex() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

size_t Hex::get_size() {
    return _size;
}

unsigned char* Hex::get_array() {
    return _array;
}

std::string Hex::get_string_for_view() {
    std::string printed = "";
    std::string s(reinterpret_cast<char const*>(_array), _size);
    std::reverse(s.begin(), s.end());
    return s;
}