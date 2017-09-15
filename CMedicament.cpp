#include <iostream>
#include "CMedicament.h"
#include "CProvider.h"

using namespace std;

CMedicament::CMedicament()
: CProvider(), CManufacturer()
{
    CDate cd;
    m_medicamentName ="";
    m_expDate = cd;
    m_manDate = cd;
    m_medicNum = 0;
}
CMedicament::CMedicament(CProvider cProvider, CManufacturer cManuf,string name,int quantity, double price, int medN)
{
    SetMedicamentName(name);
    SetQuantity(quantity);
    SetPrice(price);
    m_cp = cProvider;
    m_cman = cManuf;
    SetDates();
}

void CMedicament::SetDates()
{
    CDate manD,expD;
    do
    {
        cout<<"Manuf. Date ";
        manD.Read();
        cout<<"Exp. Date   ";
        expD.Read();
    }
    while(manD.cmp(expD) != -1);
    SetManDate(manD);
    SetExpDate(expD);
}
bool CMedicament::SetMedicamentName(string mn)
{
    if(mn.find_first_of(" 0123456789.-+*()&^%$#@:;?!,<>/\\`'|{}[]~") != -1 || mn.size() <= 3) return false;
    m_medicamentName = mn;
    return true;
}

bool CMedicament::SetQuantity(int q)
{
    if(!(q > 0 && q < 500))
    {
        cout<<"\n QUANTITY MUST BE BETWEEN 0 AND 500!"<<endl;
        return false;
    }
    m_quantity = q;
    return true;
}

bool CMedicament::SetPrice(double p)
{
    if(!(p/m_quantity > 0.10 && p/m_quantity < 300))
    {
        cout<<"\n PRICE PER ONE MEDICAMENT MUST BE BETWEEN 0.10 AND 300!"<<endl;
        return false;
    }
    m_price = p;
    return true;
}

bool CMedicament::SetMedicamentNumber(int n)
{

    if(!(n > 99999 && n < 1000000))return false;
    m_medicNum = n;
    return true;
}
void CMedicament::Read(long choice)
{

    if(choice != 3)
    {
        CProvider cprov;
        cprov.Read();
        m_cp = cprov;
    }
        if(choice == 1)
        {
            CManufacturer cmanuf;
            cmanuf.Read();
            m_cman = cmanuf;
        }

        cout<<"\n       MEDICAMENT DATA\n"<<endl;
        string name;
        int quantity;
        double price;
        do
        {
            cout<<"Medicament Name   :  ";
            cin>>name;
        }
        while(!SetMedicamentName(name));

        do
        {
            cout<<"Quantity          :  ";
            cin>>quantity;
        }
        while(!SetQuantity(quantity));
        do
        {
            cout<<"Medicament Number :  ";
            cin>>quantity;
        }
        while(!SetMedicamentNumber(quantity));

        do
        {
            cout<<"Price             :  ";
            cin>>price;
        }
        while(!SetPrice(price));
        SetDates();
    }

    void CMedicament::Print()
    {

        cout<<"\n       MEDICAMENT DATA\n"<<endl;
        cout<<"Medicament Name    :  "<<m_medicamentName<<endl;
        cout<<"Quantity           :  "<<m_quantity<<endl;
        cout<<"Price              :  "<<m_price<<endl;
        cout<<"Medicament Number  :  "<<m_medicNum<<endl;
        cout<<"Manufacture Date   :  ";
        m_manDate.Print();
        cout<<"\nExpiration Date    :  ";
        m_expDate.Print();
        cout<<endl;
        m_cp.Print();
        m_cman.Print();
    }

    CMedicament::~CMedicament()
    {
    }
