///Автор Охлопков ИВТ-23


#include <vector>
#include <algorithm>
#include "greedy_algorithm.h"
#include<cassert>


///сортировка занятий по возрастанию
bool LessonSort(const Lesson& a, const Lesson& b) {
    return a.endTime < b.endTime;
}

///проверка, что время окончания != времени начала занятия
bool Check(const Lesson& a) {
    if ((a.startTime == a.endTime) || (a.startTime < 0) || (a.endTime < 0))
    {
        return false;
    }
    else return true;
}



/// оптимальный выбор занятий
/// std::vector<Lesson>& activities - занятия
int selectLesson(std::vector<Lesson>& activities) {
    // Сортируем занятия по времени окончания в возрастающем порядке.
    //используется компаратор (функция, которая принимает два значения и возвращает значение типа bool)  LessonSort
    std::sort(activities.begin(), activities.end(), LessonSort);

    int selectedLesson = 0; // Счетчик выбранных занятий
    int lastEndTime = 0;            // Время окончания последнего выбранного занятия

    // Перебираем отсортированные занятия
    for (const Lesson& activity : activities) {
        //проверка
        if (Check(activity))
        {
            // Если текущее занятие начинается после окончания последнего выбранного занятия,
            // значит, они не пересекаются.
            if (activity.startTime >= lastEndTime) {
                lastEndTime = activity.endTime; // Обновляем время окончания последнего выбранного занятия
                selectedLesson++;      // Увеличиваем счетчик выбранных занятий
            }
        }
        
    }

    return selectedLesson; // Возвращаем общее количество выбранных занятий
}


///тесты
void all_assert()
{

    double eps = 0.000001;
    std::vector<Lesson> activities1 = { {1, 3}, {2, 4}, {3, 5}, {5,7}, {6,8}, {7,9} };
    int count = selectLesson(activities1);
    assert(count - 4 < eps);

    std::vector<Lesson> activities2 = { {1, 5}, {2, 3}, {3, 5}, {1,4}, {3,4}};
    count = selectLesson(activities2);
    assert(count - 2 < eps);


    std::vector<Lesson> activities3 = { {1, 5}, {2, 4}, {5, 8}, {9,10}, {6,7}};
    count = selectLesson(activities3);
    assert(count - 3 < eps);


    std::vector<Lesson> activities4 = { {0, 0}, {0, 0}, {0, 0}, {0,0}, {0,0} };
    count = selectLesson(activities4);
    assert(count - 0 < eps);

    std::vector<Lesson> activities5 = { {-1, -1}, {-1, -1}, {-1, -1}, {-1,-1}, {-1,-1} };
    count = selectLesson(activities5);
    assert(count - 0 < eps);


}