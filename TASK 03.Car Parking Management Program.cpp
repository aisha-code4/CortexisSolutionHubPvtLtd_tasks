#include <iostream>

using namespace std;

class Parking
{
public:
    int slot;
    string carNumber;
    string entryTime;
    string exitTime;
    float fee;
};

class ParkingSystem
{
public:
    void addVehicle()
    {
        Parking p;
        cout << "\nEnter Slot Number: ";
        cin >> p.slot;
        cout << "Enter Car Number: ";
        cin >> p.carNumber;
        cout << "Enter Entry Time (HH:MM): ";
        cin >> p.entryTime;

        p.exitTime = "-";
        p.fee = 0;

        ofstream file("parking.txt", ios::app);
        if (file.is_open())
        {
            file << p.slot << " " << p.carNumber << " " << p.entryTime << " "
                 << p.exitTime << " " << p.fee << endl;
            file.close();
            cout << "\nVehicle Added Successfully!\n";
        }
        else
        {
            cout << "\nError in opening file!\n";
        }
    }

    void exitVehicle()
    {
        int slot;
        cout << "\nEnter Slot Number for Exit: ";
        cin >> slot;
        string exitT;
        cout << "Enter Exit Time (HH:MM): ";
        cin >> exitT;

        ifstream inFile("parking.txt");
        ofstream temp("temp.txt");

        Parking p;
        bool found = false;

        while (inFile >> p.slot >> p.carNumber >> p.entryTime >> p.exitTime >> p.fee)
        {
            if (p.slot == slot)
            {
                found = true;
                p.exitTime = exitT;
                p.fee = 50; 
                cout << "\nVehicle Exited. Fee = Rs." << p.fee << endl;
            }
            temp << p.slot << " " << p.carNumber << " " << p.entryTime << " "
                 << p.exitTime << " " << p.fee << endl;
        }

        inFile.close();
        temp.close();
        remove("parking.txt");
        rename("temp.txt", "parking.txt");

        if (!found)
            cout << "\nSlot not found!\n";
    }

    void showRecords()
    {
        ifstream file("parking.txt");
        Parking p;

        cout << "\n--- Parking Records ---\n";
        cout << "Slot\tCarNumber\tEntryTime\tExitTime\tFee\n";

        while (file >> p.slot >> p.carNumber >> p.entryTime >> p.exitTime >> p.fee)
        {
            cout << p.slot << "\t" << p.carNumber << "\t\t" << p.entryTime
                 << "\t\t" << p.exitTime << "\t\t" << p.fee << endl;
        }

        file.close();
    }
};

int main()
{
    ParkingSystem ps;
    int choice;

    do
    {
        cout << "\n==== Car Parking System ====\n";
        cout << "1. Add Vehicle Entry\n";
        cout << "2. Record Vehicle Exit\n";
        cout << "3. Show All Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            ps.addVehicle();
        else if (choice == 2)
            ps.exitVehicle();
        else if (choice == 3)
            ps.showRecords();
        else if (choice == 4)
            cout << "\nExiting Program...\n";
        else
            cout << "\nInvalid Choice!\n";

    } while (choice != 4);

    return 0;
}


