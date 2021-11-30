#include"Circular_LinkedList.h"

void Circular::demonstration()
{
	Cir_list l;
	int choice;

	//Initialize list (p_head = nullptr)
	Circular::init(l);

	cout << "----------Circular linked list---------\n";
	cout << "Choose the way to get input:\n1.Keyboard    2.Text file\n";
	cout << "Choice: "; cin >> choice;

	//Get input (from text file or keyboard)
	if (choice == 1)
	{
		int data;

		cout << "\nThe number of elements in list: ";
		cin >> choice;

		for (int i = 0; i < choice; i++)
		{
			cout << "\nData of node " << i << " = ";
			cin >> data;
			Circular::add_tail(l, data);
		}
	}
	else if (choice == 2)
	{
		string file_path;

		cin.ignore();
		cout << "\nFile path: ";
		getline(cin, file_path);

		Circular::read_from_file(l, file_path);
	}

	system("pause");
	system("cls");
	Circular::display_list(l);
	cout << "Total of elements of list: " << count_elements(l) <<"\n";

	//Remove all
	cout << "\n- After remove all of node in list: ";
	Circular::remove_all(l);
	
	//Check empty
	if (Circular::is_empty(l)) {
		cout << "\nList is empty!\n";
	}

	//Add head
	cout << "\n- After add 100 to head of list: ";
	Circular::add_head(l, 100);
	Circular::display_list(l);

	//Add tail
	cout << "\n- After add 200 then 280 to tail of list: ";
	Circular::add_tail(l, 200);
	Circular::add_tail(l, 280);
	Circular::display_list(l);

	//Add tail
	cout << "\n- After add 300 before the first node which have data = 100: ";
	Circular::add_before(l, 100, 300);
	Circular::display_list(l);

	//Add after
	cout << "\n- After add 100 after the first node which have data = 200: ";
	Circular::add_after(l, 200, 100);
	Circular::display_list(l);

	//Remove duplicated node
	cout << "\n- After remove all of duplicated node in list: ";
	Circular::remove_dup(l);
	Circular::display_list(l);

	//Add at index
	cout << "\n- After add 50 to node which have index = 0 in list: ";
	Circular::add_at(l, 0, 50);
	Circular::display_list(l);

	//Add ascending(list must be sorted in ascending order)
	cout << "\n- After add 15, 75, 210, 150 to list in ascending order(list must be sorted in ascending order): ";
	Circular::add_ascending(l, 15);
	Circular::add_ascending(l, 75);
	Circular::add_ascending(l, 210);
	Circular::add_ascending(l, 150);
	Circular::display_list(l);

	//Remove head
	cout << "\n- After remove head: ";
	Circular::remove_head(l);
	Circular::display_list(l);

	////Remove tail
	//cout << "\n- After remove tail: ";
	//Circular::remove_tail(l);
	//Circular::display_list(l);

	//Remove value
	cout << "\n- After remove value 75 from list: ";
	Circular::remove_value(l, 75);
	Circular::display_list(l);

	//Remove index
	cout << "\n- After remove node which have index = 2 from list: ";
	Circular::remove_index(l, 2);
	Circular::display_list(l);


	//Remove before
	cout << "\n- After remove node before value 200 from list: ";
	Circular::remove_before(l, 200);
	Circular::display_list(l);

	//Remove after
	cout << "\n- After remove node after value 50 from list: ";
	Circular::remove_after(l, 50);
	Circular::display_list(l);

	//Remove bigger value
	cout << "\n- After remove node which have value is bigger than 200 from list: ";
	Circular::remove_bigger(l, 210);
	Circular::display_list(l);

	//Remove smaller value
	cout << "\n- After remove node which have value is bigger than 200 from list: ";
	Circular::remove_smaller(l, 210);
	Circular::display_list(l);
}

