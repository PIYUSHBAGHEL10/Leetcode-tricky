class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int temp=num/10;
            num=temp+num%10;
        }
        return num;
    }
};