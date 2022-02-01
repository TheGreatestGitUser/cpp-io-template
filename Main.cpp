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
#include <cfloat>
#include <numeric>
using namespace std;

#if defined(_WINDOWS) // On Windows GCC, use the slow thread safe version
inline int fread_unlocked() {
    return fread();
}
inline int fwrite_unlocked() {
    return fwrite();
}
#elif defined  (_MSC_VER)// On Visual Studio
inline int fread_unlocked(){
    return _fread_nolock(); // use Microsoft Thread unsafe version
}
inline int fwrite_unlocked() {
    return _fwrite_nolock();
}
#endif

//https://tinodidriksen.com/2010/02/cpp-convert-string-to-int-speed/ has some very interesting findings in C++

//https://stackoverflow.com/questions/3203452/how-to-read-entire-stream-into-a-stdstring
//^this link can be used if you want to read the entire stream into a string.

//https://stackoverflow.com/questions/1924530/mixing-cout-and-printf-for-faster-output
// ^ this is the original StackOverflow answer, so the other links are not needed

//https://softwareengineering.stackexchange.com/questions/386269/why-do-you-want-to-avoid-flushing-stdout
//https://www.generacodice.com/en/articolo/399513/mixing-cout-and-printf-for-faster-output
// ^ this link doesn't work though
//https://stackify.dev/793050-mixing-cout-and-printf-for-faster-output


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

// Template is mostly from https://usaco.guide/general/fast-io?lang=cpp
const int BUF_SZ = 1 << 15;
inline namespace Input {
    char buf[BUF_SZ];
    int pos;
    int len;
    char next_char() {
    	if (pos == len) {
    		pos = 0;
    		len = int(fread_unlocked(buf, 1, BUF_SZ, stdin));
    		if (!len) {
    			return EOF;
    		}
    	}
    	return buf[pos++];
    }
    
    long long read_int() {
    	long long x;
    	register char ch;
    	int sgn = 1;
    	while (!isdigit(ch = next_char())) {
    		if (ch == '-') {
    			sgn *= -1;
    		}
    	}
    	x = ch - '0';
    	while (isdigit(ch = next_char())) {
    		x = (x * 10) + (ch - '0');
    	}
    	return x * sgn;
    }
    
    /*
    int fast_atoi( const char * str ) {
        int val = 0;
        while( *str ) {
            val = val*10 + (*str++ - '0');
        }
        return val;
    }
    */
    
    // lots of the code used in the read_double() function
    // was taken from here: https://tinodidriksen.com/uploads/code/cpp/speed-string-to-double.cpp
    long double read_double() {
    	long double x;
    	register char ch;
    	int sgn = 1;
    	while (!isdigit(ch = next_char())) {
    		if (ch == '-') {
    			sgn *= -1;
    		}
    	}
    	x = ch - '0';
    	while (isdigit(ch = next_char())) {
    		x = (x * 10) + (ch - '0');
    	}
    	if (ch == '.'){
    	    /*
    	    long double divisor = 1;
    		while (isdigit(ch = next_char())) {
    			x += (ch - '0') / (divisor *= 10);
    		}
    		*/
    		
    		// from https://tinodidriksen.com/uploads/code/cpp/speed-string-to-double.cpp
            long double f = 0.0;
            int n = 0;
            while (isdigit(ch = next_char())) {
                f = (f * 10.0) + (ch - '0');
                ++n;
            }
            x += f / pow(10.0, n);
    	}
    	return x * sgn;
    }
    
    // https://stackoverflow.com/questions/18892281/most-optimized-way-of-concatenation-in-strings/18892355
    // the above link was used to find the quickest way of adding characters to a string.
    
    // https://stackoverflow.com/questions/6283632/how-to-know-if-the-next-character-is-eof-in-c
    // the above link was used to find when the end-of-file is for standard input.
    string read(char delim) {
		register char ch = next_char();
    	while (ch == delim) ch = next_char();
    	string out;
    	while (ch != delim){
    		out += ch;
    		if ((ch = next_char()) == EOF) break;
    	}
    	return out; 
    }
    
    // https://stackoverflow.com/questions/4754011/c-string-to-double-conversion
    // the above link was used to find how to convert a string to a long double
    long double read_double_exact() {
    	return stold(read(' '));
    }
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
} // namespace Input

