#include <iostream>

using namespace std;

class Node 
{
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class List 
{
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void PrintValuesInList() const 
    {
        cout << endl << "Values in the list: ";

        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    void PushBack(int value) 
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) 
            current = current->next;
        
        current->next = newNode;
        
    }

    Node* getHead()
    {
        return head;
    }

    // получить последнее значение, или -1 если лист пустой (head == nullptr)
    int GetLastValue();

    // стереть ноду с таким то значением, вернуть false если такой элемент не найден
    // true иначе, учесть что это может быть как и первый так и последний элемент
    bool EraseElementByValue(int valueToFind);

    // стереть ноду на которую указывает наш пойнтер, вернуть false если такой элемент не найден
    // true иначе, учесть что pointer может указывать как и на первый так и последний элемент
    bool EraseElementByPointer(Node* pointer);

    // получить указатель на Node со значением targetValue, nullptr если такой отсутствует
    Node* GetNodeByValue(int targetValue);

    // **опционально
    void PushTop(int newValue); // вставить элемент в самое начало (обновить head)


};

int main() 
{
    List myList;
    myList.PushBack(1);
    myList.PushBack(3);
    myList.PushBack(5);

    myList.PrintValuesInList();

    cout << endl;

    cout << "Last value: " << myList.GetLastValue() << endl;

    myList.EraseElementByValue(5);
    myList.PrintValuesInList();
    myList.EraseElementByValue(4);
    myList.PrintValuesInList();

    cout << endl;

    myList.EraseElementByPointer(myList.getHead());
    myList.PrintValuesInList();
    cout << endl;

    myList.PushBack(1);
    myList.PushBack(3);
    myList.PushBack(5);

    myList.PrintValuesInList();

    myList.EraseElementByPointer(myList.GetNodeByValue(5));
    myList.PrintValuesInList();
    cout << endl;

    myList.PushTop(5);
    myList.PrintValuesInList();






    return 0;
}
//------------------------------------------------------------

int List::GetLastValue() 
{
    if (!head) 
        return -1; 
    

    Node* current = head;
    while (current->next) 
        current = current->next;
    
    return current->value;
}
//------------------------------------------------------------

bool List::EraseElementByValue(int eValue) 
{
    if (!head) 
        return false;  // Пустой список
    

    Node* current = head;
    Node* prev = nullptr;

    while (current) 
    {
        if (current->value == eValue) 
        {
            if (prev) 
                prev->next = current->next;            
            else 
                head = current->next;
            
            
            delete current;
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false; 
}
//------------------------------------------------------------

bool List::EraseElementByPointer(Node* ptr)
{
    if (!head || !ptr)
        return false;


    if (ptr == head)
    {
        head = ptr->next;
        delete ptr;
        return true;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current)
    {
        if (current == ptr)
        {
            prev->next = current->next;
            delete current;
            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}
//------------------------------------------------------------

Node* List::GetNodeByValue(int tValue) 
{
    if (!head) 
        return nullptr;  // Пустой список
    

    Node* current = head;

    while (current) 
    {
        if (current->value == tValue) 
        {
            return current;
        }

        current = current->next;
    }

    return nullptr; 
}
//------------------------------------------------------------

void List::PushTop(int newValue) 
{
    Node* newNode = new Node(newValue);

    newNode->next = head;
    head = newNode;
}




