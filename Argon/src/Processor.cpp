#include "Processor.h"
#include "Argument.h"
#include "Type.h"

#include <ostream>

namespace Argon
{
    Argument &
    Processor::createArgument(const std::string &argName)
    {
        if (this->m_mappedArguments.find(argName) == this->m_mappedArguments.end())
        { // if the map do not contain this arg
            this->m_mappedArguments[argName] = std::make_shared<Argument>(argName);
            return (*this->m_mappedArguments[argName]);
        }
        else
        {
            throw std::exception(); // TODO (JBR) make real exceptions.
        }
    }

    std::shared_ptr<Argument>
    Processor::getArgument(const std::string &argName)
    {
        auto Argument = this->m_mappedArguments.find(argName);
        if (Argument != this->m_mappedArguments.end())
        {
            return Argument->second;
        }
        else
        {
            throw std::exception(); // TODO (JBR) make real exceptions.
        }
    }

    void
    Processor::processArguments(int argc, const char *argv[])
    {
        for (int i = 1; i < argc; ++i) // skip program name
        {
            const char *arg = argv[i];
            if (this->m_mappedArguments.find(arg) != this->m_mappedArguments.end())
            { // TODO (JBR) simplify this double get
                std::shared_ptr<Argument> Argument = this->m_mappedArguments[arg];
                switch (Argument->getType())
                {
                case Type::None: // No data
                    break;
                case Type::Integer:
                {
                    i++;                             // TODO assert i < argc - 1
                    int number = std::stoi(argv[i]); // TODO (JBR) Handle errors
                    Argument->setArg(number);
                    break;
                }
                case Type::String:
                    i++; // TODO assert i < argc - 1
                    Argument->setArg(argv[i]);
                    break;
                default:
                    break;
                }
            }
            else
            {
                throw std::exception(); // TODO (JBR) make real exceptions.
            }
        }
    }

    bool
    Processor::verifyArguments()
    {
        bool result = true;
        for (const auto &arg : this->m_mappedArguments)
        {
            if (arg.second->isRequired() && !arg.second->isSet())
            {
                std::cout << "Error: argument: "
                          << arg.first
                          << " required but not set"
                          << std::endl;
                result = false;
            }

            /*
            for (const auto &requiredArgument: arg.second->getRequires())
            {
                auto arg2 = this->m_mappedArguments.find(requiredArgument);
                std::cout << requiredArgument << std::endl;
                if (arg2 == this->m_mappedArguments.end())
                {
                    std::cout << "Error: argument ("
                              << arg.first
                              << ") requires ("
                              << requiredArgument
                              << ") which isn't present"
                              << std::endl;
                    return false;
                }
            }

            for (const auto &preventedArgument: arg.second->getPrevents())
            {
                auto arg2 = this->m_mappedArguments.find(preventedArgument);
                if (arg2 != this->m_mappedArguments.end())
                {
                    std::cout << "Error: argument ("
                              << arg.first
                              << ") prevents ("
                              << preventedArgument
                              << ") which is present"
                              << std::endl;
                    return false;
                }
            }
            */
        }
        return result;
    }

    std::ostream &
    operator<<(std::ostream &os, const Processor &parser)
    {
        for (const auto &arg : parser.m_mappedArguments)
        {
            os << "argName: "
               << arg.first
               << "\nargValue: "
               << (*arg.second);
        }
        return os;
    }

    void
    Processor::showHelp(std::ostream &os)
    {
        for (const auto &arg : this->m_mappedArguments)
        {
            os << arg.first
               << ": "
               << arg.second->getHelpText()
               << std::endl;
        }
    }
}