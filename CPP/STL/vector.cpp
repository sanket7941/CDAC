/*Certain functions associated with the vector are:
Iterators

begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/
// C++ program to illustrate the
// iterators in vector
#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<iterator>
#include<algorithm>

int main()
{
	vector<int> v;
for(int i ;i<10;i++)
  v.push_back(i);

  vector<int>::iterator x;

  for(x=v.begin();x!=v.end();x++)
  {
    cout<<"value at X="<<*x<<endl;
  }

  cout<<"size ="<<v.max_size()<<endl;
  cout<<"capacity  ="<<v.capacity()<<endl;

  cout<<"front"<<v.front()<<endl;
  cout<<"end"<<v.back()<<endl;
	return 0;
}
