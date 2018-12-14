//1025079 HansaemChung
// 4817575  Jimmy Hu



#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

double percentage (int a, int b)
{// pre-condition:
    assert (0 <= a && a <= b && b > 0) ;
//  post-condition: result is the percentage a/b with 2 decimals precision
    return static_cast<int>(10000 * static_cast<double> (a) / b) / 100.0;
}

int minimum (int a, int b)
{// pre-condition:
    assert (true) ;
//  post-condition: result is the minumum value of a and b
    if (a <= b)
        return a ;
    else
        return b ;
}

int maximum (int a, int b)
{// pre-condition:
    assert (true) ;
//  post-condition: result is the maximum value of a and b
    if (a >= b)
        return a ;
    else
        return b ;
}

int between (int lower, int upper, int x)
{// pre-condition:
    assert (true) ;
//  post-condition: result is lower if x < lower, and it is upper if x > upper, otherwise it is just x
    if (x < lower)  return lower ;
    else if (x > upper) return upper ;
    else return x ;
}

typedef int Coin ;

int size (vector<Coin>& coins)
{// pre-condition:
    assert (true) ;
//  post-condition: result is the number of elements in coins
    return static_cast<int> (coins.size()) ;
}

bool real_money (vector<Coin>& coins)
{// pre-condition:
    assert (true) ;
//  post-condition: result is true only if all elements in coins are positive (> 0)
    for (int i = 0 ; i < size(coins) ; i++)
        if (coins[i] < 0)
            return false ;
    return true ;
}

Coin minimum (vector<Coin>& coins, int from)
{// pre-condition:
    assert (from >= 0 && from <= size(coins)) ;
//  post-condition:
//  result is the minimum value of coins[from] .. coins[size(coins)-1], which is 0 in case from == size(coins)
    if (from == size(coins))
        return 0 ;
    Coin m = coins[from] ;
    for (int i = from+1 ; i < size(coins); i++)
        if (coins[i] < m)
            m = coins[i] ;
    return m ;
}

int sum (vector<Coin>& coins, int from)
{// pre-condition:
    assert (from >= 0 && from <= size(coins)) ;
//  post-condition:
//  result is the sum of the values coins[from] .. coins[size(coins)-1] which is 0 in case from == size(coins)
    int sum = 0 ;
    for (int i = from ; i < size(coins) ; i++)
        sum += coins[i] ;
    return sum ;
}

int sum (vector<Coin>& coins)
{
    return sum (coins,0) ;
}

void improve (vector<Coin>& current, vector<Coin>& best)
{// pre-condition:
    assert (true) ;
//  post-condition:
//  best contains the better of the two solutions (current or best)
    if (sum (current) > sum (best))
        best = current ;
}

void show ( vector<Coin>& coins )
{// pre-condition:
    assert (true) ;
//  post-condition: all elements in coins have been printed from index position 0 to size(coins)-1
	const int NO_OF_ELEMS = size (coins) ;
	cout << "{" ;
	if ( NO_OF_ELEMS > 0 )
	{
		for (int i = 0 ; i < NO_OF_ELEMS-1 ; i++)
			cout << coins[i] << "," ;
		cout << coins[NO_OF_ELEMS-1] ;
	}
	cout << "}" << endl ;
}

void swap (vector<Coin>& coins, int i, int j)
{// pre-condition:
    assert (0 <= i && i < size (coins) && 0 <= j && j < size (coins)) ;
//  post-condition: the elements at index positions i and j in coins have been swapped
    const Coin HELP = coins[i] ;
    coins[i] = coins[j] ;
    coins[j] = HELP ;
}

bool occurs (Coin x, vector<Coin>& coins, int c, int& position)
{// pre-condition:
    assert (0 <= c && c < size(coins)) ;
//  post-condition: if result is true, then position has a value such that coins[position] == x and does not exceed c;
//                  if result is false, then no such position exists, and position is not altered
    for (int i = 0 ; i <= c ; i++)
        if (coins[i] == x)
        {
            position = i ;
            return true ;
        }
    return false ;
}

