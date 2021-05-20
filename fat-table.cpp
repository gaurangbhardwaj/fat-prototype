#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
};

class FatTable
{
private:
    vector<Node *> table;

public:
    void insert()
    {
        int data;
        cout << "Enter data to insert : ";
        cin >> data;
        Node *newNode = new Node();
        newNode->data = data;
        table.push_back(newNode);
    }

    void get()
    {
        int index;
        cout << "Enter index to get data : ";
        cin >> index;
        if (index < 0 || index > (table.size() - 1))
            return;
        cout << "--------------------------" << endl;
        cout << "Index: " << index << endl;
        cout << "Address: " << table[index] << endl;
        cout << "data: " << table[index]->data << endl;
        cout << "--------------------------" << endl;
    }

    void displayFatTable()
    {
        int idx = 0;
        cout << "--------------------------" << endl;
        cout << "  Index"
             << "  |  "
             << "Address" << endl;
        cout << "--------------------------" << endl;
        for (vector<Node *>::iterator itr = table.begin(); itr != table.end(); ++itr)
        {
            cout << "  " << idx << "      |  " << *itr << endl;
            idx++;
        }
    }
};

int menu()
{
    int opt = 0;
    cout << "--------------------------" << endl;
    cout << "1. Insert new data" << endl;
    cout << "2. Display FAT table" << endl;
    cout << "3. Get data" << endl;
    cout << "4. Exit" << endl;
    cout << "--------------------------" << endl;
    cout << "Option : ";
    cin >> opt;
    return opt;
}

int main()
{
    FatTable fatTable;
    while (true)
    {
        int opt = 0;
        opt = menu();
        system("clear");
        switch (opt)
        {
        case 1:
            fatTable.insert();
            break;
        case 2:
            fatTable.displayFatTable();
            system("read");
            break;
        case 3:
            fatTable.get();
            system("read");
            break;
        case 4:
            exit(0);
        }
        system("clear");
    }
}