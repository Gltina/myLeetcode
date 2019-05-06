// 使用二维坐标模拟
class Solution {
public:
    bool judgeCircle(string moves) {
        int imitate_x = 0, imitate_y = 0;
        for (int i=0;i<moves.size();i++) {
            char move = moves[i];
            if (move == 'U'){
                imitate_y += 1;
            }else if(move == 'D') {
                imitate_y -= 1;
            }else if(move == 'L'){
                imitate_x -= 1;
            }else if(move == 'R'){
                imitate_x += 1;
            }
        }
        return (imitate_x == 0) &&( imitate_y == 0);
    }
};
