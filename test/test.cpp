#include <iostream>

struct Node {
  Node (int x) : val (x), next (nullptr){}
  int val;
  Node *next;
};

Node * makeLL( int x = 10){
  Node * head = new Node (0);
  Node * tmp = head;
  for (int i = 1; i < x; ++i)
  {
    Node *tmp2 = new Node (i);
    tmp -> next = tmp2;
    tmp = tmp2;
  }
  return head;
}

void deletehead (Node *head)
{
  *head = *head->next;
}
void deletehead2(Node *head)
{
  head = head ->next;
}
int main()
{

  Node * head = makeLL ();
  Node ** head2 = &head;
  deletehead2 (head);
  while (head != nullptr){
    std::cout << head -> val << " ";
    head = head -> next;
  }
}
