#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int labAmount = 5;

class Teacher;

/* ����� ������� */
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

// ��������� �������
void Student::sendExam() {
	if (examDop == true) {
		loadedExam = true;
		cout << "�� ������� ��������� ������� �� ��������, ���������, ���� ������������� ��� ��������" << endl;
	}
	else {
		loadedExam = false;
		cout << "������ ���������� ����� ��� ������������" << endl;
	}
}

// ��������� ���������� ����������� ������������
void Student::setLoadedLabs(int newLabs) {
	loadedLabs += newLabs;
	if (loadedLabs > labAmount) loadedLabs = labAmount;
}

// ��������� ������������
void Student::sendLab() {
	setLoadedLabs(1);
	cout << "�� ��������� ������������. �������� ��� " << labAmount - loadedLabs << endl;
}

// ��������� ������ ������������ ������
void Student::checkLabStatus() {
	cout << "�� ������ ������ � ��� ���������: " << loadedLabs << " ������������ ����� �� " << labAmount << endl;
	cout << "�� ������ ������ � ��� �����: " << currentLabs << " ������������ ����� �� " <<labAmount << endl;
}

// ��������� ������ ��������
void Student::checkExamStatus() {
	if (examDop == false) cout << "� ��� ��� ������� � ��������, ������� ����� ����� ��� ������������ � �������� �� ��� ������" << endl;
	else cout << "�� ������ ����� �������!" << endl;
	if (currentExam == false) cout << "�� ������ ������ �� �� ����� �������" << endl;
	else cout << "�� ����� �������!" << endl;
}


/* ����� ����� */
class Dean {
	friend Teacher;
	bool studentReport;
public:
	Dean() {
		studentReport = false;
	}
	void showReport();
};

// ����������� �����
void Dean::showReport() {
	if (studentReport == true) cout << "������� ���� �� � ����� ���� �������� �� ��������� ����" << endl;
	else cout << "������� ����� ���� ��������, ���� �� ����� ��� ������" << endl;
};


/* ����� ������������� */
class Teacher {
	friend Student;
	friend Dean;
public:
	void makeMark(Student & st);
	void setExamDop(Student& st);
	void setExam(Student & st);
	void sendReport(Student & st, Dean & dn);
};

// ��������� ������ �� ������
void Teacher::makeMark(Student & st) {
	if (st.loadedLabs == 0) cout << "������� ��� �� �������� �� ����� ������" << endl;
	else if (st.loadedLabs > st.currentLabs) {
		cout << "�� ��������� ������ �� ������������ ������" << endl;
		st.currentLabs += 1;
		if (st.currentLabs > labAmount) st.currentLabs = labAmount;
		cout << "�� ������ ������ � �������� ��������� " << st.loadedLabs << " �� " << labAmount << endl;
		cout << "� ����� " << st.currentLabs << " �� " << labAmount << endl;
	}
	else cout << "�� ��� ������� ��� ������������" << endl;
	setExamDop(st);
}
 
// ��������� ������ �� ��� �������
void Teacher::setExamDop(Student& st) {
	if (st.currentLabs == labAmount) st.examDop = true;
	else st.examDop = false;
}

// ��������� ������ �� �������
void Teacher::setExam(Student& st) {
	if (st.loadedExam == true) {
		cout << "������� �������� ���������� ��������, �� ��������� ��� ������" << endl;
		st.currentExam = true;
	}
	else cout << "������� ��� �� �������� ����������� �������"<<endl;
}

// ��������� ���������
void Teacher::sendReport(Student& st, Dean& dn) {
	if (st.currentExam == true) {
		dn.studentReport = true;
		cout << "��������� ���������� � �������." << endl;
	}
	else cout << "������� ��� �� ���� �������, ���������� ��������� ���������" << endl;
}


/* ������� ������� */
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student st;
	Teacher tc;
	Dean dn;
	int key;
	while (true) {
		cout << "��������, � �������� ���� �� ������ �����:" << endl;
		cout << "1. �������" << endl;
		cout << "2. �������������" << endl;
		cout << "0. �����" << endl;
		cin >> key;

		if (key == 1) {

			while (true) {

				system("cls");
				cout << "��������, ��� ���������� �������:" << endl;
				cout << "1. ��������� ��������� ������������" << endl;
				cout << "2. ��������� ��������� ��������" << endl;
				cout << "3. ����� ������" << endl;
				cout << "4. ����� �������" << endl;
				cout << "5. �����" << endl;
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
				cout << "��������, ��� ���������� �������:" << endl;
				cout << "1. ��������� ������" << endl;
				cout << "2. ��������� ���������" << endl;
				cout << "3. ��������� ������ �� �������" << endl;
				cout << "4. ����� ���������" << endl;
				cout << "5. �����" << endl;
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