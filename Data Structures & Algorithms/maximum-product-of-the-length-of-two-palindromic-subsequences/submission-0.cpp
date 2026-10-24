class Solution {
public:
    int maxProduct(string s) {
        int n=s.size(),limit=1<<n; vector<int> pal(limit); for(int mask=1;mask<limit;mask++) { string word; for(int i=0;i<n;i++) if(mask&(1<<i)) word+=s[i]; bool valid=true; for(int l=0,r=(int)word.size()-1;l<r;l++,r--) if(word[l]!=word[r]) valid=false; if(valid) pal[mask]=word.size(); } vector<int> best=pal; for(int bit=0;bit<n;bit++) for(int mask=0;mask<limit;mask++) if(mask&(1<<bit)) best[mask]=max(best[mask],best[mask^(1<<bit)]); int answer=0; for(int mask=0;mask<limit;mask++) answer=max(answer,pal[mask]*best[(limit-1)^mask]); return answer;
    }
};

