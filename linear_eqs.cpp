#include <iostream>
#include <string>
#include <vector>
#include "equation.h"

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    vector<Equation> system(n);
    vector<string> globalVars;

    // Read and parse equations
    for (int i = 0; i < n; i++) {
        string line, lhsStr, rhsStr;
        getline(cin, line);

        system[i].rhs = 0;

        splitEqualSign(line, lhsStr, rhsStr);
        parseLHS(lhsStr, system[i]);
        system[i].rhs += stof(rhsStr);

        // Count unique variables
        for (int j = 0; j < system[i].terms.size(); j++) {
            string v = system[i].terms[j].var;
            bool found = false;
            for (int k = 0; k < globalVars.size(); k++) {
                if (globalVars[k] == v) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                globalVars.push_back(v);
            }
        }
    }

    string command;
    while (cin >> command && command != "quit") {
        if (command == "num_vars") {
            cout << globalVars.size() << endl;
        }
        else if (command == "equation") {
            int i;
            cin >> i;
            printEquation(system[i - 1]);
        }
        else if (command == "column") {
            string varName;
            cin >> varName;

            for (int i = 0; i < n; i++) {
                float coeffToPrint = 0;
                for (int j = 0; j < system[i].terms.size(); j++) {
                    if (system[i].terms[j].var == varName) {
                        coeffToPrint = system[i].terms[j].coeff;
                        break;
                    }
                }
                cout << coeffToPrint << endl;
            }
        }
        else if (command == "add") {
            int i, j;
            cin >> i >> j;
            addEquations(system[i - 1], system[j - 1]);
        }
        else if (command == "subtract") {
            int i, j;
            cin >> i >> j;
            subtractEquations(system[i - 1], system[j - 1]);
        }
    }
    return 0;
}