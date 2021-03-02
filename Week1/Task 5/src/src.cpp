#include <iostream>
#include <map>
#include <string>
#include <tuple>

using namespace std;

class TeamTasks {
public:
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        return data.at(person);
    }

    void AddNewTask(const string& person)
    {
        data[person][TaskStatus::NEW]++;
    }
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
    {
        TasksInfo updated, untouched = data[person];
        int a = data[person][TaskStatus::NEW];
        int b = data[person][TaskStatus::IN_PROGRESS];
        int c = data[person][TaskStatus::TESTING];
        for (; 0 < task_count; task_count--, a--)
        {
            if (a == 0)
            {
                break;
            }
            data[person][TaskStatus::NEW]--;
            data[person][TaskStatus::IN_PROGRESS]++;

            untouched[TaskStatus::NEW]--;
            updated[TaskStatus::IN_PROGRESS]++;
        }
        for (; 0 < task_count; task_count--, b--)
        {
            if (b == 0)
            {
                break;
            }
            data[person][TaskStatus::IN_PROGRESS]--;
            data[person][TaskStatus::TESTING]++;

            untouched[TaskStatus::IN_PROGRESS]--;
            updated[TaskStatus::TESTING]++;
        }
        for (; 0 < task_count; task_count--, c--)
        {
            if (c == 0)
            {
                break;
            }
            data[person][TaskStatus::TESTING]--;
            data[person][TaskStatus::DONE]++;

            untouched[TaskStatus::TESTING]--;
            updated[TaskStatus::DONE]++;
        }
        TasksInfo updated1 = updated, untouched1 = untouched, data1 = data[person];
        for (auto c : updated1)
        {
            if (c.second == 0)
            {
                updated.erase(c.first);
            }
        }
        for (auto c : untouched1)
        {
            if (c.second == 0)
            {
                untouched.erase(c.first);
            }
        }
        for (auto c : data1)
        {
            if (c.second == 0)
            {
                data[person].erase(c.first);
            }
        }
        untouched.erase(TaskStatus::DONE);
        return tie(updated, untouched);
    }

private:
    map<string, TasksInfo> data;
};