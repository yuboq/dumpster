#include <iostream>
#include <vector>
#include <queue>
struct Node 
{
  Node (int x): left(NULL), right (NULL), val(x){}
  Node () : Node (0){}
  Node * left;
  Node * right;
  int val;
};

using pkg = std::pair <bool, int>;
class Solution
{
  public:
    static pkg isBalanced(Node *head)
    {
      if (!head) return (pkg (true, -1));

      pkg subTreeLeft, subTreeRight;
      subTreeLeft = isBalanced (head->left);
      subTreeRight=  isBalanced (head->right);

      if (!subTreeLeft.first || !subTreeRight.first) return(pkg (false, 0));

      if (abs (subTreeLeft.second - subTreeRight.second) >=2) return (pkg (false, 0));

      return (pkg (true, std::max(subTreeLeft.second ,subTreeRight.second) +1));
    }
};

void createTree (Node * head)
{
  head-> left = new Node (10);
  head -> left ->left = new Node (5);
  head -> left ->left ->left = new Node (1);

  head -> right = new Node (30);
  head -> right -> right = new Node (40);

}

void printTree (std::queue <Node *> myq){
  if (myq.empty()) {return;}
  std::queue <Node * > childq;
  while (!myq.empty())
  {
    Node * tmp = myq.front();
    myq.pop();
    std::cout << tmp -> val << " ";
    if (tmp->left) {childq.push (tmp->left);}
    if (tmp->right) {childq.push(tmp->right);}
  }
  std::cout <<std::endl;
  printTree (childq);
}


int main()
{
  Node * head = new Node(20);
  createTree (head);
  std::queue <Node *> myq;
  myq.push(head);
  printTree (myq);

  pkg mypkg = Solution::isBalanced (head);

  std::cout << mypkg.first <<std::endl;
  return 0;
}
