#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "work10.h"

int main() {
   srand(time(NULL));
   
   struct menu *list = NULL;
   
   char * f1 = "banana";
   double p1 = rand() / 100000000.0;
   int a1 = rand() / 100000000;
   list = insert_front(list, f1, p1, a1);
   
   char * f2 = "apple";
   double p2 = rand() / 100000000.0;
   int a2 = rand() / 100000000;
   list = insert_front(list, f2, p2, a2);
   
   char * f3 = "pear";
   double p3 = rand() / 100000000.0;
   int a3 = rand() / 100000000;
   list = insert_front(list, f3, p3, a3);
   
   print_list(list);
   remove_node(list, a2);
   print_list(list);
   //list = free_list(list);
   //print_list(list);
   
   return 0;
}
