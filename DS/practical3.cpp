/* 3. Create a class RELATION, use Matrix notation to represent a relation. Include functions to check 
if a relation is reflexive, Symmetric, Anti-symmetric and Transitive. Write a Program to use this class.
    4. Use the functions defined in Ques 3 to find check whether the given relation is:
    a) Equivalent, or
    b) Partial Order relation, or
    c) None
*/

#include <iostream>
using namespace std;

class Relation    // creating a class relation
{
private:
    int **arr;   // declaring dynamic array
    int size;
    int *set;

public:
    Relation()   // default contructor
    {
        arr = NULL;
        size = 0;
    }
    void set_size()  //function to set size
    {
        cout << "Enter the size of the set." << endl;
        cin >> size;
        set = new int[size];
        cout << "Enter elements of the set." << endl;
        for (int i = 0; i < size; i++)
            cin >> set[i];
        arr = new int *[size]; // creating two dimensial array
        for (int i = 0; i < size; i++)
            arr[i] = new int[size];
        for (int i = 0; i < size; i++) //initalizing matrix with zero at all positions.
            for (int j = 0; j < size; j++)
                arr[i][j] = 0;   // initialize the matrix with zero
    }
    void input()    // function to enter relation between two elements
    {
        int a, b, i, num;
        cout << "Enter the number of elements in the relation." << endl;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter pair number " << (i + 1) << " respectively--->" << endl;
            cin >> a >> b;
            if (a || b <= set[i])
            {
                int p, q;

                for (int j = 0; j < size; j++)
                {
                    if (a == set[j])
                        p = j;
                    if (b == set[j])
                        q = j;
                }
                arr[p][q] = 1;
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        show_matrix();
    }
    void show_matrix()
    {
        cout << "The Relation matrix is:" << endl;
        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < size + 1; j++)
            {
                if (i == 0 && j == 0)
                    cout << "   ";
                else if (i == 0)
                    cout << set[j - 1] << "  ";
                else if (j == 0)
                    cout << set[i - 1] << "| ";
                else
                    cout << arr[i - 1][j - 1] << "  ";
            }
            cout << endl;
        }
    }
    bool Reflexive()  // function to check reflexivity of a relation
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i][i] != 1)
                return false;
        }
        return true;
    }
    bool Symmetric() // function to check symmetric of a relation
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i][j] == 1 && arr[j][i] != 1)
                    return false;
            }
        }
        return true;
    }
    bool Transitive() // function to check transitivity of relation
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i][j] == 1)
                {
                    for (int k = 0; k < size; k++)
                    {
                        if (arr[j][k] == 1 && arr[i][k] == 0)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    bool anti_symmetric() // function to check antisymmetricity of reltion
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if ((arr[i][j] == 1 && arr[j][i] == 1) && i != j)
                    return false;
            }
        }
        return true;
    }
    bool Equivalence()
    {
        return (this->Reflexive() && this->Symmetric() && this->Transitive());
    }
    bool partial_order()
    {
        return (this->Reflexive() && this->anti_symmetric() && this->Transitive());
    }
};
int main()
{
    Relation r;
    r.set_size();
    r.input();
    cout << endl;
    int ch;
    char c;
    do
    {
        cout << "Enter your choice to check whether relation is:\n"
             << endl;
        cout << "1: Reflexive Relation" << endl;
        cout << "2: Symmetric Relation" << endl;
        cout << "3: Transitive Relation" << endl;
        cout << "4: Anti-Symmetric Relation" << endl;
        cout << "5: Equivalence Relation" << endl;
        cout << "6: Partial Order Relation" << endl;
        cout << "------------------------------------------------" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            if (r.Reflexive())
                cout << "The entered relation is Reflexive.\n"
                     << endl;

            else
                cout << "The entered relation is not Reflexive.\n"
                     << endl;

            break;
        }
        case 2:
        {
            if (r.Symmetric())
                cout << "The entered relation is Symmetric.\n"
                     << endl;
            else
                cout << "The entered relation is not Symmetric.\n"
                     << endl;
            break;
        }
        case 3:
        {
            if (r.Transitive())
                cout << "The entered relation is Transitive.\n"
                     << endl;
            else
                cout << "The entered relation is not Transitive.\n"
                     << endl;
            break;
        }
        case 4:
        {
            if (r.anti_symmetric())
                cout << "The entered relation is Anti-Symmetric.\n"
                     << endl;
            else
                cout << "The entered relation is not Anti-Symmetric.\n"
                     << endl;
            break;
        }
        case 5:
        {
            if (r.Equivalence())
                cout << "The entered relation is Equivalence.\n"
                     << endl;
            else
                cout << "The entered relation is not Equivalence.\n"
                     << endl;
            break;
        }
        case 6:
        {
            if (r.partial_order())
                cout << "The entered relation is Partial Order.\n"
                     << endl;
            else
                cout << "The entered relation is not Partial Order.\n"
                     << endl;
            break;
        }
        default:
            cout << "Invalid choice, Please Try Again." << endl;
            break;
        }
        cout << "Do you want to continue? Enter y for yes." << endl;
        cin >> c;
        cout << "--------------------------------------------------" << endl;
    } while (c == 'y');
    return 0;
}
