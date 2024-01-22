/*


===================== Movie Theater Seat Reservation System =========================

This program is developed for a new a automated seat reservation system for a movie theater. 
The theater has a single auditorium with a capacity of 100 seats.
    30 seats for VIP
    70 seats for standard
The program assigned automatically depending on the choice of the user.
The program requests to input their name, preferred genre, and age for reservation of seats.

Features
    - Handles error for invalid inputs(out of range selection)
    - displays the current seat occupancy status to the theater staff.
    - Allow searching for patrons based on their name for future reservations.
    - Implemented design for both the "VIP" and "Standard" sections.

While excution, 
    - the program asks the user to choose from the five choose
        ( VIP Seating, Standard Seating, Display Seat Occupancy, Search for Patron, Exit)  
    - request to input the desired input for the choice(Vip seatin and standard seating)
    - assigned the seat and displays ID of the seat

Note: while entering your name and prerred genre, you should end your information by dot "."


*/


#include <iostream>
#include <string>
#include <cctype> //to use isalph()
using namespace std;

const int VIP_SEATS = 30, TOTAL_SEATS = 100;
string patronNames[TOTAL_SEATS], patronGenres[TOTAL_SEATS], temp;
int patronAges[TOTAL_SEATS];
bool checker;


int main() {
    char choice;

    do {
        cout << "====== Movie Theater Seat Reservation System ======"<<endl;
        cout << "\t1. VIP Seating"<<endl;
        cout << "\t2. Standard Seating"<<endl;
        cout << "\t3. Display Seat Occupancy"<<endl;
        cout << "\t4. Search for Patron"<<endl;
        cout << "\t5. Exit"<<endl;
        cout << "===============================================\n"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        char nextChar;
        if(!(cin.get(nextChar) && nextChar == '\n')){
            cout << "Invalid choice. Please try again.\n"<<endl;
            cin.clear();
            cin.ignore(256, '\n'); 
            continue;
        }

        int seatNumber = -1;

        switch (choice) {
            case '1': {

                for (int i=0; i < VIP_SEATS;i++) {

                    if (patronNames[i].empty()) {
                        seatNumber = i;
                        break;
                    }
                }

                string response;

                if (seatNumber == -1) {
                    cout << "Sorry, all VIP seats are occupied.\n";
                    cout << "Would you like to be placed in the standard section? (yes/no): ";
                    cin >> response;

                    if (response == "yes") {

                        for (int i = VIP_SEATS; i < TOTAL_SEATS; ++i) {
                            if (patronNames[i].empty()) {
                                seatNumber = i;
                                break;
                            }
                        }

                    } else {
                        cout << "Sorry, All seats are occupied.\n";
                        continue;
                    }
                }

                checker=true;
                while(checker){
                    cout << "Enter your name: ";
                    getline(cin,temp);                    
                    
                    if (temp.empty()) {
                        cout << "Error: Name cannot be empty. Please enter a valid name." <<endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    for (int i=0;i<size(temp);i++) {
                        if (!isalpha(temp[i]) && !(temp[i]==' ')) {
                                cout << "Invalid character .Please enter only alpha characters." <<endl;
                                checker=true;
                                break;
                            }
                        checker=false;
                    }
                }
                patronNames[seatNumber]=temp;
                
                checker=true;
                while(checker){
                    cout << "Enter your preferred genre: ";
                    getline(cin,temp);
                    
                    if (temp.empty()) {
                        cout << "Error: genre cannot be empty. Please enter a valid name." <<endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    for (int i=0;i<size(temp);i++) {
                        if (!isalpha(temp[i]) && !(temp[i]==' ')) {
                                cout << "Invalid character .Please enter only alpha characters." <<endl;
                                checker=true;
                                break;
                            }
                        checker=false;
                    }
                }
                patronGenres[seatNumber]=temp;

                cout << "Enter your age: ";
                cin >> patronAges[seatNumber];

                cout << "Reservation successful!"<<endl;
                cout << "Your ticket - Seat: " << seatNumber + 1 << " (VIP)\n";
                break;
            }


            case '2': {

                for (int i = VIP_SEATS; i < TOTAL_SEATS; ++i) {

                    if (patronNames[i].empty()) {
                        seatNumber = i;
                        break;
                    }

                }

                string response;

                if (seatNumber == -1) {
                    cout << "Sorry, all standard seats are occupied.\n";
                    cout << "Would you like to be placed in the VIP section? (yes/no): ";
                    cin >> response;

                    if (response == "yes") {

                        for (int i = 0; i < VIP_SEATS; ++i) {
                            if (patronNames[i].empty()) {
                                seatNumber = i;
                                break;
                            }
                        }
                    } else {

                        cout << "Sorry, All seats are occupied\n";
                        continue;
                    }
                }

                checker=true;
                while(checker){
                    cout << "Enter your name: ";
                    getline(cin,temp);
                    
                    if (temp.empty()) {
                        cout << "Error: Name cannot be empty. Please enter a valid name." <<endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    for (int i=0;i<size(temp);i++) {
                        if (!isalpha(temp[i]) && !(temp[i]==' ')) {
                                cout << "Invalid character .Please enter only alpha characters." <<endl;
                                checker=true;
                                break;
                            }
                        checker=false;
                    }
                }
                patronNames[seatNumber]=temp;
                
                checker=true;
                while(checker){
                    cout << "Enter your preferred genre: ";
                    getline(cin,temp);
                    
                    if (temp.empty()) {
                        cout << "Error: genre cannot be empty. Please enter a valid name." <<endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    for (int i=0;i<size(temp);i++) {
                        if (!isalpha(temp[i]) && !(temp[i]==' ')) {
                                cout << "Invalid character .Please enter only alpha characters." <<endl;
                                checker=true;
                                break;
                            }
                        checker=false;
                    }
                }
                patronGenres[seatNumber]=temp;


                cout << "Enter your age: ";
                cin >> patronAges[seatNumber];
                cout << "Reservation successful!\n";
                cout << "Your ticket - Seat: " << seatNumber + 1 << " (Standard)\n";
                break;
            }


            case '3': {

                cout << "\tSeat Occupancy Status\n";
                for (int i = 0; i < TOTAL_SEATS; ++i) {
                    if (!patronNames[i].empty()) {
                        cout << "Seat " << i + 1 << ": " << patronNames[i] << " ("
                                  << (i < VIP_SEATS ? "VIP" : "Standard") << ")"<<endl;
                    }
                }
                cout << "================================"<<endl;
                break;
            }


            case '4': {
                string searchName;
                checker=true;
                while(checker){
                    cout << "Enter the name to search: ";
                    getline(cin,temp);
                    
                    if (temp.empty()) {
                        cout << "Error: Search Name cannot be empty. Please enter a valid name." <<endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }

                    for (int i=0;i<size(temp);i++) {
                        if (!isalpha(temp[i]) && !(temp[i]==' ')) {
                                cout << "Invalid character .Please enter only alpha characters." <<endl;
                                checker=true;
                                break;
                            }
                        checker=false;
                    }
                }
                searchName=temp;


                bool found = false;
                for (int i = 0; i < TOTAL_SEATS; i++) {
                    if (!patronNames[i].empty() && patronNames[i] == searchName) {
                        cout << "Patron found!\n";
                        cout << "Name: " << patronNames[i] << "\n";
                        cout << "Preferred Genre: " << patronGenres[i] << "\n";
                        cout << "Age: " << patronAges[i] << "\n";
                        cout << "Seat: " << i + 1 << " ("
                                  << (i < VIP_SEATS ? "VIP" : "Standard") << ")\n";
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Patron not found.\n";
                }
                break;
            }


            case '5':

                cout << "Exiting the program. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n"<<endl;
                cin.clear();
                cin.ignore(256, '\n'); 
        }
    } while (choice!=5);

    return 0;
}