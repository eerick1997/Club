/**
    This problem is also in strings section in "cracking the code interview"
    We have a lot of solutions but it is a little bit difficult if your interviewer says:
    "Solve it wthout using an extra data structure"
    So we can use something similar to an array, maybe we can use a bitmask, we know that we have
    32 bits in a normal integer, and the alphabet has 26 characters, let's suposse that each bit represents
    a character of the alphabet, so we need to convert each character to a number, and we can do it using
    the ASCII code, if we use this we can shift a integer "c" times and check if the bit is on or off, if
    the bit is off that means that is the first time that we find the character, otherwise that means that
    we already found the same character before.
**/
#include<bits/stdc++.h>

using namespace std;

bool unique_characters( string &input ) {
    int32_t count_characters = 0;
    for( char c : input ) {
        int32_t  int_c = c - 'a';
        if( (count_characters >> int_c) > 0 )
            return false;
        count_characters |= ( 1 << int_c );
    }
    return true;
}
int main() {
    string input;
    cin >> input;
    cout << (unique_characters( input ) ? "true" : "false" ) << endl;
    return 0;
}