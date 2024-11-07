#include <iostream>

class Array {
private:
    int* data;
    int size;

public:
    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other) return *this;
        delete[] data;

        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    Array operator+(const Array& other) const {
        Array result(size + other.size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i];
        }
        for (int i = 0; i < other.size; ++i) {
            result.data[i + size] = other.data[i];
        }
        return result;
    }

    int& operator[](int index) {
        return data[index];
    }

    ~Array() {
        delete[] data;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
