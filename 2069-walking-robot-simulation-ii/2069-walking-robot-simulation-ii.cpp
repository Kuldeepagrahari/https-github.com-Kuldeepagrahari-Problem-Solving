class Robot {
    int idx = 0;
    bool moved = false;
    vector<pair<int, int>> pos;
    vector<int> dir;
    string toDir[4] = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) {
        for (int i = 0; i < width; ++i) { pos.push_back({i, 0}); dir.push_back(0); }
        for (int i = 1; i < height; ++i) { pos.push_back({width - 1, i}); dir.push_back(1); }
        for (int i = width - 2; i >= 0; --i) { pos.push_back({i, height - 1}); dir.push_back(2); }
        for (int i = height - 2; i > 0; --i) { pos.push_back({0, i}); dir.push_back(3); }
        dir[0] = 3;
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx].first, pos[idx].second};
    }
    
    string getDir() {
        return !moved ? "East" : toDir[dir[idx]];
    }
};