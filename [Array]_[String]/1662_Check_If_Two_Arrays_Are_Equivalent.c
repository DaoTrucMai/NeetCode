bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i=0,j=0; //index word
    int x=0,y=0; //index each word

    while (i<word1Size && j< word2Size){
        if (word1[i][x]!=word2[j][y]) return false;

        x++;
        y++;

        if (word1[i][x]=='\0'){
            i++;
            x=0;
        }

        if (word2[j][y]=='\0'){
            j++;
            y=0;
        }
    }
    return i == word1Size && j == word2Size;
}