bool check_selection (vector<Coin>& a, vector<Coin>& b, int c)
{// pre-condition:
    assert (0 <= c && c < size (b)) ;
//  post-condition: result is true only if every element of a occurs individually in b[0]...b[c];
//                  the order of elements in b[0]...b[c] has been changed, and the size of a might have been
//                  decreased
    if (size (a) == 0) { return true ; }     // the empty selection is always a selection of any collection
    else if (c == 0)   { return false ; }    // a non-empty selection can not be a selection of an empty collection
    int index_of_last_in_b ;
    int last_of_a = size(a) - 1 ;
    bool does_occur = occurs ( a[last_of_a], b, c, index_of_last_in_b ) ;
    if (!does_occur)   { return false ; }    // last element of a does not occur in b[0]...b[c]
    else
    {
        swap (b, index_of_last_in_b, c) ;    // swap the found element with b[c]
        a.pop_back () ;                      // get rid of the last element of a
        return check_selection (a, b, c-1) ; // and check any remaining elements in a
    }
}

bool is_selection (vector<Coin>& a, vector<Coin>& b, int c)
{// pre-condition:
    assert (0 <= c && c <= size(b)) ;
//  post-condition: result is true only if every element of a occurs individually in b[0]...b[c];
//                  the content of a and b are unchanged
    if (c == 0)
        return size(a) == 0 ;   // only an empty selection can be a selection of an empty selection
    else
    {
        vector<Coin> x = a ;    // use copy because check_selection alters a
        vector<Coin> y = b ;    // use copy because check_selection alters b
        return check_selection (x, y, c) ;
    }
}

int solutions1 ( vector<Coin>& money, int c, int target )
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money)) ;
//  post-condition:
//  result is the number of ways of matching target exactly with the coins in money[c] .. money[size(money)-1]
	if	    ( target == 0 )		    { return 1; }
	else if ( target < 0 )		    { return 0; }
	else if ( c >= size(money) )	{ return 0; }
	else {
		const int WITH_C    = solutions1 ( money, c+1, target-money[c] );
		const int WITHOUT_C = solutions1 ( money, c+1, target );
		return WITH_C + WITHOUT_C;
	}
}

int solutions2 ( vector<Coin>& attempt, vector<Coin>& money, int c, int target )
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money) && is_selection (attempt, money, between (0, maximum(0,size(money)-1), c))) ;
//  post-condition:
//  result is the number of ways to extend attempt with matching target exactly with the coins in money[c] .. money[size(money)-1]
//  and each such solution is printed on screen
	if	    ( target == 0 )		    { show (attempt) ; return 1; }
	else if ( target < 0 )	    	{ return 0;	}
	else if ( c >= size(money) )	{ return 0;	}
	else {
		attempt.push_back ( money[c] ) ;
		const int WITH_C    = solutions2 ( attempt, money, c+1, target - money[c] ) ;
		attempt.pop_back () ;
		const int WITHOUT_C = solutions2 ( attempt, money, c+1, target ) ;
		return WITH_C + WITHOUT_C ;
	}
}

int solutions3 ( vector<Coin>& attempt, vector<Coin>& money, int c, int target, int& no_of_fails )
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money) && is_selection (attempt, money, between (0, maximum(0,size(money)-1), c)) && no_of_fails >= 0) ;
//  post-condition:
//  result is the number of ways of extending attempt matching target exactly with the coins in money[c] .. money[size(money)-1]
//  and each solution is printed on screen;
//  no_of_fails is incremented with the number of failed attempts
	if	    ( target == 0 )		    { show (attempt) ; return 1; }
	else if ( target < 0 )		    { no_of_fails++;            return 0; }
	else if ( c >= size(money) )	{ no_of_fails++;            return 0; }
	else {
		attempt.push_back ( money[c] ) ;
		const int WITH_C    = solutions3 ( attempt, money, c+1, target - money[c], no_of_fails ) ;
		attempt.pop_back () ;
		const int WITHOUT_C = solutions3 ( attempt, money, c+1, target,            no_of_fails ) ;
		return WITH_C + WITHOUT_C ;
	}
}

