#ifndef CLASEEEE_H_INCLUDED
#define CLASEEEE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*Se doreste implementarea unei aplicatii OOP care sa permita
gestionarea activitatii unor farmacii apartinand proprietarului X. Pentru
fiecare farmacie se cunoaște cel puțin denumirea, numărul de angajați și
profiturile pe fiecare luna. Farmaciile pot fi și online. În acest caz se
cunoaște doar adresa web, numărul de vizitatori și discountul utilizat.*/
class Farmacie
{
    protected:
        string denumire;
        int numar_angajati;
        double profit[12];

    public :

        Farmacie ()
        {
            denumire = "";
            numar_angajati = 0;
            for(int i = 0 ; i < 12 ; i++ )
                profit[i] = 0;
        }
        Farmacie(string nume, int numar, const double p[])
        {
            denumire = nume;
            numar_angajati = numar;
            for(int i = 0 ; i < 12 ; i++ )
                profit[i] = p[i];
        }
        Farmacie(const Farmacie& f)
        {
            denumire = f.denumire;
            numar_angajati = f.numar_angajati;
            for(int i = 0 ; i < 12 ; i++ )
                profit[i] = f.profit[i];
        }
        ~Farmacie(){}
        string get_denumire(){return denumire;}
        void set_denumire(string nume)
                {
                    denumire = nume;
                }

        int get_numar_angajati(){ return numar_angajati;}
        void set_numar_angajati( int numar )
                {
                    numar_angajati = numar;
                }
        double get_profit( int i){ return profit[i]; }
        double set_profit( double numar, int i)
                {
                    profit[i] = numar;
                }

        friend istream& operator>>(istream&, Farmacie&);
        friend ostream& operator<<(ostream&, const Farmacie&);
        const Farmacie& operator=(const Farmacie&);
        virtual void Afisare(ostream& on) const
        {
            on << "Denumire farmacie: " << denumire << endl;
            on << "Numar angajati: " << numar_angajati << endl;
            on << "Profit pe toate lunile: " << endl;
            for(int i = 0 ; i < 12 ; i++ )
                on << "Luna " << i+1 << " cu profit " << profit[i] << endl;
            on << endl;
        }
};

class Farmacie_Online: public Farmacie
{
    string adresa_web;
    int numarul_de_vizitatori;
    double discountul_utilizat;

    public:

        Farmacie_Online()
        {
            adresa_web = "";
            numarul_de_vizitatori = 0;
            discountul_utilizat = 0;
        }
        Farmacie_Online(string web, int nr, double discount)
        {
            adresa_web = web;
            numarul_de_vizitatori = nr;
            discountul_utilizat = discount;
        }
        Farmacie_Online(string nume, int angajati, double p[], string web, int nr, double discount): Farmacie(nume,angajati,p)
        {
            adresa_web = web;
            numarul_de_vizitatori = nr;
            discountul_utilizat = discount;
        }
        Farmacie_Online(const Farmacie_Online& f): Farmacie(f.denumire,f.numar_angajati,f.profit)
        {
            adresa_web = f.adresa_web;
            numarul_de_vizitatori = f.numarul_de_vizitatori;
            discountul_utilizat = f.discountul_utilizat;
        }
        ~Farmacie_Online(){}

        string get_adresa_web(){ return adresa_web; }
        void set_adresa_web(string web){ adresa_web = web;}

        int get_numarul_de_vizitatori(){return numarul_de_vizitatori;}
        void set_numarul_de_vizitatori(int nr){ numarul_de_vizitatori = nr; }

        double get_discountul_utilizat(){return discountul_utilizat;}
        void set_discountul_utilizat(double nr){ discountul_utilizat = nr; }

        friend istream& operator>>(istream&, Farmacie_Online&);
        friend ostream& operator<<(ostream&, const Farmacie_Online&);
        const Farmacie_Online& operator=(const Farmacie_Online&);
        void Afisare(ostream& on) const
        {
            Farmacie::Afisare(on);
            on << "Adresa web: " << adresa_web;
            on << endl << "Numar de vizitatori: " << numarul_de_vizitatori << endl;
            on << "Discountul utilizat: " << discountul_utilizat << endl;
        }

};

template <class T>

class GestionareFarmacie
{
    static int index ; // o data statica nu apartine unui anumit obiect, ci este la fel pentru toate obiectele unei clase
    const int id;
    vector <T*> farmacii;

    public:

        GestionareFarmacie( const int id_ul): id(id_ul){} // constructor de initializare cu parametri
        GestionareFarmacie(const GestionareFarmacie& D): id(D.id) // constructor de copiere
        {
            farmacii = D.farmacii;
        }
        ~GestionareFarmacie() // destructor
        {
            for( int i = 0 ; i < farmacii.size() ; i++)
            {
                delete farmacii[i];
            }
        }

        static int get_index(){return index;}

        vector <Farmacie*> get_vector()const{return farmacii;}

        const int get_id(){return id;}

        friend ostream& operator<<(ostream&, const GestionareFarmacie&);
        const GestionareFarmacie& operator=(const GestionareFarmacie& D)
        {
            if(&D != this)
            {
                farmacii = D.farmacii;
            }
            return *this;
        }

        GestionareFarmacie& operator+=( T& D)
        {
            farmacii.push_back(&D); //downcasting
            index++;
            return *this;
        }

};

template <>
class GestionareFarmacie<unsigned>
{
    int nr_vizitatori;

    public:

        GestionareFarmacie(int nr)
        {
            nr_vizitatori = nr;
        }
        GestionareFarmacie()
        {
            nr_vizitatori = 0;
        }
        GestionareFarmacie(GestionareFarmacie& D)
        {
            nr_vizitatori = D.nr_vizitatori;
        }
        ~GestionareFarmacie(){}

        int get_nr()const{return nr_vizitatori;}
        void set_nr(int nr){nr_vizitatori = nr;}

        friend ostream& operator<<(ostream &D, const GestionareFarmacie<unsigned>& U)
        {
            D << endl << "Numar vizitatori online: " << U.nr_vizitatori << endl;
            return D;
        }
};

#endif // CLASEEEE_H_INCLUDED
