//
//  vending.cpp
//  Vending Machine
//
//  Created by Gabriel Torres on 10/7/21.
//
// Gabriel Alexander Torres
// Based on CSCE 1136 Lab 6: Deep Fried Twinkies
#include <iostream>
#include <string>
#include "VendingMachine.h"
using namespace std;

int main()
{
  VendingMachine Cookies("Cookies", 2.5), Soda("Soda", 1.75), Cupcake("Cupcake", 2.5), Chips("Chips", 1.25);

    
  string itemName;
  double itemPrice;
  char decision;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  do 
  {
     
    ShowMenu();
    int choice = getChoice();
    if (choice == 5)
    {
      cout << "Thank You!" << endl;
      return 0;
    } 
      
    switch (choice)
    {
      case 1:
        Cookies.showPrice();
        itemName = Cookies.getName();
        itemPrice = Cookies.getPrice();
        break;
      case 2:
        Soda.showPrice();
        itemName = Soda.getName();
        itemPrice = Soda.getPrice();
        break;
      case 3:
        Cupcake.showPrice();
        itemName = Cupcake.getName();
        itemPrice = Cupcake.getPrice();
        break;
      case 4:
        Chips.showPrice();
        itemName = Chips.getName();
        itemPrice = Chips.getPrice();
        break;
      default:
        break;
    }
      
    cout << "\nDo you want this item? (Y or N): ";
    cin >> decision;
    } while (decision == 'N' || decision == 'n');

  // Function call the total amount paid (Outputs total and change)
  double change = processCoins(itemName, itemPrice);
  showReceipt(itemName, itemPrice, change);
    
  return 0;
}