#include <stdio.h>
#include <iostream>

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};

class LinkedList
{
public:
    LinkedList() : head(nullptr)
    {
    }

    ~LinkedList()
    {
        while (this->head != nullptr)
        {
            auto elem = this->head;
            this->head = this->head->next_;
            delete elem;
        }
    }

    void PushBack(int value)
    {
        auto node = new LinkedListNode(value);

        node->next_ = this->head;
        this->head = node;
    }

    void Reverse()
    {
        if (this->head == nullptr)
        {
            return;
        }

        auto first = (LinkedListNode*)nullptr;
        auto second = this->head;

        while (second != nullptr)
        {
            auto aux = second->next_;
            second->next_ = first;
            first = second;
            second = aux;
        }

        this->head = first;
    }

    void Print()
    {
        for (auto iter = head; iter != nullptr; iter = iter->next_)
        {
            std::cout << iter->intValue_ << " ";
        }
        std::cout << std::endl;
    }

    const LinkedListNode* GetHead()
    {
        return this->head;
    }

private:

    LinkedListNode* head;
};

int main(void)
{
    LinkedList list;

    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    list.Print();

    list.Reverse();

    list.Print();

    getchar();

    return 0;
}
