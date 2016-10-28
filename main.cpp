#include "test.h"
#include <iostream>
#include <string>

namespace Chrono {
    enum class Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep,oct,nov, dec };
    class Date {
    public:
        class Bad_date{}; // exception class
        explicit Date(int dd={}, Month mm={}, int yy={}) : d{dd}, y{yy} {m = (int)mm; };
        int day() const { return d; }
        int year() const { return y; }
        void printer() const { std::cout << d << " " << (int)m << " " << y << '\n'; }

        Date& add_year() { ++y; return *this; }
        Date& add_day() { ++d; return *this; }
        Date& add_month() {   return *this; }
    private:
        bool is_valid();
        int d,m, y;
    };
} // Chrono 

int main(int argc, char const *argv[])
{
    Chrono::Month jan = Chrono::Month::jan;
    Chrono::Date d{1,jan,2016};
    return 0;
}

