#ifndef CPERSON_H
#define CPERSON_H
#include <cstring>
#include <iostream>
#include <vector>
#include "CAbsClass.h"
using namespace std;
class CPerson : public CAbs
{
    public:
        CPerson();
        CPerson(string fn, string ln, string address, string phoneN);

        virtual ~CPerson();

        string GetfirstN() { return m_firstN; }
        bool SetfirstN(string val);
        string GetlastN() { return m_lastN; }
        bool SetlastN(string val);
        string Getaddress() { return m_address; }
        bool Setaddress(string val);
        string GetphoneNumber() { return m_phoneNumber; }
        bool SetphoneNumber(string val);
        void Read();
        void Print();

    protected:

    private:
        string m_firstN;
        string m_lastN;
        string m_address;
        string m_phoneNumber;
};
static vector<string> m_phoneNumbers;
#endif // CPERSON_H
