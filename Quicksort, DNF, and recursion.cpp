//s1025079 Hansaem Chung
// s4817575 Jimmy Hu


/*********************************************************************
*   Example framework for assignment 9 IPC031.
*   Content:
*   - the type definitions for the music database for *arrays* (convert this yourself to vector, see part 1)
*   - ordering relations on Track;
*   - reading Tracks.txt file;
*   - functions and data structures from lecture #9 IPC031:
*   - sorting algorithms insertion_sort, selection_sort, bubble_sort
*     (based on *arrays*, convert this yourself to vector)
*   - main that reads Tracks.txt and calls a sorting algorithm.
**********************************************************************/
#define NDEBUG

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>


using namespace std;


/*********************************************************************
*   type definitions and global array songs:
**********************************************************************/
struct Length
{
    int minutes;							// #minutes (0..)
    int seconds;							// #seconds (0..59)
};
struct Track
{
    string artist;                          // artist name
    string cd;                              // cd title
    int    year;                            // year of appearance
    int    track_no;						// track number
    string title;                           // track title
    string tags;                            // track tags (separated by ,)
    Length time;							// track length
    string country;                         // countr(y/ies) of artist (separated by ,)
};

const int MAX_NO_OF_SONGS = 6000;           // NOTE: only required for *array*
vector<Track> songs ;              // NOTE: this must become vector<Track>
int counter=0;
/************************************************************************
*   Ordering relations op Track:
*      define < and == for Length and Track yourself, the other
*      ordering relations (>, <=, >=, >) follow from these automatically.
************************************************************************/
bool operator <(const Length& a, const Length& b)
{
    /*post-condition
    if minutes is not same, return the comparison's result
    else, compare the seconds, and return the comparison's result
    */
    if (a.minutes == b.minutes)
        return a.seconds < b.seconds;
    else
        return a.minutes < b.minutes;
}

bool operator==(const Length& a, const Length& b)
{

    return a.minutes==b.minutes && a.seconds==b.seconds;
}


bool operator<(const Track& a, const Track& b)
{
    /*post condition
    it compare Track's artist, cd, year, track_no one by one
    if the component is not same, return the component's comparing result
    if its same, it compare next component

    */
    counter++;
    return a.time < b.time;

    //cout<<counter<<endl;
    /*
        if(a.artist == b.artist)
        {if(a.cd == b.cd)
            {if(a.year == b.year)
                {if(a.track_no == b.track_no){}
                 else return a.track_no < b.track_no ;
                }
                else return a.year < b.year ;
                }
            else return a.cd<b.cd;
            }

         else
            return a.artist < b.artist;

            */

    if(a.artist == b.artist)
    {
        if(a.cd == b.cd)
        {
            if (a.track_no == b.track_no)
            {
                return false;
            }
            else
                return a.track_no < b.track_no;
        }
        else
            return a.cd < b.cd ;
    }
    else
        return a.artist < b.artist;


}

/* implement a correct <  ordering on Track values */

bool operator==(const Track& a, const Track& b)
{
    /*post condition
    it compare Track's artist, cd, year, track_no
    if one of the components are not same, return false
    only when all of the components are same, return true

    */
    counter++;
    //cout<<counter<<endl;
    //return a.artist == b.artist && a.cd == b.cd && a.year == b.year && a.track_no==b.track_no;
    return a.time == b.time ;
    //&&a.artist == b.artist && a.cd == b.cd &&a.title==b.title;
}



//	derived ordering on Track values:
bool operator>(const Track& a, const Track& b)
{
    /*post condition
    it compare Track's artist, cd, year, track_no one by one
    if the component is not same, return the component's comparing result
    if its same, it compare next component
    */
    return b < a;


}

bool operator<=(const Track& a, const Track& b)
{
    //counter--;
    return !(b < a) ;
}

bool operator>=(const Track& a, const Track& b)
{
    //counter--;
    return b <= a ;
}








