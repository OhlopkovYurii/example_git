///����� �������� ���-23

#include <vector>
#include <algorithm>



///��������� �������
struct Lesson {
    int startTime; // ����� ������ �������
    int endTime;   // ����� ��������� �������
};


///���������� ������� �� �����������
bool LessonSort(const Lesson& a, const Lesson& b);

/// ����������� ����� �������
/// std::vector<Lesson>& activities - �������
int selectLesson(std::vector<Lesson>& activities);


void all_assert();