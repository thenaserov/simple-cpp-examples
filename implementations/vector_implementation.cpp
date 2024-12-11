// A vector should have:
// constructor (ok)
// destructor  (ok)
// push_back   (ok)
// pop         (no)
// size        (ok)

#include <iostream>

template <class T>
class m_vector {

	T* _vec;
	size_t _vec_size{ 1 };
	int _current_index{ 0 };

public:

	m_vector(int size) {
		_vec = new T[size];
		_vec_size = size;
		_current_index = --size;
	}

	m_vector() {
		_vec = new T[1];
		_vec_size = 1;
		_current_index = 0;
	}

	~m_vector() { delete[] _vec; }

	void m_push_back(T input) {
		if (_current_index == _vec_size) {
			T* temp = new T[2 * _vec_size];
			for (int i{ 0 }; i < _vec_size; i++) {
				temp[i] = _vec[i];
			}
			delete[] _vec;
			_vec_size *= 2;
			_vec = temp;
		}
		_vec[_current_index] = input;
		_current_index++;
	}
	void pop() {
		if (_current_index > 0) {
			_current_index--;
		}
		else {
			throw std::out_of_range("No elements to pop");
		}
	}

	int size() const {
		return _current_index;
	}

	T& operator[](int index) {
		if (index < 0 || index >= _current_index) {
			throw std::out_of_range("Index out of range");
		}
		return _vec[index];
	}
};

int main() {
	m_vector<int> myVec = m_vector<int>(2);
	myVec.pop();
	std::cout << myVec.size() << std::endl;
	return 0;
}
