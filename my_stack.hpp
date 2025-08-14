
template <typename T>
class Node
{
public:
    T *data;
    Node *prev;
    Node() = default;
    // template <typename U>
    // Node(U&& el)
    // {
    //     cout << "\t\tctor Node(U&& el)\n";
    //     void *mem = new char[sizeof(T)];
    //     data = new (mem) T(el);
    // }
};

template <typename T>
class My_Stack
{
private:
    using element_type = T;
    Node<T> *head;


public:
    My_Stack()
    {
        head = new Node<T>;
        head->data = nullptr;
        head->prev = nullptr;
    }
    My_Stack(T &new_el) : My_Stack()
    {
        Node<T> *tmp = new Node<T>;
        tmp->data = new T{new_el};
        tmp->prev = head;
        head = tmp;
    }

    void push(T &new_el)
    {
        cout << "\tpush(T& new_el)\n";
        Node<T> *tmp = new Node<T>;
        tmp->data = new T{new_el};
        tmp->prev = head;
        head = tmp;
    }

    void push(T &&new_el)
    {
        cout << "\tpush(T&& new_el)\n";
        Node<T> *tmp = new Node<T>;
        cout << "-----\n";
        tmp->data = new T(forward<T>(new_el));
        // tmp->data = new T(std::move(new_el)); // DO THE SAME ??
        cout << "-----\n";

        tmp->prev = head;
        head = tmp;
    }

    template <typename U, typename... TYPES>
    void push(U&& first_el, TYPES&&... Args)
    {
        cout << "\tpush(TYPES... Args) first el = "<< first_el << "" << "\n";
        push(forward<U>(first_el));
        cout << "1 push(TYPES... Args)\n";
        // if (sizeof...(Args) > 0 ){
        //     cout << "------ 2 push(TYPES... Args)\n";
        //     push(Args...);
        // }
        push(forward<TYPES>(Args)...);
        cout << "------ end push(TYPES... Args)\n";
    }

    template <typename... TYPES> //
    void push_emplace(TYPES... Args)
    {
        cout << "\tpush_emplace()\n";
        Node<element_type> *tmp = new Node<element_type>;
        cout << "-----\n";
        tmp->data = new element_type(Args...);
        cout << "-----\n";
        tmp->prev = head;
        head = tmp;
    }

    template <typename... TYPES>
    void push_emplace_placement_new(TYPES... Args)
    {
        cout << "push_emplace_placement_new()\n";
        Node<element_type> *tmp = new Node<element_type>;
        void *mem = new char[sizeof(element_type)];
        tmp->data = new (mem) element_type(Args...);
        cout << "  new placemet el = " << *(tmp->data) << endl;
        tmp->prev = head;
        head = tmp;
    }

    // T pop() // realization without delete of stack el.. ?? its valid ??
    // {
    //     Node<T> * tmp = head;
    //     head = head->prev;
    //     return *tmp->data;
    // }
    T pop() // ??
    {
        if (!head->data)
        {
            cout << "error - stack's empty\n";
            throw std::runtime_error("error - stack's empty");
        }
        else
        {
            // MAYBE NRVO ??
            // T ret_el(move(*head->data));
            Node<T> *tmp = head;
            cout << " pop() \n";
            head = head->prev;
            T ret_el(move(*tmp->data));
            delete tmp;
            return ret_el;
        }
    }
    void print_stack()
    {
        Node<T> *it = head;
        cout << "start stack: \n";
        while (it->data != nullptr)
        {
            cout << "el of stack = " << *it->data << " | it = " << (void *)it << " | it->prev = " << (void *)it->prev << endl;
            it = it->prev;
        }
        cout << "end of stack: \n\n";
    }

};
