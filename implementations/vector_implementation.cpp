#include <iostream>  
#include <stdexcept> 

template <class T>
class m_vector {
public:
    m_vector(int size) : _vec_size(size), _current_index(0) {
        _vec = new T[_vec_size];
    }

    ~m_vector() {
        delete[] _vec;
    }

    void m_push_back(T input) {
        if (_current_index >= _vec_size) {
            std::cout << "Out of range, cannot add more elements." << std::endl;
            return;
        }
        _vec[_current_index] = input;
        ++_current_index;
    }

    T& operator[](int index) {
        if (index < 0 || index >= _current_index) {
            throw std::out_of_range("Index out of range");
        }
        return _vec[index];
    }

    int size() const {
        return _current_index;
    }

private:
    T* _vec;
    int _vec_size;
    int _current_index;
};
