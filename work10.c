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

struct menu * make_menu(char* food, double price, int amount) {
	struct menu *n;
	n = malloc(sizeof(struct menu));

	strncpy(n->food, food, 100);
	n->price = price;
   n->amount = amount;

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
   struct menu * new = make_menu(new_f, new_p, new_a);
   new->next = current;
   return new;
}

struct menu * free_list(struct menu * l) {
   struct menu * temp = l;
   while(l) {
   	l = l->next;
   	free(temp);
   	temp = l;
	}
	return l;
}

struct menu * remove_node(struct menu * current, int amount) {
   struct menu * front = current;
   struct menu * temp;
   if (current->amount == amount) {
      temp = current->next;
      free(current);
      return temp;
   }
	while (current) {
      if (current->amount == amount) {
         temp->next = current->next;
         free(current);
      }
      temp = current;
      current = current->next;
   }
   //From class:
   //temp = curr->next
   //curr->next = temp->next
   //free(temp)
   return front;
}
