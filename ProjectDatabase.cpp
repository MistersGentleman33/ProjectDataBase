//
// Created by Axel Caballero on 05/01/23.
//
#include <iostream>
#include "iomanip"
#include <map>
#include <vector>
using namespace std;


struct Employers
        {
            char rfc[11];
            char name[30];
            char last_name[30];
            int salary;
            char dpt[3];
            int year_income;
            int age;
        }employ[6] ={{"SACV750524", "Veronica", "Sanchez", 6000, "A1", 2004, 34},
                      {"HEFC790926", "Carlos", "Hernandez", 8000, "A2", 2003, 18},
                     {"ROPJ081001", "Jose", "Rojas", 10000, "A2", 2003, 22},
                     {"ROA0740114", "Oscar", "Romero", 8000, "A1", 2002, 14},
                     {"FORG760206", "German", "Flores", 12000, "A1", 2002, 80},
                     {"PEVN780704", "Noe", "Perez", 15000, "A3", 2002, 22}};

struct department
    {
        int idDep;
        char name[30];
        int areaEdificio;
    }departamento[6] ={{1,"Adminitracion", 1},
                        {2,"Ventas",5},
                        {3, "Compras",7},
                        {4, "Produccion", 3},
                        {5, "Finanzas", 9},
                        {6, "Recursos Humanos", 4},};

struct newEmployers
{
    char rfc[11];
    char name[30];
    char last_name[30];
    int salary;
    char dpt[3];
    int year_income;
    int age;
}newEmploy[6]={{"SACV750524", "Veronica", "Sanchez", 6000, "A1", 2004, 34},
               {"ROPJ081001", "Jose", "Rojas", 10000, "A2", 2003, 22},
               {"REFFDAWFDW", "Omar", "Ramirez", 7000, "A3", 2005,27},
               {"LKSAMDALSD", "Selena ","Martinez", 9500, "A4", 2006, 25},
               {"SADCKLDSCN", "Luis", "Lopez", 8000, "A5", 2007, 30},
               {"PODPASODAS", "Juan", "Perez", 9000, "A1", 2005, 27}};

void interseccion(){
    start:
    ::system("clear");
    cout<<"Interseccion de las siguientes tablas: \n"<<endl;
    cout<<"Empleados \n"<<endl;
    cout<<left<<setw(13)<<"RFC"<<left<<setw(11)<<"Name"<<left<<setw(11)<<"Last_Name"<<left<<setw(8)<<"Salary"<<left<<setw(5)<<"DPT"<<left<<setw(14)<<"Año de inicio"<<left<<setw(3)<<"Edad"<<endl;
    for (auto & i : employ)
    {
        cout<<left<<setw(13)<<i.rfc<<left<<setw(11)<<i.name<<left<<setw(11)<<i.last_name<<left<<setw(8)<<i.salary<<left<<setw(5)<<i.dpt<<left<<setw(14)<<i.year_income<<left<<setw(3)<<i.age<<endl;
    }
    cout<<"Nuevos Empleados \n"<<endl;
    cout<<left<<setw(13)<<"RFC"<<left<<setw(11)<<"Name"<<left<<setw(11)<<"Last_Name"<<left<<setw(8)<<"Salary"<<left<<setw(5)<<"DPT"<<left<<setw(14)<<"Año de inicio"<<left<<setw(3)<<"Edad"<<endl;
    for(auto & i: newEmploy)
    {
        cout<<left<<setw(13)<<i.rfc<<left<<setw(11)<<i.name<<left<<setw(11)<<i.last_name<<left<<setw(8)<<i.salary<<left<<setw(5)<<i.dpt<<left<<setw(14)<<i.year_income<<left<<setw(3)<<i.age<<endl;
    }
    cout<<"Interseccion \n"<<endl;
    cout<<left<<setw(13)<<"RFC"<<left<<setw(11)<<"Name"<<left<<setw(11)<<"Last_Name"<<left<<setw(8)<<"Salary"<<left<<setw(5)<<"DPT"<<left<<setw(14)<<"Año de inicio"<<left<<setw(3)<<"Edad"<<endl;
    for(auto & i : newEmploy)
    {
        for(auto & j : employ)
        {
            if(i.rfc == j.rfc)
            {
                cout<<left<<setw(13)<<i.rfc<<left<<setw(11)<<i.name<<left<<setw(11)<<i.last_name<<left<<setw(8)<<i.salary<<left<<setw(5)<<i.dpt<<left<<setw(14)<<i.year_income<<left<<setw(3)<<i.age<<endl;
            }
        }
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );


}

