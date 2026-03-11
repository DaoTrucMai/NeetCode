int lengthOfLongestSubstring(char* s) {
    int last[256];
    for (int i = 0; i < 256; i++) 
    last[i] = -1; // chưa thấy ký tự nào

    int left = 0; // biên trái cửa sổ
    int ans = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = (unsigned char)s[right];

        // nếu ký tự c đã xuất hiện trong cửa sổ hiện tại
        if (last[c] >= left) {
            // nhảy left qua sau vị trí trùng để cửa sổ lại hợp lệ
            left = last[c] + 1;
        }

        // cập nhật vị trí xuất hiện gần nhất của c
        last[c] = right;

        // độ dài cửa sổ hiện tại
        int len = right - left + 1;
        if (len > ans) ans = len;
    }

    return ans;
}