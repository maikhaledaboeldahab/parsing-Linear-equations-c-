#ifndef EQUATION_H
#define EQUATION_H

#include <string>
#include <vector>

using namespace std;

// Structure to hold a single term like "3x1"
struct Term {
    string var;
    float coeff;
};

// Structure to hold the full equation
struct Equation {
    vector<Term> terms;
    float rhs; // Right Hand Side constant
};

// Function prototypes (just the names and inputs, no bodies)
void addTermToEquation(Equation& eq, string varStr, float coeff);
void splitEqualSign(string eq, string& lhs, string& rhsStr);
void processTerm(string termStr, Equation& eq);
void parseLHS(string lhs, Equation& eq);
void printEquation(Equation eq);
void addEquations(Equation e1, Equation e2);
void subtractEquations(Equation e1, Equation e2);

#endif