/************************************************************************
*   Reading Tracks.txt file:
************************************************************************/
istream& operator>> (istream& in, Length& length)
{
    // Pre-condition:
    assert (true) ;
    /*  Post-condition:
        a value for length has been obtained from in: first minutes, followed by ':', followed by seconds.
    */
    char colon ;
    in >> length.minutes >> colon >> length.seconds ;
    return in ;
}

ostream& operator<< (ostream& out, const Length length)
{
    // Pre-condition:
    assert (true) ;
    /*  Post-condition:
        length is sent to out as: minutes, ':', seconds (at least 2 digits)
    */
    out << length.minutes << ':';
    if (length.seconds < 10)
        out << '0';
    out << length.seconds;
    return out ;
}

void skip_to_next_newline (istream& infile)
{
    // pre-condition:
    assert (true) ;
    /*  post-condition:
        infile has been read up to and including the next newline character.
    */
    string remains ;
    getline (infile, remains) ;
}

istream& operator>> (istream& infile, Track& track)
{
    // pre-condition:
    assert (true) ;
    /*  post-condition:
        infile has been read up to and including all members of one Track entry, including the last separating newline.
        These members are stored in track.
    */
    getline(infile,track.artist);       // artist
    getline(infile,track.cd);           // cd
    infile >> track.year ;              // year
    skip_to_next_newline(infile) ;
    infile >> track.track_no ;          // track number
    skip_to_next_newline(infile) ;
    getline(infile,track.title);        // track title
    getline(infile,track.tags);         // track tags
    infile >> track.time ;              // track time
    skip_to_next_newline(infile) ;
    getline(infile,track.country);      // country
    skip_to_next_newline(infile) ;
    return infile ;
}

// not necessary for assignment (because of show_track function), but included anyway because of symmetry:
ostream& operator<< (ostream& out, const Track track)
{
    // pre-condition:
    assert (true) ;
    /*  post-condition:
        out has emitted all members of track, including the last separating newline.
    */
    out << "Artist: " << track.artist   << endl ;
    out << "Album: " << track.cd       << endl ;
    out << "Year: " << track.year     << endl ;
    out << "Track number: " << track.track_no << endl ;
    out << "Title: " << track.title    << endl ;
    out << "Tags: " << track.tags     << endl ;
    out << "Time: " << track.time     << endl ;
    out << "Country: "<< track.country  << endl ;
    out << endl ;
    return out ;
}

// NOTE: this version uses *array* implementation, convert to vector yourself
int read_songs (ifstream& infile, vector<Track> &songs)
{
    // pre-condition:
    assert (infile.is_open ()) ;
    /*  post-condition:
        All tracks in infile have been read and stored in the same order in songs.
        The result is the number of tracks that have been read.
    */
    int no_of_read_songs = 0 ;
    do
    {
        Track song ;
        infile >> song ;
        if (infile)
            songs.push_back(song) ;
    }
    while (infile);
    return songs.size();
}

int read_file (string filename)
{
    // pre-condition:
    assert (songs.size() == 0) ;
    /*  post-condition:
        If the result is -1, then no file could be opened, and songs is unchanged.
        Otherwise, the result is zero or positive, and songs contains all the found tracks in the
        file that corresponds with filename.
    */
    ifstream songsDBS (filename.c_str());
    if (!songsDBS)
    {
        cout << "Could not open '" << filename << "'." << endl;
        return -1;
    }
    cout << "Reading '" << filename << "'." << endl;
    const int NO_OF_SONGS = read_songs (songsDBS, songs);
    songsDBS.close();
    cout << " Read " << NO_OF_SONGS << " tracks." << endl;
    return NO_OF_SONGS;
}

// NOTE: this version uses *array* implementation, convert to vector yourself
void show_all_tracks (vector<Track> &songs)
{
    // pre-condition:
    assert (true) ;
    /*  post-condition:
        songs[0] ... songs[no_of_songs-1] have been displayed to cout.
    */
    for(int i = 0; i<songs.size(); i++)
        cout << songs[i];
}


