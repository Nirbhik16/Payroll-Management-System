#include <iostream>
#include <fstream>
#include <string.h>
#include<iomanip>
using namespace std;

class Employee
{
private:
    int emp_num;
    char emp_status;
    char emp_name[25];
    unsigned long long int emp_mno;
    int emp_age;
    char emp_gender[10];
    char emp_designation[20];
    char emp_city[50];
    int days_worked;
    float basic_pay;
    float DA;  //Dearness allowance
    float HRA; //House rent allowance
    float TA;  //Transport allowance
    float MA;  //medical allowance
    float gross_pay;
    float PF;
    float income_tax;
    float bus_deduction;
    float CWF = 15; //Company welfare fund
    float other_deductions;
    float net_pay;
    float deductions;

public:
    void NEW_EMPLOYEE(void);//
    void OTHER_DETAILS(void);
    void MODIFICATION(void);//
    int MOD_ITDT();
    void MOD_DELETION(void);
    void DELETION(void);//
    void LIST(void);
    char SALARY_SLIP(void);//mobile no,gender,age,income tax,modification file handling
    int oldemp();
    void OTDT_LIST();
    char *return_num()
    {
        char *empl_num = (char *)emp_num;
        return empl_num;
    }
};
int Employee::oldemp()
{
    cout<<"Enter employee number:";
    cin>>emp_num;
    fstream fin;
    fin.open("emp.txt",ios::in|ios::out);
    int c=emp_num;
    int b = 0;
    char str[25];
    char str1[30];
    char str2[30];
    int pay = 0;
    int line_no = 0;
    int no = 0;
    while(!fin.eof())
    {
        fin >> b >> str >> str1 >> str2 >> pay;
        if(c==b){
        emp_num=b;
        strcpy(emp_name,str);
        strcpy(emp_city,str1);
        strcpy(emp_designation,str2);
        basic_pay=pay;
        DELETION();
        no=line_no;
        break;
        }
        line_no++;
    }
    fin.close();
    char choice;
    cout << "What do you want to modify?\nChoose from the following:\ntype 1 for name\ntype 2 for designation\ntype 3 for city\ntype 4 for basic pay\ntype 5 for exit\n";
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "enter the new name:\n";
        cin >> emp_name;
        break;
    case '2':
        cout << "enter new designation:\n";
        cin >> emp_designation;
        break;
    case '3':
        cout << "enter new city(if chandigarh write chd):\n";
        cin >> emp_city;
        break;
    case '4':
        cout << "enter basic pay:\n";
        cin >> basic_pay;
        break;
    case '5':
        return 0;
    default:
        break;
    }
    ifstream f;
    f.open("emp.txt");
    int z = 0;
    char stn[25];
    char stn1[30];
    char stn2[30];
    int pay1 = 0;
    int line= 0;
    while(!f.eof())
    {
        f >> z >> stn >> stn1 >> stn2 >> pay1;
        line++;
    }
    f.close();
    fstream file;
    file.open("emp.txt",ios::in);
    fstream fotd;
    fotd.open("otd.txt",ios::out|ios::trunc);
    b = 0;
    str[25];
    str1[30];
    str2[30];
    pay = 0;
    line_no = 0;
    for(int i=0;i<line;i++)
    {
        if(no==line_no){
            fotd<<c<<" "<<emp_name<<" "<<emp_city<<" "<<emp_designation<<" "<<basic_pay<<endl;
        }
        else{
        file >> b >> str >> str1 >> str2 >> pay;
        fotd<<b<<" "<<str<<" "<<str1<<" "<<str2<<" "<<pay<<" "<<endl;
        }
        line_no++;
    }
    file.close();
    fotd.close();
    fstream it;
    it.open("otd.txt");
    fstream oft;
    oft.open("emp.txt",ios::out|ios::trunc);
    char ch;
    while (!it.eof())
    {
        it.get(ch);
        oft<<ch;
    }
}
/*
int Employee::newemp()
{
    cout << "\nEnter name of Employee: ";
    cin >> emp_name;
    cout << "\nEnter city of residence: ";
    cin >> emp_city;
    cout << "\nEnter designation: ";
    cin >> emp_designation;
    cout << "\nEnter basic pay of Employee: ";
    cin >> basic_pay;
}*/
void Employee::NEW_EMPLOYEE()
{
    ofstream outf;
    outf.open("emp.txt", ios::app);
    cout << "Enter employee number: ";
    cin >> emp_num;
    cout << "\nEnter name of Employee: ";
    cin >> emp_name;
    cout << "\nEnter city of residence(if chandigarh write chd): ";
    cin >> emp_city;
    cout << "\nEnter designation: ";
    cin >> emp_designation;
    cout << "\nEnter basic pay of Employee: ";
    cin >> basic_pay;
    outf << emp_num << " " <<emp_name<<" "<<emp_city << " "<<emp_designation << " "<<basic_pay<<endl;
    outf.close();
}
void Employee::OTHER_DETAILS()
{
    ofstream out;
    out.open("otdt1.txt",ios::app);
    cout<<"Enter employee number:";
    cin>>emp_num;
    cout<<"Enter mobile no. of employee:";
    cin>>emp_mno;
    cout<<"Enter age of employee:";
    cin>>emp_age;
    cout<<"\nEnter gender of employee:";
    cin>>emp_gender;
    out<<emp_num<<" "<<emp_mno<<" "<<emp_age<<" "<<emp_gender<<endl;
    out.close();
}
int Employee::MOD_ITDT()
{
    cout<<"Enter employee number :";
    cin>>emp_num;
    fstream in;
    in.open("otdt1.txt",ios::in|ios::out);
    int c=emp_num;
    int b = 0;
    unsigned long long mno;
    int g;
    char str[30];
    int line_no = 0;
    int no = 0;
    while(!in.eof())
    {
        in >> b >> mno >> g >> str;
        if(c==b){
        emp_num=b;
        emp_mno=mno;
        emp_age=g;
        strcpy(emp_gender,str);
        MOD_DELETION();
        no=line_no;
        break;
        }
        line_no++;
    }
    in.close();
    char choice;
    cout << "What do you want to modify?\nChoose from the following:\ntype 1 for mobile number\ntype 2 for age\ntype 3 for gender\ntype 4 for exit\n";
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "enter the new mobile number:\n";
        cin >> emp_mno;
        break;
    case '2':
        cout << "enter new age:\n";
        cin >> emp_age;
        break;
    case '3':
        cout << "enter gender:\n";
        cin >> emp_gender;
        break;
    case '4':
        return 0;
    default:
        break;
    }
    ifstream of;
    of.open("otdt1.txt");
    int z = 0;
    unsigned long long mno1;
    int h;
    char str5[30];
    int line= 0;
    while(!of.eof())
    {
        of >> z >> mno1 >> h >> str5;
        line++;
    }
    of.close();
    fstream fout;
    fout.open("otdt1.txt",ios::in);
    fstream out;
    out.open("mod.txt",ios::out|ios::trunc);
    b = 0;
    mno=0;
    g;
    str[30];
    line_no = 0;
    for(int i=0;i<line-1;i++)
    {
        fout >> b >> mno >> g >> str;
        if(no==line_no){
            out<<c<<" "<<emp_mno<<" "<<emp_age<<" "<<emp_gender<<endl;
        }
        else{
        out<<b<<" "<<mno<<" "<<g<<" "<<str<<endl;
        }
        line_no++;
    }
    fout.close();
    out.close();
    fstream tit;
    tit.open("mod.txt");
    fstream toft;
    toft.open("otdt1.txt",ios::out|ios::trunc);
    char ch;
    while (!tit.eof())
    {
        tit.get(ch);
        toft<<ch;
    }
    tit.close();
    toft.close();
}
void Employee::MOD_DELETION()
{
    fstream mof;
    mof.open("otdt1.txt");
    int z = 0;
    unsigned long long mno1;
    int h;
    char str5[30];
    int line= 0;
    while(!mof.eof())
    {
        mof >> z >> mno1 >> h >> str5;
        line++;
    }
    fstream file;
    file.open("otdt1.txt");
    cout << "enter your employee number:\n";
    cin >> emp_num;
    int c = emp_num;
    int b = 0;
    unsigned long long mno;
    int g;
    char str[30];
    int line_no = 0;
    int no = 0;
    for (int i = 0; i < line; i++)
    {
        file >> b >> mno >> g >> str;
        line_no++;
        if (c == b)
        {
            no = line_no;
            break;
        }
    }
    const char *file_name = "b.txt";

    fstream is(file_name,ios::out);

    fstream ofs;
    ofs.open("otdt1.txt");
    char d;
    line_no=1;
    while (!ofs.eof())
    {
        ofs.get(d);
        if (line_no != no)

            is << d;
        if (d == '\n')
            line_no++;
    }
    ofs.close();
    is.close();
    fstream it;
    it.open("b.txt");
    fstream oft;
    oft.open("otdt1.txt",ios::out);
    char ch;
    while (!it.eof())
    {
        it.get(ch);
        oft<<ch;
    }
}
void Employee::MODIFICATION()
{
        oldemp();
}
void Employee::DELETION()
{
    ifstream f;
    f.open("emp.txt");
    int z = 0;
    char stn[25];
    char stn1[30];
    char stn2[30];
    int pay1 = 0;
    int line= 0;
    while(!f.eof())
    {
        f >> z >> stn >> stn1 >> stn2 >> pay1;
        line++;
    }
    fstream file;
    file.open("emp.txt");
    cout << "enter your employee number:\n";
    cin >> emp_num;
    int c = emp_num;
    int b = 0;
    char str[20];
    char str1[30];
    char str2[30];
    int pay = 0;
    int line_no = 0;
    int no = 0;
    for (int i = 0; i < line; i++)
    {
        file >> b >> str >> str1 >> str2 >> pay;
        line_no++;
        if (c == b)
        {
            no = line_no;
            break;
        }
    }
    const char *file_name = "a.txt";
    // open file in read mode or in mode

    fstream is(file_name,ios::out);

    // open file in write mode or out mode

    fstream ofs;
    ofs.open("emp.txt");
    // loop getting single characters
    char d;
    line_no=1;
    while (!ofs.eof())
    {
        ofs.get(d);
        // if a newline character
        if (line_no != no)

            is << d;
        if (d == '\n')
            line_no++;
        // file content not to be deleted

        // if (line_no != no)

        //     is << d;
    }
    // closing output file
    ofs.close();
    // closing input file
    is.close();
    // remove the original file
    // fstream abc;
    // abc.open("emp.txt",ios::in|ios::trunc);
    // remove(file_name);
    // // rename the file
    // rename("emp.txt", file_name);
    fstream it;
    it.open("a.txt");
    fstream oft;
    oft.open("emp.txt",ios::out);
    char ch;
    while (!it.eof())
    {
        it.get(ch);
        oft<<ch;
    }

}
char Employee::SALARY_SLIP()
{
    fstream file;
    file.open("emp.txt");
    cout << "Enter Employee Number: ";
    cin >> emp_num;
    int c = emp_num;
    int b = 0;
    char str[20];
    char str1[30];
    char str2[30];
    int pay = 0;
    while(!file.eof())
    {
        file >> b >> str >> str1 >> str2 >> pay;
        if (c == b)
        {
            basic_pay = pay;
            strcpy(emp_name, str);
            strcpy(emp_city, str1);
            break;
        }
    }
    DA = (69.75 * basic_pay) / 100;
    HRA = (59.5 * basic_pay) / 100;
    TA = (0.1 * basic_pay) / 100;
    MA = (0.169 * basic_pay) / 100;
    gross_pay = basic_pay + DA + HRA + TA + MA;
    PF = (14 * (basic_pay + DA)) / 100;
    if ((strcmp(emp_city, "CHD") == 0) || strcmp(emp_city, "chd") == 0)
    {
        bus_deduction = 0;
    }
    else
    {
        bus_deduction = 800;
    }
    int other_deductions;
    cout<<"Enter other deductions:";
    cin>>other_deductions;
    deductions = PF + other_deductions + bus_deduction + CWF;
    net_pay = gross_pay - deductions;
    cout << "Salary slip for the employee No. : " << emp_num << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << "Employee No.: " << emp_num << "                                         " << emp_name << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << "Earnings=" << endl;
    cout << "\nBasic=" << basic_pay << endl;
    cout << "DA=" << DA << endl;
    cout << "HRA=" << HRA << endl;
    cout << "TA=" << TA << endl;
    cout << "MA=" << MA << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << "Deductions=" << endl;
    cout << "\nBus Deduction=" << bus_deduction << endl;
    cout << "CWF=" << CWF << endl;
    cout << "PF=" << PF << endl;
    cout << "Other Deductions=" << other_deductions << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << "Gross Pay=" << gross_pay << "                                         "
         << "Deductions=" << deductions << endl;
    cout << "__________________________________________________________________________________" << endl;
    cout << "NET PAY=" << net_pay;
}
void Employee::LIST(){
    ifstream f;
    f.open("emp.txt");
    int z = 0;
    char stn[25];
    char stn1[30];
    char stn2[30];
    int pay1 = 0;
    int line= 0;
    while(!f.eof())
    {
        f >> z >> stn >> stn1 >> stn2 >> pay1;
        line++;
    }
    fstream fin;
    fin.open("emp.txt",ios::in);
    fin.seekp(0);
    int c = emp_num;
    int b = 0;
    char str[20];
    char str1[30];
    char str2[30];
    int pay = 0;
    cout<<"Employee No."<<setw(8)<<"Name"<<setw(12)<<"City"<<setw(18)<<"Designation"<<setw(12)<<"Basic Pay"<<endl;
    for(int i=0;i<line-1;i++)
    {
        fin >> b >> str >> str1 >> str2 >> pay;
        cout<<b<<setw(19)<<str<<setw(12)<<str1<<setw(14)<<str2<<setw(12)<<pay<<endl;
    }
    fin.close();
}
void Employee::OTDT_LIST(){
    fstream mof;
    mof.open("otdt1.txt");
    int z = 0;
    unsigned long long mno1;
    int h;
    char str5[30];
    int line= 0;
    while(!mof.eof())
    {
        mof >> z >> mno1 >> h >> str5;
        line++;
    }
    mof.close();
    fstream oin;
    oin.open("otdt1.txt",ios::in);
    oin.seekp(0);
    int c=emp_num;
    int b = 0;
    unsigned long long mno;
    int g;
    char str[30];
    int line_no = 0;
    int no = 0;
    cout<<"Employee No."<<setw(15)<<"Mobile Number"<<setw(12)<<"AGE"<<setw(18)<<"Gender"<<endl;
    for(int i=0;i<line-1;i++)
    {
        oin >> b >> mno >> g >> str;
        cout<<b<<setw(22)<<mno<<setw(14)<<g<<setw(15)<<str<<endl;
    }
    oin.close();
}

