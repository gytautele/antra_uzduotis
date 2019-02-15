#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::setw;

struct mok
{
    string vardas;
    string pavarde;
    double galutinis1=0; //galutinis rezultatas
    double galutinis2=0; //galutinis rezultatas
    double med=0; //mediana
};

int main ()
{
    int m=0; //studentu skaicius
    cout << "Iveskite kiek bus studentu?" << endl;
    cin >> m;

    mok *A=new mok[m];

    for (int i=0; i<m; i++) {
        cout << "Iveskite savo varda ir pavarde" << endl;
        cin >> A[i].vardas >> A[i].pavarde;

        int a; //skaicius skirtas pasirinkti

        cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite ivesti patys spauskite 1:" << endl;
        cin >> a;

        double sum = 0; //suma;
        int kiek=0;

        if (a==1)
        {
            int *nd=new int[2]; //namu darbu rezultatai
            cout << "Iveskite namu darbu rezultatus. Kai baigsite, spauskite 0:" << endl;
            int b;
            cin >> b;
            nd[0]=b;
            kiek++;
            while (true)
            {
                if (kiek>=1)
                {
                    cin >> b;
                    if (b==0) break;

                    int *laikk=new int[2*kiek];

                    for (int d=0; d<kiek; d++)
                    {
                        laikk[d]=nd[d];
                    }
                    //std::copy(nd, nd+1, laikk);

                    delete []nd;
                    nd=laikk;

                    nd[kiek]=b;
                }
                kiek++;
            }

            int laik; //laikinas kintamasis rikiavimui
            for (int k=0; k<kiek-1; k++)
                for (int l=i+1; l<kiek; l++)
                    if (nd[k]>nd[l])
                    {
                        laik=nd[k];
                        nd[k]=nd[l];
                        nd[l]=laik;
                    }

            double kk=0; //laikinas

            if (kiek% 2 != 0) kk=(double)nd[kiek/2];

            else A[i].med=(double)(nd[(kiek-1)/2] + nd[kiek/2])/2.0;
        }

        else
        {
            cout << "Kiek norite generuoti skaiciu?" << endl;
            cin >> kiek;
            int *nd=new int[kiek]; //namu darbu rezultatai
            for (int j = 0; j < kiek; j++) {
                nd[j]=rand()%10;
                cout << nd[j] << endl;
                sum+=nd[j];
                cout << sum << endl;
                cout << "-----------------" << endl;
            }

            int laik; //laikinas kintamasis rikiavimui
            for (int k=0; k<kiek-1; k++)
                for (int l=i+1; l<kiek; l++)
                    if (nd[k]>nd[l])
                    {
                        laik=nd[k];
                        nd[k]=nd[l];
                        nd[l]=laik;
                    }

            double kk=0; //laikinas

            if (kiek% 2 != 0) kk=(double)nd[kiek/2];

            else A[i].med=(double)(nd[(kiek-1)/2] + nd[kiek/2])/2.0;

        }

        int egz; //egzamino rezultatas
        cout << "Iveskite egzamino pazymi" << endl;
        cin >> egz;

        double vid=0; //vidurkis
        vid=sum/(double)kiek;
        A[i].galutinis1 = 0.4 * vid + 0.6 * (double)egz;
        A[i].galutinis2 = 0.4 * A[i].med + 0.6 * (double)egz;

    }

    cout << "Pavarde" <<std::right << setw(20) << "Vardas" << std::right <<setw(20) << "VidGalutinis" << std::right << setw(20) << "MedGalutinis" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for (int i=0; i<m; i++)
    {
        cout << A[i].pavarde << std::right << setw(20) << A[i].vardas << std::right << setw(20) << std::fixed << std::setprecision(2) << std::right << A[i].galutinis1 << setw(20) << std::right << A[i].galutinis2 << endl;
    }

}