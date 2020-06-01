// Copyright (c) 2015 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#include <stdlib.h>

#include "list.h"

// COPIED FROM list.h FOR REFERENCE
// struct list {
//     struct list *next;
//     struct list *prev;
// };
//
// This is a doubly-linked list which is NULL terminated at either end.


// Write the reverse function which takes a list as defined above, reverses the
// list in place and then returns the new head of the list.
//
// Once that is done insert the call to your reverse() function where
// appropriate.


struct list * reverse (struct list * head)
{
  if (!head) return head;
  struct list * tmp = head->next;
  head -> next = head ->prev;
  head->prev = tmp;
  if (!(head -> prev)) return head;
  reverse (head -> prev);
}

