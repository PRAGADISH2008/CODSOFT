#include<iostream>
#include<vector>
using namespace std;
class TASK{
    public:
        string name;
        string task_status = "PENDING";
        TASK(string name){
            this->name = name;
        }
};
class TO_DO_LIST{
    public:
        vector <TASK> tasks;
        void add_task(){
            string task_name;
            cout<<"Enter the Task Name : ";
            cin.ignore();
            getline(cin,task_name);
            tasks.emplace_back(task_name);
            cout<<"Task Added Successfully!\n";
        }
        void view_task(){
            int num = 1;
            cout<<"-------Task List------- \n";
            for(auto &task : tasks){
                cout<<num++<<". "<<task.name<<" | "<<task.task_status<<"\n";
            }
            cout<<"   <--------------->\n";
        }
        void task_status(){
            string name;
            cout<<"Enter Task Name : ";
            cin.ignore();
            getline(cin,name);
            int f = 0;
            for(auto &task : tasks){
                if(task.name == name){
                    f = 1;
                    cout<<"Enter Status : ";
                    string status;
                    getline(cin,status);
                    task.task_status = status;
                    cout<<"Task Status Updated Successfully!\n";
                }
            }
            if(f == 0){
                cout<<"Task Not Found!\n";
            }
        }
        void delete_task(){
            cout<<"Enter Task Name to Delete : ";
            string name;
            cin.ignore();
            getline(cin,name);
            int f = 0;
            for(auto i = tasks.begin(); i != tasks.end(); ++i){
                if(i->name == name){
                    f = 1;
                    tasks.erase(i);
                    cout<<"Task deleted successfully!\n";
                    break;
                }
            }
            if(f == 0){
                cout<<"Task Not Found!\n";
            }
        }
};
int main(){
    TO_DO_LIST l;
    int choice;
    do{
        cout<<"----TO-DO LIST----\n";
        cout<<"1.ADD TASK\n2.VIEW TASK\n3.TASK STATUS\n4.DELETE TASK\n5.EXIT\n";
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice){
            case 1:
                l.add_task();
                break;
            case 2:
                l.view_task();
                break;
            case 3:
                l.task_status();
                break;
            case 4:
                l.delete_task();
                break;
            case 5:
                cout<<"Exiting Thank You!\n";
                break;
            default:
                cout<<"Invalid Choice\n";
        }
    }while(choice != 5);
}
