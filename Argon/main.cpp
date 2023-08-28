#include "Processor.h"

#include <iostream>

int main()
{
    Argon::Processor argonProcessor;

    argonProcessor.createArgument("-y")
        .setType(Argon::Type::Integer)
        .setIsRequired(true)
        .setHelpText("This is the -y parameter for user's age");
    //.setRequires({"-v"})
    //.setPrevents({"-u"});

    argonProcessor.createArgument("-u")
        .setType(Argon::Type::String)
        .setIsRequired(false)
        .setHelpText("This is the -u parameter for user's username");

    const int argc = 5;
    const char *argv[argc] = {"thisProg", "-u", "Julo", "-y", "21"};

    argonProcessor.processArguments(argc, argv);
    argonProcessor.verifyArguments();

    std::cout << argonProcessor << std::endl;
    std::cout << "/*/*/*/*/*/*/*/" << std::endl;
    argonProcessor.showHelp();

    return 0;
}