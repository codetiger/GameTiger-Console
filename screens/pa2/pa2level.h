
const char fruitsAnimSeq[][17] = {
    {0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6, 6},
    {7, 7, 7, 7, 7, 8, 9, 9, 9, 10, 10, 11, 12, 12, 12, 13, 13},
    {14, 14, 14, 14, 14, 15, 16, 16, 16, 17, 17, 18, 19, 19, 19, 20, 20},
    {21, 21, 21, 21, 21, 22, 23, 23, 23, 24, 24, 25, 26, 26, 26, 27, 27},
    {28, 28, 28, 28, 28, 29, 30, 30, 30, 31, 31, 32, 33, 33, 33, 34, 34},
    {35, 35, 35, 35, 35, 36, 37, 37, 37, 38, 38, 39, 40, 40, 40, 41, 41},
    {42, 42, 42, 42, 42, 43, 44, 44, 44, 45, 45, 46, 47, 47, 47, 48, 48},
    {49, 49, 49, 49, 49, 50, 51, 51, 51, 52, 52, 53, 54, 54, 54, 55, 55},
    {56, 57, 58, 59, 60, 61}
};

const uint8_t level01XCount = 32;
const uint8_t level01YCount = 18;
const uint8_t level01[] = {
    78, 61, 97, 97, 62, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78,
    78, 79, 88, 89, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 62, 78,
    78, 79, 107, 108, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 68, 69, 69, 70, 87, 68, 70, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 72, 73, 73, 73, 73, 73, 74, 77, 78,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 91, 92, 92, 92, 92, 92, 93, 77, 78,
    78, 79, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 91, 92, 92, 92, 92, 92, 93, 77, 78,
    78, 79, 109, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 91, 92, 92, 92, 92, 92, 93, 96, 62,
    78, 79, 63, 64, 64, 64, 64, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 91, 92, 92, 92, 92, 92, 92, 74, 77,
    78, 79, 82, 83, 83, 83, 83, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 91, 92, 92, 92, 92, 92, 93, 71, 77,
    78, 79, 101, 102, 102, 87, 85, 64, 64, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87, 110, 111, 111, 111, 111, 112, 87, 109, 77,
    78, 80, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 81,
    78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78, 78
};

const uint8_t level01GoodiesCount = 8;
const uint16_t level01Goodies[][6] = {
    {90, 80, 10, 0, 0, 8},
    {120, 80, 10, 0, 1, 8},
    {150, 80, 10, 0, 2, 8},
    {180, 80, 10, 0, 3, 8},
    {210, 80, 10, 0, 4, 8},
    {240, 80, 10, 0, 5, 8},
    {270, 80, 10, 0, 6, 8},
    {300, 80, 10, 0, 7, 8},
};