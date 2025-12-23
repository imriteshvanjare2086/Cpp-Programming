#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 100;
struct Employee
{
    string name;
    float salary;
};
void input_data(Employee e[],int &n)
{
    cout << "\n=============================================================================================";
    cout << "\n           ------ Performing Sorting Methods on Employee Data -----\n";
    cout << "=============================================================================================\n";
    cout << "\n--->Enter Number of Employees:" << " ";
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cout << "\n->Name of Employee no : " << i+1 << endl;
        getline(cin,e[i].name);
        cout << "\n";
        cout << "->Salary of Employee no : " << i+1 << "\n" << "Rs.";
        cin >> e[i].salary;
        cin.ignore();
    }
}

void display_data(Employee e[],int n)
{
    cout << "\nSr No\t\tEmployee Name\t\tSalary\t\t\n";
    for(int i=0;i<n;i++)
    {
        cout << i+1 << "\t\t"  << e[i].name << "\t\t" <<" Rs." << e[i].salary << endl;
    }
}
void bubble_sort(Employee e[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(e[j].salary > e[j+1].salary)
            {
                swap(e[j],e[j+1]);
            }
        }
    }
}
void selection_sort(Employee e[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int seidx = i;
        for(int j=i+1;j<n;j++)
        {
            if(e[seidx].salary > e[j].salary)
            {
                seidx = j;
            }
        }
        swap(e[i],e[seidx]);
    }
}
void insertion_sort(Employee e[],int n)
{
    for(int i=0;i<n;i++)
    {
        Employee curr = e[i];
        int prev = i-1;
        while(prev >=0 && e[prev].salary > curr.salary)
        {
            e[prev+1] = e[prev];
            prev--;
        }
        e[prev+1] = curr;
    }
}
int partition(Employee e[],int lb,int ub)
{
    float pivot = e[lb].salary;
    int st = lb;
    int end = ub;
    while(st < end)
    {
        while(e[st].salary <= pivot)
        {
            st++;
        }
        while(e[end].salary > pivot)
        {
            end--;
        }
        if(st < end)
        {
            swap(e[st],e[end]);
        }
    }
    swap(e[lb],e[end]);
    return end;
}
void quick_sort(Employee e[],int lb,int ub)
{
    if(lb < ub)
    {
        int p = partition(e,lb,ub);
        quick_sort(e,lb,p-1);
        quick_sort(e,p+1,ub);
    }
}
int main()
{
    Employee e[MAX];
    int n;
    int choice;
    input_data(e,n);
    char ch = 'Y';
    while(ch == 'Y' || ch == 'y')
    {
    cout << "\n                       --------- MENU --------                          \n";
    cout << "==========================================================================\n";
    cout << "     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----    ";
    cout << "\n==========================================================================\n";
    cout << "Press 1 to perform Bubble sort\n" ;
    cout << "Press 2 to perform Selection sort\n";
    cout << "Press 3 to perform Insertion sort\n"; 
    cout << "Press 4 to perform Quick sort\n";
    cout << "Press 5 to exit\n";
    cout << "-----------------------------------------------------------------------------";
    cout << "\n=> Enter Choice : " << " ";
    cin >> choice;
    cout << "------------------------------------------------------------------------------";
    switch(choice)
    {
        case 1:
        bubble_sort(e,n);
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n       ------- Employee Data after Bubble Sort -------\n" ;
        cout << "--------------------------------------------------------------------------------";
        display_data(e,n);
        break;

        case 2:
        selection_sort(e,n);
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n       ------- Employee Data after Selection Sort -------\n" ;
        cout << "-------------------------------------------------------------------------------";
        display_data(e,n);
        break;

        case 3:
        insertion_sort(e,n);
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n        ------- Employee Data after Insertion Sort -------\n" ;
        cout << "-------------------------------------------------------------------------------";
        display_data(e,n);
        break;

        case 4:
        quick_sort(e,0,n-1);
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n         ------- Employee data after Quick Sort -------\n";
        cout << "-------------------------------------------------------------------------------";
        display_data(e,n);
        break;

        case 5:
        ch = false;
        cout << "\n          ----- EXIT -----          " << endl;
        break;

        default:
        cout << "Invalid Choice" << endl;
    }
    cout << "\n--->Do You want to Continue(y/n) : ";
    cin >> ch;
    }
}

