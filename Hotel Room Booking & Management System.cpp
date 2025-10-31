#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room {
protected:
    int roomNo;
    string type;
    float price;
public:
    Room() {}
    Room(int r, string t, float p) 
	{
        roomNo = r;
        type = t;
        price = p;
    }
    void showRoom() 
	{
        cout << "Room No: " << roomNo << " | Type: " << type << " | Price: Rs " << price << endl;
    }
    int getRoomNo() 
	{ 
	   return roomNo;
    }
    string getType() 
	{ 
	  return type; 
    }
    float getPrice() 
	{
	  return price; 
    }
 
};

class Booking : public Room {
    string guestName;
    int days;
    string status;
public:
    Booking() {}
    Booking(int r, string t, float p, string g, int d, string s)
        : Room(r, t, p) 
	{
        guestName = g;
        days = d;
        status = s;
    }
    void showBooking() 
	{
        cout << "Room No: " << roomNo << " | Guest: " << guestName
             << " | Days: " << days << " | Status: " << status
             << " | Total: Rs " << price * days << endl;
    }

    string getStatus() 
	{ 
	   return status; 
	}
    int getRoomNo() 
	{ 
	   return roomNo; 
	}
    string getGuest() 
	{ 
	   return guestName; 
	}
    float getTotal() 
	{ 
	   return price * days; 
	}

    void setStatus(string s) 
	{ 
	   status = s; 
	}
};


void saveBooking(Booking b) {
    ofstream file("bookings.txt", ios::app);
    if (file.is_open()) 
	{
        file << b.getRoomNo() << " " << b.getType() << " " << b.getPrice()
             << " " << b.getGuest() << " " << b.getTotal() << " " << b.getStatus() << endl;
        file.close();
    }
    
}

void showAllBookings() 
{
    ifstream file("bookings.txt");
    string line;
    if (!file) {
        cout << "No booking record found.\n";
        return;
    }
  cout << "\n--- All Bookings ---\n";
    
    while (getline(file, line)) 
	{
        cout << line << endl;
    }
       file.close();
}


int main() {
    int choice;
    Booking b[20]; 
    int count = 0;

    cout << "===== HOTEL ROOM BOOKING SYSTEM =====\n";

    while (true) {
        cout << "\n1. View Available Rooms";
        cout << "\n2. Add Booking";
        cout << "\n3. View All Bookings";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- Available Rooms ---\n";
            Room r1(101, "Single", 3000);
            Room r2(102, "Double", 4500);
            Room r3(103, "Deluxe", 7000);
            r1.showRoom();
            r2.showRoom();
            r3.showRoom();
        }
        else if (choice == 2) {
            int roomNo, days;
            string type, name;
            float price;

            cout << "\nEnter Room No: ";
            cin >> roomNo;
            cout << "Enter Type (Single/Double/Deluxe): ";
            cin >> type;
            cout << "Enter Price per night: ";
            cin >> price;
            cout << "Enter Guest Name: ";
            cin >> name;
            cout << "Enter No. of Days: ";
            cin >> days;

            b[count] = Booking(roomNo, type, price, name, days, "Booked");
            saveBooking(b[count]);
            cout << "\nBooking Successful!\n";
            b[count].showBooking();
            count++;
        }
        else if (choice == 3) {
            showAllBookings();
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

