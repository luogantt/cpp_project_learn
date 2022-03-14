#include <iostream>


/***
//用法1：输入一个数字或字符
#include <iostream>
using namespace std;
int main ()
{
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    return 1;
}

 ***/




/***
//用法2：接收一个字符串，遇“空格”、“TAB”、“回车”就结束
#include <iostream>
using namespace std;
int main ()
{
    char a[20];
    cin>>a;
    cout<<a<<endl;
    return 1;
}
***/

//二、cin.getline()
//用法:接收一个字符串，可以接收空格并输出





/***
#include <iostream>
using namespace std;
int main ()
{
    char m[20];
    cin.getline(m,5);
    cout<<m<<endl;
    return 1;
}
 ***/



/***
//三、getline()
//用法：接收一个字符串，可以接收空格并输出，需包含“#include<string>”

#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
    return 1;
}
 ***/





/***
四、注意的问题
1、cin.getline()属于istream流，而getline()属于string流，是不一样的两个函数

2、当同时使用cin>>,getline()时，需要注意的是，在cin>>输入流完成之后，getline()之前，需要通过
 ***/

/*-------------Basic Input/Output-------------*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    int age;
    //standard input(cin)
    cout<<"Please enter an integer value as your age: ";
    cin>>age;
    cout<<"Your ager is: "<<age<<".\n";
    //cin and string
    string mystr;
    cout<<"What's your name? "<<endl;
    mystr="\n";
    getline(cin,mystr);

    getline(cin,mystr);
    cout<<"Hello,"<<mystr<<".\n";
    char sex;
    cout<<"Please enter a F or M as your sex: ";
    cin>>sex;
    cout<<"Your sex is: "<<sex<<endl;
    cout<<"What's your favorite team? ";
    mystr="\n";
    getline(cin,mystr);

    getline(cin,mystr);
    cout<<"I like "<<mystr<<".\n";

    //system("pause");
    return 0;
}


/***

 ***/
