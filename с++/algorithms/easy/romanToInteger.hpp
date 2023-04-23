//  Roman numerals are represented by seven different symbols : I, V, X, L, C, Dand M.
//  
//  Symbol       Value
//  I             1
//  V             5
//  X             10
//  L             50
//  C             100
//  D             500
//  M             1000
//  For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II.The number 27 is written as XXVII, which is XX + V + II.
//  
//  Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//  
//  I can be placed before V(5) and X(10) to make 4 and 9.
//  X can be placed before L(50) and C(100) to make 40 and 90.
//  C can be placed before D(500) and M(1000) to make 400 and 900.
//  Given a roman numeral, convert it to an integer.


//  Example 1:
//  
//  Input: s = "III"
//  Output : 3
//  Explanation : III = 3.
//  Example 2 :
//  
//  Input : s = "LVIII"
//  Output : 58
//  Explanation : L = 50, V = 5, III = 3.
//  Example 3 :
//  
//  Input : s = "MCMXCIV"
//  Output : 1994
//  Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.


class Solution {
private:
    std::unordered_map<char, int> dict
    {
        {'I',1    },
        {'V',5    },
        {'X',10   },
        {'L',50   },
        {'C',100  },
        {'D',500  },
        {'M',1000 },
    };

    int placedBefore(const char& _charBefore, const char _charAfter)
    {
        if (_charBefore == 'I') {
            if (_charAfter == 'V') return 4;
            else if (_charAfter == 'X') return 9;
        }
        else if (_charBefore == 'X') {
            if (_charAfter == 'L') return 40;
            else if (_charAfter == 'C') return 90;
        }
        else if (_charBefore == 'C') {
            if (_charAfter == 'D') return 400;
            else if (_charAfter == 'M') return 900;
        }

        return 0;
    }
public:
    int romanToInt(string s) {
        int result = 0;

        for (size_t i = 0; i < s.length(); i++) {
            auto _placedBefore = placedBefore(s[i], s[i + 1]);
            if (_placedBefore != 0) { result += _placedBefore; i++; }
            else { result += dict[s[i]];}
        }
        return result;
    }
};