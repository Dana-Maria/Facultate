#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Persoana
{
    protected:

        int id;
        char *nume;
        static int nr_obiecte;

    public:

        Persoana ();
        Persoana (int );
        Persoana (char*);
        Persoana (int, char*);
        Persoana ( const Persoana&);
        virtual ~Persoana() {
            nr_obiecte--;
            delete[] nume; }

        static int get_nr_obiecte() { return nr_obiecte; }
        void set_id(int numar){  id = numar; }
        int get_id() const { return id;}

        char* get_nume(){return nume;}
        void set_nume(char* denumire)
                {
                    int nr = strlen(denumire);
                    delete [] nume;
                    nume = new char[ nr + 1];
                    for(int i = 0; i < nr ; i++ )
                            nume[i] = denumire[i];
                    nume[nr] = NULL;
                }

        const Persoana& operator=(const Persoana&);
        friend istream& operator>>(istream&, Persoana&);
        friend ostream& operator<<(ostream&, const Persoana&);


};



class Abonat: public Persoana
{
    protected:

      char *nr_telefon;

    public:

        Abonat(char*, char*, int);
        Abonat();
        Abonat( const Abonat&);
        virtual ~Abonat() { delete[] nr_telefon; nr_obiecte--; }

        void set_nr_telefon(char *numar)
        {
                    int nr = strlen(numar);
                    delete [] nr_telefon;
                    nr_telefon = new char[ nr + 1];
                    for(int i = 0; i < nr ; i++ )
                            nr_telefon[i] = numar[i];
                    nr_telefon[nr] = NULL;
        }

        char* get_nr_telefon(){ return nr_telefon; }

        const Abonat& operator=(const Abonat&);
        friend istream& operator>>(istream&, Abonat&);
        friend ostream& operator<<(ostream&, const Abonat&);


};

class Abonat_Skype:public Abonat
{
     protected:

        char* id_Skype;

     public:

            Abonat_Skype();
            Abonat_Skype ( char*, char*, int, char*);
            Abonat_Skype ( const Abonat_Skype& );
            virtual ~Abonat_Skype(){ delete[] id_Skype; nr_obiecte--; }

            char* get_id_skype(){ return id_Skype; }
            void set_id_skype(char* id)
            {
                    int nr = strlen(id);
                    delete [] id_Skype;
                    id_Skype = new char[ nr + 1];
                    for(int i = 0; i < nr ; i++ )
                            id_Skype[i] = id[i];
                    id_Skype[nr] = NULL;
            }

            const Abonat_Skype& operator=(const Abonat_Skype&);
            friend istream& operator>>(istream&, Abonat_Skype&);
            friend ostream& operator<<(ostream&, const Abonat_Skype&);


};

class Abonat_Skype_Romania:public Abonat_Skype
{
    protected:

     char* adresa_mail;

    public:

        Abonat_Skype_Romania();
        Abonat_Skype_Romania(char*, char*, char*, int i, char*);
        Abonat_Skype_Romania (const Abonat_Skype_Romania&);
        ~Abonat_Skype_Romania(){ delete [] adresa_mail; nr_obiecte--;}

        void set_adresa_mail(char* denumire)
                {
                    int nr = strlen(denumire);
                    delete[] adresa_mail;
                    adresa_mail = new char[ nr + 1];
                    for(int i = 0; i < nr ; i++ )
                            adresa_mail[i] = denumire[i];
                    adresa_mail[nr] = NULL;
                }
        char* get_adresa_mail(){return adresa_mail;}

        const Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania&);
        friend istream& operator>>(istream&, Abonat_Skype_Romania&);
        friend ostream& operator<<(ostream&, const Abonat_Skype_Romania&);

};

class Abonat_Skype_Extern:public Abonat_Skype
{
    protected:

      char* tara;

    public:

        char* get_tara(){ return tara; }
        void set_tara(char *denumire)
                {
                    int nr = strlen(denumire);
                    delete[] tara;
                    tara = new char[ nr + 1];
                    for(int i = 0; i < nr ; i++ )
                        tara[i] = denumire[i];
                    tara[nr] = NULL;
                }

        Abonat_Skype_Extern();
        Abonat_Skype_Extern(char*, char*, char*, int i, char*);
        Abonat_Skype_Extern (const Abonat_Skype_Extern&);
        ~Abonat_Skype_Extern(){ delete [] tara; nr_obiecte--; }

        const Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern&);
        friend istream& operator>>(istream&, Abonat_Skype_Extern&);
        friend ostream& operator<<(ostream&, const Abonat_Skype_Extern&);

};

class Agenda
{
    Abonat *abonati[200];
    int numar_abonati;

    public:

        int get_abonati(){ return numar_abonati; }
        void set_abonati(int numar){ numar_abonati = numar; }

        Agenda();
        Agenda(int);
        Agenda(const Agenda&);
        ~Agenda(){

            for(int i = 0 ; i < numar_abonati ; i++)
                delete abonati[i];
                }

        friend istream& operator>>(istream& , Agenda&);
        friend ostream& operator<<(ostream&, const Agenda&);
        const Agenda& operator=(const Agenda&);
        //const Abonat*& operator[](int x) const { return abonati[x]; }
        Abonat*& operator[](int x){ return abonati[x]; }
};
#endif // CLASE_H_INCLUDED
