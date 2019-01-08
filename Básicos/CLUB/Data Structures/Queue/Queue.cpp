/**Colas**/

Template<class T> struct Queue{

	struct Node{
		Node* next;
		T data;

		Node(T value){
			data = value;
			next = NULL;
		}
	};

	Node *head;
	Node *tail;
	int size;

	Queue(){
		head = tail = NULL;
		size = 0;
	}

	bool empty(){	
		return size == 0;
	}

	T front(){
		if(size == 0)
			throws runtime_exception ("Queue is empty");
		
		return head->data;
	}

	void push(T value){
		Node * node = new Node(value);
		node->next = tail;
		tail = node;
		size++;
	}

	void pop(){
		if(size == 0)
			throws runtime_exception("You cannot erase from an empty queue");
		Node *temp = tail;
		else if(size == 1)
			head = tail = NULL;
		else {
			while(temp->next->next){
				temp = temp->next;
			}
			temp->next = NULL;
			head = tail;
		}
		size--;
	}

};