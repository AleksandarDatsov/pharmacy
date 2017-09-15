#include "CDate.h"
#include <ctime>
#include <iostream>
using namespace std;

CDate::CDate()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}
CDate::CDate(unsigned short day,unsigned short month,unsigned short year)
{
    SetDate(day, month, year);
}
bool IsLeapYear(unsigned short year)
{
    return ((!(year%4) && (year%100)) || !(year%400));
}

bool CDate::SetDate(unsigned short day, unsigned short month, unsigned short year)
{
        bool isEvOkay = true;
        switch (month)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12 : if(day > 31) isEvOkay = false;
            break;
        case 4:case 6:case 9:case 11: if(day > 30) isEvOkay = false;

            break;
        case 2 :if(IsLeapYear(year)){
                    if(day > 29) isEvOkay = false;
                }else if(day > 28) isEvOkay = false;

        }
        if(isEvOkay && year > 2010)
        {
            Setday(day);
            Setmonth(month);
            Setyear(year);
            return true;
        }

    return false;
}
void CDate::Read()
{
    unsigned short day, month, year;
    do
    {
        cout<<"dd mm yyyy : ";
        cin>>day;
        cin>>month;
        cin>>year;
    }
    while(!SetDate(day, month, year));
}

void CDate::Print()
{
    if(m_day < 10) cout<<0;
    cout<<m_day<<'.';
    if(m_month < 10) cout<<0;
    cout<<m_month<<'.';
    cout<<m_year;
}
int CDate::cmp(CDate date)
{
    if(m_year < date.m_year) return -1;
    if(m_year > date.m_year) return 1;
    if(m_month < date.m_month) return -1;
    if(m_month > date.m_month) return 1;
    if(m_day < date.m_day) return -1;
    if(m_day > date.m_day) return 1;
    return 0;
}
CDate::~CDate()
{
    //dtor

}
