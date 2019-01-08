/**Prority queue**/

template<class T> struct PriorityQueue{
	
	vector<T> tree;
	int size;

	PriorityQueue(){
		tree = vector<T>(5);
		size = 0;
	}

	void swim(int pos){
		int k = pos;
		while(k/2 > 0 && tree[k/2] < tree[k]){
			//swap intercambia el valor entre dos variables	
			swap(tree[k/2], tree[k]);
			k /=2;
		}
	}

	void push(T val){
		if(size == tree.size() - 1) rezise(2*size+1);
		tree[++size] = val;
		swim(size);
	}

	/**
	| x | raiz | hijo | hijo | hijo | hijo | hijo | hijo | hijo |
	**/
	T top(){
		if(size == 0) throw runtime_error("Tree is empty");
		return tree[1];
	}

	boolean empty(){
		return size == 0;
	}

	void sink(int pos){
		int k = pos;
		while(true){
			if((2*k <= size) && (2*k+1 <= size)){
				if(tree[2*k]>tree)
			}
		}
	}
};