#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int rollNo;

    Student( string& n, int roll) {
        name = n;
        rollNo = roll;
    }

    virtual void print() {
        cout << '\t' << "Name" << '\t' << "Roll No" << endl;
        cout << '\t' << name << "\t" << rollNo << endl;
    }
};

class StudentResult : public Student {
private:
    vector<string> subjects = {"dedc","oops","DM","Coa","Uhiv"};
    vector<int> assessmentMarks={0,0,0,0,0};
    vector<int> examMarks={0,0,0,0,0};

public:
    StudentResult(string& n, int roll) : Student(n, roll) {
         for (int i = 0; i < subjects.size(); ++i) {
            cout << "Enter "<<subjects[i]<< " Assessment Marks: ";
            cin >> assessmentMarks[i];

            cout << "Enter"<<subjects[i]<< "Exam Marks: ";
            cin >> examMarks[i];
        }
    }

    void print(){
        Student::print();
        cout << '\t' << "Subject" << '\t' << "Assessment" << '\t' << "Exam" << endl;
        for (int i = 0; i < subjects.size(); ++i) {
            cout << '\t' << subjects[i] << '\t' << assessmentMarks[i] << '\t' << examMarks[i] << endl;
        }
    }
    void editMarks(){
        cout << "Enter Subject to edit: ";
        string subject;
        cin >> subject;

        auto it = find(subjects.begin(), subjects.end(), subject);
        if (it != subjects.end()) {
            int index = distance(subjects.begin(), it);
            cout << "Enter new Assessment Marks: ";
            cin >> assessmentMarks[index];

            cout << "Enter new Exam Marks: ";
            cin >> examMarks[index];
        } else {
            cout << "Subject not found." << endl;
        }
    }
};

int main() {
    vector<StudentResult> records;

    while (true) {
        cout << "\n1. Print Records\n2. Insert Record\n3. Delete Record\n4. Edit Record\n5. Search Record\n6. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                for (auto& record : records) {
                    record.print();
                    cout << endl;
                }
                
                break;
            }
            case 2: {
                int temproll;
                string tempname;
                cout<<"Enter the roll number to insert:";
                cin>>temproll;
                cout<<"Enter the name:";
                cin>>tempname;
                StudentResult newRecord(tempname,temproll);
                records.push_back(newRecord);
                break;
            }
            case 3: {
                cout << "Enter Roll No to delete: ";
                int roll;
                cin >> roll;

                int index =-1;
                for(int i =0;i<records.size();i++)
                {
                   if(records[i].rollNo==roll)
                   {
                        index = i;
                        break;
                   }
                }

                if (index!=-1) {
                    records.erase(records.begin()+index, records.end());
                    cout << "Record deleted successfully." << endl;
                } else {
                    cout << "Record not found." << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter Roll No to edit: ";
                int roll;
                cin >> roll;

                int index =-1;
                for(int i =0;i<records.size();i++)
                {
                   if(records[i].rollNo==roll)
                   {
                        index = i;
                        break;
                   }
                }

                if (index!=-1) {
                    records[index].editMarks();
                } else {
                    cout << "Record not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Enter Roll No to search: ";
                int roll;
                cin >> roll;

                int index =-1;
                for(int i =0;i<records.size();i++)
                {
                   if(records[i].rollNo==roll)
                   {
                        index = i;
                        break;
                   }
                }

                if (index!=-1) {
                    cout<<"Roll no was found."<<endl;
                } else {
                    cout << "Record not found." << endl;
                }
                break;
            }
            case 6: {
                return 0;
            }
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
