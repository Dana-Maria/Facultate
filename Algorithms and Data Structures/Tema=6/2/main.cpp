#include <iostream>

using namespace std;

struct my_priority_queue
{
    int priority;
    int value;
    my_priority_queue* next;
};

void create_priority_queue(my_priority_queue* &first_element, int number_of_elements)
{
    first_element = new my_priority_queue;
    cout<<"\nIntroduceti prioritatea primului element: ";
    cin>>first_element->priority;
    cout<<"Introduceti valoarea primului element: ";
    cin>>first_element->value;
    first_element->next = NULL;
    my_priority_queue* aux_first_element = first_element;
    for (int index = 1; index < number_of_elements; index++)
    {
        my_priority_queue* new_element = new my_priority_queue; // Cream un nou element

        cout<<"\nIntroduceti prioritatea urmatorului element: ";
        cin>>new_element->priority; // Citim prioritatea noului element

        cout<<"Introduceti valoarea urmatorului element: ";
        cin>>new_element->value; // Citim valoarea noului element

        my_priority_queue* current_element = aux_first_element; // Pointer cu care parcurgem coada pana in momentul in care gasim
                                                                // o prioritate mai mare decat cea citita
        my_priority_queue* left_element = NULL; // Pointer in care vom retine elementul din stanga locului unde vom adauga noul element

        while (current_element && current_element->priority <= new_element->priority)
        { // Parcurgem elementele cozii pana cand gasim o prioritate mai mare decat cea a noului element sau terminam elementele

            if (current_element->next) // Daca nu ne aflam pe ultima pozitie a cozii
                if (current_element->next->priority > new_element->priority) // Daca urmatorul element are prioritatea mai mare decat noul element
                    left_element = current_element; // Elementul curent va deveni elementul din stanga pe care il vom lega de noul element de adaugat

            current_element = current_element->next; // Trecem la urmatorul element
        }

        // Daca primul element al cozii este 1 cu prioritatea 3 acesta este inserat in coada normal
        // apoi citim elementul 2 cu prioritatea 1
        // la finalul while-ului current_element va pointa catre primul element al cozii, adica pe 1
        // 1 are prioritatea mai mare decat 2 ( 3 > 1)
        // atunci noul element trebuie inserat inaintea lui 1, iar coada va arata astfel:
        // 2 (prioritatea 1) , 1 (prioritatea 3)
        // daca mai citim un element 3 cu prioritatea 2 se repeta procesul
        // current_element pointeaza la finalul while-ului pe 1 ( primul element cu prioritatea mai mare decat 2)
        // left_element va retine elementul din stanga ( 2 cu prioritatea 1)
        // 3 va fi inserat la mijloc intre cele doua elemente, iar coada va arata astfel:
        // 2 (prioritatea 1), 3 (prioritatea 2), 1 (prioritatea 3)
        // acum daca mai citim elementul 4 cu prioritatea egala cu 2 ( prioritate deja existenta in coada)
        // vom repeta parcurgerea, iar current_element va pointa pe elementul 1 ( prima prioritate mai mare decat 2)
        // left_element pointeaza pe 3 (ultimul element cu prioritatea 2 deja in coada)
        // 4 este adaugat intre cele doua elemente, iar coada arata astfel:
        // 2 (prioritatea 1), 3 (prioritatea 2), 4 (prioritatea 2), 1 (prioritatea 3)
        // in cazul unei stergeri primul element eliminat este cel mai din fata
        // adica cel cu cea mai mica prioritate ( in cazul acesta elementul 2)

        if (current_element) // Daca noul element trebuie adaugat in interiorul cozii
        {
            if (left_element) // Daca elementul nu trebuie inserat pe prima pozitie a cozii
            {
                left_element->next = new_element; // Elementul din stanga va fi legat de noul element
                new_element->next = current_element; // Noul element va fi legat de elementul curent
            }

            else{ // Daca elementul trebuie inserat pe prima pozitie a cozii

                new_element->next = current_element; // Noul element va fi legat de elementul curent care pointeaza catre prima pozitie a cozii
                aux_first_element = new_element; // Reinitializam primul element al cozii
            }

            continue; // Continuam executia for-ului fara a executa ce urmeaza dupa if
        }

        // Daca noul element trebuie adaugat la finalul cozii ( nu am intrat in instructiunea if anterioara )
        first_element->next = new_element; // Pointerul first_element va pointa catre penultimul element al cozii si va fi legat de noul element
        new_element->next = NULL; // Noul element va fi legat de nul
        first_element = new_element; // Reinitializam pointerul cu ultimul element al cozii
    }
    first_element = aux_first_element;
}

