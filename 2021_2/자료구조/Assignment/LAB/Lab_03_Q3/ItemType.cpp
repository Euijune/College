#include <fstream>
#include <iostream>
#include "ItemType.h"


// ItemType.cpp is the implementation file for data for the real 
//  estate manipulation program.

void HouseType::GetFromFile(std::ifstream& file)
{
    lastName.GetStringFile(true, NOT_NEW, file);
    firstName.GetStringFile(true, NOT_NEW, file);
    address.GetStringFile(true, NOT_NEW, file);
    file >> price >> squareFeet >> bedRooms >> BathRooms;
}

void HouseType::WriteToFile(std::ofstream& file)
{
    using std::endl;
    lastName.PrintToFile(false, file);
    firstName.PrintToFile(true, file);
    address.PrintToFile(true, file);
    file << endl << price << endl;
    file << squareFeet << endl;
    file << bedRooms << endl;
    // A
    file << BathRooms << endl;
}

void HouseType::GetFromUser()
{
    using namespace std;
    cout << "Enter last name; press return." << endl;
    lastName.GetString(true, NOT_NEW);
    cout << "Enter first name; press return." << endl;
    firstName.GetString(true, NOT_NEW);
    cout << "Enter address; press return." << endl;
    address.GetString(true, NOT_NEW);
    cout << "Enter price, square feet, number of bedrooms, number of bathrooms;"
        << " press return." << endl;
    // A
    cin >> price >> squareFeet >> bedRooms >> BathRooms;
}

void HouseType::PrintHouseToScreen()
{
    using namespace std;
    firstName.PrintToScreen(false);
    cout << " ";
    lastName.PrintToScreen(false);
    address.PrintToScreen(true);
    cout << endl << "Price: " << price << endl;
    cout << "Square Feet: " << squareFeet << endl;
    cout << "Bedrooms: " << bedRooms << endl;
    // A
    cout << "Bathrooms: " << BathRooms << endl;
}

void HouseType::GetNameFromUser()
{
    using namespace std;
    cout << "Enter last name;  press return." << endl;
    lastName.GetString(true, NOT_NEW);
    cout << "Enter first name;  press return." << endl;
    firstName.GetString(true, NOT_NEW);
}

void HouseType::PrintNameToScreen()
{
    using namespace std;
    firstName.PrintToScreen(false);
    cout << " ";
    lastName.PrintToScreen(false);
    cout << endl;
}

RelationType HouseType::ComparedTo(HouseType house)
{
    /*if (lastName < house.lastName)
        return LESS;
    else if (house.lastName < lastName)
        return GREATER;
    else if (firstName < house.firstName)
        return LESS;
    else if (house.firstName < firstName)
        return GREATER;
    else return EQUAL;*/

    if (*this == house)
        return EQUAL;
    else if (*this < house)
        return LESS;
    else
        return GREATER;
}

bool HouseType::operator<(const HouseType& other) {
    if (lastName < other.lastName)
        return true;
    else if (other.lastName < lastName)
        return false;
    else if (firstName < other.firstName)
        return true;
    else if (other.firstName < firstName)
        return false;
}

bool HouseType::operator==(const HouseType& other) {
    // last와 first가 모두 같아야 동일한 것이다.
    if (lastName == other.lastName && firstName == other.firstName)
        return true;
    else
        return false;
}