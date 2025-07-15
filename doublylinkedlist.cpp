#include <iostream>
#include <string>
using namespace std;

template<typename T>
class DNode {
private:
    T data;
    DNode<T>* prev, * next;
    template<typename T> friend class DoublyList;
};

template<typename T>
class DoublyList {
private:
    DNode<T>* header, * trailer;
    int n;

public:
    DoublyList() {
        header = new DNode<T>;
        trailer = new DNode<T>;
        header->next = trailer;
        trailer->prev = header;
        n = 0;
    }

    // Copy constructor
    DoublyList(const DoublyList& obj) {
        header = new DNode<T>;
        trailer = new DNode<T>;
        header->next = trailer;
        trailer->prev = header;
        n = 0;
        DNode<T>* p = obj.header->next;
        while (p != obj.trailer) {
            addBack(p->data);
            p = p->next;
        }
    }

    ~DoublyList() {
        while (!empty()) {
            removeFront();
        }
        delete header;
        delete trailer;
    }

    int size() const { return n; }
    bool empty() const { return header->next == trailer; }

    DNode<T>* createNode(const T& item) {
        DNode<T>* m = new DNode<T>;
        m->data = item;
        m->next = m->prev = nullptr;
        return m;
    }

    void addFront(const T& item) {
        DNode<T>* newnode = createNode(item);
        newnode->next = header->next;
        newnode->prev = header;
        header->next->prev = newnode;
        header->next = newnode;
        n++;
    }

    void addBack(const T& item) {
        DNode<T>* newnode = createNode(item);
        newnode->next = trailer;
        newnode->prev = trailer->prev;
        trailer->prev->next = newnode;
        trailer->prev = newnode;
        n++;
    }

    T& front() const {
        if (empty()) throw runtime_error("List is empty");
        return header->next->data;
    }

    T& back() const {
        if (empty()) throw runtime_error("List is empty");
        return trailer->prev->data;
    }

    bool removeFront() {
        if (empty()) return false;
        DNode<T>* p = header->next;
        header->next = p->next;
        p->next->prev = header;
        delete p;
        n--;
        return true;
    }

    DNode<T>* find(const T& item) {
        DNode<T>* p = header->next;
        while (p != trailer && p->data != item)
            p = p->next;
        return (p == trailer) ? nullptr : p;
    }

    bool remove(const T& item) {
        DNode<T>* p = find(item);
        if (!p) return false;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        n--;
        return true;
    }

    void printInReverse() {
        DNode<T>* p = trailer->prev;
        while (p != header) {
            cout << p->data << "\t";
            p = p->prev;
        }
        cout << endl;
    }


    bool isPalindrome() {
        DNode<T>* first = header->next;
        DNode<T>* last = trailer->prev;
        for (int i = 0; i < n / 2; ++i) {
            if (first->data != last->data)
                return false;
            first = first->next;
            last = last->prev;
        }
        return true;
    }
};

void displayList(DoublyList<string> L) {
    while (!L.empty()) {
        cout << L.front() << "  ";
        L.removeFront();
    }
    cout << endl;
}

int main() {
    DoublyList<string> st;
    cout << st.size() << endl;

    st.addFront("int");
    cout << st.size() << endl;

    st.addFront("float");
    st.addFront("double");
    st.addFront("char");
    cout << st.size() << endl;

    cout << "Front: " << st.front() << endl;
    cout << "Back: " << st.back() << endl;

    st.addBack("short");
    cout << "Back after addBack: " << st.back() << endl;

    cout << "List: ";
    displayList(st);

    st.addBack("double");  // add it back to test remove
    st.remove("double");

    cout << "List after removing 'double': ";
    displayList(st);

    cout << "Reverse: ";
    st.printInReverse();

    DoublyList<char> L;
    L.addFront('D');
    L.addFront('a');
    L.addFront('a');
    L.addFront('a');
    L.addFront('D');

    cout << "Is Palindrome: " << (L.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}
