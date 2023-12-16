#pragma once
#include <memory>
#include <concepts>
#include <initializer_list>

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
    static_assert(std::is_default_constructible_v<T>,"Types stored in Vector must have a default constructor");
public:
    Vector() : size_(0), capacity_(0), data_(nullptr), alloc_(Allocator()) {}
	Vector(size_t size, const T& val) 
	: size_(0), capacity_(0), data_(nullptr), alloc_(Allocator()) {
		reserve(size);
		for (size_t i{0}; i<size; ++i) {
			alloc_traits::construct(alloc_, data_+i, val);
		}
		size_ = size;
	}
	Vector(const Vector<T,Allocator>& other) requires std::copyable<T> {
		copy(other);
	}
	Vector(std::initializer_list<T> list) 
	: size_(0), capacity_(0), data_(nullptr), alloc_(Allocator()) {
		reserve(list.size());
		std::uninitialized_copy(list.begin(), list.end(), data_);
		size_ = list.size();
	}
	~Vector() {
		clear();
		deallocate();
	}

	size_t size() const { return size_; }
	size_t capacity() const {return capacity_;};
	void push_back(const T& value) {
		size_t old_size = size_;
		if (size_==capacity_) {
			reserve(capacity_==0 ? 1 : 2*capacity_);
		}
		size_ = old_size;
		alloc_traits::construct(alloc_, data_+size_, value);
		++size_;
	}
	void clear() {
		for (size_t i{0}; i<size_; ++i) {
			alloc_traits::destroy(alloc_, data_+i);
		}
		size_ = 0;
	}
	Vector<T, Allocator>& operator=(const Vector<T, Allocator>& other) {
		clear();
		deallocate();
		copy(other);
	}
	bool operator==(const Vector<T,Allocator>& other) {
		if (size_ != other.size_) {
			return false;
		}
		for (size_t i{0}; i<size_; ++i) {
			if (data_[i]!=other.data_[i]) {
				return false;
			}
		}
		return true;
	}
	T& operator[](size_t index) {
		if (index>=size_) {
			throw std::out_of_range("Index is too big");
		}
		return data_[index];
	}
	class Iterator{
		public : 
		using iterator_category = std::forward_iterator_tag;
		using difference_type   = std::ptrdiff_t;
		using pointer_type      = T*;
		using reference_type    = T&;

		Iterator() = default;
        Iterator(pointer_type ptr) : m_ptr(ptr) {}
    
    	reference_type operator*() const {
            return *m_ptr;
        }
		pointer_type operator->() {
            return m_ptr;
        }
        Iterator& operator++() {
            m_ptr++; 
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
		friend bool operator== (const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        }
        friend bool operator!= (const Iterator& a, const Iterator& b) { 
			return !(a == b);
        }

		private : 
			pointer_type m_ptr;
	};

	class ConstIterator 
    {
    public : 
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using pointer_type      = const T*;
        using reference_type    = const T&;

		ConstIterator() = default;
        ConstIterator(pointer_type ptr) : m_ptr(ptr) {}

    	reference_type operator*() const {
            return *m_ptr;
        }

		pointer_type operator->() {
            return m_ptr;
        }

        ConstIterator& operator++() {
            m_ptr++; return *this;
        }  
        ConstIterator operator++(int) {
            ConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
		friend bool operator== (const ConstIterator& a, const ConstIterator& b) {
            return a.m_ptr == b.m_ptr;
        }
        friend bool operator!= (const ConstIterator& a, const ConstIterator& b) {
			return !(a == b);
        }
		
    private:
        pointer_type m_ptr;
    };

	Iterator begin() { return Iterator(&data_[0]); }
    Iterator end()   { return Iterator(&data_[size_]); }

	ConstIterator begin() const { return ConstIterator(&data_[0]); }
    ConstIterator end() const   { return ConstIterator(&data_[size_]); }

	ConstIterator cbegin() { return ConstIterator(&data_[0]); }
    ConstIterator cend()   { return ConstIterator(&data_[size_]); }
	
private :
	T * data_;
	size_t capacity_;
	size_t size_;
	Allocator alloc_;
	using alloc_traits = std::allocator_traits<Allocator>;
	void copy(const Vector& other) {
		data_ = alloc_traits::allocate(alloc_, other.size_);
		size_ = other.size_;
		capacity_ = other.capacity_;
		std::uninitialized_copy(other.data_, other.data_ + other.size_, data_);
	}
	void allocate(size_t capacity) {
		data_ = alloc_traits::allocate(alloc_, capacity);
		capacity_ = capacity;
	}
	void deallocate() {
		alloc_traits::deallocate(alloc_, data_, capacity_);
	}
	void reserve(size_t capacity) {
		if (capacity > capacity_) {
			T* data = alloc_traits::allocate(alloc_, capacity);
			std::uninitialized_copy(data_, data_+size_, data);
			clear();
			deallocate();
			data_ = data;
			capacity_ = capacity;
		}
	}
};