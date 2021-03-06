#include <iostream>


using namespace std;

struct node{ // Declararea listei dublu inlantuite

    int value;
    node *next, *prev;
};

void display_info() // Functie care afiseaza meniul problemei
{
    cout<<"\n1) Adaugare la inceputul listei";
    cout<<"\n2) Adaugare la sfarsitul listei";
    cout<<"\n3) Adaugare in interiorul listei";
    cout<<"\n4) Afisarea in ordine";
    cout<<"\n5) Afisarea in ordine inversa";
    cout<<"\n6) Stergere (numar de ordine)";
    cout<<"\n7) Stergere (valoare)";
    cout<<"\n\n0) Iesire";
}

void read_number_of_elements(int &number_of_elements)
{
    cout<<"Introduceti numarul elementelor din lista: ";
    cin>>number_of_elements;
}

void create_list(node* &first_node, node* &last_node, int number_of_elements) // Functie care creaza o lista dublu inlantuita
{
    first_node = new node; // Cream primul nod al listei

    cout<<"\nPrimul element al listei este: ";
    cin>>first_node->value; // Citim informatia din primul nod al listei

    first_node->next = NULL; // Legam primul nod de nul in partea dreapta
    first_node->prev = NULL; // Legam primul nod de nul in partea stanga

    node* aux_first_node = first_node; // Pointer in care retinem valoarea din primul nod
    for (int index = 1; index < number_of_elements; index++) // Citim restul elementelor
    {
        node* new_node = new node; // Cream un nou nod

        cout<<"Urmatorul element al listei este: ";
        cin>>new_node->value; // Citim informatia din noul nod creat

        first_node->next = new_node; // Legam nodul anterior de noul nod in partea dreapta
        new_node->next = NULL; // Legam noul nod de nul la dreapta
        new_node->prev = first_node; // Legam noul nod de cel precedent la stanga

        first_node = new_node; // Reinitializam nodul precedent cu valoarea noului nod adaugat
    }

    last_node = first_node; // Pointerul first_node se va afla pe ultimul nod al listei la finalul ciclului
    first_node = aux_first_node; // Reinitializam pointerul first_node cu primul nod al listei
}

void print_list(node* given_node, int type_of_navigation) // Functie care afiseaza lista dublu inlantuita in functie de modul de parcurgere ales
{
    node* current_node = given_node; // Pointer catre nodul curent al listei
    cout<<'\n';

    while(current_node) // Parcurgem lista
    {
        cout<<current_node->value<<" "; // Afisam informatia din nodul curent
        current_node = type_of_navigation == 1 ? current_node->next : current_node->prev; // Pointerul curent va avansa spre stanga sau dreapta
                                                                                          // in functie de tipul de parcurgere ales
                                                                                          // 1 - parcurgere obisnuita
                                                                                          // altfel - parcurgere inversa
    }
}

void add_beginning(node* &first_node, int node_info) // Functie care adauga un element la inceputul listei
{
    node* new_node = new node; // Cream noul nod
    new_node->value = node_info; // Initializam informatia din noul nod

    new_node->next = first_node; // Legam noul nod de anteriorul prim nod la dreapta
    new_node->prev = NULL; // In stanga il legam la nul
    first_node->prev = new_node; // Legam anteriorul prim nod la stanga cu noul nod

    first_node = new_node; // Reinitializam primul nod al listei cu noul nod adaugat
}

void add_end(node* &last_node, int node_info) // Functie care adauga un element la finalul listei
{
    node* new_node = new node; // Cream noul nod
    new_node->value = node_info; // Initializam informatia din noul nod

    new_node->next = NULL; // Legam noul nod de nul la dreapta
    new_node->prev = last_node; // si de prcedentul ultim element la stanga
    last_node->next = new_node; // Legam precedentul ultim nod de noul nod la dreapta

    last_node = new_node; // Reinitializam ultimul nod cu noul nod adaugat
}

