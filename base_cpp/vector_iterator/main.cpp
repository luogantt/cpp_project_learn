#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    //顺序访问
    vector<int>obj;
    for(int i=0;i<10;i++)
    {
        obj.push_back(10-i);   
    } 
 
    cout<<"直接利用数组：";

    sort(obj.begin(),obj.end()); 
    for(int i=0;i<10;i++)//方法一 
    {
        cout<<obj[i]<<" ";
	//cout<<&obj[i]<<" ";
    }

    cout<<"输出vector的指针"<<endl;
    for(int i=0;i<10;i++)//方法一
    {
        //cout<<obj[i]<<" ";
        cout<<&obj[i]<<" ";
    }


 
    cout<<endl; 
    cout<<"利用迭代器：" ;

    vector<int>::iterator it ;

    for (it=obj.begin();it!=obj.end();it++)
    {
        cout<<*it<<" ";

    }

    /*** 
    for (it=obj.begin();it!=obj.end();it++)
    {
        cout<<it<<" ";

    }
    ***/
    cout<<endl; 
    return 0;
}
