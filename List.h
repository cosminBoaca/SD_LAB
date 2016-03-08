template<typename T>
class List {
private:
    class Iterator {
    public:
        T& operator *();
        T* operator ->();
        Iterator operator ++();
        Iterator operator ++(int);
    };

public:
    typedef Iterator iterator;
    void insert(const T& element, unsigned index);
    void remove(unsigned index);
    void push_back(const T& element);
    void push_front(const T& element);
    iterator begin();
    iterator end();
};
