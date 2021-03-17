/*Encode and Decode TinyURL

Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it 
returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode 
algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.*/

class Solution {
private:
    unordered_map<string, string> codeMap, urlMap;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int len = chars.length();
    const string tinyURL = "http://tinyurl.com/";
    // private method to generate a random 6-char code.
    string genCode() {
        string code = "";
        for(int i = 0; i < 6; i++) {
            code += chars[rand() % len];
        }
        return tinyURL + code;
    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longUrl.empty()) return "";
        // URL already encoded before.
        if(urlMap.find(longUrl) != urlMap.end()) {
            return urlMap[longUrl];
        }
        
        // generate new unique code.
        string code;
        do {
            code = genCode();
        } while(codeMap.find(code) != codeMap.end());
        
        // Encode Url and return.
        codeMap[code] = longUrl;
        urlMap[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.empty()) return "";
        // shortUrl expects an entry in CodeMap, return the encoded url.
        return codeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));