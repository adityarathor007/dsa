class Solution {
public:
    bool isPrime(int num){
        if(num==1) return false;
        if(num==2 or num==3) return true;

        for(int i=2;i<=sqrt(num);i++){
            if(!(num%i)) return false;
        }

        return true;

    }

    bool completePrime(int num) {
        int y=0,z=1,x=num;
        while(x>0){
            y=z*(x%10)+y; //for suffix
            if(!isPrime(x)) return false;
            if(!isPrime(y)) return false;
            x/=10;
            z*=10;
        }

        return true;

    }
};
