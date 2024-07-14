#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


class Shopping
{
  private:
    int pcode;
    float price;
    float dis;
    string pname;
  public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void Shopping::menu()
{
  m: // label
  int choice;
  string email;
  string password;

  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t      SuperMarket Main Menu       \n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t  1-) Administrator\n";
  cout << "\t\t\t                   \n";
  cout << "\t\t\t  2-) Buyer        \n";
  cout << "\t\t\t                   \n";
  cout << "\t\t\t  3-) Exit         \n";
  cout << "\t\t\t                   \n";
  cout << "\t\t\t Please Select From Menu! ";
  cin >> choice;

  switch (choice)
  {
    case 1:
      cout << "\t\t\t Please Login \n";
      cout << "\n\t\t\t Enter Email: ";
      cin >> email;
      cout << "\n\t\t\t Enter Password: ";
      cin >> password;

      if(email == "boss@gmail.com" && password == "boss2025")
      {
        administrator();
      }
      else
      {
        cout << "Invalid email or password";
      }
  break;

    case 2:
    {
      buyer();
    }
  break;

    case 3:
    {
      exit(0);
    }
  break;

    default:
    {
      cout << "Please Select From The Given Options!";
    }
  }

  goto m;
}

void Shopping::administrator()
{
  m:
  int choice;

  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t       Administrator Menu         \n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout << "\n\t   1-) Add product       ";
  cout << "\n\t                         ";
  cout << "\n\t   2-) Modified Product  ";
  cout << "\n\t                         ";
  cout << "\n\t   3-) Delete Product    ";
  cout << "\n\t                         ";
  cout << "\n\t   4-) Back to Main Menu ";

  cout << "\n\n\t Please Enter Your Choice: ";
  cin >> choice;

  switch(choice)
  {
    case 1:
      {
        add();
      }
    break;

    case 2:
      {
        edit();
      }
    break;

    case 3:
      {
        rem();
      }
    break;

    case 4:
      {
        menu();
      }
    break;
    
    default:
      cout << "Invalid Choice";
  }

  goto m;
}

void Shopping::buyer()
{
  m:
  int Choice;

  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t           Buyer Menu             \n";
  cout << "\t\t\t                                  \n";
  cout << "\t\t\t----------------------------------\n";
  cout << "\t\t\t                                  \n";
  cout <<"\t 1-) Buy product   \n";
  cout <<"\t                   \n";
  cout <<"\t 2-) Go Back       \n";
  cout <<"\t                   \n";

  cout << "Enter Your Choice: ";
  cin >> Choice;

  switch (Choice)
  {
    case 1:
      {
        receipt();
      }
    break;

    case 2:
      {
        menu();
      }
    break;

  default:
    cout << "Invalid Choice";
  }

  goto m;
}

void Shopping::add()
{
  m:
  fstream data;
  int token = 0;
  int c;     // product code
  float p;   // product price
  string n;  // product name

  cout << "\t\t\t-----------------------------------\n";
  cout << "\t\t\t                                   \n";
  cout << "\t\t\t        Add New Product            \n";
  cout << "\t\t\t                                   \n";
  cout << "\t\t\t-----------------------------------\n";
  cout << "\t\t\t                                   \n";
  cout << "\n\t product Code:  ";
  cin>> pcode;
  cout << "\n\t Name Of Product:  " ;
  cin >> pname;
  cout << "\n\t Price Of Product:  ";
  cin >> price;

  data.open("database.txt", ios::in);

  if(!data) // if the database not created
  {
    data.open("database.txt", ios::app | ios::out);
    data << pcode << " " << pname << " " << price << "\n";
    data.close();
  }
  else // if the database already created
  {
    data >> c >> n >> p;

    while(!data.eof())
    {
      if( c == pcode)
      {
        token++;
      }
      data >> c >> n >> p;
    }
    data.close();
  
  if(token == 1)
  {
    goto m;
  }
  else
  {
    data.open("database.txt", ios::app | ios::out);
    data << pcode << " " << pname << " " << price << "\n";
    data.close();
  }
}
    cout << "\n\n\t\t Record inserted !\n\n";
}


