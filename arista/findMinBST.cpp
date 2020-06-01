#include <iostream>

//find min, find next

Node * findMin(Node *root)
{
  while (root -> left != NULL)
  {
    root = root->left;
  }
  return root;
}

//find next

Node * findNext(Node * root)
{
  //assume you have parent node
  if (root -> right){return findMin (root->right);}
  if (root -> parent){return root->parent;}
  return root;
  /*
  if (root -> val <= root -> parent ->val){//on the left
    return (root->right)?root->right : root -> parent;
  }
  else if (root -> val > root->parent -> val){//on the right
    Node *temp = findMin (root);
    if (temp != root) return temp;
    if (root -> parent -> parent) return root -> parent->parent;
    return root->parent;
    */

  }

//write printBST in order depth first search
void printBST (Node *root){
  if (root -> left) printBST (root-> left);
  if (root->right) printBST (root -> right);
  print (root);

}
