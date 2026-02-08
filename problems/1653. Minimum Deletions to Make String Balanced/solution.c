int minimumDeletions(char* s) {
    int bCount = 0;
    int deletions = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            bCount++;
        } else { // s[i] == 'a'
            // Either delete this 'a' or delete all previous 'b's
            deletions = (deletions + 1 < bCount) ? deletions + 1 : bCount;
        }
    }

    return deletions;
}
