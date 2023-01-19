#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
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

    return 0;
}