void print_priority_queue(my_priority_queue* first_element) // Functie care afiseaza coada de prioritati
{
    if (!first_element) // Daca coada este goala
    {
        cout<<"\nNu a fost introdus niciun element in coada"; // Afisam un mesaj
        return; // Oprim executarea restului functiei
    }

    my_priority_queue* current_element = first_element; // Pointer care va parcurge elementele cozii
    cout<<'\n';

    while (current_element) // Parcurgem elementele cozii
    {
        cout<<"Elementul "<<current_element->value<<" ( cu prioritatea "<<current_element->priority<<" );"<<endl; // Afisam elementul curent cu formatul
                                                                                 // ( prioritate, valoare )
        current_element = current_element->next; // Trecem mai departe in coada
    }
}

void push_priority_queue(my_priority_queue* &first_element, int priority, int element_value) // Functie care adauga un element in coada de prioritati
{
    my_priority_queue* current_element = first_element; // Pointer care retine elementul curent al cozii
    my_priority_queue* left_element = NULL; // Pointer care va retine elementul din stanga pozitiei unde va fi adaugat noul element
    my_priority_queue* aux_first_element = first_element; // Pointer care va retine primul element al cozii

    my_priority_queue* new_element = new my_priority_queue; // Cream un nou element
    new_element->priority = priority; // Ii atribuim prioritatea
    new_element->value = element_value; // Si ii atribuim valoarea

    while (current_element && current_element->priority <= priority)
    { // Ca la creare parcurgem pana intalnim o prioritate mai mare decat cea care trebuie adaugata

        if (current_element->next) // Daca nu ne aflam pe ultima pozitie
            if (current_element->next->priority > priority) // Daca pe pozitia urmatoare trebuie sa inseram elementul
                left_element = current_element; // Pointerul stanga ia valoarea pointerului curent

        current_element = current_element->next; // Trecem mai departe in coada
    }

    // Aceeasi logica precum la functia de creare a cozii
    // Cautam primul element cu prioritatea mai mare decat cea a elementului pe care dorim sa il inseram
    // In partea de jos luam fiecare caz particular in parte, adica:
    // inserarea pe prima pozitie, pe ultima pozitie sau in interiorul cozii

    if (current_element) // Elementul trebuie inserat in interiorul cozii
    {
            if (left_element) // Daca elementul nu trebuie inserat pe prima pozitie a cozii
            {
                left_element->next = new_element; // Elementul din stanga va fi legat de noul element
                new_element->next = current_element; // Noul element va fi legat de elementul curent
            }

            else{ // Daca elementul trebuie inserat pe prima pozitie a cozii

                new_element->next = current_element; // Noul element va fi legat de elementul curent care pointeaza catre prima pozitie a cozii
                aux_first_element = new_element; // Reinitializam primul element al cozii
            }

        first_element = aux_first_element; // Reinitializam valoarea pointerului first_element
        return; // Oprim executarea functiei
    }

    // Elementul trebuie inserat la capatul cozii ( nu am intrat in if-ul anterior )

    my_priority_queue* last_element = first_element; // Pointer care va retine ultimul element al cozii
    while (last_element->next) // Parcurgem coada pana la ultimul element
        last_element = last_element->next; // Ne deplasam mai departe in coada

    last_element->next = new_element; // last_element ( care pointeaza pe ultimul element ) este legat la dreapta de noul element
    new_element->next = NULL; // Legam noul element de nul

    first_element = aux_first_element; // Reinitializam valoarea pointerului first_element
}

void pop_priority_queue(my_priority_queue* &first_element) // Functie pentru stergerea elementului din fata cozii
{
    my_priority_queue* next_element = first_element->next; // Pointer care retine al doilea element al cozii
    delete first_element; // Stergem primul element
    first_element = next_element; // Reinitializam primul element al cozii
}

int main()
{
        int n,x,y;
        my_priority_queue* first_node;
        my_priority_queue* last_node;
        cout<<"Cate elemente va contine coada?"<<endl;
        cin>>n;
        create_priority_queue(first_node,n);
        print_priority_queue(first_node);
        cout<<endl<<"Se va adauga elementul: ";
        cin>>x;
        cout<<"Cu prioritatea: ";
        cin>>y;
        push_priority_queue(first_node, y, x);
        print_priority_queue(first_node);
        cout<<endl<<"Se va elimina elementul de pe prima pozitie: ";
        pop_priority_queue(first_node);
        print_priority_queue(first_node);
        return 0;
}

