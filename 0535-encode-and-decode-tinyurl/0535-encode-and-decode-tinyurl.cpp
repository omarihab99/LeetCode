class Solution {
public:
    string l;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        l = longUrl;
        return longUrl+'+';
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return l;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));