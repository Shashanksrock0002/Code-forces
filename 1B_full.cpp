#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

//this is nothing just matching 65 to 1 66 to 2 like so
int ASCII_Convertor(int character)
{
    return character-64;
}
//through this we are mapping character to integer like A to 1 and AA to 27
int col_into_integer(string col)
{
    int s1=col.size();
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    for(int i=s1-1;i>=0;i--)
    {
// {ASCII_Convertor(name[i])<<endl;
        a=ASCII_Convertor(col[i]);
        // cout<<a<<"::";
        c=a*pow(26,d);
        d++;
        b=b+c;

    }
    return b+s1-1;
}
//We will not be using this function it is more advanced fucntion and some
//optiminsation is still required
/*void string_split(string c)
{
    //  string c = "6741W672ASDSD12D1F34";
    int num = 0;

    int size = c.size();
    cout << "size is : " << size << endl;
    string a[c.size()];
    string b[c.size()];
    int j = 0;
    int k = 0;
    int l=1;
    int m=1;
    string var = "";
    int count = 0;
    // a = "";
    for (int i = 0; i < size; i++)
    {
        if (c[i] >= '0' && c[i] <= '9') //to confirm it's a digit
        {
            if (k > 0)
            {
                j++;
            }
            a[j] = a[j] + c[i];
            k = 0;

        }
        else
        {
            k++;
        }
    }
    int array_number[j + 1];
    string array_char[l];
    cout << endl
         << sizeof(a[4]) << " 1" << endl;
    cout << j << endl<<"-------------"<<endl;

    for (int i = 0; i < j + 1; i++)
    {
        array_number[i] = stoi(a[i]);
        cout << "array at " << i << ": " << array_number[i] << endl;
        // cout<<" : "<<sizeof(a)<<": ";
        // cout<<sizeof(array_)<<": ";
    }
    cout<<"-------------"<<endl;
    for (int i = 0; i < l ; i++)
    {
        array_char[i] = b[i];
        cout << "array at " << i << ": " << array_char[i] << endl;
        // cout<<" : "<<sizeof(a)<<": ";
        // cout<<sizeof(array_)<<": ";
    }
    
    // cout<<"--------------"<<endl;
    // for(int i=0;i<size;i++)
    // {
    //     cout<<i<<"   :"<<b[i]<<"    :      :";
    //     cout<<a[i]<<" : "<<endl;
    // }

}*/
//this funcion is used for converting RXCY array into array of two having X and Y
int* numeric_index_array(string index)
{
int size=index.size();
int count=0;
string after="";
string before="";
int *arr=new int[2];
for(int i=0;i<size;i++)
{
    if(index[i]=='R' && count==0)
    {
        count=1;
    }
    if(index[i]=='C'&&count==1)
    {
        count=2;
    }
    if(count==1 && index[i]!='R')
    {
        before=before+index[i];
        // cout<<"inserting :"<<index[i]<<endl;
    }
    if(count==2&& index[i]!='C')
    {
          after=after+index[i];
        //   cout<<"inserting ::::"<<index[i]<<endl;
    }
}

arr[0]=stoi(before);
// cout<<arr[0]<<endl;
arr[1]=stoi(after);
// cout<<arr[1];
return arr;
}
//it splits string into numeric portion as well as into alphabetic protion
string *split_string(string s)
{
string *array=new string[2];
    int size=s.size();
    for(int i=0;i<size;i++)
    {
        int a=s[i];
        if(a>48&&a<58)
        {
            array[0]=array[0]+s[i];
        }
            if(a>64 && a<91)
        {
        array[1]=array[1]+s[i];
        }
    }
return array;
}
//This function is used integer index to number like 25-Z 27-AA 52-AZ
string int_to_sting(int index)
{ 
    int reminder=0;
    char ascii=' ';
    string full="";
    
    while(index>=1)
{
    reminder=index%26;
    index=index/26;
    if(reminder==0)
    {
        reminder=26;
        index--;
    }
    reminder=reminder+64;
    if(reminder==64)
    {
        reminder=90;
    }
    ascii=char(reminder);
    if(index==1 && reminder==90)
    {
        full=ascii;
    }
    else
   { full=full+ascii;
   }
    reminder=0;
}
string final;
int n=full.size();
for(int i=0;i<n/2;i++)
{
swap(full[i],full[n-i-1]);
}
return full;

}
//for converting R23C55 into BC23
string func1(string index)
{
int *ptr=numeric_index_array(index);
ptr[0];
ptr[1];
string string_alpha=int_to_sting(ptr[1]);
string_alpha=string_alpha+to_string(ptr[0]);
return string_alpha;
}

//for converting BC23 into R23C55
string func2(string index)
{
    string *split=split_string(index);//ex index=BC23
    string numeric=split[0];//split[0]=23,split[1]=BC
    string alpha=to_string(col_into_integer(split[1]));//here BC is converted to 55
    string to_return ='R'+numeric+'C'+alpha;
    return to_return;

}




int main()
{
    int number;
    cin>>number;
    string arr[number];
    for(int i=0;i<number;i++)
    {
        cin>>arr[i];
        if(i%2==0)
        {
        arr[i]=func1(arr[i]);
        }
        else
        {
            arr[i]=func2(arr[i]);
        }
        cout<<arr[i]<<endl;
        
    }
    


}