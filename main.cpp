#include <iostream>

#define BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WApplication>
#include <Wt/WEnvironment>
#include <Wt/WTheme>
#include <Wt/WCssTheme>
#include <Wt/WBootstrapTheme>

#include "GeneralApplication.h"

Wt::WApplication* createApplication(const Wt::WEnvironment& env) {
    return new GeneralApplication(env);
}

int main(int argc, char** argv) {
    return Wt::WRun(argc, argv, &createApplication);
}