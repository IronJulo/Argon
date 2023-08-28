#ifndef ARGON_PROCESSOR_H
#define ARGON_PROCESSOR_H

#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>

#include "Argument.h"
#include "Type.h"

namespace Argon
{
    class Processor
    {
    private:
        std::map<std::string, std::shared_ptr<Argument>> m_mappedArguments;

    public:
        Argument &createArgument(const std::string &argName);

        std::shared_ptr<Argument> getArgument(const std::string &argName);
        void processArguments(int argc, const char *argv[]);
        bool verifyArguments();
        void showHelp(std::ostream &os = std::cout);

        friend std::ostream &operator<<(std::ostream &os, const Processor &processor);
    };

}
#endif /* ARGON_PROCESSOR_H */