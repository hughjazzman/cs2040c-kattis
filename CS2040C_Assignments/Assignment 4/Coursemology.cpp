#define DEFAULTHEAPSIZE 1023

template <class T>
class Heap {
protected:
	T* _heap;
	int _n;
	void _bubbleUp(int index);
	void _bubbleDown(int index);
    int _lookFor(T x); // return the index of the item x, return -1 if not found
                       // it is not a good/usual implementation, so we hide it from public
    void _swap(int, int); // swap 2 indexes
public:
	Heap() {
		_heap = new T[DEFAULTHEAPSIZE];
		_n = 0;
	};

	void insert(T);
    bool empty() {return _n==0;};
	T extractMax();
    T peekMax() {return _heap[0];};
	void printHeapArray();
	void printTree();
    void increaseKey(T from, T to);
    void decreaseKey(T from, T to);
    void deleteItem(T);

	~Heap() { delete[] _heap; };
	
	//You may include your own functions, if necessary
};


template <class T>
void Heap<T>::_swap(int i, int j) {
	T temp = _heap[i];
	_heap[i] = _heap[j];
	_heap[j] = temp;
}

template <class T>
void Heap<T>::_bubbleUp(int index) {
	int parent = floor((index - 1) / 2);
	while (index > 0) {
		// If parent already larger do nothing
		if (_heap[parent] > _heap[index]) return;
		_swap(parent, index);
		index = parent;
		parent = floor((index - 1) / 2);
	}
}

template <class T>
void Heap<T>::_bubbleDown(int index) {
	int left = 2 * index + 1, right = left + 1, higher;
	while (right < _n) {
		T idxT = _heap[index], leftT = _heap[left], rightT = _heap[right];
		// If both child smaller do nothing
		if (idxT > leftT && idxT > rightT) return;
		// Higher priority placed into index
		higher = leftT > rightT ? left : right;
		_swap(higher, index);
		index = higher;
		left = 2 * index + 1;
		right = left + 1;
	}
	// Deal with no right, and left child higher priority
	if (left < _n && _heap[left] > _heap[index])
	    _swap(index, left);
}

template <class T>
void Heap<T>::insert(T item) {
	_heap[_n] = item;
	_bubbleUp(_n++);
}

template <class T>
T Heap<T>::extractMax() {
	T mx = peekMax();
	_heap[0] = _heap[--_n];
	_bubbleDown(0);
	return mx;
}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;
    
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
	int i = _lookFor(from);
	// If not found do nothing
	if (i == -1) return;
	_heap[i] = to;
	_bubbleDown(i);
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
	int i = _lookFor(from);
	// If not found do nothing
	if (i == -1) return;
	_heap[i] = to;
	_bubbleUp(i);
}

template <class T>
void Heap<T>::deleteItem(T x)
{
	int i = _lookFor(x);
	// If not found do nothing
	if (i == -1) return;
	T last = _heap[--_n];
	_heap[i] = last;
	x > last ? _bubbleDown(i) : _bubbleUp(i);
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;
	
	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		
		cout << endl;
		space /= 2;
	}

}

//If necessary, you may include your own functions




void customerQueueTest(int n_cust) {
	int current_time = 0;
	int totalWaitingTime = 0;
	int i;
	int WT = 0; // waiting time for each customer

	Heap<Customer> queue;

	Customer* custList = new Customer[n_cust];
	cout << endl << endl << "Setup" << endl;
	cout << "List of customers and their arrival and processing times" << endl;
	for (i = 0; i<n_cust; i++)
	{
		custList[i].setAT(i);
		custList[i].setPT((n_cust - i) % (n_cust / 2) + 1 + (i % 2)*(n_cust / 2));
		cout << "Customer " << i << " will arrive at time " << custList[i].AT() << " with PT=" << custList[i].PT() << endl;
	}
	cout << endl;


	for (int round = 0; round<2; round++) {
		// you may need a big modification within this for-loop
		cout << endl << endl;
		cout << "Test Round " << round + 1 << endl;
		cout << (round == 0 ? "First come first serve" : "Customer with the least PT served first") << endl;
		comparisonWay = round;
		current_time = 0;
		totalWaitingTime = 0;
		int nextTime = 0; // To track when next customer can be served

		// Keep going until all customers cleared
		while (!queue.empty() || current_time < n_cust) {
			// If customer arrive at the current_time, add to queue
			if (current_time < n_cust) {
				queue.insert(custList[current_time]);
				cout << "Customer arrives at time " << custList[current_time].AT() << " with PT=" << custList[current_time].PT() << endl;
			}
			// you should change all of the code here inside
			// If still processing current customer add time
			if (current_time < nextTime) {
				current_time++;
				continue;
			}
			Customer c = queue.extractMax();
			// Add processing time of next customer
			nextTime += c.PT();
			// Served when arriving
			if (c.AT() == current_time)
				cout << "Customer arrives when no one is waiting" << endl;
			WT = current_time - c.AT();
			totalWaitingTime += WT;
			cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for "
				<< WT << " min." << endl;
			// To the next minute
			current_time++;
		}
		cout << "Total Waiting Time: " << totalWaitingTime << endl;
		cout << "Average Waiting Time: " << totalWaitingTime / (float)n_cust << endl;

	}


	delete[] custList;
}