int main()
{
    Employee e;
    cout<<setw(75)<<"WELCOME TO PAYROLL MANAGEMENT SYSTEM"<<endl;
    cout<<setw(75)<<"____________________________________"<<endl;
    char choice;
    cout << "What do you want to Operate?\nChoose from the following:\nENTER A for registering details of New Employee\nENTER B for registering other details of New Employee"<<endl;
    cout<<"ENTER C for modifying details of Old Employee\nENTER D for modifying other details of Old Employee\nENTER E for displaying Salary Slip of an Employee\n";
    cout<<"ENTER F for displaying details of an Employee\nENTER G for displaying other details of an Employee\nENTER H to delete details of an Employee\n";
    cout<<"ENTER I to delete other details of an Employee\nENTER J to EXIT\n";
    cout<<setw(65)<<"****THANKYOU****\n";
    cin >> choice;
    switch (choice)
    {
    case 'A':
        e.NEW_EMPLOYEE();
        break;
    case 'B':
        e.OTHER_DETAILS();
        break;
    case 'C':
        e.MODIFICATION();
        break;
    case 'D':
        e.MOD_ITDT();
        break;
    case 'E':
        e.SALARY_SLIP();
        break;
    case 'F':
        e.LIST();
        break;
    case 'G':
        e.OTDT_LIST();
        break;
    case 'H':
        e.DELETION();
        break;
    case 'I':
        e.MOD_DELETION();
        break;
    case 'J':
        break;
    default:
        break;
    }
    cout<<setw(65)<<"****THANKYOU****\n";
}
