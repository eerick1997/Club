#include <iostream>
#include <vector>

using namespace std;

template<class T> struct StackArray{
	
	vector<T> items;
	int head;

	StackArray(){
		head = 0;
		items = vector<T>(1);
	}

	void push(T value){

		if(head == items.size()){
			vector<T> replacement(2*items.size());
			for(int i = 0; i < head; i++)
				replacement[i] = items[i];
			items = replacement;
		}
		items[head++] = val;
	}

	void pop(){
		if(head == 0)
			throw runtime_error("You cannot erase from an empty Stack");
		if(head <= items.size()/4) {
			vector<T> replacement(items.size()/2);
			for(int i = 0; i < items.size(); i++)
				replacement[i] = items[i];
			items = replacement;
		}
		head--;
	}

	T top(){
		if(head == 0)
			throw runtime_error("");
		return items[head-1];
	}

	bool isEmpty(){
		return (head == 0);
	}


};