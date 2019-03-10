/*************************************************************************************************************
CIS 22C
Lab 4: This program provides the implementation of the class Encrypted for the main function, which receives
       the a file name of the file containing the encrypted message as input and outputs the decrypted message.
Author: Vincent Nguyen
Date: 3/1/19
*************************************************************************************************************/
#ifndef Encrypted_h
#define Encrypted_h

#include <string>

using namespace std;

class Encrypted {
    private:
        char *code;
        bool status = true;
    public:
        ~Encrypted();
        Encrypted(string name, int size);
        bool isEmpty();
        char decode();
        char print ();
};

#endif
