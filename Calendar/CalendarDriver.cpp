#include <iostream>
#include <iomanip>
#include "Appointment.h"
#include "Meeting.h"
#include "Reminder.h"
#include "Calendar.h"



int main() {
Reminder reminder(2025,3,10,"Go Math Class");
    std::cout << reminder.toString() << std::endl;

Appointment appointment(2025,3,10,"Dental Appoinment","Fremont");
    std::cout <<appointment.toString() << std::endl;

Meeting meeting(2023,3,10,"Presentation","Ohlone College");
    meeting.addAttendee("Shaahid");
    meeting.addAttendee("Halid");
    std::cout <<meeting.toString() << std::endl;

    Calendar calendar;
    calendar.addEvent(&reminder);
    calendar.addEvent(&meeting);
    calendar.addEvent(&appointment);





    return 0;
}