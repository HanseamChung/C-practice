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

bool read_word (ifstream& infile, char word [MAX_CHARS])
{
    //pre_conditions:
    assert(infile.is_open());
    //post_conditions:
    //result is true only if word has been filled with
    //a next word from infile
    //********added contents****
    //it distinguish whether letter or not, and if it is not letter, the value is changed '\0'
    infile >> word ;
        for(int i=0; i < MAX_CHARS;i++)
        {

            if(word[i]==45 && word[i+1]==45){
            word[i] =='\0' ; word[i+1] =='\0';}

        else if (word[i]>=65 &&word[i]<=90 ||word[i]>=97 &&word[i]<=122 || word[i]==47|| word[i]==45){

        }

        else{
        word[i] ='\0';
        }
    }
    return infile;
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

int main()
{
    char word[MAX_CHARS];
    char words [MAX_WORDS][MAX_CHARS] ;
    int freqs [MAX_WORDS];

    ifstream myfile("a.txt");
    open_file(myfile);
    read_word(myfile, word);

    int nr=count_words(myfile,words,freqs);

    display_frequencies(words,freqs,nr);
    myfile.close();

}
