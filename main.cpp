#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define MAXLINE 1000000
using namespace std;
int getsym(string Token, string program)
{
    int i = 0;
    while(i < program.length())
    {
        Token.clear();
        while (program[i] == ' ' || program[i] == '\t' || program[i] == '\n' || program[i] == '\r')
        {
            i++;
        }
        if (isalpha(program[i]))
        {
            while ((isalpha(program[i])||isdigit(program[i]))&&i<program.length())
            {
                Token += program[i];
                i++;
            }
            if(Token == "Begin")
            {
                printf("Begin\n");
            }
            else if(Token == "End")
            {
                printf("End\n");
            }
            else if(Token == "FOR")
            {
                printf("For\n");
            }
            else if(Token == "IF")
            {
                printf("If\n");
            }
            else if(Token == "THEN")
            {
                printf("Then\n");
            }
            else if(Token == "ELSE")
            {
                printf("Else\n");
            }
            else
            {
                printf("Ident(%s)\n",Token.c_str());
            }
        }
        else if(isdigit(program[i]))
        {
            while(isdigit(program[i])&&i<program.length())
            {
                Token += program[i];
                i++;
            }
            int num = atoi(Token.c_str());
            printf("Int(%d)\n",num);
        }
        else if(program[i] == ':')
        {
            i++;
            printf("Colon\n");
        }
        else if(program[i] == '+')
        {
            i++;
            printf("Plus\n");
        }
        else if(program[i] == '*')
        {
            i++;
            printf("Star\n");
        }
        else if(program[i] == ',')
        {
            i++;
            printf("Comma\n");
        }
        else if(program[i] == '(')
        {
            i++;
            printf("LParenthesis\n");
        }
        else if(program[i] == ')')
        {
            i++;
            printf("RParenthesis\n");
        }
        else
        {
            printf("Unknown\n");
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[])
{
    FILE *fp;
    int file_size;
    int num = 0;
    char c;
    string s;
    string Token;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("this file does not exist");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < file_size; i++)
    {
        c = fgetc(fp);
        s += c;
    }
    getsym(Token,s);
    fclose(fp);
}
