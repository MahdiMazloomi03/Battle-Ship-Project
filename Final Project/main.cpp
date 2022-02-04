//  __/\\\\____________/\\\\______/\\\\\\\\\______/\\\________/\\\___/\\\\\\\\/\\____/\\\\\\\\\\_|
//   _\/\\\\\\________/\\\\\\____/\\\\\\\\\\\\\___\/\\\________/\\\__\/\\\____\/\\\__\////\\\///__|
//    _\/\\\//\\\____/\\\//\\\___/\\\/////////\\\__\/\\\________/\\\__\/\\\____\/\\\\____\/\\\_____|
//     _\/\\\\///\\\/\\\/_\/\\\__\/\\\_______\/\\\__\/\\\\\\\\\\\\\\\__\/\\\____\/\\\\____\/\\\_____|
//      _\/\\\__\///\\\/___\/\\\__\/\\\\\\\\\\\\\\\__\/\\\/////////\\\__\/\\\____\/\\\\____\/\\\_____|
//       _\/\\\____\///_____\/\\\__\/\\\/////////\\\__\/\\\_______\/\\\__\/\\\____\/\\\_____\/\\\_____|
//        _\/\\\_____________\/\\\__\/\\\_______\/\\\__\/\\\_______\/\\\__\/\\\___/\\\\______\/\\\_____|
//         _\/\\\_____________\/\\\__\/\\\_______\/\\\__\/\\\_______\/\\\__\/\\\\\\/\\_____/\\\\\\\\\\__|
//          _\///______________\///___\///________\///___\///________\///___\/////////_____\//////////___|
#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vpi;
typedef pair<int, int> pii;
#define hurry                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define setp setprecision
#define popp pop_back()
#define pb push_back
#define mp make_pair
#define beg begin()
#define en end()
#define sc second
#define sz size()
#define fr first
#define endl '\n'
const long long mod = 1e9 + 7;
const long long INF = 1e16 + 10;
const int N = 1e5 + 7;
//=======================================================================================================================
//STRUCTS
struct user
{
    str username;
    int coin;
    int id;
};
//=======================================================================================================================
//GLOBAL
int mapA[15][15];
int mapB[15][15];
char showMapA[15][15] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};
char showMapB[15][15] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};

