#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
class BOOK{
    public:
        string title,author,ISBN;
        bool is_available = true;
        time_t issue_date = 0;
        BOOK(string title,string author,string ISBN){
            this->title = title;
            this->author = author;
            this->ISBN = ISBN;
        }
};
class LIBRARY{
    public:
        vector <BOOK> books;
        
        void add_book(){
            string title,author,ISBN;
            cout<<"Enter Book Title : ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Book Author : ";
            getline(cin,author);
            cout<<"Enter Book ISBN : ";
            getline(cin,ISBN);
            books.emplace_back(title,author,ISBN);
            cout<<"Book Added Successfully!\n";
        }
        void search_by_title(){
            string title;
            cout<<"Enter Book Title : ";
            cin.ignore();
            getline(cin,title);
            int f = 0;
            cout<<"\n------ BOOK INFO ------\n";
            for(auto &book : books){
                if(book.title == title){
                    f = 1;
                    cout<<"Book Title : "<<book.title<<"\nAuthor Name : "<<book.author
                    <<"\nISBN : "<<book.ISBN<<"\nBook Status : "<<((book.is_available) ? "Available" : "Not Available")<<"\n";
                }
            }
            if(f == 0){
                cout<<"Book not found with title : "<<title<<"\n";
            }
        }
        void search_by_author(){
            string author;
            cout<<"Enter Book Author : ";
            cin.ignore();
            getline(cin,author);
            int f = 0;
            cout<<"\n------ BOOK INFO ------\n";
            for(auto &book : books){
                if(book.author == author){
                    f = 1;
                    cout<<"Book Title : "<<book.title<<"\nAuthor Name : "<<book.author
                    <<"\nISBN : "<<book.ISBN<<"\nBook Status : "<<((book.is_available) ? "Available" : "Not Available")<<"\n";
                }
            }
            if(f == 0){
                cout<<"Book not found with author name : "<<author<<"\n";
            }
        }
        void search_by_ISBN(){
            string ISBN;
            cout<<"Enter Book ISBN : ";
            cin.ignore();
            getline(cin,ISBN);
            int f = 0;
            cout<<"\n------ BOOK INFO ------\n";
            for(auto &book : books){
                if(book.ISBN == ISBN){
                    f = 1;
                    cout<<"Book Title : "<<book.title<<"\nAuthor Name : "<<book.author
                    <<"\nISBN : "<<book.ISBN<<"\nBook Status : "<<((book.is_available) ? "Available" : "Not Available")<<"\n";
                }
            }
            if(f == 0){
                cout<<"Book not found with ISBN : "<<ISBN<<"\n";
            }
        }
        void book_checkout(){
            string title;
            cout<<"Enter Book Title to Checkout : ";
            cin.ignore();
            getline(cin,title);
            int f = 0;
            for(auto &book : books){
                if(book.title == title){
                    f = 1;
                    if(book.is_available){
                        book.is_available = false;
                        book.issue_date = time(0);
                        cout<<"\nBook Issued Successfully!\n";
                    }
                    else{
                        cout<<"\nBook is out of stock!\n";
                    }
                }
            }
            if(f == 0){
                cout<<"\nBook not found with title : "<<title<<"\n";
            }
            
        }
        void book_return(){
            string title;
            cout<<"Enter title of returning book : ";
            cin.ignore();
            getline(cin,title);
            for(auto &book : books){
                if(book.title == title){
                    if(book.is_available){
                        cout<<"Book was not issued!\n";
                    }
                    else{
                        time_t current_time = time(0);
                        double days = difftime(current_time,book.issue_date) / (60*60*24);
                        book.is_available = true;
                        
                        if(days > 7){
                            double fine = (days-7) * 10;
                            cout<<"\nBook Returned Successfully.\n";
                            cout << "Overdue by " << (days - 7) << " days. Fine = ₹" << fine << "\n";
                        }
                        else{
                            cout<<"\nBook Returned Successfully.No fine!\n";
                            cout<<"No of days borrowed : "<<days<<" days.\n";
                        }
                    }
                }
            }
        }
};
int main(){
    LIBRARY l;
    int choice;
    do{
        cout<<"\n------- LIBRARY MANAGEMENT SYSTEM -------\n";
        cout<<"1.ADD BOOK\n2.SEARCH BOOK BY TITLE\n3.SEARCH BOOK BY AUTHOR\n";
        cout<<"4.SEARCH BOOK BY ISBN\n5.BOOK CHECKOUT\n6.BOOK RETURN\n7.EXIT\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                l.add_book();
                break;
            case 2:
                l.search_by_title();
                break;
            case 3:
                l.search_by_author();
                break;
            case 4:
                l.search_by_ISBN();
                break;
            case 5:
                l.book_checkout();
                break;
            case 6:
                l.book_return();
                break;
            case 7:
                cout<<"Exiting Thank You.....\n";
                break;
            default:
                cout<<"Invalid choice\n";
        }
    }while(choice != 7);
}
