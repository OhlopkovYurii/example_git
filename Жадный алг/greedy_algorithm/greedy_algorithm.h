///Автор Охлопков ИВТ-23

#include <vector>
#include <algorithm>



///структура занятие
struct Lesson {
    int startTime; // Время начала занятия
    int endTime;   // Время окончания занятия
};


///сортировка занятий по возрастанию
bool LessonSort(const Lesson& a, const Lesson& b);

/// оптимальный выбор занятий
/// std::vector<Lesson>& activities - занятия
int selectLesson(std::vector<Lesson>& activities);


void all_assert();