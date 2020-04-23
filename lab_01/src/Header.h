#ifndef Header_h_
#define Header_h_
#include <iostream>

using namespace std;

struct Vector
{
    int nsz;
    int* arr;
    Vector(int insz)
    {
        nsz = insz;
        arr = new int[nsz];

        for (int i = 0; i < nsz; i++)
        {
            arr[i] = 0;
        }
    };
    ~Vector()
    {
        delete[] arr;
    };
    void Vin()
    {
        for (int i = 0; i < nsz; i++)
        {
            arr[i] = rand() % 20;
        }
    };
    void Vout()
    {
        for (int i = 0; i < nsz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };
    void push(int*& arr, int& nsz, int k)
    {
        int* arrq = new int[nsz + 1];
        for (int i = 0; i < nsz; i++)
        {
            arrq[i] = arr[i];
        }
        arrq[nsz] = k;
        nsz++;
        delete[] arr;
        arr = arrq;
    };
    void pop(int*& arr, int& nsz)
    {
        nsz--;
        int* arrq = new int[nsz];
        for (int i = 0; i < nsz; i++)
        {
            arrq[i] = arr[i];
        }
        arr = arrq;
    };
    int peek(int*& arr)
    {
        return arr[nsz - 1];
    };
    int count(int& msz)
    {
        return nsz;
    };
    int at(int v)
    {
        if ((v < 0) && (v >= nsz))
        {
            throw out_of_range("Out of range At()");
        }
        else
        {
            return arr[v];
        }
    };
    void concatstruct(Vector v1, Vector v2)
    {
        for (int i = 0; i < v1.nsz; i++)
        {
            cout << v1.arr[i] << " ";
        }
        for (int j = 0; j < v2.nsz; j++)
        {
            cout << v2.arr[j] << " ";
        }
    };
};

struct Stack
{
    int msz;
    int* arr;
    Stack(int imsz)
    {
        msz = imsz;
        arr = new int[msz];

        for (int i = 0; i < msz; i++)
        {
            arr[i] = 0;
        }
    };
    ~Stack()
    {
        delete[] arr;
    };
    void Vin()
    {
        for (int i = 0; i < msz; i++)
        {
            arr[i] = rand() % 20;
        }
    };
    void Vout()
    {
        for (int i = 0; i < msz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };
    void push(int*& arr, int& msz, int k)
    {
        int* arrq = new int[msz + 1];
        for (int i = 0; i < msz; i++)
        {
            arrq[i] = arr[i];
        }
        arrq[msz] = k;
        msz++;
        delete[] arr;
        arr = arrq;
    };
    void pop(int*& arr, int& msz)
    {
        msz--;
        int* arrq = new int[msz];
        for (int i = 0; i < msz; i++)
        {
            arrq[i] = arr[i];
        }
        arr = arrq;
    };
    int peek(int*& arr)
    {
        return arr[msz - 1];
    };
    int count(int& msz)
    {
        return msz;
    };
    void concatstruct(Stack s1, Stack s2)
    {
        for (int i = 0; i < s1.msz; i++)
        {
            cout << s1.arr[i] << " ";
        }
        for (int j = 0; j < s2.msz; j++)
        {
            cout << s2.arr[j] << " ";
        }
    }
};

struct Queue
{
    int bsz{ 0 };
    int* arr{ nullptr };

    Queue() = default;

    Queue(int insz)
    {
        bsz = insz;
        arr = new int[bsz];

        for (int i = 0; i < bsz; i++)
        {
            arr[i] = 0;
        }
    };
    ~Queue()
    {
        delete[] arr;
    };
    void Vin()
    {
        for (int i = 0; i < bsz; i++)
        {
            arr[i] = rand() % 20;
        }
    };
    void Vout()
    {
        for (int i = 0; i < bsz; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    };
    void push(int*& arr, int& bsz, int k)
    {
        int* arrq = new int[bsz + 1];
        for (int i = 0; i < bsz; i++)
        {
            arrq[i] = arr[i];
        }
        arrq[bsz] = k;
        bsz++;
        delete[] arr;
        arr = arrq;
    };
    void pop(int*& arr, int& bsz)
    {
        bsz--;
        int* arrq = new int[bsz];
        for (int i = 0; i < bsz; i++)
        {
            arrq[i] = arr[i + 1];
        }
        arr = arrq;
    };
    int peek(int*& arr)
    {
        return arr[0];
    };
    int count(int& bsz)
    {
        return bsz;
    };
    void concat(int*& arr, int& bsz)
    {
        for (int i = 0; i < bsz; i++)
        {
            if (arr[i] < 0)
                arr[i] = arr[i] * (-1);
            cout << arr[i];
        }
        cout << endl;
    };
    void concatstruct(Queue q1, Queue q2)
    {
        for (int i = 0; i < q1.bsz; i++)
        {
            cout << q1.arr[i] << " ";
        }
        for (int j = 0; j < q2.bsz; j++)
        {
            cout << q2.arr[j] << " ";
        }
    };
};
#endif 
