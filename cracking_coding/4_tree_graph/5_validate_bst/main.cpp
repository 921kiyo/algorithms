#include <iostream>
using namespace std;

class Node{
private:
  int data;
  Node* right;
  Node* left;
public:
  Node(int d):data(d), right(nullptr), left(nullptr){}
  void insertRight(Node* r){right = r;}
  void insertLeft(Node* l){left = l;}
  Node* getRight(){return right;}
  Node* getLeft(){return left;}
  int getData(){return data;}
};

bool check_bst(Node* n, int min, int max){
  if(n == nullptr) return true;

  if((min != 0 && n->getData() <= min) || (max != 0 && n->getData() > max)){
    return false;
  }
  if(!check_bst(n->getLeft(), min, n->getData()) || !check_bst(n->getRight(), n->getData(), max)){
    return false;
  }
  return true;
}

int main(){
  Node root = Node(2);
  Node right = Node(3);
  Node left = Node(1);

  Node right2 = Node(2);
  Node left2 = Node(3);

  right2.insertLeft(&left2);
  right.insertRight(&right2);

  root.insertRight(&right);
  root.insertLeft(&left);

  cout << check_bst(&root, -2e9, 2e9) << endl;
  return 0;
}
