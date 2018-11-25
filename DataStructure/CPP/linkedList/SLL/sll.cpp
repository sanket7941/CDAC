/*
 * main.cpp
 *
 *  Created on: 24-Nov-2018
 *      Author: sachin
 */

//implentation of singly linear linked list and operations:
#include<stdlib.h>
#include<iostream>
#include<iomanip>

using namespace std;

//forward declaration
class list;

class node
{
private:
	int data;//data part -- 4 bytes
	node *next;//pointer part -- 4 bytes --> referential pointer
public:
	node(int data)
	{
		this->data = data;
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
	list()
	{
		this->head = NULL;
		this->cnt = 0;
	}

	int get_node_count(void)
	{
		return this->cnt;
	}

	bool is_list_empty(void)
	{
		return ( this->head == NULL );
	}

	void add_at_last(int data)
	{
		//create a newnode
		node *newnode = new node(data);
		//if list is empty
		if( is_list_empty() )
		{
			//attach newly created node to the head i.e. store the addr of
			//newly created node into the head pointer
			head = newnode;
			cnt++;
		}
		else//if list is not empty
		{
			//traverse the list till last node
			node *trav = head;
			while( trav->next != NULL )
			{
				trav = trav->next;
			}
			//attach newly created node to the last node i.e. store addr of
			//newly created node into the next part of last node
			trav->next = newnode;
			cnt++;
		}
	}

	void add_at_first(int data)
	{
		//create a newnode
		node *newnode = new node(data);
		//if list is empty
		if( is_list_empty() )
		{
			//attach newly created node to the head i.e. store the addr of
			//newly created node into the head pointer
			head = newnode;
			cnt++;
		}
		else//if list is not empty
		{
			//store the addr of cur first node into the newly created node
			newnode->next = head;
			//attach newly created node to the head
			head = newnode;
			cnt++;
		}
	}

	void add_at_specific_position(int data, int pos)
	{
		if( pos == 1 )
			add_at_first(data);
		else
		if( pos == this->cnt+1 )
			add_at_last(data);
		else
		{
			//create a newnode
			node *newnode = new node(data);

			//traverse the list till (pos-1)th node
			node *trav = head;
			int i = 1;
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}
			//store the addr of cur (pos)th node into the next part of newly created
			//node
			newnode->next = trav->next;
			//store the addr of newly created node into the next part of (pos-1)th node
			trav->next = newnode;
			cnt++;
		}
	}

