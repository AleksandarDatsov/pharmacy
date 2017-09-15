#ifndef CMANUFACTURER_H
#define CMANUFACTURER_H
#include "CPerson.h"
#include "CAbsClass.h"
static long licenseNumber = 10000000;


class CManufacturer : public CPerson
{

    public:
        CManufacturer();
        CManufacturer(string fn, string ln, string address, string phN);

        virtual ~CManufacturer();

        long GetlicenseNumber() { return m_licenseNumber; }
        void SetlicenseNumber() { m_licenseNumber = licenseNumber++; }
        void Read();
        void Print();
    private:
        long m_licenseNumber;
};

#endif // CMANUFACTURER_H