/************************************************************************
*   functions and data structures from lecture #9 IPC031:
************************************************************************/
struct Slice
{
    int from ;  // 0    <= from
    int to ;  // from <= to
} ;

Slice mkSlice (int from, int to)
{
    // pre-condition:
    assert (0 <= from && from <= to);
    /*  post-condition:
        result is the slice formed by from and to.
    */ Slice s = { from, to } ;
    return s ;
}

bool valid_slice (Slice s)
{
    // pre-condition:
    assert (true) ;
    /*  post-condition:
        result is true only if s.from is not negative, and s.from is not larger than s.to.
    */
    return 0 <= s.from && s.from <= s.to ;
}

typedef int El ;                // NOTE: for the assignment you need to sort Track values

bool is_sorted (vector<Track> &songs, Slice s)
{
    // pre-condition:
    assert (valid_slice(s)) ; // ...and s.to < size of songs
// post-condition:
// result is true if songs[s.from]   <= songs[s.from+1]
//      songs[s.from+1] <= songs[s.from+2]
//      ...
//      songs[s.to-1]   <= songs[s.to]
    bool sorted = true ;
    for (int i = s.from; i < s.to && sorted; i++)
        if (songs[i] > songs[i+1])
            sorted = false ;
    return sorted ;
}

int find_position ( vector<Track> &songs, Slice s, Track y )
{
    // pre-condition:
    assert (valid_slice(s) && is_sorted(songs,s)) ;    // ...and s.to < size of songs
// post-condition: s.from <= result <= s.to+1
    for ( int i = s.from ; i <= s.to ; i++ )
        if ( y <= songs [i] )
            return i ;
    return s.to+1;
}

void shift_right ( vector<Track> &songs, Slice s )
{
    // pre-condition:
    assert (valid_slice (s)) ; // ... and s.to < size (songs) - 1
// post-condition:  songs[s.from+1] =  old songs[s.from]
//         songs[s.from+2] =  old songs[s.from+1]
//      ...
//         songs[s.to+1]  =  old songs[s.to]
    for ( int i = s.to+1 ; i > s.from ; i-- )
        songs [i]  = songs [i-1] ;
}

void insert ( vector<Track> &songs, int& length, Track y )
{
    // pre-condition:
    Slice s = mkSlice(0,length-1) ;
    assert (length >= 0 && is_sorted (songs, s)) ;
    /*  post-condition:
        value y is inserted in songs[0] ... songs[length-1] at the right ordering position,
        and length is increased by one.
    */
    const int POS = find_position (songs, mkSlice (0, length-1), y) ;
    if (POS < length)
        shift_right ( songs, mkSlice (POS, length-1) ) ;
    songs [POS] = y ;
    length++;
}

void swap (vector<Track> &songs, int  i, int  j )
{
    // pre-condition:
    assert ( i >= 0 && j >= 0 ) ; // ... and i < size of songs
    // ... and j < size of songs
// Post-condition: songs[i] = old songs[j] and songs[j] = old songs[i]
    const Track HELP = songs [i];
    songs [i] = songs [j] ;
    songs [j] = HELP;
}

// array based insertion sort:
void insertion_sort ( vector<Track> &songs, int length )
{
    int sorted = 1 ;
    while ( sorted < length )
    {
        insert ( songs, sorted, songs[sorted] ) ;
    }
}

// array based selection sort:
int smallest_value_at ( vector<Track> &songs, Slice s )
{
    // pre-condition:
    assert (valid_slice (s)) ; // ... and s.to < size (s)
// Post-condition: s.from <= result <= s.to and songs[result] is
// the minimum value of songs[s.from] .. songs[s.to]
    int smallest_at = s.from ;
    for ( int index = s.from+1 ; index <= s.to ; index++ )
        if ( songs [index] < songs [smallest_at] )
            smallest_at = index ;
    return smallest_at ;
}

void selection_sort ( vector<Track> &songs, int length )
{
    for ( int unsorted = 0 ; unsorted < length ; unsorted++ )
    {
        const int k = smallest_value_at (songs, mkSlice (unsorted, length-1));
        swap ( songs, unsorted, k ) ;
    }
}

