#include "car.h"

void Status::operator =(int a) { // usually used to set status back to NONE
    left = a;
    right = a;
    stopped = a;
}

Car::Car()
{
    signalling = false;
    signalCounter = 0;
    distanceTravelled = 0.0;
    onTrack = false;

    status = NONE;

    keyPosition[INTO] = 1500;
    keyPosition[TURNINTO] = 1725;
    keyPosition[CIRCLE] = 1726 + 90 * 5;
    keyPosition[TURNAWAY] = 1951 + 90 * 5;
    keyPosition[AWAY] = 3451 + 90 * 5;
}

void Car::setCar(const double sp[2][5]) {
    for (int lane = 0; lane < 2; ++lane)
        for (int count = 0; count < 5; ++count)
            referenceSpeed[lane][count] = sp[lane][count];
}

void Car::newCar(double spee) {
    passedp = false;
    onTrack = true;

    dimensions[0] = 0.2 + 0.1 * (rand() % 5) / 4.0;
    dimensions[1] = dimensions[0] + 0.1;
    dimensions[2] = 0.6 + 0.15 * (rand() % 5) / 4.0;
    dimensions[3] = dimensions[2] + 0.05;

    occupied.pathOn = INTO;
    occupied.lane = 0;

    position = 0;
    dposition = 0;
    distanceTravelled = 0.0;
    signalCounter = 0;
    colour = rand() % 7;

    speed[INTO] = spee;
    translateSpeed(INTO);
}

void Car::stopCar() {
    position = keyPosition[AWAY] + 1;
    dposition = double(position);
    onTrack = false;
    passedp = false;
}

void Car::update(bool initial) { // initial is for updating the car without moving it so its status can be determined
    int oldPathOn = occupied.pathOn; // kept because if the pathOn switches the position will need to be recalculated

    status = NONE; // status reset

    translateSpeed(occupied.pathOn);
    dposition += speed[occupied.pathOn];
    position = int(dposition); // updates position

    if (position < keyPosition[INTO]) { // entryway
        occupied.pathOn = INTO;
        occupied.road = start;
        occupied.position = position;
    }
    else if (position < keyPosition[TURNINTO]) { // turn into the roundabout
        occupied.pathOn = TURNINTO;
        occupied.road = start;
        occupied.position = position - keyPosition[INTO];
        signalling = true;
        status.right = SIGNALLING;
    }
    else if (position < keyPosition[CIRCLE]) { // around the roundabout
        occupied.pathOn = CIRCLE;
        occupied.road = NULL;
        occupied.position = (position - keyPosition[TURNINTO] + 45 * 5 + start * 90 * 5) % 1800;
        signalling = true;
        status.right = SIGNALLING;
    }
    else if (position < keyPosition[TURNAWAY]) { // exit the roundabout
        occupied.pathOn = TURNAWAY;
        occupied.road = end;
        occupied.position = position - keyPosition[CIRCLE];
        if (signalCounter < 20)
            status.right = SIGNALLING;
    }
    else if (position < keyPosition[AWAY]) { // drive on end road away from roundabout
        occupied.pathOn = AWAY;
        occupied.road = end;
        occupied.position = position - keyPosition[TURNAWAY];
        signalling = false;
    }
    else if (position >= keyPosition[AWAY])
        onTrack = false;

    if (occupied.pathOn - oldPathOn == 1) {
        dposition -= speed[oldPathOn];
        dposition = keyPosition[oldPathOn] + (dposition + speed[oldPathOn] - keyPosition[oldPathOn]) / speed[oldPathOn] * speed[occupied.pathOn];
        position = int(dposition);
        if (occupied.pathOn != CIRCLE)
            occupied.position = position - keyPosition[oldPathOn];
        else
            occupied.position = (position - keyPosition[TURNINTO] + 45 * 5 + start * 90 * 5) % 1800;
    }

    if (signalling)
        signalCounter = (signalCounter + 1) % 40;
    else
        signalCounter = 0;
}

bool Car::get_onTrack() {
    return onTrack;
}

int Car::get_start() {
    return start;
}

int Car::get_end() {
    return end;
}

int Car::get_position() {
    return position;
}

int Car::get_colour() {
    return colour;
}

void Car::set_colour(int a) {
    colour = a;
}

void Car::set_distanceTravelled(double a, bool addition) {
    if (addition)
        distanceTravelled += a;
    else
        distanceTravelled = a;
}

double Car::get_distanceTravelled() {
    return distanceTravelled;
}

double Car::get_dimensions(int a) {
    return dimensions[a % 4];
}

void Car::set_dimensions(int index, double a) {
    dimensions[index] = a;
}

void Car::set_id(int id) {
    occupied.id = id;
}

void Car::translateSpeed(int index) {
    for (int count = 0; count < 5; ++count)
        speed[count] = speed[index] / referenceSpeed[occupied.lane][index] * referenceSpeed[occupied.lane][count];
}
