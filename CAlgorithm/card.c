#include <stdio.h>
#define MAX_LEN 3300
int Answer;

int dp[MAX_LEN][MAX_LEN]={0,};

//Not Used
int c1[MAX_LEN] ={0,};
int c2[MAX_LEN] ={0,};
int len1 =0;
int len2 =0;

int pr[MAX_LEN][MAX_LEN], qr[MAX_LEN][MAX_LEN],px[MAX_LEN], qx[MAX_LEN],p[MAX_LEN],q[MAX_LEN];

void solve(void)
{
    int n, k;
    scanf("%d %d",&n,&k);
//printf("%d %d\n",n,k);
    // 1: initialize
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) {dp[i][j] = 0; pr[i][j] = 0; qr[i][j] = 0;}
    for(int i=0;i<=n;i++) px[i] = qx[i] =0;
    // 2: scanf
    for(int i=1;i<=n;i++) scanf("%d ",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d ",&q[i]);
    
    // 3: Init Value
    dp[0][0]=1;
    
    // 4: 'l' means
    //    'ls' find l which is available to take
    // x refer card counter how many card available at that turn.
    int l = 1, ls = 0;
    for(int i=1;i<=n;i++)
    {
        ls += p[i];
        //find something
        while(ls>k) ls -= p[l++];
        px[i]= l-1;
        //printf("a : %d\n",l-1);
    }
    
    // 5:
    l = 1; ls=0;
    for(int i=1;i<=n;i++)
    {
        ls += q[i];
        while(ls>k) ls-= q[l++];
        qx[i] = l-1;
        //printf("b : %d\n",l-1);
    }
    
    
    
    // r represent what?
    // 2-dimensional dynamic programming structure
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int pt = 0, qt = 0;
            if (i) pt = pr[i - 1][j] - (px[i] ? pr[px[i] - 1][j] : 0);
            if (j) qt = qr[i][j - 1] - (qx[j] ? qr[i][qx[j] - 1] : 0);
            if (pt + qt != i - px[i] + j - qx[j]) dp[i][j] = 1;
            pr[i][j] = (i ? pr[i - 1][j] : 0) + dp[i][j];
            qr[i][j] = (j ? qr[i][j - 1] : 0) + dp[i][j];
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            int pt =0, qt=0;
            if (i) pt = pr[i-1][j] - (px[i] ? pr[px[i]-1][j] : 0);
            if (j) qt = qr[i][j-1] - (qx[j] ? qr[i][qx[j]-1] : 0);
            if(pt + qt != i - px[i] + j - qx[j]) dp[i][j]=1;
            pr[i][j] = (i ? pr[i-1][j] : 0) + dp[i][j];
            qr[i][j] = (j ? pr[i][j-1] : 0) + dp[i][j];
            
        }
    }*/
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",dp[i][j]);
            
        }
        printf("\n");
    }
    
    int s = 0;
    for (int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            s+= dp[i][j];
    printf("%d %d\n",s,(n+1)*(n+1)-s);
    
    return;
}

int main(void)
{
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using scanf function.
       You may remove the comment symbols(//) in the below statement and use it.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */
    //freopen("input.txt", "r", stdin);

    /*
       If you remove the statement below, your program's output may not be recorded
       when your program is terminated after the time limit.
       For safety, please use setbuf(stdout, NULL); statement.
     */
    
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    
    for(test_case = 0; test_case < T; test_case++)
    {
        
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
        /////////////////////////////////////////////////////////////////////////////////////////////
    
                // Print the answer to standard output(screen).
        
        printf("Case #%d\n", test_case+1);
        //printf("%d\n", Answer);
        solve();
        //if(test_case >10) return 0;
    }

    return 0;//Your program should return 0 on normal termination.
}
