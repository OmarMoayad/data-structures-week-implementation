#include <iostream>

using namespace std;

template<typename T>
class ArrayQueue
{
private:
	T* q;
	int  R, F, n, capacity;

public:
	ArrayQueue(int newCap = 5) {
		R = F = n = 0;
		capacity = newCap;
		q = new T[capacity];
	}

	~ArrayQueue() {
		if (q) delete[] q;
		q = NULL;
	}

	bool empty() const { return n <= 0; }
	int size() const { return  n; }
	bool full() const { return n >= capacity; }

	bool enqueue(const T& elem) {
		if (full()) return false;
		q[R] = elem;
		R = (R + 1) % capacity;
		n++;
		return true;
	}

	void dequeue() {
		if (empty()) return;
		F = (F + 1) % capacity;
		n--;

	}
	T front() const {

		if (empty()) exit(1);
		return q[F];
	}
};

int main()
{
	ArrayQueue<int> q(10);
	for (int i = 0; i < 10; i++) {
		q.enqueue(i);
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.dequeue();
	}
	cout << endl;
	return 0;
}