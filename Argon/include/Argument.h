#ifndef ARGON_ARG_H
#define ARGON_ARG_H

#include <list>
#include <memory>
#include <string>
#include <variant>

#include "Type.h"

namespace Argon
{
    class Argument
    {
    private:
        std::variant<
            std::shared_ptr<int>,
            std::shared_ptr<std::string>>
            m_arg;
        std::string m_argName;
        std::string m_helpText;
        Type m_type;
        bool m_isRequired;
        bool m_isSet;

    public:
        explicit Argument(std::string argName);

        Argument &setArgName(const std::string &argName);
        Argument &setType(Type type);
        Argument &setIsRequired(bool isRequired);
        Argument &setHelpText(const std::string &helpText);
        Argument &setArg(const char *);
        Argument &setArg(int);

        bool isRequired() const;
        bool isSet() const;
        const Type getType() const;
        const std::string &getHelpText() const;
        const std::string &getDebugText() const;

        friend std::ostream &operator<<(std::ostream &os, const Argument &arg);
    };
}

#endif /* ARGON_ARG_H */