class Solution {
public:
    void rec(int n, int y, vector<bool> &xTaken, vector<bool> &positiveDiagTaken, vector<bool> &negativeDiagTaken, vector<int> &sol, vector<string> &currentString, vector<vector<string>> &global) {
        string s(n, '.');
        for (int x = 0; x < n; x++) {
            // check if current placement is legal.
            int negativeDiag = x+y;
            int positiveDiag = x-y + (n - 1); // offset negative value
            if (xTaken[x]) continue; // this Y column is taken. illegal placement.
            if (positiveDiagTaken[positiveDiag]) continue; // this diag line is taken
            if (negativeDiagTaken[negativeDiag]) continue; // this diag line is taken
            // legal placement, queen won't be attacked.
            sol[y] = x;
            s[x] = 'Q';
            currentString.push_back(s);

            cout << "y " << y << "x " << x << endl;

            xTaken[x] = true;
            negativeDiagTaken[negativeDiag] = true;
            positiveDiagTaken[positiveDiag] = true;

            if (y == n - 1) { // bottom
                // add solution to global solution list
                global.push_back(currentString);
            }else {
                rec(n, y + 1, xTaken, positiveDiagTaken, negativeDiagTaken, sol, currentString, global);
            }

            // revert
            s[x] = '.';
            currentString.pop_back();
            xTaken[x] = false;
            negativeDiagTaken[negativeDiag] = false;
            positiveDiagTaken[positiveDiag] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector yTaken(n, false);
        vector positiveDiagTaken(n * 2 - 1, false);
        vector negativeDiagTaken((n * 2) - n, false);
        vector sol(n, 0);
        vector<string> currentString;
        vector<vector<string>> global;

        rec(n, 0, yTaken, positiveDiagTaken, negativeDiagTaken, sol, currentString, global);

        return global;
    }
};
