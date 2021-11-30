# Circle_Linkedlist

Danh sách liên kết vòng bao gồm các chức năng như:
//Common function
	bool is_empty(Cir_list l);
	void init(Cir_list& l);
	void display_list(Cir_list l);
	Cir_node* sentinel_linear_search(Cir_list l, int key);
	int count_elements(Cir_list l);
	void swap_var(int& a, int& b);
	void read_from_file(Cir_list& l, string file_path);
	void demonstration();

//Add function
	void add_head(Cir_list& l, int data);
	void add_tail(Cir_list& l, int data);
	void add_before(Cir_list& l, int key, int data);
	void add_after(Cir_list& l, int key, int data);
	void add_at(Cir_list& l, int pos, int data);
	void add_ascending(Cir_list& l, int data);

//Remove function
	void remove_head(Cir_list& l);
	void remove_value(Cir_list& l, int value);
	void remove_index(Cir_list& l, int index);
	void remove_all(Cir_list& l);
	void remove_dup(Cir_list& l);
	void remove_before(Cir_list& l, int value);
	void remove_after(Cir_list& l, int value);
	void remove_bigger(Cir_list& l, int value);
	void remove_smaller(Cir_list& l, int value);