void Shopping::edit()
{
  fstream data,data1;
  int pkey;
  int token = 0;
  int c;
  float p;
  string n;

  cout << "\n\t\t\t Modifiy The Record";
  cout << "\n\t\t Enter Product Code: ";
  cin >> pkey;

  data.open("database.txt", ios::in);

  if(!data)
  {
    cout << "\n\n File Dosen't Exist";
  }
  else
  {
    data1.open("database1.txt", ios::app | ios::out);

    data >> pcode >> pname >> price;

    while(!data.eof())
    {
      if(pkey == pcode)
      {
        cout << "\n\t\t Enter product New Code: ";
        cin >> c;

        cout << "\n\t\t Enter Product Name: ";
        cin >> n;

        cout << "\n\t\t Enter Product Price: ";
        cin >> p;

        data1 << c << " " << n << " " << p << "\n";

        cout << "\n\t\t Record has been edited";

        token++;
      }
      else
      {
        data1 << pcode << " " << pname << " " << price << "\n";
      }

      data >> pcode >> pname >> price;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token == 0)
    {
      cout << "\n\n Record not founded";
    }
  }

}


void Shopping::rem()
{
  fstream data,data1;
  int pkey;
  int token = 0;
  
  cout << "\n\n\t\t Delete Product";
  cout << "\n\n\t product Code:";
  cin >> pkey;

  data.open("database.txt", ios::in);

  if(!data)
  {
    cout << "file dosen't exist";
  }
  else
  {
    data1.open("database1.txt", ios::app | ios::out);
    data >> pcode >> pname >> price;

    while(!data.eof())
    {
        if(pcode == pkey)
        {
          cout << "\n\n\t Product deleted successfully";
          token++;
        }
        else
        {
          data1 << pcode << pname << price << "\n";
        }
        data >> pcode >> pname >> price;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token == 0)
    {
      cout << "Record Not Founded";
    }
  }
}


void Shopping::list()
{
  fstream data;
  data.open("database.txt", ios::in);

  cout << "\n\n                                            \n";
  cout << " Product Code \t\t Name \t\t Price\n";
  cout << "\n\n                                            \n";
  data >> pcode >> pname >> price;

  while(!data.eof())
  {
    cout <<"\t" << pcode << "\t\t" <<pname << "\t\t" << price << "\n";
    data >> pcode >> pname >> price;
  }
  data.close();
}


void Shopping::receipt()
{
  fstream data;
  int c = 0;
  float amount = 0;
  float total = 0;
  char choice;
  int arrc[100]; // array of product codes
  int arrq[100]; // array of quantities

  cout << "\n\n\t\t\t Receipt ";

  data.open("database.txt", ios::in);
  if(!data)
  {
    cout << "Empty database.";
  }
  else
  {
    data.close();

    list();
    cout << "\n\t\t----------------------------\n";
    cout << "\n\t\t     Place Your Order       \n";
    cout << "\n\t\t----------------------------\n";

    do
    {
      m:
      cout << "Enter Product Code: ";
      cin >> arrc[c];

      cout << "Enter Product Quantity: ";
      cin >> arrq[c];

      for(int i = 0; i < c; i++)
      {
        if(arrc[c] == arrc[i])
        {
          cout << "Product code is duplicated, Try again\n";
          goto m;
        }
      }
      c++;
      cout << "Do You Want to Buy Another Product? If Yes, Press (y) Else (n): ";
      cin >> choice;
    }
    while(choice == 'y');

    cout << "\n\n\n\t\t\t                   RECEIPT                 \n\n";
    cout << " " << "Pro.Num" << "\t" << "Pro.Name" << "\t" << "Pro.Quantity" << "\t" << "Pro.Price" << "\t" << "Pro.Amount\n\n";

    for(int i = 0; i < c; i++)
    {
      data.open("database.txt", ios::in);
      data >> pcode >> pname >> price;
      while(!data.eof())
      {
        if(pcode == arrc[i])
        {
          amount = price * arrq[i];
          total += amount;
          cout << " " << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\n";
        }
        data >> pcode >> pname >> price;
      }
      data.close();
    }
  }

  cout << "\n\n--------------------------------------\n";
  cout << "Total Amount = " << total << "\n\n";
}


int main()
{
  Shopping s;
  s.menu();
  return 0;
}