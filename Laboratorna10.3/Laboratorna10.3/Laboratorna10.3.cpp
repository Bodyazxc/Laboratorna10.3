#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

struct Room
{
    int phone_number;
    int room_number;
    string employees[4];
    int employee_count;
};

// Функції
void AddRoom(Room*& rooms, int& count);
void DeleteRoom(Room*& rooms, int& count);
void EditRoom(Room* rooms, int count);
void PrintAllRooms(const Room* rooms, int count);
void PrintByPhoneNumber(const Room* rooms, int count);
void PrintByRoomNumber(const Room* rooms, int count);
void PrintByEmployee(const Room* rooms, int count);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Room* rooms = new Room[100];  // Динамічно виділений масив
    int count = 0;
    int MenuItem;

    while (true)
    {
        cout << endl << "Оберіть дію:" << endl;
        cout << "1 - Додати приміщення" << endl;
        cout << "2 - Видалити приміщення" << endl;
        cout << "3 - Редагувати приміщення" << endl;
        cout << "4 - Вивести всі приміщення" << endl;
        cout << "5 - Пошук за номером телефону" << endl;
        cout << "6 - Пошук за номером приміщення" << endl;
        cout << "7 - Пошук за прізвищем службовця" << endl;
        cout << "0 - Завершити роботу програми" << endl;
        cout << "Введіть: ";
        cin >> MenuItem;

        switch (MenuItem)
        {
        case 1:
            AddRoom(rooms, count);
            break;
        case 2:
            DeleteRoom(rooms, count);
            break;
        case 3:
            EditRoom(rooms, count);
            break;
        case 4:
            PrintAllRooms(rooms, count);
            break;
        case 5:
            PrintByPhoneNumber(rooms, count);
            break;
        case 6:
            PrintByRoomNumber(rooms, count);
            break;
        case 7:
            PrintByEmployee(rooms, count);
            break;
        case 0:
            delete[] rooms;
            return 0;
        }
    }
}

void AddRoom(Room*& rooms, int& count)
{
    if (count >= 100)
    {
        cout << "Досягнуто максимальну кількість приміщень." << endl;
        return;
    }

    cout << "Введіть номер телефону (2 цифри): ";
    cin >> rooms[count].phone_number;
    cout << "Введіть номер приміщення: ";
    cin >> rooms[count].room_number;
    cout << "Введіть кількість службовців (до 4): ";
    cin >> rooms[count].employee_count;

    if (rooms[count].employee_count > 4)
    {
        cout << "Кількість службовців не може перевищувати 4." << endl;
        rooms[count].employee_count = 4;
    }

    cin.ignore();
    for (int i = 0; i < rooms[count].employee_count; i++)
    {
        cout << "Введіть прізвище службовця №" << i + 1 << ": ";
        getline(cin, rooms[count].employees[i]);
    }

    count++;
}

void DeleteRoom(Room*& rooms, int& count)
{
    int phone;
    cout << "Введіть номер телефону приміщення для видалення: ";
    cin >> phone;

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].phone_number == phone)
        {
            for (int j = i; j < count - 1; j++)
            {
                rooms[j] = rooms[j + 1];
            }
            count--;
            cout << "Приміщення видалено." << endl;
            return;
        }
    }
    cout << "Приміщення з таким номером телефону не знайдено." << endl;
}

void EditRoom(Room* rooms, int count)
{
    int phone;
    cout << "Введіть номер телефону приміщення для редагування: ";
    cin >> phone;

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].phone_number == phone)
        {
            cout << "Введіть новий номер приміщення: ";
            cin >> rooms[i].room_number;
            cout << "Введіть кількість службовців (до 4): ";
            cin >> rooms[i].employee_count;

            if (rooms[i].employee_count > 4)
            {
                cout << "Кількість службовців не може перевищувати 4." << endl;
                rooms[i].employee_count = 4;
            }


            cin.ignore();
            for (int j = 0; j < rooms[i].employee_count; j++)
            {
                cout << "Введіть прізвище службовця №" << j + 1 << ": ";
                getline(cin, rooms[i].employees[j]);
            }

            cout << "Приміщення оновлено." << endl;
            return;
        }
    }
    cout << "Приміщення з таким номером телефону не знайдено." << endl;
}

void PrintAllRooms(const Room* rooms, int count)
{
    cout << "=====================================================================" << endl;
    cout << "|  Телефон  | Приміщення | Службовці                                |" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < count; i++)
    {

        cout << "| " << setw(9) << rooms[i].phone_number << " | " << setw(10) << rooms[i].room_number << " | ";

        
        for (int j = 0; j < rooms[i].employee_count; j++)
        {
            cout << rooms[i].employees[j];
            if (j < rooms[i].employee_count - 1)
                cout << ",";
        }


        cout <<  "" << "                            |" << endl;
    }

    cout << "=====================================================================" << endl;
}

void PrintByPhoneNumber(const Room* rooms, int count)
{
    int phone;
    cout << "Введіть номер телефону: ";
    cin >> phone;

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].phone_number == phone)
        {
            cout << "=====================================================================" << endl;
            cout << "|  Телефон  | Приміщення | Службовці                                |" << endl;
            cout << "---------------------------------------------------------------------" << endl;
            cout << "| " << setw(9) << rooms[i].phone_number;
            cout << " | " << setw(10) << rooms[i].room_number;
            cout << " | ";

            for (int j = 0; j < rooms[i].employee_count; j++)
            {
                cout << rooms[i].employees[j];
                if (j < rooms[i].employee_count - 1)
                    cout << ", ";
            }

            cout << "" << "                           |" << endl;
            cout << "=====================================================================" << endl;
            return;
        }
    }
    cout << "Приміщення з таким номером телефону не знайдено." << endl;
}

void PrintByRoomNumber(const Room* rooms, int count)
{
    int room_number;
    cout << "Введіть номер приміщення: ";
    cin >> room_number;

    for (int i = 0; i < count; i++)
    {
        if (rooms[i].room_number == room_number)
        {
            cout << "=====================================================================" << endl;
            cout << "|  Телефон  | Приміщення | Службовці                                |" << endl;
            cout << "---------------------------------------------------------------------" << endl;
            cout << "| " << setw(9) << rooms[i].phone_number;
            cout << " | " << setw(10) << rooms[i].room_number;
            cout << " | ";

            for (int j = 0; j < rooms[i].employee_count; j++)
            {
                cout << rooms[i].employees[j];
                if (j < rooms[i].employee_count - 1)
                    cout << ", ";
            }

            cout << "" << "                           |" << endl;
            cout << "=====================================================================" << endl;
            return;
        }
    }
    cout << "Приміщення з таким номером не знайдено." << endl;
}

void PrintByEmployee(const Room* rooms, int count)
{
    string employee;
    cout << "Введіть прізвище службовця: ";
    cin >> employee;


    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < rooms[i].employee_count; j++)
        {
            if (rooms[i].employees[j] == employee)
            {
                cout << "==================================================================" << endl;
                cout << "|  Телефон  | Приміщення | Службовці                             |" << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "| " << setw(9) << rooms[i].phone_number;
                cout << " | " << setw(10) << rooms[i].room_number;
                cout << " | ";

                for (int k = 0; k < rooms[i].employee_count; k++)
                {
                    cout << rooms[i].employees[k];
                    if (k < rooms[i].employee_count - 1)
                        cout << ", ";
                }

                cout << "" << "                        |" << endl;
                cout << "==================================================================" << endl;
                return;
            }
        }
    }
    cout << "Службовець з таким прізвищем не знайдений." << endl;
}