// array based bubble sort:
bool bubble ( vector<Track> &songs, Slice s )
{
    // pre-condition:
    assert (valid_slice(s)); // ... and s.to < size(songs)
// Post-condition:
// maximum of songs[s.from]..songs[s.to] is at songs[s.to]
// if result is true then sorted( songs, s )
    bool is_sorted = true ;
    for ( int i = s.from ; i < s.to ; i++)
        if ( songs [i] > songs [i+1])
        {
            swap ( songs, i, i+1 ) ;
            is_sorted = false ;
        }
    return is_sorted ;
}

void bubble_sort ( vector<Track> &songs, int length )
{
    while ( !bubble ( songs, mkSlice (0, length-1 ) ) )
        length-- ;
}

void print_stars()
{
    int x;
    int punt;
    x = counter / 100000;
    punt = counter % 100000;
    for (int i = 0; i < x; i++)
        cout << "*";
    if (punt != 0)
        cout << ".";
    cout << endl;
}
/************************************************************************
*   the main structure of the program:
*       - read file
*       - sort data with insertion_sort / selection_sort / bubble_sort
*              and 'normal' order of Tracks
*              and increasing track length
************************************************************************/
enum SortingMethod {InsertionSort,SelectionSort,BubbleSort,NoOfSortingMethods};
string methods [] = {"insertion", "selection", "bubble"} ;

int maximum(int a, int b)
{
    if (a>=b)
        return a;
    else
        return b;
}

int minimum(int a, int b)
{
    if (a<=b)
        return a;
    else
        return b;
}


SortingMethod get_sorting_method ()
{
    cout << "What sorting method do you want to use? " << endl ;
    for (int m = 0; m < NoOfSortingMethods; m++)
        cout << m+1 << ": " << methods[m] << " sort" << endl ;
    int choice ;
    cin >> choice ;
    choice = maximum (1, minimum (choice, NoOfSortingMethods)) ;
    return static_cast<SortingMethod>(choice-1) ;
}

void DNF (vector<Track>& songs, int first, int last, int& red, int& blue)
{
    // pre-condition
    assert (true);
    /* post-condition: function determines the middle element of the vector based on the size of the vector.
    then checks if the unsorted part of the vector is not empty, and sorts the vector by comparing either the album, track number or time, based on the operator.
    Check operators for comparison function.
    */

    red = first - 1;
    blue = last + 1;
    int white = last + 1;
    const Track MIDDLE = songs[first+(last-first)/2];
    while (red < white - 1)
    {
        const int NEXT = white - 1;
        if (songs[NEXT] < MIDDLE)
        {
            red++;
            swap(songs, red, NEXT);
        }
        else if (songs[NEXT] == MIDDLE)
            white--;
        else
        {
            white--;
            blue--;
            swap(songs, NEXT, blue);
        }
    }
    for (int i = 0; i < 40; i++)
     {
        cout << songs[i];
        cout << "Read " << i << " songs" << endl;
     }
}

void DNF_adjust (vector<Track>& songs, int first, int last, int& red, int& blue)
// red, white, orange, blue --> red, white, NEXT, blue
{
    // pre-condition
    assert (true);
    /* post-condition: function determines the middle element of the vector based on the size of the vector.
    then checks if the unsorted part of the vector is not empty, and sorts the vector by comparing either the album, track number or time, based on the operator.
    Check operators for comparison function.
    */

    red = first - 1;
    blue = last + 1;
    int white = red + 1;
    const Track MIDDLE = songs[first+(last-first)/2];
    while (red < white - 1)
    {
        const int NEXT = white + 1;
        if (songs[NEXT] < MIDDLE)
        {
            red++; white++;
            swap(songs, red, NEXT);
        }
        else if (songs[NEXT] == MIDDLE)
        {
            white++;
        }
        else // (songs[NEXT] > MIDDLE)
        {
            blue--;
            swap(songs, NEXT, blue);
        }
    }
    for (int i = 0; i < 40; i++)
     {
        cout << songs[i];
        cout << "Read " << i + 1 << " songs\n" << "Adjusted" << endl;
     }
}

