#include <iostream>
#include <map>

using namespace std;

class Calendar {

public:
  Calendar() {
    month = 1;
    day = 1;
    year = 1900;
    day_of_week = 1;
    sundays_on_the_first = 0;

    day_lookup[1] = 31;
    day_lookup[2] = 28;
    day_lookup[3] = 31;
    day_lookup[4] = 30;
    day_lookup[5] = 31;
    day_lookup[6] = 30;
    day_lookup[7] = 31;
    day_lookup[8] = 31;
    day_lookup[9] = 30;
    day_lookup[10] = 31;
    day_lookup[11] = 30;
    day_lookup[12] = 31;

    month_str_lookup[1] = "January";
    month_str_lookup[2] = "February";
    month_str_lookup[3] = "March";
    month_str_lookup[4] = "April";
    month_str_lookup[5] = "May";
    month_str_lookup[6] = "June";
    month_str_lookup[7] = "Huly";
    month_str_lookup[8] = "August";
    month_str_lookup[9] = "September";
    month_str_lookup[10] = "October";
    month_str_lookup[11] = "November";
    month_str_lookup[12] = "December";

    day_str_lookup[1] = "Monday";
    day_str_lookup[2] = "Tuesday";
    day_str_lookup[3] = "Wednesday";
    day_str_lookup[4] = "Thursday";
    day_str_lookup[5] = "Friday";
    day_str_lookup[6] = "Saturday";
    day_str_lookup[7] = "Sunday";
  }
  ~Calendar() {}

  void print() {
    cout << day_str_lookup[day_of_week] << ", " << month_str_lookup[month]
         << " " << day << " " << year << endl;
  }

  void advance() {
    day++;
    day_of_week++;

    if (day_of_week > 7) {
      day_of_week = 1;
    }

    if (!is_leapyear()) {
      if (day > day_lookup[month]) {
        day = 1;
        month++;
      }

      if (month > 12) {
        month = 1;
        year++;
      }

    } else {
      if (month == 2 && day == 29) {

      } else {
        if (day > day_lookup[month]) {
          day = 1;
          month++;
        }

        if (month > 12) {
          month = 1;
          year++;
        }
      }
    }

    // count sundays on the 1st
    if (day_of_week == 7 && day == 1 && year >= 1901 && year < 2001) {
      sundays_on_the_first++;
    }
  }

  unsigned int get_sundays() { return sundays_on_the_first; }

  bool is_leapyear() {

    if (year % 4 == 0 && year % 400 == 0) {
      return true;

    } else if (year % 4 == 0 && year % 100 != 0) {
      return true;
    }
    return false;
  }

  int get_month() { return month; }
  int get_day() { return day; }
  int get_year() { return year; }

private:
  unsigned int month;
  unsigned int day;
  unsigned int year;
  unsigned int day_of_week;

  unsigned int sundays_on_the_first;

  map<int, int> day_lookup;
  map<int, string> month_str_lookup;
  map<int, string> day_str_lookup;
};

int main() {
  cout << "evildojo" << endl;
  Calendar cal;
  for (int i = 0; i < 365 * 101 + 25; i++) {
    // cal.print();
    cal.advance();
  }
  cout << cal.get_sundays() << endl;
  return 0;
}
