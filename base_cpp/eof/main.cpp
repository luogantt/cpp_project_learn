#include<iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
    char data;
    ifstream infile;
    ifstream infile1;
    std::vector<string> classNames;
    infile.open("../my.txt");

    if(infile.fail())
    {
        cout<<"Fail to open the input file"<<endl;
        exit(1);
    }

    while( !infile.eof() )
    {
        infile >> data;
        cout << data <<endl;
    }

    infile1.open("../my.txt");
    vector<string> alpha;
    std::string word;
    while( infile1>> word)
    {
        alpha.push_back(word);
    }


    cout<<"alpha.size="<<alpha.size()<<endl;
    for (int i = 0; i < alpha.size(); i++)
    {
        cout << "alpha["<<i <<"]= "<< alpha[i] << endl;
    }



    infile.close();
    cout << endl;

    return 0;
}