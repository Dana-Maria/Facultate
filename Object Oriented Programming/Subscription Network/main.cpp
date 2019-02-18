#include <iostream>
#include <string.h>
#include "Clase.h"
using namespace std;

Persoana::Persoana()
{
    id = -1;
    nume = NULL;
    nr_obiecte++;
}

Persoana::Persoana(int numar)
{
    id = numar;
    nume = NULL;
    nr_obiecte++;
}

Persoana::Persoana(char* denumire)
{
    int nr = strlen(denumire);
    nume = new char[ nr + 1];
    for(int i = 0; i < nr ; i++ )
        nume[i] = denumire[i];
    id = -1;
    nr_obiecte++;
}

Persoana::Persoana(int numar, char* denumire)
{
    id = numar;
    int nr = strlen(denumire);
    nume = new char[ nr + 1];
    for(int i = 0; i < nr ; i++ )
        nume[i] = denumire[i];
    nr_obiecte++;
}

Persoana::Persoana ( const Persoana& copie)
{
    id = copie.id;
    int nr = strlen(copie.nume);
    nume = new char[ nr + 1];
    for(int i = 0; i < nr ; i++ )
        nume[i] = copie.nume[i];
    nr_obiecte++;
}

const Persoana& Persoana::operator=(const Persoana& P)
{
    if(this != &P )
        {
            id = P.id;
            set_nume(P.nume);
        }
    return *this;
}

istream& operator>>(istream& i, Persoana& p)
{
    cout << "Se citeste o persoana: " << endl;
    cout << "ID: ";
    i >> p.id;
    delete [] p.nume;
    cout << "Nume: ";
    i >> p.nume;
    cout << endl;
    return i;
}

ostream& operator<<(ostream& o, const Persoana& p)
{
    o << "Informatii persoana: " << endl << "ID: " << p.id << endl << "Nume: " << p.nume << endl;
    return o;
}

/*   Clasa Abonat  */
Abonat::Abonat(char *telefon, char* denumire, int i): Persoana(i, denumire)
{
    int nr = strlen(telefon);
    nr_telefon = new char[nr+1];
    for(int j = 0; j < nr ; j++)
        nr_telefon[j] = telefon[j];
    nr_obiecte++;
}

Abonat::Abonat(const Abonat& a):Persoana(a.id, a.nume)
{
    int nr = strlen(a.nr_telefon);
    nr_telefon = new char[nr+1];
    for(int j = 0; j < nr ; j++)
        nr_telefon[j] = a.nr_telefon[j];
    nr_obiecte++;
}

Abonat::Abonat()
{
    nr_telefon = NULL;
    nr_obiecte++;
}

const Abonat& Abonat :: operator=(const Abonat& a)
{
    if(this != &a)
    {
            id = a.id;
            set_nume(a.nume);
            set_nr_telefon(a.nr_telefon);
    }
    return *this;
}

istream& operator>>(istream& i, Abonat& p)
{
    char s[256];
    cout << endl << "Se citeste o persoana: " << endl;
    cout << "ID: ";
    i >> p.id;

    cout << "Nume: ";
    i.get();
    i.getline(s, 256);
    p.set_nume(s);

    cout << "Numar de telefon: ";
    i >> s;
    p.set_nr_telefon(s);

    return i;
}

ostream& operator<<(ostream& o, const Abonat& p)
{
    o << endl << "Informatii Abonat: " << endl << "ID: " << p.id << endl << "Nume: ";
    o << p.nume << endl <<  "Numar de telefon: " << p.nr_telefon << endl;
    return o;
}

/*   Clasa Abonat Skype */

Abonat_Skype::Abonat_Skype()
{
    id_Skype = NULL;
    nr_obiecte++;
}

Abonat_Skype::Abonat_Skype(char *telefon, char* denumire, int i, char* j): Abonat (telefon, denumire, i)
{
    set_id_skype(j);
    nr_obiecte++;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype& a): Abonat(a.nr_telefon, a.nume, a.id)
{
    set_id_skype(a.id_Skype);
    nr_obiecte++;
}

const Abonat_Skype& Abonat_Skype :: operator=(const Abonat_Skype& a)
{
    if(this != &a)
    {
            id = a.id;

            set_nume(a.nume);

            set_nr_telefon(a.nr_telefon);

            set_id_skype(a.id_Skype);
    }
    return *this;
}