	void delete_at_first(void)
	{
		//check list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head->next == NULL )
			{
				//delete the node and make head as NULL and cnt as 0
				delete head;
				head = NULL;
				cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of first into the temp pointer variable
				node *temp = head;
				//store the addr of cur second node into the head
				head = head->next;
				//delete the node
				delete temp;
				temp = NULL;
				cnt--;
			}

		}
		else
			cout << "list is empty !!!" << endl;
	}

	void delete_at_last(void)
	{
		//check list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head->next == NULL )
			{
				//delete the node and make head as NULL and cnt as 0
				delete head;
				head = NULL;
				cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//traverse the list till second last node
				node *trav = head;
				node *temp = NULL;

				while( trav->next != NULL )
				{
					temp = trav;
					trav = trav->next;
				}
				//delete cur last node
				delete trav;
				temp->next = NULL;
				cnt--;
			}

		}
		else
			cout << "list is empty !!!" << endl;
	}

	/*
	void delete_at_last(void)
	{
		//check list is not empty
		if( !is_list_empty())
		{
			//if list contains only one node
			if( head->next == NULL )
			{
				//delete the node and make head as NULL and cnt as 0
				delete head;
				head = NULL;
				cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//traverse the list till second last node
				node *trav = head;
				while( trav->next->next != NULL )
					trav = trav->next;
				//delete cur last node
				delete trav->next;
				trav->next = NULL;
				cnt--;
			}

		}
		else
			cout << "list is empty !!!" << endl;
	}
*/
	int count_nodes(void)
	{
		node *trav = head;
		int cnt = 0;
		while( trav != NULL )
		{
			cnt++;
			trav = trav->next;
		}
		return cnt;
	}

	void display_list(void)
	{
		if( !is_list_empty())
		{
			node *trav = head;
			//cout << "no. of nodes in a list are: " << count_nodes() << endl;
			cout << "no. of nodes in a list are: " << get_node_count() << endl;
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

	void delete_at_specific_position(int pos)
	{
		if( pos == 1 )
			delete_at_first();
		else
		if( pos == cnt )
			delete_at_last();
		else
		{
			//traverse list till (pos-1)th node
			node *trav = head;
			int i = 1;
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}
			//store the addr of node to be delete in a temp
			node *temp = trav->next;
			//store the addr of (pos+1)th node into the next part of (pos-1)th node
			trav->next = temp->next;
			delete temp;
			temp = NULL;
			cnt--;
		}
	}

	node *search_node(int key, node **parent)
	{
		node *trav = head;

		while( trav != NULL )
		{
			if( trav->data == key )
				return trav;

			*parent = trav;
			trav = trav->next;
		}
		*parent = NULL;
		return NULL;
	}

	bool search_and_delete(int key)
	{
		node *parent = NULL;
		node* temp = search_node(key, &parent);

		if( temp == NULL )
			return false;

		cout << "temp->data: " << temp->data << endl;

		if( parent != NULL )
		{
			cout << "parent->data: " << parent->data << endl;
			parent->next = temp->next;
			delete temp;
			cnt--;
		}
		else
		{
			delete_at_first();
		}
		return true;
	}

	void display_reverse(node *trav)
	{
		if( trav == NULL )
			return;

		display_reverse(trav->next);
		cout << setw(4) << trav->data;
	}

	void display_reverse(void)
	{
		if( !is_list_empty())
		{
			cout << "list in a reverse order is : ";
			display_reverse(head);
			cout << endl;
		}
		else
			cout << "list is empty !!!" << endl;
	}

	void reverse_list(void)
	{
		node *t1 = head;
		node *t2 = t1->next, *t3 = NULL;
		t1->next = NULL;

		while( t2 != NULL )
		{
			t3 = t2->next;
			t2->next = t1;
			t1 = t2;
			t2 = t3;
		}
		head = t1;
	}

	void free_list(void)
	{
		while( !is_list_empty())
			delete_at_last();
			//delete_at_first();
	}

	~list()
	{
		if( !is_list_empty())
		{
			free_list();
			cout << "all heap memory freed successfully...." << endl;
		}
		else
			cout << "list is empty !!!" << endl;
	}

};

int main(void)
{
	list l1;

	l1.add_at_last(10);
	l1.add_at_last(20);
	l1.add_at_last(30);
	l1.add_at_last(40);
	l1.add_at_last(50);
	/*
	l1.add_at_first(11);
	l1.add_at_first(22);
	l1.add_at_first(33);
	l1.add_at_first(44);
	l1.add_at_first(55);
	*/
	l1.display_list();

	/*
	int pos;

	while(1)
	{
		cout << "enter the position: ";
		cin >> pos;
		if( pos > 0 && pos <= l1.get_node_count() + 1 )
			break;
		else
			cout << "invalid position..." << endl;
	}

	l1.add_at_specific_position(45, pos);
	*/

	/*
	int pos;

	while(1)
	{
		cout << "enter the position: ";
		cin >> pos;
		if( pos > 0 && pos <= l1.get_node_count())
			break;
		else
			cout << "invalid position..." << endl;
	}

	l1.delete_at_specific_position(pos);
	*/
	/*
	int key;
	cout << "enter the key: ";
	cin >> key;

	if( l1.search_and_delete(key) )
		cout << "node deleted successfully... " << endl;
	else
		cout << "node does not exists !!!" << endl;
		*/


	//l1.display_reverse();

	l1.reverse_list();

	l1.display_list();


	return 0;
}










