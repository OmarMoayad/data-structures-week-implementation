#include <iostream>
using namespace std;
// Big O of N
class DynamicArray {
private:
    int* data; 
    int length;  // عدد العناصر الحالية
    int capacity; // الحجم الكلي

    void resize() {
        int newCapacity = capacity * 2; // مضاعفة السعة عند الحاجة
        int* newData = new int[newCapacity];
        for (int i = 0; i < length; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    //constructor
    DynamicArray() {
        capacity = 2; // السعة الابتدائية
        length = 0;
        data = new int[capacity];
    }
    // destructor
    ~DynamicArray() {
        delete[] data;
    }

    void add(int value) { 
        if (length == capacity)
            resize();
        data[length++] = value;
    }

    int get(int index) {
        if (index < 0 || index >= length) {
            cout << "Error: index out of bounds" << endl;
            return -1; 
        }
        return data[index];
    }

    void set(int index, int value) { 
        if (index < 0 || index >= length) {
            cout << "Error: index out of bounds" << endl;
            return;
        }
        data[index] = value;
    }

    int size()  { // برجع عدد العناصر الحالية
        return length;
    }

    void print()  {
        cout << "[";
        for (int i = 0; i < length; ++i) {
            cout << data[i];
            if (i != length - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.add(1);
    arr.add(2);
    arr.add(3); // هون بكبر وبعمل resize

    arr.print(); // [1, 2, 3]

    cout << "Element at index 1: " << arr.get(1) << endl; // 2

    arr.set(1, 99);
    arr.print(); // [1, 99, 3]

    cout << "Size: " << arr.size() << endl;

    return 0;
}
