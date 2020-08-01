#include <bits/stdc++.h>

using namespace std;
int CN = 10, WN = 10, AN = 10;

void Welcome()
{
    cout << "------------------------------------------------" << endl;
    cout << "C - J U I C E" << endl;
    cout << "------------------------------------------------" << endl;
}

string MainMenu()
{
    cout << endl << "------------------------------------------------" << endl;
    cout << "Select one of the options:" << endl;
    cout << "c)Create me a character" << endl;
    cout << "q)Quit" << endl;
    cout << "------------------------------------------------" << endl;

    string a;
    cin >> a;
    return a;

}

void CreateCharacter()
{
    ifstream creatures("creatures.txt"), weapon("weapon.txt"), additude("additude.txt");

    srand( (unsigned)time(NULL) );
    int m = rand() % 4, c = rand() % CN + 1, w = rand() % WN + 1, a = rand() % AN + 1;

    string cr, we, ad;

    for(int i = 0; i < c; i++)
    {
        getline(creatures, cr);
    }
    for(int i = 0; i < w; i++)
    {
        getline(weapon, we);
    }
    for(int i = 0; i < a; i++)
    {
        getline(additude, ad);
    }

    cout << endl << "------------------------------------------------" << endl;

    if(m == 0)
        cout << "A " << ad << " " << cr << " who is wielding a " << we << endl;
    else if(m == 1)
        cout << "A " << we << " wielding " << cr << " who is " << ad << endl;
    else if(m == 2)
        cout << "A " << cr << " who is " << ad << " and has a " << we << endl;
    else
        cout << "A " << cr << " with a " << ad << " additude " << "with an " << we << endl;

    cout << "------------------------------------------------" << endl;

}

int main()
{
    string choice;

    Welcome();

    while(true)
    {
        choice = MainMenu();

        if(choice == "c")
            CreateCharacter();
        else
            break;
    }

    return 0;
}
