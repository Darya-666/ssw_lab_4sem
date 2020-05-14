#ifndef Header_h_
#define Header_h_
#include <iostream>
#include <sstream>
#include <climits>
#include <chrono>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct Vector
{
    private:
        int nsz { 0 };
        int anchor { 0 };
        int* arr { nullptr };

    public:    
        explicit Vector(int insz)
        {
            anchor = insz;
            arr = new int[anchor];
        };
        ~Vector()
        {
            delete[] arr;
        };
        void Vin()
        {
            for (int i = 0; i < anchor; i++)
            {
                arr[i] = rand() % 20;
                nsz++;
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

        void push(int k)
        {
            if(anchor > nsz)
            {
                arr[nsz++] = k;
                return;
            }
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
        void pop()
        {
            if (nsz == 0) throw logic_error("Vector is epmty");
            if(anchor > nsz)
            {
                arr[nsz--] = 0;
                return;
            }
            nsz--;
            int* arrq = new int[nsz];
            for (int i = 0; i < nsz; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (nsz == 0) throw logic_error("Vector is epmty");
            return arr[nsz - 1];
        };
        int count()
        {
            return nsz;
        };
        int at(int index)
        {
            if ((index < 0) || (index >= nsz))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < nsz; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(Vector *v1)
        {
            for (int i = 0; i < v1->count(); i++)
                this->push(v1->at(i));
        };
        static Vector concatstructs(Vector *v1, Vector *v2)
        {
            Vector concatedVector(0);
            concatedVector.concatstruct(v1);
            concatedVector.concatstruct(v2);
            return concatedVector;
        };
};

struct Stack
{
    private:
        int msz { 0 };        
        int anchor { 0 };
        int* arr { nullptr };
    public:
        explicit Stack(int imsz)
        {
            anchor = imsz;
            arr = new int[anchor];

            for (int i = 0; i < anchor; i++)
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
            for (int i = 0; i < anchor; i++)
            {
                arr[i] = rand() % 20;
                msz++;
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
        void push(int k)
        {
            if(anchor > msz)
            {
                arr[msz++] = k;
                return;
            }
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
        void pop()
        {
            if (msz == 0) throw logic_error("Stack is epmty");
            if(anchor > msz)
            {
                arr[msz--] = 0;
                return;
            }
            msz--;
            int* arrq = new int[msz];
            for (int i = 0; i < msz; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (msz == 0) throw logic_error("Stack is epmty");
            return arr[msz - 1];
        };
        int count()
        {
            return msz;
        };
        int at(int index)
        {
            if ((index < 0) || (index >= msz))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < msz; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(Stack* s1)
        {
            for (int i = 0; i < s1->count(); i++)
                this->push(s1->at(i));
        };
        static Stack concatstructs(Stack* s1, Stack* s2)
        {
            Stack concatedStack(0);
            concatedStack.concatstruct(s1);
            concatedStack.concatstruct(s2);
            return concatedStack;
        };
};

struct Queue
{
    private:
        int bsz{ 0 };
        int anchor { 0 };
        int* arr{ nullptr };
    public:
        Queue() = default;

        explicit Queue(int insz)
        {
            anchor = insz;
            arr = new int[anchor];

            for (int i = 0; i < anchor; i++)
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
            for (int i = 0; i < anchor; i++)
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
        void push(int k)
        {
            if(anchor > bsz)
            {
                arr[bsz++] = k;
                return;
            }
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
        void pop()
        {
            if (bsz == 0) throw logic_error("Queue is epmty");
            if(anchor > bsz)
            {
                for (int i = 0; i < bsz; ++i)
                {
                    arr[i] = arr[i+1];
                }
                arr[bsz] = 0;
                bsz--;
                return;
            }
            bsz--;
            int* arrq = new int[bsz];
            for (int i = 0; i < bsz; i++)
            {
                arrq[i] = arr[i + 1];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (bsz == 0) throw logic_error("Queue is epmty");
            return arr[0];
        };
        int count()
        {
            return bsz;
        };
        int at(int index)
        {
            if ((index < 0) || (index >= bsz))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < bsz; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(Queue* q1)
        {
            for (int i = 0; i < q1->count(); i++)
                this->push(q1->at(i));
        };
        static Queue concatstructs(Queue* q1, Queue* q2)
        {
            Queue concatedQueue(0);
            concatedQueue.concatstruct(q1);
            concatedQueue.concatstruct(q2);
            return concatedQueue;
        };
};
#endif 