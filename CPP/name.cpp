#include"iostream"
using namespace std;

namespace boys
{
  int a=1,b=2,c=3,d=4;
}

namespace girls
{
  namespace fools
  {
    int a=11,b=22,c=33,d=44;
  }
  namespace wierd
  {
    int a=111,b=222,c=333,d=444;
  }
}
int main()
{
  using namespace boys;
  cout<< "the a"<<a<<'\n';

  using namespace girls;
  cout << " type 2 "<< girls::fools::b<<'\n';

  using namespace wierd;
  cout << " type 3 "<< wierd::b<<'\n';

 return 0;
}
