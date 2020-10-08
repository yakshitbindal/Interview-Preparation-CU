#include<bits/stdc++.h>
using namespace std;
class DynamicArray
{
    int* data;
    int nextIndex;
    int capacity;  //total Size

    public:

    DynamicArray()
    {
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }

    DynamicArray(DynamicArray const &d)
    {
        //this->data=d.data;  //shallow copy

        //deep copy
        this->data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }

    void add(int element)
    {
        if(nextIndex==capacity)
        {
            int* newData=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            delete [] data;
            data=newData;
            capacity*=2;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    int get(int i) const
    {
        if(i<nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add(int i,int element)
    {
        if(i<nextIndex)
        {
            data[i]=element;
        }
        else if(i==nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
        
    }
    void print() const
    {
        for(int i=0;i<nextIndex;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void operator=(DynamicArray const &d)
    {
        //deep copy
        this->data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++)
        {
            this->data[i]=d.data[i];
        }
        this->nextIndex=d.nextIndex;
        this->capacity=d.capacity;
    }
};

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    DynamicArray d2(d1);
    d2.print();

    DynamicArray d3=d1;

    d3.print();
}