/*
=> OUTPUT :

=============================================================================================
           ------ Performing Sorting Methods on Employee Data -----
=============================================================================================

--->Enter Number of Employees: 4

->Name of Employee no : 1
Ritesh Vanjare

->Salary of Employee no : 1
Rs.500003

->Name of Employee no : 2
Deepak Patil

->Salary of Employee no : 2
Rs.500000

->Name of Employee no : 3
Chaitanya Patil

->Salary of Employee no : 3
Rs.500001

->Name of Employee no : 4
Shaizaan Shaikh

->Salary of Employee no : 4
Rs.500002

                       --------- MENU --------
==========================================================================
     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----
==========================================================================
Press 1 to perform Bubble sort
Press 2 to perform Selection sort
Press 3 to perform Insertion sort
Press 4 to perform Quick sort
Press 5 to exit
-----------------------------------------------------------------------------
=> Enter Choice :  1
------------------------------------------------------------------------------
-------------------------------------------------------------------------------
       ------- Employee Data after Bubble Sort -------
--------------------------------------------------------------------------------
Sr No           Employee Name           Salary
1               Deepak Patil             Rs.500000
2               Chaitanya Patil          Rs.500001
3               Shaizaan Shaikh          Rs.500002
4               Ritesh Vanjare           Rs.500003

--->Do You want to Continue(y/n) : y

                       --------- MENU --------
==========================================================================
     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----
==========================================================================
Press 1 to perform Bubble sort
Press 2 to perform Selection sort
Press 3 to perform Insertion sort
Press 4 to perform Quick sort
Press 5 to exit
-----------------------------------------------------------------------------
=> Enter Choice :  2
------------------------------------------------------------------------------
-------------------------------------------------------------------------------
       ------- Employee Data after Selection Sort -------
-------------------------------------------------------------------------------
Sr No           Employee Name           Salary
1               Deepak Patil             Rs.500000
2               Chaitanya Patil          Rs.500001
3               Shaizaan Shaikh          Rs.500002
4               Ritesh Vanjare           Rs.500003

--->Do You want to Continue(y/n) : y

                       --------- MENU --------
==========================================================================
     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----
==========================================================================
Press 1 to perform Bubble sort
Press 2 to perform Selection sort
Press 3 to perform Insertion sort
Press 4 to perform Quick sort
Press 5 to exit
-----------------------------------------------------------------------------
=> Enter Choice :  3
------------------------------------------------------------------------------
-------------------------------------------------------------------------------
        ------- Employee Data after Insertion Sort -------
-------------------------------------------------------------------------------
Sr No           Employee Name           Salary
1               Deepak Patil             Rs.500000
2               Chaitanya Patil          Rs.500001
3               Shaizaan Shaikh          Rs.500002
4               Ritesh Vanjare           Rs.500003

--->Do You want to Continue(y/n) : y

                       --------- MENU --------
==========================================================================
     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----
==========================================================================
Press 1 to perform Bubble sort
Press 2 to perform Selection sort
Press 3 to perform Insertion sort
Press 4 to perform Quick sort
Press 5 to exit
-----------------------------------------------------------------------------
=> Enter Choice :  4
------------------------------------------------------------------------------
-------------------------------------------------------------------------------
         ------- Employee data after Quick Sort -------
-------------------------------------------------------------------------------
Sr No           Employee Name           Salary
1               Deepak Patil             Rs.500000
2               Chaitanya Patil          Rs.500001
3               Shaizaan Shaikh          Rs.500002
4               Ritesh Vanjare           Rs.500003

--->Do You want to Continue(y/n) : y

                       --------- MENU --------
==========================================================================
     ----- Choose any 1 Method to perfrom Sorting on Employee Data -----
==========================================================================
Press 1 to perform Bubble sort
Press 2 to perform Selection sort
Press 3 to perform Insertion sort
Press 4 to perform Quick sort
Press 5 to exit
-----------------------------------------------------------------------------
=> Enter Choice :  5
------------------------------------------------------------------------------
          ----- EXIT -----

--->Do You want to Continue(y/n) : n
*/


























