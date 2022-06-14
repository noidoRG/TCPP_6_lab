#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int labAmount = 5;

class Teacher;

/* Класс студент */
class Student {
	friend class Teacher;
public:
	int loadedLabs;
	int currentLabs;
	bool examDop;
	bool currentExam;
	bool loadedExam;

	Student() {
		loadedLabs = 0;
		currentLabs = 0;
		examDop = 0;
		currentExam = false;
		loadedExam = false;
	}

	~Student() {};
	void checkLabStatus();
	void checkExamStatus();
	int getCurrentLabs() { return currentLabs; };
	bool getCurrentExam() { return currentExam; };
	void setLoadedLabs(int newLabs);
	void sendLab();
	void sendExam();
};

// Отправить экзамен
void Student::sendExam() {
	if (examDop == true) {
		loadedExam = true;
		cout << "Вы успешно отправили экзамен на проверку, дождитесь, пока преподаватель его проверит" << endl;
	}
	else {
		loadedExam = false;
		cout << "Сперва необходимо сдать все лабораторные" << endl;
	}
}

// Выставить количество загруженных лабораторных
void Student::setLoadedLabs(int newLabs) {
	loadedLabs += newLabs;
	if (loadedLabs > labAmount) loadedLabs = labAmount;
}

// Отправить лабораторную
void Student::sendLab() {
	setLoadedLabs(1);
	cout << "Вы загрузили лабораторную. Осталось ещё " << labAmount - loadedLabs << endl;
}

// Проверить статус лабораторной работы
void Student::checkLabStatus() {
	cout << "На данный момент у Вас загружено: " << loadedLabs << " лабораторных работ из " << labAmount << endl;
	cout << "На данный момент у Вас сдано: " << currentLabs << " лабораторных работ из " <<labAmount << endl;
}

// Проверить статус экзамена
void Student::checkExamStatus() {
	if (examDop == false) cout << "У вас нет допуска к экзамену, сначала нужно сдать все лабораторные и получить за них оценки" << endl;
	else cout << "Вы можете сдать экзамен!" << endl;
	if (currentExam == false) cout << "На данный момент Вы не сдали экзамен" << endl;
	else cout << "Вы сдали экзамен!" << endl;
}


/* Класс декан */
class Dean {
	friend Teacher;
	bool studentReport;
public:
	Dean() {
		studentReport = false;
	}
	void showReport();
};

// Просмотреть отчёт
void Dean::showReport() {
	if (studentReport == true) cout << "Студент сдал всё и может быть переведён на следующий курс" << endl;
	else cout << "Студент может быть отчислен, если не сдаст все работы" << endl;
};


/* Класс преподаватель */
class Teacher {
	friend Student;
	friend Dean;
public:
	void makeMark(Student & st);
	void setExamDop(Student& st);
	void setExam(Student & st);
	void sendReport(Student & st, Dean & dn);
};

// Выставить оценку за работу
void Teacher::makeMark(Student & st) {
	if (st.loadedLabs == 0) cout << "Студент ещё не загрузил ни одной работы" << endl;
	else if (st.loadedLabs > st.currentLabs) {
		cout << "Вы выставили оценку за лабораторную работу" << endl;
		st.currentLabs += 1;
		if (st.currentLabs > labAmount) st.currentLabs = labAmount;
		cout << "На данный момент у студента загружено " << st.loadedLabs << " из " << labAmount << endl;
		cout << "А сдано " << st.currentLabs << " из " << labAmount << endl;
	}
	else cout << "Вы уже оценили все лабораторные" << endl;
	setExamDop(st);
}
 
// Выставить оценку за доп экзамен
void Teacher::setExamDop(Student& st) {
	if (st.currentLabs == labAmount) st.examDop = true;
	else st.examDop = false;
}

// Выставить оценку за экзамен
void Teacher::setExam(Student& st) {
	if (st.loadedExam == true) {
		cout << "Студент загрузил выполнение экзамена, вы поставили ему оценку" << endl;
		st.currentExam = true;
	}
	else cout << "Студент ещё не отправил выполненный экзамен"<<endl;
}

// Отправить ведомость
void Teacher::sendReport(Student& st, Dean& dn) {
	if (st.currentExam == true) {
		dn.studentReport = true;
		cout << "Ведомость отправлена в деканат." << endl;
	}
	else cout << "Студент ещё не сдал экзамен, невозможно заполнить ведомость" << endl;
}


/* Главная функция */
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student st;
	Teacher tc;
	Dean dn;
	int key;
	while (true) {
		cout << "Выберите, в качестве кого Вы хотите зайти:" << endl;
		cout << "1. Студент" << endl;
		cout << "2. Преподаватель" << endl;
		cout << "0. Выход" << endl;
		cin >> key;

		if (key == 1) {

			while (true) {

				system("cls");
				cout << "Выберите, что необходимо сделать:" << endl;
				cout << "1. Проверить состояние лабораторных" << endl;
				cout << "2. Проверить состояние экзамена" << endl;
				cout << "3. Сдать работу" << endl;
				cout << "4. Сдать экзамен" << endl;
				cout << "5. Выход" << endl;
				int keySt;
				cin >> keySt;

				if (keySt == 1) {
					system("cls");
					st.checkLabStatus();
					system("pause");
					continue;
				}

				if (keySt == 2) {
					system("cls");
					st.checkExamStatus();
					system("pause");
					continue;
				}

				if (keySt == 3) {
					system("cls");

					st.sendLab();
					system("pause");
					continue;
				}

				if (keySt == 4) {
					system("cls");
					st.sendExam();
					system("pause");
					continue;
				}

				if (keySt == 5) {
					system("cls");
					break;
				}
		
			}
		}

		if (key == 2) {

			while (true) {

				system("cls");
				cout << "Выберите, что необходимо сделать:" << endl;
				cout << "1. Выставить оценку" << endl;
				cout << "2. Запросить ведомость" << endl;
				cout << "3. Выставить оценку за экзамен" << endl;
				cout << "4. Сдать ведомость" << endl;
				cout << "5. Выход" << endl;
				int keyTc;
				cin >> keyTc;

				if (keyTc == 1) {
					system("cls");
					tc.makeMark(st);
					system("pause");
					continue;
				}

				if (keyTc == 2) {
					system("cls");
					dn.showReport();
					system("pause");
					continue;
				}

				if (keyTc == 3) {
					system("cls");
					tc.setExam(st);
					system("pause");
					continue;
				}
				if (keyTc == 4) {
					system("cls");
					tc.sendReport(st, dn);
					system("pause");
					continue;
				}

				if (keyTc == 5) {
					system("cls");
					break;
				}

			}
		}

		if (key == 0) break;
	}	
	return 0;
}