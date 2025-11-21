#include <iostream>
#include <cstdint>
using namespace std;

// Pack single date into 16 bits
static uint16_t packDate(int y, int m, int d) {
    int yy = y - 2000;
    return static_cast<uint16_t>((yy << 9 | m << 5 | d));
}

void showPeriod(int period) {
    uint32_t p = static_cast<uint32_t>(period);

    uint16_t from = static_cast<uint16_t> ((p >> 16) & 0xFFFF);
    uint16_t to = static_cast<uint16_t> (p & 0xFFFF);

    // From
    int fy = ((from >> 9) & 0x7F) + 2000;
    int fm = ((from >> 5) & 0x0F);
    int fd = from & 0x1F;

    // To
    int ty = ((to >> 9) & 0x7F) + 2000;
    int tm = (to >> 5) & 0x0F;
    int td = to & 0x1F;

    cout << fy << '/';
    if (fm < 10) cout << '0';
    cout << fm << '/';
    if (fd < 10) cout << '0';
    cout << fd << '-';

    cout << ty << '/';
    if (tm < 10) cout << '0';
    cout << tm << '/';
    if (td < 10) cout << '0';
    cout << td << '\n';
}

int pack(int fromy, int fromm, int fromd,
        int toy, int tom, int tod) {
        uint16_t from = packDate(fromy, fromm, fromd);
        uint16_t to = packDate(toy, tom, tod);

        uint32_t period = (static_cast<uint32_t>(from) << 16) | static_cast<uint32_t>(to);

        return static_cast<int>(period);
}

int main() {
    int period = pack(2000, 2, 3, 2127, 11, 29);
    showPeriod(period);
}
