#ifndef CMEDICAMENT_H
#define CMEDICAMENT_H
#include "CProvider.h"
#include "CManufacturer.h"
#include "CDate.h"
#include "CAbsClass.h"
#include <vector>

class CMedicament : public CProvider, public CManufacturer
{
    public:
        CMedicament();
        CMedicament(CProvider cProvider, CManufacturer cManuf,string name,int quantity, double price, int medN);

        virtual ~CMedicament();
        string GetMedicamentName() { return m_medicamentName; }
        bool SetMedicamentName(string val);
        int GetQuantity() { return m_quantity; }
        bool SetQuantity(int val);
        double GetPrice() { return m_price; }
        bool SetPrice(double val);
        bool SetMedicamentNumber(int);
        int GetMedicamentNumber(){return m_medicNum;}
        CDate GetManDate(){return m_manDate;}
        void SetManDate(CDate cd){m_manDate = cd;}
        CDate GetExpDate(){return m_expDate;}
        void SetExpDate(CDate cd){m_expDate = cd;}
        CManufacturer GetManufacturer() {return m_cman;}
        void SetCManufacturer(CManufacturer cm) { m_cman = cm;}
        CProvider GetProvider() {return m_cp;}
        void SetCProvider(CProvider cp){m_cp = cp;}
        void Read(long);
        void Read(){};
        void Print();
    protected:

    private:

        void SetDates();
        CProvider m_cp;
        CManufacturer m_cman;
        string m_medicamentName;
        int m_quantity;
        int m_medicNum;
        double m_price;
        CDate m_manDate;
        CDate m_expDate;
};

#endif // CMEDICAMENT_H
