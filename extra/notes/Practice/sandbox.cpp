#include <iostream>
using namespace std;
int main( )
{ typedef int my_2darray[1][1];
my_2darray b[3][2];
cout<<sizeof(b)<<endl; //24
cout<<sizeof(b+0)<<endl; //8
cout<<sizeof(*(b+0))<<endl; //8
// the next line prints 0012FF4C
cout<<"The address of b is: "<<b<<endl; //0
cout<<"The address of b+1 is: "<<b+1<<endl;
cout<<"*(b+1) is: "<<*(b+1)<<endl<<endl;
cout<<"The address of &b is: "<<&b<<endl;
cout<<"The address of &b+1 is: "<<&b+1<<endl<<endl;
return 0;
}
