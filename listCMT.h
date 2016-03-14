#ifndef LIST_H
#define LIST_H

using namespace std;

template<typename T>
class List {
private:

    T* array;
    int capacity;
    int size;

    class Iterator{

    private:
        T* link; //"legatura" dintre iterator si un vector List
        int poz; //"pozitia curenta a iteratorului"

    public:

        Iterator() //Constructor
        {
            poz=0;
        }

        Iterator(T* array, int poz) //Constructor
        {
            //Se creeaza legatura intre iterator si lista, de la o pozitie specificata

            this->link=array;
            this->poz=poz;
        }

        T& operator *()
        {
            return link[poz];
        }

        T* operator ->()
        {
            return &link[poz];
        }

        Iterator operator ++()
        {
            poz++;
            return Iterator(link,poz);
        }

        Iterator operator ++(int)
        {
            Iterator aux=Iterator(link,poz);
            poz++;
            return aux;
        }

        void operator =(const Iterator& itr)
        {
            link=itr.link;
            poz=itr.poz;
        }

        int operator !=(const Iterator& itr)
        {
            if(link!=itr.link)
            {
                return 1;
            }

            if(poz!=itr.poz)
            {
                return 1;
            }

            return 0;
        }
    };

public:

    typedef Iterator iterator;


    List() //Constructor
    {
        this->capacity=1;
        this->size=0;
        this->array=new T[capacity];
    }

    List(int capacity) //Constructor
    {
        this->capacity=capacity;
        this->size=0;
        this->array=new T[capacity];
    }

    ~List() //Destructor
    {
        delete[] array;
    }

    int get_size()
    {
        return this->size;
    }

    int get_capacity()
    {
        return this->capacity;

    }

    T get_element(int index)
    {
        return this->array[index];
    }

    void insert(const T& element, unsigned index)
    {
        if(size+1<index) //Daca indexul nu este valid
        {
            cout<<"Operatie invalida"<<endl;
        }
        else
        {
            int i;

            if(size==capacity) //Daca vectorul este plin
            {
                T* aux=new T[++capacity];

                size++;

                for(i=0;i<index;i++)
                {
                    aux[i]=array[i];
                }

                aux[index]=element;

                for(i=index+1;i<size;i++)
                {
                    aux[i]=array[i-1];
                }

                delete[] array;

                array=aux;
            }
            else //Daca exista spatiul necesar adaugarii unui nou element
            {
                for(i=size;i>index;i--)
                {
                    array[i]=array[i-1];
                }
                array[index]=element;
                size++;
            }
        }
    }

    void remove(unsigned index)
    {
        if(index>=size || size==0) //Daca indexul nu este valid sau daca vectorul este gol
        {
            cout<<"Operatie invalida"<<endl;
        }
        else
        {
            int i;

            for(i=index;i<size-1;i++)
            {
                array[i]=array[i+1];
            }

            size--;
        }
    }

    void push_back(const T& element)
    {
        int i;

        if (size==capacity) //Daca vectorul este plin
        {
            T* aux;
            aux=new T[++capacity];

            for(i=0;i<size;i++)
            {
                aux[i]=array[i];
            }

            delete[] array;
            array=aux;
        }

        array[size]=element;
        size++;
    }

    void push_front(const T& element)
    {
        int i;

        if (size==capacity) //Daca vectorul este plin
        {
            T* aux;
            aux=new T[++capacity];

            for(i=0;i<size;i++)
            {
                aux[i+1]=array[i];
            }

            delete[] array;
            array=aux;
        }
        else
        {
            for(i=size;i>=0;i--)
            {
                array[i]=array[i-1];
            }
        }

        array[0]=element;
        size++;
    }

    iterator begin()
    {
        return Iterator(this->array,0);
    }

    iterator end()
    {
        return Iterator(this->array,this->size-1);
    }

};

#endif
