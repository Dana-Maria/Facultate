#include <iostream>

using namespace std;

struct Punct
{
    double x, y;
};

Punct p[5], acoperire_convexa[5];
int nr_puncte; // nr punctelor din acoperirea convexa

int orientare(Punct p, Punct q, Punct r)
{
    int n = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (n == 0)
        return 0;

    else if (n > 0)
        return 1;

    else
        return 2;
}

void acoperire()
{
    /* Cautam punctul cel mai din stanga, incepand de la punctul 0*/
    int cel_mai_din_stanga = 0;
    for (int i = 1; i < 4; i++)
        if (p[i].x < p[cel_mai_din_stanga].x)
            cel_mai_din_stanga = i;

    /* Initializam pivotul cu punctul cel mai din stanga si parcurgem punctele pana cand revenim la valoarea initiala */
    int pivot = cel_mai_din_stanga;
    do
    {
        /* Adaugam pivotul in acoperirea convexa */
        acoperire_convexa[nr_puncte] = p[pivot];
        nr_puncte++;

        int curent = pivot + 1; // luam urmatorul punct

        /* daca pivot == 3 => curent = 4 => am depasit punctele initiale (care sunt de la 0 la 3)
        - in cazul asta, inseamna ca trebuie sa revenim la primul punct, ca nu mai avem alta solutie */
        if (curent == 4)
            curent = 0;

        for (int i = 0; i < 4; i++)
        {
            /* Daca in i facem viraj la dreapta, il updatam pe curent */
            if (orientare(p[pivot], p[i], p[curent]) == 2)
                curent = i;
        }

        /* Acum curent e punctul care va deveni pivot */
        pivot = curent;

    } while (pivot != cel_mai_din_stanga);
}

/* Functia imi intoarce pozitia pe care se afla punctul a in vectorul de puncte p */
int gaseste_punct(Punct a)
{
    for (int i = 0; i < 4; i++)
        if (p[i].x == a.x && p[i].y == a.y)
            return i;

    return -1; // daca nu l-am gasit
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Dati punctul: " << endl << "x= ";
        cin >> p[i].x;
        cout << "y= ";
        cin >> p[i].y;
        cout << endl;
    }

    if (orientare(p[0], p[1], p[2]) == 0 && orientare(p[1], p[2], p[3]) == 0)
    {
        /* In cazul acesta, nu conteaza cum formam multimile I si J atata timp cat nu au un punct comun */
        cout << "\nPunctele sunt coliniare.\nI = {A1, A2}\nJ = {A3, A4}\n";
        return 0;
    }

    acoperire(); // construim acoperirea

    if (nr_puncte == 3)
    {
         cout << "\nPunctele formeaza un triunghi.\nI = {A";

         int aparitii[5] = {0};
         for (int i = 0; i < 3; i++)
         {
             int poz = gaseste_punct(acoperire_convexa[i]); // aflam pozitia punctului in vectorul initial
             aparitii[poz] = 1;

             if (i == 2)
                cout << poz + 1 << "}\n";

             else
                cout << poz + 1 << ", A";
         }

         /* Vedem ce punct nu a aparut in acoperire si il afisam */
         for(int i = 0; i < 4; i++)
            if(aparitii[i] == 0)
             {
                 cout << "J = {A" << i + 1 << "}\n";
                 break;
             }
    }

    else
        if(nr_puncte == 4)
        {
            cout << "\nPunctele formeaza un patrulater convex.\nI = {A" << gaseste_punct(acoperire_convexa[1]) + 1;
            cout << ", A" << gaseste_punct(acoperire_convexa[3]) + 1 << "}\nJ = {A";
            cout << gaseste_punct(acoperire_convexa[0]) + 1 << ", A" << gaseste_punct(acoperire_convexa[2]) + 1 << "}\n";
        }
    return 0;
}

