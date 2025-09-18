class TaskManager {
public:
    unordered_map<int, int> taskPriorityMap; // task -> priority
    unordered_map<int, int> taskOwnerMap;    // task -> owner
    priority_queue<pair<int, int>> maxHeap;  // priority , taskId

    TaskManager(vector<vector<int>>& tasks) {
        // userId, taskId, priority
        for (auto& it : tasks) {
            add(it[0], it[1], it[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
        maxHeap.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskPriorityMap[taskId] = newPriority;
        maxHeap.push({newPriority, taskId});
    }

    void rmv(int taskId) { taskPriorityMap[taskId] = -1; }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();

            if (priority == taskPriorityMap[taskId]) {
                taskPriorityMap[taskId] = -1;
                return taskOwnerMap[taskId];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */