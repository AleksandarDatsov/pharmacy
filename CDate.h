#ifndef CDATE_H
#define CDATE_H
#include "CAbsClass.h"
#include <ctime>

class CDate : CAbs
{
    public:
        CDate();
        CDate(unsigned short day,unsigned short month,unsigned short year);

        virtual ~CDate();

        unsigned short Getday() { return m_day; }
        void Setday(unsigned short val){m_day = val;}
        unsigned short Getmonth() { return m_month; }
        void Setmonth(unsigned short val){m_month = val;}
        unsigned short Getyear() { return m_year; }
        void Setyear(unsigned short val){m_year = val;}
        cmp(CDate date);
        void Read();
        void Print();



    protected:

    private:
        bool SetDate(unsigned short day, unsigned short month, unsigned short year);
        unsigned short m_day;
        unsigned short m_month;
        unsigned short m_year;
};

#endif // CDATE_H
