//https://www.ibm.com/docs/en/xl-c-and-cpp-aix/13.1.0?topic=reference-standard-library-header-files
// has a list of useful imports

// Random links that will be used in the future for upgrades
//https://codeforces.com/blog/entry/8080
//https://codeforces.com/blog/entry/5217
//https://stackoverflow.com/questions/44108745/how-to-optimize-printing-out-the-difference-between-the-greater-and-the-lesser-o
//https://stackoverflow.com/questions/705303/faster-i-o-in-c/705378
//https://stackoverflow.com/questions/32672689/why-this-method-using-putchar-unlocked-is-slower-than-printf-and-cout-to-print-s
//https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp10_io.html
//https://www.geeksforgeeks.org/c-stream-classes-structure/
//https://www.cplusplus.com/reference/istream/istream/
//https://www.cplusplus.com/reference/ostream/ostream/

#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <float.h>
#include <numeric>
using namespace std;
//#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0) // This one isn't needed
#define nextInteger(x) do{ bool neg = false; register int c; x = 0; while (c < 33) c = getchar_unlocked(); if (c=='-') { neg = true; c = getchar_unlocked(); } for (; (c>47 && c<58); c=getchar_unlocked()) { x = x * 10 + c - 48; } if (neg){ x *= -1; } } while (0) // This one is used for integers
//#define nextInteger(x) do{ bool neg = false; register int c; x = 0; c = get(); if (c=='-') { neg = true; c = get(); } for (; (c>47 && c<58); c=get()) { x = x * 10 + c - 48; } if (neg){ x *= -1; } } while (0) // This one is used for integers
#define nextDecimal(x) do{ double div = 1; bool neg = false; register int c = getchar_unlocked(); x = 0; while (c < 33) c = getchar_unlocked(); if (c=='-') { neg = true; c = getchar_unlocked(); } for (; (c>47 && c<58); c=getchar_unlocked()) { x = x * 10 + c - 48; } if (c=='.') { c=getchar_unlocked(); for (; (c>47 && c<58); c=getchar_unlocked()) { x += (c - '0') / (div *= 10); } } if (neg){ x *= -1; } } while (0) // This one is used for decimals, but doesn't work, so comment out later.
//#define nextDecimal(x) do{ double div = 1; bool neg = false; register int c = get(); x = 0; while (c < 33) c = get(); if (c=='-') { neg = true; c = get(); } for (; (c>47 && c<58); c=get()) { x = x * 10 + c - 48; } if (c=='.')
#define next(x) do{ register char c = getchar_unlocked(); while (c < 33) c = getchar_unlocked(); os.str(""); while (c > 32){ os << c; c = getchar_unlocked(); } x = os.str(); } while (0) // This one is used for the next token in stdin
//#define next(x) cin >> x;
#define nextLine(x) do{ register char c = getchar_unlocked(); while (c < 11) c = getchar_unlocked(); os.str(""); while (c > 10){ os << c; c = getchar_unlocked(); } x = os.str(); } while (0) // This one is used for the next line in stdin
//#define nextLine(x) getline(cin, x);
//#define nextDecimal(x) do{ string s; next(s); x = stold(s); } while (0)
//https://stackoverflow.com/questions/3203452/how-to-read-entire-stream-into-a-stdstring
//^this link can be used if you want to read the entire stream into a string.

char _;
//https://stackoverflow.com/questions/1637332/static-const-vs-define
#define INF 0x3f3f3f3f
#define NINF -INF
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define m(x, y) (x + y) / 2
#define pll(n) printf("%lld ",(n))
#define plln(n) printf("%lld\n",(n))
#define pc(x) putchar_unlocked(x);
typedef pair<int, int> pi;
typedef long long ll;
typedef pair<ll, ll> pll;
// cannot use scanf with this template

#if defined(_WINDOWS) // On Windows GCC, use the slow thread safe version
inline int getchar_unlocked() {
    return getchar();
}
#elif defined  (_MSC_VER)// On   Visual Studio
inline int getchar_unlocked(){
    return _getchar_nolock(); // use Microsoft Thread unsafe version
}
#endif

// Add support for files and tokenizing individual lines of text

ostringstream os;

vector<string> st(string s, string delimiters = " "){
    vector <string> tokens;
    size_t current;
    size_t next = -1;
    do {
        current = next + 1;
        next = s.find_first_of(delimiters, current);
        tokens.push_back(s.substr(current, next - current));
    }
    while (next != string::npos);
    return tokens;
      
}


/*
long double fastscan(long double &x) {
    do{
        string s;
        next(s);
        x = stold(s);
        return x;
    } while (0);
}
*/

/*
string fastscan(string &x) {
    do{
        register char c = getchar();
        while (c < 11){
            c = getchar();
            
        }
        os.str("");
        while (c > 10){
            os << c;
            c = getchar();
        }
        x = os.str();
        return x;
    } while (0);
}
*/

/*
string fastscan(string &x) {
    do{
        register char c = getchar();
        while (c < 33){
            c = getchar();
        }
        os.str("");
        while (c > 32){
            os << c;
            c = getchar();
        }
        x = os.str();
        return x;   
    } while (0);
}
*/


/*
double fastscan(double &x) {
    do{
        double div = 1;
        bool neg = false;
        register int c = getchar();
        
        x = 0;
        while (c < 33) c = getchar();
        if (c=='-') {
            neg = true;
            c = getchar();
        }
        
        for (; (c>47 && c<58); c=getchar()) {
            x = x * 10 + c - 48;
        }
        
        if (c=='.') {
            c=getchar();
            for (; (c>47 && c<58); c=getchar()) {
                x += (c - '0') / (div *= 10);
            }
        }
        
        if (neg){
            x *= -1;
        }
        return x;
    } while (0);
}
*/

/*
long long fastscan(long long &x) {
   do{
       bool neg = false;
       register int c = getchar();
       
       x = 0;
       while (c < 33) c = getchar();
       if (c=='-') {
           neg = true;
           c = getchar();
       }
       
       for (; (c>47 && c<58); c=getchar()) {
           x = x * 10 + c - 48;
       }
       
       if (neg){
           x *= -1;
       }
       return x;
   } while (0);
}
*/

//https://stackoverflow.com/questions/1924530/mixing-cout-and-printf-for-faster-output
// ^ this is the original StackOverflow answer, so the other links are not needed

//https://softwareengineering.stackexchange.com/questions/386269/why-do-you-want-to-avoid-flushing-stdout
//https://www.generacodice.com/en/articolo/399513/mixing-cout-and-printf-for-faster-output
// ^ this link doesn't work though
//https://stackify.dev/793050-mixing-cout-and-printf-for-faster-output

void write (string s){
    puts(s.c_str());
}

int main() {
    // These lines might not be needed, but need to test first
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    
    int n;
    nextInteger(n);
    write(to_string(n));
    /*
    for (int i =0; i < n; ++i){
        int a, b;
        nextInteger(a);
        nextInteger(b);
        write(to_string(-abs(a-b)));
    }
    */
    
    /*
    int x;
    nextInteger(x);
    //cout<<setprecision(7)<<fixed;
    writeInt(x);
    */
}