int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);                // Get the length of the string
    int maxLen = 0;                   // Variable to store the maximum length of the substring
    int start = 0;                    // Start index of the current substring
    int lastIndex[256];               // Array to store the last index of each character (ASCII size)

    // Initialize lastIndex array with -1 to indicate that characters haven't been seen yet
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    // Iterate through the string
    for (int end = 0; end < n; end++) {
        // If the character is already seen and is within the current substring
        if (lastIndex[(unsigned char)s[end]] >= start) {
            // Move the start to the next position after the last occurrence
            start = lastIndex[(unsigned char)s[end]] + 1;
        }

        // Update the last index of the current character to the current position
        lastIndex[(unsigned char)s[end]] = end;

        // Update maxLen if the current substring is longer than the previous max
        int currentLen = end - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen; // Return the maximum length of the substring found
}