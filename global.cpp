#include "global.h"
pair<string,QPoint> find_pos(const string& s)
{
    for(size_t i = 0;i < positions.size();i++){
        if(positions[i].first == s)
            return positions[i];
    }
}
