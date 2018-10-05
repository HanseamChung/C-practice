//s1025078 Han Seob Yoo
//s1025079 Han Saem Chung


#include <iostream>
#include <fstream>          // for file I/O
#include <cassert>          // for assertion checking

using namespace std;

enum Action {Encrypt, Decrypt} ;

int seed = 0 ;
void initialise_pseudo_random (int r)
{
//  pre-condition:
    assert (r > 0 && r <= 65536) ;
    /*  post-condition:
        seed has value r.
    */
    seed = r ;
}

int next_pseudo_random_number ()
{
//  pre-condition:
    assert (seed > 0 && seed <= 65536) ;
    /*  post-condition:
        result value > 0 and result value <= 65536 and result value != seed at entry of function
    */
    const int seed75 = seed * 75 ;
    int next = (seed75 & 65535) - (seed75 >> 16) ;
    if (next < 0)
        next += 65537 ;
    seed = next ;
    return next ;
}

char rotate_char (char a, int r, Action e)
{
//  Pre-condition:
    assert (a > 0 && a <= 128);
//  Post-condition:
    if(e==Decrypt)
    {
        if(a>=32)
        {
            return (a-32 - (r % (128-32)) + (128-32)) % (128-32)+32;
        }
        else
        {
            return a;
        }
    }
    else
    {
        if(a>=32)
            return (a-32 + (r % (128-32)) + (128-32)) % (128-32)+32;
        else
            return a;
    }
}
//The way to get rotate_char
//If you want to decrypt and a is more than 32, use above formula with subtraction.
//Otherwise, use above formula with addition.


void test_rotate_char ()
{
    char a;
    int r;
//  Pre-condition:
    assert (r > 0 && r <= 65536) ;
//  Post-condition:
    cout << "enter character a = ";
    cin >> a;
    cout << "enter integer r = ";
    cin >> r;
    while(r>0)
    {
        if(r>0)
        {
            cout << "character = " << a << endl;
            cout << "ASCII code = " << int(a) << endl;
            cout << "ASCII code of rotate_char_encrypt = " << rotate_char(a,r,Encrypt) << endl;
            cout << "ASCII code of rotate_char_decrypt = " << rotate_char(rotate_char(a,r,Encrypt),r,Decrypt) << endl;
            return test_rotate_char();
        }
        else
        {
            cout << "terminate" << endl;
        }
    }
}
//This function is for test the rotate_char.
//The input is a and r. The output is chr a, ASCII code a, the encrypt and decrypt of a.
//iterate until r is more than 0, otherwise terminate.

bool open_input_and_output_file (ifstream& infile, ofstream& outfile)
{
//  Pre-condition:
    assert ( true ) ;
//  Post-condition:

    if(infile == outfile)
        return false;
    else
    {

        if(infile.is_open()&&outfile.is_open())
            return true;
        else
            return false;

    }
}
//determine whether input file is equal to output file.
//If input file and output file is opened at the same time, return true result.

Action get_user_action ()
{
    // Pre-condition:
    assert ( true ) ;
    /*  Post-condition:
        result is the Action that the user has indicated that the program should encrypt / decrypt
    */
    cout << "Do you want to encrypt the file? (y/n): " ;
    string answer ;
    cin  >> answer ;
    if (answer == "y")
        return Encrypt;
    else
        return Decrypt;
}

int initial_encryption_value ()
{
    // Pre-conditie:
    assert (true) ;
    /*  Post-condition:
        result is a value between 0 and 65355 (both inclusive)
    */
    int initial_value = -1 ;
    while (initial_value < 0 || initial_value > 65535)
    {
        cout << "Please enter the initial coding value (greater or equal to 0 and less than 65536)" << endl ;
        cin  >> initial_value ;
    }
    return initial_value ;
}

void use_OTP (ifstream& infile, ofstream& outfile, Action action, int initial_value)
{
//  Pre-condition:
    assert (infile.is_open()&&outfile.is_open());
//  Post-condition:
    initialise_pseudo_random(initial_value);

    int no_of_chars=0 ;
    char c,c2;
    infile.get (c);
    while (infile)
    {
        cout << c2 ;
        c2 = rotate_char(c,next_pseudo_random_number(),action);
        outfile.put(c2);

        infile.get(c);
    }

}
//get initial value and initialise_pseudo_random function make seed
//next_pseudo_random_number get above seed and save the rotate_char to c2
//and c2 is saved in outfile.
int main()
{
    //test_rotate_char();

    const Action ACTION = get_user_action() ;
    ifstream input_file  ;
    ofstream output_file ;
    string input;
    string output;
    cout << "type the name of infile"<<endl;
    cin >> input;
    input_file.open(input.c_str());
    cout << "type the name of outfile"<<endl;
    cin >> output;
    output_file.open(output.c_str());

    //enter the name of the input file and output file
    if (!open_input_and_output_file (input_file,output_file))
    {
        cout << "Program aborted." << endl ;
        return -1 ;
    }
    const int INITIAL_VALUE = initial_encryption_value () ;
    use_OTP (input_file,output_file,ACTION,INITIAL_VALUE);
    input_file.clear () ;
    output_file.clear () ;
    input_file.close () ;
    output_file.close () ;

    if (!input_file || !output_file)
    {
        cout << "Not all files were closed succesfully. The output might be incorrect." << endl ;
        return -1 ;
    }
    return 0 ;
}
