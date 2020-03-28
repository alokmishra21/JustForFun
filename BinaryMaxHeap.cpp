
class BinaryMaxHeap
{
	int *_heap;
	int _size;
public:
	BinaryMaxHeap(int N): _size(0)
	{
		_heap = new int[N];
	}
	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}
	int find_parent(int index)
	{
		return index/2;
	}
	int left_child(int index)
	{
		int l_c = 2 * index + 1;
		return l_c >= _size ? -1 : l_c;
	}
	int right_child(int index)
	{
		int r_c = 2 * index + 2;
		return r_c >= _size ? -1 : r_c;
	}
	int peek()
	{
		if ( _size == 0 )
		{
			cout << "Heap is empty!!" << endl;
			return -1;
		}
		return _heap[0];
	}
	void bubble_down(int index)
	{
		if (index >= _size)
			return;
		if (_heap[index] < max( _heap[max(index, left_child(index))], _heap[max(index, right_child(index))] ))
		{
			int swap_index = _heap[max(index, left_child(index))] > _heap[max(index, right_child(index))] ? left_child(index) : right_child(index);
			swap(_heap[index], _heap[swap_index]);
			bubble_down(swap_index);
		}
	}
	int poll()
	{
		// This function removes and return the first
		// element from the heap;
        if ( _size == 0 )
		{
			cout << "poll::Heap is empty!!" << endl;
			return -1;
		}
		swap(_heap[0], _heap[_size - 1]);
		int removed_item = _heap[_size - 1];
		_size--;
		// Now bubble down to maintain heap property
		bubble_down(0);
		return removed_item;
	}
	void remove(){}
	void bubble_up(int index)
	{
		if (index == 0) 
			return;
		if (_heap[index] > _heap[find_parent(index)])
		{
			swap(_heap[index], _heap[find_parent(index)]);
			bubble_up(find_parent(index));
		}
	}
	void insert(int val)
	{
		_heap[_size++] = val;
		// bubble up from bottom to maintain max heap property
		bubble_up(_size - 1);
	}
};

int main()
{
	BinaryMaxHeap h(10);
	h.insert(4);
	h.insert(10);
	cout << h.peek() << endl;
	h.insert(50);
	h.insert(1);
	cout << "peek : " << h.peek() << endl;
	cout<< "poll : " << h.poll() << endl;
	cout << "peek : " << h.peek() << endl;
	cout<< "poll : " << h.poll() << endl;
	cout << "peek : " << h.peek() << endl;
	cout<< "poll : " << h.poll() << endl;
    
	cout << "peek : " << h.peek() << endl;
	cout<< "poll : " << h.poll() << endl;
    
	cout << "peek : " << h.peek() << endl;
	cout<< "poll : " << h.poll() << endl;
}