void reunion()
{

    cout<<"****\tEste es un ejemplo de la operacion Reunion********\n\n";
    vector<vector<int>> table1 = {{1, 23}, {3, 123}, {5, 343}};
    vector<vector<int>> table2 = {{2, 12132}, {3, 34333}, {5, 54545}};
    map<int, vector<int>> map1;
    vector<vector<int>> result;

    cout<<"FABRICA\n";
    cout<<"ID  "<<" Empleados"<<endl;

    for (int i = 0; i < table1.size(); i++)
    {
        for (int j = 0; j < table1[i].size(); j++)
            cout << table1[i][j] << " \t  ";
        cout << endl;
    }cout<<"-----------------------\n";


    cout<<"PRODUCCION"<<endl;
    cout<<"IDFabrica  "<<" Cantidad"<<endl;
    for (int i = 0; i < table2.size(); i++)
    {
        for (int j = 0; j < table2[i].size(); j++)
            cout << table2[i][j] << "\t\t\t";
        cout << endl;
    }cout<<"-------------------------\n";


    // Almacenar las filas de la primera tabla en un mapa
    for (int i = 0; i < table1.size(); i++)
        map1[table1[i][0]] = table1[i];

    // Recorrer las filas de la segunda tabla
    for (int i = 0; i < table2.size(); i++)
    {
        // Buscar una fila con el mismo valor en el primer campo en el mapa
        if (map1.find(table2[i][0]) != map1.end())
        {
            // Combinar las filas
            vector<int> row;
            for (int j = 0; j < map1[table2[i][0]].size(); j++)
                row.push_back(map1[table2[i][0]][j]);
            for (int j = 1; j < table2[i].size(); j++)
                row.push_back(table2[i][j]);
            result.push_back(row);
        }
    }


    cout<<"IDFabrica  "<<"Empleados  "<<" Produccion"<<endl;
    // Imprimir la tabla resultante
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << "\t\t\t";
        cout << endl;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

}

void selection()
{
    start:
    ::system("clear");
    int option;
    cout<<"\n\t******* Here you can choose examples of selection algorithm ********\n";
    cout<<"1. Age>15\n2. 8000 < Salary < 15000\n3. Year Income = 2002\n\nYour option: "; cin>>option;
    switch (option) {
        case 1:
            cout<<left<<setw(13)<<"RFC"<<left<<setw(11)<<"Name"<<left<<setw(11)<<"Last_Name"
            <<left<<setw(8)<<"Salary"<<left<<setw(5)<<"DPT"<<left<<setw(14)<<"Year_Income"<<left<<setw(3)<<"age"
            <<endl;
            for (auto & i: employ)
            {
                if (i.age > 15)
                {
                    cout<<left<<setw(13)<<i.rfc<<left<<setw(11)<<i.name<<left<<setw(11)<<i.last_name<<left
                    <<setw(8)<<i.salary<<left<<setw(5)<<i.dpt<<left<<setw(14)<<i.year_income<<left
                    <<setw(3)<<i.age<<endl;
                }
            }
            break;
        case 2:
            for (auto & i : employ)
            {
                if(i.salary>=8000 and i.salary<=20000)
                {
                    cout<<left<<setw(13)<<i.rfc<<left<<setw(11)<<i.name<<left<<setw(11)<<i.last_name<<left
                        <<setw(8)<<i.salary<<left<<setw(5)<<i.dpt<<left<<setw(14)<<i.year_income<<left
                        <<setw(3)<<i.age<<endl;
                }
            }break;
        case 3:
            for (auto & i : employ) {
                if (i.year_income == 2002)
                {
                    cout << left << setw(13) << i.rfc << left << setw(11) << i.name << left << setw(11) << i.last_name
                         << left
                         << setw(8) << i.salary << left << setw(5) << i.dpt << left << setw(14) << i.year_income << left
                         << setw(3) << i.age << endl;
                }
            }break;
    }
    cout<<"\nDo you want to try other? 1.YES  2.NO: "; cin>>option;
    if (option == 1){goto start;}

}

