#ifndef Header_h_
#define Header_h_
#include <iostream>
#include <sstream>
#include <climits>


using namespace std;

struct Vector
{
    private:
        int size { 0 };
        int capacity { 0 };
        int* arr { nullptr };

    public:    
        Vector () = default;
        explicit Vector(int isize)
        {
            capacity = isize;
            arr = new int[capacity];
        };
        ~Vector()
        {
            delete[] arr;
        };
        void Vin()
        {
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = rand() % 20;
                size++;
            }
        };
        void Vout()
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };

        void push(int k)
        {
            if(capacity > size)
            {
                arr[size++] = k;
                return;
            }
            int* arrq = new int[size + 1];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[size] = k;
            size++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (size == 0) throw logic_error("Vector is epmty");
            if(capacity > size)
            {
                arr[size--] = 0;
                return;
            }
            size--;
            int* arrq = new int[size];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (size == 0) throw logic_error("Vector is epmty");
            return arr[size - 1];
        };
        int count() const
        {
            return size;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= size))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < size; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(const Vector& v1)
        {
            for (int i = 0; i < v1.count(); i++)
                this->push(v1.at(i));
        };
        static Vector concatstructs(const Vector& v1, const Vector& v2)
        {
            Vector concatedVector(0);
            concatedVector.concatstruct(v1);
            concatedVector.concatstruct(v2);
            return concatedVector;
        };

        bool operator == (const Vector& obj) 
        {
            if(this->count() != obj.count()) return false;
            int i;
            for(i = 0; i < this->count() && this->at(i) == obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator > (const Vector& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Vectors must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) > obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator < (const Vector& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Vectors must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) < obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator <= (const Vector& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Vectors must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) <= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator >= (const Vector& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Vectors must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) >= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator != (const Vector& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Vectors must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) != obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }
};

struct Stack
{
    private:
        int size { 0 };        
        int capacity { 0 };
        int* arr { nullptr };
    public:
        Stack () = default;
        explicit Stack(int isize)
        {
            capacity = isize;
            arr = new int[capacity];

            for (int i = 0; i < capacity; i++)
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
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = rand() % 20;
                size++;
            }
        };
        void Vout()
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };
        void push(int k)
        {
            if(capacity > size)
            {
                arr[size++] = k;
                return;
            }
            int* arrq = new int[size + 1];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[size] = k;
            size++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (size == 0) throw logic_error("Stack is epmty");
            if(capacity > size)
            {
                arr[size--] = 0;
                return;
            }
            size--;
            int* arrq = new int[size];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (size == 0) throw logic_error("Stack is epmty");
            return arr[size - 1];
        };
        int count() const
        {
            return size;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= size))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < size; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(const Stack& s1)
        {
            for (int i = 0; i < s1.count(); i++)
                this->push(s1.at(i));
        };
        static Stack concatstructs(const Stack& s1, const Stack& s2)
        {
            Stack concatedStack(0);
            concatedStack.concatstruct(s1);
            concatedStack.concatstruct(s2);
            return concatedStack;
        };

        bool operator == (const Stack& obj) 
        {
            if(this->count() != obj.count()) return false;
            int i;
            for(i = 0; i < this->count() && this->at(i) == obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator > (const Stack& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Stacks must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) > obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator < (const Stack& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Stacks must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) < obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator <= (const Stack& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Stacks must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) <= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator >= (const Stack& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Stacks must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) >= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator != (const Stack& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Stacks must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) != obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }
};

struct Queue
{
    private:
        int size{ 0 };
        int capacity { 0 };
        int* arr{ nullptr };
    public:
        Queue() = default;

        explicit Queue(int isize)
        {
            capacity = isize;
            arr = new int[capacity];

            for (int i = 0; i < capacity; i++)
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
            for (int i = 0; i < capacity; i++)
            {
                arr[i] = rand() % 20;
            }
        };
        void Vout()
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        };
        void push(int k)
        {
            if(capacity > size)
            {
                arr[size++] = k;
                return;
            }
            int* arrq = new int[size + 1];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i];
            }
            arrq[size] = k;
            size++;
            delete[] arr;
            arr = arrq;
        };
        void pop()
        {
            if (size == 0) throw logic_error("Queue is epmty");
            if(capacity > size)
            {
                for (int i = 0; i < size; ++i)
                {
                    arr[i] = arr[i+1];
                }
                arr[size] = 0;
                size--;
                return;
            }
            size--;
            int* arrq = new int[size];
            for (int i = 0; i < size; i++)
            {
                arrq[i] = arr[i + 1];
            }
            delete[] arr;
            arr = arrq;
        };
        int peek()
        {
            if (size == 0) throw logic_error("Queue is epmty");
            return arr[0];
        };
        int count() const
        {
            return size;
        };
        int at(int index) const
        {
            if ((index < 0) || (index >= size))
            {
                throw out_of_range("Out of range At()");
            }
            return arr[index];
            
        };

        int concat()
        {
            stringstream ss;
            for (unsigned i = 0; i < size; ++i)
                ss << abs(arr [i]);
            int result;
            ss >> result;
            if (result == INT_MAX) throw out_of_range("Integer out of range: 2147483647");
            return result;
        };

        void concatstruct(const Queue& q1)
        {
            for (int i = 0; i < q1.count(); i++)
                this->push(q1.at(i));
        };
        static Queue concatstructs(const Queue& q1, const Queue& q2)
        {
            Queue concatedQueue(0);
            concatedQueue.concatstruct(q1);
            concatedQueue.concatstruct(q2);
            return concatedQueue;
        };

        bool operator == (const Queue& obj) 
        {
            if(this->count() != obj.count()) return false;
            int i;
            for(i = 0; i < this->count() && this->at(i) == obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator > (const Queue& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Queues must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) > obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator < (const Queue& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Queues must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) < obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator <= (const Queue& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Queues must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) <= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator >= (const Queue& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Queues must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) >= obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }

        bool operator != (const Queue& obj) const
        {
            if(this->count() != obj.count()) throw logic_error("Queues must be of same length");;
            int i;
            for(i = 0; i < this->count() && this->at(i) != obj.at(i); i++);
            return (i == this->count()) ? true : false;
        }
};
#endif 