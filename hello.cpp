#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> subarr)
{
    int minIndex = 0;
    for (int i = 0; i < subarr.size(); i++)
    {
        if (subarr[i] < subarr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
};

int main()
{
    cout << "Hello world" << endl;

    vector<int> arr{33, 22, 11, 47, 4, 13, 26};

    // Sorting Algorithms
    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //  A kinda bubble sort 
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    };

    // Selection sort
    // it selects the minimum element from the unsorted part and places it in the sorted part
    // ok so first find the min
    // Hacer una funcion que reciba el subarray y retorne el minimo (index) para ser swapeada con la posicion donde inicia el sub arr

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     vector<int> subarr;
    //     subarr = vector<int>(arr.begin() + i, arr.end());
    //     int minFound = findMin(subarr);

    //     int temp = arr[i];
    //     arr[i] = arr[minFound + i];
    //     arr[minFound + i] = temp;
    // }

    // cout << findMin(arr) << endl;
    // arr = vector<int>(arr.begin() + 1, arr.end()); //How to create a sub arr

    /* Ejemplo
      33, 22, 11, 47, 4, 13, 26
      subarr start = 0 a size min 4 pos 4 -- 4 swaps with 0 >> 4, 22, 11, 47,33, 13, 26
      new sub 1 to size min 11 swaps with 1*/

    // Insertion sort
    // takes a pivot, and compares it with the previous value, seguira recorriendo los numeros hasta que el prev sea menor o igual
    // empieza desde 1, recorre uno por uno hasta que encuentre donde insertarse prev < key(pivot)
    // starts from 1 and will swap one by one until it finds its where to insert itself prev < key(pivot)

    // first a pivot selector aka a for loop
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     int key = arr[i];
    //     int j = i - 1;
    //     while (arr[j] > key && j >= 0)
    //     {
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     arr[j + 1] = key;
    // }

    // cout << "ei" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;


}