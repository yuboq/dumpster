// Copyright (c) 2015 Arista Networks, Inc.  All rights reserved.
// Arista Networks, Inc. Confidential and Proprietary.

#ifndef LIST_H
#define LIST_H

struct list {
   struct list *next;
   struct list *prev;
};

struct list *reverse(struct list *head);

#endif // LIST_H

