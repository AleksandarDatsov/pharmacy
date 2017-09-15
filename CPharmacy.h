#ifndef CPHARMACY_H
#define CPHARMACY_H
#include "CMedicament.h"
#include "CPerson.h"
#include "CProvider.h"


static vector<CMedicament> m_medicaments;
class CPharmacy : public CPerson
{
    public:
        CPharmacy();
        virtual ~CPharmacy();
        void AddMedicament(CMedicament);
        void PrintMedicaments();
        void DeleteMedicament(int);
        void UpdateMedicament();
        void CreateAndPrintArrayWithMedicamentsSellingBySpecificProvider();
        void CreateAndPrintArrayWithDataForAllProviders();
        void PrintTheCheapestMedicByProvidersLicenseNumber(long licenseN);
        void PrintDataForProviderByMedicamentName(string);
        void PrintMedicamentsWithExpiredDate(unsigned short day,unsigned short month,unsigned short year);
        void Menu();
    protected:

    private:

        bool UpdateMedicamentName(int, long, int);
        CManufacturer& FindManuf(long);
        CProvider& FindProvider(string);
        CProvider m_cpp;
        CManufacturer m_cmm;
        vector<CProvider> m_providers;
        vector<CManufacturer> m_manufacturers;
        vector<CMedicament> m_provider_medicaments;
};

#endif // CPHARMACY_H
