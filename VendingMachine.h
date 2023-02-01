#pragma once
#include <iostream>
#include <string>
using namespace std;

// Function headers
void ShowMenu();
int getChoice();
double processCoins(string itemName, double itemPrice);
void showReceipt(string itemName, double itemPrice, double change);

// Class headers
class VendingMachine
{
  public:
    VendingMachine(string itemName, double itemPrice);
    void showPrice();
    string getName();
    double getPrice();
    double processCoins();

  private:
    string name;
    double price;
};