// Implement Dynamic Queue In c++
#include<bits/stdc++.h>
using namespace std;
class DynamicQ
{
    int *array;
    int front;
    int rare;
    int size;
    int max;

     void Resize()
        {
            
            int *temp = new int[2*max];
            for(int i=0; i<=size;i++)
            {
               temp[i]= array[i]; 
            }
                delete array;
                array = temp;
                max = 2*max;
        }
    public:
       
        DynamicQ()
        {
            array = new int[1];
            
            rare = -1;
            size = 0;
            max = 1;
            front = 0;
        }
       
        void Enqueue_(int value)
        {
            if(size == max)
            {
                Resize();
                rare++;
                array[rare] = value;
                size++;
            }
            else{
                rare++;
                array[rare]=value;
                size++;
            }  
        }
        
        void Print_()
        {
            for(int i=front; i<=rare; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<"\nMax Size -> "<<max<<endl;
            cout<<"Rare -> "<<rare+1<<endl;
            cout<<"Size -> "<<size<<endl;
        }
        void Enqueue_End(int value)
        {
            if(size == max)
            {
                Resize();
                rare++;
                array[rare]=value;
                size++;
            }
            else{
                rare++;
                array[rare]=value;
                size++;
            }
        }
        void Delete_Begin()
        {        
            front++;
        }
        void Delete_End()
        {
            rare--;
        }
        void Equeue_Front(int value)
        {
            front=0;
           for(int i=rare; i>front; i--)
           {
                array[i+1] = array[i];
           }
           rare++;
           array[front]=value;
        }
};
int main()
{
    DynamicQ u;
    while(1)
    {
        cout<<"\n...........................................................................\n";
        cout<<"1 For Enqueue \n";
        cout<<"2 For Enqueue End \n";
        cout<<"3 For Deque Front \n";
        cout<<"4 For Deque End \n";
        cout<<"5 For Print \n";
        cout<<"6 For Exit \n";
        int choice;
        cout<<"Enter a Number ";
        cin>>choice;
        int a,b;
        switch(choice)
        {
            case 1:
                cout<<"Ok Enter value ";
                cin>>a;
                u.Enqueue_(a);
            break;
            case 2:
                cout<<"Ok Enter value ";
                cin>>a;
                u.Enqueue_End(a);
            break;
            case 3:
                u.Delete_Begin();
            break;
            case 4: 
                u.Delete_End();
            break;
            case 5:
                u.Print_();
            break;
            case 6:
                 exit(0);
            break;
            default:
                 cout<<"Please Enter a valid Number ";
            break;
        }
    }
}