#include<bits/stdc++.h>
using namespace std;
class coffee
{
public:

    string name;
    float price ;
    float m;
 virtual int display()=0;
 friend void print();
 float sizee(int n);
 float bill(float m);
 float extra(int m);

};
class espresso:public coffee
{
public:
    espresso()
    {
       name="espresso";
       price=2.5;
    }
    display()
    {
        cout<<"**"<<name<<" has been selected"<<endl;
    }
};
class americano:public coffee
{
public:

    americano()
    {
        name="americano";
        price=3.0;
    }
    display()
    {
        cout<<"**"<<name<<" has been selected"<<endl;
    }
};
class latte:public coffee
{
public:

  latte()
  {
      name="latte";
      price=2.8;
  }
  display()
  {
      cout<<"**"<<name<<" has been selected"<<endl;
  }
};
class capaccino:public coffee
{
public:

   capaccino()
   {
       name="cappuccino";
       price=2.1;
   }

   display()
   {
       cout<<"**"<<name<<" has been selected"<<endl;
   }
};

float coffee::sizee(int m)
{
    if(m==1)
    {
        return 1.0;
    }
    if(m==2)
    {
        return 1.25;
    }
    if(m==3)
    {
        return 1.5;
    }
    else
    {
        cout<<"wrong input ,regular size has been choosen instead"<<endl;
        return 1.25;
    }
}
float coffee::extra(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 2.1;
    }
    if(n==2)
    {
        return 1.7;
    }
    if(n==3)
    {
        return 3.5;
    }
    else
    {
        cout<<"wrong input ,no extras added"<<endl;
        return 0;
    }

}
float coffee::bill(float n)
{
    return n*price;
}

void print()
{
    cout<<"======menu======"<<endl;
    cout<<"1 espresso - $2.5"<<endl;
    cout<<"2. latte - $3.0"<<endl;
    cout<<"3. cappuccino - $2.8"<<endl;
    cout<<"4. american0- $2.5"<<endl;
    cout<<"================"<<endl;
}
void printportion()
{
    cout<<"===portion size===="<<endl;
    cout<<"1. small- 1 times the cost"<<endl;
    cout<<"2. regular- 1.25 times the cost"<<endl;
    cout<<"3. large- 1.5 times the cost"<<endl;
    cout<<"====================="<<endl;
}

printadditionals()
{
    cout<<"=====additonal milk/sugar===="<<endl;
    cout<<"0. no additional milk/sugar"<<endl;
    cout<<"1. additional milk"<<endl;
    cout<<"2. additional sugar"<<endl;
    cout<<"3. additional both milk and sugar"<<endl;
    cout<<"======================="<<endl;
}
ostream& operator<<(ostream& print,coffee *obj)
{
    print<<obj->m;
    return print;
}
float calculatemoney(coffee *obj ,float money)
{
    if(money>obj->m)
    {
        return money-obj->m;
    }
}
int main()
{
    print();
    int n;
    cout<<"which coffee do you want :D"<<endl;
    cin>>n;
    coffee *obj ;
    if(n==1)
    {
        obj=new espresso();
    }
    if(n==2)
    {
        obj=new latte();
    }
    if(n==3)
    {
        obj=new capaccino();
    }
    if(n==4)
    {
        obj=new americano();
    }
    obj->display();
    printportion();
    cout<<"which size do you want?"<<endl;
    int sizetype;
    cin>>sizetype;
    float m=obj->sizee(sizetype);
    float p=obj->bill(m);

    printadditionals();

    cout<<"do you want extra milk/sugar?"<<endl;
    int additional;
    cin>>additional;
    float total;
    total=obj->extra(additional);
    obj->m=p+total;
    cout<<"your total cost is "<<obj<<endl;
    cout<<"enter your bill "<<endl;
    float money;
    cin>>money;
    float extra=calculatemoney(obj,money);
    cout<<"your returns are $"<<extra<<endl;



}