int solutions4 ( vector<Coin>& attempt, vector<Coin>& money, int c, int target, int& no_of_fails, int& no_of_prunes )
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money) && is_selection (attempt, money, between (0, maximum(0,size(money)-1), c)) && no_of_fails >= 0 && no_of_prunes >= 0) ;
//  post-condition:
//  result is the number of ways of extending attempt matching target exactly with the coins in money[c] .. money[size(money)-1]
//  each such solution is printed on screen
//  no_of_fails is incremented with the number of failed attempts
	if	    ( target == 0 )		         { show (attempt) ;  return 1 ; }
	else if ( target <  0 )	    	     { no_of_fails++ ;            return 0 ; }
	else if ( c >= size(money) )	     { no_of_fails++ ;            return 0 ; }
	else if (sum (money,c) < target)     { no_of_prunes++ ;           return 0 ; }
	else if (minimum(money, c) > target) { no_of_prunes++ ;           return 0 ; }
	else {
		attempt.push_back ( money[c] ) ;
		const int WITH_C    = solutions4 ( attempt, money, c+1, target - money[c], no_of_fails, no_of_prunes ) ;
		attempt.pop_back () ;
		const int WITHOUT_C = solutions4 ( attempt, money, c+1, target,            no_of_fails, no_of_prunes ) ;
		return WITH_C + WITHOUT_C ;
	}
}

int solutions5 ( vector<Coin>& current, vector<Coin>& best, vector<Coin>& money, int c, int target)
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money) && is_selection (current, money, between (0, maximum(0,size(money)-1), c)) && is_selection (best, money, maximum(0,size(money)-1))) ;
//  post-condition:
//  result is the number of ways of extending current matching target exactly with the coins in money[c] .. money[size(money)-1]
//  best contains the best solution (which might have a sum of values that is less than target in case result is 0)
	if ( target == 0 )           { best = current ; return 1 ; }
	else if ( target < 0 )       { return 0 ; }
	else if ( c >= size(money) ) { improve (current, best) ;
                                   return 0 ; }
	else {
		current.push_back ( money[c] ) ;
		const int WITH_C    = solutions5 ( current, best, money, c+1, target - money[c] ) ;
		current.pop_back () ;
		const int WITHOUT_C = solutions5 ( current, best, money, c+1, target ) ;
		return WITH_C + WITHOUT_C ;
	}
}

int solutions6 ( vector<Coin>& current, vector<Coin>& best, vector<Coin>& money, int c, int target, int& no_of_prunes)
{// pre-condition:
    assert (real_money(money) && 0 <= c && c <= size(money) && is_selection (current, money, between (0, maximum(0,size(money)-1), c)) && is_selection (best, money, maximum(0,size(money)-1)) && no_of_prunes >= 0) ;
//  post-condition:
//  result is the number of ways of extending current matching target exactly with the coins in money[c] .. money[size(money)-1]
//  best contains the best solution (which might have a sum of values that is less than target in case result is 0)
	if ( target == 0 )           { best = current ; return 1 ; }
	else if ( target < 0 )       { return 0 ; }
	else if ( c >= size(money) ) { improve (current, best) ; return 0 ; }
	else if (sum (current) + sum (money,c) <= sum (best))
                                 { no_of_prunes++ ; return 0 ; }
	else {
		current.push_back ( money[c] ) ;
		const int WITH_C    = solutions6 ( current, best, money, c+1, target - money[c], no_of_prunes ) ;
		current.pop_back () ;
		const int WITHOUT_C = solutions6 ( current, best, money, c+1, target, no_of_prunes ) ;
		return WITH_C + WITHOUT_C ;
	}
}



void show_money (vector<Coin>& coins)
{// pre-condition:
    assert (true) ;
//  post-condition: the values in coins have been displayed
	for (int i = 0 ; i < size(coins); i++)
		cout << coins[i] << " " ;
}

int enter_non_negative_number (string prompt)
{// pre-condition:
    assert (true) ;
//  post-condition: result is first value entered by user that is not negative
	int n = -1 ;
	do {
        cout << prompt ;
        cin  >> n ;
	}
	while (n < 0) ;
    return n ;
}

enum Choice {CountOnly=1,CountAndShow,CountAndShowFails,CountAndShowPrunes,BestSolution,PruneBestSolution,Huh};