inline namespace Output {
    char buf[BUF_SZ];
    int pos;
    
    void flush_out() {
    	fwrite_unlocked(buf, 1, pos, stdout);
    	pos = 0;
    }
    
    void write_char(char c) {
    	if (pos == BUF_SZ) flush_out();
    	buf[pos++] = c;
    }
    
    
    void write_int(long long x) {
    	static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
    	int len = 0;
    	for (; x >= 10; x /= 10) {
    		num_buf[len++] = (char)('0' + (x % 10));
    	}
    	write_char((char)('0' + x));
    	while (len) {
    		write_char(num_buf[--len]);
    	}
    	write_char('\n');
    }
    
    // The code below for the function write_int_2() came from here:
    // https://stackoverflow.com/questions/18006748/using-putchar-unlocked-for-fast-output
    // However I am not using it because it is slower than the write_int() function above.
    /*
    void write_int_2(long long n) {
        if (n < 0) { write_char('-'); n *= -1; }
        long long N = n, rev, count = 0;
        rev = N;
        if (N == 0) { write_char('0'); write_char('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { write_char(rev % 10 + '0'); rev /= 10;}
        while (count--) write_char('0');
        write_char('\n');
    }
    */
    
    void write(string s) {
        int len = s.length();
    	for (int i =0; i < len; ++i) {
    		write_char(s[i]);
    	}
    	write_char('\n');
    }
    
    /*
    This code isn't needed since the current write_double() function
    works similarily as it prints out the decimal places using write().
    
    // https://stackoverflow.com/questions/332111/how-do-i-convert-a-double-into-a-string-in-c
    // the above link was used to figure out how to convert a double to a string.
    void write_double_exact(long double x) {
        write(to_string(x));
    }
    */
    
    // the code for the round() function was based around the code in this link:
    // https://stackoverflow.com/questions/12349323/setting-the-precision-of-a-double-without-using-stream-ios-baseprecision

    // this link was used to figure out how to throw exceptions:
    // https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
    long double round(long double num, long long decimals = 1) {
        if (decimals < 1) throw invalid_argument("no decimal digits less than 1");
        return ((long long) ((num * pow(10.0, decimals)) + 0.5)) / pow(10.0, decimals);
    }
    
    // the code for the dmod() function was taken from here:
    // https://stackoverflow.com/questions/9138790/cant-use-modulus-on-doubles
    // This might not be needed thought because of fmod()
    long double dmod(long double x, long double y) {
        return x - int(x/y) * y;
    }
    
    void write_double(long double x) {
        static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
        long double decimals = dmod(x, 1.0);
        long long beforeDecimalPoint = (long long) double(x - decimals);
    	int len = 0;
    	for (; beforeDecimalPoint >= 10; beforeDecimalPoint /= 10) {
    		num_buf[len++] = (char)('0' + (beforeDecimalPoint % 10));
    	}
    	write_char((char)('0' + beforeDecimalPoint));
    	while (len) {
    		write_char(num_buf[--len]);
    	}
        string actualDecimals = to_string(decimals);
        
        // These two lines of code were taken from here:
        // https://stackoverflow.com/questions/13686482/c11-stdto-stringdouble-no-trailing-zeros
        actualDecimals.erase(actualDecimals.find_last_not_of('0') + 1, string::npos);
        actualDecimals.erase(actualDecimals.find_last_not_of('.') + 1, string::npos);
        write(actualDecimals.substr(1));
    }
    
    /*
    The following code is for quickly printing out double values.
    However, I cannot figure out how to write the decimal values
    directly to the num_buf array, which might cost me some time.
    Furthermore, the accuracy of the output is off, such as
    how trying to print -100.07 will end up printing:
    -100.069999999999999999722444243843710864894092082977294921875
    As a result of this, the current write_double() function is
    good enough.
    
    void write_double_2(long double x) {
    	static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
    	long double decimals = dmod(x, 1.0);
    	long long beforeDecimalPoint = (long long) double(x - decimals);
    	int len = 0;
    	for (; beforeDecimalPoint >= 10; beforeDecimalPoint /= 10) {
    		num_buf[len++] = (char)('0' + (beforeDecimalPoint % 10));
    	}
    	//cout << beforeDecimalPoint << '\n';
        write_char((char)('0' + beforeDecimalPoint));
    	while (len) {
    		write_char(num_buf[--len]);
    	}
    	if (decimals > 0.0) {
    	    write_char('.');
    	    while (decimals > 0.0){
    	        decimals *= 10;
    	        write_char((char)('0' + int(decimals)));
    	        decimals = dmod(decimals, 1.0);
    	        //cout << decimals << '\n';
    	    }
        }
    	write_char('\n');
    }
    */
    
    /*
    Might update the code below so that I can
    quickly (is it quicker at this point?) print out
    doubles. I will also have to add comments because
    the code is very long and unreadable.
    
    void write_double(long double x) {
    	static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
    	double start = x;
    	if (start == 0) start = 1;
    	if (x != 0.0 && x - dmod(x, 1.0) == 0.0){
    	    write_char('0');
    	    write_char('.');
    	}
    	int n = 0;
    	while (dmod(x, 1.0) != 0.0) {
    	    x *= 10;
	        n++;
	    }
    	int len = 0;
    	double temp = floor(log(start));
    	//cout << start << '\n';
    	if (temp < 0) temp--;
    	else temp = 1;
    	for (; x >= pow(10, temp); x /= 10) {
    		num_buf[len++] = (char)('0' + dmod(x, 10.0));
    	}
    	write_char((char)('0' + x));
    	while (len) {
    	    if (len == n) write_char('.');
    	    write_char(num_buf[--len]);
    	}
    	if (n == 0) {
    	    write_char('.');
    	    write_char('0');
    	}
    	write_char('\n');
    }
    */
    /*
    May update this code later to provide straight output for doubles.
    However, for the time being, converting it to a string and printing
    that doesn't seem so bad.
    
    void write_double(long double x) {
    	static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
    	int len = 0;
    	for (; x >= 10; x /= 10) {
    		num_buf[len++] = (char)('0' + dmod(x, 10.0));
    	}
    	write_char((char)('0' + x));
    	x = dmod(x, 1.0);
    	//cout << x << '\n';
    	
    	if (x > 0) {
    	    num_buf[len++] = '.';
    	    int n = 0;
    	    while (dmod(x, 1.0) < 0.0) {
    	        x *= 10;
    	        n++;
    	        
    	    }
    	}
    	while (len) {
    		write_char(num_buf[--len]);
    	}
    	write_char('\n');
    	    
	}
    */
    
    // auto-flush output when program exits
    void init_output() { assert(atexit(flush_out) == 0); }
} // namespace Output


int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

	init_output();
	
	long double test = read_double();
	write_double(test);
}