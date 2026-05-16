#include<iostream>
using namespace std;
int main(){
    float number_1,number_2;
    int choice;
    do{
        cout<<"-------SIMPLE CALCULATOR---------\n";
        cout<<"1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.DIVISION\n5.EXIT\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter Number_1 : ";
                cin>>number_1;
                cout<<"Enter Number_2 : ";
                cin>>number_2;
                cout<<"RESULT : "<<number_1 + number_2<<"\n";
                break;
            case 2:
                cout<<"Enter Number_1 : ";
                cin>>number_1;
                cout<<"Enter Number_2 : ";
                cin>>number_2;
                cout<<"RESULT : "<<number_1 - number_2<<"\n";
                break;
            case 3:
                float multiplicand,multiplier;
                cout<<"Enter Multiplicand : ";
                cin>>multiplicand;
                cout<<"Enter Multiplier : ";
                cin>>multiplier;
                cout<<"RESULT : "<<multiplicand * multiplier<<"\n";
                break;
            case 4:
                float dividend,divisor;
                cout<<"Enter Dividend : ";
                cin>>dividend;
                cout<<"Enter Divisor : ";
                cin>>divisor;
                if(divisor == 0){
                    cout<<"Cannot divide by 0\n";
                }
                else{
                    cout<<"RESULT : "<<dividend / divisor<<"\n";
                }
                break;
            case 5:
                cout<<"Exiting Thank You!\n";
                break;
            default:
                cout<<"Invalid Choice\n";
        }
    }while(choice != 5);
}