int s1[2][4];
int s2[2][2][3];
int s3[2][3][2];
int s5[2][5];
//bot
int bot[15][15] = {
    {0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, 3, 3, 3, -1, 0, 0, 0},
    {0, -1, 2, 2, -1, -1, -1, -1, -1, -1, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, 2, 2, -1, 0, 0, 0, 0},
    {0, -1, 3, 3, 3, -1, -1, -1, -1, -1, -1, 0, 0},
    {0, -1, -1, -1, -1, -1, 1, -1, 2, 2, -1, 0, 0},
    {0, -1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, -1, 1, -1, 0, 0, 0},
    {0, -1, 5, 5, 5, 5, 5, -1, -1, -1, 0, 0, 0},
    {0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int sbot1[4] = {64, 62, 56, 78};
int sbot2[2][3] = {{36, 22, 58}, {37, 23, 59}};
int sbot3[3][2] = {{16, 42}, {17, 43}, {18, 44}};
int sbot5[5] = {82, 83, 84, 85, 86};
str userName1;
str userName2;
int shipscntA = 10;
int shipscntB = 10;
int userID1;
int userID2;
user users[100000];
int usercnt;
bool isbot;
bool end = 0;
//=======================================================================================================================
//FUNCTIONS
void getdata()
{
    ifstream indata;
    indata.open("users.txt");
    str a;
    int m;
    indata >> a >> m;
    for (int i = 1; i < 100000; i++)
    {
        if (a == users[i - 1].username)
            return;
        else
        {
            users[i].username = a;
            users[i].coin = m;
            users[i].id = i;
            indata >> a >> m;
            usercnt = i;
        }
    }
}
void save()
{
    ofstream writeInFile;
    writeInFile.open("maps.txt");
    ofstream savedata;
    savedata.open("users.txt");
    for (int i = 1; i <= usercnt; i++)
    {
        savedata << users[i].username << ' ' << users[i].coin << endl;
    }
    ////////////////////////
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            writeInFile << mapA[i][j] << ' ';
        }
        writeInFile << endl;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            writeInFile << mapB[i][j] << ' ';
        }
        writeInFile << endl;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (showMapA[i][j] == ' ')
                writeInFile << 'k' << ' ';
            else
                writeInFile << showMapA[i][j] << ' ';
        }
        writeInFile << endl;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (showMapB[i][j] == ' ')
                writeInFile << 'k' << ' ';
            else
                writeInFile << showMapB[i][j] << ' ';
        }
        writeInFile << endl;
    }
    writeInFile << userName1 << endl
                << userName2 << endl
                << shipscntA << endl
                << shipscntB << endl
                << userID1 << endl
                << userID2 << endl;
    for (int i = 0; i < 5; i++)
        writeInFile << s5[0][i] << ' ';
    writeInFile << endl;
    for (int th = 0; th < 2; th++)
    {
        for (int i = 0; i < 3; i++)

            writeInFile << s3[0][i][th] << ' ';
    }
    writeInFile << endl;
    for (int th = 0; th < 3; th++)
    {
        for (int i = 0; i < 2; i++)
            writeInFile << s2[0][i][th] << ' ';
    }
    writeInFile << endl;
    for (int th = 0; th < 4; th++)
        writeInFile << s1[0][th] << ' ';
    writeInFile << endl;
    //////////
    for (int i = 0; i < 5; i++)
        writeInFile << s5[1][i] << ' ';
    writeInFile << endl;
    for (int th = 0; th < 2; th++)
    {
        for (int i = 0; i < 3; i++)
            writeInFile << s3[1][i][th] << ' ';
    }
    writeInFile << endl;
    for (int th = 0; th < 3; th++)
    {
        for (int i = 0; i < 2; i++)

            writeInFile << s2[1][i][th] << ' ';
    }
    writeInFile << endl;
    for (int th = 0; th < 4; th++)
        writeInFile << s1[1][th] << ' ';
    writeInFile << endl;
    writeInFile.close();
}
bool isval(int x1, int y1, int x2, int y2, int l, bool n)
{
    if (x1 < 1 or x2 < 1 or y1 < 1 or y2 < 1 or x1 > 10 or x2 > 10 or y1 > 10 or y2 > 10)
        return 0;
    if (x1 != x2 and y1 != y2)
        return 0;
    if (x1 == x2 and abs(y1 - y2) != l - 1)
        return 0;
    if (y1 == y2 and abs(x1 - x2) != l - 1)
        return 0;
    for (int i = 0; i < l; i++)
    {
        if (!n)
        {
            if (x1 == x2)
            {
                int y = min(y1, y2);
                if (mapA[x1][y + i] != 0)
                    return 0;
            }
            else
            {
                int x = min(x1, x2);
                if (mapA[x + i][y1] != 0)
                    return 0;
            }
        }
        else
        {
            if (x1 == x2)
            {
                int y = min(y1, y2);
                if (mapB[x1][y + i] != 0)
                    return 0;
            }
            else
            {
                int x = min(x1, x2);
                if (mapB[x + i][y1] != 0)
                    return 0;
            }
        }
    }
    return 1;
}
void show(bool n)
{
    if (!n)
    {
        for (int i = 1; i <= 41; i++)
        {
            if (i % 4 == 1)
            {
                for (int j = 0; j < 41; j++)
                    cout << '=';
                cout << endl;
            }
            else if (i % 4 == 3)
            {
                for (int j = 1; j <= 10; j++)
                {
                    cout << "| " << showMapA[(i + 1) / 4][j] << " ";
                }
                cout << '|';
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 1; i <= 41; i++)
        {
            if (i % 4 == 1)
            {
                for (int j = 0; j < 41; j++)
                    cout << '=';
                cout << endl;
            }
            else if (i % 4 == 3)
            {
                for (int j = 1; j <= 10; j++)
                {
                    cout << "| " << showMapB[(i + 1) / 4][j] << " ";
                }
                cout << '|';
                cout << endl;
            }
        }
    }
}
void game(bool n)
{
    while (shipscntA > 0 and shipscntB > 0)
    {
        if (!n)
        {
            cout << "\tIt's " << userName1 << "'s turn" << endl;
            show(1);
            cout << "\tIf you want to save your game enter \"save\" else enter something else";
            str v;
            cin >> v;
            if (v == "save")
                save();
            bool flg = 0;
            int x1, y1;
            while (!flg)
            {
                cout << endl
                     << "\tEnter coordinates of your shoot in format x1 y1" << endl;
                cin >> x1 >> y1;
                if (x1 > 0 and x1 < 11 and y1 > 0 and y1 < 11 and showMapB[x1][y1] == ' ')
                    flg = 1;
            }
            if (mapB[x1][y1] == 0 or mapB[x1][y1] == -1)
            {
                showMapB[x1][y1] = 'W';
                show(1);
                game(1);
            }
            else
            {
                showMapB[x1][y1] = 'E';
                if (mapB[x1][y1] == 5)
                {
                    bool flg = 1;
                    for (int i = 0; i < 5; i++)
                    {
                        int x = s5[1][i] / 10;
                        int y = s5[1][i] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapB[x][y] == ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(0);
                    }
                    else
                    {
                        users[userID1].coin += 25;
                        int xi, yi, xf, yf;
                        xi = s5[1][0] / 10;
                        yi = s5[1][0] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s5[1][4] / 10;
                        yf = s5[1][4] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntB--;
                        for (int i = 0; i < 5; i++)
                        {
                            int x = s5[1][i] / 10;
                            int y = s5[1][i] % 10;
                            if (y == 0)
                                y = 10;
                            showMapB[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 6; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 6; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        game(0);
                    }
                }
                if (mapB[x1][y1] == 3)
                {
                    bool flg = 1;
                    int th;
                    for (int j = 0; j < 2; j++)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            int x = s3[1][i][j] / 10;
                            int y = s3[1][i][j] % 10;
                            if (y == 0)
                                y = 10;
                            if (x1 == x and y1 == y)
                                th = j;
                        }
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        int x = s3[1][i][th] / 10;
                        int y = s3[1][i][th] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapB[x][y] == ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(0);
                    }
                    else
                    {
                        users[userID1].coin += 12;
                        int xi, yi, xf, yf;
                        xi = s3[1][0][th] / 10;
                        yi = s3[1][0][th] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s3[1][2][th] / 10;
                        yf = s3[1][2][th] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntB--;
                        for (int i = 0; i < 3; i++)
                        {
                            int x = s3[1][i][th] / 10;
                            int y = s3[1][i][th] % 10;
                            if (y == 0)
                                y = 10;
                            showMapB[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 4; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 4; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        game(0);
                    }
                }
                if (mapB[x1][y1] == 2)
                {
                    bool flg = 1;
                    int th;
                    for (int j = 0; j < 3; j++)
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            int x = s2[1][i][j] / 10;
                            int y = s2[1][i][j] % 10;
                            if (y == 0)
                                y = 10;
                            if (x1 == x and y1 == y)
                                th = j;
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {
                        int x = s2[1][i][th] / 10;
                        int y = s2[1][i][th] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapB[x][y] == ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(0);
                    }
                    else
                    {
                        users[userID1].coin += 8;
                        int xi, yi, xf, yf;
                        xi = s2[1][0][th] / 10;
                        yi = s2[1][0][th] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s2[1][1][th] / 10;
                        yf = s2[1][1][th] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntB--;
                        for (int i = 0; i < 2; i++)
                        {
                            int x = s2[1][i][th] / 10;
                            int y = s2[1][i][th] % 10;
                            if (y == 0)
                                y = 10;
                            showMapB[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 3; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 3; j++)
                                {
                                    if (mapB[i][j] == -1)
                                        showMapB[i][j] = 'W';
                                }
                            }
                        }
                        game(0);
                    }
                }
                if (mapB[x1][y1] == 1)
                {
                    users[userID1].coin += 5;
                    int th;
                    for (int j = 0; j < 4; j++)
                    {

                        int x = s1[1][j] / 10;
                        int y = s1[1][j] % 10;
                        if (y == 0)
                            y = 10;
                        if (x1 == x and y1 == y)
                            th = j;
                    }
                    int x, y;
                    x = s1[1][th] / 10;
                    y = s1[1][th] % 10;
                    if (y == 0)
                        y = 10;
                    shipscntB--;
                    showMapB[x][y] = 'C';
                    for (int i = x - 1; i < x + 2; i++)
                    {
                        for (int j = y - 1; j < y + 2; j++)
                        {
                            if (mapB[i][j] == -1)
                                showMapB[i][j] = 'W';
                        }
                    }
                    game(0);
                }
            }
        }
        else
        {
            cout << "\tIt's " << userName2 << "'s turn" << endl;
            show(0);
            if (!isbot)
            {
                cout << "\tIf you want to save your game enter \"save\" ";
                str v;
                cin >> v;
                if (v == "save")
                    save();
            }
            bool flg = 0;
            int x1, y1;
            while (!flg)
            {
                cout << endl
                     << "\tEnter coordinates of your shoot in format x1 y1" << endl;
                if (isbot)
                {
                    x1 = rand() % 10 + 1;
                    y1 = rand() % 10 + 1;
                    cout << x1 << ' ' << y1 << endl;
                }
                else
                    cin >> x1 >> y1;
                if (x1 > 0 and x1 < 11 and y1 > 0 and y1 < 11 and showMapA[x1][y1] == ' ')
                    flg = 1;
            }
            if (mapA[x1][y1] == 0 or mapA[x1][y1] == -1)
            {
                showMapA[x1][y1] = 'W';
                show(0);
                game(0);
            }
            else
            {
                showMapA[x1][y1] = 'E';
                if (mapA[x1][y1] == 5)
                {
                    bool flg = 1;
                    for (int i = 0; i < 5; i++)
                    {
                        int x = s5[0][i] / 10;
                        int y = s5[0][i] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapA[x][y] = ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(1);
                    }
                    else
                    {
                        users[userID2].coin += 25;
                        int xi, yi, xf, yf;
                        xi = s5[0][0] / 10;
                        yi = s5[0][0] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s5[0][4] / 10;
                        yf = s5[0][4] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntA--;
                        for (int i = 0; i < 5; i++)
                        {
                            int x = s5[0][i] / 10;
                            int y = s5[0][i] % 10;
                            if (y == 0)
                                y = 10;
                            showMapA[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 6; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 6; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        game(1);
                    }
                }
                if (mapA[x1][y1] == 3)
                {
                    bool flg = 1;
                    int th;
                    for (int j = 0; j < 2; j++)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            int x = s3[0][i][j] / 10;
                            int y = s3[0][i][j] % 10;
                            if (y == 0)
                                y = 10;
                            if (x1 == x and y1 == y)
                                th = j;
                        }
                    }
                    for (int i = 0; i < 3; i++)
                    {
                        int x = s3[0][i][th] / 10;
                        int y = s3[0][i][th] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapA[x][y] == ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(1);
                    }
                    else
                    {
                        users[userID2].coin += 12;
                        int xi, yi, xf, yf;
                        xi = s3[0][0][th] / 10;
                        yi = s3[0][0][th] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s3[0][2][th] / 10;
                        yf = s3[0][2][th] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntA--;
                        for (int i = 0; i < 3; i++)
                        {
                            int x = s3[0][i][th] / 10;
                            int y = s3[0][i][th] % 10;
                            if (y == 0)
                                y = 10;
                            showMapA[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 4; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 4; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        game(1);
                    }
                }
                if (mapA[x1][y1] == 2)
                {
                    bool flg = 1;
                    int th;
                    for (int j = 0; j < 3; j++)
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            int x = s2[0][i][j] / 10;
                            int y = s2[0][i][j] % 10;
                            if (y == 0)
                                y = 10;
                            if (x1 == x and y1 == y)
                                th = j;
                        }
                    }
                    for (int i = 0; i < 2; i++)
                    {
                        int x = s2[0][i][th] / 10;
                        int y = s2[0][i][th] % 10;
                        if (y == 0)
                            y = 10;
                        if (showMapA[x][y] == ' ')
                            flg = 0;
                    }
                    if (!flg)
                    {
                        game(1);
                    }
                    else
                    {
                        users[userID2].coin += 8;
                        int xi, yi, xf, yf;
                        xi = s2[0][0][th] / 10;
                        yi = s2[0][0][th] % 10;
                        if (yi == 0)
                            yi = 10;
                        xf = s2[0][1][th] / 10;
                        yf = s2[0][1][th] % 10;
                        if (yf == 0)
                            yf = 10;
                        shipscntA--;
                        for (int i = 0; i < 2; i++)
                        {
                            int x = s2[0][i][th] / 10;
                            int y = s2[0][i][th] % 10;
                            if (y == 0)
                                y = 10;
                            showMapA[x][y] = 'C';
                        }
                        if (yi == yf)
                        {
                            int x = min(xi, xf);
                            for (int i = x - 1; i < x + 3; i++)
                            {
                                for (int j = yi - 1; j < yi + 2; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        else
                        {
                            int y = min(yi, yf);
                            for (int i = xi - 1; i < xi + 2; i++)
                            {
                                for (int j = y - 1; j < y + 3; j++)
                                {
                                    if (mapA[i][j] == -1)
                                        showMapA[i][j] = 'W';
                                }
                            }
                        }
                        game(1);
                    }
                }
                if (mapA[x1][y1] == 1)
                {
                    users[userID2].coin += 5;
                    int th;
                    for (int j = 0; j < 4; j++)
                    {

                        int x = s1[0][j] / 10;
                        int y = s1[0][j] % 10;
                        if (y == 0)
                            y = 10;
                        if (x1 == x and y1 == y)
                            th = j;
                    }
                    int x, y;
                    x = s1[0][th] / 10;
                    y = s1[0][th] % 10;
                    if (y == 0)
                        y = 10;
                    shipscntA--;
                    showMapA[x][y] = 'C';
                    for (int i = x - 1; i < x + 2; i++)
                    {
                        for (int j = y - 1; j < y + 2; j++)
                        {
                            if (mapA[i][j] == -1)
                                showMapA[i][j] = 'W';
                        }
                    }
                    game(1);
                }
            }
        }
    }
    if (shipscntA == 0 and end == 0)
    {
        cout << "****CONGRATULATION " << userName2 << " YOU ARE THE WINNER****" << endl;
        end = 1;
        exit;
    }
    if (shipscntB == 0 and end == 0)
    {

        cout << "****CONGRATULATION " << userName1 << " YOU ARE THE WINNER****" << endl;
        end = 1;
        exit;
    }
}
void playUser()
{
    cout << endl
         << "Play with a friend" << endl
         << endl;
    //first player
    cout << "First player:" << endl;
    cout << "\tChoose user" << endl;
    cout << "\t1-Choose from available users" << endl;
    cout << "\t2-New user" << endl;
    str n;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tChoose user" << endl;
        cout << "\t1-Choose from available users" << endl;
        cout << "\t2-New user" << endl;
        cin >> n;
    }
    str e;
    if (n[0] == '1')
    {
        bool flg = 0;
        while (!flg)
        {
            cout << "\tEnter your username" << endl;
            cin >> e;
            for (int i = 1; i <= usercnt; i++)
            {
                if (e == users[i].username)
                {
                    userID1 = i;
                    flg = 1;
                    break;
                }
            }
            if (!flg)
                cout << "\tYour username is not on the list" << endl;
        }
    }
    if (n[0] == '2')
    {
        ofstream writeInFile;
        writeInFile.open("users.txt");
        cout << "\tEnter your username" << endl;
        cin >> e;
        bool flg = 0;
        int i = 1;
        while (i <= usercnt)
        {
            if (users[i].username == e)
            {

                i = 0;
                flg = 1;
                e += '-';
            }
            i++;
        }
        if (flg)
        {
            cout << "\tThis username has been taken your username is :" << endl;
            cout << e << endl;
        }
        int coin = 0;
        usercnt++;
        users[usercnt].username = e;
        users[usercnt].coin = coin;
        users[usercnt].id = usercnt;
        userID1 = usercnt;
        for (int i = 1; i <= usercnt; i++)
        {
            writeInFile << users[i].username << ' ' << users[i].coin << endl;
        }
        writeInFile.close();
    }
    userName1 = e;
    cout << "\tPut ships" << endl;
    cout << "\t1-Auto" << endl;
    cout << "\t2-Manual" << endl;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tPut ships" << endl;
        cout << "\t1-Auto" << endl;
        cout << "\t2-Manual" << endl;
        cin >> n;
    }
    if (n[0] == '1')
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                mapA[i][j] = bot[i][j];
            }
        }
        for (int i = 0; i < 5; i++)
            s5[0][i] = sbot5[i];
        for (int th = 0; th < 2; th++)
        {
            for (int i = 0; i < 3; i++)
                s3[0][i][th] = sbot3[i][th];
        }
        for (int th = 0; th < 3; th++)
        {
            for (int i = 0; i < 2; i++)
                s2[0][i][th] = sbot2[i][th];
        }
        for (int th = 0; th < 4; th++)
        {
            s1[0][th] = sbot1[th];
        }
    }
    if (n[0] == '2')
    {
        for (int th = 0; th < 1; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 5, 0))
            {
                cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 5; i++)
                {
                    if (y1 == 10)
                        s5[0][i] = (x + i) * 10;
                    else
                        s5[0][i] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 5;
                }
                for (int i = x - 1; i < x + 6; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 5; i++)
                {
                    if (y + i == 10)
                        s5[0][i] = (x1 * 10);
                    else

                        s5[0][i] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 5;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 6; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 2; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 3, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 3; i++)
                {
                    if (y1 == 10)
                        s3[0][i][th] = (x + i) * 10;
                    else

                        s3[0][i][th] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 3;
                }
                for (int i = x - 1; i < x + 4; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 3; i++)
                {
                    if (y + i == 10)
                        s3[0][i][th] = (x1 * 10);
                    else

                        s3[0][i][th] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 3;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 4; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 3; th++)
        {
            int flg = 0;
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 2, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 2; i++)
                {
                    if (y1 == 10)
                        s2[0][i][th] = (x + i) * 10;
                    else
                        s2[0][i][th] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 2;
                }
                for (int i = x - 1; i < x + 3; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 2; i++)
                {
                    if (y + i == 10)
                        s2[0][i][th] = (x1 * 10);
                    else
                        s2[0][i][th] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 2;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 3; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 4; th++)
        {
            int flg = 0;
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 1, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == 10)
                s1[0][th] = (x1 * 10);
            else
                s1[0][th] = (x1 * 10) + y1;
            mapA[x1][y1] = 1;
            for (int i = x1 - 1; i < x1 + 2; i++)
            {
                for (int j = y1 - 1; j < y1 + 2; j++)
                {
                    if (mapA[i][j] == 0)
                        mapA[i][j] = -1;
                }
            }
        }
    }
    cout << endl;
    //second player
    cout << "Second player:" << endl;
    cout << "\tChoose user" << endl;
    cout << "\t1-Choose from available users" << endl;
    cout << "\t2-New user" << endl;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tChoose user" << endl;
        cout << "\t1-Choose from available users" << endl;
        cout << "\t2-New user" << endl;
        cin >> n;
    }
    if (n[0] == '1')
    {
        bool flg = 0;
        while (!flg)
        {
            cout << "\tEnter your username" << endl;
            cin >> e;
            for (int i = 0; i <= usercnt; i++)
            {
                if (e == users[i].username)
                {
                    userID2 = i;
                    flg = 1;
                    break;
                }
            }
            if (!flg)
                cout << "\tYour username is not on the list" << endl;
        }
    }
    if (n[0] == '2')
    {
        ofstream writeInFile;
        writeInFile.open("users.txt");
        cout << "\tEnter your username" << endl;
        cin >> e;
        bool flg = 0;
        int i = 0;
        while (i <= usercnt)
        {
            if (users[i].username == e)
            {
                i = 0;
                flg = 1;
                e += '-';
            }
            i++;
        }
        if (flg)
        {
            cout << "\tThis username has been taken your username is :" << endl;
            cout << e << endl;
        }
        int coin = 0;
        usercnt++;
        users[usercnt].username = e;
        users[usercnt].coin = coin;
        users[usercnt].id = usercnt;
        userID2 = usercnt;
        for (int i = 1; i <= usercnt; i++)
        {
            writeInFile << users[i].username << ' ' << users[i].coin << endl;
        }
        writeInFile.close();
    }
    userName2 = e;
    cout << "\tPut ships" << endl;
    cout << "\t1-Auto" << endl;
    cout << "\t2-Manual" << endl;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tPut ships" << endl;
        cout << "\t1-Auto" << endl;
        cout << "\t2-Manual" << endl;
        cin >> n;
    }
    if (n[0] == '1')
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                mapB[i][j] = bot[i][j];
            }
        }
        for (int i = 0; i < 5; i++)
            s5[1][i] = sbot5[i];
        for (int th = 0; th < 2; th++)
        {
            for (int i = 0; i < 3; i++)
                s3[1][i][th] = sbot3[i][th];
        }
        for (int th = 0; th < 3; th++)
        {
            for (int i = 0; i < 2; i++)
                s2[1][i][th] = sbot2[i][th];
        }
        for (int th = 0; th < 4; th++)
        {
            s1[1][th] = sbot1[th];
        }
    }
    if (n[0] == '2')
    {
        for (int th = 0; th < 1; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 5, 1))
            {
                cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 5; i++)
                {
                    if (y1 == 10)
                        s5[1][i] = (x + i) * 10;
                    else
                        s5[1][i] = (x + i) * 10 + y1;
                    mapB[x + i][y1] = 5;
                }
                for (int i = x - 1; i < x + 6; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 5; i++)
                {
                    if (y + i == 10)
                        s5[1][i] = (x1 * 10);
                    else
                        s5[1][i] = (x1 * 10) + y + i;
                    mapB[x1][y + i] = 5;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 6; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 2; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 3, 1))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 3; i++)
                {
                    if (y1 == 10)
                        s3[1][i][th] = (x + i) * 10;
                    else
                        s3[1][i][th] = (x + i) * 10 + y1;
                    mapB[x + i][y1] = 3;
                }
                for (int i = x - 1; i < x + 4; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 3; i++)
                {
                    if (y + i == 10)
                        s3[1][i][th] = (x1 * 10);
                    else
                        s3[1][i][th] = (x1 * 10) + y + i;
                    mapB[x1][y + i] = 3;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 4; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 3; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 2, 1))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 2; i++)
                {
                    if (y1 == 10)
                        s2[1][i][th] = (x + i) * 10;
                    else
                        s2[1][i][th] = (x + i) * 10 + y1;
                    mapB[x + i][y1] = 2;
                }
                for (int i = x - 1; i < x + 3; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 2; i++)
                {
                    if (y + i == 10)
                        s2[1][i][th] = (x1 * 10);
                    else
                        s2[1][i][th] = (x1 * 10) + y + i;
                    mapB[x1][y + i] = 2;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 3; j++)
                    {
                        if (mapB[i][j] == 0)
                            mapB[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 4; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 1, 1))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == 10)
                s1[1][th] = (x1 * 10);
            else
                s1[1][th] = (x1 * 10) + y1;
            mapB[x1][y1] = 1;
            for (int i = x1 - 1; i < x1 + 2; i++)
            {
                for (int j = y1 - 1; j < y1 + 2; j++)
                {
                    if (mapB[i][j] == 0)
                        mapB[i][j] = -1;
                }
            }
        }
    }
    cout << endl;
    cout << "******GAME STARTS NOW******" << endl
         << endl;
    game(0);
}
void playBot()
{
    ofstream writeInFile;
    writeInFile.open("users.txt", ofstream::app);
    isbot = 1;
    cout << "\tChoose user" << endl;
    cout << "\t1-Choose from available users" << endl;
    cout << "\t2-New user" << endl;
    str n;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tChoose user" << endl;
        cout << "\t1-Choose from available users" << endl;
        cout << "\t2-New user" << endl;
        cin >> n;
    }
    str e;
    if (n[0] == '1')
    {
        bool flg = 0;
        while (!flg)
        {
            cout << "\tEnter your username" << endl;
            cin >> e;
            for (int i = 0; i <= usercnt; i++)
            {
                if (e == users[i].username)
                {
                    userID1 = i;
                    flg = 1;
                    break;
                }
            }
            if (!flg)
                cout << "\tYour username is not on the list" << endl;
        }
    }
    if (n[0] == '2')
    {
        cout << "\tEnter your username" << endl;
        cin >> e;
        bool flg = 0;
        int i = 0;
        while (i <= usercnt)
        {
            if (users[i].username == e)
            {

                i = 0;
                flg = 1;
                e += '-';
            }
            i++;
        }
        if (flg)
        {
            cout << "\tThis username has been taken your username is :" << endl;
            cout << e << endl;
        }
        int coin = 0;
        usercnt++;
        users[usercnt].username = e;
        users[usercnt].coin = coin;
        users[usercnt].id = usercnt;
        userID1 = usercnt;
        for (int i = 1; i <= usercnt; i++)
        {
            writeInFile << users[i].username << ' ' << users[i].coin << endl;
        }
        writeInFile.close();
    }
    userName1 = e;
    cout << "\tPut ships" << endl;
    cout << "\t1-Auto" << endl;
    cout << "\t2-Manual" << endl;
    cin >> n;
    while (n.sz > 1 or n[0] > '2' or n[0] < '1')
    {
        cout << endl;
        cout << "\tPut ships" << endl;
        cout << "\t1-Auto" << endl;
        cout << "\t2-Manual" << endl;
        cin >> n;
    }
    if (n[0] == '1')
    {
        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                mapA[i][j] = bot[i][j];
            }
        }
        for (int i = 0; i < 5; i++)
            s5[0][i] = sbot5[i];
        for (int th = 0; th < 2; th++)
        {
            for (int i = 0; i < 3; i++)
                s3[0][i][th] = sbot3[i][th];
        }
        for (int th = 0; th < 3; th++)
        {
            for (int i = 0; i < 2; i++)
                s2[0][i][th] = sbot2[i][th];
        }
        for (int th = 0; th < 4; th++)
        {
            s1[0][th] = sbot1[th];
        }
    }
    if (n[0] == '2')
    {
        for (int th = 0; th < 1; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 5, 0))
            {
                cout << "\tEnter coordinates of ship with length 5 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 5; i++)
                {
                    if (y1 == 10)
                        s5[0][i] = (x + i) * 10;
                    else
                        s5[0][i] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 5;
                }
                for (int i = x - 1; i < x + 6; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 5; i++)
                {
                    if (y + i == 10)
                        s5[0][i] = (x1 * 10);
                    else
                        s5[0][i] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 5;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 6; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 2; th++)
        {
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 3, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 3 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 3; i++)
                {
                    if (y1 == 10)
                        s3[0][i][th] = (x + i) * 10;
                    else
                        s3[0][i][th] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 3;
                }
                for (int i = x - 1; i < x + 4; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 3; i++)
                {
                    if (y + i == 10)
                        s3[0][i][th] = (x1 * 10);
                    else
                        s3[0][i][th] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 3;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 4; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 3; th++)
        {
            int flg = 0;
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 2, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 2 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == y2)
            {
                int x = min(x1, x2);
                for (int i = 0; i < 2; i++)
                {
                    if (y1 == 10)
                        s2[0][i][th] = (x + i) * 10;
                    else
                        s2[0][i][th] = (x + i) * 10 + y1;
                    mapA[x + i][y1] = 2;
                }
                for (int i = x - 1; i < x + 3; i++)
                {
                    for (int j = y1 - 1; j < y1 + 2; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
            else
            {
                int y = min(y1, y2);
                for (int i = 0; i < 2; i++)
                {
                    if (y + i == 10)
                        s2[0][i][th] = (x1 * 10);
                    else
                        s2[0][i][th] = (x1 * 10) + y + i;
                    mapA[x1][y + i] = 2;
                }
                for (int i = x1 - 1; i < x1 + 2; i++)
                {
                    for (int j = y - 1; j < y + 3; j++)
                    {
                        if (mapA[i][j] == 0)
                            mapA[i][j] = -1;
                    }
                }
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////
        for (int th = 0; th < 4; th++)
        {
            int flg = 0;
            int x1, x2, y1, y2;
            cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            while (!isval(x1, y1, x2, y2, 1, 0))
            {
                cout << "\tEnter coordinates of ship number " << th + 1 << " with length 1 (first and last) in format x1 y1 x2 y2 : " << endl;
                cin >> x1 >> y1 >> x2 >> y2;
            }
            if (y1 == 10)
                s1[0][th] = (x1 * 10);
            else
                s1[0][th] = (x1 * 10) + y1;
            mapA[x1][y1] = 1;
            for (int i = x1 - 1; i < x1 + 2; i++)
            {
                for (int j = y1 - 1; j < y1 + 2; j++)
                {
                    if (mapA[i][j] == 0)
                        mapA[i][j] = -1;
                }
            }
        }
    }
    cout << endl;
    userName2 = "BOT";
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            mapB[i][j] = bot[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
        s5[1][i] = sbot5[i];
    for (int th = 0; th < 2; th++)
    {
        for (int i = 0; i < 3; i++)
            s3[1][i][th] = sbot3[i][th];
    }
    for (int th = 0; th < 3; th++)
    {
        for (int i = 0; i < 2; i++)
            s2[1][i][th] = sbot2[i][th];
    }
    for (int th = 0; th < 4; th++)
    {
        s1[1][th] = sbot1[th];
    }
    cout << endl;
    cout << "******GAME STARTS NOW******" << endl
         << endl;
    game(0);
}
void load()
{
    ifstream indata;
    indata.open("maps.txt");
    int tempA[15][15];
    int tempB[15][15];
    char showtempA[15][15];
    char showtempB[15][15];
    int stemp1[2][4];
    int stemp2[2][2][3];
    int stemp3[2][3][2];
    int stemp5[2][5];
    str userNametemp1;
    str userNametemp2;
    int shipscnttempA;
    int shipscnttempB;
    int userIDtemp1;
    int userIDtemp2;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            indata >> tempA[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            indata >> tempB[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            indata >> showtempA[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            indata >> showtempB[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            mapA[i][j] = tempA[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            mapB[i][j] = tempB[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (showtempA[i][j] == 'k')
                showtempA[i][j] = ' ';
            else
                showMapA[i][j] = showtempA[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (showtempB[i][j] == 'k')
                showMapB[i][j] = ' ';
            else
                showMapB[i][j] = showtempB[i][j];
        }
    }
    ////////////////////////////////////////////
    indata >> userNametemp1 >> userNametemp2 >> shipscnttempA >> shipscnttempB >> userIDtemp1 >> userIDtemp2;
    userName1 = userNametemp1;
    userName2 = userNametemp2;
    shipscntA = shipscnttempA;
    shipscntB = shipscnttempB;
    userID1 = userIDtemp1;
    userID2 = userIDtemp2;
    for (int i = 0; i < 5; i++)
        indata >> stemp5[0][i];
    for (int th = 0; th < 2; th++)
    {
        for (int i = 0; i < 3; i++)

            indata >> stemp3[0][i][th];
    }
    for (int th = 0; th < 3; th++)
    {
        for (int i = 0; i < 2; i++)
            indata >> stemp2[0][i][th];
    }
    for (int th = 0; th < 4; th++)
        indata >> stemp1[0][th];
    //////////////////////////////////////////////////////
    for (int i = 0; i < 5; i++)
        indata >> stemp5[1][i];
    for (int th = 0; th < 2; th++)
    {
        for (int i = 0; i < 3; i++)
            indata >> stemp3[1][i][th];
    }
    for (int th = 0; th < 3; th++)
    {
        for (int i = 0; i < 2; i++)

            indata >> stemp2[1][i][th];
    }
    for (int th = 0; th < 4; th++)
        indata >> stemp1[1][th];
    //////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
            s5[i][j] = stemp5[i][j];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
                s3[i][j][k] = stemp3[i][j][k];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
                s2[i][j][k] = stemp2[i][j][k];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
            s1[i][j] = stemp1[i][j];
    }
    cout << "******GAME STARTS NOW******" << endl
         << endl;
    game(0);
}
void scoreboard()
{
    user sortedusers[100000];
    for (int i = 1; i <= usercnt; i++)
    {
        sortedusers[i].username = users[i].username;
        sortedusers[i].coin = users[i].coin;
        sortedusers[i].id = users[i].id;
    }
    for (int i = 1; i < usercnt; i++)
    {
        for (int j = usercnt; j > i; j--)
        {
            if (sortedusers[j].coin > sortedusers[j - 1].coin)
                swap(sortedusers[j], sortedusers[j - 1]);
        }
    }
    cout << "*****SCORE BOARD*****" << endl;
    for (int i = 1; i <= usercnt; i++)
    {
        cout << i << "- " << sortedusers[i].username << "   " << sortedusers[i].coin << "coin" << endl;
    }
}
void showMenu()
{
    cout << "******MENU*******" << endl;
    cout << "1-Play with a friend" << endl;
    cout << "2-Play with bot" << endl;
    cout << "3-Load last game" << endl;
    cout << "4-Score board" << endl;
    cout << "5-Exit" << endl;
    cout << "*****************" << endl;
    str n;
    cin >> n;
    while (n.sz > 1 or n[0] > '5' or n[0] < '1')
    {
        cout << endl
             << "Please choose one of the items in menu" << endl
             << endl;
        cout << "******MENU*******" << endl;
        cout << "1-Play with a friend" << endl;
        cout << "2-Play with bot" << endl;
        cout << "3-Load last game" << endl;
        cout << "4-Score board" << endl;
        cout << "5-Exit" << endl;
        cout << "*****************" << endl;
        cin >> n;
    }
    if (n[0] == '1')
    {
        playUser();
    }
    if (n[0] == '2')
    {
        playBot();
    }
    if (n[0] == '3')
    {
        load();
    }
    if (n[0] == '4')
    {
        scoreboard();
    }
    if (n[0] == '5')
    {
        exit;
    }
}
//=======================================================================================================================
int main()
{
    getdata();
    showMenu();
}
//=======================================================================================================================