void add_middle(node* &first_node, int node_info, int position) // Functie care adauga un elementul in interiorul listei in functie de pozitie
{
    int index = 1; // Variabila care contorizeaza pozitia curenta din lista
    node* new_node = new node; // Cream noul nod
    new_node->value = node_info; // Initializam informatia din noul nod

    node* current_left_node; // Pointer care va retine elementul din stanga pozitiei unde trebuie adaugat noul nod
    node* current_right_node = first_node; // Pointer care va retine elementul din dreapta pozitiei unde trebuie adaugat noul nod

    while (current_right_node && index != position) // Parcurgem lista pana cand ajungem pe pozitia furnizata ca parametru sau terminam lista
    {
        index++; // Incrementam variabila care contorizeaza pozitia curenta
        current_right_node = current_right_node->next; // Trecem pe urmatorul element din dreapta
    }

    // Daca lista data este: 1 2 3 5
    // pozitita pe care vrem sa adaugam este: 4
    // elementul este: 4
    // dupa iesirea din while, current_right_node va pointa pe 5
    // current_left_node este pointat pe 3
    // elementul 4 trebuie adaugat intre 3 si 5
    // in stanga lui 5 il legam pe 4 (4 <-- 5)
    // in dreapta lui 3 il legam pe 4 (3 --> 4)
    // lista arata la final: 1 2 3 4 5

    if (current_right_node) // Daca am gasit pozitia in lista
    {
        current_left_node = current_right_node->prev; // Retinem nodul din stanga

        current_left_node->next = new_node; // Legam nodul din stanga de noul nod
        new_node->prev = current_left_node; // Legam noul nod de nodul din stanga

        current_right_node->prev = new_node; // Legam nodul din dreapta de noul nod
        new_node->next = current_right_node; // Legam noul nod de nodul din dreapta
        return; // Oprim executarea functiei
    }

    cout<<"\nPozitia introdusa nu este una valida"; // Afisam mesajul in cazul in care pointerul e nul, adica nu am gasit pozitia in lista
}

void erase_element_position(node* &first_node, int position) // Functie care sterge un element din lista in functie de pozitie
{
    int index = 1; // Variabila care contorizeaza pozitia curenta din lista
    node* current_element = first_node; // Pointer catre elementul curent din lista

    while (current_element && index != position) // Parcurgem lista pana cand gasim pozitia furnizata ca parametru sau terminam elementele listei
    {
        index++; // Incrementam variabila care retine pozitia curenta din lista
        current_element = current_element->next; // Trecem pe urmatorul element din dreapta
    }

    // Daca lista arata asa: 1 2 3 4 5
    // si vrem sa stergem elementul de pe pozitia 4
    // la finalul while-ului pointerul currrent_element se va afla exact pe pozitia 4
    // atunci declaram alti 2 pointeri
    // left_element -->  3
    // right_element --> 5
    // stergem elementul 4 si refacem legaturile dintre vecinii sai
    // left_element->next = right_element (3 --> 5)
    // right_element->prev = left_element (3 <-- 5)
    // lista finala va arata asa: 1 2 3 5

    if (current_element) // Daca am gasit pozitia
    {
        node* left_element = current_element->prev; // Elementul din stanga celui care urmeaza sa fie sters
        node* right_element = current_element->next; // Elementul din dreapta celui care urmeaza sa fie sters

        delete current_element; // Stergem elementul curent

        left_element->next = right_element; // Legam elementul din stanga de cel din dreapta
        right_element->prev = left_element; // Legam elementul din dreapta de cel din stanga
        return; // Oprim executia functiei
    }

    cout<<"\nPozitia introdusa nu este valida"; // Afisam mesajul in cazul in care pointerul e nul, adica nu am gasit pozitia in lista
}

