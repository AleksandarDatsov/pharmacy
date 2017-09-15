#include <iostream>
#include "CPerson.h"
#include "CDate.h"
#include "CProvider.h"
#include "CManufacturer.h"
#include "CMedicament.h"
#include "CPharmacy.h"
#include <cstring>
using namespace std;

int main()
{
    /*CDate deadline(3,3,2017);
    CProvider cp("Alek", "Datsov", "Sofiq", "0988373625", deadline);
    CProvider cp2("Mirella", "Krysteva", "Sofiq", "0988323625", deadline);

    CManufacturer cm("Pharma","Ood","Sofia", "0987654329");
    CManufacturer cm2("Bilki","Ood","Sofia", "0983654329");

    CMedicament cMed(cp,cm);
    CMedicament cMed2(cp2,cm2);

    CPharmacy cPharma;
    cPharma.AddMedicament(cMed);
    cPharma.AddMedicament(cMed2);

    cout<<"\n\nPharmacy PRINT DATA FOR PROVIDERS BY MEDICAMENT NAME :\n";
    cPharma.PrintDataForProviderByMedicamentName("Aspirin");

    cout<<"\n\nPharmacy PRINT MEDICAMENTS WITH EXP DATE:\n";
    cPharma.PrintMedicamentsWithExpiredDate(4, 4, 2017);

    cout<<"\n\nPharmacy PRINT DATA FOR PROVIDERS BY MEDICAMENT NAME :\n";
    cPharma.PrintTheCheapestMedicByProvidersLicenseNumber(cm.GetlicenseNumber());
    */
    /*cout<<"\n\nPharmacy Print :\n";
    cPharma.PrintMedicaments();


    cPharma.DeleteMedicament(200000);
    cout<<"\nPharmacy Print :\n\n";
    cPharma.PrintMedicaments();
*/
    CPharmacy cp;
    cp.Menu();
        return 0;
}
