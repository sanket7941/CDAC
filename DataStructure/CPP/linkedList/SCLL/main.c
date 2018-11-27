#include<iostream>

using namespace std;

class node
{
private:
  int data;
  node *next;
public:
  node(int data)
  {
    this->data=data;
    this->next = NULL;
  }
  friend class list;
};

class list
{
private:
  node *head;
  int cnt;
public:
  // ctor
  list()
  {
    this-> head=NULL;
    this-> cnt=0;
  }
// functions on linked list
    int getNodeCount(void)
    {
      return this->cnt;
    }

    bool listIsEmpty(void)
    {
      return(this->head == NULL);
    }

    void addAtFirst(int data)
    {
        // creat a new node
        node *newnode = new node(data);
        if(listIsEmpty())
        {
          head = newnode;
          cnt++;
       }
       else
       {
         newnode->next = head;
         head = newnode;
         cnt++;
       }
    }
    void addAtLast(int data)
    {
        node *newnode = new node(data);

        if(listIsEmpty())
        {
          head = newnode;
          cnt++;
        }
        else
        {
          node *trav = head;
          while(trav->next!=NULL)
          {
            trav=trav->next;
          }
          trav->next = newnode;
          cnt++;
        }
    }

    void addAtSpecificPos(int data , int pos)
    {
      if(pos == 1 )
      addAtFirst(data);
      else if( pos == this->cnt+1)
          addAtLast(data);
      else
      {
        node *newnode =new node(data);
        node *trav = head;
        int i =1;
        while(i < pos-1 )
        {
          i++;
          trav = trav->next;
        }
        newnode->next = trav->next;
        trav->next = newnode;
        cnt++;

      }
    }

    void deleteAtFirst(void)
    {
      // chk if list is not listIsEmpty
      if(!listIsEmpty())
      {
        if(head->next == NULL)
        {
          delete head;
          head = NULL;
          cnt = 0;
        }
        else
        {
          node *temp = head;
          head = head->next;

          delete temp;
          temp = NULL;
          cnt--;
        }
      }
      else
      { cout << "list is empty !!!"<<endl; }

    }

    void deleteAtLast(void)
    {
      if(!listIsEmpty())
      {
        if(head->next == NULL)
        {
          delete head;
          head = NULL;
          cnt = 0;
        }
        else
        {
          node *trav = head;
          node *temp = head;

          while(trav->next != NULL)
          {
            temp = trav;
            trav = trav->next;
          }
          delete trav;
          temp->next = NULL;
          cnt--;
        }
      }
      else
      { cout << "list is empty !!!"<<endl; }
    }

    void deleteAtSpecificPos(int pos)
    {
      if(pos == 1)
      { deleteAtFirst();}
      else if(pos == cnt)
      { deleteAtLast(); }
      else
      {
        node *trav = head;
        int i =1 ;
        while(i < pos-1)
        {
          i++;
          trav=trav->next;
        }

      }


    }

void displayList(void)
{
  if( !listIsEmpty())
  {
    node *trav = head;
    //cout << "no. of nodes in a list are: " << count_nodes() << endl;
    cout << "no. of nodes in a list are: " << getNodeCount() << endl;
    cout << "list is: ";
    while( trav != NULL )
    {
      cout << trav->data << "->";
      trav = trav->next;
    }
    cout << " NULL " << endl;

  }
  else
    cout << "list is empty !!!" << endl;
  }

  void searchnode(int key)
  {
    node *trav = head;
    bool flag;
    while(trav != NULL)
    {
        if(trav->data == key)
        { flag = true;
          break;}
        trav=trav->next;
    }
    if (flag==true)
    { cout<<"key found"<<endl;}
    else
    {  cout<<"key not found"<<endl;  }

  }
};

 int main()
  {
    list l1;
    l1.displayList();
    l1.addAtFirst(10);
    l1.addAtLast(20);
    l1.addAtLast(30);
    l1.addAtLast(40);
    l1.addAtLast(50);
    l1.addAtLast(60);

    l1.addAtSpecificPos(55,6);
    cout<<"--------------------------------"<<endl;
    l1.displayList();
    cout<<"--------------------------------"<<endl;
    cout<<"delete at first"<<endl;
    l1.deleteAtFirst();
    cout << "deleteAtLast" << '\n';
    l1.deleteAtLast();
    cout<<"--------------------------------"<<endl;
    l1.displayList();
    cout<<"--------------------------------"<<endl;
    l1.searchnode(56);
    return 0;
  }
