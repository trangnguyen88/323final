#ifndef STD_TYPES_H

#define STD_TYPES_H
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;
const int TOTAL_RESERVED_WORD = 5;
const int TOTAL_SPECIAL = 8;
const string Reserved_Word[TOTAL_RESERVED_WORD] = { "PROGRAM","INTEGER", "END.", "INTEGER", "PRINT" };
const char Special[TOTAL_SPECIAL] = { '=', ';', '(', ')', ',', ':','*','+'};
#endif
