#include <iostream>
#include <string>
using namespace std;

#define MAX_LIST_SIZE 100

struct Element
{
    int number;
    string string;
};

class List
{
private:
    int lastIndex;
    Element a[MAX_LIST_SIZE];

public:
    List()
    {
        lastIndex = -1;
    }

    int end()
    {
        return lastIndex + 1;
    }

    int error(const string &s)
    {
        cout << "Error: " << s << endl;
        exit(0);
    }

    int empty()
    {
        lastIndex = -1;
        return end();
    }

    bool isEmpty()
    {
        return lastIndex == -1;
    }

    int first()
    {
        if (isEmpty() == false)
            return 0;
        else
            return end();
    }

    int last()
    {
        return lastIndex;
    }

    int getNext(int w)
    {
        if (w == last())
            return end();
        else if (w == end())
            error("can't find next after end of list");
        else
            return w + 1;
    }

    int getPrevious(int w)
    {
        if (w != first())
            return w - 1;
        else
        {
            error("can't find previous before first element of list");
            return w;
        }
    }

    List *insert(const Element &e, int w)
    {
        int i;
        if (lastIndex >= MAX_LIST_SIZE - 1)
            error("Can't insert - list is full");
        else if (w > lastIndex + 1 || w < 0)
            error("Position does not exist");
        else
        {
            // Insert element and shift all elements after w to the right
            for (i = lastIndex; i >= w; i--)
                a[i + 1] = a[i];
            a[w] = e;
            lastIndex = lastIndex + 1;
            return this;
        }
    }

    List *remove(int w)
    {
        int i;
        if (w > lastIndex || w < 0)
            error("Position does not exist");
        else
        {
            // Remove element and shift all elements after w to the left
            lastIndex = lastIndex - 1;
            for (i = w; i <= lastIndex; i++)
                a[i] = a[i + 1];
            return this;
        }
    }

    Element retrieve(int w)
    {
        if (w < 0 || w > lastIndex)
            error("Position does not exist");
        else
            return a[w];
    }

    int print()
    {
        int w;
        Element e;
        cout << "Contents of list:" << endl;
        w = first();
        while (w != end())
        {
            e = retrieve(w);
            cout << e.number << " " << e.string << endl;
            w = getNext(w);
        }
        cout << "---" << endl;
        return 0;
    }

    void assignElementValues(Element *e, int number, const string &s)
    {
        e->string = s;
        e->number = number;
    }
};

int main()
{
    List list;
    int w;
    Element e;

    list.empty();
    list.print();

    list.assignElementValues(&e, 1, "String A");
    w = list.first();
    list.insert(e, w)->print();

    list.assignElementValues(&e, 2, "String B");
    list.insert(e, w)->print();

    list.assignElementValues(&e, 3, "String C");
    list.insert(e, list.last())->print();

    list.assignElementValues(&e, 4, "String D");
    w = list.getNext(list.last());
    list.insert(e, w)->print();

    w = list.getPrevious(w);
    list.remove(w)->print();

    return 0;
}

// Coded with ❤ by Aimal Khan.
