#include<iostream>

using namespace std;

#define SIZE 5
class Queue
{
private:
  int arr[SIZE];
  int front,rear;
public:
  Queue()
  {
    this->front=-1;
    this->rear=-1;
  }
  bool Qempty()
  {
    return (rear==-1 && front==-1);
  }

  bool Qfull()
  {
    return(front==(rear+1)%SIZE);
  }

  void QInsert(int data)
  {
    rear = (rear+1)%SIZE;
    arr[rear]=data;
    if(front == -1)
      front=0;
  }

  void QDel(void)
  {
    if(front==rear)
    {     front = rear = -1 ;       }
    else
    {      front=(front=1)%SIZE;    }
  }

  void QDisplay()
  {
    if(front==-1 && rear==-1)
    {
      cout<<"queue is empty"<<endl;
    }
    else
    {
      for(int i =front;i<=rear;i++)
      {
        cout<<arr[i]<<"\t";
      }
    }
  }

};// end of class Q

int main()
{
  Queue q;
  q.QInsert(10);
  q.QInsert(20);
  q.QInsert(30);
  q.QInsert(40);
  q.QInsert(50);
  q.QInsert(60);
  q.QDisplay();


return 0;
}
