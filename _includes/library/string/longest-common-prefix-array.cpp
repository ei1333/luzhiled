struct LongestCommonPrefixArray {
  vector< int > LCP, rank;

  LongestCommonPrefixArray(SuffixArray &SA) {
    string &s = SA.s;
    rank.resize(s.size());
    for(int i = 0; i < s.size(); i++) {
      rank[SA[i]] = i;
    }
    LCP.resize(s.size());
    LCP[0] = 0;
    for(int i = 0, h = 0; i < s.size(); i++) {
      if(rank[i] + 1 < s.size()) {
        for(int j = SA[rank[i] + 1]; max(i, j) + h < s.length() && s[i + h] == s[j + h]; ++h);
        LCP[rank[i] + 1] = h;
        if(h > 0) --h;
      }
    }
  }

  int operator[](int k) const {
    return (LCP[k]);
  }

  int size() const {
    return (LCP.size());
  }
};
