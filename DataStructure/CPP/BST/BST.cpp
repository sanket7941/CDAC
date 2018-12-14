#include <iostream>

using namespace std;

class node
{
private:
  int data;
  node *left;
  node *right;

  /*
      ||  *left | data | *right||
 */
public:
  node(int data)
  {
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
  friend class BTree;
};

class BTree
{
private:
  node *root;

public:
// CTor
  BTree()
  {
    this->root=NULL;
  }

  bool BSTempty()
  {
    return (root == NULL);
  }

  void BSTadd(int data)
  {
    node *newnode = new node(data);

    if(BSTempty() )
    {
      root = newnode;

    }
    else
    {
      node * trav = root;

      while(1)
      {
        if(data < trav->data )
        {
          if(trav->left==NULL )
          {
            trav->left= newnode;
            break;
          }
          else
          {
            trav = trav->left;
          }
        }
        else // if(data >= trav->data )
        {


            if(trav->right==NULL )
            {
              trav->right= newnode;
              break;
            }
            else
            {
              trav = trav->right;
            }

        }
      }//end of while loop

    }// end of else

  }// end of BST add


};//end of class BTree
