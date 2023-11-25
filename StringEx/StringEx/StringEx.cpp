#include <iostream>
#include <string>
#include <iterator>

using namespace std;
 
//string::iterator iter = m.begin();

void f1(string m) {  
    int x = 0;
    char lastsym = m.back();
    int itlastsym = m.find(lastsym);
    while ((m.find(lastsym) != m.size() - 1) && (m.size() != 1)) {
        itlastsym = m.find(lastsym);
        cout << itlastsym + x << " ";
        m.erase(itlastsym, 1);
        x++;
    }
    cout << endl;
}

void f2(string m) {
    for (int i = 2; i < m.size(); i += 3) {
        cout << m.at(i)<<" ";
    }
    cout << endl;
}

void f3(string m) {
    int PaM=0,PaMwZ=0;
    for (int i = 0; i < m.size(); i++) {
        if (m.at(i) == '+' || m.at(i) == '-') {
            PaM++;
            if (m[i + 1] == '0') {
                PaMwZ++;
            }
        }
    }
    cout << PaM<<", " <<PaMwZ<<"." << endl;
}

void f4(string m) {
    bool XvsW = true,x=false,w=false;
    for (int i = m.size()-1; i > -1 ; i--) {
        if (m[i] == 'x') {
            XvsW = true;
            x = true;
        }
        else if (m[i] == 'w') {
            XvsW = false;
            w = true;
        }
    }
    if (x || w) {
        if (XvsW) {
        cout << "First x." << endl;
        }
        else {
        cout << "First w." << endl;
        }
        if (!x) {
            cout << "Missing x." << endl;
        }
        else if(!w) {
            cout << "Missing w." << endl;
        }
    }
    else {
        cout << "Missing x and w." << endl;
    }
    
}

void f5(string m,string s) {
    if (m.size() > s.size()) {
        for (int i = 0; i < (m.size() - s.size()); i++) {
            cout << m << endl;
        }
    }
    else {
        for (int i = 0; i < (s.size() - m.size()); i++) {
            cout << s << endl;
        }
    }
}

void f6(string m) {
    if ((m[0]=='a')&&(m[1]=='b')&&(m[2]=='c')) {
        m.erase(0,3);
        m.insert(0, 3, 'w');
    }
    else {
        m.insert(m.end(), 3, 'z');
    }
    cout << m <<endl;
}

int main()
{
    string s1="agxcgefg";
    string s2 = "ef+nq-0-d+ew-0";
    f1(s1);
    f2(s1);
    f3(s2);
    f4(s1);
    f5(s1, s2);
    f6(s1);
}