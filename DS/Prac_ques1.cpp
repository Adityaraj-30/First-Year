// /* 1) Write a program to accept a directed Graph G and compute the in-degree and
// out-degree of each vertex. (User can directly input the matrix element or the edges
//  between the vertices).
// */

#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;

void printArray(int arr[][SIZE], int v, char vertice_name[]) // for printing matrix
{
    cout << endl
         << "   ";
    for (int i = 0; i < v; i++)
    {
        cout << vertice_name[i] << " ";
    }

    for (int k = 0; k < v; k++)
    {
        cout << endl;
        cout << vertice_name[k] << " |";
        for (int l = 0; l < v; l++)
            cout << arr[k][l] << " ";
        cout << "|";
    }
}

int foundCharAt(char vertice_name[], char ch, int v) //for checking
{
    for (int i = 0; i < v; i++)
    {
        if (vertice_name[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

bool foundChar(char vertice_name[], char ch, int v)
{
    for (int i = 0; i < v; i++)
    {
        if (vertice_name[i] == ch)
        {
            return true;
        }
    }
    return false;
}

int main() // main function
{
    int v;
    cout << "Enter the number of vertices : ";
    cin >> v; //input no of vertices
    char vertice_name[v] = {'\0'};
    int arr[SIZE][SIZE] = {0};
    int edges = 0;
    cout << "Enter the number of edges in the graph : ";
    cin >> edges; // input no of edges

    for (int i = 0; i < v; i++)
    {
        cout << "Enter the name of " << i + 1 << " vertice : "; //naming the vertex
        string s;
        cin >> s;
        if (s.length() != 1)
        {
            cout << "Entered vertice name should only be 1 character long. Enter again.\n";
            i--;
            continue;
        }

        if (foundChar(vertice_name, s.at(0), v)) //for uniqueness
        {
            cout << "Already entered name. Enter a unique value.\n";
            i--;
            continue;
        }
        vertice_name[i] = s.at(0);
    }

    for (int i = 0; i < edges; i++) //taking pair of vertex
    {
        char v1, v2;
        cout << "Enter the " << i + 1 << " pair of directed edge (vertex1 <SPACE> vertex2): ";
        cin >> v1 >> v2;
        if (!foundChar(vertice_name, v1, v) || !foundChar(vertice_name, v2, v))
        {
            cout << "Entered set of vertices does not match vertices provided. Enter again. : \n";
            i--;
            continue;
        }
        arr[foundCharAt(vertice_name, v1, v)][foundCharAt(vertice_name, v2, v)] += 1;
    }

    printArray(arr, v, vertice_name); //printing matrix
    cout << endl;
    for (int i = 0; i < v; i++) //for indegree and outdegree
    {
        int out_deg = 0, in_deg = 0;
        for (int j = 0; j < v; j++)
        {
            out_deg += arr[i][j];
            in_deg += arr[j][i];
        }
        cout << endl;
        cout << "Outdegree of " << vertice_name[i] << " : " << out_deg << endl; //showing outdegree
        cout << "Indegree of " << vertice_name[i] << " : " << in_deg << endl;   //showing indegree
    }
    return 0;
}