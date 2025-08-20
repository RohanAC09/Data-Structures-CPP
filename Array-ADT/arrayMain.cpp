#include<iostream>
#include<climits>

using namespace std;

class Array{
    private:
        int *A;
        int length;
        int size;
    public:
        Array(int size){
            this->size=size;
            A=new int[size];
            length=0;
        }
        void display(){
            for(int i=0; i<length; i++){
                std::cout<<A[i]<<" ";
            }
            std::cout<<endl;
        }
        void add(int ele){
            if(length<size){
                A[length]=ele;
                length++;
            }
        }
        int get(int index){
            if(index >= 0 && index<size){
                return A[index];
            } else return INT_MIN;
        }
        void insertElement(int value, int index){
            if(index >= 0 && index<size){
                for(int i=length; i<size && i>index; i--){
                    A[i]=A[i-1];
                }
                A[index]=value;
            }
        }
        int deleteElement(int index){
            if(index >= 0 && index<size){
                int value=A[index];
                for(int i=index; i<length-1; i++){
                    A[i]=A[i+1];
                }
                return value;
            } else return INT_MIN;
        }
        int getSize(){
            return this->size;
        }
        int getLength(){
            return this->size;
        }
        ~Array(){
            delete []A;
        }
};

int main(){
    Array arr(10);
    for(int i=0; i<10; i++) arr.add(i+1);

    arr.display();

    return 0;
}