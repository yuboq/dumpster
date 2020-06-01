#include <iostream>

struct Node {
  Node (int x) : val(x), next = nullptr, prev = nullptr{}
  int val;
  Node *next;
  Node *prev;
}

int main(){
  return 0;
}
