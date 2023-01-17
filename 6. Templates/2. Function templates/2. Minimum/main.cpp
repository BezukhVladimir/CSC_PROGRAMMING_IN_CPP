#include <cstddef>

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& other);
    ~Array();
    Array& operator=(Array other);
    void swap(Array &other);
    size_t size() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;

private:
    size_t size_;
    T * data_;
};

template <typename T, typename Comp>
const T& minimum(const Array<T>& ar, const Comp& comp)
{
    const T * result = &ar[0];
    
    for (size_t i = 1, size = ar.size(); i < size; ++i)
        if (comp(ar[i], *result))
            result = &ar[i];
        
    return * result;
}