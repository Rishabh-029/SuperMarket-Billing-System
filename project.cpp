#include<iostream>
#include<fstream>

using namespace std;

class shopping{
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

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;


    cout<<"\t\t\t\t\t\t_______________________________________________________\n";
     cout<<"\t\t\t\t\t\t\t\t                                                  \n";
      cout<<"\t\t\t\t\t\t             SUPERMARKET MAIN MENU                   \n";
        cout<<"\t\t\t\t\t\t\t\t                                                  \n";
         cout<<"\t\t\t\t\t\t_______________________________________________________\n";
          cout<<"\t\t\t\t\t\t\t\t                                 \n";
          cout<<"\t\t\t\t\t\t|       1)Administrator    |\n";
          cout<<"\t\t\t\t\t\t\t\t                       \n";
          cout<<"\t\t\t\t\t\t\t\t                       \n";
          cout<<"\t\t\t\t\t\t|       2)Buyer            |\n";
          cout<<"\t\t\t\t\t\t\t\t                       \n";
           cout<<"\t\t\t\t\t\t\t\t                       \n";
          cout<<"\t\t\t\t\t\t|       3)Exit             |\n";
          cout<<"\t\t\t\t\t\t\t\t                       \n";
           cout<<"\n\t\t\t please select";
            cin>>choice;

            switch(choice)
            {
                case 1:

                    cout<<"\t\t\t please Login\n";
                    cout<<"\t\t\t Enter Email\n";
                     cin>>email;
                    cout<<"\t\t\t Enter password\n";
                    cin>>password;

                 if(email=="admin@email.com" && password=="admin@123")
                 {
                     administrator();
                 }
                 else
                 {
                     cout<<"Invalid Email/Password";
                 }
                 break;

                case 2:
                {
                    buyer();
                }

                case 3:
                {
                    exit(0);
                }
                default:
                    {
                     cout<<"please select from the given options";
                    }
            }
            goto m;
}


void shopping::administrator()
{
    m:
    int choice;
    cout<<"\t\t\t Administrator Menu\n";
    cout<<"\t\t\t| 1)ADD THE PRODUCT |\n";
    cout<<"\t\t\t| 2)MODIFY THE PRODUCT |\n";
    cout<<"\t\t\t| 3)DELETE THE PRODUCT |\n";
    cout<<"\t\t\t| 4)BACK TO MAIN MENU |\n";
    cout<<"\t please enter your choice\n";
    cin>>choice;


    switch(choice)
    {
        case 1: add();
                break;

         case 2: edit();
                break;

          case 3: rem();
                break;

          case 4: menu();
                break;

          default:
            cout<<"Invalid choice";

    }
    goto m;
}

void shopping::buyer()
{
     m:
     int choice;
    cout<<"\t\t\t Buyer\n";
     cout<<"\t\t\t____________\n";
    cout<<"\t\t\t| 1)Buy Product |\n";
    cout<<"\t\t\t| 2)Go Back|\n";
    cout<<"enter choice";
    cin>>choice;

    switch(choice)
    {
         case 1: receipt();
                break;

          case 2: menu();
                break;

          default:
            cout<<"Invalid choice";
    }
    goto m;
}

void shopping::add()
{
    m:
    fstream data;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t\t\t Enter product code of the product";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the Product";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the product";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on the product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{

         data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)
        goto m;
     else{
         data.open("database.txt",ios::app|ios::out);
         data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
         data.close();
     }
  }
    cout<<"\n\n\t\t Record Inserted!";

}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t product code";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\n file doesn't exist!";

    }
    else{
          data1.open("database1.txt",ios::app|ios::out);

          data>>pcode>>pname>>price>>dis;
          while(!data.eof())
          {
              if(pkey==pcode)
              {
                  cout<<"\n\n\t product new code";
                  cin>>c;
                  cout<<"\n\t\t Name of the product";
                  cin>>n;
                  cout<<"\n\t\t price";
                  cin>>p;
                  cout<<"\n\t\t discount";
                  cin>>d;
                  data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                  cout<<"\n\n\t\t Record Edited";
                  token++;

              }
              else{
                   data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
              }
              data>>pcode>>pname>>price>>dis;
          }
          data.close();
          data1.close();

          remove("database.txt");
          rename("database1.txt","database.txt");

           if(token==0)
           {
               cout<<"\n\n Record not found sorry!";
           }

    }

}


void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doesn't exist";
    }

    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n product deleted successfully";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
             data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________\n";
    cout<<"ProNo\t\tName\tprice\n";
     cout<<"\n\n|_______________________________\n";
     data>>pcode>>pname>>price>>dis;

     while(!data.eof())
     {
         cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
         data>>pcode>>pname>>price>>dis;
     }
     data.close();

}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t Receipt";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else{
        data.close();
        list();
           cout<<"\n_______________________________________________________\n";
     cout<<"\n                                                  \n";
      cout<<"\n\t            please Place the order                  \n";
        cout<<"\n\t\t\t                                                  \n";
         cout<<"\n_______________________________________________________\n";

         do{
             m:
             cout<<"\n\nEnter product code";
             cin>>arrc[c];
              cout<<"\n\nEnter product quantity";
             cin>>arrq[c];

             for(int i=0;i<c;i++)
             {
                 if(arrc[c]==arrc[i])
                    {
                        cout<<"\n\nDuplicate product code.please try again!";
                        goto m;
                    }
             }
             c++;
             cout<<"\n\n Do you want to buy another product if yes then press y else  n for no";
             cin>>choice;
         }
         while(choice=='y');

         cout<<"\n\n\n\t\t\t_________________________RECEIPT______________________________________________\n";
         cout<<"\nProduct NO\t Product Name\tProductquantity\t price\tAmount\tAmount with discount\n";

         for(int i=0;i<c;i++)
         {
              data.open("database.txt",ios::in);
              data>>pcode>>pname>>price>>dis;

              while(!data.eof())
              {
                  if(pcode==arrc[i])
                  {
                      amount=price*arrq[i];
                      dis=amount-(amount*dis/100);
                      total=total+dis;
                      cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                  }
                  data>>pcode>>pname>>price>>dis;
              }

         }
         data.close();

    }
    cout<<"\n\n ________________________________________________________________________________";
    cout<<"\n Total Amount"<<total;

}

int main()
{
    shopping s;
    s.menu();
}