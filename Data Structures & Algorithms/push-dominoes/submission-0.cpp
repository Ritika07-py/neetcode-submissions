class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = "";
        int dots = 0;
        bool R = false;

        for (char d : dominoes) {
            if (d == '.') {
                dots++;
            } else if (d == 'R') {
                if (R) {
                    res += string(dots + 1, 'R');
                } else if (dots > 0) {
                    res += string(dots, '.');
                }
                dots = 0;
                R = true;
            } else {
                if (R) {
                    res += 'R';
                    if (dots > 0) {
                        res += string(dots / 2, 'R');
                        if (dots % 2 != 0) {
                            res += '.';
                        }
                        res += string(dots / 2, 'L');
                    }
                    res += 'L';
                    R = false;
                    dots = 0;
                } else {
                    res += string(dots + 1, 'L');
                    dots = 0;
                }
            }
        }

        if (R) {
            res += string(dots + 1, 'R');
        } else {
            res += string(dots, '.');
        }

        return res;
    }
};
