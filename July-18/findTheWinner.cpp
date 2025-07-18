class Solution {
    public:
        // int findTheWinner(int n, int k) {
        //     queue<int>q;
        //     for(int i=1;i<=n;i++){
        //         q.push(i);
        //     }
        //     while(q.size()>1){
        //         for(int j=1;j<k;j++){
        //             q.push(q.front());
        //             q.pop();
        //         }
        //         q.pop();
        //     }
        //     return q.front();
        // }
        int solve(int n, int k){
            if(n==1)    return 0;
            return (solve(n-1,k)+k) % n;
        }
        int findTheWinner(int n, int k){
            return solve(n,k) + 1;
        }
    };