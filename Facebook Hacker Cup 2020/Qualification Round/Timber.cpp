#include <bits/stdc++.h>

using namespace std;

struct Position{
    int height = 0;
    int fromleft = 0;
    int fromright = 0;

    bool seenleft = false;
    bool seenright = false;
};

int main() {
    int sections;
    cin >> sections;
    for (int i = 0; i < sections; ++i) {
        int maxfromleft = 0;
        int maxfromright = 0;
        int trees;
        cin >> trees;
        map<int, Position> treemap;
        for (int j = 0; j < trees; ++j) {
            int position, height;
            cin >> position >> height;
            treemap[position].height = height;
            treemap[position - height].fromright = max(treemap[position - height].fromright, height);
            treemap[position + height].fromleft = max(treemap[position + height].fromleft, height);
        }
        for (auto it = treemap.begin(); it != treemap.end(); ++it) {
            if (it->second.height != 0 && !it->second.seenleft) {
                int coords = it->first + it->second.height;
                Position nextpos = treemap[coords];
                nextpos.seenleft = true;
                nextpos.fromleft = max(nextpos.fromleft, it->second.height);
                maxfromleft = max(maxfromleft, nextpos.fromleft);
                while (nextpos.height != 0) {
                    coords += nextpos.height;
                    treemap[coords].fromleft = max(treemap[coords].fromleft, nextpos.fromleft + nextpos.height);
                    treemap[coords].seenleft = true;
                    nextpos = treemap[coords];
                    maxfromleft = max(maxfromleft, nextpos.fromleft);
                }
            }
        }
        for (auto it = treemap.rbegin(); it != treemap.rend(); ++it) {
            if (it->second.height != 0 && !it->second.seenright) {
                int coords = it->first - it->second.height;
                Position nextpos = treemap[coords];
                nextpos.seenright = true;
                nextpos.fromright = max(nextpos.fromright, it->second.height);
                maxfromright = max(maxfromright, nextpos.fromright);
                while (nextpos.height != 0) {
                    coords -= nextpos.height;
                    treemap[coords].fromright = max(treemap[coords].fromright, nextpos.fromright + nextpos.height);
                    treemap[coords].seenright = true;
                    nextpos = treemap[coords];
                    maxfromright = max(maxfromright, nextpos.fromright);
                }
            }
        }
        int maxOneDirection = max(maxfromleft, maxfromright);
        int maxTwoDirection = 0;
        for (auto it = treemap.begin(); it != treemap.end(); ++it) {
            if (it->second.fromleft != 0 && it->second.fromright != 0) maxTwoDirection = max(maxTwoDirection, it->second.fromleft + it->second.fromright);
        }
        cout << "Case #" << i+1 << ": " << max(maxOneDirection, maxTwoDirection) << "\n";
    }
}