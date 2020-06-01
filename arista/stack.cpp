//implement a stack using LL
//stack: top(), pop(), size(), push()

#include <iostream>
struct Node 
{
  Node (int x) : val (x), next(nullptr) {}
  Node ():Node (0){}
  int val;
  Node *next;
};

class Stack
{
  public:
    Stack (): head (nullptr), size (0) {}

    void push(Node * n){
      n -> next = head;
      head = n;
      size++;
    }

    Node * top(){
      return head;
    }

  private:
    Node * head;
    int size;
};

int main()
{
  Stack s;
  Node * n1= new Node(1);
  Node * n2= new Node(2);
  Node * n3= new Node(3);
  s.push (n1);
  std::cout << s.top()->val << " ";
  s.push (n2);
  std::cout << s.top()->val << " ";
  s.push (n3);
  std::cout << s.top()->val << " ";
  Node * n = nullptr;
  n->val;
}
