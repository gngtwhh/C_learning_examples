//力扣567
bool checkInclusion(char * s1, char * s2) {
    int pLen = strlen(s1);
    int tLen = strlen(s2);
    int pFreq[26], tFreq[26];
    int pCount = 0, tCount = 0;
    memset(pFreq, 0, sizeof pFreq);
    memset(tFreq, 0, sizeof tFreq);

    for (int i = 0; i < pLen; ++i) {
        pFreq[s1[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (pFreq[i] > 0)
            pCount++;
    }

    int left = 0, right = 0;
    while (right < tLen) {
        if (pFreq[s2[right] - 'a'] > 0) {
            tFreq[s2[right] - 'a']++;
            if (pFreq[s2[right] - 'a'] == tFreq[s2[right] - 'a']) {
                tCount++;
            }
        }
        right++;

        while (pCount == tCount) {
            if (right - left == pLen) {
                return true;
            }
            if (pFreq[s2[left] - 'a'] > 0) {
                tFreq[s2[left] - 'a']--;
                if (tFreq[s2[left] - 'a'] < pFreq[s2[left] - 'a']) {
                    tCount--;
                }
            }
            left++;
        }
    }
    return false;
}