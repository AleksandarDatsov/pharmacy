#ifndef CPROVIDER_H
#define CPROVIDER_H
#include "CPerson.h"
#include "CDate.h"
#include "CAbsClass.h"


class CProvider : public CPerson, public CDate
{
    public:
        CProvider();
        CProvider(string fn, string ln, string address, string phN, CDate deadline);

        virtual ~CProvider();
        CDate GetDeadline(){return m_deadline;}
        void Read();
        void Print();
    protected:

    private:
       CDate m_deadline;
};

#endif // CPROVIDER_H
