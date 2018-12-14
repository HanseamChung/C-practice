//s1025079 Hansaem Chung
// s4817575 Jimmy Hu


#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

int power(int x, int n)
{
    //pre-condition
    assert(x>=0&&n>=0);
    /*post-condition
    it multiply x n times by repeating power function
    */
    if (n==0)
        return 1;

    return x*power(x,n-1);
}

int power_efficient(int x, int n)
{
        //pre-condition
    assert(x>=0&&n>=0);
    /*post-condition
    it multiply x n times by repeating power function
    but when n is divided by 2, it divide the function two part
    */
    if (n==0)
    {
        return 1;
    }

    if(n%2==0)
    {
        int y = power_efficient(x , n/2);
        return y*y;
    }

    return x*power_efficient(x,n-1);
}
//run time complexity = (2logn)^(2longn)

bool same(int a, int b)
{//pre=condition
    assert(true);
/*post-condition
if a=b, return true
if a=b and a is a capital letter and b is a small letter, return true
if a=b and a is a small letter and b is a capital letter, return true
*/
    if (a == b)
        return true;
    if (a>=65&&a<=90&&(a +32 ==b))
        return true;
    if (a>=97&&a<=122&&(a - 32 == b))
        return true;
    else
        return false;
}
bool palindrome1 (string text, int i, int j)
{
    //pre-condition
    assert(i>=0&&j>=0);
/*post-condition
it compare the text[i] and text[j]
if it is same, repeat on text[i+1] and text[j-1]
if there is some letter not matched, return false
if not, return true
*/
    if (i>=j)
        return true;

    if (text[i] !=text[j])
{
        cout<<"not_pal";
        return false;
}

    cout<<"palindromel!";
    return palindrome1(text,++i,j--);


}



bool palindrome2 (string text, int i, int j)
{
    //pre-condition
    assert(i>=0&&j>=0);
/*post-condition
it compare the text[i] and text[j]
by using same boolean, if it is same, repeat on text[i+1] and text[j-1]
if there is some letter not matched, return false
if not, return true
*/
    if (i>=j)
        return true;

    if (!same(text[i],text[j]))
{
        cout<<"not_pal";
        return false;
}

    cout<<"palindromel!"<<"\n";
    return palindrome1(text,++i,j--);


}

bool palindrome3 (string text, int i, int j)
{
    //pre-condition
    assert(i>=0&&j>=0);
/*post-condition
If there is a letter which is not alphabet, it skip and see next letter
it compare the text[i] and text[j]
by using same boolean, if it is same, repeat on text[i+1] and text[j-1]
if there is some letter not matched, return false
if not, return true
*/
    if (i>=j)

return true;



if  (!((65<=text[i]&&90>=text[i])||(97<=text[i]&&122>=text[i])))
    i++;

if  (!((65<=text[j]&&90>=text[j])||(97<=text[j]&&122>=text[j])))
    j--;


    if (!same(text[i],text[j]))
{
        cout<<"not_pal";
        return false;

}
    cout<<"palindromel!"<<"\n";
        return palindrome1(text,++i,j--);


}



bool match_chars (string chars, int i, string source, int j)
{
    //pre-condition
    assert(i>=0&&j>=0);
    /*post-condition
    if chars[i] and source[j]is not matched, operate this function on
    j+1 condition. if there is no letters matched till the end of source, return false
    if there is, add 1 to i and j
    and repeat till the end of length of chars

    */
   if (i == chars.length())
    return true;
   if (j ==source.length())
    return false;
   if (chars[i]==source[j])
    return match_chars(chars, i+1, source, j+1);
    if(chars[i]!=source[j])
    return match_chars(chars, i, source, j+1);
}

int main()
{
    int i =0;
    int j =0;
    //cout << power(2,4) << endl;
    string text = "Otto";
    string text2 = "Mddap, I'p Addm.";
    string text3 = "abc";
    string text4 =  "It is a bag of cards";
    //palindrome1(text,0,3);
    //palindrome2(text,0,3);
    //palindrome3(text2,0,15);

    if(match_chars(text3,i,text4,j))
        cout<<"true";
}
