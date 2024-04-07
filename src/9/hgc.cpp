class Solution {
public:

    //定义递归回溯函数
    //传入结果数组：引用类型
    //传入映射容器和tickets的大小
    //还需要传入起点字符串
    bool backtracking(vector<string>& result, unordered_map<string, map<string, int>> target, int size, string begin) {
        //如果结果数组中的机场数目等于路径数目加一，则直接返回true，表示路径收集完了
        if (result.size() == size + 1) {
            return true;
        }
        //递归回溯逻辑
        //同一层遍历当前起点能走的路径，初始起点是JFK，如果路径能走（用第二个映射的int判断），则进入回溯，不能走，则返回上一层
        //向下一层遍历是为了找到下一条路径的起点
        for (map<string, int>::iterator it = target[begin].begin(); it != target[begin].end(); it++) {//取出起点的map容器，然后再遍历容器中的每一个终点
            if (it->second > 0) {//如果当前路径可以走
                //将当前终点加入result，作为下一层递归的起点
                result.push_back(it->first);
                it->second--;
                //进入递归（如果下一层判断出了路径已经收集完了，则直接返回true，表示回溯也不用做了，直接一步步返回到最外层
                if (this->backtracking(result, target, size, it->first)) return true;
                //回溯
                result.pop_back();
                it->second++;
            }
        }
        //如果当前起点所有的路径都找完了，并且结果数组中的路径没有收集完，则返回false，表示还需要进入回溯
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //定义结果数组
        vector<string> result;
        //定义映射容器并初始化
        unordered_map<string, map<string, int>> target;
        for (int i = 0; i < tickets.size(); i++) {//初始化target，第一元素为起点，第二个元素为终点和路径次数的映射
            target[tickets[i][0]][tickets[i][1]]++;
        }
        //初始化结果数组
        result.push_back("JFK");

        //调用递归回溯函数
        this->backtracking(result, target, tickets.size(), "JFK");

        //返回结果数组
        return result;
    }
};