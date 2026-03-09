bool recCheck(int i,int j,string& s,string& p){
        if(j == p.size()) return i == s.size();

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

         if(j+1 < p.size() && p[j+1] == '*'){
        return recCheck(i, j+2, s, p)      // 0 occurrences of a*
            || (match && recCheck(i+1, j, s, p)); // 1+ occurrences
        }

        if(match) return recCheck(i+1, j+1, s, p);
        return false;

    }
    bool isMatch(string s, string p) {
        return recCheck(0,0,s,p);
    }