istream& operator>>(istream& i, Abonat_Skype& p)
{
    char s[256];
    cout << endl << "Se citeste o persoana: " << endl;
    cout << "ID: ";
    i >> p.id;

    cout << "Nume: ";
    i.get();
    i.getline(s, 256);
    p.set_nume(s);

    cout << "Numar de telefon: ";
    i >> s;
    p.set_nr_telefon(s);

    cout << "ID Skype: ";
    i >> s;
    p.set_id_skype(s);

    return i;
}

ostream& operator<<(ostream& o, const Abonat_Skype& p)
{
    o << endl << "Informatii Abonat: " << endl << "ID: " << p.id << endl << "Nume: ";
    o << p.nume << endl <<  "Numar de telefon: " << p.nr_telefon << endl << "ID Skype: " <<p.id_Skype ;
    return o;
}

/* Abonat Skype Romania */

Abonat_Skype_Romania:: Abonat_Skype_Romania()
{
    adresa_mail = NULL;
    nr_obiecte++;
}

Abonat_Skype_Romania:: Abonat_Skype_Romania(char *denumire, char *telefon, char* mail, int i, char* j): Abonat_Skype(telefon, denumire,i,j)
{
    int nr = strlen(mail);
    adresa_mail = new char[nr+1];
    for(int j = 0; j < nr ; j++)
        adresa_mail[j] = mail[j];
    adresa_mail[nr] = NULL;
    nr_obiecte++;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& a): Abonat_Skype(a.nr_telefon, a.nume,a.id,a.id_Skype)
{
    int nr = strlen(a.adresa_mail);
    adresa_mail = new char[nr+1];
    for(int j = 0; j < nr ; j++)
        adresa_mail[j] = a.adresa_mail[j];
    adresa_mail[nr] = NULL;
    nr_obiecte++;
}

const Abonat_Skype_Romania& Abonat_Skype_Romania :: operator=(const Abonat_Skype_Romania& a)
{
    if(this != &a)
    {
            id = a.id;

            set_nume(a.nume);

            set_nr_telefon(a.nr_telefon);

            set_id_skype(a.id_Skype);

            set_adresa_mail(a.adresa_mail);
    }
    return *this;
}

istream& operator>>(istream& i, Abonat_Skype_Romania& p)
{
    char s[256];
    cout << endl;
    cout << "Se citeste o persoana: " << endl;
    cout << "ID: ";
    i >> p.id;

    cout << "Nume: ";
    i.get();
    i.getline(s, 256);
    p.set_nume(s);

    cout << "Numar de telefon: ";
    i >> s;
    p.set_nr_telefon(s);

    cout << "ID Skype: ";
    i >> s;
    p.set_id_skype(s);

    cout << "Adresa de mail: ";
    i >> s;
    p.set_adresa_mail(s);

    return i;
}

ostream& operator<<(ostream& o, const Abonat_Skype_Romania& p)
{
    o << endl << "Informatii Abonat: " << endl << endl << "ID: " << p.id << endl << "Nume: ";
    o << p.nume << endl <<  "Numar de telefon: " << p.nr_telefon << endl << "ID Skype: " <<p.id_Skype ;
    o << endl << "Adresa de mail: " << p.adresa_mail << endl;
    return o;
}

/* Abonat Skype Extern */

Abonat_Skype_Extern::Abonat_Skype_Extern()
{
    tara = NULL;
    nr_obiecte++;
}

Abonat_Skype_Extern:: Abonat_Skype_Extern(char *denumire, char *telefon, char* t, int i, char* j): Abonat_Skype(telefon, denumire,i,j)
{
    int nr = strlen(t);
    tara = new char[nr+1];
    for(int i = 0; i < nr ; i++)
        tara[i] = t[i];
    tara[nr] = NULL;
    nr_obiecte++;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern &a): Abonat_Skype (a.nr_telefon, a.nume, a.id, a.id_Skype)
{
    int nr = strlen(a.tara);
    tara = new char[nr+1];
    for(int j = 0; j < nr ; j++)
        tara[j] = a.tara[j];
    tara[nr] = NULL;
    nr_obiecte++;
}
const Abonat_Skype_Extern& Abonat_Skype_Extern :: operator=(const Abonat_Skype_Extern& a)
{
    if(this != &a)
    {
            id = a.id;

            set_nume(a.nume);

            set_nr_telefon(a.nr_telefon);

            set_id_skype(a.id_Skype);

            set_tara(a.tara);
    }
    return *this;
}

