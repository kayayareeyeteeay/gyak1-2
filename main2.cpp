#include "graphics.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace genv;
using namespace std;

struct Csirke {


    Csirke(string fajlnev) {
        ifstream befajl(fajlnev);
        int szel, mag;

        befajl >> szel >> mag;


        v = vector<vector<vector<int>>>(mag, vector<vector<int>>(szel, vector<int>(3)));

        for (int j = 0; j < mag; j++) {
            for (int i = 0; i < szel; i++) {
                befajl >> v[j][i][0] >> v[j][i][1] >> v[j][i][2];
            }
        }

        befajl.close();
    }

    void rajzol() {
        for (int j = 0; j < v.size(); j++) {
            for (int i = 0; i < v[j].size(); i++) {
                gout << color(v[j][i][0], v[j][i][1], v[j][i][2])
                     << move_to(i, j)
                     << dot;
            }
        }
    }

    int szelesseg() {
        return v[0].size();
    }

    int magassag() {
        return v.size();
    }

private:
    vector<vector<vector<int>>> v;
};

int main() {
    Csirke csirke("a.kep");

    gout.open(csirke.szelesseg(), csirke.magassag());
    csirke.rajzol();
    gout << refresh;

    event ev;
    while (gin >> ev) {
    }

    return 0;
}
