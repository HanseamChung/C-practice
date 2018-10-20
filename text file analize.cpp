#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
//2015079 Hansaem Chung 2015078 Hanseob Yoo
const int MAX_CHARS = 60;
const int MAX_WORDS = 30000;

bool open_text_file(char filename[80] )
{   //pre-conditions
    assert (filename >0);
    ifstream infile;
//    cout<< "Pleaseenter file name: ";
//    cin.getline(  filename, 80, '\n') ;
    infile.open(  filename) ;
    return infile.is_open()   ;

}

int sequential_search (char data[MAX_WORDS][MAX_CHARS], int from, int to, char search_value[MAX_CHARS])
{
    //pre-conditons:
    assert(0<=from && 0 <= to);
    //post-conditions:
    //if from > to : result = to+1
    //if search_value is not an element of data : result = to+1
    //ohterwise:    result value is the index of the first occurrence of
    //              search_value in data[from] ~ data[to]
    //              hence: from <= result value <= to
    if (from > to)
        return to + 1;
    int position = from ;
    while (position <= to && data [position] != search_value)
        position++;
    return position;
}





bool read_word (ifstream& infile, char word [MAX_CHARS])
{
    //pre_conditions:
    assert(infile.is_open());
    //post_conditions:
    //result is true only if word has been filled with
    //a next word from infile
    infile >> word ;
    return infile;
}

bool tally_word (char word[MAX_CHARS],char words [MAX_WORDS][MAX_CHARS],
                 int freqs[MAX_WORDS], int& no)
{
    //pre_conditions:
    assert(no>=0 && no < MAX_WORDS);
    //post_conditions:
    //result = true when for some 0<=1 no & words[i] is word hence freqs[i]++
    //or word is not found, hence words[no] = word, freqs[no] = 1, no++
    int pos = sequential_search(words, 0, no, word) ;
    if (pos < no)
    {
        freqs [pos]++ ;
        return true ;

    } else if (pos < MAX_WORDS)
    {
        strcpy(words[pos],word);
        freqs[pos]=1;
        no++;
        return true;
    }
    return false;

}

int count_words( ifstream& infile, char words [MAX_WORDS][MAX_CHARS],
                int freqs [MAX_WORDS])
{
    //pre-conditions
    assert(infile.is_open());
    //post-condition
    const int MAX_CHARS = 60;
    const int MAX_WORDS = 30000;
    int no = 0 ;
    char next [MAX_CHARS];
    while ( read_word(infile,next)&&
           tally_word(next,words,freqs,no)&&
           no<MAX_WORDS);
    return no;
}

void display_frequencies (char words [MAX_WORDS][MAX_CHARS],
                          int freqs [MAX_WORDS], int no)
{
    //pre-conditions:
    assert (no>=0 && no < MAX_WORDS);
    //post-conditions:
    //all(words[i],freqs[i]) pairs have been printed, for 0<=i<n
    for (int i = 0 ; i < no ; i++)
    {
        cout << words [i] << "\t" << freqs [i] << "\n" ;
    }
}

static int count_array (const std::string *array)
{
    //pre-conditon
    assert(true);
    //post condition
    // count the array till the
    size_t i = 0;
    while (!array[i].empty())
        ++i;
    return i;
}




void display_frequencies2 (char words [MAX_WORDS][MAX_CHARS],
                          int freqs [MAX_WORDS], int no, string inputed_word[])
{
    //pre-conditions:
    assert (no>=0 && no < MAX_WORDS);
    //post-conditions:
    //this function at first count matched word(mw) in one sequence(i) and if mw is matched with whole words(nw2) add 1 to c2
    //mw is initialized when i is changed
    //it repeat in whole file
    int nw2 = count_array(inputed_word);
    int c2 = 0;
    for (int i = 0 ; i < no ; i++)
    {
        int mw = 0;
        for (int j =0 ; j < nw2 ; j++)
            {
                if (inputed_word[j] == words[i+j]) mw++;
                if(mw==nw2) c2++;
            }
    }
    for (int j= 0 ; j < nw2 ; j++)
    {
        cout << inputed_word[j] << " " ;
    }
    cout << "\t" << c2 << "\n" ;

}

void find_location (char words [MAX_WORDS][MAX_CHARS],
                          int freqs [MAX_WORDS], int no, string inputed_word[])
{
    //pre-conditions:
    assert (no>=0 && no < MAX_WORDS);
    //post-conditions:
    //basic operating system is similar with display_frequency2
    //if condition is met, it reserve location's number(i) into loc_no
    //
    int nw2 = count_array(inputed_word);
    int c2 = 0;
    int loc_no[MAX_CHARS];
    int ln=0;
    for (int i = 0 ; i < no ; i++)
    {
        int mw = 0;
        for (int j =0 ; j < nw2 ; j++)
            {
                if (inputed_word[j] == words[i+j]) mw++;
                if(mw==nw2) {
                            c2++;
                            loc_no[ln++]=i;
                            }
            }
    }
    for (int j= 0 ; j < nw2 ; j++)
    {

    }
    cout << loc_no[0];
    cout << "\t" << c2 << "\n" ;

}

void open_file(ifstream& myfile)
{
    if (myfile.is_open())
    {
        cout << "success" << endl;
    }else
    {
        cout << "Fail.." << endl;
    }
}

void open_content(ifstream& myfile)
{
    //pre-condition
    assert(myfile.is_open());
    string content;
    while(myfile.good())
    {
        getline(myfile, content);
        cout << content << endl;
    }

}




int main()
{
string command;
string command2;
char filename[MAX_CHARS];
cout << "Enter command1 and file's name: ";
cin>>command;
cin.ignore(1);
cin.getline(filename,MAX_CHARS);
ifstream myfile(filename);
open_file(myfile);

if (command =="enter")
{
    char words [MAX_WORDS][MAX_CHARS] ;
    int freqs [MAX_WORDS];

    int nr=count_words(myfile,words,freqs);
    cout<<nr;
    {
         cout << "\nEnter command2";
         cin >> command2;
        string inputed_word[MAX_CHARS];

        for (int i=0 ; i<2; i++) // I dont know how to stop repeating when user press enter
        {
        cin >> inputed_word[i];
        cout << inputed_word[i]<<"\n";
        }
         if (command2 =="count")
        {
           display_frequencies2(words,freqs,nr, inputed_word);
           return true;
        }
        else if (command2 =="where")
        {
            find_location(words,freqs,nr, inputed_word);
            return true;
        }
        else if (command2 =="context")
        {
            return true;
        }

    }

}

else if (command =="content")
{
    open_content(myfile);
}
else if (command =="stop")
    cout<<"terminate the program";
    return false;
}
