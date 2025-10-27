#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void inputData (studentType Siswa[], int N);
void Nilai (studentType Siswa[], int N);
void Tertinggi (studentType Siswa[], int N);
void outputTertinggi (studentType Siswa[], int i);
void outputData (studentType Siswa[], int N);


int main(){
    int N;
    cout << "Masukkan Jumlah Siswa: ";
    cin >> N;
    studentType Siswa[N];
    inputData(Siswa,N);
    Nilai(Siswa,N);
    Tertinggi(Siswa,N);
    outputData(Siswa,N);

    return 0;
}

void inputData (studentType Siswa[], int N){
    cout << "----INPUT DATA SISWA----" << endl;
    for(int i = 0; i < N; i++){
        cout << "Siswa " << i+1 << ":" << endl;
        cout << "Masukkan Nama Depan: ";
        cin >> Siswa[i].studentFName;
        cout << "Masukkan Nama Belakang: ";
        cin >> Siswa[i].studentLName;
        cout << "Masukkan Nilai Siswa: ";
        cin >> Siswa[i].testScore;
        cout << "------------------" << endl;
    }
}

//A = 85 - 100, B = 70 - 84, C = 60 - 69, D = 50 - 59, E = 0 - 49
void Nilai (studentType Siswa[], int N){
    for(int i = 0; i < N; i++){
        int nilai = Siswa[i].testScore; 
        if (nilai < 50){
            Siswa[i].grade = 'E';
        }
        else if (nilai < 60){
            Siswa[i].grade = 'D';
        }
        else if(nilai < 70){
            Siswa[i].grade = 'C';
        }
        else if(nilai < 85){
            Siswa[i].grade = 'B';
        }
        else{
            Siswa[i].grade = 'A';
        }
    }
}

void Tertinggi (studentType Siswa[], int N){
    int max = INT_MIN;
    int index;
    for(int i = 0; i < N; i++){
        if(Siswa[i].testScore > max){
            max = Siswa[i].testScore;
            index = i;
        }
    }
    outputTertinggi(Siswa,index);
}

void outputTertinggi (studentType Siswa[], int i){
    cout << "NILAI TERTINGGI" << endl;
    cout << "NAMA : " << Siswa[i].studentFName << " " << Siswa[i].studentLName << endl;
    cout << "NILAI: " << Siswa[i].testScore << endl;
    cout << "GRADE: " << Siswa[i].grade << endl;
    cout << "----------------------" << endl;
}

void outputData (studentType Siswa[], int N){
    cout << "---OUTPUT DATA SISWA---" << endl;
    for(int i = 0; i < N; i++){
        cout << Siswa[i].studentLName << ", " << Siswa[i].studentFName << endl;
    }
}