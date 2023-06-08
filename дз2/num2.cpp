#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct times
{
    string time_out, time_in;
};

struct travel
{
    char out[30], in[30];
    int passengers;
    int cars;
    times t_mass;

};

void sort_time(travel* p, int n);

void convertt(string s, int *a, int *b)
{
    *a = 0;
    *b = 0;
    bool check = true;
    int k = 1;
    for (int i = s.length() - 1; i>=0; i--)
    {
        if (s[i] != ':' && check)
        {
            *b +=(s[i]-'0') * k;
            k *= 10;
        }
        else if (s[i] == ':')
        {
            check = false;
            --i;
            k = 1;
        }
        if (!check)
        {
            *a += (s[i]-'0') * k;
            k *= 10;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    travel* mass;
    int quantity, a, b, c, d;
    cout << "Введите количество рейсов: "; cin >> quantity;
    mass = new travel[quantity];
    for (int i = 0; i < quantity; i++)
    {
        cout << "Рейс №" << i +1<< " :\n";
        cout << "Пункт отправления(время указывается полностью <01:01>): ";
        cin >> mass[i].out;
        cout << "Время отправления: ";
        cin >> mass[i].t_mass.time_out;
        cout << "Пункт прибытия: ";
        cin >> mass[i].in;
        cout << "Время прибытия: ";
        cin >> mass[i].t_mass.time_in;
        cout << "Количество мест: ";
        cin >> mass[i].cars;
        cout << "Количество пассажиров: ";
        cin >> mass[i].passengers;
    }
    if(quantity>=2)sort_time(mass, quantity);
    cout << "\n--------------------------------------\nОтсортированный массив:\n";
    for (int i = 0; i < quantity; i++)
    {
        cout << "Отправление: "<<mass[i].out<< " (" << mass[i].t_mass.time_out <<")\nПрибытие: " << mass[i].in << " ("<< mass[i].t_mass.time_in << ")\nМеста/пассажиры: " << mass[i].cars << "/" << mass[i].passengers << endl;
        cout << "\n";
    }
    string fix_time;
    cout << "\nЗадайте время отправления: "; cin >> fix_time;
    cout << "Рейсы после заданного времени: ";
    for (int i = 0; i <quantity; i++)
    {
        convertt(mass[i].t_mass.time_out, &a, &b);
        convertt(fix_time, &c, &d);
        if (a > c)
        {
            cout << "Отправление: " << mass[i].out << " (" << mass[i].t_mass.time_out << ")\nПрибытие: " << mass[i].in << " (" << mass[i].t_mass.time_in << ")\nМеста/пассажиры: " << mass[i].cars << "/" << mass[i].passengers << endl;
        }
        else if (a == c)
        {
            if (b > d)
            {
                cout << "\nОтправление: " << mass[i].out << ", " << mass[i].t_mass.time_out << "\nПрибытие: " << mass[i].in << ", " << mass[i].t_mass.time_in << "\nМеста/пассажиры: " << mass[i].cars << ", " << mass[i].passengers << endl;
            }
        }
    }
}

void sort_time(travel* p, int n)
{
    int i, j, a, b, c, d;
    travel extra;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 2; j >= i; j--)
        {
            convertt(p[j].t_mass.time_out, &a, &b);
            convertt(p[j+1].t_mass.time_out, &c, &d);
            if (a > c)
            {
                extra = p[j];
                p[j] = p[j + 1];
                p[j + 1] = extra;
            }
            else if (a == c)
            {
                if (b > d)
                {
                    extra = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = extra;
                }
            }
        }
    }
}