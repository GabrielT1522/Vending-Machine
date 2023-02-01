#include <iostream>
#include <string>
#include <limits>
#include "VendingMachine.h"
using namespace std;

// Function definitions
void ShowMenu()
{
  cout << "<><><><><><><><><><><><><><><><>";
  cout << "\nEnter item number for price\n"
             << "   1. Cookies\n"
             << "   2. Soda\n"
             << "   3. Cupcake\n"
             << "   4. Chips\n"
             << "   5. Quit\n";
  cout << "<><><><><><><><><><><><><><><><>" << endl;
}

int getChoice()
{
	int userChoice;
 
    do
    {
      cout << "Enter item number: ";
      cin >> userChoice;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (userChoice < 1 || userChoice > 5);
	return userChoice;
}


// Start class definitions
VendingMachine::VendingMachine(string itemName, double itemPrice)
{
  name = itemName;
  price = itemPrice;
}

void VendingMachine::showPrice()
{
  cout << name << " costs " << "$" << price;
}

string VendingMachine::getName()
{
  return name;
}

double VendingMachine::getPrice()
{
  return price;
}

double processCoins(string itemName, double itemPrice)
{
  double inserted = 0.00;
  char coins;

  // Ask for user to input "coins"
  do
  {
      cout << endl;
      cout << "Please insert coins:\n";
      cout << "n - Nickel\n";
      cout << "d - Dime\n";
      cout << "q - quarter\n";
      cout << "D - dollar\n";
      cout << "A " << itemName << " costs $" << itemPrice << ". ";
      cout << "You have inserted $" << inserted << ". ";
      cout << "\nEnter coin (Press enter after each coin input): ";
      cin >> coins;

      // Switch case to accumulate monetary value
      switch (coins)
      {
      case 'n':
        inserted += 0.05;
        break;
      case 'd':
        inserted += 0.10;
        break;
      case 'q':
        inserted += 0.25;
        break;
      case 'D':
        inserted += 1.00;
        break;
      default:
        cout << "That is not a valid input\n";
      }
  } while (inserted < itemPrice);
  return inserted - itemPrice;
}

void showReceipt(string itemName, double itemPrice, double change)
{
  cout << "\n\nA " << itemName << " costs $" << itemPrice;
  cout << ". You have inserted $" << change + itemPrice;
  cout << "\nEnjoy your "<< itemName << "! Your change is $" << change
       << "\n\n\n\n";
  cout << "Thank You!" << endl;
}