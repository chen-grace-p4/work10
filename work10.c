#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct menu {
   char food[100];
   double price;
   int amount;
   struct menu* next;
};

struct menu * make_menu(char* food, double price, int amount, struct menu* next);
void print_menu(struct menu *s);
void print_list(struct menu* n);
struct menu * insert_front(struct menu * current, char* new_f, double new_p, int new_a);
struct menu * free_list(struct menu * current);

int main() {
   srand(time(NULL));

   char * f1 = "banana";
   double p1 = rand() / 100000000.0;
   int a1 = rand() / 100000000;
   struct menu *test = make_menu(f1, p1, a1, NULL);

   char * f2 = "apple";
   double p2 = rand() / 100000000.0;
   int a2 = rand() / 100000000;
   //struct menu *test2 = make_menu(f2, p2, a2, test);
   struct menu *test2 = insert_front(test, f2, p2, a2);

   char * f3 = "pear";
   double p3 = rand() / 100000000.0;
   int a3 = rand() / 100000000;
   //struct menu *test3 = make_menu(f3, p3, a3, test2);
   struct menu *test3 = insert_front(test2, f3, p3, a3);

   print_list(test3);
   free_list(test3);
   //print_menu(free_list(test3));
   //free(test);
   //printf("Note: price and number of food is randomized. \n");

   return 0;
}

struct menu * make_menu(char* food, double price, int amount, struct menu* next) {
	struct menu *n;
	n = malloc(sizeof(struct menu));

	strncpy(n->food, food, 100);
	n->price = price;
   n->amount = amount;
   n->next = next;

	return n;
}

void print_menu(struct menu* s) {
   printf("food: '%s'\t price: $%.2lf\tnumber of food: %d \n", s->food, s->price, s->amount);
}

void print_list(struct menu* current) {
   while (current != NULL) {
      print_menu(current);
      current = current->next;
   }
}

struct menu * insert_front(struct menu * current, char* new_f, double new_p, int new_a) {
   struct menu * new = make_menu(new_f, new_p, new_a, current);
   return new;
}

struct menu * free_list(struct menu * current) {
   while (current != NULL) {
      free(current);
      current = current->next;
   }
   return current;
}
