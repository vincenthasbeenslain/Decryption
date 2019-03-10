
/*************************************************************************************************************
CIS 22C
Lab 4: This program provides the implementation of the class Encrypted for the main function, which receives
       the a file name of the file containing the encrypted message as input and outputs the decrypted message.
Author: Vincent Nguyen
Date: 3/1/19
*************************************************************************************************************/
#include "Encrypted.h"
#include <fstream>
#include <iostream>
#include <cstring>

/*************************************************************************************************************
The constructor receives the file name and maximum byte size and dynamically allocates space for the "code"
variable which will hold the message. Then it attempts to open the file and sets the variable "status" based
on the result. Then it lets "code" receive each character from the file.
*************************************************************************************************************/
Encrypted::Encrypted(string name, int size)
{
    code = new char [size + 1];

    ifstream inputFile;
    inputFile.open(name.c_str());
    if(!inputFile)
        status = true;
    else
        status = false;

    int n = 0;
    char temp;

    inputFile >> noskipws;
    while(inputFile >> temp)
    {
        code[n] = temp;
        n++;
    }
}

/*************************************************************************************************************
destructor of Encrypted
*************************************************************************************************************/
Encrypted::~Encrypted()
{
    delete []code;
}
/*************************************************************************************************************
the bool isEmpty returns the value of status.
*************************************************************************************************************/
bool Encrypted::isEmpty()
{
    return status;
}

/*************************************************************************************************************
the decode function creates the decryption key array where the decrypted alphabetic character is 26
spaces ahead of the encrypted character. It checks each character in code; if it is an alphabetic character it
is converted to an ASCII int, then converted to index (ASCII: 97-149 -> index: 0-52). If it isn't alphabetic,
it is not altered.
*************************************************************************************************************/
char Encrypted::decode()
{
    char key[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                  'i', 'z', 't', 'o', 'h', 'n', 'd', 'b', 'e', 'q', 'r', 'k', 'g',
                  'l', 'm', 'a', 'c', 's', 'v', 'w', 'f', 'u', 'y', 'p', 'j', 'x'};

    for (int i = 0; i <strlen(code); i++)
        if (isalpha(code[i]))
            code[i] = key[int(code[i]) - 97 + 26];
        else
            continue;
}

/*************************************************************************************************************
the print function displays the encrypted message.
*************************************************************************************************************/
char Encrypted::print()
{
    for (int i = 0; i < strlen(code); i++)
        cout << code[i];
}

/**
Sample output:
Enter file name: Encrypted.txt
encryption is the name given to the process of applying an algorithm to a message, which scrambles the data in it-making it very difficult and time consuming, if not practically impossible, to deduce the original given only the encoded data. inputs to the algorithm typically involve additional secret data called keys, which prevents the message from being decoded-even if the algorithm is publicly known.

Process returned 0 (0x0)   execution time : 2.587 s
Press any key to continue.
*/
