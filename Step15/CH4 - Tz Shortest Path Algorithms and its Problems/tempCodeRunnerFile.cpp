
    int n = 7;
    vector<vector<int>> roads = {
        {0,6,7},
        {0,1,2},
        {1,2,3},
        {1,3,3},
        {6,3,3},
        {3,5,1},
        {6,5,1},
        {2,5,1},
        {0,4,5},
        {4,6,2}
    };

    cout << obj.countPaths(n, roads) << endl;

    return 0;
}