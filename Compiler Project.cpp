#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

bool is_A_Keyword(char buffer[])
{
    char keywords[41][15] =
    {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while","include","iostream","using", "namespace","std","cout","endl","cin","new"
    };
    bool f=false;

    for(int i = 0; i < 41; i++)
    {
        if(!strcmp(keywords[i], buffer))
        {
            f = true;
            break;
        }
    }

    return f;
}

int c_Dot;
bool isNumber(string checkint)
{
    c_Dot=0 ;
    bool flag=true;
    for (int i = 0; i < checkint.length(); i++)
    {
        if(checkint[i]=='.') ++c_Dot;
        else if (!isdigit(checkint[i])|| c_Dot>1) // check if not a digit or there are more one Dot
        {
            flag=false;
            break;
        }

    }
    return flag;
}

void Check_Fun(char buffer[])
{
    if(is_A_Keyword(buffer))  cout << buffer << "  is a Keyword \n";
    else
    {
        if(isNumber(buffer))
        {
            if(c_Dot)
                cout<< buffer << "  is a decimal Number \n";

            else
                cout<< buffer << "  is an integer Number \n";
        }
        else
        {
            if (c_Dot>1)
                cout<< buffer << "  is an invalid decimal Number \n";
            else
                cout << buffer << "  is an Identifier \n";
        }
    }

}
int main()
{
    char buffer[15], logical_op[] = "><",math_op[]="+-*/=",special_char[]=",;\\(){}[]'':";


    ifstream file("SourceProgram.txt");
    int k=0;

    if(!file.is_open())
    {
        cout<<"error while opening the file,Please try again. \n";
        exit(0);
    }

    while(!file.eof())
    {
        string temp="";
        getline(file,temp);
        for(int j=0; j<temp.size(); j++)
        {
            // check if ch is an alphanumeric (either letter or number)
            if( isalnum(temp[j]) || (temp[j]=='.' && k!=0 ) || (temp[j]=='_' && k!=0 ))

                buffer[k++] = temp[j];




            else if((temp[j] == ' ' || temp[j] == '\n') && (k != 0))
            {
                buffer[k] = '\0';
                k = 0;

                Check_Fun(buffer);


            }

            for(int i = 0; i < 2; ++i)
            {
                if(temp[j] == logical_op[i])
                {
                    if(k!=0)
                    {
                        Check_Fun(buffer);
                    }
                    k=0;
                    cout << temp[j] << "  is a Logical operator \n";
                }
            }


            for(int i = 0; i < 5; ++i)
            {
                if(temp[j] == math_op[i])
                {
                    if(k!=0)
                    {
                        Check_Fun(buffer);
                    }
                    k=0;
                    cout << temp[j] << "  is a Math operator \n";
                }

            }


            for(int i = 0; i < 12; ++i)
            {
                if(temp[j] == special_char[i])
                {
                    if(k!=0)
                    {
                        Check_Fun(buffer);
                    }
                    k=0;
                    cout << temp[j] << "  is a Special Character \n";
                }
            }



        }

    }

    file.close();

    return 0;
}
