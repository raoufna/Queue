#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <ostream>
#include <cassert>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node *next;

        Node() : next(nullptr) {}

        Node(const T &v, Node *n = nullptr) : value(v), next(n) {}
    };

    Node *_head;
    Node *_tail;
    unsigned int _size;

public:
    Queue() : _head(nullptr), _tail(nullptr), _size(0) {}

    template <typename IterT>
    Queue(IterT b, IterT e) : _size(0), _head(nullptr), _tail(nullptr)
    {
        try
        {
            while (b != e)
            {
                enqueue(static_cast<T>(*b));
                ++b;
            }
        }
        catch (...)
        {
            clear();
            throw;
        }
    }

    /* copy constructor*/
    Queue(const Queue &other)
        : _head(nullptr), _tail(nullptr), _size(0)
    {

        Node *h = other._head;

        // Cicliamo sui nodi di other e mano a mano
        // aggiungiamo un valore dentro this.
        // La new può fallire. Per questo
        // dobbiamo gestire l'eventuale eccezione che si
        // genera con un blocco try/catch
        try
        {
            while (h != nullptr)
            {
                enqueue(h->value);
                h = h->next;
            }
        }
        catch (...)
        {
            // Se c'e' un problema, svuotiamo la lista e rilanciamo
            // l'eccezione
            clear();
            throw;
        }
    }

    Queue &operator=(const Queue &other)
    {

        if (this != &other)
        {
            Queue temp(other);

            std::swap(this->_head, temp._head);
            std::swap(this->_tail, temp._tail);
            std::swap(this->_size, temp._size);
        }

        return *this;
    }

    ~Queue()
    {
        //std::cerr << "Distruttore chiamato." << std::endl;
        clear();
        //std::cerr << "Distruttore terminato." << std::endl;
    }

    bool isEmpty() const { return _size == 0; }

    void dequeue()
    {
        // se la Queue è vuota, fermiamo subito.
        if (_size == 0)
        {
            return;
        }

        Node *temp = _head;
        _head = _head->next;
        _size--;

        delete temp;
        temp = nullptr;

        if (!_head)
        {
            _tail = nullptr;
        }
        
    }

    void enqueue(const T &value)
    {
        try{
            Node *temp = new Node(value);

            // se la Queue è vuota
            if (_size == 0)
            {
                _head = temp;
                _tail = temp;
            }
            else
            {
                _tail->next = temp;
                _tail = _tail->next;
            }

            _size++;
        }catch(...){
            clear();
            throw;
        }
    }

    void clear() {
        Node *curr = _head;
        Node *temp = nullptr;
        while(curr != nullptr) {
          temp = curr->next;
          delete curr;
          curr = temp;
        }
        _head = nullptr;
        _tail = nullptr;
        _size = 0;
    }
    

    unsigned int getSize() const { return _size; }

    T read_first() const
    {   
        if (this->isEmpty())
        {
            std::cout << "IMPOSSIBILE LEGGERE PRIMO ELEMENTO: ";
            std::cout << "La coda è vuota!" << std::endl;
            return T();
        }
        return _tail->value;
        
    }

    T read_last() const
    {        
        if (this->isEmpty())
        {
            std::cout << "IMPOSSIBILE LEGGERE ULTIMO ELEMENTO: ";
            std::cout << "La coda è vuota!" << std::endl;
            return T();
        }
        return _tail->value;
    }

    bool write_first(const T &value)
    {
        if (this->isEmpty())
        {
            std::cout << "IMPOSSIBILE MODIFICARE PRIMO ELEMENTO: ";
            std::cout << "La coda è vuota!" << std::endl;
            return false;
        }
        _head->value = value;
        return true;
    }

    bool write_last(const T &value)
    {   
        if (this->isEmpty())
        {
            std::cout << "IMPOSSIBILE MODIFICARE ULTIMO ELEMENTO: ";
            std::cout << "La coda è vuota!" << std::endl;
            return false;
        }
        _tail->value = value;
        return true;
    }

    bool find(const T& value) const{
        Node *curr = _head;

        while (curr != nullptr)
        {
            if(curr->value == value) return true;
            curr = curr->next;
        }
        
        return false;
        
    }







    // Definizione della classe const_iterator (sola lettura)
    class const_iterator
    {
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;

        const_iterator(Node *p = nullptr) : current(p) {}

        const_iterator(const const_iterator &other) : current(other.current) {}

        const_iterator &operator=(const const_iterator &other)
        {
            current = other.current;
            return *this;
        }

        ~const_iterator() = default;

        reference operator*() const
        {
            assert(current != nullptr && "Dereferenziamento di un iteratore nullo");
            return current->value;
        }

        pointer operator->() const
        {
            assert(current != nullptr && "Accesso a membro di un iteratore nullo");
            return &(current->value);
        }

        const_iterator operator++(int)
        {
            assert(current != nullptr && "Incremento di un iteratore nullo");
            const_iterator temp = *this;
            current = current->next;
            return temp;
        }

        const_iterator &operator++()
        {
            assert(current != nullptr && "Incremento di un iteratore nullo");
            current = current->next;
            return *this;
        }

        bool operator==(const const_iterator &other) const
        {
            return current == other.current;
        }

        bool operator!=(const const_iterator &other) const
        {
            return current != other.current;
        }

    private:
        const Node *current;
        friend class Queue;
    };

    // Ritorna l'iteratore const all'inizio della sequenza dati
    const_iterator begin() const
    {
        return const_iterator(_head);
    }

    // Ritorna l'iteratore const alla fine della sequenza dati
    const_iterator end() const
    {
        return const_iterator(nullptr);
    }


    
    friend std::ostream &operator<<(std::ostream &os,
                            const Queue<T> &queue)
    {

        typename Queue<T>::const_iterator i, ie;

        os << "[ ";
        for (i = queue.begin(), ie = queue.end(); i != ie; ++i)
        {
            os << *i << " ";
        }
        os << "]";
        os << " size: " << queue.getSize();
        return os;

        return os;
    }
}; //Queue
#endif