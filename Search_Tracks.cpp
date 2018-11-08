#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
// s1025079 Hansaem Chung
// s4817575 Jimmy Hu
using namespace std;

struct Length
{
	int minutes;							// #minutes (0..)
	int seconds;							// #seconds (0..59)
};

struct Track
{
	string artist;                          // name of artist
	string cd;                              // cd title
	int    year;                            // year of appearance (if known)
	int    track;							// track number
	string title;                           // track title
	string tags;                            // tags
	Length time;							// playing time
	string country;                         // main countr(y/ies) of artist
};

struct TrackDisplay
{
	bool showArtist;						// if true, show name of artist
	bool showAlbum;							// if true, show cd title
	bool showYear;							// if true, show year of appearance
	bool showTrack;							// if true, show track number
	bool showTitle;							// if true, show track title
	bool showTags;                          // if true, show tags
	bool showLength;						// if true, show playing time
	bool showCountry;                       // if true, show countr(y/ies) of artist
};

/* For testing purposes, you can use the below defined, very small, music database.
   This is also convenient if you have not yet implemented reading the database file.
*/
vector<Track> testDB = {{"Adele",                          "19",                          2008,1, "Daydreamer",                  "pop,debut album",                   { 3,40},"England"}
                       ,{"Adele",                          "19",                          2008,10,"My same",                     "pop,debut album",                   { 3,15},"England"}
                       ,{"Adele",                          "19",                          2008,11,"Tired",                       "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,12,"Hometown glory",              "pop,debut album",                   { 4,31},"England"}
                       ,{"Adele",                          "19",                          2008,2, "Best for last",               "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,3, "Chasing pavements",           "pop,debut album",                   { 3,30},"England"}
                       ,{"Adele",                          "19",                          2008,4, "Cold shoulder",               "pop,debut album",                   { 3,11},"England"}
                       ,{"Adele",                          "19",                          2008,5, "Crazy for you",               "pop,debut album",                   { 3,28},"England"}
                       ,{"Adele",                          "19",                          2008,6, "Melt my heart to stone",      "pop,debut album",                   { 3,23},"England"}
                       ,{"Adele",                          "19",                          2008,7, "First love",                  "pop,debut album",                   { 3,10},"England"}
                       ,{"Adele",                          "19",                          2008,8, "Right as rain",               "pop,debut album",                   { 3,17},"England"}
                       ,{"Adele",                          "19",                          2008,9, "Make you feel my love",       "pop,debut album",                   { 3,32},"England"}
                       ,{"Adele",                          "21",                          2011,1, "Rolling in the deep",         "pop",                               { 3,49},"England"}
                       ,{"Adele",                          "21",                          2011,10,"Lovesong",                    "pop",                               { 5,16},"England"}
                       ,{"Adele",                          "21",                          2011,11,"Someone like you",            "pop",                               { 4,47},"England"}
                       ,{"Adele",                          "21",                          2011,2, "Rumour has it",               "pop",                               { 3,43},"England"}
                       ,{"Adele",                          "21",                          2011,3, "Turning tables",              "pop",                               { 4,10},"England"}
                       ,{"Adele",                          "21",                          2011,4, "Don't you remember",          "pop",                               { 4, 3},"England"}
                       ,{"Adele",                          "21",                          2011,5, "Set fire to the rain",        "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,6, "He won't go",                 "pop",                               { 4,37},"England"}
                       ,{"Adele",                          "21",                          2011,7, "Take it all",                 "pop",                               { 3,48},"England"}
                       ,{"Adele",                          "21",                          2011,8, "I'll be waiting",             "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,9, "One and only",                "pop",                               { 5,48},"England"}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,1, "Call me star",                "alternative,rock",                  { 3,54},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,2, "El centro",                   "alternative,rock,instrumental",     { 8,25},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,3, "Dirt preachers",              "alternative,rock",                  { 3,44},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,4, "This is where it falls apart","alternative,rock",                  { 7, 2},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,5, "Mellowing",                   "alternative,instrumental",          { 3,11},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,6, "Open passageways",            "alternative,rock",                  { 3,14},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,7, "Instrumental 2 (welcome to the caveman future)"
                                                                                                                                ,"alternative,rock,instrumental",     { 2,33},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,8, "Talisman",                    "alternative,rock",                  { 6, 7},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,9, "Blood and sand / milk and endless waters","alternative,rock",      { 7,20},"U.S.A."}
                       ,{"The decemberists",               "The tain",                    2005,1, "The tain (parts i-iv)",       "progressive,experimental,folk,rock",{18,35},"U.S.A."}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,1, "The sun roars into view",     "jazz,instrumental,experimental",    { 7,37},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was"  ,2015,2, "Won't be a thing to become",  "jazz,instrumental,experimental",    { 3,24},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,3, "In the vespers",              "jazz,instrumental,experimental",    { 6, 2},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,4, "And still they move",         "jazz,instrumental,experimental",    { 2,56},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,5, "With the dark hug of time",   "jazz,instrumental,experimental",    { 6,34},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,6, "The rest of us",              "jazz,instrumental,experimental",    { 6,30},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,7, "Never were the way she was",  "jazz,instrumental,experimental",    { 8,12},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,8, "Flight",                      "jazz,instrumental,experimental",    { 1,38},"U.S.A.,Canada"}
                       } ;

bool match (string sub, string source)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    Result is true only if sub is a literal (case sensitive) sub string of source.
*/
    return source.find(sub) != string::npos ;
}


ostream& operator<< (ostream& out, const Length length)
{
    // Precondition:
    assert (true) ;
    /*  Postcondition:
        the value of length is shown via out in the format: minutes, ':', seconds (two digits)
    */
    if(length.minutes < 10)
        out << "0";
    out << length.minutes << ":";
    if (length.seconds < 10)
        out << "0";

    out << length.seconds ;
    return out;
}

istream& operator>> (istream& in, Length& length)
{
    // Precondition:
    assert (true) ;
    /*  Postcondition:
        the value of length has been read from in: first minutes, then ':', then seconds
    */
    //  if (length.minutes < 10)
//       in >> '0';
    in >> length.minutes;

    in.ignore();
//    if (length.seconds < 10)
//        in >> '0';
    in >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{
    // Precondition:
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
    /*  Postcondition:
        Result is the sum of a and b.
    */
    Length nw;
    nw.seconds = a.seconds + b.seconds;
    nw.minutes = a.minutes + b.minutes;
    if (nw.seconds >= 60)
    {
        nw.minutes += 1;
        nw.seconds -= 60;
    }
    return nw;
}



istream& operator>> (istream& in, Track& track)
{
    // Precondition:
    assert (true) ;
    /*  Postcondition:
        the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
        The following (empty) line from in has also been read.
    */
    //strings: getline
    // ints: in >>
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year
       >> track.track;
    in.ignore();
    getline(in, track.title);
    getline(in, track.tags);
    in >> track.time;
    in.ignore();
    getline(in,track.country);
    in.ignore();
    return in;
}

void show_track (Track track, TrackDisplay lt)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    only the members of track are shown for which the corresponding member in lt is true.
*/
    if(lt.showArtist)
        cout<<track.artist<<"\t";
    if(lt.showAlbum)
        cout<<track.cd<<"\t";
    if(lt.showCountry)
        cout<<track.country<<"\t";
    if(lt.showLength)
        cout<<track.time<<"\t";
    if(lt.showTags)
        cout<<track.tags<<"\t";
    if(lt.showTitle)
        cout<<track.title<<"\t";
    if(lt.showTrack)
        cout<<track.track<<"\t";
    if(lt.showYear)
        cout<<track.year<<"\t";
    cout<<"\n";

}



int match_tracks (vector<Track>& tracks, string track, bool display)
{
    //pre-condition
    assert(true);
    //post-condition
    /*
    it compares tracks' title with track(the word user find)
    find titles which contains certain string
    and count the number matched with it
    if display is true, initialize show_track in certain conditions
    */
    TrackDisplay lt;
    int no = 0;
    int co=0;
    int N = tracks.size();
    while (no < N)
        {
        if(match(track,tracks[no].title))
            {
            co++;
                if(display)
                {
                lt.showArtist=true;
                lt.showAlbum=true;
                lt.showYear=true;
                lt.showTrack=true;
                lt.showLength=true;
                lt.showTitle=true;
                lt.showTags=true;
                lt.showCountry=true;
                show_track(tracks[no],lt);

                }
            }
            no++;
        }
    return co;

}

int match_artists (vector<Track>& tracks, string artist, bool display)
{
    //pre-condition
    assert(true);
    //post-condition
    /*
    it compares tracks' artist with track(the word user find)
    find artist which contains certain strings
    if the string is same as the one found before, it won't count it
    and count the number of artist matched with it
    if display is true, initialize show_track in certain conditions
    */
    TrackDisplay lt;
                lt.showArtist=true;
                lt.showAlbum=false;
                lt.showYear=false;
                lt.showTrack=false;
                lt.showLength=false;
                lt.showTitle=false;
                lt.showTags=false;
                lt.showCountry=false;
    int no = 0;
    int co=0;
    int N = tracks.size();
    if(match(artist,tracks[no].artist))
            {
            co++;
            if(display)
                show_track(tracks[no],lt);
            }
            no++;

    while (no < N)
        {
        if(match(artist,tracks[no].artist)
           &&!match(tracks[no-1].artist,tracks[no].artist))
            {
            co++;
                if(display)
                show_track(tracks[no],lt);
            }
            no++;
        }
    return co;
}

int match_cds (vector<Track>& tracks, string artist, bool display)
{
    //pre-condition
    assert(true);
    //post-condition
    /*
    it compares cd's artist with track(the word user find)
    find artist which contains certain strings
    if the cd's title is same as the one found before, it won't count it
    and count the number of cd's matched with it
    if display is true, initialize show_track in certain conditions
    */
    TrackDisplay lt;
                lt.showArtist=true;
                lt.showAlbum=true;
                lt.showYear=true;
                lt.showTrack=false;
                lt.showLength=false;
                lt.showTitle=false;
                lt.showTags=false;
                lt.showCountry=false;
    int no = 0;
    int co=0;
    int N = tracks.size();
    if(match(artist,tracks[no].artist))
            {
            co++;
                if(display)
                {
                show_track(tracks[no],lt);
                }
            }
            no++;
    while (no < N)
        {

        if(match(artist,tracks[no].artist)

           &&!match(tracks[no-1].cd,tracks[no].cd))
            {
            co++;
                if(display)
                {
                show_track(tracks[no],lt);

                }
            }
            no++;
        }
    return co;
}

int number_of_cds (vector<Track>& tracks)
{
    //pre-condition
    assert(true);
    //post-condition
    /*
    This function returns the total number of CDs.
    Each CD is counted exactly once
    */
    int no = 1;
    int co=1;
    int N = tracks.size();
    while (no < N)
        {

        if(!match(tracks[no-1].cd,tracks[no].cd))
            {
            co++;
            }
            no++;
        }
    return co;
}



int main()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the music database "Tracks.txt" has been read (if present and correctly formatted).
    The assignment queries have been executed and their result has been shown on screen.
    In case of the bonus assignment, the user has been able to query the database and has
    seen the results of these queries.
*/
    //cout<<match_tracks(testDB,"el",true);
    //cout<<match_artists(testDB,"el",true);
    //cout<<match_cds(testDB,"el",true);
    //cout<<number_of_cds(testDB);
    vector<Track> tracks;
    Track trak1;
    ifstream infile("Tracks.txt");
    while(infile) {
        infile >> trak1;
        tracks.push_back(trak1);
    }
    TrackDisplay ds = {true, true, true, true, true, true, true, true};

    cout<<tracks.size()-1<<"\n";
    for(int i =0; i <tracks.size();i++)
    {
        show_track(tracks[i],ds);
    }
    //match_tracks(tracks,"",true);
    return 0;
}
