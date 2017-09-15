#include <iostream>
#include "CPharmacy.h"
#include <vector>
#include <cstring>
using namespace std;

CPharmacy::CPharmacy()
: CPerson()
{
}

void CPharmacy::AddMedicament(CMedicament medicament)
{
    m_medicaments.push_back(medicament);
    cout<<"\nTHE MEDICAMENT WAS ADDED"<<endl;
}
void CPharmacy::PrintMedicaments()
{
    int len = m_medicaments.size();
    if(len > 0)
        for(int i =0 ; i < len; i++)
        {
            cout<<"\n\n";
            m_medicaments[i].Print();
        }
    else cout<<"\n NO MEDICAMENTS IN STOCK!"<<endl;
}
void CPharmacy::DeleteMedicament(int medicamentNumber)
{
    int len = m_medicaments.size();
    for(int i =0 ; i < len; i++)
    {
        if(m_medicaments[i].GetMedicamentNumber() == medicamentNumber)
        {
            cout<<"MEDICAMENT WITH NAME: "<<m_medicaments[i].GetMedicamentName()<<" WAS DELETED!"<<endl;
            m_medicaments.erase(m_medicaments.begin() + i);
            return;
        }
    }
    cout<<"\nMEDICAMENT WITH SUCH NUMBER: "<<medicamentNumber<<" DOES NOT EXIST!"<<endl;
}

