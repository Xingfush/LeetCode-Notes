/* 求[1,n)范围内的素数个数 */

int count_primes(int n){
    vector<bool> isPrime(n,true);
    int res = 0;
    for(int i=2;i<n;i++){
        if(isPrime[i]){
            res++;
            for(int j=2;i*j<n;j++){
                isPrime[i*j]=false;
            }
        }
    }

    return res++;
}