cmake_minimum_required(VERSION 3.5)

project(quizApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        Ui/main.cpp
        Ui/mainwindow.cpp
        Ui/mainwindow.h
        Ui/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(quizApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET quizApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(quizApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(quizApp
            ${PROJECT_SOURCES}

            Ui/signup.ui

            Ui/results.ui
            Ui/quizzes.ui


            Ui/reviewquiz.ui

            Ui/home.h Ui/home.cpp Ui/home.ui
            Ui/resource.qrc
            Ui/sidebar.h Ui/sidebar.cpp Ui/sidebar.ui
            Ui/quiz.h Ui/quiz.cpp Ui/quiz.ui
            Ui/signup.h Ui/signup.cpp Ui/signup.ui
            Ui/quizzes.h Ui/quizzes.cpp Ui/quizzes.ui

            Ui/question.h Ui/question.cpp Ui/question.ui
            Ui/reviewquiz.h Ui/reviewquiz.cpp Ui/reviewquiz.ui
            Ui/quizresult.h Ui/quizresult.cpp Ui/quizresult.ui
            Ui/quizinfo.h Ui/quizinfo.cpp Ui/quizinfo.ui
            Ui/results.h Ui/results.cpp Ui/results.ui

            Ui/login.h Ui/login.cpp Ui/login.ui

            include/controllers/login_controller.h src/controllers/login_controller.cpp
            include/controllers/main_controller.h src/controllers/main_controller.cpp
            include/controllers/signup_controller.h src/controllers/signup_controller.cpp

            include/model/quiz.h src/model/quiz.cpp
            src/model/database.cpp
            include/model/database.h
            src/controllers/quizzes_controller.cpp include/controllers/quizzes_controller.h
            include/model/question.h
            src/model/question.cpp
            include/controllers/quiz_controller.h
            src/controllers/quizzes_controller.cpp
            src/controllers/quiz_controller.cpp
            src/controllers/results_controller.cpp
            include/controllers/results_controller.h
            include/controllers/review_controller.h
            src/controllers/review_controller.cpp
            include/model/user.h
            src/model/user.cpp
            include/controllers/home_controller.h
            src/controllers/home_controller.cpp


        )
    endif()
endif()

target_link_libraries(quizApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(quizApp PRIVATE pqxx)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.quizApp)
endif()
set_target_properties(quizApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS quizApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(quizApp)
endif()
