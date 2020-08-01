#include <bits/stdc++.h>

using namespace std;
int CN = -1, WN = -1, AN = -1; //CN - number of lines in creatures.txt, etc.
ifstream creatures("creatures.txt"), weapon("weapon.txt"), additude("additude.txt");

void Welcome()
{
    cout << "------------------------------------------------" << endl;
    cout << "C - J U I C E" << endl;
    cout << "------------------------------------------------" << endl;

    string as;

    while(getline(creatures, as))
    {
        CN += 1;
    }

    while( getline(weapon, as))
    {
        WN += 1;
    }

    while(getline(additude, as))
    {
        AN += 1;
    }
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
    srand( (unsigned)time(NULL) );
    int m = rand() % 4, c = rand() % CN + 1, w = rand() % WN + 1, a = rand() % AN + 1;

    string cr, we, ad;

    creatures.close(); creatures.open("creatures.txt");
    for(int i = 0; i < c; i++)
    {
        getline(creatures, cr);
    }

    weapon.close(); weapon.open("weapon.txt");
    for(int i = 0; i < w; i++)
    {
        getline(weapon, we);
    }
    additude.close(); additude.open("additude.txt");
    for(int i = 0; i < a; i++)
    {
        getline(additude, ad);
    }

    cout << endl << "------------------------------------------------" << endl;

    if(m == 0)
    {

        cout << "A " << ad << " " << cr << " who is wielding a " << we << endl;
    }
    else if(m == 1)
    {
        cout << "A " << we << " wielding " << cr << " who is " << ad << endl;
    }
    else if(m == 2)
    {
        cout << "A " << cr << " who is " << ad << " and has a " << we << endl;
    }
    else
    {
        cout << "A " << cr << " with a " << ad << " additude " << "with an " << we << endl;
    }

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
