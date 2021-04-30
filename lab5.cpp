//Text strings and dynamic arrays

#include <iostream>
#include <string>

using namespace std;


//encodes and decodes the string
void cencode(unsigned char* c, int seed, bool code)
{
    while(*c)
    {
        if(code) *c+=seed;
        else *c-=seed;
        c++;
    }
}

int main()
{
    cout<<"Enter the size of the input string"<<endl;
    int size=-1;
    cin>>size;
    unsigned char* str=new unsigned char[size];
    cout<<"Enter the string"<<endl;
    cin>>str;

    cout<<"Enter a number to add to each character"<<endl;
    cin>>size;
    cout<<"Encoded string"<<endl;
    cencode(str,size,true);
    cout<<str<<endl;
    cout<<"Decoded string"<<endl;
    cencode(str,size,false);
    cout<<str<<endl;

    delete[] str;
    return 0;
}
