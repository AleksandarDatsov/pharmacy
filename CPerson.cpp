#include "CPerson.h"
#include <cstring>
#include <string>
#include <iostream>

#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

CPerson::CPerson()
{
    m_firstN = "";
    m_lastN = "";
    m_address = "";
    m_phoneNumber = "";
}
CPerson::CPerson(string firstN, string lastN, string address, string phoneNumber)
{
    SetfirstN(firstN);
    SetlastN(lastN);
    Setaddress(address);
    SetphoneNumber(phoneNumber);
}

bool CPerson::SetfirstN(string firstN)
{
    if(isupper(firstN[0])&& firstN.find_first_of(" 0123456789.-+*()&^%$#@:?!,<>/\\`'|{}[]~") == -1){
    int len = firstN.size();
    for(int i= 1; i < len; ++i)
        {
            if(isupper(firstN[i]))return false;
        }
        m_firstN = firstN;
        return true;
    }
    return false;
}
bool CPerson::SetlastN(string lastN)
{
    if(isupper(lastN[0]) && lastN.find_first_of(" 0123456789.-+*()&^%$#@:?!,<>/\\`'|{}[]~") == -1){
    int len = lastN.size();
    for(int i= 1; i < len; ++i)
        {
            if(isupper(lastN[i]))return false;
        }
        m_lastN = lastN;
        return true;
    }
    return false;
}

bool CPerson::Setaddress(string address)
{
    if(address.size() > 4){
    m_address = address;
    return true;
    }
return false;
}

bool CPerson::SetphoneNumber(string phoneNumber)
{

    if(phoneNumber.size() == 10 && (phoneNumber[0] == '0' && (phoneNumber[1] == '8' || phoneNumber[1] == '9'))
       && phoneNumber.find_first_of(".-+*()&^%$#@:?!,<>/\\`'|{}[]~") == -1)
    {
        for(int i = 0; i < phoneNumber.size(); i++)
        {
            if((phoneNumber[i] >= 'a' && phoneNumber[i] <= 'z') || (phoneNumber[i] >= 'A' && phoneNumber[i] <= 'Z')) return false;
        }
        int len = m_phoneNumbers.size();
        if(len)for(int i = 0; i < len; i++)
        {
            if(!m_phoneNumbers[i].compare(phoneNumber)) return false;
        }
        m_phoneNumber = phoneNumber;
        m_phoneNumbers.push_back(phoneNumber);
        return true;
    }
    return false;
}

void CPerson::Read()
{
    string str;
    do
    {
        cout<<"First Name       :  ";
        cin>>str;
    }while(!SetfirstN(str));
    do
    {
        cout<<"Last Name        :  ";
        cin>>str;
    }while(!SetlastN(str));
    do
    {
        cout<<"Address          :  ";
        cin>>str;
    }while(!Setaddress(str));
    do
    {
        cout<<"Phone Number     :  ";
        cin>>str;
    }while(!SetphoneNumber(str));
}

void CPerson::Print()
{
    cout<<"First Name       :  "<<m_firstN<<endl;
    cout<<"Last Name        :  "<<m_lastN<<endl;
    cout<<"Address          :  "<<m_address<<endl;
    cout<<"Phone Number     :  "<<m_phoneNumber<<endl;
}
CPerson::~CPerson()
{
}
