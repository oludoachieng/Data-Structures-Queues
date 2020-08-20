#include <iostream>
#include <string>
#define MaxSize 50

template <typename T>
class Queues
{
private:
    int front;
    int back;
    int Items;
    T QueueArray[MaxSize];

public:
    Queues();
    void Insert(const T& var);
    void ClearQueue();
    void PrintQueue();
    void Delete();
    void Peek()const;
 
};

template<typename T>
Queues<T>::Queues()
{
    front = -1;
    back = -1;
    Items = 0;
    std::cout << "Queue of size " << MaxSize << " is created " << std::endl << std::endl;

}

template<typename T>
void Queues<T>::Insert(const T& var)
{
    if (Items == MaxSize)
    {
        std::cout << "Queue is full" << std::endl;
        return ;
    }
    else
        if (front == -1)//for the first insersion
        {
            front++;
        }
        Items++;
        back++;
        back = back % MaxSize;
        QueueArray[back] = var;
        std::cout << QueueArray[back] << " is inserted to the queue" << std::endl;
}

template<typename T>
void Queues<T>::PrintQueue()
{
    if (Items > 0)
    {
        std::cout << " Printing queue:" << std::endl;
        for (int count = front;count <= back;count++)
            std::cout<< QueueArray[count] << std::endl;
    }
    else
        std::cout <<"Queue is empty"<< std::endl;
}

template<typename T>
void Queues<T>::ClearQueue()
{
    front = -1;
    back = -1;
    Items = 0;
    std::cout << "Queue is cleared"<< std::endl;
}

template<typename T>
void Queues<T>::Delete()
{
    
    if (Items==0)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        int TempFront = front;
        front++;
        front = front % MaxSize;
        Items--;
        std::cout<< QueueArray[TempFront]<<" is deleted"<<std::endl;
    }
}

template<typename T>
void Queues<T>::Peek() const
{
    if (Items==0)
    {
        std::cout << "Queue is Empty"<<std::endl;
      
    }
    else
        std::cout << QueueArray[front] <<" is at the front of the queue"<< std::endl;
}


int main()
{
    Queues<std::string> example;

    std::cout << "Select 0 to exit program" << std::endl;
    std::cout << "Select 1 to insert to queue" << std::endl;
    std::cout << "Select 2 to clear queue" << std::endl;
    std::cout << "Select 3 print queue" << std::endl;
    std::cout << "Select 4 to delete front of queue" << std::endl;
    std::cout << "Select 5 to peek into queue" << std::endl << std::endl;

    char input;

    while (true)
    {
        std::cin >> input;


        if (input < '0' || input> '5')
        {
            std::cout << "Select a valid input" << std::endl << std::endl;
        }



        switch (input)
        {
        case '1':
        {

            std::string insert_val;
            std::cout << "What to insert:" << std::endl;
            std::cin >> insert_val;
            example.Insert(insert_val);
            std::cout << "Select 0, 1, 2, 3, 4 or 5" << std::endl;
            break;
        }
        case '2':
        {
            example.ClearQueue();
            std::cout << "Select 0, 1, 2, 3, 4 or 5" << std::endl;
            break;
        }
        case '3':
        {
            example.PrintQueue();
            std::cout << "Select 0, 1, 2, 3, 4 or 5" << std::endl;
            break;
        }
        case '4':
        {
            example.Delete();
            std::cout << "Select 0, 1, 2, 3, 4 or 5" << std::endl;
            break;
        }
        case '5':
        {
            example.Peek();
            std::cout << "Select 0, 1, 2, 3, 4 or 5" << std::endl;
            break;
        }
        case '0':
        {
            return 0;
        }
        }

        
    }
}
