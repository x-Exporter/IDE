#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ifstream ifile("in.txt");
    ofstream ofile("out.txt");
    int firstlenght;
    int secondlenght;
    if (ifile.is_open())
    {
        int tmp;
        ifile >> firstlenght;
        int* firstArray = new int[firstlenght];
        for (int i = 0; i < firstlenght; i++)
        {
            ifile >> firstArray[i];
        }

        ifile >> secondlenght;
        int* secondArray = new int[secondlenght];
        for (int i = 0; i < secondlenght; i++)
        {
            ifile >> secondArray[i];
        }
        //Сдвиг на 1 влево
        tmp = firstArray[0];
        for (int i = 0; i < firstlenght - 1; i++)
        {
            firstArray[i] = firstArray[i + 1];

        }
        firstArray[firstlenght - 1] = tmp;

        //Сдвиг на 1 вправо
        tmp = secondArray[secondlenght - 1];
        for (int i = secondlenght - 1; i >= 0; i--)
        {
            secondArray[i] = secondArray[i - 1];
        }
        secondArray[0] = tmp;

        ofile << secondlenght << endl;
        for (int i = 0; i < secondlenght; i++)
        {
            ofile << secondArray[i] << " ";
        }
        ofile << endl;

        ofile << firstlenght << endl;
        for (int i = 0; i < firstlenght; i++)
        {
            ofile << firstArray[i] << " ";
        }
        ifile.close();
        ofile.close();
        delete[] firstArray;
        delete[] secondArray;
    }
}