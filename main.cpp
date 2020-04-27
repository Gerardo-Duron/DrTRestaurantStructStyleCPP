//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
// Name: Gerardo Duron

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Input_Validation.h"
using namespace std; 

//***** Struct Style *******
struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};

string reset = "\x1b[0m";
string red = "\x1b[" + to_string(32) + ";"+to_string(91)+"m";
string blue = "\x1b[34;1m";

/// ****** Class Style ******
class MenuItemList
{
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count; 
  public:
    void setName(string n) { name = n; }
    void setItemCost(double it) { itemCost = it; }
    void setDesc(string d) { desc = d; }
    void setAddLetter(char aL) { addLetter = aL; }
    void setRemoveLetter(char rL) { removeLetter = rL; }
    void setCount( int c) { count = c; }
    string getName() const { return name; }
    double ItemCost() const { return itemCost; }
    string getDesc() const { return desc; }
    char getAddLetter() const { return addLetter; }
    char getRemoveLetter() const { return removeLetter; }
    double getCount() const { return count; }

    // void print() 
};


//****** Struct Class ********

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Carne Asada", "Burgers", "Street Tacos", "Burritos", "Fajitas", "Stake"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].name = defaultMenuNames[i]; 
    entireMenu[i].addLetter = defaultAddLetters[i]; 
    entireMenu[i].removeLetter = defaultRemoveLetters[i]; 
    entireMenu[i].itemCost = (3.00 + i); //set a random starter cost for each item
    entireMenu[i].count = 0; //initialze all counts to 0
    entireMenu[i].desc = "delicious"; //set all default desc to "delicous"
  }


}

/// ******* Class Style ******
//function definitions
void populateObjectMenu(vector<MenuItemList> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItemList Item1; // Item1 is an object
  MenuItemList Item2;
  MenuItemList Item3; 
  MenuItemList Item4;
  MenuItemList Item5;
  MenuItemList Item6;
  MenuItemList Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Carne Asada", "Burgers", "Street Tacos", "Burritos", "Fajitas", "Stake"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }


};


void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << blue << setw(32) << "Gerardo's Favorites" << reset << endl; 
  cout << "\x1b[46;1m" << "ADD  \tNAME \t COST \tREMOVE \tCOUNT \tDESC"<< reset << endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout <<"\x1b[46;1m"  << m[i].addLetter << ")" << reset << setw(10) << m[i].name
    << setw(5) << "$" << m[i].itemCost << setw(5) << "(" << m[i].removeLetter
    << ")" << setw(7) << m[i].count << setw(13) << m[i].desc 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."; 
        m[i].count++; //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].removeLetter)
      {
        cout << "\nRemove Item " << m[i].removeLetter << " selected."; 
        if(m[i].count > 0) //subtract if and only if the count is > 0
        {
          m[i].count--; //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].name << endl;
          subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
        }
      }
      else if(
                option != m[i].addLetter && 
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //handle reciept generation here
}


void tipFunction()
{ cout <<setprecision(2);
  int tipOption;
  double total = 0.0;
  double subtotal = 0.0; 
  double const tax = 0.0825;
  double tip = 0.0;
  double payment=0.0;
  
 
    cout<< red <<"        Would you like to leave a tip?        " << reset <<endl;
    cout<<setw(5)<<"(0)"<<setw(10)<<" (1) "<<setw(10)<<" (2) "<<setw(10)<<" (3) "<<setw(10)<<"(4)  "<<endl;
    cout<<setw(5)<<"0%"<<setw(10)<<" 15% "<<setw(10)<<" 20% "<<setw(10)<<" 25% "<<setw(10)<<"custom"<<endl;
    cout<<setprecision(2)<<setw(5)<<"0 "<<setw(10)<<(subtotal*.15)<<setw(10)<<(subtotal*.20)<<setw(10)<<(subtotal*.25)<<endl<<endl;

    do
    {
      cout<< "Please make a selection ("<< red <<"0,1,2,3,4" << reset<<"): "<<red;
      tipOption = validateInt(tipOption); //Verifing user input
      cout<<reset;
      
      

    
         //if loop to check user tip selection
          if (tipOption==0){tip=0.0;}
          else if  (tipOption==1){tip=subtotal*.15;}
          else if  (tipOption==2){tip=subtotal*.20;}
          else if  (tipOption==3){tip=subtotal*.25;}
          else if  (tipOption==4){  
                                      int customTip;
                                      cout<<"\nWhat percentage would you like to leave? (whole number)"<<endl;
                                      customTip=validateInt(customTip);
            
                                      tip=(customTip/100.0)*subtotal;}
            else {
                  cout<<red<<"That's not a valid answer."<<reset<<endl<<endl;

                 }

    } while(tipOption != 0 && tipOption != 1 && tipOption != 2 && tipOption != 3 && tipOption != 4);
}
  
void showReceipt(vector<MenuItemList> &m)
  {
    cout <<setprecision(2);
    system("clear");
     double total = 0.0;
    double subtotal = 0.0; 
    double const tax = 0.0825;
    double tip = 0.0;
   

    //Creating header
    cout <<setw(20)<< red << "Gerardo's Favorites " <<reset<< endl; 
    cout << blue << "**********************************************"<<reset<<endl;
    cout<< setw(14) << "\tFort Worth's Hidden Secret "<<endl;
    cout <<setw(17) << "\t\t\tItems purchased"<<endl;
    cout << blue << "**********************************************"<<reset<<endl;

    //Will check vector size and will display all purchased items
    for(int i = 0; i < m.size(); i++)
    {
    
      if(m[i].getCount()>0)
      {
        //Shows count followed by name
        cout <<"\t"<< m[i].getCount() <<"\t"<< m[i].getName()<<endl;
       
      }
    }
  //display total for user's record
    cout << "\n  Subtotal: " <<subtotal<<endl;
    cout << "  Tax: " <<(subtotal*tax)<<endl;
    cout << "  Tip: " <<tip<<endl<<endl;
    cout << "  Total: "<<total<<endl;

    cout << blue << "**********************************************"<<reset<<endl;
    cout<<"\t\tFollow us on facebook "<<endl;
    cout << blue << "**********************************************"<<reset<<endl;
       
            
  }


int main() 
{
  //******** Struct Style *******
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 

  ///********* Class Sytle **********
  vector<MenuItemList> objectMenu;
  populateObjectMenu(objectMenu);
  tipFunction();
  showReceipt(objectMenu);
  
  return 0; 
}