void erase_element_value(node* &first_node, int node_info) // Functie care sterge un element al listei in functie de informatia din interiorul sau
{
    node* current_element = first_node; // Pointer catre elementul curent al listei

    while(current_element && current_element->value != node_info) // Parcurgem de la stanga la dreapta elementele listei pana cand gasim valoarea cautata sau terminam elementele
    {
        current_element = current_element->next; // Trecem pe urmatorul element din dreapta
    }

    if (current_element) // Daca am gasit valoarea cautata in lista
    {
        node* left_element = current_element->prev; // Pointer catre elementul din stanga celui care urmeaza sa fie sters
        node* right_element = current_element->next; // Pointer catre elementul din dreapta celui care urmeaza sa fie sters

        delete current_element; // Stergem elementul curent

        left_element->next = right_element; // Legam elementul din stanga de cel din dreapta
        right_element->prev = left_element; // Legam elementul din dreapta de cel din stanga
        return; // Oprim executia functiei
    }

    cout<<"\nValoarea introdusa nu se afla in lista"; // Afisam mesajul in cazul in care pointerul e nul, adica nu am gasit elementul in lista
}

int main()
{
    int number_of_elements; // Numarul de elemente al listei
    int type; // Optiunea din meniu introdusa de la tastatura
    int x, position; // Variabile care vor fi folosite in interiorul instructiunii switch

    node* first_node; // Pointer catre primul nod al listei
    node* last_node; // Pointer catre ultimul nod al listei

    display_info(); // Afisam meniul
    cout<<"\nIntroduceti numarul problemei alese: ";
    cin>>type; // Citim optiunea aleasa

    read_number_of_elements(number_of_elements); // Citim numarul de elemente al listei
    create_list(first_node, last_node, number_of_elements); // Cream lista prin salvarea primei si ultimei valori din lista

    while (type) // Cat timp optiunea introdusa diferita de 0
    {
        switch (type) // Instructiune switch in functie de optiunea introdusa
        {
            case 1: // Adaugarea unui element la inceputul listei

                cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
                cin>>x; // Citim elementul care urmeaza sa fie adaugat in lista

                add_beginning(first_node, x); // Apelam functia de adaugare care salveaza modificarile facute in pointerul first_node
                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch

            case 2: // Adaugarea unui element la sfarsitul listei

                cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
                cin>>x; // Citim elementul care urmeaza sa fie adaugat in lista

                add_end(last_node, x); // Apelam functie de adaugare care salveaza modificarile facute in pointerul last_node
                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch

            case 3: // Adaugarea unui element in interiorul listei in functie de pozitie

                cout<<"\nIntroduceti elementul care urmeaza sa fie adaugat in lista: ";
                cin>>x; // Citim elementul care urmeaza sa fie adaugat in lista

                cout<<"Introduceti pozitia pe care urmeaza sa fie inserat elementul: ";
                cin>>position; // Citim pozitia pe care urmeaza sa fie inserat elementul citit

                add_middle(first_node, x, position); // Apelam functia care salveaza modificarile facute in pointerul first_node
                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch

            case 4: // Afisarea listei de la stanga la dreapta

                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch

            case 5: // Afisarea listei de la dreapta la stanga

                print_list(last_node, 0); // Afisam lista utilizand parcurgerea de tip 0, adica de la dreapta la stanga
                break; // Oprim executarea instructiunii switch

            case 6: // Stergerea unui element in functie de pozitie
                cout<<"Introduceti pozitia de pe care urmeaza sa fie sters elementul: ";
                cin>>position; // Citim pozitia pe care se afla elementul care urmeaza sa fie sters

                erase_element_position(first_node, position); // Apelam functia care salveaza modificarile facute in pointerul first_node
                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch

            case 7: // Stergerea unui element in functie de valoare
                cout<<"\nIntroduceti elementul care urmeaza sa fie sters din lista: ";
                cin>>x; // Citim informatia elementului care urmeaza sa fie sters din lista

                erase_element_value(first_node, x); // Apelam functia care salveaza modificarile facute in pointerul first_node
                print_list(first_node, 1); // Afisam lista utilizand parcurgerea de tip 1, adica de la stanga la dreapta
                break; // Oprim executarea instructiunii switch
        }

        display_info(); // Afisam din nou meniul
        cout<<"\nIntroduceti numarul problemei alese: ";
        cin>>type; // Citim optiunea introdusa de la tastatura
    }
}
