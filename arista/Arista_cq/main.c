// Copyright (c) 2015 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "list.h"

struct element {
   struct list list;
   int value;
};

#define NUM 100

struct foo {
   int field1;
   char field2[10];
   struct element field3[NUM];
   int field4;
};

static void init_foo(struct foo *foo);

int main(int argn, char **args)
{
   struct foo *foo = NULL;
   struct element *newelement = NULL;
   struct element *last = NULL;
   struct list *newhead = NULL;

   int value = NUM - 1;

   foo = (struct foo *)malloc(sizeof(*foo));
   init_foo(foo);

   /*
    * INSERT YOUR CALL HERE
    *
    * The first element of the list is foo->field3[0]
    *
    * newhead = ...
    */
   //my code starts here
   newhead = reverse (&(foo -> field3[0].list));

   newelement = (struct element *)newhead;
   assert((char *)newelement > (char *)foo);
   assert((char *)newelement < (char *)(foo + sizeof(*foo)));
   while (newelement) {
     printf (" %i",newelement ->value );
      assert(newelement->value == value--);
      last = newelement;
      newelement = (struct element *)newelement->list.next;
   }
   assert(value == -1);
   newelement = last;
   value = 0;
   while (newelement) {
      assert(newelement->value == value++);
      last = newelement;
      newelement = (struct element *)newelement->list.prev;
   }
   assert(value == NUM);

   printf("Success!\n");

   free(foo);

   return 0;
}

static void init_foo(struct foo *foo) {
   foo->field1 = 68;
   memset(foo->field2, 0, sizeof(foo->field2));
   foo->field3[0].list.prev = NULL;
   foo->field3[NUM - 1].list.next = NULL;
   for (int i = 0; i < NUM; i++) {
      if (i != 0)
         foo->field3[i].list.prev = (struct list *)(foo->field3 + (i - 1));
      if (i != NUM - 1)
         foo->field3[i].list.next = (struct list *)(foo->field3 + (i + 1));
      foo->field3[i].value = i;
   }
   foo->field4 = 56087;
}

