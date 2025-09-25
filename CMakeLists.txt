cmake_minimum_required(VERSION 3.26)
project(InheritanceLab)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(
        Catch2

        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

if(NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    #check the compiler being used, if its not Microsoft Visual C then include files

    file(GLOB_RECURSE file_list "catch_string_manip.hpp" "catch_test_case_info.hpp" "catch_xmlwriter.cpp")
    # find files that are known to be missing include statement

    foreach(file ${file_list}) #iterate through said files

        file(READ ${file} file_contents) #open file

        string(FIND "${file_contents}" "#include <cstdint>" file_has_include) # check if file has include

        if(${file_has_include} EQUAL -1) # if file does not have include

            string(CONCAT new_file_contents "#include <cstdint>\n" "${file_contents}")
            #append file contents to the include

            file(WRITE ${file} "${new_file_contents}") # write to file with new contents
        endif()
    endforeach()
endif()


add_executable(ProductDriver
        Products/ProductDriver.cpp
        Products/Product.h
        Products/Product.cpp
        Products/Electronic.cpp
        Products/Electronic.h
        Products/Book.cpp
        Products/Book.h
        Products/Clothing.cpp
        Products/Clothing.h
)

add_executable(CalendarDriver
        Calendar/CalendarDriver.cpp
        Calendar/Calendar.cpp
        Calendar/Calendar.h
        Calendar/Schedulable.h
        Calendar/Locatable.h
        Calendar/Appointment.cpp
        Calendar/Appointment.h
        Calendar/Meeting.cpp
        Calendar/Meeting.h
        Calendar/Reminder.cpp
        Calendar/Reminder.h
)


add_executable(CharacterDriver
        Character/CharacterDriver.cpp
        Character/Knight.cpp
        Character/Knight.h
        Character/Wizard.cpp
        Character/Wizard.h
        Character/Rogue.cpp
        Character/Rogue.h
        Character/Character.cpp
        Character/Character.h
        Character/Monster.cpp
        Character/Monster.h
)

add_executable(ProductTest
        tests/ProductTest.cpp
        Products/Product.h
        Products/Product.cpp
)

add_executable(BookTest
        tests/BookTest.cpp
        Products/Product.h
        Products/Product.cpp
        Products/Book.cpp
        Products/Book.h
)

add_executable(ElectronicTest
        tests/ElectronicTest.cpp
        Products/Product.h
        Products/Product.cpp
        Products/Electronic.cpp
        Products/Electronic.h
)

add_executable(ClothingTest
        tests/ClothingTest.cpp
        Products/Product.h
        Products/Product.cpp
        Products/Clothing.cpp
        Products/Clothing.h
)

add_executable(SchedulableTest
        tests/SchedulableTest.cpp
        Calendar/Schedulable.h
)

add_executable(LocatableTest
        tests/LocatableTest.cpp
        Calendar/Locatable.h
)

add_executable(ReminderTest
        tests/ReminderTest.cpp
        Calendar/Schedulable.h
        Calendar/Reminder.h
        Calendar/Reminder.cpp
)

add_executable(AppointmentTest
        tests/AppointmentTest.cpp
        Calendar/Schedulable.h
        Calendar/Appointment.h
        Calendar/Appointment.cpp
)

add_executable(MeetingTest
        tests/MeetingTest.cpp
        Calendar/Schedulable.h
        Calendar/Meeting.h
        Calendar/Meeting.cpp
)

add_executable(CalendarTest
        tests/CalendarTest.cpp
        Calendar/Calendar.cpp
        Calendar/Calendar.h
        Calendar/Schedulable.h
        Calendar/Locatable.h
        Calendar/Appointment.cpp
        Calendar/Appointment.h
        Calendar/Meeting.cpp
        Calendar/Meeting.h
        Calendar/Reminder.cpp
        Calendar/Reminder.h
)


add_executable(CharacterTest
        tests/CharacterTest.cpp
        Character/Character.h
        Character/Character.cpp
)

add_executable(KnightTest
        tests/KnightTest.cpp
        Character/Character.h
        Character/Character.cpp
        Character/Knight.h
        Character/Knight.cpp
)

add_executable(WizardTest
        tests/WizardTest.cpp
        Character/Character.h
        Character/Character.cpp
        Character/Wizard.h
        Character/Wizard.cpp
)

add_executable(RogueTest
        tests/RogueTest.cpp
        Character/Character.h
        Character/Character.cpp
        Character/Rogue.h
        Character/Rogue.cpp
)

add_executable(MonsterTest
        tests/MonsterTest.cpp
        Character/Character.h
        Character/Character.cpp
        Character/Monster.h
        Character/Monster.cpp
)

target_link_libraries(ProductTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(BookTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ElectronicTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ClothingTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(SchedulableTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(LocatableTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ReminderTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(AppointmentTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(MeetingTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(CalendarTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(CharacterTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(KnightTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(WizardTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(RogueTest PRIVATE Catch2::Catch2WithMain)
target_link_libraries(MonsterTest PRIVATE Catch2::Catch2WithMain)