Choice enter_command ()
{// pre-condition:
    assert (true) ;
//  post-condition: the user is informed of the proper choices, result is the choice entered by the user
    cout << "Choose one of the following commands:"               << endl ;
    cout << "1. Count all possible combinations"                  << endl ;
    cout << "2. As 1. and show all possible combinations"         << endl ;
    cout << "3. As 2. and count all failed attempts"              << endl ;
    cout << "4. As 3. and count all prematurely aborted attempts" << endl ;
    cout << "5. Keep track of best solution so far"               << endl ;
    cout << "6. Use best solution so far to stop earlier"         << endl ;
    int choice ;
    cin  >> choice ;
    if (choice >= CountOnly && choice < Huh)
        return static_cast<Choice>(choice) ;
    else
        return Huh ;
}

void show_percentage (int a, int no_of_coins)
{// pre-condition:
    assert (a >= 0 && a <= pow (2,no_of_coins)) ;
//  post-condition: the percentage a/2^no_of_coins is shown on cout as a standard message
    cout << " (this is " << percentage (a, pow(2,no_of_coins)) << "% of all combinations)" ;
}

void count_solutions (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the number of all possible ways to obtain value with coins has been displayed
    cout << endl << "The number of solutions to make " << value << " is: " << endl ;
    int no = solutions1 (coins, 0, value) ;
    cout << no ;
    show_percentage (no, size(coins)) ;
    cout << endl ;
}

void count_and_show_solutions (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the number of all possible ways to obtain value with coins is returned,
//  and all solutions have been displayed
    vector<Coin> solution ;
    cout << endl << "The solutions to make " << value << " are: " << endl ;
    int no = solutions2 (solution, coins, 0, value) ;
    cout << endl << "These are " << no << " solutions" ;
    show_percentage (no, size(coins)) ;
    cout << endl ;
}

void count_and_show_fails (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the number of all possible ways to obtain value with coins is returned,
//  and all solutions have been displayed, as well as the number of failed attempts
    int no_of_fails = 0 ;
    vector<Coin> solution ;
    cout << endl << "The solutions to make " << value << " are: " << endl ;
    int no = solutions3 (solution, coins, 0, value, no_of_fails) ;
    cout << endl << "These are " << no << " solutions " ;
    show_percentage (no, size(coins)) ;
    cout << endl << no_of_fails << " attempts have failed" ;
    show_percentage (no_of_fails, size(coins)) ;
    cout << endl ;
}

void count_and_show_prunes (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the number of all possible ways to obtain value with coins is returned,
//  and all solutions have been displayed, as well as the number of failed attempts and
//  number of pruned attempts
    int no_of_fails  = 0 ;
    int no_of_prunes = 0 ;
    vector<Coin> solution ;
    cout << endl << "The solutions to make " << value << " are: " << endl ;
    int no = solutions4 (solution, coins, 0, value, no_of_fails, no_of_prunes) ;
    cout << endl << "These are " << no << " solutions" ;
    show_percentage (no, size(coins)) ;
    cout << endl << no_of_fails << " attempts have failed" ;
    show_percentage (no_of_fails, size(coins)) ;
    cout << endl << no_of_prunes << " attempts have been pruned." ;
    show_percentage (no_of_prunes, size(coins)) ;
    cout << endl ;
}

void find_best_solution (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the selection of coins that is closest to value (but not exceeding)
//  has been shown, as well as its value
    vector<Coin> current ;
    vector<Coin> best ;
    cout << endl << "The number of solutions to make " << value << " is: " << endl ;
    cout << solutions5 (current, best, coins, 0, value) ;
    cout << endl << "One best found solution is: " << endl ;
    show (best) ;
    cout << endl << "It has value: " << sum(best) << endl ;
    cout << endl ;
}

void find_best_solution_by_pruning (vector<Coin>& coins, int value)
{// pre-condition:
    assert (real_money(coins)) ;
//  post-condition: the selection of coins that is closest to value (but not exceeding)
//  has been shown, as well as its value
    vector<Coin> current ;
    vector<Coin> best ;
    int no_of_prunes = 0 ;
    cout << endl << "The number of solutions to make " << value << " is: " << endl ;
    cout << solutions6 (current, best, coins, 0, value, no_of_prunes) ;
    cout << endl << "One best found solution is: " << endl ;
    show (best) ;
    cout << endl << "It has value: " << sum(best) << endl ;
    cout << "Number of early failing attempts detected is: " << no_of_prunes ;
    show_percentage (no_of_prunes, size(coins)) ;
    cout << endl ;
}

//////////



struct Present
//post-condition : make structure have two element price and product
{
    int Price;

    string Product;
};
string Boy[50];
vector<Present> Giftstore;



