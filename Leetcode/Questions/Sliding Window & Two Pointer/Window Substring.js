var minWindow = function (s, t) {
    let n = s.length;
    let m = t.length;
    let mp = new Map();
    // Populate map with characters from string t
    for (let i = 0; i < m; i++) {
        mp.set(t[i], (mp.get(t[i]) || 0) + 1);
    }
    let l = 0;
    let r = 0;
    let cnt = 0;
    let sindex = -1;
    let len = Infinity; // Initialize len with maximum value
    while (r < n) {
        if (mp.has(s[r])) {
            if (mp.get(s[r]) > 0) {
                cnt++;
            }
            mp.set(s[r], mp.get(s[r]) - 1);
        }
        while (cnt === m) {
            if (len > r - l + 1) {
                len = r - l + 1;
                sindex = l;
            }
            // Move left pointer

            mp.set(s[l], mp.get(s[l]) + 1);
            if (mp.get(s[l]) > 0) {
                cnt--;
            }

            l++;
        }
        r++;
    }
    if (sindex === -1) {
        return "";
    }
    return s.substring(sindex, sindex + len);
};

// Example usage
console.log(minWindow("ADOBECODEBANC", "ABC")); // Output: "BANC"