bool CPharmacy::UpdateMedicamentName(int choice, long manLN, int medN)
{
    int len = m_medicaments.size();
    for(int i = 0; i < len; i++)
    {
        if(m_medicaments[i].GetManufacturer().GetlicenseNumber() == manLN && m_medicaments[i].GetMedicamentNumber() == medN)
        {
            switch(choice)
            {
            case 1:
            {
                cout<<"\nNEW NAME: ";
                string newName;
                cin>>newName;
                cout<<"THE NAME OF THE FOLLOWING MEDICAMENT '"<<m_medicaments[i].GetMedicamentName()<<"'\nWAS CHANGED TO '"<<newName<<endl;
                m_medicaments[i].SetMedicamentName(newName);
                break;
            }
            case 2:
            {
                cout<<"\nNEW QUANTITY: ";
                int newQuantity, oldQuantity;
                cin>>newQuantity;
                oldQuantity = m_medicaments[i].GetQuantity();
                if(m_medicaments[i].SetQuantity(newQuantity)){
                cout<<"THE QUANTITY OF THE FOLLOWING MEDICAMENT '"<<m_medicaments[i].GetMedicamentName()<<"'\nWAS CHANGED FROM '"<<oldQuantity<<"' TO '"<<newQuantity<<"'"<<endl;
                }
                break;
            }
            case 3:
            {
                cout<<"\nNEW PRICE: ";
                double newPrice, oldPrice;
                cin>>newPrice;
                oldPrice = m_medicaments[i].GetPrice();
                if(m_medicaments[i].SetPrice(newPrice)){
                cout<<"THE PRICE OF THE FOLLOWING MEDICAMENT '"<<m_medicaments[i].GetMedicamentName()<<"'\nWAS CHANGED FROM '"<<oldPrice<<"' TO '"<<newPrice<<"'"<<endl;
                }
                break;
            }
            case 4:
            {
                cout<<"\nNEW MED. NUMBER: ";
                int newNumber, oldNumber;
                cin>>newNumber;
                oldNumber = m_medicaments[i].GetMedicamentNumber();
                if(m_medicaments[i].SetMedicamentNumber(newNumber)){
                cout<<"THE MED. NUMBER OF THE FOLLOWING MEDICAMENT '"<<m_medicaments[i].GetMedicamentName()<<"'\nWAS CHANGED FROM '"<<oldNumber<<"' TO '"<<newNumber<<"'"<<endl;
                }
                break;
            }
            default:
                cout<<"I DONT KNOW HOW I GOT HERE?!?"<<endl;
                break;
            }
            return true;
        }
    }
    cout<<"\nWRONG MANUFACTURER LICENSE NUMBER OR MEDIC NUMBER"<<endl;
    return false;
}
void CPharmacy::UpdateMedicament()
{
    if(m_medicaments.size() == 0) cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
    else{
    bool areAllOfDataCorrect;
    int choice;
    long manLN;
    int medN;
    cout<<"                 UPDATE mode status - ACTIVE - \n";
    cout<<"                 ENTER LICENSE NUMBER OF MANUFACTURER:";
    cin>>manLN;
    cout<<"                 ENTER NUMBER OF MEDICAMENT:";
    cin>>medN;

    do
    {
        cout<<"         CHOOSE WHICH ONE OF THE FOLLOWING CHARACHTERISTICS TO BE UPDATED:"<<endl;
        cout<<"         1. Medicament Name."<<endl;
        cout<<"         2. Medicament Quantity."<<endl;
        cout<<"         3. Medicament Price."<<endl;
        cout<<"         4. Medicament Number."<<endl;
        cout<<"         0. Back To Main Menu."<<endl;
        cin>>choice;

        if(choice!=0)areAllOfDataCorrect = UpdateMedicamentName(choice, manLN, medN);
    }
    while(choice && areAllOfDataCorrect);
    }
}
void CPharmacy::CreateAndPrintArrayWithMedicamentsSellingBySpecificProvider()
{
    if(m_medicaments.size() > 0){
    cout<<"License Number: ";
    cin>>licenseNumber;
    int counter = 0;
    int len = m_medicaments.size();
    cout<<"MEDICAMENTS OFFERED BY MANUFACTURER WITH "<<licenseNumber<< " : ";
    for(int i = 0; i < len; i++)
    {
        if(licenseNumber == m_medicaments[i].GetManufacturer().GetlicenseNumber())
        {
            m_provider_medicaments.push_back(m_medicaments[i]);
            counter++;
            cout<<m_medicaments[i].GetMedicamentName()<<" ";
        }
        cout<<endl;
    }
}else cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
}
void CPharmacy::CreateAndPrintArrayWithDataForAllProviders()
{
    if(m_medicaments.size() > 0){
    int counter = 0;
    int len = m_medicaments.size();
    for(int i = 0; i < len; i++)
    {
        m_providers.push_back(m_medicaments[i].GetProvider());
        counter++;
        m_medicaments[i].GetProvider().Print();
    }
    }else cout<<"\nNO WAY!!! THERE IS NO AVAILABLE PROVIDERS!"<<endl;
}
void CPharmacy::PrintTheCheapestMedicByProvidersLicenseNumber(long licenseNumber)
{
    int indexOfTheCheapestMedic = 0;
    int len = m_medicaments.size();
    if(len > 0)
    {
        double cheapestMedic = m_medicaments[0].GetPrice();
        for(int i = 0; i < len; i++)
        {
            cout<<licenseNumber<<endl;
            cout<<m_medicaments[i].GetManufacturer().GetlicenseNumber()<<endl;
            if(licenseNumber == m_medicaments[i].GetManufacturer().GetlicenseNumber())
            {
                if(cheapestMedic > m_medicaments[i].GetPrice())
                {
                    cheapestMedic = m_medicaments[i].GetPrice();
                    indexOfTheCheapestMedic = i;
                }
            }
        }

        cout<<"\nTHE CHEAPEST MEDIC IS : "<<endl;
        m_medicaments[indexOfTheCheapestMedic].Print();
        return;
    }
    cout<<"\nNO MEDICAMENTS IN STOCK."<<endl;
}
void CPharmacy::PrintDataForProviderByMedicamentName(string medicamentName)
{
    int len = m_medicaments.size();
    for(int i = 0; i < len; i++)
    {
        if(!medicamentName.compare(m_medicaments[i].GetMedicamentName()))m_medicaments[i].GetProvider().Print();
    }
}
void CPharmacy::PrintMedicamentsWithExpiredDate(unsigned short day,unsigned short month,unsigned short year)
{
    int len = m_medicaments.size();
    CDate date(day, month, year);
    for(int i = 0; i < len; i++)
    {
        if(m_medicaments[i].GetExpDate().cmp(date) == -1)
        {
            m_medicaments[i].Print();
        }
    }
}
CProvider& CPharmacy::FindProvider(string phoneNumber)
{
    int len2 = m_providers.size();
    if(len2 > 0)
    for(int i = 0; i < len2; i++)
    {
        if(m_providers[i].GetphoneNumber() == phoneNumber)
        {
            return m_providers[i];
        }
    }
    cout<<"\n NO SUCH PHONE NUMBER!"<<endl;
    return m_cpp;
}
CManufacturer& CPharmacy::FindManuf(long licenseNumber)
{
    int len = m_manufacturers.size();
    if(len > 0)
    for(int i = 0; i < len; i++)
    {

        if(m_manufacturers[i].GetlicenseNumber() == licenseNumber)
        {
            return m_manufacturers[i];
        }
    }
    cout<<"\n NO SUCH MANUFACTURER!"<<endl;
    return m_cmm;
}
void CPharmacy::Menu()
{
    CPharmacy cpharma;
    CManufacturer cmanuf;
    CMedicament cmedic;
    bool isEvOk, isHere;
    int choice;
    long choice2;

    do
    {
        cout<<"\nCHOOSE OPTION:"<<endl;
        cout<<"1. Add Medicament To Pharmacy."<<endl;
        cout<<"2. Print All Elements."<<endl;
        cout<<"3. Delete Medicament by n. Number."<<endl;
        cout<<"4. Print The Cheapest Medicament By Specific Manufacturer."<<endl;
        cout<<"5. Print Providers which provides A Specific Medicament."<<endl;
        cout<<"6. Print Medicaments With Expired Date."<<endl;
        cout<<"7. Update Medicament."<<endl;
        cout<<"8. Create And Print Array With All Providers."<<endl;
        cout<<"9. Create And Print Array With Medicaments By Specific Manufacturer."<<endl;
        cout<<"0. Exit."<<endl;
        cout<<"YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"     CHOOSE OPTIONS:"<<endl;
            cout<<"     1. ADD NEW MANUFACTURER"<<endl;
            cout<<"     2. ADD EXISTING ONE BY LICENSE NUMBER."<<endl;
            cout<<"     3. ADD EXISTING ONE BY LICENSE NUMBER AND ADD EXISTING PROVIDER BY PHONE NUMBER."<<endl;
            cout<<"     0. Back To The Main Menu"<<endl;

            cout<<"YOUR CHOICE: ";
            cin>>choice2;
            isHere = false;
            isEvOk = false;
            if(choice2 == 3){ choice2 = 2; isHere = true;}
            switch(choice2)
            {
                case 1:  {
                cmedic.Read(choice2);
                m_providers.push_back(cmedic.GetProvider());
                m_manufacturers.push_back(cmedic.GetManufacturer());
                isEvOk = true;
                break;
                }
            case 2:
            {
                if(choice2 == 2)
                {
                    long ln;
                    cout<<"2.   AVAILABLE MANUFACTURERS LICENSE NUMBERS : ";
                    for(unsigned int i = 0 ; i < m_manufacturers.size(); i++) cout<<m_manufacturers[i].GetlicenseNumber()<<" ;  ";
                    cout<<"     \nCHOOSE : ";
                    cin>>ln;
                    if(FindManuf(ln).GetlicenseNumber() > 0 )
                        {
                            isEvOk = true;
                            cmedic.SetCManufacturer(FindManuf(ln));
                            m_providers.push_back(cmedic.GetProvider());
                            choice2 = (isHere) ? choice2+1 : choice2;
                            cmedic.Read(choice2);
                        }
                }
                if(!isHere) break;
            }
             case 3:
                {
                    string phoneNumber;
                    cout<<"2.   PROVIDERS PHONE NUMBER: ";
                    cin>>phoneNumber;
                    if(FindProvider(phoneNumber).GetfirstN().length() > 0)
                    {
                        isEvOk = true;
                    cmedic.SetCProvider(FindProvider(phoneNumber));
                    }
                }
            break;
        }
                    if(isEvOk) cpharma.AddMedicament(cmedic);

        break;
        }
        case 2:
            cpharma.PrintMedicaments();
            break;
        case 3:
        {
            if(m_medicaments.size() > 0){
            cout<<"Enter A Medicament Number \nOr '0' To Back To The Main Menu: ";
            int n;
            cin>>n;
            if(n)cpharma.DeleteMedicament(n);
            }else cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
            break;
        }
        case 4:
        {
            if(m_medicaments.size() > 0){
            cout<<"Manufacturer License Number \nOr '0' To Back To The Main Menu: ";
            long l;
            cin>>l;
            if(l)cpharma.PrintTheCheapestMedicByProvidersLicenseNumber(l);
            }else cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
            break;
        }
        case 5:
        {
            if(m_medicaments.size() > 0){
            cout<<"Medicament Name: ";
            string mn;
            cin>>mn;
            cpharma.PrintDataForProviderByMedicamentName(mn);
            }else cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
            break;
        }

        case 6:
        {
            if(m_medicaments.size() > 0){
            cout<<"Date: ";
            unsigned short day, month, year;
            cin>>day>>month>>year;
            cpharma.PrintMedicamentsWithExpiredDate(day, month, year);
        }else cout<<"\nNO MEDICAMENTS IN STOCK!"<<endl;
            break;
        }
        case 7:
            UpdateMedicament();
            break;
        case 8: CreateAndPrintArrayWithDataForAllProviders();
            break;
        case 9: CreateAndPrintArrayWithMedicamentsSellingBySpecificProvider();
            break;
        default:
            cout<<"\n\nWRONG CHOICE!!\n"<<endl;
        };
    }
    while(choice);
}
CPharmacy::~CPharmacy()
{
    //dtor
}
