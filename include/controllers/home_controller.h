#ifndef HOME_CONTROLLER_H
#define HOME_CONTROLLER_H

#include "../../Ui/home.h"
#include "../model/database.h"

class HomeController : public QObject
{
    Q_OBJECT

    public:
        HomeController() = default;
        void setHomePage(home *_homePage);
        ~HomeController() = default;

    public slots:
        void initHomePage();
        void updateHomePage();

    private:
        home *homePage;
};

#endif // HOME_CONTROLLER_H