void Circular::swap_var(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool Circular::is_empty(Cir_list l)
{
	if (l.p_head == nullptr) {
		return true;
	}
	return false;
}

void Circular::init(Cir_list& l)
{
	l.p_head = nullptr;
}

void Circular::display_list(Cir_list l)
{
	if (!Circular::is_empty(l))
	{
		cout << "\nContent of list: ";
		Cir_node* temp = l.p_head;
		do {
			cout << temp->data << "  ";
			temp = temp->p_next;
		} while (temp != l.p_head);
		cout << "\n";
	}
	else
	{
		cout << "\nList is empty!\n";
	}
}

Cir_node* Circular::sentinel_linear_search(Cir_list l, int key)
{
	if (l.p_head->data == key)
	{
		return l.p_head;
	}

	Cir_node* temp = l.p_head->p_next;
	int head_data = l.p_head->data;
	l.p_head->data = key;
	
	while (temp->data != key)
	{
		temp = temp->p_next;
	}
	
	//Update head value
	l.p_head->data = head_data;

	if (temp == l.p_head) {
		return nullptr;
	}
	else {
		return temp;
	}
}

int Circular::count_elements(Cir_list l)
{
	if (Circular::is_empty(l))
	{
		return 0;
	}

	int count = 1;

	for (Cir_node* temp = l.p_head->p_next; temp != l.p_head; temp = temp->p_next)
	{
		count++;
	}

	return count;
}

void Circular::read_from_file(Cir_list& l, string file_path)
{
	ifstream ifs(&file_path[0]);
	if (ifs.fail())
	{
		cout << "\nError: Cannot open file! Please check if file is exist ";
		cout << "and file path must not have any space";
		exit(1);
	}

	vector<int>input;
	int temp;

	while (!ifs.eof())
	{
		ifs >> temp;
		input.push_back(temp);
	}

	ifs.close();
	for (size_t iv = 0; iv < input.size(); iv++)
	{
		Circular::add_tail(l, input.at(iv));
	}
}

void Circular::add_head(Cir_list& l, int data)
{
	//Create new node
	Cir_node* new_node = new Cir_node();
	new_node->data = data;

	//if list is empty
	if (Circular::is_empty(l))
	{
		l.p_head = new_node;
		new_node->p_next = l.p_head;
		new_node->p_prev = l.p_head;
	}
	else
	{
		//Insert new node before head node
		new_node->p_prev = l.p_head->p_prev;
		new_node->p_next = l.p_head;
		(l.p_head->p_prev)->p_next = new_node;
		l.p_head->p_prev = new_node;

		//Update head
		l.p_head = new_node;
	}
}

void Circular::add_tail(Cir_list& l, int data)
{
	Cir_node* new_node = new Cir_node();
	new_node->data = data;

	if (Circular::is_empty(l))
	{
		l.p_head = new_node;
		new_node->p_next = l.p_head;
		new_node->p_prev = l.p_head;
	}
	else
	{
		l.p_head->p_prev->p_next = new_node;
		new_node->p_prev = l.p_head->p_prev;
		new_node->p_next = l.p_head;
		l.p_head->p_prev = new_node;
	}
}

void Circular::add_before(Cir_list& l, int key, int data)
{
	//Is list empty?
	if (Circular::is_empty(l)) {
		cout << "\nList is empty!\n";
		return;
	}

	//Find key node
	Cir_node* key_node = Circular::sentinel_linear_search(l, key);

	if (key_node == nullptr)
	{
		return;
	}
	else
	{
		//Create new node
		Cir_node* new_node = new Cir_node();
		new_node->data = data;

		//Insert new node before key node
		new_node->p_prev = key_node->p_prev;
		new_node->p_next = key_node;
		(key_node->p_prev)->p_next = new_node;
		key_node->p_prev = new_node;

		if (key_node == l.p_head)
		{
			l.p_head = key_node->p_prev;
		}
	}
}

void Circular::add_after(Cir_list& l, int key, int data)
{
	//Is list empty?
	if (Circular::is_empty(l)) {
		cout << "\nList is empty!\n";
		return;
	}

	//Find key node
	Cir_node* key_node = Circular::sentinel_linear_search(l, key);

	if (key_node == nullptr)
	{
		return;
	}
	else
	{
		//Create new node
		Cir_node* new_node = new Cir_node();
		new_node->data = data;

		//Insert new node before key node
		new_node->p_next = key_node->p_next;
		new_node->p_prev = key_node;
		(key_node->p_next)->p_prev = new_node;
		key_node->p_next = new_node;
	}
}

void Circular::add_at(Cir_list& l, int pos, int data)
{
	//Is list empty?
	if (Circular::is_empty(l))
	{
		cout << "\nError: List is empty!\n";
		return;
	}

	if (pos < 0)
	{
		cout << "\nError: position(user_input) is negative\n";
		return;
	}

	if (pos == 0)
	{
		l.p_head->data = data;
		return;
	}

	Cir_node* node_at_pos = l.p_head->p_next;
	for (; node_at_pos != l.p_head; pos--)
	{
		if (pos == 1)
		{
			node_at_pos->data = data;
			return;
		}
		node_at_pos = node_at_pos->p_next;
	}
	cout << "\nError: The number of node in list is less than position(user_input)\n";
}

void Circular::add_ascending(Cir_list& l, int data)
{
	//Is list empty?
	if (Circular::is_empty(l))
	{
		cout << "\nList is empty!\n";
		return;
	}

	Cir_node* new_node = new Cir_node();
	new_node->data = data;

	if (l.p_head->data >= data || l.p_head->p_prev->data <= data)
	{
		l.p_head->p_prev->p_next = new_node;
		new_node->p_prev = l.p_head->p_prev;
		new_node->p_next = l.p_head;
		l.p_head->p_prev = new_node;

		if (l.p_head->data >= data)
		{
			l.p_head = new_node;
		}
	}
	else
	{
		for (Cir_node* temp = l.p_head->p_next; temp != l.p_head; temp = temp->p_next)
		{
			if (temp->data >= data)
			{
				temp->p_prev->p_next = new_node;
				new_node->p_prev = temp->p_prev;
				new_node->p_next = temp;
				temp->p_prev = new_node;
				return;
			}
		}
	}
}

void Circular::remove_head(Cir_list& l)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty.\n";
		return;
	}

	if (l.p_head->p_next == l.p_head)
	{
		l.p_head = nullptr;
		cout << "\n List has just one node. After remove, list is empty.\n";
	}
	else
	{
		Cir_node* temp = l.p_head->p_prev;

		temp->p_next = l.p_head->p_next;
		l.p_head->p_next->p_prev = temp;

		delete(l.p_head);

		temp = temp->p_next;
		l.p_head = temp;
	}
}

