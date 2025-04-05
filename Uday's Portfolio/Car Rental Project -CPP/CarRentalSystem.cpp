#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Car
{
    string Company;
    string Model;
    string Color;
    string MaxSpeed;
    string FuelType;
    string Manufacturer;
    string Price;
    bool IsAvailable;
};

struct Customer
{
    string CustomerName;
    string CustomerEmail;
    string CustomerPhoneNumber;
};

vector<Car> cars;
vector<Customer> customers;

const string carDataFile = "car_data.txt";
const string customerDataFile = "customer_data.txt";

void LoadData()
{
    ifstream carFile(carDataFile);
    if (carFile.is_open())
    {
        Car car;
        while (carFile >> car.Company >> car.Model >> car.Color >> car.MaxSpeed >> car.FuelType >> car.Manufacturer >> car.Price >> car.IsAvailable)
        {
            cars.push_back(car);
        }
        carFile.close();
    }

    ifstream customerFile(customerDataFile);
    if (customerFile.is_open())
    {
        Customer customer;
        while (getline(customerFile, customer.CustomerName) && getline(customerFile, customer.CustomerEmail) && getline(customerFile, customer.CustomerPhoneNumber))
        {
            customers.push_back(customer);
        }
        customerFile.close();
    }
}

void SaveData()
{
    ofstream carFile(carDataFile);
    for (const Car &car : cars)
    {
        carFile << car.Company << " " << car.Model << " " << car.Color << " " << car.MaxSpeed << " " << car.FuelType << " " << car.Manufacturer << " " << car.Price << " " << car.IsAvailable << endl;
    }
    carFile.close();

    ofstream customerFile(customerDataFile);
    for (const Customer &customer : customers)
    {
        customerFile << customer.CustomerName << endl
                     << customer.CustomerEmail << endl
                     << customer.CustomerPhoneNumber << endl;
    }
    customerFile.close();
}

void InitializeCars()
{
    cars.push_back({"Maruti", "Swift", "White", "180", "Petrol", "2015", "500000", true});
    cars.push_back({"Honda", "City", "Black", "200", "Petrol", "2017", "1000000", true});
    cars.push_back({"Toyota", "Fortuner", "Grey", "170", "Diesel", "2019", "5000000", true});
}

void DisplayAvailableCars()
{
    cout << "Available Cars:" << endl;
    cout << setw(5) << "ID" << setw(10) << "Company" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "MaxSpeed" << setw(10) << "Price" << endl;
    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (cars[i].IsAvailable)
        {
            cout << setw(5) << i + 1 << setw(10) << cars[i].Company << setw(10) << cars[i].Model << setw(10) << cars[i].Color << setw(10) << cars[i].MaxSpeed << setw(10) << cars[i].Price << endl;
        }
    }
}

void RegisterCustomer()
{
    Customer newCustomer;
    cout << "Customer Registration:" << endl;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newCustomer.CustomerName);
    cout << "Enter Email: ";
    getline(cin, newCustomer.CustomerEmail);
    cout << "Enter Phone Number: ";
    getline(cin, newCustomer.CustomerPhoneNumber);
    customers.push_back(newCustomer);
    cout << "Registration successful!" << endl;
}

void RentCar(int customerId)
{
    DisplayAvailableCars();
    size_t carId;
    cout << "Enter the car ID to rent: ";
    cin >> carId;

    if (carId > 0 && carId <= cars.size() && cars[carId - 1].IsAvailable)
    {
        string enteredPhoneNumber;
        cout << "Enter your phone number for verification: ";
        cin.ignore();
        getline(cin, enteredPhoneNumber);

        if (enteredPhoneNumber == customers[customerId].CustomerPhoneNumber)
        {
            cars[carId - 1].IsAvailable = false;
            cout << "Car rented successfully!" << endl;
            cout << "Invoice:" << endl;
            cout << "Customer: " << customers[customerId].CustomerName << endl;
            cout << "Phone Number: " << customers[customerId].CustomerPhoneNumber << endl;
            cout << "Car: " << cars[carId - 1].Company << " " << cars[carId - 1].Model << endl;
            cout << "Price: " << cars[carId - 1].Price << endl;
        }
        else
        {
            cout << "Phone number verification failed. Car rental denied." << endl;
        }
    }
    else
    {
        cout << "Invalid car selection or car is not available." << endl;
    }
}

void ReturnCar(int customerId)
{
    DisplayAvailableCars();
    cout << "Cars Rented by " << customers[customerId].CustomerName << ":" << endl;
    cout << setw(5) << "ID" << setw(10) << "Company" << setw(10) << "Model" << setw(10) << "Color" << setw(10) << "MaxSpeed" << setw(10) << "Price" << endl;

    for (size_t i = 0; i < cars.size(); ++i)
    {
        if (!cars[i].IsAvailable)
        {
            cout << setw(5) << i + 1 << setw(10) << cars[i].Company << setw(10) << cars[i].Model << setw(10) << cars[i].Color << setw(10) << cars[i].MaxSpeed << setw(10) << cars[i].Price << endl;
        }
    }

    size_t carId;
    cout << "Enter the car ID to return: ";
    cin >> carId;

    if (carId > 0 && carId <= cars.size() && !cars[carId - 1].IsAvailable)
    {
        string enteredPhoneNumber;
        cout << "Enter your phone number for verification: ";
        cin.ignore();
        getline(cin, enteredPhoneNumber);

        if (enteredPhoneNumber == customers[customerId].CustomerPhoneNumber)
        {
            cars[carId - 1].IsAvailable = true;
            cout << "Car returned successfully!" << endl;
            cout << "Invoice:" << endl;
            cout << "Customer: " << customers[customerId].CustomerName << endl;
            cout << "Phone Number: " << customers[customerId].CustomerPhoneNumber << endl;
            cout << "Car: " << cars[carId - 1].Company << " " << cars[carId - 1].Model << endl;
            cout << "Price: " << cars[carId - 1].Price << endl;
        }
        else
        {
            cout << "Phone number verification failed. Car return denied." << endl;
        }
    }
    else
    {
        cout << "Invalid car selection or car is not rented by you." << endl;
    }
}

int main()
{
    LoadData();
    InitializeCars();

    while (true)
    {
        cout << "Car Rental System:" << endl;
        cout << "1. Register as a Customer" << endl;
        cout << "2. Rent a Car" << endl;
        cout << "3. Return a Car" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            RegisterCustomer();
            SaveData();
            break;
        case 2:
            if (customers.empty())
            {
                cout << "Please register as a customer first." << endl;
            }
            else
            {
                RentCar(0);
                SaveData();
            }
            break;
        case 3:
            if (customers.empty())
            {
                cout << "Please register as a customer first." << endl;
            }
            else
            {
                ReturnCar(0);
                SaveData();
            }
            break;
        case 4:
            cout << "Thank you for using our system." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}
