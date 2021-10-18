struct menu * make_menu(char* food, double price, int amount, struct menu* next);
void print_menu(struct menu *s);
void print_list(struct menu* n);
struct menu * insert_front(struct menu * current, char* new_f, double new_p, int new_a);
struct menu * free_list(struct menu * current);
struct menu * remove_node(struct menu * current, int amount);
