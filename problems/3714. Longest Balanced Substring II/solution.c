#include <string.h>

#define MAXN 100005
#define HSIZE 262144

/* ---------- single char run ---------- */
static int longest_single(const char *s){
    int best=0,cnt=0;
    for(int i=0;s[i];i++){
        if(i==0||s[i]==s[i-1]) cnt++;
        else cnt=1;
        if(cnt>best) best=cnt;
    }
    return best;
}

/* ---------- two char equal ---------- */

static int first1[2*MAXN];
static int seen1[2*MAXN];
static int epoch1=1;

static int longest_two(const char *s,char x,char y,char bad){
    int n=strlen(s),d=0,best=0,off=n;

    epoch1++;
    seen1[d+off]=epoch1;
    first1[d+off]=-1;

    for(int i=0;i<n;i++){
        if(s[i]==bad){
            epoch1++;
            d=0;
            seen1[d+off]=epoch1;
            first1[d+off]=i;
            continue;
        }

        if(s[i]==x) d++;
        else if(s[i]==y) d--;

        if(seen1[d+off]==epoch1){
            int len=i-first1[d+off];
            if(len>best) best=len;
        }else{
            seen1[d+off]=epoch1;
            first1[d+off]=i;
        }
    }
    return best;
}

/* ---------- three equal ---------- */

typedef struct{
    int d1,d2,idx,stamp;
} Node;

static Node H[HSIZE];
static int hepoch=1;

static inline unsigned hfun(int a,int b){
    unsigned x=(unsigned)a*1000003u ^ (unsigned)b;
    return x&(HSIZE-1);
}

static int longest_three(const char *s){
    int A=0,B=0,C=0,best=0,n=strlen(s);
    hepoch++;

    unsigned h=hfun(0,0);
    H[h]=(Node){0,0,-1,hepoch};

    for(int i=0;i<n;i++){
        if(s[i]=='a') A++;
        else if(s[i]=='b') B++;
        else C++;

        int d1=A-B, d2=A-C;
        h=hfun(d1,d2);

        while(H[h].stamp==hepoch){
            if(H[h].d1==d1 && H[h].d2==d2){
                int len=i-H[h].idx;
                if(len>best) best=len;
                goto cont;
            }
            h=(h+1)&(HSIZE-1);
        }
        H[h]=(Node){d1,d2,i,hepoch};
cont:;
    }
    return best;
}

/* ---------- main ---------- */

int longestBalanced(char* s){
    int ans=0,t;

    t=longest_single(s); if(t>ans) ans=t;

    t=longest_two(s,'a','b','c'); if(t>ans) ans=t;
    t=longest_two(s,'a','c','b'); if(t>ans) ans=t;
    t=longest_two(s,'b','c','a'); if(t>ans) ans=t;

    t=longest_three(s); if(t>ans) ans=t;

    return ans;
}
