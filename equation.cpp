#include <iostream>
#include "equation.h"

using namespace std;

// Helper to add a term, merge duplicates, and keep the list sorted alphabetically
void addTermToEquation(Equation& eq, string varStr, float coeff) {
    bool found = false;

    // 1. Check if the variable already exists to merge it
    for (int i = 0; i < eq.terms.size(); i++) {
        if (eq.terms[i].var == varStr) {
            eq.terms[i].coeff += coeff;
            found = true;
            break;
        }
    }

    // Check if it is not found
    if (!found) {
        Term newTerm;
        newTerm.var = varStr;
        newTerm.coeff = coeff;
        eq.terms.push_back(newTerm);
    }

    // Sorting
    for (int i = 0; i < eq.terms.size(); i++) {
        for (int j = i + 1; j < eq.terms.size(); j++) {
            if (eq.terms[i].var > eq.terms[j].var) {
                Term temp = eq.terms[i];
                eq.terms[i] = eq.terms[j];
                eq.terms[j] = temp;
            }
        }
    }
}

// Splits the equation into left and right sides of the '='
void splitEqualSign(string eq, string& lhs, string& rhsStr) {
    int idx = eq.find("=");
    if (idx != -1) {
        lhs = eq.substr(0, idx);
        rhsStr = eq.substr(idx + 1);
    }
}

// Processes a single piece of string like "-2x1" into a number and variable
void processTerm(string termStr, Equation& eq) {
    if (termStr == "") return;

    string coeffStr = "";
    string varStr = "";
    int i = 0;

    // Get the sign
    if (termStr[i] == '+' || termStr[i] == '-') {
        coeffStr += termStr[i];
        i++;
    }

    // Get the number (including decimals)
    while (i < termStr.length() && (isdigit(termStr[i]) || termStr[i] == '.')) {
        coeffStr += termStr[i];
        i++;
    }

    // Get the variable part
    while (i < termStr.length()) {
        if (termStr[i] != ' ') {
            varStr += termStr[i];
        }
        i++;
    }

    // Convert the string number to a float using stof
    float coeff = 0;
    if (coeffStr == "" || coeffStr == "+") coeff = 1.0;
    else if (coeffStr == "-") coeff = -1.0;
    else coeff = stof(coeffStr);

    // If it is just a number (no variable), move it to the right side
    if (varStr == "") {
        eq.rhs -= coeff;
    }
    else {
        addTermToEquation(eq, varStr, coeff);
    }
}

// Walks through the left side string and breaks it into individual terms
void parseLHS(string lhs, Equation& eq) {
    string currentTerm = "";
    for (int i = 0; i < lhs.length(); i++) {
        char c = lhs[i];
        if (c == ' ') continue;

        // If we find a + or -, process the previous term
        if ((c == '+' || c == '-') && currentTerm != "" && currentTerm != "+" && currentTerm != "-") {
            processTerm(currentTerm, eq);
            currentTerm = "";
        }
        currentTerm += c;
    }
    // Process the final piece
    processTerm(currentTerm, eq);
}

// Prints the equation in the proper requested form
void printEquation(Equation eq) {
    bool first = true;
    for (int i = 0; i < eq.terms.size(); i++) {
        float coeff = eq.terms[i].coeff;
        string var = eq.terms[i].var;

        if (coeff == 0) continue;

        if (!first && coeff > 0) cout << "+";

        if (coeff == -1) cout << "-";
        else if (coeff != 1) cout << coeff;

        cout << var;
        first = false;
    }
    cout << "=" << eq.rhs << endl;
}

// Adds two equations together
void addEquations(Equation e1, Equation e2) {
    Equation result = e1;
    for (int i = 0; i < e2.terms.size(); i++) {
        addTermToEquation(result, e2.terms[i].var, e2.terms[i].coeff);
    }
    result.rhs += e2.rhs;
    printEquation(result);
}

// Subtracts the second equation from the first
void subtractEquations(Equation e1, Equation e2) {
    Equation result = e1;
    for (int i = 0; i < e2.terms.size(); i++) {
        addTermToEquation(result, e2.terms[i].var, -e2.terms[i].coeff);
    }
    result.rhs -= e2.rhs;
    printEquation(result);
}