istream& operator>> (istream& in, Present& present)
{// pre-condition:
    assert (true) ;
/*  post-condition:
    first, put  price of it into present struct's price
    after ignore space, put the name of it into present struct's product
*/
    in >> present.Price ;
    in.ignore();
    getline(in, present.Product);       // artist
    return in ;
}


ostream& operator<< (ostream& out, const Present Present)
{// pre-condition:
    assert (true) ;
/*  post-condition:
    out has emitted all members of present, including the last separating newline.
*/
    out << Present.Price   << endl;
    out << Present.Product << endl;
    return out ;
}




int read_gifts (ifstream& infile, vector<Present> &presents)
{// pre-condition:
    assert (infile.is_open ()) ;
/*  post-condition:
    All present in infile have been read and stored in the same order in presents.
    The result is the number of presents that have been read.
*/
    int no_of_read_present = 0 ;
    do {
        Present pp ;
        infile >> pp ;
        if (infile)
            presents.push_back(pp) ;
    }
    while (infile);
    return presents.size();
}

int read_file (string filename)
{// pre-condition:
    assert (Giftstore.size() == 0) ;
/*  post-condition:
    If the result is -1, then no file could be opened, and songs is unchanged.
    Otherwise, the result is zero or positive, and songs contains all the found presents in the
    file that corresponds with filename.
*/
    ifstream giftDBS (filename.c_str());
    if (!giftDBS)
    {
        cout << "Could not open '" << filename << "'." << endl;
        return -1;
    }
    cout << "Reading '" << filename << "'." << endl;
	const int NO_OF_GIFTS = read_gifts(giftDBS, Giftstore);
	giftDBS.close();
	cout << " Read " << NO_OF_GIFTS << " tracks." << endl;
	return NO_OF_GIFTS;
}

void show_all_tracks (vector<Present> &Giftstore)
{
    // pre-condition:
    assert (true) ;
/*  post-condition:
    Giftstore[0] ... Giftstore[Giftstore.size()-1] have been displayed to cout.
*/
    for(int i = 0; i<Giftstore.size(); i++)
        cout << Giftstore[i];
}

int read_word (ifstream& infile, string word [])
{
    //pre_conditions:
    assert(infile.is_open());
    //post_conditions:
    //result is true only if word has been filled with
    //a next word from infile
    int i = 0;
    while(infile) {
        getline(infile, word[i]);
        i++;
    }
    return i;
}

bool match (Present giftstore, string Boy[], int j)
{
    //pre_codition :
    assert(j>=0);
    /*post_condition :
    if giftstore's product element is matched with Boy[j], return true
    */
    if (giftstore.Product == Boy[j])
        return true;

    else
        return false;
}

int price_make (Present giftstore)
{
    //pre_codition :
    assert(true);
    return giftstore.Price;
}

int match_Price_product (vector<Present> &Giftstore, string Boy[], int i)
{
    //pre_codition :
    assert(i>=0);
    /*post_condition :
    check all of Giftstore's element if there is matched one, return the price of the product
    if not, return -1
    */

        for(int j = 0 ; j <Giftstore.size(); j++)
    {
        if (match(Giftstore[j],Boy,i))
            return price_make(Giftstore[j]);
    }
    return -1;
}




int main()
{
    char filename[FILENAME_MAX];
    read_file("giftstore.txt");
    //show_all_tracks(Giftstore);
    cout<<"Enter the file name"<<endl;
    cin.getline(filename,FILENAME_MAX);
    ifstream myfile(filename);
    int B_size = read_word(myfile,Boy);

    vector<int> boy_pp;
    int boy_p[B_size];
    for (int i =1; i< B_size-1;i++)
        // if boy_p[i] is not -1, make boy_pp vector saving the  price of child's product
        {boy_p[i] = match_Price_product(Giftstore, Boy,i);
        //cout<<boy_p[i]<<endl;
        if(boy_p[i]!=-1)
        boy_pp.push_back(boy_p[i]);
        }
    typedef int coin;




	vector<Coin> coins ;
    coins = boy_pp;
	show_money (coins) ;

    stringstream geek(Boy[0]);
    int value =0;
    geek >> value;



    find_best_solution (coins, value) ;



    return 0 ;

}