void Circular::remove_value(Cir_list& l, int value)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty.\n";
		return;
	}
	else
	{
		if (value == l.p_head->data)
		{
			Circular::remove_head(l);
		}
		else
		{
			Cir_node* temp = l.p_head->p_next;
			Cir_node* prev = l.p_head->p_next->p_prev;

			do
			{
				if (value == temp->data)
				{
					prev->p_next = temp->p_next;

					delete(temp);

					temp = prev->p_next;
					temp->p_prev = prev;
				}
				else
				{
					temp = temp->p_next;
					prev = prev->p_next;
				}
			} while (temp != l.p_head);
		}
	}
}

void Circular::remove_index(Cir_list& l, int index)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty.\n";
		return;
	}

	if (index < 0)
	{
		cout << "\nError: index(user_input) is negative\n";
		return;
	}

	if (index == 0)
	{
		Circular::remove_head(l);
		return;
	}
	else
	{
		int count = 1;
		Cir_node* temp = l.p_head->p_next;
		Cir_node* prev = l.p_head;

		for (; temp != l.p_head; count++)
		{
			if (count == index)
			{
				prev->p_next = temp->p_next;

				delete(temp);
				return;
			}
			else
			{
				temp = temp->p_next;
				prev = prev->p_next;
			}
		}

		if (count < index)
		{
			cout << "\n Error: List hasn't enough node.\n";
			return;
		}
	}
}