void proyection()
{
    start:
    ::system("clear");
    int option = 0;
    cout<<"Which attribute you want?: \n";
    cout<<"1. RFC\n2. Name\n3.Last Name\n4. Salary\n5.Department\n6. Year Income\n\nYour option: "; cin>>option;
    cout<<endl;
    switch (option)
    {
        case 1:
            cout<<"RFC"<<endl;
            for (auto & i : employ)
            {
                cout<<i.rfc<<endl;
            }break;
        case 2:
            cout<<"Name"<<endl;
            for (auto & i : employ)
            {
                cout<<i.name<<endl;
            }break;

        case 3:
            cout<<"Last Name"<<endl;
            for (auto & i : employ)
            {
                cout<<i.last_name<<endl;
            }break;
        case 4:
            cout<<"Salary"<<endl;
            for (auto & i : employ)
            {
                cout<<i.salary<<endl;
            }break;
        case 5:
            cout<<"Department"<<endl;
            for (auto & i : employ)
            {
                cout<<i.dpt<<endl;
            }break;
        case 6:
            cout<<"Year Income"<<endl;
            for (auto & i : employ)
            {
                cout<<i.year_income<<endl;
            }break;
    }
    int option2 = 0;
    cout<<"Do you want other attribute 1. Yes, 2. No: "; cin>>option2;
    if (option2 == 1){ goto start;}

}

void productoCruz()
{
    //start:
    ::system("clear");
    
    cout<<"Producto Cartesiano \n"<<endl;
    cout<<left<<setw(13)<<"RFC"<<left<<setw(5)<<"Name"<<left<<setw(11)<<"Last_Name"<<left<<setw(8)<<"Salary"<<left<<setw(5)<<"DPT"<<left<<setw(14)<<"Year_Incame"<<left<<setw(3)<<"age"<<left<<setw(5)<<"ID"<<left<<setw(11)<<"Name"<<left<<setw(11)<<"AreaEdificio"<<endl;
    for(auto & i : departamento)
    {
        for(auto & j : employ)
        {
            cout<<j.rfc<<" | "<<j.name<<" "<<j.last_name<<" | "<<j.salary<<" | "<<j.dpt<<" | "<<j.year_income<<" | "<<j.age<<" | "<<i.idDep<<" | "<<i.name<<" | "<<i.areaEdificio<<endl;
        }
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

}

void menu()
{
    int option = 0;

    do
    {
        ::system("clear");
        cout<<"\t*******WELCOME*********\n";
        cout<<"1. Proyeccion"<<endl;
        cout<<"2. Seleccion"<<endl;
        cout<<"3. Producto Cruz"<<endl;
        cout<<"4. Union"<<endl;
        cout<<"5. Diferencia"<<endl;
        cout<<"6. Interseccion"<<endl;
        cout<<"7. Reunion"<<endl;
        cout<<"8. !!Exit!!"<<endl;

        cout<<"\nYour option here: "; cin>>option;
        switch (option) {
            case 1:
                proyection(); break;
            case 2:
                selection(); break;
            case 3:;
                productoCruz(); break;
            case 4:;
            case 5:;
            case 6:interseccion();break;
            case 7: reunion(); break;
            case 8:
                option = 8;
        }
    }
    while (option != 8);


}

int main()
{
    menu();

    return 0;
}