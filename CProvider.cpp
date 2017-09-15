#include <iostream>
#include "CProvider.h"
#include "CDate.h"
#include <iostream>
using namespace std;

CProvider::CProvider()
: CPerson()
{
    CDate cd;
    m_deadline = cd;
}
CProvider::CProvider(string fn, string ln, string address, string phN, CDate deadline)
:CPerson(fn, ln, address, phN)
{
    m_deadline = deadline;
}
void CProvider::Read()
{
    cout<<"\n       PROVIDER DATA\n"<<endl;
    CPerson::Read();
    CDate cd;
    cout<<"Delivery Date  :  ";
    cd.Read();
    m_deadline = cd;
}
void CProvider::Print()
{
    cout<<"\n\n     PROVIDER DATA\n"<<endl;
    CPerson::Print();
    cout<<"Delivery Date    :  ";
    m_deadline.Print();
}
CProvider::~CProvider()
{
    //dtor
}