void Circular::remove_dup(Cir_list& l)
{
	if (Circular::is_empty(l))
	{
		cout << "\nList is empty!\n";
		return;
	}

	if (l.p_head->p_next == l.p_head)
	{
		return;
	}

	Cir_node* cur = l.p_head;
	do
	{
		for (Cir_node* temp = cur->p_next; temp != l.p_head;)
		{
			if (cur->data == temp->data)
			{
				Cir_node* up_temp = temp->p_next;
				temp->p_prev->p_next = temp->p_next;
				temp->p_next->p_prev = temp->p_prev;

				delete temp;
				temp = up_temp;
			}
			else
			{
				temp = temp->p_next;
			}
		}
		cur = cur->p_next;
	} while (cur != l.p_head);
}

void Circular::remove_before(Cir_list& l, int value)
{
	if (Circular::is_empty(l)) {
		cout << "\nList is empty\n";
		return;
	}

	if (l.p_head->p_next == l.p_head)
	{
		return;
	}

	Cir_node* cur = l.p_head->p_next;
	Cir_node* prev;
	while (cur != l.p_head)
	{
		if (cur->data == value)
		{
			prev = cur->p_prev;
			prev->p_prev->p_next = cur;
			cur->p_prev = prev->p_prev;

			delete prev;
			prev = nullptr;
		}
		cur = cur->p_next;
	}
}

void Circular::remove_after(Cir_list& l, int value)
{
	if (Circular::is_empty(l)) {
		cout << "\nList is empty\n";
		return;
	}

	if (l.p_head->p_next == l.p_head)
	{
		return;
	}

	Cir_node* cur = l.p_head;
	do
	{
		if (cur->data == value)
		{
			Cir_node* next = cur->p_next;
			cur->p_next = next->p_next;
			next->p_next->p_prev = cur;

			delete next;
			next = nullptr;
		}
		cur = cur->p_next;
	} while (cur != l.p_head);
}

void Circular::remove_all(Cir_list& l)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty!\n";
		return;
	}

	Cir_node* temp = l.p_head->p_next;
	Cir_node* prev = l.p_head;

	for(; temp != l.p_head;)
	{
		prev->p_next = temp->p_next;
		temp->p_next->p_prev = prev;

		delete(temp);
		temp = prev->p_next;
	}

	delete l.p_head;
	l.p_head = nullptr;
}

void Circular::remove_smaller(Cir_list& l, int value)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty.\n";
		return;
	}

	if (l.p_head->data < value)
	{
		do
		{
			Circular::remove_head(l);
		} while (l.p_head->data < value);
	}

	Cir_node* temp = l.p_head;
	Cir_node* prev = l.p_head->p_prev;

	do
	{
		if (temp->data < value)
		{
			prev->p_next = temp->p_next;
			temp->p_next->p_prev = prev;

			delete(temp);

			temp = prev->p_next;

		}
		else
		{
			temp = temp->p_next;
			prev = prev->p_next;
		}
	} while (temp != l.p_head);
}

void Circular::remove_bigger(Cir_list& l, int value)
{
	if (Circular::is_empty(l)) {
		cout << "\n List is empty.\n";
		return;
	}

	if (l.p_head->data > value)
	{
		do
		{
			Circular::remove_head(l);
		} while (l.p_head->data > value);
	}

	Cir_node* temp = l.p_head;
	Cir_node* prev = l.p_head->p_prev;

	do
	{
		if (temp->data > value)
		{
			prev->p_next = temp->p_next;
			temp->p_next->p_prev = prev;

			delete(temp);

			temp = prev->p_next;

		}
		else
		{
			temp = temp->p_next;
			prev = prev->p_next;
		}
	} while (temp != l.p_head);
}