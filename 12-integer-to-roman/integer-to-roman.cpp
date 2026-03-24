class Solution {
public:
    string intToRoman(int num) {

        vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";

        for(int i = 0; i < values.size(); i++) {

            // jab tak num bada hai current value se
            while(num >= values[i]) {

                result += symbols[i];   // symbol add karo
                num -= values[i];      // num ko reduce karo
            }
        }

        return result;
    }
};