#include <iostream>
#include <random>
#include "Queue.hpp"

void separator_lines()
{
    std::cout << std::endl;
    for (size_t i = 0; i < 50; i++)
        std::cout << "--";
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T, size_t N>
void printArray(const T (&arr)[N]) {
    std::cout << "[ ";
    for (size_t i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << " ]" << std::endl;
}

/*     INT     */
void test_enqueue_e_dequeue_EASY()
{
    // Creazione della queue di interi
    Queue<int> q;

    std::cout << "Test enqueue e dequeue EASY:\n";

    // Aggiunta di elementi alla coda
    q.enqueue(10);
    std::cout << q << std::endl;
    q.enqueue(20);
    std::cout << q << std::endl;
    q.enqueue(30);
    std::cout << "Elementi inseriti con successo.\n";
    std::cout << q << std::endl;

    // Tentativo di rimuovere elementi
    std::cout << "\nTest dequeue:\n";
    q.dequeue();
    std::cout << "1 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "2 rimozione: " << q << '\n';
    q.dequeue();
    std::cout << "3 rimozione: " << q << '\n';

    q.dequeue();
    // Tentativo di rimuovere da una coda vuota
    std::cout << "coda vuota: " << q << '\n';

    separator_lines();
}

void test_enqueue_e_dequeue_HARD()
{
    std::cout << "******** Test ENQUEUE e DEQUEUE randomici, su elementi randomici nella lista di interi ********" << std::endl;

    long n_volte = 3000;
    Queue<int> q;

    std::random_device rd;  // Generatore di entropia hardware (se disponibile)
    std::mt19937 gen(rd()); // Inizializza il generatore con un seme casuale

    int scelta, numeroCasuale;
    std::uniform_int_distribution<int> distribuzione(1, 100);

    std::cout << q << "\n"
              << std::endl;
    for (long i = 1; i < n_volte; i++)
    {
        // numeri randomici
        numeroCasuale = distribuzione(gen);
        scelta = distribuzione(gen);

        std::cout << i << ". "; // intestazione

        if ((scelta % 2) == 0)
        {
            q.enqueue(numeroCasuale);
            std::cout << "ENQUEUE, SCELTA " << scelta << ",numero: " << numeroCasuale << std::endl;
        }
        else
        {
            q.dequeue();
            std::cout << "DEQUEUE, SCELTA " << scelta << ",numero: " << numeroCasuale << std::endl;
        }
        std::cout << q << "\n"
                  << std::endl;
    }

    separator_lines();
}

void test_copy_construtor()
{
    Queue<int> q;

    q.enqueue(12);
    q.enqueue(146);

    std::cout << "stampa di q: " << q << std::endl;

    Queue<int> p = q;

    std::cout << "copia fatta!" << std::endl;
    ;

    std::cout << "stampa di p: " << p << std::endl;

    p.enqueue(1);
    q.dequeue();
    std::cout << "aggiunta elemento a p" << std::endl;
    std::cout << "stampa di q: " << q << std::endl;
    std::cout << "stampa di p: " << p << std::endl;

    separator_lines();
}

void test_metodi_fondamentali_int()
{
    std::cout << "******** Test metodi fondamentali della lista di interi ********" << std::endl;

    Queue<int> q; // ctor default

    q.enqueue(5); // enqueue
    q.enqueue(8);
    q.enqueue(1);
    q.enqueue(4);

    std::cout << "Stampa di q dopo inserimenti:" << std::endl;
    std::cout << q << std::endl; // operator<<

    Queue<int> q2(q); // cctor

    std::cout << "Stampa di q2 dopo copy constructor:" << std::endl;
    std::cout << q2 << std::endl; // operator<<

    Queue<int> q3;

    q3 = q; // operator=

    std::cout << "Stampa di q3 dopo assegnamento:" << std::endl;
    std::cout << q3 << std::endl; // operator<<

    //lettura elementi
    std::cout << "elemento più vecchio di q: " << q.read_first() << std::endl; //old
    std::cout << "elemento più recente di q: " << q.read_last() << std::endl;//recent

    separator_lines();
} // ~Queue()



void test_iter_ctor(){

    std::cout << "******** Test costruttore tramite due iteratori ********" << std::endl;
    
    int a[5] = {20,10,5,100,80};

    Queue<int> q(a,a+5); //ctor iterator

    std::cout << "stampa array: "; printArray(a);
    std::cout << "stampa queue: " << q << std::endl;

    separator_lines();
}
void test_read_write(){
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;
    int a[5] = {1,2,3,4,5};
    Queue<int> q(a,a+5);
    
    std::cout << "q: " << q << std::endl;    
    q.read_first();
    q.read_last();
    q.write_first(5);
    q.write_last(10);
    std::cout << "q: " << q << std::endl;
    
    std::cout << "******** Test azioni di lettura su CODA VUOTA ********" << std::endl;
    Queue<int> q_empty;

    std::cout << "q_empty: " << q_empty << std::endl;
    q_empty.read_first();
    q_empty.read_last();
    q_empty.write_first(5);
    q_empty.write_last(5);
    std::cout << "q_empty: " << q_empty << std::endl;

    separator_lines();    
}
void test_find(){
    std::cout << "******** Test ricerca elemento nella CODA ********" << std::endl;
    
    int a[5] = {1,2,3,4,5};
    Queue<int> q(a,a+5);
    std::cout << "q: " << q << std::endl;

    
    std::cout << "->5 in q: " << q.find(5) << std::endl;
    std::cout << "->9 in q: " << q.find(9) << std::endl;


    Queue<int> q_empty;    
    std::cout << "q_empty: " << q_empty << std::endl;
    
    std::cout << "->5 in q_empty: " << q_empty.find(5) << std::endl;
    std::cout << "->9 in q_empty: " << q_empty.find(9) << std::endl;

    separator_lines();
}
/*    STRING    */


void test_read_write_s(){
    std::cout << "******** Test azioni di lettura su CODA ********" << std::endl;

    std::string a[3] = {"testa","corpo","coda"};
    //Queue<std::string> q(a,a+3); //iter ctor
    Queue<std::string> q_empty;

    q_empty.read_first();
/*
    std::cout << "queue: " << q << std::endl;
    std::cout << "elemento più vecchio(head): " << q.read_first() << std::endl;
    std::cout << "elemento più recente(tail): " << q.read_last() << std::endl;

    std::cout << "******** Test azioni di scrittura su CODA ********" << std::endl;
    std::cout << "primo elemento -> banana" << std::endl;
    std::cout << "ultimo elemento -> mela" << std::endl;

    q.write_first("banana");
    q.write_last("mela");
    std::cout << "queue: " << q << std::endl;*/
    
    separator_lines();
}

/*    STRUCT    */

int main()
{

    // test_enqueue_e_dequeue_EASY();
    //test_enqueue_e_dequeue_HARD();
    // test_copy_construtor();
    // test_metodi_fondamentali_int();
    // test_read_write();
    test_find();


    return 0;
}
