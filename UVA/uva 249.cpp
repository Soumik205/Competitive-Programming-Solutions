//#Name: Anonta Haque #Problm:

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long L;                 //"%ld"
typedef long long LL;           //"%lld"
typedef long double LD;         //"%f"
typedef unsigned int UI;        // "%u"
typedef unsigned long  UL;      //"%lu"
typedef unsigned long long ULL; //"%llu"

short COUNT_;
#define sf scanf
#define pf printf
#define NL pf("\n");
#define put(x_) pf("%d", x_)
#define read(x_) sf("%d", &x_)
#define readf(x_) sf("%f", &x_)
#define read2(x_,y_) sf("%d%d",&x_,&y_)
#define arySZ(x_) sizeof(x_)/sizeof(x_[0])  //(array must be in scope)
#define ALPHAB "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHAb "abcdefghijklmnopqrstuvwxyz"
#define SS pf(">_<LOOOOOK@MEEEEEEEEEEEEEEE<<( %d )>>\n",++COUNT_);
#define DD(x_) cout<<">>>>( "<<++COUNT_<<" ) "<<#x_<<": "<<x_<<endl;
#define EXT(st_) cout<<"\n>>>Exicution Time: "<<(double)(clock()-st_)/CLOCKS_PER_SEC<<endl;

//functions templates
template <typename T> T mnary(T*st,T*nd){T mn= *st;while(++st<nd)if(mn>*st)mn= *st;return mn;}
template <typename T> T mxary(T*st,T*nd){T mx= *st;while(++st<nd)if(mx<*st)mx= *st;return mx;}
template <typename T>void pary(T* st, T* nd){/*pf("%d", *st++);*/while(st<nd)printf("%d ", *st++);NL}
template <typename T>void rary(T* st, T* nd){while(st<nd)swap(*st++,*--nd);}
template <typename T>inline void sary(T* st, T* nd){while(st<nd) sf("%d", st++);}
template <typename T>void tobin(T n,char*bin){int pos=1<<((8*sizeof(T)-2));while((n&pos)==0)pos>>=1;while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
LL todec(char* bin){LL dec= 0;short i= 0, len= strlen(bin) -1;while(bin[i]){if(bin[i++]=='1'){dec += 1<<len;} len--;}return dec;}
/*BUGGI FOR LONG LONG TYPES*/template <typename T>void dec2bin(T n,char*bin){int pos=1<<((8*sizeof(T)-2));while((n&pos)==0)pos>>=1;while(pos>=1){if((n & pos)==0)*bin='0';else*bin='1';pos>>=1;bin++;}*bin='\0';}
template <typename T>inline T LCM(T x,T y){return((x*y)/__gcd(x,y));}
LL str2num(char* str){LL num= *str++ - '0';while(*str){num= 10*num + (*str++ - '0');}return num;}
LL bin2dec(char* bin){LL dec= 0;short i= 0, len= strlen(bin) -1;while(bin[i]){if(bin[i++]=='1'){dec += 1<<len;} len--;}return dec;}
void num2str(LL n,char*st){char*bu=st;while(n>0&&st){*st++='0'+n%10;n/=10;}rary(bu,st);*st='\0';}
inline LL POW(LL base, int exp){LL p= 1; while(exp-->0){p *= base;} return p;}
bool ispal(char* str, int len){for(int i= 0; i<len/2; i++){if(str[i]==str[len-i-1]){}else return false;}return true;}
bool comp(const int& a,const int& b){return a>b;} //reverse sort



const int SZ= 1e6;
const int pSZ= 8E4;

bool stat[SZ+10];
LL primes[pSZ];
int divisors[30];

void sieve()
{
    int sqrtN= sqrt((double) SZ);

    for(int i= 3, j; i<=sqrtN; i+= 2)
    {
        if(stat[i] == 0){
            for(j= i*i; j<=SZ; j+= i<<1)
            {
                stat[j]= 1;
            }

        }

    }

    primes[0]= 2;
    for(int i= 3, j= 1; i<SZ; i+=2){
        if(stat[i] == 0){
            primes[j++]= i;
//            pf("%d ", primes[j]);
        }
    }

}

int factors(LL num){
    LL sqNum= sqrt((double) num);

    for(int i= 0; i<30; i++){
        divisors[i]= 0;
    }

    int divCount= 1;
    int j= 0;
    for(int i= 0; primes[i]<=sqNum; i++)
    {
        if(num%primes[i] == 0)
        {
            while(num%primes[i] == 0){
                divisors[j]++;
                num /= primes[i];
            }

//            divisors[j]++;
            j++;
        }
    }

    if(num != 1){
        divisors[j]= 1;
    }


    for(int i= 0; i<=j; i++){
        divCount*= divisors[i] + 1;
    }

    return divCount;

}

void solve(void)
{
    int T;
    LL Lb, Ub, maxN;
    int divs, maxdiv;
    read(T);

//    while(sf("%d", &n) == 1)
    for(int tst= 1; tst<=T; tst++)
    {
        sf("%lld%lld", &Lb, &Ub);

        maxN= 0;
        maxdiv= 0;
        for(LL i= Lb; i<= Ub; i++){
            divs= factors(i);
            if(maxdiv<divs){
                maxdiv= divs;
                maxN= i;
            }
        }

       pf("Between %lld and %lld, %lld has a maximum of %d divisors.\n", Lb, Ub, maxN, maxdiv);
    }

}



int main(void)
{
    sieve();
    solve();

    return 0;
}




