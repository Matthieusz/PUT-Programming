template <typename T>
class Vector{
private:
    size_t dimensions;
    T* data;
public:
    Vector(size_t size) : dimensions(size), data(new T[size]) {}

    Vector(const Vector<T>& other) : dimensions(other.dimensions), data(new T[other.dimensions]) {
        copy(other.data, other.data + other.dimensions, data);
    }

    Vector(Vector<T>&& other) noexcept : dimensions(other.dimensions), data(other.data) {
        other.data = nullptr;
        other.dimensions = 0;
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] data;
            dimensions = other.dimensions;
            data = new T[other.dimensions];
            std::copy(other.data, other.data + other.dimensions, data);
        }
        return *this;
    }
    virtual ~Vector<T>() {
        if(data) delete[] data;
    }
    size_t size() const {
        return dimensions;
    }
    T& operator[](size_t index) { // a
        return data[index];
    }
    const T& operator[](size_t index) const { // a
        return data[index];
    }
    Vector<T> operator+(const Vector<T>& b) { // b
        Vector<T> c(this->size());
        for (size_t i = 0; i < this->size(); i++) {
            c[i] = (*this)[i] + b[i];
        }
        return c;
    }
    Vector<T> operator-(const Vector<T>& b) { // c
        Vector<T> c(this->size());
        for (size_t i = 0; i < this->size(); i++) {
            c[i] = (*this)[i] - b[i];
        }
        return c;
    }
    bool operator==(const Vector<T>& b) { // d
        if (this->size() != b.size()) return false;
        for (size_t i = 0; i < this->size(); i++) {
            if ((*this)[i] != b[i]) return false;
        }
        return true;
    }
    bool operator!=(const Vector<T>& b) { // e
        return !(*this == b);
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& v) { // f
        for (size_t i = 0; i < v.size(); i++) {
            os << v[i] << " ";
        }
        return os;
    }
};
template <typename T>
    Vector<T> add(const Vector<T>& a, const Vector<T>& b) { // b
    Vector<T> c(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}
template<typename T>
bool equals(const Vector<T>& a, const Vector<T>& b) { // c
    if (&a == &b) return true;
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}; 