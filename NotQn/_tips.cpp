sort(data.begin(), data.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // Sort by first column
    });