void quicksort (vector<Track>& songs, int first, int last)
{
    // pre-condition
    assert (0 <= first && last < 40);
    // post-condition
    // songs[first] until songs[last] is sorted.
    if (first >= last)
    {
        cout << "returned" << endl;
        return ;
    }
    else
    {
        int red, blue;
        DNF(songs, first, last, red, blue);
        quicksort(songs, first, red);
        quicksort(songs, blue, last);
    }


}
void quicksort_adjust (vector<Track>& songs, int first, int last)
{
    // pre-condition
    assert (0 <= first && last < 40);
    // post-condition
    // songs[first] until songs[last] is sorted.
    if (first >= last)
    {
        cout << "returned" << endl;
        return ;
    }
    else
    {
        int red, blue;
        DNF_adjust(songs, first, last, red, blue);
        quicksort_adjust(songs, first, red);
        quicksort_adjust(songs, blue, last);
    }
}





int largest (vector<Track>& songs, int low, int up)
{
    //pre-condition
     assert (0 <= low && up < 40);
     //post-condition
     //check the low till it is not smaller than up, if not, return low
     //iterate it and at the end, compare song[low]and song[pos]
     //if songs[low] is bigger than songs[POS] return low
     //if not return POS
    if (low >= up)
        return low;
    else
    {
        const int POS = largest(songs, low+1, up);
        if (songs[low] > songs[POS])
            return low;
        else return POS;
    }
}
int largest_iterate (vector<Track>& songs, int low, int up)
{
     //pre-condition
     assert (0 <= low && up < 40);
     //post-condition
     //check the low till it is not smaller than up, if not, return low
     //iterate it and at the end, compare song[low]and song[pos]
     //if songs[low] is bigger than songs[POS] return low
     //if not return POS
    vector<int> stack;
    int POS=0;
    while (low < up)
    {
    POS = low++;
    stack.push_back(POS);
    low++;
    }

    if (songs[stack[0]-1] > songs[POS])
        return stack[0]-1;
    else return POS;
}
void sort (vector<Track>& songs, int n)
{
    if (n > 1)
    {
        const int POS = largest (songs, 0, n-1);
        swap(songs, POS, n-1);
        sort (songs, n-1);
    }
}
void sort_iterate(vector<Track>& songs, int n)
{
    while (n >= 1)
    {
        const int POS = largest (songs, 0, n-1);
        swap(songs, POS, n-1);
    }
    if (n = 0)
        cout << "sorted." << endl;
}

int main()
{
    /*
        const int NO_OF_SONGS = read_file ("Tracks.txt");
        if (NO_OF_SONGS < 0)
        {
            cout << "Reading file failed. Program terminates." << endl;
            return NO_OF_SONGS;
        }

        SortingMethod m = get_sorting_method () ;

        cout << "Sorting tracks with " << methods[m] << " sort" << endl;

          switch (m)
           {
               case InsertionSort: insertion_sort(songs,NO_OF_SONGS) ; break ;
               case SelectionSort: selection_sort(songs,NO_OF_SONGS) ; break ;
               case BubbleSort:    bubble_sort   (songs,NO_OF_SONGS) ; break ;
               default:        cout << "Huh?" << endl ;
           }

        for (int i = 100; i < NO_OF_SONGS; i+=100)
        {
            insertion_sort(songs,i);
            print_stars();
            songs.clear();
            read_file("Tracks.txt");
        }
        //  SelectionSort=17348995 > BubbleSort= 17343324 > InsertionSort =8664447

        //main.exe>>output;
        //show_all_tracks (songs) ;

        */
    vector<Track> songs;
    ifstream infile;
    infile.open("Tracks.txt");
    read_songs(infile, songs);
    int first = 0, last = 40;
    int red,blue;

    //DNF(songs, first, last, red, blue);
    quicksort_adjust(songs, first, last);
    return 0;

}