istream& operator>>(istream& i, Abonat_Skype_Extern& p)
{
    char s[256];

    cout << endl << "Se citeste o persoana: " << endl;
    cout << "ID: ";
    i >> p.id;

    cout << "Nume: ";
    i.get();
    i.getline(s, 256);
    p.set_nume(s);

    cout << "Numar de telefon: ";
    i >> s;
    p.set_nr_telefon(s);

    cout << "ID Skype: ";
    i >> s;
    p.set_id_skype(s);

    cout << "Tara: ";
    i.get();
    i.getline(s, 256);
    p.set_tara(s);

    return i;
}

ostream& operator<<(ostream& o, const Abonat_Skype_Extern& p)
{
    o << endl << "Informatii Abonat: " << endl << endl << "ID: " << p.id << endl << "Nume: ";
    o << p.nume << endl <<  "Numar de telefon: " << p.nr_telefon << endl << "ID Skype: " <<p.id_Skype ;
    o << endl << "Tara: " << p.tara << endl;
    return o;
}

/* AGENDA */

Agenda::Agenda(int numar)
{
    for(int i = 0; i < numar ; i++)
            abonati[i] = new Abonat;
    numar_abonati = numar;
}

Agenda::Agenda(const Agenda& a)
{
    numar_abonati = a.numar_abonati;
    for(int i = 0 ; i < numar_abonati ; i++)
        {
            abonati[i] = new Abonat;
            *abonati[i] = *(a.abonati[i]);

        }
}

Agenda::Agenda()
{
    numar_abonati = 0;
    abonati[0] = NULL;
}

const Agenda& Agenda :: operator=(const Agenda& a)
{
    if(this != &a)
    {
        set_abonati(a.numar_abonati);
        for(int i = 0 ; i < numar_abonati ; i++)
            {
                delete abonati[i];
                abonati[i] = new Abonat;
                *abonati[i] = *(a.abonati[i]);
            }
    }

    return *this;
}

istream& operator>>(istream& i, Agenda& a)
{
    cout << "Numar de abonati: ";
    i >> a.numar_abonati;
    cout << "Abonati: " << endl;
    for(int j = 0 ; j < a.numar_abonati; j++)
    {
        cout << "Abonat[" << j << "]= ";
        delete a.abonati[j];
        i >> *(a.abonati[j]);
    }
    return i;
}

void meniu ()
{
    cout << endl << "Meniu: ";
    cout << endl << "1. Abonat Skype Romania";
    cout << endl << "2. Abonat Skype Extern";
    cout << endl;
}

int Persoana:: nr_obiecte = 0;

int main()
{

    int numar_abonati, i, j;
    cout << "Se da numarul de abonati: ";
    cin >> numar_abonati;
    Agenda ag;
    Abonat_Skype_Extern* e;
    Abonat_Skype_Romania* r;

    for(i = 0 ; i < numar_abonati ; i++)
    {
        int optiune;
        meniu();
        cout << endl;
        cout << "Alege optiune: ";
        cin >> optiune;
        switch(optiune)
        {
            case 1 :
                {
                    r = new Abonat_Skype_Romania;
                    cout << "Citeste Abonat Skype Romania: " << endl;
                    cin >> *r;
                    ag[i] = r;
                    break;
                }
            case 2:
                {
                    e = new Abonat_Skype_Extern();
                    cout << "Citeste Abonat Skype Extern: " << endl;
                    cin >> *e;
                    ag[i] = e;
                    break;
                }
            default:
                cout << "Operatiunea aleasa nu este valida!";
                if(i == 0 )
                {
                    break;
                }
                ag.set_abonati(numar_abonati - 1);
                numar_abonati--;
                break;
        }
    }
    cout << endl;
    for ( i = 0 ; i < numar_abonati ; i++)
    {
        if(Abonat_Skype_Extern* n = dynamic_cast <Abonat_Skype_Extern*>(ag[i]))
                cout << *n << endl;
        else
            if(Abonat_Skype_Romania* n = dynamic_cast <Abonat_Skype_Romania*>(ag[i]))
                    cout << *n << endl;
    }
    cout << endl;
    cout << "Numar de obicte: ";
    cout << Persoana::get_nr_obiecte() << endl;
    for ( i = 0 ; i < numar_abonati ; i++)
    {
        delete ag[i];
    }
    cout << endl;
    cout << "Numar de obicte: ";
    cout << Persoana::get_nr_obiecte() << endl;
    return 0;
}
