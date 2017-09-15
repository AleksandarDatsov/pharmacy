#include <iostream>
#include "CManufacturer.h"
#include "CPerson.h"
using namespace std;


CManufacturer::CManufacturer()
: CPerson()
{
    m_licenseNumber = 0;
}

CManufacturer::CManufacturer(string fn, string ln, string address, string phN)
            : CPerson(fn, ln, address, phN)
{
    SetlicenseNumber();
}

void CManufacturer::Read()
{
    cout<<"\n\n     MANUFACTURER DATA\n\n";
    CPerson::Read();
    SetlicenseNumber();
}
void CManufacturer::Print()
{
    cout<<"\n\n     MANUFACTURER DATA\n "<<endl;
    CPerson::Print();
    cout<<"License Number   :  "<<GetlicenseNumber()<<endl;
}

CManufacturer::~CManufacturer()
{
    //dtor
}
