#include "path.h"

void Point::operator =(double a) {
    x = a;
    y = a;
    rotation = 0.0;
    position = 0;
}

bool Point::operator <=(Point a) {
    if (fabs(x) <= fabs(a.x) && fabs(y) <= fabs(a.y) &&
        x / fabs(x) == a.x / fabs(a.x) && y / fabs(y) == a.y / fabs(a.y))
        return true;
    else
        return false;
}

bool Point::operator >=(Point a) {
    if (fabs(x) >= fabs(a.x) && fabs(y) >= fabs(a.y) &&
        x / fabs(x) == a.x / fabs(a.x) && y / fabs(y) == a.y / fabs(a.y))
        return true;
    else
        return false;
}

Path::Path()
{

}

void Path::set(double r, double lw) {
    radius[0] = r + lw * 0.5;
    radius[1] = r + lw * 1.5;

    laneVector[0] = lw * 0.5;
    laneVector[1] = lw * 1.5;

    for (int lane = 0; lane < 2; ++lane) {
        speed[lane][INTO] = 1.0;
        speed[lane][AWAY] = speed[lane][INTO];
    }

    for (int lane = 0; lane < 2; ++lane) {
        radians = 0.0;
        for (int count = 0; count < 1800; ++count, radians += PI / 180.0 / 5.0) {
            circle[lane][count].x = radius[lane] * cos(radians)  - TRANSLATION * sin(radians);
            circle[lane][count].y = TRANSLATION * cos(radians) + radius[lane] * sin(radians);
            circle[lane][count].rotation = (count + 90 * 5) % 1800 / 5.0;
        }
    }
    for (int lane = 0; lane < 2; ++lane)
        speed[lane][CIRCLE] = DISTANCE * 5.0 * 180.0 / PI / radius[lane];

    for (int lane = 0; lane < 2; ++lane) {
        radius[lane + 2] = (radius[lane] * sin(PI / 4.0) - laneVector[lane]) / (1 - sin(PI / 4.0)); // horizontal / vertical distance from origin to origin of new reference circle = newradius[0] + 0.55 = oldradius[0] * sin(45) + newradius[0] * sin(45)
        coordinate[lane] = laneVector[lane] + radius[lane + 2];                                     // since new circle 135 degree point matches 45 degree point of origin circle, and 270 degree of new circle matches with horizontal and vertical of laneVector
    }

    double origin[4][2][2] = {  {  {coordinate[0], coordinate[0]},
                                   {coordinate[1], coordinate[1]}  },    {  {-coordinate[0], coordinate[0]},
                                                                            {-coordinate[1], coordinate[1]}  },
                                {  {-coordinate[0], -coordinate[0]},
                                   {-coordinate[1], -coordinate[1]}  },  {  {coordinate[0], -coordinate[0]},
                                                                            {coordinate[1], -coordinate[1]}  }
                             };

    for (int road = 0; road < 4; ++road) {
        for (int lane = 0; lane < 2; ++lane) {
            radians = 270.0 * PI / 180.0 + road * 90.0 * PI / 180.0;
            radians2 = 494.8 * PI / 180.0 + road * 90.0 * PI / 180.0;
            for (int count = 0; count < 225; ++count, radians -= PI / 180.0 / 5.0, radians2 -= PI / 180.0 / 5.0) {
                turninto[road][lane][count].x = origin[road][lane][0] + radius[lane + 2] * cos(radians) + TRANSLATION * sin(radians);
                turninto[road][lane][count].y = origin[road][lane][1] - TRANSLATION * cos(radians) + radius[lane + 2] * sin(radians);
                turninto[road][lane][count].rotation = (540 * 5 + 90 * 5 * road - count) % 1800 / 5.0;

                turnaway[road][lane][count].x = origin[(road + 3) % 4][lane][0] + radius[lane + 2] * cos(radians2) + TRANSLATION * sin(radians2);
                turnaway[road][lane][count].y = origin[(road + 3) % 4][lane][1] - TRANSLATION * cos(radians2) + radius[lane + 2] * sin(radians2);
                turnaway[road][lane][count].rotation = (2024 + 90 * 5 * road - count) % 1800 / 5.0;
            }
        }
    }
    for (int lane = 0; lane < 2; ++lane) {
        speed[lane][TURNINTO] = DISTANCE * 5.0 * 180.0 / PI / radius[lane + 2];
        speed[lane][TURNAWAY] = speed[lane][TURNINTO];
    }

    for (int road = 0; road < 4; ++road)
        for (int lane = 0; lane < 2; ++lane)
            for (int count = 0; count < 1500; ++count) {
                if (road % 2 == 1) {
                    into[road][lane][count].x = turninto[road][lane][0].x;
                    into[road][lane][count].y = turninto[road][lane][0].y + (2 - road) * ((1500 - count) * DISTANCE);
                    into[road][lane][count].rotation = (180 + road * 90) % 360;

                    away[road][lane][count].x = turnaway[road][lane][224].x;
                    away[road][lane][count].y = turnaway[road][lane][224].y + (2 - road) * ((count + 1) * DISTANCE);
                    away[road][lane][count].rotation = road * 90;
                }
                else if (road % 2 == 0) {
                    into[road][lane][count].x = turninto[road][lane][0].x + (1 - road) * ((1500 - count) * DISTANCE);
                    into[road][lane][count].y = turninto[road][lane][0].y;
                    into[road][lane][count].rotation = (180 + road * 90) % 360;

                    away[road][lane][count].x = turnaway[road][lane][224].x + (1 - road) * ((count + 1) * DISTANCE);
                    away[road][lane][count].y = turnaway[road][lane][224].y;
                    away[road][lane][count].rotation = road * 90;
                }
            }
    distance_tostart = into[2][0][1499].x - into[2][0][0].x;// + (radius[0] + radius[2]) * PI / 4.0;
}
