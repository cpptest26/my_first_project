#include <iostream>
#include <bitset>
using namespace std;

//1
unsigned char option_viewed     = 0x01;
unsigned char option_edited     = 0x02;
unsigned char option_liked      = 0x04;
unsigned char option_shared     = 0x08;
unsigned char option_deleted    = 0x80;
//2
unsigned char option4 = 1 << 1;
unsigned char option5 = 1 << 3;


unsigned char my_article_flags = 0;
unsigned char myflags = 0;


int main() {
///////1
my_article_flags |= option_viewed;
cout << "View article" << bitset<16>(my_article_flags) << endl;

my_article_flags |= option_liked;
cout << "Click article_like" << bitset<16>(my_article_flags) << endl;

my_article_flags ^= option_liked;
cout << "reclick article_like" << bitset<16>(my_article_flags) << endl;

if (my_article_flags & option_viewed)
my_article_flags |= option_deleted ;

cout << "delete article" << bitset<16>(my_article_flags) << endl;


////////2

myflags = ~(option4 | option5 );
cout << "~(option4 | option5 ) = " << bitset<8>(myflags) << endl;

myflags = ~option4 &~option5 ;
cout << "~option4 &~option = " << bitset<8>(myflags) << endl;






return 0;
}